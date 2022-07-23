idf_component_register(SRCS "softapweb.c"
                    INCLUDE_DIRS "."
	            EMBED_FILES "silder.html")

#spiffs_create_partition_image(storage ../library FLASH_IN_PROJECT)