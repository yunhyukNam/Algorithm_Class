#define _CRT_NOT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define Q_size 10

typedef int element;

typedef struct{
    element queue[Q_size];

    int front, rear;
} QueueType;

QueueType* createQueue();
int isFull(QueueType* Q);
int isEmpty(QueueType* Q);
void enQueue(QueueType* Q, element item);
element deQueue(QueueType* Q);
element peek(QueueType* Q);
void printQ(QueueType* Q);

int main(void){
    int cnt_i;

    QueueType* Q1 = createQueue();
    QueueType* Q2 = createQueue();

    element data;

    printf("[ Enter Queue ]\n");

    for(cnt_i = 0; cnt_i <= 10; cnt_i ++){
        printf("%d insert\n", cnt_i);
        
        enQueue(Q1, cnt_i);
        printQ(Q1);
    }

    data = peek(Q1);
    printf("\nFirst item in Queue: %d\n", data);

    printf("[ Delete Queue ]\n");

    for(cnt_i = 0; cnt_i <= 10; cnt_i++){
        data = deQueue(Q1);

        printf("%d Delete\n", data);
        printQ(Q1);
    }

    printf("\n[ °ÅÁþ Æ÷È­ ]\n");

    for(cnt_i = 0; cnt_i <= 10; cnt_i++){
        printf("enQueue: ");
        enQueue(Q2, cnt_i);
        printQ(Q2);

        printf("deQueue: ");
        deQueue(Q2);
        printQ(Q2);
    }
}

QueueType* createQueue(){
    QueueType* Q;
    Q = (QueueType*)calloc(1, sizeof(QueueType));
    Q->front = -1;
    Q->rear = -1;

    return Q;
}

int isFull(QueueType* Q){
    if(Q->rear == Q_size -1){
        printf("Queue is full!!\n");

        return TRUE;
    }
    else{
        return FALSE;
    }
}

int isEmpty(QueueType* Q){
    if(Q->front == Q->rear){
        printf("Queue is empty!!\n");

        return TRUE;
    }
    else{
        return FALSE;
    }
}

void enQueue(QueueType* Q, element item){
    if(isFull(Q)){
        return;
    }
    else{
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

element deQueue(QueueType* Q){
    if(isEmpty(Q)){
        return;
    }
    else{
        Q->front++;

        return Q->queue[Q->front];
    }
}

element peek(QueueType* Q){
    if(isEmpty(Q)){
        return;
    }
    else{
        return Q->queue[Q->front + 1];
    }
}

void printQ(QueueType* Q){
    int cnt_i;
    
    printf("Queue: (front: %d) rear: %d)[", Q->front, Q->rear);

    for(cnt_i = Q->front + 1; cnt_i <= Q->rear; cnt_i++){
        printf("%d ", Q->queue[cnt_i]);
    }
    printf("]\n");
}