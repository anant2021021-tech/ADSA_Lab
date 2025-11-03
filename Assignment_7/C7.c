//Implement a circular queue using an array and perform enqueue, dequeue, and display operations demonstrating wrap-around behavior.

#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;


int isFull() {
    return (front == (rear + 1) % SIZE);
}
int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }

    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d enqueued to the circular queue.\n", value);
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    int deletedValue = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;  

    printf("%d dequeued from the circular queue.\n", deletedValue);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60); 
    enqueue(70);

    display();

    dequeue();
    display();

    return 0;
}
