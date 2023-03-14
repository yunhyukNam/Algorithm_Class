#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(int data[], int size){
    int cnt;

    printf("%d개의 데이터를 입력하세요 : ", size);

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