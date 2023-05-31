#include <stdio.h>
#include <stdint.h>

void sortList(uint8_t array[],uint8_t size){
    for(int i=0;i<size;i++){
        int min_index = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min_index])
                min_index = j;
        }
        if(min_index !=i){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }

    printf("\n");
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == array[i+1])
        {
            count++;
        }
        else {
            printf("%d xuat hien %d lan\n",array[i],count);
            count = 1;
        }
    }
}

int main(){
    uint8_t size;
    scanf("%d",&size);

    uint8_t array[size];
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    sortList(array,size);

    return 0;
}