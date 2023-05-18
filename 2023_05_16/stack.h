// stack.h
#pragma once

#include "expressiontree.h"

#define STACK_SIZE 100

typedef TREENODE* element;

typedef struct  stackNode {// ������ ��带 ����ü�� ����
    element data;
    struct stackNode *link;
} stackNode;

void init();
void freeStack();
void push(element item);

element pop();
element peek();