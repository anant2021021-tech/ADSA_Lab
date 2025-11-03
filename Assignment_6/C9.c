//Write a function to check whether a given linked list is circular or not.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
int isCircular(struct Node* head) {
    if (head == NULL)
        return 0;  

    struct Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    return (temp == head);
}
void makeCircular(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;
}
void displayList(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    printf("List elements: ");
    while (temp != NULL && count < 10) { 
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("...\n");
}
int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    displayList(head);

    if (isCircular(head))
        printf("The linked list is circular.\n");
    else
        printf("The linked list is not circular.\n");
    makeCircular(head);

    if (isCircular(head))
        printf("After modification: The linked list is circular.\n");
    else
        printf("After modification: The linked list is not circular.\n");

    return 0;
}
