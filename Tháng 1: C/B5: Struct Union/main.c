#include <stdio.h>
#include <stdint.h>

typedef struct
{
    // size struct = tổng các thành viên
    uint16_t arr1[7];
    uint64_t arr4[5];
    uint32_t arr2[2];
    uint8_t arr3[10];

}data_struct;

typedef union
{
    // size union = size thành viên lớn nhất
    // union là bộ nhớ dùng chung nên khi thay đổi member này sẽ ảnh hưởng đến thành viên khác cũng thay đổi
    uint8_t test1[5]; // 5 byte
    uint8_t test2[2]; // 2 byte
}data_union;
 
int main ()
{
    printf("Size struct: %lu\n", sizeof(data_struct));
    printf("Size union: %lu\n", sizeof(data_union));

    data_union data;

    for (int i = 0; i < 5; i++)
    {
        data.test1[i] = i; // 0 1 2 3 4
    }
    
    for (int i = 0; i < 2 ; i++)
    {
        data.test2[i] = 2*i; // 0 2
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",data.test1[i]);
    }
    return 0;
}