//By emag
/* Simple HTTP Server Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <esp_wifi.h>
#include <esp_event.h>
#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <sys/param.h>
#include "nvs_flash.h"
#include "tcpip_adapter.h"
#include "esp_eth.h"
//#include "protocol_examples_common.h"

#include <esp_http_server.h>

#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//#include "esp_system.h"
//#include "esp_wifi.h"
//#include "esp_event.h"
//#include "esp_log.h"
//#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

//#include <iostream>
#include <stdio.h>
#include <string.h>
#include "driver/gpio.h"
#include "lwip/netdb.h"
#include "lwip/api.h"
#include "mdns.h"

#include "driver/ledc.h"
#include "esp_err.h"

#include <stdlib.h>
#include "driver/adc.h"
#include "esp_adc_cal.h"
/* A simple example that demonstrates how to create GET and POST
 * handlers for the web server.
 */

#define EXAMPLE_ESP_WIFI_SSID      CONFIG_ESP_WIFI_SSID
#define EXAMPLE_ESP_WIFI_PASS      CONFIG_ESP_WIFI_PASSWORD
#define EXAMPLE_ESP_WIFI_CHANNEL   CONFIG_ESP_WIFI_CHANNEL
#define EXAMPLE_MAX_STA_CONN       CONFIG_ESP_MAX_STA_CONN

#define LEDC_HS_CH0_CHANNEL    LEDC_CHANNEL_0
#define LEDC_HS_TIMER          LEDC_TIMER_0
#define LEDC_HS_MODE           LEDC_HIGH_SPEED_MODE
#define LEDC_HS_CH0_GPIO       (2)

#define DEFAULT_VREF    1100        //Use adc2_vref_to_gpio() to obtain a better estimate
#define NO_OF_SAMPLES   64          //Multisampling

static const char *TAG = "wifi softAP Web";
int status=0;

uint32_t adc_reading = 0;
static esp_adc_cal_characteristics_t *adc_chars;
static const adc_channel_t channel = ADC_CHANNEL_6;     //GPIO34 if ADC1, GPIO14 if ADC2
static const adc_atten_t atten = ADC_ATTEN_DB_11;
static const adc_unit_t unit = ADC_UNIT_1;

static esp_err_t hello_get_handler(httpd_req_t *req)
{
    char*  buf;
    size_t buf_len;// Length buf

    /* Get header value string length and allocate memory for length + 1,
     * extra byte for null termination */
    buf_len = httpd_req_get_hdr_value_len(req, "Host") + 1;//return length
    if (buf_len > 1) {
        //ESP_LOGI(TAG, "Found header => : %d", buf_len);
        buf = malloc(buf_len);//จองหน่วยความจำ
        /* Copy null terminated value string into buffer */
        if (httpd_req_get_hdr_value_str(req, "Host", buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG, "Found header => Host: %s", buf);
        }
        free(buf);// คืนหน่วยความจำ
    }
    buf_len = httpd_req_get_url_query_len(req) + 1;
    if (buf_len > 1) {
        buf = malloc(buf_len);
        if (httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK) {
            ESP_LOGI(TAG, "Found URL query => %s", buf);
            char param[32];
            /* Get value of expected key from query string */
            if (httpd_query_key_value(buf, "pin", param, sizeof(param)) == ESP_OK) {
                ESP_LOGI(TAG, "Received query parameter => pin=%s", param);
                status = atoi(param);
           }
        }
        free(buf);
    }

    /* Get handle to embedded file upload script */
    extern const unsigned char upload_silder_start[] asm("_binary_silder_html_start");
    extern const unsigned char upload_silder_end[]   asm("_binary_silder_html_end");
    const size_t upload_silder_size = (upload_silder_end - upload_silder_start);
    extern const uint8_t plotly_start[] asm("_binary_plotly_latest_min_js_start");
    extern const uint8_t plotly_end [] asm (" _ binary_plotly_latest_min_js_end ");
    const size_t plotly_size = (plotly_end - plotly_start);

    /* Add file upload form and script which on execution sends a POST request to /upload */
    httpd_resp_send_chunk(req, (const char *)plotly_start, plotly_size);
    httpd_resp_send_chunk(req, (const char *)upload_silder_start, upload_silder_size);

    /* Send empty chunk to signal HTTP response completion */
    httpd_resp_sendstr_chunk(req, NULL);
    //char* resp_str = "<div class=\"slidecontainer\"><input type=\"range\" min=\"1\" max=\"100\" value=\"50\" class=\"slider\" id=\"myRange\"><p>Value: <span id=\"demo\"></span></p></div><script>var slider = document.getElementById(\"myRange\");var output = document.getElementById(\"demo\");output.innerHTML = slider.value;slider.oninput = function() {output.innerHTML = this.value;}var httpRequest = new XMLHttpRequest();httpRequest.open(\"GET\", \"/?pin=\"+slider, true);httpRequest.send();</script>";
    //httpd_resp_send(req, resp_str, strlen(resp_str)); //strlen return length

    
   
    /* After sending the HTTP response the old HTTP request
     * headers are lost. Check if HTTP request headers can be read now. */
    if (httpd_req_get_hdr_value_len(req, "Host") == 0) {
        ESP_LOGI(TAG, "Request headers lost");
    }
    return ESP_OK;
}

