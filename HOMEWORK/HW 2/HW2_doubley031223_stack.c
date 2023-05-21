
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STACK_SIZE    10000

int STACK_SIZE = 0;

int stack[MAX_STACK_SIZE];

void push(int _data) {
    stack[STACK_SIZE] = _data;

    STACK_SIZE++;
}

int empty() {
    if (STACK_SIZE == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int pop() {
    if (empty() == 1) {
        return -1;
    }
    else {
        STACK_SIZE -= 1;
    }

    return stack[STACK_SIZE];
}

int size() {
    return STACK_SIZE;
}

int top() {
    if (empty()) {
        return -1;
    }
    else {
        return stack[STACK_SIZE-1];
    }
}

void test1() {
	int str;
    scanf("%d", &str);

    char command[10];

    for (int cnt_i = 0; cnt_i < str; cnt_i++) {
        scanf("%s", &command);

        if (strcmp(command, "push") == 0) {
            int data;

            scanf("%d", &data);
            push(data);
        }
        else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(command, "top") == 0) {
            printf("%d\n", top());
        }
        else {
            printf("Check your Enter, please\n");
        }
    }
}

void test2() {
	int count, data;
	scanf("%d", &count);

	int num = 1;
	int idx = 0;

	bool check = true;
	
	char print[MAX_STACK_SIZE + 1];

	for (int cnt_i = 0; cnt_i < count; cnt_i++) {
		scanf("%d", &data);

		if (top() < data) {
			while (top() < data) {
				push(num++);
				print[idx++] = '+';
			}
		}
		else if (top() > data) {
			while (top() > data) {
				pop();
				print[idx++] = '-';
			}
		}
		else if (top() != data) {
			check = false;
			break;
		}
		else {
			pop();
			print[idx++] = '-';
		}
	}

	for (int cnt_j = 0; cnt_j < idx; cnt_j++) {
		if (check == false) {
			printf("Please Check!\n");
		}
		else {
			printf("%c\n", print[cnt_j]);
		}
	}
	
}

int main()
{
	// test1();
	test2();

	return 0;
}

// EOF

