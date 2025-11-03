//Implement a priority queue using an array, where each element has a (data, priority) pair, and dequeue should remove the element with the highest priority.
#include <stdio.h>
#define SIZE 10  

struct PriorityQueue {
    int data;
    int priority;
};

struct PriorityQueue pq[SIZE];
int count = 0;  

void enqueue(int data, int priority) {
    if (count == SIZE) {
        printf("Priority Queue Overflow! Cannot insert (%d, %d).\n", data, priority);
        return;
    }

    pq[count].data = data;
    pq[count].priority = priority;
    count++;
    printf("Inserted element: Data = %d, Priority = %d\n", data, priority);
}
int findHighestPriorityIndex() {
    if (count == 0)
        return -1;

    int highest = 0;
    for (int i = 1; i < count; i++) {
        if (pq[i].priority > pq[highest].priority)
            highest = i;
    }
    return highest;
}


void dequeue() {
    if (count == 0) {
        printf("Priority Queue Underflow! Queue is empty.\n");
        return;
    }

    int highestIndex = findHighestPriorityIndex();
    printf("Dequeued element: Data = %d, Priority = %d\n",
           pq[highestIndex].data, pq[highestIndex].priority);
    for (int i = highestIndex; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }

    count--;
}

void display() {
    if (count == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Current Priority Queue:\n");
    printf("Data\tPriority\n");
    printf("----\t---------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
    printf("\n");
}
int main() {
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 3);
    enqueue(40, 1);
    enqueue(50, 4);

    display();

    dequeue();  
    display();

    dequeue();  
    display();

    enqueue(60, 6);
    display();

    dequeue();  
    display();

    return 0;
}
