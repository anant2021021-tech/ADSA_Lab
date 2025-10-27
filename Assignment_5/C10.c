//Remove duplicate elements from a sorted linked list so that each element appears only once.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            
            nextNode = current->next->next;
            current->next=nextNode->next;
            free(nextNode);
        }
    }
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 20);
    insertEnd(&head, 50);

    printf("Linked List before operations:\n");
    display(head);

    removeDuplicates(head);
    
    printf("Linked List after operations:\n");
       display(head);

    return 0;
}
