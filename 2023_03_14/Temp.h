#include <stdio.h>

void input(int data[], int size){
    int cnt;

    printf("%d???? ??????? ???????? : ", size);

    for(cnt = 0;cnt<size;cnt++){
        scanf("%d", &data[cnt]);
    }
}
int getTotal(int data[], int size){
    int cnt, total = 0;

    for(cnt = 0;cnt<size;cnt++){
        total += data[cnt];
    }

    return total;
}