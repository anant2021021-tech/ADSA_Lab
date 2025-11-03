//Implement a queue using an array and perform enqueue, dequeue, and display operations with overflow and underflow checks.
#include <stdio.h>
#define MAX 5  

int queue[MAX];
int front = -1, rear = -1;  

int isFull() {
    return (rear == MAX - 1);
}
int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)  
        front = 0;

    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }

    int removed = queue[front];
    printf("%d dequeued from the queue.\n", removed);
    front++;
    if (front > rear)
        front = rear = -1;
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); 

    display();

    dequeue();
    dequeue();
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue(); 

    return 0;
}
