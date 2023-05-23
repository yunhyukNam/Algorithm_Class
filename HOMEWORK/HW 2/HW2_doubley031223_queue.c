
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE	100

#define MAZE_SIZE	6

typedef struct _POS_ {
	short r;
	short c;
} POS;

typedef POS Element;

Element data[MAX_QUEUE_SIZE];

int front;
int rear;

void error(char* _str) {
	fprintf(stderr, "%s\n", _str);
	exit(1);
}

void init_queue() {
	front = rear = 0;
}
int is_Empty() {
	return front == rear;
}
int is_Full() {
	return front == (rear+1) % MAX_QUEUE_SIZE;
}
int size() {
	return (rear-front+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

Element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void enqueue(Element _val) {
	if (is_Full()) {
		error("	?Åê ?è¨?ôî ?óê?ü¨");
	}
	rear = (rear+1) % MAX_QUEUE_SIZE;
	data[rear] = _val;
}

Element dequeue() {
	if (is_Empty()) {
		error("	?Åê Í≥µÎ∞± ?óê?ü¨");
	}
	front = (front+1) % MAX_QUEUE_SIZE;

	return data[front];
}

Element peek() {
	if (is_Empty()) {
		error("	?Åê Í≥µÎ∞± ?óê?ü¨");
	}
	
	return data[(front+1) % MAX_QUEUE_SIZE];
}

void printQ() {
	int cnt_i;

	if (!is_Empty()) {
		printf("\n[");

		for (cnt_i = front+1; cnt_i <= rear; cnt_i++) {
			printf("(%d, %d) ", data[cnt_i].r, data[cnt_i].c);
		}
		printf("]\n\n");
	}
}

void pushLoc(int _r, int _c) {
	if (_r < 0 || _c < 0) {
		return;
	}
	
	if (maze[_r][_c] != '1' && maze[_r][_c] != '.') {
		Element tmp;
		tmp.r = _r;
		tmp.c = _c;

		enqueue(tmp);
	}
}

void printMaze(char _m[MAZE_SIZE][MAZE_SIZE]) {
	int r, c;

	printf("\n\n");

	for (r = 0; r < MAZE_SIZE; r++) {
		for (c = 0; c < MAZE_SIZE; c++) {
			if (c == here.c && r == here.r) {
				printf("m");
			}
			else {
				if (_m[r][c] == 0) {
					printf("0	");
				}
				else {
					printf("%c", _m[r][c]);
				}
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

// ----------------------------------------------------

typedef struct queue {
	int queue[100000];
	int front = 0;
	int rear = -1;
} s_queue;

int q_empty() {
	if (rear - front + 1 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void q_push(int _data) {
	s_queue[++rear] = _data;
}

int q_pop() {
	if (rear - front + 1 == 0) {
		return -1;
	}
	return s_queue[front++];
}

// ----------------------------------------------------



void test1() {
	int r, c;

	here = entry;

	printMaze(maze);
	printQ();

	while (maze[here.r][here.c] != 'x') {
		printMaze(maze);

		r = here.r;
		c = here.c;

		maze[r][c] = '.';

		pushLoc(r-1, c);
		pushLoc(r+1, c);
		pushLoc(r, c-1);
		pushLoc(r, c+1);
		printQ();

		if (is_Empty()) {
			printf("FAILURE\n");

			return;
		}
		else {
			here = dequeue();
		}

		printMaze(maze);
		printQ();
	}
	printf("SUCCESS\n");
}

void test2() {
	int str;
	char command[10];

	scanf("%d", &str);

	for (int cnt_i = 0;cnt_i < str; cnt_i++) {
		scanf("%s", command);

		if (!strcmp(command, "push")) {
			int data;

			scanf("%d", &data);
			q_push(data);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", q_pop());
		}
		else if (!strcmp(command, "size")) {
			if (q_empty() == 1) {
				printf("%d\n", 0);
			}
			else {
				printf("%d\n", (rear - front + 1));
			}
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", q_empty());
		}
		else if (!strcmp(command, "front")) {
			if(rear - front + 1 == 0) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", s_queue[front]);
			}
		}
		else if (!strcmp(command, "back")) {
			if(rear - front + 1 == 0) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", s_queue[rear]);
			}
		}
		else {
			printf("Check your Enter, please\n");
		}
	}
}

void test3() {
	
}

int main()
{
	// test1();
	// test2();
	test3();

	return 0;
}

// EOF