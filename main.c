#include "LPC17xx.h"
#include "digital.h"
#include <stdint.h>
#include "mcp23S17.h"


int main() {
    mcp23S17_init();
    mcp23S17_configura_pino(MCP_PIN_15, INPUT);
    mcp23S17_configura_pino(MCP_PIN_0 , OUTPUT);

    while(1) {
        mcp23S17_escreve_pino(MCP_PIN_0, HIGH);
        delay_ms(1000);
        mcp23S17_escreve_pino(MCP_PIN_0, LOW);
        delay_ms(1000);

        if (mcp23S17_le_pino(MCP_PIN_15)==HIGH) {
            printf("Botao em VCC\n");
        }
            else printf("Botao em GND\n");
        }
}
