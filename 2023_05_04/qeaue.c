#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int element;    // 자료형 element를 int형으로 선언

typedef struct _DQNODE_ {   // 이중 연결 리스트의 데크의 노드 구조를 정의
    element data;
    struct _DQNODE_ *llink;
    struct _DQNODE_ *rlink;    
} DQNODE;

typedef struct _DQNODE_Type_ {  // 데크에서 사용하는 포인터 front와 rear를 정의
    DQNODE *front, *rear;
} DQUEUE_Type;

DQUEUE_Type *createDQue() { // 공백 데크 생성
    DQUEUE_Type *DQ = NULL;
    
    DQ = (DQUEUE_Type*)calloc(1, sizeof(DQUEUE_Type));
    DQ->front = NULL;
    DQ->rear = NULL;

    return DQ;
}

int isEmpty(DQUEUE_Type *DQ) {
    if (DQ->front == NULL){
        printf("\n Linked Queue is Empty! \n");

        return true;
    }
    else {
        return false;
    }
}

void insertFront(DQUEUE_Type *DQ, element item) {
    DQNODE* newNode = NULL;

    newNode = (DQNODE*)calloc(1, sizeof(DQNODE));
    newNode->data = item;

    if (DQ->front == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;

        newNode->llink = NULL;
        newNode->rlink = NULL;
    }
    else {
        DQ->front->llink = newNode;
        
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        
        DQ->front = newNode;
    }
}

void insertRear(DQUEUE_Type* DQ, element item) {
    DQNODE* newNode = NULL;

    newNode = (DQNODE*)calloc(1, sizeof(DQNODE));
    newNode->data = item;

    if (DQ->rear == NULL) {
        DQ->front = newNode;
        DQ->rear = newNode;

        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else {
        DQ->rear->llink = newNode;
        
        newNode->rlink = NULL;
        newNode->llink = DQ->rear;
        
        DQ->rear = newNode;
    }
}

element deleteFront(DQUEUE_Type *DQ) {
    DQNODE* old = NULL;
    element item;

    if (isEmpty(DQ)) {
        return false;
    }
    else {
        old = DQ->front;
        item = old->data;

        if (DQ->front->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->front = DQ->front->llink;
            DQ->front->llink = NULL;
        }
        free(old);

        return item;
    }
}

element deleteRear(DQUEUE_Type *DQ) {
    DQNODE* old = NULL;
    element item;

    if (isEmpty(DQ)) {
        return 0;
    }
    else {
        old = DQ->rear;
        item = old->data;

        if (DQ->rear->llink == NULL) {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);

        return item;
    }
}

element peekFront(DQUEUE_Type *DQ) {
    element item;

    if (isEmpty(DQ)) {
        return false;
    }
    else {
        item = DQ->front->data;

        return item;
    }
}

element peekRear(DQUEUE_Type *DQ) {
    element item;

    if (isEmpty(DQ)) {
        return false;
    }
    else {
        item = DQ->rear->data;

        return item;
    }
}

void printDQ(DQUEUE_Type *DQ) {
    DQNODE *temp = DQ->front;

    printf("DeQue (front : %p | rear : %p) : [ ", (DQ->front), (DQ->rear));

    while(temp) {
        printf("%d", temp->data);

        temp = temp->rlink;
    }
    printf(" ] \n");
}

void main() {
    DQUEUE_Type* DQ1 = createDQue();
    element data;

    int cnt_i;

    printDQ(DQ1);

    insertFront(DQ1, 1);
    printDQ(DQ1);

    insertFront(DQ1, 2);
    printDQ(DQ1);

    insertRear(DQ1, 3);
    printDQ(DQ1);

    deleteFront(DQ1);
    printDQ(DQ1);

    deleteRear(DQ1);
    printDQ(DQ1);

    insertRear(DQ1, 4);
    printDQ(DQ1);

    insertFront(DQ1, 5);
    printDQ(DQ1);

    insertFront(DQ1, 6);
    printDQ(DQ1);

    printf("     [ 큐 삽입 ]\n");

    for (cnt_i = 0; cnt_i < 5; cnt_i++) {
        printf("%d 삽입\n", cnt_i);
        insertFront(DQ1, cnt_i);
        printDQ(DQ1);
    }

    for (cnt_i = 5; cnt_i < 10; cnt_i++) {
        printf("%d 삽입\n", cnt_i);
        insertRear(DQ1, cnt_i);
        printDQ(DQ1);
    }

    printf("\n     [ 큐 삭제 ]\n");

    for (cnt_i = 0; cnt_i < 15; cnt_i++) {
        data = deleteRear(DQ1);
        printf("%d 삭제\n", data);
        printDQ(DQ1);
    }
}