//Implement a merge procedure using two queues (each containing sorted integers) and output a single sorted queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front > q->rear;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }
    return q->arr[q->front++];
}

int peek(struct Queue *q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void mergeQueues(struct Queue *q1, struct Queue *q2, struct Queue *result) {
    while (!isEmpty(q1) && !isEmpty(q2)) {
        if (peek(q1) <= peek(q2))
            enqueue(result, dequeue(q1));
        else
            enqueue(result, dequeue(q2));
    }
    while (!isEmpty(q1))
        enqueue(result, dequeue(q1));
    while (!isEmpty(q2))
        enqueue(result, dequeue(q2));
}

int main() {
    struct Queue q1, q2, merged;
    int n1, n2, val;

    initQueue(&q1);
    initQueue(&q2);
    initQueue(&merged);

    printf("Enter number of elements in first sorted queue: ");
    scanf("%d", &n1);
    printf("Enter elements (in sorted order): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        enqueue(&q1, val);
    }

    printf("Enter number of elements in second sorted queue: ");
    scanf("%d", &n2);
    printf("Enter elements (in sorted order): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        enqueue(&q2, val);
    }

    printf("\nQueue 1: ");
    display(&q1);
    printf("Queue 2: ");
    display(&q2);

    mergeQueues(&q1, &q2, &merged);

    printf("\nMerged Sorted Queue: ");
    display(&merged);

    return 0;
}
