//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL; 
void push(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '\0'; 
    }

    struct Node* temp = top;
    char popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}


char peek() {
    if (top == NULL)
        return '\0';
    return top->data;
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == NULL)
                return 0; 
            char open = pop();
            if (!isMatchingPair(open, ch))
                return 0; 
        }
    }

    
    return (top == NULL);
}
void clearStack() {
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    char expression[100];

    printf("Enter an expression: ");
    gets(expression); 

    if (isBalanced(expression))
        printf("The expression has balanced parentheses.\n");
    else
        printf("The expression is NOT balanced.\n");

    clearStack();
    return 0;
}
