#include <stdio.h>

void tong(int a, int b){
    printf("Tong la: %d \n",a+b);
}

void hieu(int a, int b){
    printf("Hieu la: %d\n ",a-b);
}

void tich(int a,int b ){
   printf("Tich la: %d\n ",a*b);
}

void thuong(int a,int b ){
   printf("Thuong la: %f\n",(float)a/b);
}

//con trỏ vào hàm
void tinhToan(int a,int b, void (*ptr)(int,int )){
    printf("Chuong trinh toan \n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{

    int i = 10; 

    double d = 15.6; 

    char c = 'A';

    void *ptr = &i; 

    //con trỏ void
    printf("i = %d \n",*(int*)ptr);
    ptr = &d; 
    printf("i = %f \n",*(double *)ptr);
    ptr = &c; 
    printf("i = %c \n",*(char *)ptr);
    ptr = &tong; 

    //con trỏ hàm
    ((void (*)(int,int))ptr)(9,16); 

    char* array = "hello"; //phan vung text 

    char array1[] = "hello"; // phan vung stack 

    char* array2[]= {"Hi","hello","world"};

    printf("test: %c\n", *(*(array2+1)+3));

    //con trỏ point to point
    int a = 15; 

    int *ptr2 = &a; 

    int **ptp = &ptr2; 

    printf("test : %d \n",**ptp);
    return 0;
}