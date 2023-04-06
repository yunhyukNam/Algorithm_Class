#define _CRT_NOT_NO_WARNINGS_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRLEN 32

typedef struct _LISTNODE_
{
    char data[MAXSTRLEN];
    struct _LISTNODE_* link;
} listNode;

typedef struct _LINKEDLIST_H_
{
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void){
    linkedList_h* L;
    L = (linkedList_h*)calloc(1, sizeof(linkedList_h));
    L -> head = NULL;

    return L;
}

void printList(linkedList_h* L){
    listNode* p;

    printf("L = (");
    p = L -> head;

    while(p != NULL){
        printf("%s", p -> data);
        p = p -> link;

        if(p != NULL){
            printf(", ");
        }
    }
    printf(") \n");
}

void freeLinkedList_h(linkedList_h* L){
    listNode* p;

    if(L != NULL){
        while (L -> head != NULL){
            p = L -> head;
            L -> head = L -> head -> link;

            free(p);
            p = NULL;
        }
        L -> head = NULL;        
    }
    else{
        fprintf(stderr, "ERROR: NULL LIST\n");

        return;
    }
}

void insertFirstNode(linkedList_h* L, char* x){
    listNode* newNode;
    
    newNode = (listNode*)malloc(sizeof(listNode));

    strcpy(newNode -> data, x);

    newNode -> link = L -> head;
    L -> head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode *pre, char* x){
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);

    if(L -> head == NULL){
        newNode -> link = NULL;
        L -> head = newNode;
    }
    else if(pre == NULL){
        newNode -> link = L -> head;
        L -> head = newNode;
    }
    else{
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

void insertLastNode(linkedList_h* L, char* x){
    listNode* newNode;
    listNode* temp;

    newNode = (listNode*)malloc(sizeof(listNode));

    strcpy(newNode -> data, x);

    newNode -> link = NULL;

    if(L -> head == NULL){
        L -> head = newNode;

        return;
    }

    temp = L -> head;

    while(temp -> link != NULL){
        temp = temp -> link;
    }

    temp -> link = newNode;
}

listNode* searchNode(linkedList_h* L, char* x){
    listNode *temp;
    temp = L -> head;

    while(temp != NULL){
        if(strcmp(temp -> data, x) == 0){
            return temp;
        }
        else{
            temp = temp -> link;
        }
    }
    return temp;
}

void deleteNode(linkedList_h* L, listNode* p){
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* find = NULL;

    if(L -> head == NULL || p == NULL){
        return;
    }

    pre = cur = L -> head;

    if(pre == p){
        cur = pre -> link;
        free(pre);
        L -> head = cur;

        return;
    }

    cur = cur -> link;

    while(cur != NULL){
        if(cur == p){
            find = cur;
            break;
        }
        pre = cur;
        pre = cur -> link;
    }

    if(find != NULL){
        pre -> link = find -> link;
        free(find);
    }
}

void orderedInsert(linkedList_h* L, char* x){
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* newNode = NULL;

    newNode = (listNode*)malloc(sizeof(listNode));

    strncpy(newNode -> data, x, MAXSTRLEN);

    newNode -> link = NULL;

    if(cur == NULL){
        L -> head = newNode;

        return;
    }

    else if(cur != NULL){
        if(strncmp(cur -> data, x, MAXSTRLEN) > 0){
            newNode -> link = cur;
            L -> head = newNode;

            return;
        }
    }

    cur = cur -> link;

    while(cur != NULL){
        if(strncmp(cur -> data, x, MAXSTRLEN) > 0){
            break;
        }
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

void test2(){
    linkedList_h* L;
    linkedList_h* L2;
    linkedList_h* L3;
    listNode *p;

    L = createLinkedList_h();
    L2 = createLinkedList_h();
    L3 = createLinkedList_h();

    printf("\n(1) Node's head Insert!\n");
    insertFirstNode(L, "apple");
    insertFirstNode(L, "banana");
    insertFirstNode(L, "cat");

    printList(L);

    printf("\n(2) Node's tail Insert\n");
    insertFirstNode(L2, "apple");
    insertFirstNode(L2, "banana");
    insertFirstNode(L2, "cat");

    printList(L2);

    getchar();

    printf("\n(3) Search Node in List\n");

    p = searchNode(L, "banana");

    if(p == NULL){
        printf("No data in there\n");
    }

    else{
        printf("Find the [%s]!", p -> data);
    }

    printf("\n(4) Insert Node's Middle in List\n");
    insertMiddleNode(L, p, "zero");

    printList(L);

    printf("\n(6) Delete the Node\n");

    p = searchNode(L3, "absolute");
    
    deleteNode(L3, p);

    printList(L3);

    getchar();
    getchar();

    freeLinkedList_h(L);

    if(L != NULL){
        free(L);
    }

    getchar();
}

int main(void){
    test2();
}