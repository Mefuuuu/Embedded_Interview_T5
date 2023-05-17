#include <stdio.h>
#include <stdint.h>

void readByte(uint8_t byte){
    for(int i=7;i>=0;i--){
        printf("%d",(byte>>i) & 1);
    }
}

int main(){
    uint8_t test = 0b10010001;

    readByte(test);
    return 0;
}