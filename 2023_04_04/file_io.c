#define _NO_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

typedef struct STUDENT{
    char name[128];
    char major[128];
    int age;
} STUDENT;

void FileIO_Lab3();
void test1();
void test2();

int main(){
    // FileIO_Lab3();
    // test1();
    test2();

    return 0;
}

void FileIO_Lab3(){
    FILE *fp = NULL;
    fp = fopen("FileIO_Lab3.txt", "wt");

    if(fp == NULL){
        fprintf(stderr, "the file is exist!");

        return;
    }

    char buf[128] = {0x00, };

    printf("Enter the word : ");
    if(fgets(buf, sizeof(buf), stdin) != NULL){
        fputs(buf, fp);
    }
    
    if(fp != NULL){
        fclose(fp);
    }

    fp = fopen("FileIO_Lab3.txt", "rt");

    if(fp == NULL){
        fprintf(stderr, "the file is exist!");

        return;
    }
    
    printf("Print the your Message : ");
    
    if(fgets(buf, sizeof(buf), fp) != NULL){
        fputs(buf, stdout);
    }
}

void test1(){
    STUDENT stu[3] = {{0x00, }};

    FILE *fp = NULL;
    fp = fopen("data.bin", "wb");

    int cnt_i;
    for(cnt_i = 0; cnt_i < 3; cnt_i++){
        printf("Enter the Name, Major, Age : ");
        scanf("%s%s%d", &stu[cnt_i].name, &stu[cnt_i].major, &stu[cnt_i].age);

        fwrite(&stu[cnt_i], sizeof(STUDENT), 1, fp);
    }
}

void test2(){
    int size = 0;

    FILE* fp = NULL;
    char buf[128] = {0x00, };

    fp = fopen("test.txt", "r");
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    printf("File Size : %d\n", size);

    printf("Reading File First Attempt : ");
    fgets(buf, sizeof(buf), fp);

    printf("\nReading File Second Attempt : ");
    rewind(fp);
    fgets(buf, sizeof(buf), fp);

    printf("%s", buf);

    if(fp != NULL){
        fclose(fp);
    }
}




