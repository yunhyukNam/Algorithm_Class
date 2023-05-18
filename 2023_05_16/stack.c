#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stackNode* top;// ������ top ��带 �����ϱ� ���� ������ top ����
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

// ������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item) {
    stackNode* temp = (stackNode *)calloc(1, sizeof(stackNode));
    temp->data = item;
    temp->link = top;// ���� ��带 top�� ���� ����
    top = temp;// top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
    element item;
    stackNode* temp = top;
    if (top == NULL) {// ������ ���� ����Ʈ�� ���
        printf("\n\n Stack is empty !\n");
        return;
    }
    else {// ������ ���� ����Ʈ�� �ƴ� ���
        item = temp->data;
        top = temp->link;// top ��ġ�� ���� ��� �Ʒ��� �̵�
        free(temp);// ������ ����� �޸� ��ȯ
        return item;// ������ ���� ��ȯ
    }
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
    if (top == NULL) {// ������ ���� ����Ʈ�� ���
        printf("\n\n Stack is empty !\n");
        return;
    }
    else {// ������ ���� ����Ʈ�� �ƴ� ���
        return(top->data);  // ���� top�� ���� ��ȯ
    }
}