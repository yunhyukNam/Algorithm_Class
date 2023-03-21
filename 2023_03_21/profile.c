#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "STUDENT_TYPE.h"

#define ex1_3_NUM 3
#define elite_NUM 5

void ex1_structure(void);
void ex3_structure(void);

void input_Data(PROF *sp, int size);
void elite(PROF *sp, int size);
void ex4_structure(void);

void main(){
    // ex1_structure();
    // ex3_structure();
    ex4_structure();
}

void ex1_structure(void){
    STUDENT s1;

    printf("학생 1 이름 입력 : ");
    scanf("%s", s1.pf.name);
    
    printf("학생 1 나이 입력 : ");
    scanf("%d", &s1.pf.age);

    printf("학생 1 키 입력 : ");
    scanf("%lf", &s1.pf.height);

    printf("학생 1 id 입력 : ");
    scanf("%d", &s1.id);

    printf("학생 1 grade 입력 : ");
    scanf("%d", &s1.grade);

    printf("\n학생 1 이름 : %s\n", s1.pf.name);
    printf("학생 1 나이 : %d\n", s1.pf.age);
    printf("학생 1 키 : %.1lf\n", s1.pf.height);
    printf("학생 1 id : %d\n", s1.id);
    printf("학생 1 grade : %d\n", s1.grade);   
}

void ex3_structure(void){
    STU student[ex1_3_NUM];

    for(int i = 0; i < ex1_3_NUM; i++){
        int student_num = i+1;

        printf("학생 %d 이름 입력 : ", student_num);
        scanf("%s", student[i].name);
        
        printf("학생 %d ID 입력 : ", student_num);
        scanf("%d", &student[i].id);

        printf("학생 %d 전공 입력 : ", student_num);
        scanf("%s", student[i].major);

        printf("학생 %d 나이 입력 : ", student_num);
        scanf("%s", student[i].address);

        printf("\n");
    }

    printf("[ 학생 정보 출력 ]\n\n");

    for(int i = 0; i < ex1_3_NUM; i++){
        int student_num = i+1;

        printf("학생 %d 이름 : %s\n", student_num, student[i].name);
        printf("학생 %d ID : %d\n", student_num, student[i].id);
        printf("학생 %d 전공 : %s\n", student_num, student[i].major);
        printf("학생 %d 나이 : %s\n", student_num, student[i].address);

        printf("\n");
    }
}

void input_Data(PROF *sp, int size){
    printf("[ 이름, 학점, 영어 점수를 입력하세요. ]\n\n");
    
    for(int i = 0; i < elite_NUM; i++){
        printf("%d-th 학생 : ", i+1);
        scanf("%s %lf %d", ((sp + i)->name), &((sp + i)->grade), &((sp + i)->english));
    }
}

void elite(PROF *sp, int size){
    printf("[ Followings are elite students! ]\n\n");
    
    for(int i = 0; i < elite_NUM; i++){
        if((sp + i)->grade >= 4.0 && (sp + i)->english >= 900){
            printf("%d-th 학생\n", i+1);
            printf("이름 : %s\n", (sp + i)->name);
            printf("등급 : %.1lf\n", (sp + i)->grade);
            printf("영어 : %d\n\n", (sp + i)->english);
        }
    }
}

void ex4_structure(void){
    PROF profile[elite_NUM];

    input_Data(profile, elite_NUM);
    elite(profile, elite_NUM);
}