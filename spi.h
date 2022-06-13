#ifndef __SPI__
#define __SPI__

#include <stdint.h>

#define PIN(P,B) ((P<<5)|B)
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0



// CS = Chip Select
// SPI um protocolo de comunicação da nossa versão
// I2c que a gente poderia mas não vai utilizar porque nosso componente está preparado apenas para comunicação SPI

//
//
//
// labirinto32


void spi_habilita(); // coloca o CS (enable / disable do componente) para 0, isto é, liga o dispositivo
void spi_desabilita(); // coloca o CS (enable / disable do componente) para 1, isto é, desliga o dispositivo
uint8_t spi_write(uint8_t byte); // Escreve no MOSI (master output, slave input). Começa do bit mais significativo para o menos significativo

// algo write
// primeiro escrever o byte no pino mosi
// colocar clock nivel alto
// dar delay
// ler miso e salvar em global (leitura bit a bit) a cada borda de clock pega um valor de volta
// termina baixando o clock

#endif
