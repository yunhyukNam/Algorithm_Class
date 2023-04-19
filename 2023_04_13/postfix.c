#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// #include <crtdbg.h>// �޸� ������ Ȯ���ϱ� ���� CRT ����� �Լ� ���

// * postfix ���� �� �������� operand�� ���ؼ��� ���갡��

typedef int element;// ���� ����(element)�� �ڷ����� int�� ���� 
typedef struct  stackNode {// ������ ��带 ����ü�� ����
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;// ������ top ��带 �����ϱ� ���� ������ top ����
/*
 * �������� �켱������ ��ȯ��
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

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����

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


// ������ ���� �������� Ȯ���ϴ� ����

int isEmpty() {
    if (top == NULL) return 1;
    
    else return 0;
}



// ������ top�� ���Ҹ� �����ϴ� ����

void push(element item) {
    stackNode* temp = (stackNode*)calloc(1, sizeof(stackNode));

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
        return 0;
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

        return 0;
    }
    else {// ������ ���� ����Ʈ�� �ƴ� ���
        return(top->data);  // ���� top�� ���� ��ȯ
    }
}

// ������ ��ȣ�� �˻��ϴ� ����
int testPair(char* exp) {
    char symbol, open_pair;
    // char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����

    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++) {
        //printStack();
        symbol = exp[i];
        switch (symbol) {
            // (1) ���� ��ȣ�� ���ÿ� ����
            case '(':case '[':case '{':
                push(symbol); 
                break;
            // (2) ������ ��ȣ�� ������,
            case ')':case ']':case '}':
                if (top == NULL) return 0;
                else {
                // (2)-1 ���ÿ��� ���������� ���� ��ȣ�� ����
                    open_pair = pop();
                // (2)-2 ��ȣ ���� �´��� �˻�
                    if ((open_pair == '(' && symbol != ')') ||
                        (open_pair == '[' && symbol != ']') ||
                        (open_pair == '{' && symbol != '}'))
                // (2)-3 ��ȣ ���� Ʋ���� ���� ����
                    return 0;
                // (2)-4 ��ȣ ���� ������ ���� symbol �˻縦 �����
                    else break;
                }
        }
    }
    if (top == NULL) return 1;// ���� �˻縦 ��ģ �� ������ �����̸� 1�� ��ȯ
    else return 0;            // ������ �ƴϸ� 0�� ��ȯ(���� ��ȣ Ʋ��)
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

// ���� ǥ��� ������ ����ϴ� ����
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