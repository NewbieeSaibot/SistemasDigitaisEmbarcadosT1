#include <stdio.h>
#include <stdint.h>
#include "mcp23s17.h"


int main() {
    mcp23S17_init();
    mcp23S17_configura_pino(15, INPUT); // O pino 15 é o último pino do port B
    mcp23S17_configura_pino(0 , OUTPUT); // primeiro pino do port A. A funcao se encarrega internamente de selecionar o correto.

    while(1) {
        mcp23S17_escreve_pino(0, HIGH);
        delay_ms(1000);
        mcp23S17_escreve_pino(0, LOW);
        delay_ms(1000);

        if (mcp23S17_le_pino(15)==HIGH) {
            printf("Botao em VCC\n");
        }
            else printf("Botao em GND\n");
        }
}
