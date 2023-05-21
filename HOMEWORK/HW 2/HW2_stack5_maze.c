#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack 사용과 관련된 함수 및 코드 정의
#define MAX_STACK_SIZE	100
#define MAZE_SIZE	6

typedef struct StackObjectRec {
	short r;
	short c;
} StackObject;

StackObject stack[MAX_STACK_SIZE];
StackObject here = {1, 0}, entry = {1, 0};

int top = -1;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1'},
	{ 'e', '0', '1', '0', '0', '1'},
	{ '1', '0', '0', '0', '1', '1'},
	{ '1', '0', '1', '0', '1', '1'},
	{ '1', '0', '1', '0', '0', 'x'},
	{ '1', '1', '1', '1', '1', '1'},
};

void initialize() {
	top = -1;
}

int isEmpty() {
	return (top == -1);
}

int isFull() {
	return (top == (MAX_STACK_SIZE - 1));
}

void push(StackObject _item) {
	if (isFull()) {
		printf("Stack is Full!\n");
	}
	else {
		stack[++top] = _item;
	}
}

StackObject pop() {
	if (isEmpty()) {
		printf("Stack is Full!\n");
	}
	else {
		return stack[top--];
	}
}

void printStack() {
	int cnt_i;

	for (cnt_i = 5; cnt_i > top; cnt_i--) {
		printf("|        |\n");
	}
	for (cnt_i = top; cnt_i >= 0; cnt_i--) {
		printf("| (%01d, %01d) |\n", stack[cnt_i].r, stack[cnt_i].c);
		printf("----------\n");
	}
}

void pushLoc(int r, int c) {
	if (r < 0 || c < 0) {
		return;
	}

	if (maze[r][c] != '1' && maze[r][c] != '.') {
		StackObject tmp;
		tmp.r = r;
		tmp.c = c;

		push(tmp);
	}
}

void printMaze(char _maze[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;

	printf("\n\n");

	for (r = 0; r < MAZE_SIZE; r++) {
		for (c = 0; c < MAZE_SIZE; c++) {
			if (c == here.c && r == here.r) {
				printf("m ");
			}
			else {
				if (_maze[r][c] == 0) {
					printf("0 ");
				}
				else {
					printf("%c ", _maze[r][c]);
				}
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void findRoot() {
	int r, c;
	
	here = entry;

	printMaze(maze);
	printStack();

	while (maze[here.r][here.c] != 'x') {
		printMaze(maze);

		r = here.r;
		c = here.c;

		maze[r][c] = '.';

		pushLoc(r-1, c);
		pushLoc(r+1, c);
		pushLoc(r, c-1);
		pushLoc(r, c+1);

		printStack();

		if (isEmpty()) {
			printf("FAILURE\n");

			return;
		}
		else {
			here = pop();
		}
		printMaze(maze);
		printStack();
	}
	printf("SUCCESS\n");
}