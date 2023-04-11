#define _CRT_NOT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define STACK_SIZE 100

typedef int element;

typedef struct _ARRAY_STACK_{
    element stackArr[STACK_SIZE];
    int topIndex;
    int stackSize;
} ARRAY_STACK;

void init(ARRAY_STACK* stack, int size){
    stack->stackSize = size;
    stack->topIndex = -1;
}

int isEmpty(ARRAY_STACK* stack){
    if(stack->topIndex == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(ARRAY_STACK* stack){
    if(stack->topIndex == (stack->stackSize)){
        return 1;
    }
    else{
        return 0;
    }
}

int push(ARRAY_STACK* stack, element item){
    if(isFull(stack)){
        return 0;
    }
    else{
        stack->stackArr[++(stack->topIndex)] = item;
        
        return 1;
    }
}

int pop(ARRAY_STACK* stack){
    if(isEmpty(stack)){
        return 0;
    }
    else{
        stack->stackArr[(stack->topIndex)--];
        return 1;
    }
}

element peek(ARRAY_STACK* stack){
    if(isEmpty(stack)){
        printf("\n\n Stack is Empty !\n");

        exit(1);
    }
    else{
        return stack->stackArr[stack->topIndex];
    }
}

void printStack(ARRAY_STACK* stack){
    int cnt_i;

    printf("\n STACK [ ");

    for(cnt_i = stack->topIndex; cnt_i >= 0; cnt_i--){
        printf("%d ", stack->stackArr[cnt_i]);
    }
    printf("] ");
}

void exer1_stack_array(){
    int cnt_i = 0;
    element item;
    ARRAY_STACK stack;

    printf("\n** 순차 스택 연산 **\n");

    init(&stack, 10);
    printStack(&stack);

    for(cnt_i = 0; cnt_i < 10; cnt_i++){
        if(push(&stack, cnt_i) == 0){
            printf("Stack is FULL\n");
        }
        printStack(&stack);
    }

    push(&stack, cnt_i);
    printStack(&stack);

    item = peek(&stack);
    printStack(&stack);

    printf("peek => %d", item);

    for(cnt_i = 0; cnt_i < 10; cnt_i++){
        ifpop(&stack);
        printStack(&stack);

        printf("\tpop => %d", item);
    }

    item = pop(&stack);
    printStack(&stack);
}

int main(){
    exer1_stack_array();

    return 0;
}