#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

// 자료형 선언

//********************** STRUCTURE 5, 6 *******************************
typedef struct _STUDENTINFO_
{
	char name[32];
	int id;
	double height;
} STUDENTINFO;

// dir
#define INCREASING 1
#define DECREASING 2

// type
#define NAME 1
#define ID 2
#define HEIGHT 3
//********************** STRUCTURE 5, 6 ******************************


//********************** MALLOC 4, 5 *******************************
typedef struct _STUDENT_
{
	char name[32];
	char major[32];
	int age;
} STUDENT;

//********************** MALLOC 4, 5 *******************************

//********************** FILEIO 7 *******************************
LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER Endtime;
__int64 elapsed;
double during_time;
//********************** FILEIO 7 *******************************


//------------------------------------------------------------------------
// 사용자 정의 함수 선언 및 정의
//------------------------------------------------------------------------

//********************** STRUCTURE 5, 6 **********************************
void insertionSort(STUDENTINFO data[], int size, int dir, int type){
	int cnt_i, cnt_j;

	STUDENTINFO r_data;

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

void insertionSort_by_Ptr(STUDENTINFO* data[], int size, int dir, int type){
	int cnt_i, cnt_j;

	STUDENTINFO* r_data;

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

void print_info(STUDENTINFO st[], int size){
	int cnt_i;

	for(cnt_i = 0; cnt_i < size; cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, st[cnt_i].name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, st[cnt_i].id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, st[cnt_i].height);
		printf("\n");
	}
	printf("\n");
}

void print_info_by_Ptr(STUDENTINFO* st[], int size){
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

//********************** MALLOC 4, 5 *******************************
void inputStudent(STUDENT stu[], int size){
	char buf;
	int cnt_i;
	
	printf("\t[ Input Student ]\n");

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("\n* %d student\n", cnt_i + 1);

		printf("Name : ");
		fgets(stu[cnt_i].name, 32, stdin);

		printf("Major : ");
		fgets(stu[cnt_i].major, 32, stdin);

		printf("Age : ");
		scanf("%d%c", &((stu+cnt_i)->age), &buf);
	}
}

void printStudent(STUDENT stu[], int size){
	int cnt_i;

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("\n* %d student\n", cnt_i + 1);
		printf("Name : %s\n", (stu+cnt_i)->name);
		printf("Major : %s\n", (*(stu+cnt_i)).major);
		printf("Age : %d\n", stu[cnt_i].age);
	}
}

void insertionSort_by_Ptr_2(STUDENTINFO* data[], int size, int dir, int type){
	int cnt_i, cnt_j;

	if(dir == INCREASING){
		for(cnt_i = 0; cnt_i < size - 1; cnt_i++){
			for(cnt_j = cnt_i - 1; cnt_j >= 0; cnt_j--){
				if(type == NAME){
					if(strcmp(data[cnt_j]->name, data[cnt_j+1]->name) <= 0){
						break;
					}
				}
				else if(type == ID){
					if(data[cnt_j]->id <= data[cnt_j+1]->id){
						break;
					}
				}
				else if(type == HEIGHT){
					if(data[cnt_j]->height <= data[cnt_j+1]->height){
						break;
					}
				}
				data[cnt_j + 1] = data[cnt_j];
			}
			data[cnt_j + 1] = &data;
		}
	}
}
//********************** MALLOC 4, 5 *******************************

//********************** FILEIO 7 *******************************
// NONE
//********************** FILEIO 7 *******************************

// 구조체 파트 실습 5
void test1()
{
	STUDENTINFO stu[5] = {0x00, };
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
	STUDENTINFO stu[5] = {{0x00, },};
	STUDENTINFO* stu_Ptr[5] = {0x00, };

	int cnt_i;

	for(cnt_i = 0; cnt_i < sizeof(stu) / sizeof(STUDENTINFO); cnt_i++){
		stu_Ptr[cnt_i] = &stu[cnt_i];
	}

	printf("\n");
	printf("\t[ Enter the STUDENT info ]\n");
	
	for(cnt_i = 0; cnt_i < sizeof(stu) / sizeof(STUDENTINFO); cnt_i++){
		printf("\nEnter No.%d Student's Name : ", cnt_i + 1);
		scanf("%s", &(stu_Ptr[cnt_i]->name));

		printf("Enter No.%d Student's Id : ", cnt_i + 1);
		scanf("%d", &(stu_Ptr[cnt_i]->id));


		printf("Enter No.%d Student's Height : ", cnt_i + 1);
		scanf("%lf", &(stu_Ptr[cnt_i]->height));
	}

	printf("\n\t[ Print Student's info ]\n");
	printf("\n");
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO));
	printf("\n");

	printf("\t[ Sort by Student's Name ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO), INCREASING, NAME);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO));
	printf("\n");

	printf("\t[ Sort by Student's ID ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO), INCREASING, ID);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO));
	printf("\n");

	printf("\t[ Sort by Student's Height ]\n");
	printf("\n");
	insertionSort_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO), INCREASING, HEIGHT);
	print_info_by_Ptr(stu_Ptr, sizeof(stu) / sizeof(STUDENTINFO));
	printf("\n");
}	


