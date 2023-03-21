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

    printf("�л� 1 �̸� �Է� : ");
    scanf("%s", s1.pf.name);
    
    printf("�л� 1 ���� �Է� : ");
    scanf("%d", &s1.pf.age);

    printf("�л� 1 Ű �Է� : ");
    scanf("%lf", &s1.pf.height);

    printf("�л� 1 id �Է� : ");
    scanf("%d", &s1.id);

    printf("�л� 1 grade �Է� : ");
    scanf("%d", &s1.grade);

    printf("\n�л� 1 �̸� : %s\n", s1.pf.name);
    printf("�л� 1 ���� : %d\n", s1.pf.age);
    printf("�л� 1 Ű : %.1lf\n", s1.pf.height);
    printf("�л� 1 id : %d\n", s1.id);
    printf("�л� 1 grade : %d\n", s1.grade);   
}

void ex3_structure(void){
    STU student[ex1_3_NUM];

    for(int i = 0; i < ex1_3_NUM; i++){
        int student_num = i+1;

        printf("�л� %d �̸� �Է� : ", student_num);
        scanf("%s", student[i].name);
        
        printf("�л� %d ID �Է� : ", student_num);
        scanf("%d", &student[i].id);

        printf("�л� %d ���� �Է� : ", student_num);
        scanf("%s", student[i].major);

        printf("�л� %d ���� �Է� : ", student_num);
        scanf("%s", student[i].address);

        printf("\n");
    }

    printf("[ �л� ���� ��� ]\n\n");

    for(int i = 0; i < ex1_3_NUM; i++){
        int student_num = i+1;

        printf("�л� %d �̸� : %s\n", student_num, student[i].name);
        printf("�л� %d ID : %d\n", student_num, student[i].id);
        printf("�л� %d ���� : %s\n", student_num, student[i].major);
        printf("�л� %d ���� : %s\n", student_num, student[i].address);

        printf("\n");
    }
}

void input_Data(PROF *sp, int size){
    printf("[ �̸�, ����, ���� ������ �Է��ϼ���. ]\n\n");
    
    for(int i = 0; i < elite_NUM; i++){
        printf("%d-th �л� : ", i+1);
        scanf("%s %lf %d", ((sp + i)->name), &((sp + i)->grade), &((sp + i)->english));
    }
}

void elite(PROF *sp, int size){
    printf("[ Followings are elite students! ]\n\n");
    
    for(int i = 0; i < elite_NUM; i++){
        if((sp + i)->grade >= 4.0 && (sp + i)->english >= 900){
            printf("%d-th �л�\n", i+1);
            printf("�̸� : %s\n", (sp + i)->name);
            printf("��� : %.1lf\n", (sp + i)->grade);
            printf("���� : %d\n\n", (sp + i)->english);
        }
    }
}

void ex4_structure(void){
    PROF profile[elite_NUM];

    input_Data(profile, elite_NUM);
    elite(profile, elite_NUM);
}