//Write a program to split a circular linked list into two halves and display both lists.
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
void splitCircularList(struct Node* head, struct Node** head1, struct Node** head2) {
    if (head == NULL) {
        *head1 = *head2 = NULL;
        return;
    }

    struct Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next->next == head)
        fast = fast->next;
    *head1 = head;
    if (head->next != head)
        *head2 = slow->next;
    fast->next = slow->next;
    slow->next = head;
}
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to start)\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);

    printf("Original Circular Linked List:\n");
    displayList(last->next);

    struct Node *head1 = NULL, *head2 = NULL;
    splitCircularList(last->next, &head1, &head2);

    printf("\nFirst Half:\n");
    displayList(head1);

    printf("\nSecond Half:\n");
    displayList(head2);

    return 0;
}
