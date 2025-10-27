//Delete nodes from a singly linked list from:
//• The beginning
//• The end
//• A given position

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


void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;  
    printf("Deleted node: %d\n", temp->data);
    free(temp);
}
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted node: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
        return;
    }
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = temp->next->next;

    printf("Deleted node: %d\n", delNode->data);
    free(delNode);
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Initial Linked List:\n");
    display(head);
    printf("\nAfter deleting from beginning:\n");
    deleteFromBeginning(&head);
    display(head);
    printf("\nAfter deleting from end:\n");
    deleteFromEnd(&head);
    display(head);

    printf("\nAfter deleting from position 2:\n");
    deleteFromPosition(&head, 2);
    display(head);

    return 0;
}
