#define NO_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void){
    linkedList_h* CL;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL->head = NULL;

    return CL;
}

void printList(linkedList_h* CL){
    listNode* p;
    
    printf("CL = (");
    p = CL->head;

    do{
        printf("%d", p->data);
        p = p->link;

        if(p != CL->head){
            printf(", ");
        }
    }
    while (p != CL->head);

    printf(") \n");    
}

void insertFirstNode(linkedList_h *CL, int x){
    listNode* newNode, *cur;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;

    if(CL->head == NULL){
        CL->head = newNode;
        newNode->link = newNode;
    }
    else{
        cur = CL->head;

        while(cur->link != CL->head){
            cur = cur->link;
        }
        newNode->link = cur->link;
        cur->link = newNode;
        CL->head = newNode;
    }
}

void insertMiddleNode(linkedList_h* CL, listNode *pre, int x){
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;

    if(CL->head == NULL){
        CL->head = newNode;
        newNode->link = newNode;
    }
    else if(pre == NULL){
        newNode->link = CL->head;
        CL->head = newNode;
    }
    else{
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deleteNode(linkedList_h* CL, listNode* old){
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* find = NULL;

    if(CL->head == NULL || old == NULL){
        return;
    }

    pre = cur = CL->head;

    if(pre == old){
        while(cur->link != CL->head){
            cur = cur->link;
        }
        
        CL->head = pre->link;
        cur->link = CL->head;

        free(pre);

        return;
    }
    cur = pre->link;

    while(cur != CL->head){
        if(cur == old){
            find = cur;
            break;
        }
        pre = cur;
        cur = cur->link;
    }

    if(find != NULL){
        pre->link = find->link;

        free(find);
    }
}

listNode* searchNode(linkedList_h* CL, int x){
    int cnt_i = 0;

    listNode *temp;
    temp = CL->head;

    if(temp == NULL){
        return NULL;
    }

    do{
        printf("Search try : %d\n", cnt_i++);

        if(temp->data == x){
            return temp;
        }
        else{
            temp = temp->link;
        }
    }
    while(temp != CL->head);

    return NULL;
}

void orderedInsert(linkedList_h* CL, int x){
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* newNode = NULL;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;

    pre = cur = CL->head;

    if(cur == NULL){
        CL->head = newNode;
        newNode->link = newNode;

        return;
    }
    else if(cur != NULL){
        if(cur->data > x){
            while(cur->link != CL->head){
                cur = cur->link;
            }
            newNode->link = cur->link;
            cur->link = newNode;
            CL->head = newNode;

            return;
        }
    }
    cur = cur->link;

    while(cur != CL->head){
        if(cur->data > x){
            break;
        }
        pre = cur;
        cur = cur->link;
    }
    newNode->link = pre->link;
    pre->link = newNode;
}

void freeLinkedList_h(linkedList_h* CL){
    listNode* pre = NULL;
    listNode* cur = NULL;

    if(CL != NULL){
        cur = CL->head;

        if(cur != NULL){
            cur = cur->link;

            while(cur != CL->head){
                pre = cur;
                cur = cur->link;

                free(pre);
                pre = NULL;
            }
            free(cur);
            cur = NULL;
        }
        else{
            fprintf(stderr, "error: NULL List\n");

            return;
        }
    }
}

void exec2_circularlist(){
    int cnt_i, data;

    linkedList_h* CL;
    listNode *p;

    srand(time(NULL));

    CL = createLinkedList_h();
    printf("(1) 원형 연결 리스트 생성\n\n");

    printf("(2) orderedInsert()를 이용하여 원형 연결 리스트에 데이터 노드 삽입\n\n");

    for(cnt_i = 0; cnt_i < 10; cnt_i++){
        orderedInsert(CL, rand() % 10);
        printList(CL);
    }

    printf("\n(3) insertFirstNode를 이용하여 원형 연결 리스트에 데이터 노드 삽입\n\n");

    for(cnt_i = 0; cnt_i < 11; cnt_i++){
        insertFirstNode(CL, cnt_i);
    }

    printList(CL);

    printf("\n(4) 5 탐색\n");

    p = searchNode(CL, 5);

    printf("\n(5) 4 재탐색\n");

    p = searchNode(CL, 4);

    printf("\n(6) 4 이후에 100 넣기\n");

    insertMiddleNode(CL, p, 100);
    
    printList(CL);

    printf("\n(7) 10, 100, 9 순서대로 삭제\n");

    p = searchNode(CL, 10);
    deleteNode(CL, p);
    printList(CL);

    printf("\n");

    p = searchNode(CL, 100);
    deleteNode(CL, p);
    printList(CL);

    printf("\n");

    p = searchNode(CL, 9);
    deleteNode(CL, p);
    printList(CL);

    printf("\n");

    freeLinkedList_h(CL);

    if(CL != NULL){
        free(CL);
    }

    printf("Done\n");
}

void main(){
    exec2_circularlist();
}