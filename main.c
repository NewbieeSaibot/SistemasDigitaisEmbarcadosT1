#include <stdio.h>
#include <stdint.h>
#include "mcp23s17.h"


int main() {
    mcp23S17_init();
    mcp23S17_configura_pino(3, OUTPUT);
    mcp23S17_configura_pino(15, INPUT); // O pino 15 é o último pino do port B
    mcp23S17_configura_pino(9 , OUTPUT); // primeiro pino do port A. A funcao se encarrega internamente de selecionar o correto.

    while(1) {
        mcp23S17_escreve_pino(9, HIGH);
        delay_ms(1000);

        if (mcp23S17_le_pino(15)==LOW) {
            mcp23S17_escreve_pino(3, HIGH);
        }
            else mcp23S17_escreve_pino(3, LOW);
        }
}
