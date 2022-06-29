#include "spi.h"
#include "delay.h"

uint8_t CS;
uint8_t MISO;
uint8_t MOSI;
uint8_t CLOCK;

void spi_init(){
    CS = PIN(0,9);
    MISO = PIN(0,10);
    MOSI = PIN(0,8);
    CLOCK = PIN(0,7);
    pinMode(CS, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(MOSI, OUTPUT);
    pinMode(MISO, INPUT);
    digitalWrite(CLOCK, 0);
    digitalWrite(CS, 1);
}


void spi_habilita(){
    digitalWrite(CS, LOW);
} // coloca o CS (enable / disable do componente) para 0, isto é, liga o dispositivo


void spi_desabilita(){
    digitalWrite(CS, HIGH);
} // coloca o CS (enable / disable do componente) para 1, isto é, desliga o dispositivo


uint8_t spi_write(uint8_t byte){
    uint8_t valor = 0;
    uint8_t bit = 0;
    for(uint8_t x = 0; x < 8; x++){
        bit = (byte >> (7 - x))&1;
        digitalWrite(MOSI, bit);
        digitalWrite(CLOCK, HIGH);
        delay_us(50);
        valor = (valor << 1)|digitalRead(MISO);
        digitalWrite(CLOCK, LOW);
        delay_us(50); 
    }
    return valor;
} 
