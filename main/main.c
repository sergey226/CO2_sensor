#include <stdio.h>
#include "esp_log.h"
#include "driver/uart.h"
#include "string.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define TXD_PIN 4
#define RXD_PIN 5

#define RX_BUF_SIZE 1024

void process(uint8_t *m) {
  for (int i=0; i<8; ++i) {
    printf("Byte %d = %d, ", i, m[i]);
  }
  int result = (int)m[3]*256 + m[4];
  printf("CO2 reading = %d\n", result);
}

void app_main(void)
{
  uart_config_t uart_config = {
    .baud_rate = 9600,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .rx_flow_ctrl_thresh = 122,
  };
  uart_param_config(UART_NUM_1 ,&uart_config);
  uart_set_pin(UART_NUM_1,TXD_PIN,RXD_PIN,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE);
  uart_driver_install(UART_NUM_1, RX_BUF_SIZE, 0,0,NULL,0);
  while (true) {
    char command[] = "\xFE\x44\x00\x08\x02\x9F\x25"; // Command 8 byte command to read RAM CRC = 0x259F
    //printf("sending: %s\n", command);
    uart_write_bytes(UART_NUM_1, command, sizeof(command));

    vTaskDelay(500 / portTICK_PERIOD_MS);
    uint8_t response[RX_BUF_SIZE];
    uart_read_bytes(UART_NUM_1, response, RX_BUF_SIZE, pdMS_TO_TICKS(1000));
    process(response);
  }

}