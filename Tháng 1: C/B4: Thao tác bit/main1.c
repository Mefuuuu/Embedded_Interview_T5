#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
uint8_t PORTB = 0b11111111;

void readByte(uint8_t byte){
    uint8_t temp;
    printf("0b");
    for (uint8_t i = 0; i <=7; i++)
    {
        temp = byte & 0b10000000;
        if(temp != 0)
            printf("1");
        else printf("0");
        byte = byte << 1;
    }
    printf("\n");
}

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
}pins;

void pinHigh(pins pin){
    PORTA = PORTA | (0b10000000 >> pin);
}

void pinLow(pins pin){
    PORTB = PORTB & ~(0b10000000 >> pin); 
}

int main(){
    uint8_t test = 8;
    
    readByte(test);

    pinHigh(PIN7);

    pinHigh(PIN2);

    readByte(PORTA);

    pinLow(PIN1);
    pinLow(PIN6);
    readByte(PORTB);


    return 0;
}