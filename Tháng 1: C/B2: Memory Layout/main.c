#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    //Khai báo mảng ban đầu dùng malloc
    uint8_t *arr = (uint8_t *)malloc(sizeof(uint8_t)*5);

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("i = %d \n",arr[i]);
    }
    
    //Thay đổi kích thước mảng dùng realloc

    arr = realloc(arr, sizeof(uint8_t)*3);

    for (int i = 0; i < 5; i++)
    {
        arr[i] = 2*i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("i = %d \n",arr[i]);
    }

    // Khi dùng cấp phát động thì cần dùng lệnh free để thu hồi bộ nhớ
    free(arr);
    return 0;
}