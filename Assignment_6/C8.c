//Write a function to delete a node with a specific value from a circular linked list.
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
void deleteByValue(int value) {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *current = last->next, *prev = last;
    if (last == last->next && last->data == value) {
        free(last);
        last = NULL;
        printf("Node with value %d deleted. List is now empty.\n", value);
        return;
    }

    do {
        if (current->data == value) {
            prev->next = current->next;

            if (current == last)
                last = prev;

            if (current == last->next)
                last->next = current->next;

            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != last->next);

    printf("Node with value %d not found in the list.\n", value);
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
    insertAtEnd(50);

    printf("Original List:\n");
    displayList();

    deleteByValue(10);  
    displayList();

    deleteByValue(50);  
    displayList();

    deleteByValue(30);  
    displayList();

    deleteByValue(100); 
    displayList();

    return 0;
}
