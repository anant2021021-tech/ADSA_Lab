//Write a function to insert a new node after a given node in a circular linked list.
#include <stdio.h>
#include <stdlib.h>

// Structure for circular singly linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;  // Pointer to the last node

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end (for testing)
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (last == NULL) {
        last = newNode;
        last->next = last;
        return;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}
void insertAfter(int targetValue, int newValue) {
    if (last == NULL) {
        printf("List is empty. Cannot insert.\n");
        return;
    }

    struct Node* temp = last->next; 
    do {
        if (temp->data == targetValue) {
            struct Node* newNode = createNode(newValue);
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode;

            printf("%d inserted after %d.\n", newValue, targetValue);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    printf("Node with value %d not found.\n", targetValue);
}

void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
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
    insertAtEnd(40);

    printf("Original List:\n");
    displayList();

    insertAfter(20, 25);  
    insertAfter(40, 50); 
    insertAfter(100, 60); 

    printf("\nUpdated List:\n");
    displayList();

    return 0;
}
