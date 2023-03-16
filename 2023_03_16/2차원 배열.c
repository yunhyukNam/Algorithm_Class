#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROW     3
#define NUM_COL     3

void inputMat();
void matrixAdd();
void matrixSub();
void matrixMul();
void printMat();

int main(void){
    int matA[NUM_ROW][NUM_COL] = {{0, }};
    int matB[NUM_ROW][NUM_COL] = {{0, }};

    srand(time(NULL));

    inputMat(matA, NUM_ROW, NUM_COL);
    inputMat(matB, NUM_ROW, NUM_COL);

    printf("     [ Matrix A ]\n");
    printMat(matA, NUM_ROW, NUM_COL);
    
    printf("     [ Matrix B ]\n");
    printMat(matB, NUM_ROW, NUM_COL);

    int matAdd[NUM_ROW][NUM_COL] = {{0, }};
    matrixAdd(matAdd, matA, matB, NUM_ROW, NUM_COL);
    
    printf("   [ Add Matrix  ]\n");
    printMat(matAdd, NUM_ROW, NUM_COL);

    int matSub[NUM_ROW][NUM_COL] = {{0, }};
    matrixSub(matSub, matA, matB, NUM_ROW, NUM_COL);

    printf("   [ Sub Matrix  ]\n");
    printMat(matSub, NUM_ROW, NUM_COL);

    int matMul[NUM_ROW][NUM_COL] = {{0, }};
    matrixMul(matMul, matA, matB, NUM_ROW, NUM_COL);

    printf("   [ Mul Matrix  ]\n");
    printMat(matMul, NUM_ROW, NUM_COL);
}

void  inputMat(int (*mat)[NUM_COL], int row, int col){
    int i, j, ran;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mat[i][j] =  rand() % 8;
        }
    }
}

void matrixAdd(int mat[][NUM_COL],  int matA[][NUM_COL], int matB[][NUM_COL], int row, int col){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mat[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void matrixSub(int mat[][NUM_COL],  int matA[][NUM_COL], int matB[][NUM_COL], int row, int col){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mat[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void matrixMul(int mat[][NUM_COL],  int matA[][NUM_COL], int matB[][NUM_COL], int row, int col){
    int i, j, k;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            for(k=0; k<row; k++){
                mat[i][j] = matA[i][j] * matB[i][j];
            }
        }
    }
}

void printMat(int matrix[][NUM_COL], int row, int col){
    int i, j;

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%3d\t", matrix[i][j]);
        }
        printf("\n");
    }
}