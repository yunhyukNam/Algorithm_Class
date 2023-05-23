#define NO_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_MAX_SIZE	500001

typedef struct QUEUE {
    int data[DATA_MAX_SIZE];
    
    int front, rear;
} QUEUE;

QUEUE q;

void init (QUEUE *q) {
    q->front = q->rear = -1;
}

int empty (QUEUE *q) {
    return (q->front == q->rear);
}

int full (QUEUE *q) {
    return ((q->rear + 1) % DATA_MAX_SIZE == q->front);
}

int size (QUEUE *q) {
    if (empty(q)) {
        return 0;
    }

    return (q->rear - q->front);
}

void push (QUEUE *q, int _data) {
    q->data[++(q->rear)] = _data;
}

int pop (QUEUE *q) {
    if (empty(q)) {
        return -1;
    }

    return q->data[++(q->front)];
}

int front (QUEUE *q) {
    if (empty(q)) {
        return -1;
    }
    
    return q->data[q->front + 1];
}

int back (QUEUE *q) {
    if (empty(q)) {
        return -1;
    }

    return q->data[q->rear];
}

// ----------------------------------------------------

<<<<<<< HEAD
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
=======
void enqueue (QUEUE *q, int _data) {
    if (full(q)) {
        return;
    }
    else {
        q->rear = (q->rear + 1) % DATA_MAX_SIZE;
        q->data[q->rear] = _data;
    }
>>>>>>> 0374ee1e809ed0871a798a06d5bc6a9e6678c810
}

int dequeue (QUEUE *q) {
    if (empty(q)) {
        return -1;
    }
    else {
        q->front = (q->front + 1) % DATA_MAX_SIZE;

        return q->data[q->front];
    }
}

// ----------------------------------------------------

void test1() {
    init(&q);

    int count;
    scanf("%d", &count);

    while(count--) {
        char command[6];
        scanf("%s", command);
        
        if (!strcmp(command, "push")) {
            int data = 0;
            scanf("%d", &data);
            
            push(&q, data);
        }
        else if (!strcmp(command, "front")) {
            printf("%d\n", front(&q));
        }
        else if (!strcmp(command, "back")) {
            printf("%d\n", back(&q));
        }
        else if (!strcmp(command, "pop")) {
            printf("%d\n", pop(&q));
        }
        else if (!strcmp(command, "size")) {
            printf("%d\n", size(&q));
        }
        else if (!strcmp(command, "empty")) {
            printf("%d\n", empty(&q));
        }
        else {
            printf("Check your Enter, please\n");
        }
    }
}

void test2() {
    init(&q);

    int count;
    scanf("%d", &count);

    for (int cnt_i = 0; cnt_i < count; cnt_i++) {
        enqueue(&q, cnt_i + 1);
    }

    int data = 0;

    while(!empty(&q)) {
        data = dequeue(&q);

        if (empty(&q)) {
            break;
        }
        else {
            data = dequeue(&q); 
            enqueue(&q, data);
        }
    }
    printf("%d\n", data);
}

int main()
{
	// test1();
<<<<<<< HEAD
	// test2();
	test3();
=======
	test2();
>>>>>>> 0374ee1e809ed0871a798a06d5bc6a9e6678c810

	return 0;
}

// EOF