#ifndef __MCP23S17__
#define __MCP23S17__

#include <stdint.h>
#include<stdio.h>
#include "spi.h"

#define PIN(P,B) ((P<<5)|B)
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

enum {
        MCP_IODIRA,     MCP_IODIRB,
        MCP_IPOLA,      MCP_IPOLB,
        MCP_GPINTENA,   MCP_GPINTENB,
        MCP_DEFVALA,    MCP_DEFVALB,
        MCP_INTCONA,    MCP_INTCONB,
        MCP_IOCONA,     MCP_IOCONB,
        MCP_GPPUA,      MCP_GPPUB,
        MCP_INTFA,      MCP_INTFB,
        MCP_INTCAPA,    MCP_INTCAPB,
        MCP_GPIOA,      MCP_GPIOB,
        MCP_OLATA,      MCP_OLATB
    };

uint8_t _reg[22];   // Local mirrors of the 22 internal registers of the MCP23S17 chip
uint8_t _addr = 0; // é o endereço do componenet, que pé definido como 0 pela gente arbitrairamente

_reg[MCP_IODIRA] = 0xFF;
_reg[MCP_IODIRB] = 0xFF;
_reg[MCP_IPOLA] = 0x00;
_reg[MCP_IPOLB] = 0x00;
_reg[MCP_GPINTENA] = 0x00;
_reg[MCP_GPINTENB] = 0x00;
_reg[MCP_DEFVALA] = 0x00;
_reg[MCP_DEFVALB] = 0x00;
_reg[MCP_INTCONA] = 0x00;
_reg[MCP_INTCONB] = 0x00;
_reg[MCP_IOCONA] = 0x18;
_reg[MCP_IOCONB] = 0x18;
_reg[MCP_GPPUA] = 0x00;
_reg[MCP_GPPUB] = 0x00;
_reg[MCP_INTFA] = 0x00;
_reg[MCP_INTFB] = 0x00;
_reg[MCP_INTCAPA] = 0x00;
_reg[MCP_INTCAPB] = 0x00;
_reg[MCP_GPIOA] = 0x00;
_reg[MCP_GPIOB] = 0x00;
_reg[MCP_OLATA] = 0x00;
_reg[MCP_OLATB] = 0x00;

void mcp23S17_init();
void writeAll();
void le_registrador(uint8_t addr);

void mcp23S17_configura_pino(uint8_t pino, uint8_t modo);
void mcp23S17_escreve_pino(uint8_t pino, uint8_t valor);
uint8_t mcp23S17_le_pino(uint8_t pino);
void escreve_no_registrador(uint8_t addr);

#endif
