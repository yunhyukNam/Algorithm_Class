#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE   16

#define INC 1
#define DEC 2

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

int main(void) {
    srand(time(NULL));

    int cnt_i, mode;
    int data[DATA_SIZE] = { '\0', };

    generateRandom(data, 100, DATA_SIZE);
    for (cnt_i = 0; cnt_i < DATA_SIZE; cnt_i++) {
        printf("%d  ", data[cnt_i]);
    }
    printf("\n\n\n");


    printf("Select Your Sort Mode!\n=======================\n1) INCREASING MODE\n2) DECREASING MODE\n\n");
    scanf("%d", &mode);
    printf("\n");

    selectionSort(data, DATA_SIZE, 1);
    printf("===================================\n");

    for (cnt_i = 0; cnt_i < DATA_SIZE; cnt_i++) {
        printf("%d  ", data[cnt_i]);
    }
    printf("\n");
}