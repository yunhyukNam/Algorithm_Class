#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap_wrong(int a, int b);
void test1();

/*void swap_wrong(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}*/

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int** a, int** b){
    int temp;
    temp = **a;
    **a = **b;
    **b = temp;
}

void test1(){
    int a, b;
    int* pa = &a, * pb = &b;

    printf("두 수를 입력해주세요 : ");
    scanf("%d %d", &a, &b);
    
    printf("\n함수 실행 전 | a: %d, b: %d\n", a, b);

    //swap_wrong(a, b);
    //printf("\nswap_wrong 함수 실행 후 | a: %d, b: %d\n", a, b);

    swap(&a, &b);
    printf("\nswap 함수 실행 후 | a: %d, b: %d\n", a, b);

    swap2(&pa, &pb);
    printf("\nswap2 함수 실행 후 | a: %d, b: %d\n", a, b);
}

int main(void){
    test1();
}