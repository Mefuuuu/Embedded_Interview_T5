#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
//uint8_t PORTB = 0b11111111;

void readByte(uint8_t byte){
    uint8_t temp;
    printf("0b");
    for (uint8_t i = 0; i < 8; i++)
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
}s_pins;

typedef enum{
    LOW,
    HIGH,
}s_status;

void pinHigh(s_pins pin){
    PORTA = PORTA | (0b10000000 >> pin);
}

void pinLow(s_pins pin){
    PORTA = PORTA & ~(0b10000000 >> pin);
}

void digitalWrite(s_pins pin, s_status status){
    if(status == LOW){
        pinLow(pin);
    }
    else pinHigh(pin);
}

int main(){
    
    // readByte(test);
    // pinHigh(PIN4);
    // readByte(PORTA);
    // pinLow(PIN5);
    // readByte(PORTB);
    digitalWrite(PIN3,HIGH);
    readByte(PORTA);

    digitalWrite(PIN5,HIGH);
    readByte(PORTA);

    digitalWrite(PIN3,LOW);
    readByte(PORTA);

    return 0;
}