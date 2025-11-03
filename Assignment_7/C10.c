//Write a program using both stack and queue to check whether a given string is a palindrome.
#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
char queue[SIZE];
int top = -1;
int front = -1, rear = -1;

void push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack[top--];
}

void enqueue(char ch) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = ch;
}

char dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return '\0';
    }
    return queue[front++];
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    top = -1;
    front = rear = -1;
    for (int i = 0; i < len; i++) {
        push(str[i]);
        enqueue(str[i]);
    }
    for (int i = 0; i < len; i++) {
        if (pop() != dequeue())
            return 0;
    }

    return 1;
}

int main() {
    char str[SIZE];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str))
        printf("✅ The string \"%s\" is a palindrome.\n", str);
    else
        printf("❌ The string \"%s\" is not a palindrome.\n", str);

    return 0;
}
