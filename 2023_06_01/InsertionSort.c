#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INC 1
#define DEC 0

#define SIZE    16

void generateRandom(int _data[], int _mod, int _size) {
    int cnt_i;

    for (int cnt_i = 0; cnt_i < _size; cnt_i++) {
        _data[cnt_i] = rand() % 100;
    }

    printf("Congratulations!! Your Number init Complete!!!\n\n");        
}

void swap(int *_opA, int *_opB) {
    int tmp;

    tmp = *_opA;
    *_opA = *_opB;
    *_opB = tmp;
}

void selectionSort(int _data[], int _size, int _mode) {
    int cnt_i, cnt_j;
    int min, tmp;

    if (_mode == INC) {
        for (cnt_i = 0; cnt_i < (_size - 1); cnt_i++) {
            min = cnt_i;

            for (cnt_j = cnt_i + 1; cnt_j < _size; cnt_j++) {
                if (_data[min] > _data[cnt_j]) {
                    min = cnt_j;
                }
            }
            swap(&_data[cnt_i], &_data[min]);   
        }
        printf("Congratulations!! Sort Complete!!!\n");      
    }
    else if (_mode == DEC) {
        for (cnt_i = 0; cnt_i < (_size - 1); cnt_i++) {
            min = cnt_i;

            for (cnt_j = cnt_i + 1; cnt_j < _size; cnt_j++) {
                if (_data[min] < _data[cnt_j]) {
                    min = cnt_j;
                }
            }
            swap(&_data[cnt_i], &_data[min]);   
        }
        printf("Congratulations!! Sort Complete!!!\n"); 
    }
}

void insertionSort(int _data[], int _size, int _mode) {
    int cnt_i, cnt_j;
    int tmp;


}

int main(void) {
    srand(time(NULL));

    int cnt_i, mode;

    int S[SIZE] = {'\0', };
    int U[SIZE] = {'\0', };

    generateRandom(S, 100, SIZE);
    generateRandom(U, 100, SIZE);
    printf("\n");


    printf("Select Your Sort Mode!\n=======================\n1) INCREASING MODE\n2) DECREASING MODE\n\n");
    scanf("%d", &mode);
    printf("\n");

    printf("  [ Array U ]   \n");
    selectionSort(S, SIZE, mode);
    for (cnt_i = 0; cnt_i < SIZE; cnt_i++) {
        printf("%d  ", S[cnt_i]);
    }
    printf("\n");    

    printf("  [ Array U ]   \n");
    for (cnt_i = 0; cnt_i < SIZE; cnt_i++) {
        printf("%d  ", U[cnt_i]);
    }

    printf("Select Your Sort Mode!\n=======================\n1) INCREASING MODE\n2) DECREASING MODE\n\n");
    scanf("%d", &mode);
    printf("\n");

    insertionSort(U, );

}