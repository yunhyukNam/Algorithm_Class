#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// #include <crtdbg.h>// 메모리 누수를 확인하기 위해 CRT 디버그 함수 사용

// * postfix 연산 시 여러가지 operand에 대해서도 연산가능

typedef int element;// 스택 원소(element)의 자료형을 int로 정의 
typedef struct  stackNode {// 스택의 노드를 구조체로 정의
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;// 스택의 top 노드를 지정하기 위해 포인터 top 선언
/*
 * 연산자의 우선순위를 반환함
 */

int precedence(char op){
    switch (op) {
        case '(': case ')': 
                        return 0;
        case '+': case '-': 
                        return 1;
        case '*': case '/': case '%': 
                                return 2;
    }
    return -1;
}

void init(){
    top = NULL;
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산

void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");

    while (p) {
        printf("%c ", p->data);
        p = p->link;
    }
    printf("] ");
}

void freeStack(){
    stackNode* pre = NULL;
    stackNode* cur = NULL;

    pre = cur = top;

    while (cur != NULL){
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
    stackNode* temp = (stackNode*)calloc(1, sizeof(stackNode));

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
        return 0;
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

        return 0;
    }
    else {// 스택이 공백 리스트가 아닌 경우
        return(top->data);  // 현재 top의 원소 반환
    }
}

// 수식의 괄호를 검사하는 연산
int testPair(char* exp) {
    char symbol, open_pair;
    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장

    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++) {
        //printStack();
        symbol = exp[i];
        switch (symbol) {
            // (1) 왼쪽 괄호는 스택에 삽입
            case '(':case '[':case '{':
                push(symbol); 
                break;
            // (2) 오른쪽 괄호를 읽으면,
            case ')':case ']':case '}':
                if (top == NULL) return 0;
                else {
                // (2)-1 스택에서 마지막으로 읽은 괄호를 꺼냄
                    open_pair = pop();
                // (2)-2 괄호 쌍이 맞는지 검사
                    if ((open_pair == '(' && symbol != ')') ||
                        (open_pair == '[' && symbol != ']') ||
                        (open_pair == '{' && symbol != '}'))
                // (2)-3 괄호 쌍이 틀리면 수식 오류
                    return 0;
                // (2)-4 괄호 쌍이 맞으면 다음 symbol 검사를 계속함
                    else break;
                }
        }
    }
    if (top == NULL) return 1;// 수식 검사를 마친 후 스택이 공백이면 1을 반환
    else return 0;            // 공백이 아니면 0을 반환(수식 괄호 틀림)
}

void infix_to_postfix(char* infix, char* postfix){
    int cnt_i = 0, cnt_j = 0;
    char c, op;

    while(infix[cnt_i] != '\0'){
        c = infix[cnt_i++];

        if(c >= '0' && c <= '9'){
            postfix[cnt_j++] = c;

            while(infix[cnt_i] <= '9' && infix[cnt_i] >= '0'){
                postfix[cnt_j++] = infix[cnt_i++];
            }
            postfix[cnt_j++] = ' ';
        }
        else if(c == '('){
            push(c);
        }
        else if(c == ')'){
            while(!isEmpty()){
                op = pop();
                
                if(op == '('){
                    break;
                }
                else{
                    postfix[cnt_j++] = op;
                    postfix[cnt_j++] = ' ';
                }
            }
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
            while(!isEmpty()){
                op = peek();

                if(precedence(c) <= precedence(op)){
                    op = pop();

                    postfix[cnt_j++] = op;
                    postfix[cnt_j++] = ' ';
                }
                else{
                    break;
                }
            }
            if(c == '-'){
                op = 0;
            }
            push(c);
        }
    }
    while(!isEmpty()){
        postfix[cnt_j++] = pop();
        postfix[cnt_j++] = ' ';
    }
    postfix[cnt_j] = '\0';
}

// 후위 표기법 수식을 계산하는 연산
element evalPostfix(char* exp) {
// ...
}

void exer4_postfix_eval(){
    int result;
    int cnt_i;
    char infix_expr[13][80] = { "3*5-6/2",
                                "((4+2)/4)-(3+70/(7*5))",
                                "((((5*6)+7)-8)*9)",
                                "((((5*6)+7)-8)*9)+(9+8)*7",
                                "((((5*6)+7)-8)*9)+(((9+8)*7)'%%4)",
                                "(((((((((1*2)*3)*4)*5)*6)*7)*8)*9)*10)",
                                "1*2+3*4+6/2+8%%3+9-8",
                                "70+80*9-10+(60+70+80*2-10)",
                                "(9-(4/2+1))*(5*2-2)",
                                "((80*87)/4)*2-705",
                                "100*((90-80+20*5)-(30*20-10/5))",
                                "(9-(4/2+1+(10*5)+7*6))*(50*20-10%%2)",
                                "123+456*(789+(90-80+20*5)-(30*20-10/5))",
                               };
    char postfix_expr[320] = { 0x00, };
    // .... 
}

void main(void) {
    exer4_postfix_eval();
    getchar();
}