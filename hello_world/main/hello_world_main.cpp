#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

class MyClass
{
    int a;

public:
    void set(int val)
    {
        a = val;
    }

    int get()
    {
        return a;
    }
};

int f()
{
    MyClass c;

    c.set(100);

    return c.get();
}

// app_main() is the entry point for our programs and it must be a C function:

#ifdef __cplusplus
extern "C"
{
#endif

    void app_main()
    {
        printf("Hello world!\n");

        /* Print chip information */
        esp_chip_info_t chip_info;
        esp_chip_info(&chip_info);
        printf("This is ESP8266 chip with %d CPU cores, WiFi, ", chip_info.cores);

        printf("silicon revision %d, ", chip_info.revision);

        printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024), (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

        for (int i = 10; i >= 0; i--)
        {
            printf("Restarting in %d seconds...\n", i);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }

        // for testing the C++ compiler:
        int v = f();
        printf("Value is: %d\n", v);
        vTaskDelay(500 / portTICK_PERIOD_MS);

        printf("Restarting now.\n");
        fflush(stdout);
        esp_restart();
    }

#ifdef __cplusplus
}
#endif