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

    printf("�� ���� �Է����ּ��� : ");
    scanf("%d %d", &a, &b);
    
    printf("\n�Լ� ���� �� | a: %d, b: %d\n", a, b);

    //swap_wrong(a, b);
    //printf("\nswap_wrong �Լ� ���� �� | a: %d, b: %d\n", a, b);

    swap(&a, &b);
    printf("\nswap �Լ� ���� �� | a: %d, b: %d\n", a, b);

    swap2(&pa, &pb);
    printf("\nswap2 �Լ� ���� �� | a: %d, b: %d\n", a, b);
}

int main(void){
    test1();
}