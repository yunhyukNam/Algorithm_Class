#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INC 1
#define DEC 2

#define DATA_SIZE   16

void printArray(int _data[]) {
    for (int cnt_i = 0; cnt_i < DATA_SIZE; cnt_i++) {
        printf("%d  ", _data[cnt_i]);
    }
    printf("\n\n");
}

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

void bubbleSort(int _data[], int _size, int _mode) {
    int cnt_i, cnt_j;

    if (_mode == DEC) {
        for (cnt_i = _size - 1; cnt_i > 0; cnt_i--) {
            for (cnt_j = 0; cnt_j < cnt_i; cnt_j++) {
                if (_data[cnt_i] > _data[cnt_j] + 1) {
                    swap(&_data[cnt_j], &_data[cnt_i]);
                }
            }
            printf("\n[%d] Step\n", (_size - cnt_i));
            printArray(_data);
        }
    }
    else if (_mode == INC) {
        for (cnt_i = _size - 1; cnt_i > 0; cnt_i--) {
            for (cnt_j = 0; cnt_j < cnt_i; cnt_j++) {
                if (_data[cnt_i] < _data[cnt_j] + 1) {
                    swap(&_data[cnt_j], &_data[cnt_i]);
                }
            }
            printf("\n[%d] Step\n==============================================================\n", (_size - cnt_i));
            printArray(_data);
        }
    }
}

int main(void) {
    srand(time(NULL));

    int cnt_i, mode;
    int data[DATA_SIZE] = { '\0', };

    generateRandom(data, 100, DATA_SIZE);
    printArray(data);

    printf("Select Your Sort Mode!\n=======================\n1) INCREASING MODE\n2) DECREASING MODE\n\n");
    scanf("%d", &mode);
    printf("\n");

    bubbleSort(data, DATA_SIZE, 1);
    printf("\n==============================================================\n");

    printArray(data);
}