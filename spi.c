#include "spi.h"
#include "digital.h"
#include "delay.h"

uint8_t PINO_CS = PIN(20, 0);
uint8_t PINO_MISO = PIN(21, 0);
uint8_t PINO_MOSI = PIN(22, 0);
uint8_t PINO_CLOCK = PIN(23, 0);


void spi_habilita(){
    pinMode(PINO_CS, OUTPUT);
    digitalWrite(PINO_CS, LOW);
} // coloca o CS (enable / disable do componente) para 0, isto é, liga o dispositivo


void spi_desabilita(){
    pinMode(PINO_CS, OUTPUT);
    digitalWrite(PINO_CS, HIGH);
} // coloca o CS (enable / disable do componente) para 1, isto é, desliga o dispositivo


uint8_t spi_write(uint8_t byte){
    pinMode(PINO_MOSI, OUTPUT);
    uint8_t valor = 0;
    uint8_t bit = 0;
    for(uint8_t x = 0; x < 8; x++){
        bit = (byte >> (7 - x))&1;
        digitalWrite(PINO_MOSI, bit);
        digitalWrite(PINO_CLOCK, HIGH);
        delay_ms(50);
        valor = (valor << 1)|digitalRead(PINO_MISO);
        digitalWrite(PINO_CLOCK, LOW);
        delay_ms(50); 
    }
    return valor;
} 