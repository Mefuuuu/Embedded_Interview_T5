#include <stdio.h>
#include <stdint.h>

void priceTaxi(int km){
    int price;

    if(km <= 1){
        price = 14000;
        printf("So tien can thanh toan la %d vnd",price);
    }
    else if (km <=30)
        {
            price = 14000 + (km - 1) * 10000;
            printf("So tien can thanh toan la %d vnd",price);
        }
        else if (km > 30)
        {
            price = 14000 + (30-1) * 10000 + (km - 30) *8000;
            printf("So tien can thanh toan la %d vnd",price);
        }
}

int main(){

    int km;
    scanf("%d",&km);

    priceTaxi(km);
    
    return 0;
}