idf_component_register(SRCS "softAPWeb.c"
                    INCLUDE_DIRS "."
	            EMBED_FILES "silder.html")

spiffs_create_partition_image(work ../spiffs_image1 FLASH_IN_PROJECT)