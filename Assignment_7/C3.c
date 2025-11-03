//
#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}


void push(struct Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = ch;
}

char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

void reverseString(char str[]) {
    struct Stack s;
    initStack(&s);
    int i;

    
    for (i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }

    
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    gets(str); 

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
