#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackNode* top;// 스택의 top 노드를 지정하기 위해 포인터 top 선언
int precedence(char op) {
    switch (op) {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
    }
    
    return -1;
}

void init() {
    top = NULL;
}

void freeStack() {
    stackNode* pre = NULL;
    stackNode* cur = NULL;
    
    pre = cur = top;

    while (cur != NULL) {
        pre = cur;
        cur = cur->link;
        free(pre);
        pre = NULL;
    }
}

// 스택이 공백 상태인지 확인하는 연산
int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode* temp = (stackNode *)calloc(1, sizeof(stackNode));
    temp->data = item;
    temp->link = top;// 삽입 노드를 top의 위에 연결
    top = temp;// top 위치를 삽입 노드로 이동
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
    element item;
    stackNode* temp = top;
    if (top == NULL) {// 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
        return;
    }
    else {// 스택이 공백 리스트가 아닌 경우
        item = temp->data;
        top = temp->link;// top 위치를 삭제 노드 아래로 이동
        free(temp);// 삭제된 노드의 메모리 반환
        return item;// 삭제된 원소 반환
    }
}

// 스택의 top 원소를 검색하는 연산
element peek() {
    if (top == NULL) {// 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty !\n");
        return;
    }
    else {// 스택이 공백 리스트가 아닌 경우
        return(top->data);  // 현재 top의 원소 반환
    }
}