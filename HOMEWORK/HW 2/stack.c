#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE    10000

int STACK_SIZE = 0;

int stack[SIZE];

void push(int _data) {
    stack[STACK_SIZE] = _data;

    STACK_SIZE++;
}

int empty() {
    if (STACK_SIZE == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int pop() {
    if (empty() == 1) {
        return -1;
    }
    else {
        STACK_SIZE -= 1;
    }

    return stack[STACK_SIZE];

    stack[STACK_SIZE] = 0;
}

int size() {
    return STACK_SIZE;
}

int top() {
    if (empty()) {
        return -1;
    }
    else {
        return stack[STACK_SIZE-1];
    }
}

int main() {
    int str;
    scanf("%d", &str);

    char command[10];

    for (int cnt_i = 0; cnt_i < str; cnt_i++) {
        scanf("%s", &command);

        if (strcmp(command, "push") == 0) {
            int data;

            scanf("%d", &data);
            push(data);
        }
        else if (strcmp(command, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(command, "size") == 0) {
            printf("%d\n", size());
        }
        else if (strcmp(command, "top") == 0) {
            printf("%d\n", top());
        }
        else {
            printf("Check your Enter, please\n");
        }
    }
    
    return 0;
}