// 동적메모리할당 실습 4
void test3()
{
	int cnt_i = 0x00;
	int limit = 0x00;
	char buf = 0x00;

	STUDENT* stuList = NULL;

	printf("\t[ Input the number of student ]\n");
	scanf("%d%c", &limit, &buf);

	stuList = (STUDENT*)calloc(limit, sizeof(STUDENT));
	assert(stuList != NULL);

	inputStudent(stuList, limit);
	printStudent(stuList, limit);

	if(stuList != NULL){
		free(stuList);
	}
}	

// 동적메모리할당 실습 5
void test4()
{
	STUDENTINFO *stu = NULL;
	STUDENTINFO **stuPtr = NULL;

	int cnt_i, size;

	printf("Enter the Number of Student : ");
	scanf("%d", &size);

	stuPtr = (STUDENTINFO **)calloc(size, sizeof(STUDENTINFO *));
	stu = (STUDENTINFO *)calloc(size, sizeof(STUDENTINFO));

	for(cnt_i = 0; cnt_i < size; cnt_i++){
		stuPtr[cnt_i] = &stu[cnt_i];
	}

	printf("\n\t[ Enter the Student Info ]");
	
	for(cnt_i = 0; cnt_i < size; cnt_i++){
		printf("\n");
		printf("Enter the No.%d Student's Name : ", cnt_i + 1);
		scanf("%s", stuPtr[cnt_i]->name);
		printf("Enter the No.%d Student's Id : ", cnt_i + 1);
		scanf("%d", &(stuPtr[cnt_i]->id));
		printf("Enter the No.%d Student's Height : ", cnt_i + 1);
		scanf("%lf", &(stuPtr[cnt_i]->height));
	}

	printf("\n\t[ Print the Student Info ]\n\n");

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, stuPtr[cnt_i]->name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, stuPtr[cnt_i]->id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, stuPtr[cnt_i]->height);
		printf("\n");
	}

	printf("\n\t[ Sort by Name ]\n");
	insertionSort_by_Ptr_2(stuPtr, size, INCREASING, NAME);

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, stuPtr[cnt_i]->name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, stuPtr[cnt_i]->id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, stuPtr[cnt_i]->height);
		printf("\n");
	}

	printf("\n\t[ Sort by ID ]\n");
	insertionSort_by_Ptr_2(stuPtr, size, INCREASING, ID);

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, stuPtr[cnt_i]->name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, stuPtr[cnt_i]->id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, stuPtr[cnt_i]->height);
		printf("\n");
	}

	printf("\n\t[ Sort by Height ]\n");
	insertionSort_by_Ptr_2(stuPtr, size, INCREASING, HEIGHT);

	for(cnt_i = 0;cnt_i < size;cnt_i++){
		printf("No.%d Student's Name : %s\n", cnt_i + 1, stuPtr[cnt_i]->name);
		printf("No.%d Student's Id : %d\n", cnt_i + 1, stuPtr[cnt_i]->id);
		printf("No.%d Student's Height : %.1lf\n", cnt_i + 1, stuPtr[cnt_i]->height);
		printf("\n");
	}

	if(stuPtr != NULL && stu != NULL){
		free(stuPtr);
		free(stu);
	}
}


// 파일입출력 실습 7
void test5()
{
	int cnt_i;
	int* dataList = NULL;

	FILE *bfp = NULL;
	FILE *tfp = NULL;

	QueryPerformanceFrequency(&Frequency);

	dataList = (int*)calloc(10000, sizeof(int));

	for(cnt_i = 0;cnt_i < 10000;cnt_i++){
		dataList[cnt_i] = cnt_i;
	}

	bfp = fopen("FileIO_binary.dat", "wb");
	assert(bfp != NULL);

	tfp = fopen("FileIO_text.txt", "wt");
	assert(tfp != NULL);

	QueryPerformanceCounter(&BeginTime);
	fwrite(dataList, sizeof(int), 10000, bfp);
	QueryPerformanceCounter(&Endtime);

	elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	during_time = (double)elapsed / (double)Frequency.QuadPart;

	printf("elapsed time with binary file : %lf\n", during_time);

	QueryPerformanceCounter(&BeginTime);
	for(cnt_i = 0;cnt_i < 10000;cnt_i++){
		fprintf(tfp, "%d", dataList[cnt_i]);
	}

	QueryPerformanceCounter(&Endtime);

	elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	during_time = (double)elapsed / (double)Frequency.QuadPart;
	
	printf("elapsed time with text file : %lf\n", during_time);

	if(bfp != NULL && tfp != NULL){
		free(bfp);
		free(tfp);
	}
}

int main()
{
	// test1();
	// test2();
	// test3();
	test4();
	// test5();

	return 0;
}

// EOF