#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Temp.h"

int main(){
    int data[10] = { 0, };
    int size, cnt, total;

    for(cnt = 0;cnt<3;cnt++){
        input(data, sizeof(data) / sizeof(int));
        total = getTotal(data, sizeof(data) / sizeof(int));

        printf("total : %d\n\n", total);
    }

    return 0;
}