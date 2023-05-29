#include <stdio.h>

#define sum_marco(a,b) ((a)+(b))

// Dấu "\" được dùng để viết liền dòng khi xuống dòng
#define CREATE_FUNC(tenHam, noiDung) \
void tenHam() { \
    printf("%s\n", noiDung); \
}

CREATE_FUNC(test, "abccc");

static inline int sum_inline(int a, int b){
    return a+b;
}

int sum_func(int a, int b){
    return a + b;
}

int main(){
    printf("a + b = %d\n",sum_marco(7,9)); // dùng hàm Marco thì vị trí này sẽ được thay ngay bằng 7+9

    test();

    printf("inline a + b = %d\n",sum_inline(8,4));

    printf("func a + b = %d\n",sum_func(6,3));
    return 0;
}