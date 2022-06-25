#include "spi.h"
#include "digital.h"
#include "delay.h"


void spi_init(){
    pinMode(pino_CS, OUTPUT);
    pinMode(pino_CLOCK, OUTPUT);
    pinMode(pino_MOSI, OUTPUT);
    pinMode(pino_MISO, INPUT);
}


void spi_habilita(){
    pinMode(pino_CS, OUTPUT);
    digitalWrite(pino_CS, LOW);
} // coloca o CS (enable / disable do componente) para 0, isto é, liga o dispositivo


void spi_desabilita(){
    pinMode(pino_CS, OUTPUT);
    digitalWrite(pino_CS, HIGH);
} // coloca o CS (enable / disable do componente) para 1, isto é, desliga o dispositivo


uint8_t spi_write(uint8_t byte){
    pinMode(pino_MOSI, OUTPUT);
    uint8_t valor = 0;
    uint8_t bit = 0;
    for(uint8_t x = 0; x < 8; x++){
        bit = (byte >> (7 - x))&1;
        digitalWrite(pino_MOSI, bit);
        digitalWrite(pino_CLOCK, HIGH);
        delay_ms(50);
        valor = (valor << 1)|digitalRead(pino_MISO);
        digitalWrite(pino_CLOCK, LOW);
        delay_ms(50); 
    }
    return valor;
} 