static const httpd_uri_t hello = {
    .uri       = "/",
    .method    = HTTP_GET,
    .handler   = hello_get_handler,
    /* Let's pass response string in user
     * context to demonstrate it's usage */
    .user_ctx  = "Hello World!"
};


static httpd_handle_t start_webserver(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();

    // Start the httpd server
    ESP_LOGI(TAG, "Starting server on port: '%d'", config.server_port);
    if (httpd_start(&server, &config) == ESP_OK) {
        // Set URI handlers=ตัวจัดการ
        ESP_LOGI(TAG, "Registering URI handlers");
        httpd_register_uri_handler(server, &hello);
        //httpd_register_uri_handler(server, &echo);
       // httpd_register_uri_handler(server, &ctrl);
        return server;
    }

    ESP_LOGI(TAG, "Error starting server!");
    return NULL;
}

static void stop_webserver(httpd_handle_t server)
{
    // Stop the httpd server
    httpd_stop(server);
}
static void wifi_event_handler(void* arg, esp_event_base_t event_base,int32_t event_id, void* event_data)
{
    if (event_id == WIFI_EVENT_AP_STACONNECTED) {
        wifi_event_ap_staconnected_t* event = (wifi_event_ap_staconnected_t*) event_data;
        ESP_LOGI(TAG, "station "MACSTR" join, AID=%d",
                 MAC2STR(event->mac), event->aid);
    } else if (event_id == WIFI_EVENT_AP_STADISCONNECTED) {
        wifi_event_ap_stadisconnected_t* event = (wifi_event_ap_stadisconnected_t*) event_data;
        ESP_LOGI(TAG, "station "MACSTR" leave, AID=%d",
                 MAC2STR(event->mac), event->aid);
    }
}
void wifi_init_softap()
{
    //tcpip_adapter_init();
   // ESP_ERROR_CHECK(esp_event_loop_create_default());

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));

    wifi_config_t wifi_config = {
        .ap = {
            .ssid = EXAMPLE_ESP_WIFI_SSID,
            .ssid_len = strlen(EXAMPLE_ESP_WIFI_SSID),
            .channel = EXAMPLE_ESP_WIFI_CHANNEL,
            .password = EXAMPLE_ESP_WIFI_PASS,
            .max_connection = EXAMPLE_MAX_STA_CONN,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        },
    };
    if (strlen(EXAMPLE_ESP_WIFI_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_softap finished. SSID:%s password:%s channel:%d",
             EXAMPLE_ESP_WIFI_SSID, EXAMPLE_ESP_WIFI_PASS, EXAMPLE_ESP_WIFI_CHANNEL);
}

static void print_char_val_type(esp_adc_cal_value_t val_type)
{
    if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) {
        printf("Characterized using Two Point Value\n");
    } else if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) {
        printf("Characterized using eFuse Vref\n");
    } else {
        printf("Characterized using Default Vref\n");
    }
}

void app_main()
{
    //Configure ADC
    if (unit == ADC_UNIT_1) {
        adc1_config_width(ADC_WIDTH_BIT_12);
        adc1_config_channel_atten(channel, atten);
    }

    //Characterize ADC
    adc_chars = calloc(1, sizeof(esp_adc_cal_characteristics_t));
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize(unit, atten, ADC_WIDTH_BIT_12, DEFAULT_VREF, adc_chars);
    print_char_val_type(val_type);
    
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_13_BIT, // resolution of PWM duty
        .freq_hz = 5000,                      // frequency of PWM signal
        .speed_mode = LEDC_HS_MODE,           // timer mode
        .timer_num = LEDC_HS_TIMER,            // timer index
        .clk_cfg = LEDC_AUTO_CLK,              // Auto select the source clock
    };
    // Set configuration of timer0 for high speed channels
    ledc_timer_config(&ledc_timer);

    static httpd_handle_t server = NULL;

    ESP_ERROR_CHECK(nvs_flash_init());
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    //ESP_LOGI(TAG,"%s",slider);
    ESP_LOGI(TAG, "ESP_WIFI_MODE_AP");
    wifi_init_softap();
    server = start_webserver();

    while (1) {
        ledc_channel_config_t ledc_channel = {
            .channel    = LEDC_HS_CH0_CHANNEL,
            .duty       = 0,
            .gpio_num   = LEDC_HS_CH0_GPIO,
            .speed_mode = LEDC_HS_MODE,
            .hpoint     = 0,
            .timer_sel  = LEDC_HS_TIMER
        };

        ledc_channel_config(&ledc_channel);

        printf("LEDC set duty = %d without fade\n", status);
            ledc_set_duty(ledc_channel.speed_mode, ledc_channel.channel, status);
            ledc_update_duty(ledc_channel.speed_mode, ledc_channel.channel);
        //vTaskDelay(1000 / portTICK_PERIOD_MS);
        
        //Multisampling
        for (int i = 0; i < NO_OF_SAMPLES; i++) {
            if (unit == ADC_UNIT_1) {
                adc_reading += adc1_get_raw((adc1_channel_t)channel);
            }
        }
        adc_reading /= NO_OF_SAMPLES;
        //Convert adc_reading to voltage in mV
        uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, adc_chars);
        adc_reading = adc_reading/40.95;
        printf("Raw: %d\tVoltage: %dmV\n", adc_reading, voltage);
        vTaskDelay(pdMS_TO_TICKS(500));
    }

}
