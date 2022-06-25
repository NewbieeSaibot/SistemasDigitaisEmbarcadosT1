#ifndef __MCP23S17__
#define __MCP23S17__

#include <stdint.h>
#include<stdio.h>
#include "spi.h"
#include "digital.h"

uint8_t MCP_IODIRA = 0;
uint8_t MCP_IODIRB = 1;
uint8_t MCP_IPOLA = 2;
uint8_t MCP_IPOLB = 3;
uint8_t MCP_GPINTENA = 4;
uint8_t MCP_GPINTENB = 5;
uint8_t MCP_DEFVALA = 6;
uint8_t MCP_DEFVALB = 7;
uint8_t MCP_INTCONA = 8;
uint8_t MCP_INTCONB = 9;
uint8_t MCP_IOCONA = 10;
uint8_t MCP_IOCONB = 11;
uint8_t MCP_GPPUA = 12;
uint8_t MCP_GPPUB = 13;
uint8_t MCP_INTFA = 14;
uint8_t MCP_INTFB = 15;
uint8_t MCP_INTCAPA = 16;
uint8_t MCP_INTCAPB = 17;
uint8_t MCP_GPIOA = 18;
uint8_t MCP_GPIOB = 19;
uint8_t MCP_OLATA = 20;
uint8_t MCP_OLATB = 21;

uint8_t _reg[22];   // Local mirrors of the 22 internal registers of the MCP23S17 chip
uint8_t _addr = 0; // é o endereço do componenet, que pé definido como 0 pela gente arbitrairamente

_reg[MCP_IODIRA] = 255;
_reg[MCP_IODIRB] = 255;
_reg[MCP_IPOLA] = 0;
_reg[MCP_IPOLB] = 0;
_reg[MCP_GPINTENA] = 0;
_reg[MCP_GPINTENB] = 0;
_reg[MCP_DEFVALA] = 0;
_reg[MCP_DEFVALB] = 0;
_reg[MCP_INTCONA] = 0;
_reg[MCP_INTCONB] = 0;
_reg[MCP_IOCONA] = 24;
_reg[MCP_IOCONB] = 24;
_reg[MCP_GPPUA] = 0;
_reg[MCP_GPPUB] = 0;
_reg[MCP_INTFA] = 0;
_reg[MCP_INTFB] = 0;
_reg[MCP_INTCAPA] = 0;
_reg[MCP_INTCAPB] = 0;
_reg[MCP_GPIOA] = 0;
_reg[MCP_GPIOB] = 0;
_reg[MCP_OLATA] = 0;
_reg[MCP_OLATB] = 0;

void mcp23S17_init();
void writeAll();
void le_registrador(uint8_t addr);

void mcp23S17_configura_pino(uint8_t pino, uint8_t modo);
void mcp23S17_escreve_pino(uint8_t pino, uint8_t valor);
uint8_t mcp23S17_le_pino(uint8_t pino);
void escreve_no_registrador(uint8_t addr);

#endif
