// stack.h
#pragma once

#include "expressiontree.h"

#define STACK_SIZE 100

typedef TREENODE* element;

typedef struct  stackNode {// 스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;

void init();
void freeStack();
void push(element item);

element pop();
element peek();