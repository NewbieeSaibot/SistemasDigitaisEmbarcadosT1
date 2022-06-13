#include "mcp23S17.h"
#include "LPC17xx.h"
#include "spi.h"


void mcp23S17_init(){
    _spi->begin();
    ::pinMode(_cs, OUTPUT);
    ::digitalWrite(_cs, HIGH);
    uint8_t cmd = 0b01000000;
    ::digitalWrite(_cs, LOW);
    _spi->transfer(cmd);
    _spi->transfer(MCP_IOCONA);
    _spi->transfer(0x18);
    ::digitalWrite(_cs, HIGH);
    writeAll();
}


void mcp23S17_configura_pino(uint8_t pb, uint8_t tipo){

}


void mcp23S17_escreve_pino(uint8_t pb, uint8_t valor){

}


uint_8 mcp23S17_le_pino(uint8_t pb){

}
