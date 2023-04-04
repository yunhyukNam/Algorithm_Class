#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 자료형 선언

//********************** STRUCTURE 5, 6 *******************************
typedef struct _STUDENT_
{
	char name[32];
	int id;
	double height;
} STUDENT;

// dir
#define INCREASING 1
#define DECREASING 2

// type
#define NAME 1
#define ID 2
#define HEIGHT 3
//********************** STRUCTURE 5, 6 ******************************

// 사용자 정의 함수 선언 및 정의

//********************** STRUCTURE 5, 6 **********************************
void insertionSort(STUDENT data[], int size, int dir, int type){
	int cnt_i, cnt_j;

	STUDENT r_data;

	if(dir == INCREASING){
		for(cnt_i = 1; cnt_i < size; cnt_i++){
			r_data = data[cnt_i];

			for(cnt_j = cnt_i - 1; cnt_j >= 0; cnt_j--){
				if(type == NAME){
					if(strcmp(data[cnt_j].name, r_data.name) <= 0){
						break;
					}
				}
				else if(type == ID){
					if(data[cnt_j].id <= r_data.id){
						break;
					}
				}
				else if(type == HEIGHT){
					if(data[cnt_j].height <= r_data.height){
						break;
					}
				}
				data[cnt_j + 1] = data[cnt_j];
			}
			data[cnt_j + 1] = r_data;
		}
	}
	else if(dir == DECREASING){
		for(cnt_i = 1; cnt_i < size; cnt_i++){
			r_data = data[cnt_i];

			for(cnt_j = cnt_i - 1; cnt_j >= 0; cnt_j--){
				if(type == NAME){
					if(strcmp(data[cnt_j].name, r_data.name) >= 0){
						break;
					}
				}
				else if(type == ID){
					if(data[cnt_j].id >= r_data.id){
						break;
					}
				}
				else if(type == HEIGHT){
					if(data[cnt_j].height >= r_data.height){
						break;
					}
				}
				data[cnt_j + 1] = data[cnt_j];
			}
			data[cnt_j + 1] = r_data;
		}
	}
}

void insertionSort_by_Ptr(STUDENT* data[], int size, int dir, int type){
	int cnt_i, cnt_j;

	STUDENT* r_data;

	if(dir == INCREASING){
		for(cnt_i = 1; cnt_i < size; cnt_i++){
			r_data = data[cnt_i];

			for(cnt_j = cnt_i - 1; cnt_j >= 0; cnt_j--){
				if(type == NAME){
					if(strcmp(data[cnt_j]->name, r_data->name) <= 0){
						break;
					}
				}
				else if(type == ID){
					if(data[cnt_j]->id <= r_data->id){
						break;
					}
				}
				else if(type == HEIGHT){
					if(data[cnt_j]->height <= r_data->height){
						break;
					}
				}
				data[cnt_j + 1] = data[cnt_j];
			}
			data[cnt_j + 1] = r_data;
		}
	}
	else if(dir == DECREASING){
		for(cnt_i = 1; cnt_i < size; cnt_i++){
			r_data = data[cnt_i];

			for(cnt_j = cnt_i - 1; cnt_j >= 0; cnt_j--){
				if(type == NAME){
					if(strcmp(data[cnt_j]->name, r_data->name) >= 0){
						break;
					}
				}
				else if(type == ID){
					if(data[cnt_j]->id >= r_data->id){
						break;
					}
				}
				else if(type == HEIGHT){
					if(data[cnt_j]->height >= r_data->height){
						break;
					}
				}
				data[cnt_j + 1] = data[cnt_j];
			}
			data[cnt_j + 1] = r_data;
		}
	}
}

void print_info(STUDENT st[], int size){
	int cnt_i;

	for(cnt_i = 0; cnt_i < size; cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, st[cnt_i].name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, st[cnt_i].id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, st[cnt_i].height);
		printf("\n");
	}
	printf("\n");
}

void print_info_by_Ptr(STUDENT* st[], int size){
	int cnt_i;

	for(cnt_i = 0; cnt_i < size; cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, st[cnt_i]->name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, st[cnt_i]->id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, st[cnt_i]->height);
		printf("\n");
	}
	printf("\n");
}
//********************** STRUCTURE 5, 6 **********************************

// 구조체 파트 실습 5
void test1()
{
	STUDENT stu[5] = {0x00, };
	int cnt_i;

	printf("\n");
	printf("\t[ Enter the STUDENT info ]\n");
	
	for(cnt_i = 0; cnt_i < sizeof(stu) / sizeof(STUDENT); cnt_i++){
		printf("\nEnter No.%d Student's Name : ", cnt_i + 1);
		scanf("%s", &stu[cnt_i].name);

		printf("Enter No.%d Student's Id : ", cnt_i + 1);
		scanf("%d", &stu[cnt_i].id);


		printf("Enter No.%d Student's Height : ", cnt_i + 1);
		scanf("%lf", &stu[cnt_i].height);
	}

	printf("\n\t[ Print Student's info ]\n");
	printf("\n");
	print_info(stu, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's Name ]\n");
	printf("\n");
	insertionSort(stu, sizeof(stu) / sizeof(STUDENT), INCREASING, NAME);
	print_info(stu, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's ID ]\n");
	printf("\n");
	insertionSort(stu, sizeof(stu) / sizeof(STUDENT), INCREASING, ID);
	print_info(stu, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's Height ]\n");
	printf("\n");
	insertionSort(stu, sizeof(stu) / sizeof(STUDENT), INCREASING, HEIGHT);
	print_info(stu, sizeof(stu) / sizeof(STUDENT));
	printf("\n");
}
	
// 구조체 파트 실습 6
void test2()
{
	STUDENT stu[5] = {0x00, };
	STUDENT* stu_Ptr[5] = {0x00, };

	int cnt_i;

	for(cnt_i = 0; cnt_i < sizeof(stu) / sizeof(STUDENT); cnt_i++){
		stu_Ptr[cnt_i] = &stu[cnt_i];
	}

	printf("\n");
	printf("\t[ Enter the STUDENT info ]\n");
	
	for(cnt_i = 0; cnt_i < sizeof(stu) / sizeof(STUDENT); cnt_i++){
		printf("\nEnter No.%d Student's Name : ", cnt_i + 1);
		scanf("%s", &stu_Ptr[cnt_i]->name);

		printf("Enter No.%d Student's Id : ", cnt_i + 1);
		scanf("%d", &stu_Ptr[cnt_i]->id);


		printf("Enter No.%d Student's Height : ", cnt_i + 1);
		scanf("%lf", &stu_Ptr[cnt_i]->height);
	}

	printf("\n\t[ Print Student's info ]\n");
	printf("\n");
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's Name ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT), INCREASING, NAME);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's ID ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT), INCREASING, ID);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT));
	printf("\n");

	printf("\t[ Sort by Student's Height ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT), INCREASING, HEIGHT);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENT));
	printf("\n");
}	

// 동적메모리할당 실습 4
void test3()
{
	
}	

// 동적메모리할당 실습 5
void test4()
{
	
}	

// 파일입출력 실습 7
void test5()
{
	
}	

int main()
{
	// test1();
	test2();
	// test3();
	// test4();
	// test5();

	return 0;
}

// EOF