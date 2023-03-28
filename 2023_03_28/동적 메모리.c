#define _NO_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>

void dynamic_Lab3_2(void);
void dynamic_Lab3_3(void);
void dynamic_Lab3_4(void);

void inputMat(int* mat[], int rows, int cols, int mod);
void printMat(int* mat[], int rows, int cols);
void matrixAdd(int* addMat[], int* matA[], int* matB[], int rows, int cols);
void matrixMul(int* mulMat[], int* matA[], int* matB[], int rows, int cols);

int **allocMat(int rows, int cols);
void freeMat(int **mat, int rows);

int main(int argc, char *argv[]){
    // dynamic_Lab3_2();
    // dynamic_Lab3_3();
    dynamic_Lab3_4();
}

void dynamic_Lab3_2(void){
    int row, col;
    int **matrix = NULL;
    int cnt_i, cnt_j;

    srand(time(NULL));

    printf("행과 열을 입력하세요. : ");
    scanf("%d %d", &row, &col);

    matrix = (int **)calloc(row, sizeof(int *));
    assert(matrix != NULL);

    for(cnt_i = 0; cnt_i < row; cnt_i++){
        matrix[cnt_i] = (int *)calloc(col, sizeof(int));
        assert(matrix[cnt_i]!= NULL);
    }

    for(cnt_i = 0; cnt_i < row; cnt_i++){
        for(cnt_j = 0; cnt_j < col; cnt_j++){
            matrix[cnt_i][cnt_j] = rand() % 32;
        }
    }

    printf("\t[ Matrix ]\n");

    for(cnt_i = 0; cnt_i < row; cnt_i++){{
        for(cnt_j = 0; cnt_j < col; cnt_j++){
                printf("%d ", matrix[cnt_i][cnt_j]);
            }
            printf("\n");
        }
    }

    for(cnt_i = 0; cnt_i < row; cnt_i++){
        free(matrix[cnt_i]);
    }
}

void dynamic_Lab3_3(void){
    int rows, cols;
    int** matA = NULL,** matB = NULL,** addMat = NULL,** mulMat = NULL;

    int cnt_i, cnt_j;

    printf("Enter the matrix's ROWS & COLS : ");
    scanf("%d %d", &rows, &cols);

    matA = (int**)calloc(rows, sizeof(int *));
    assert(matA != NULL);

    matB = (int**)calloc(rows, sizeof(int *));
    assert(matB != NULL);

    addMat = (int**)calloc(rows, sizeof(int *));
    assert(addMat != NULL);

    mulMat = (int**)calloc(rows, sizeof(int *));
    assert(mulMat != NULL);

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        matA[cnt_i] = (int *)calloc(cols, sizeof(int));
        assert(matA[cnt_i]!= NULL);

        matB[cnt_i] = (int *)calloc(cols, sizeof(int));
        assert(matB[cnt_i]!= NULL);

        addMat[cnt_i] = (int *)calloc(cols, sizeof(int));
        assert(addMat[cnt_i]!= NULL);

        mulMat[cnt_i] = (int *)calloc(cols, sizeof(int));
        assert(mulMat[cnt_i]!= NULL);
    }

    inputMat(matA, rows, cols, 16);
    inputMat(matB, rows, cols, 16);

    printf("\t[ Matrix A ]\n");
    printMat(matA, rows, cols);

    printf("\t[ Matrix B ]\n");
    printMat(matB, rows, cols);

    matrixAdd(addMat, matA, matB, rows, cols);

    printf("\t[ Matrix A + Matrix B ]\n");
    printMat(addMat, rows, cols);

    matrixMul(mulMat, matA, matB, rows, cols);

    printf("\t[ Matrix A * Matrix B ]\n");
    printMat(mulMat, rows, cols);
}

void dynamic_Lab3_4(void){
    int rows, cols;
    int** mat = NULL;

    printf("Enter the matrix's ROWS & COLS : ");
    scanf("%d %d", &rows, &cols);

    mat = allocMat(rows, cols);
    inputMat(mat, rows, cols, 16);

    printMat(mat, rows, cols);

    freeMat(mat, rows);
}

int **allocMat(int rows, int cols){
    int **mat = NULL;
    
    int cnt_i;

    mat = (int**)calloc(rows, sizeof(int*));
    assert(mat != NULL);

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        mat[cnt_i] = (int *)calloc(cols, sizeof(int));
        assert(mat[cnt_i] != NULL);
    }

    return mat;
}

void inputMat(int* mat[], int rows, int cols, int mod){
    int cnt_i, cnt_j;

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        for(cnt_j = 0; cnt_j < cols; cnt_j++){
            mat[cnt_i][cnt_j] = rand() % mod;
        }
    }
}

void printMat(int* mat[], int rows, int cols){
    int cnt_i, cnt_j;

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        for(cnt_j = 0; cnt_j < cols; cnt_j++){
            printf("%d ", mat[cnt_i][cnt_j]);
        }
        printf("\n");
    }
}

void matrixAdd(int* addMat[], int* matA[], int* matB[], int rows, int cols){
    int cnt_i, cnt_j;

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        for(cnt_j = 0; cnt_j < cols; cnt_j++){
            addMat[cnt_i][cnt_j] = matA[cnt_i][cnt_j] + matB[cnt_i][cnt_j];
        }
    }
}

void matrixMul(int* mulMat[], int* matA[], int* matB[], int rows, int cols){
    int cnt_i, cnt_j, cnt_k;

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        for(cnt_j = 0; cnt_j < cols; cnt_j++){
            for(cnt_k = 0; cnt_k < cols; cnt_k++){
                mulMat[cnt_i][cnt_j] = matA[cnt_i][cnt_j] * matB[cnt_i][cnt_j];
            }
        }
    }
}

void freeMat(int* mat[], int rows){
    int cnt_i;

    for(cnt_i = 0; cnt_i < rows; cnt_i++){
        free(mat[cnt_i]);
    }

    free(mat);
}