//Implement a double-ended queue (deque) using a circular array with insert and delete operations at both ends.
#include <stdio.h>
#define SIZE 5  

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}
int isEmpty() {
    return (front == -1);
}
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at front.\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front = front - 1;
    }

    deque[front] = value;
    printf("%d inserted at the front.\n", value);
}
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at rear.\n", value);
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear = rear + 1;
    }

    deque[rear] = value;
    printf("%d inserted at the rear.\n", value);
}
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from front.\n");
        return;
    }

    int deletedValue = deque[front];
    printf("%d deleted from the front.\n", deletedValue);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front = front + 1;
    }
}
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from rear.\n");
        return;
    }

    int deletedValue = deque[rear];
    printf("%d deleted from the rear.\n", deletedValue);
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear = rear - 1;
    }
}
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);
    insertFront(5);
    insertFront(2); 

    display();

    deleteRear();
    deleteFront();

    display();

    insertRear(40);
    insertFront(1);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
