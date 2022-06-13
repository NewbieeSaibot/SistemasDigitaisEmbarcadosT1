#ifndef __MCP23S17__
#define __MCP23S17__

#include <stdint.h>

#define PIN(P,B) ((P<<5)|B)
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

void mcp23S17_init();
void mcp23S17_configura_pino(uint8_t pb, uint8_t tipo);
void mcp23S17_escreve_pino(uint8_t pb, uint8_t valor);
uint_8 mcp23S17_le_pino(uint8_t pb);

#endif
