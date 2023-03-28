#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void FileIO_Lab0(void);
void FileIO_Lab1(void);

int main(int argc, char *argv){
    // FileIO_Lab0();
    FileIO_Lab1();
    
    return 0;
}

void FileIO_Lab0(void){
    FILE *fp = NULL;
    
    fp = fopen("test.txt", "wt");

    if(fp == NULL){
        fprintf(stderr, "FileIO_Lab0: Failed to open file\n");
    }

    fprintf(fp, "Hello, World as %d!!!\n", 3000);

    if(fp != NULL){
        fclose(fp);
    }
}

void FileIO_Lab1(void){
    FILE *fp = NULL;

    int msg[5] = {0, };

    printf("Input the 5 Numbers : \n");
    
    for(int cnt_i = 0; cnt_i < 5; cnt_i++){
        scanf("%d", &msg[cnt_i]);
    }

    printf("Writing 5 Numbers to a File.\n");
    
    fp = fopen("data1.txt", "wt");

    if(fp == NULL){
        fprintf(stderr, "FileIO_Lab1: Failed to open file\n");
    }

    for(int cnt_i = 0; cnt_i < 5; cnt_i++){
        fprintf(fp, "%d\n", msg[cnt_i]);
    }

    if(fp != NULL){
        fclose(fp);
    }
}