//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;  
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (last == NULL) {
        last = newNode;
        last->next = last;  
        printf("%d inserted as the first node.\n", value);
        return;
    }
    newNode->next = last->next;
    last->next = newNode;

    printf("%d inserted at the beginning.\n", value);
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        last->next = last;
        printf("%d inserted as the first node.\n", value);
        return;
    }
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    printf("%d inserted at the end.\n", value);
}
void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;  
    printf("Circular Singly Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to start)\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    displayList();

    insertAtBeginning(5);
    insertAtBeginning(1);

    displayList();

    insertAtEnd(40);
    displayList();

    return 0;
}
