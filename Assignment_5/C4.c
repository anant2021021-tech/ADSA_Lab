//Write a program to detect whether a linked list contains a loop using Floyd’s Cycle Detection Algorithm.
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
 
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow && fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;  
}

void display(struct Node* head) {
    struct Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 20) {  
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
        printf("... (loop detected while displaying)");
    else
        printf("NULL");
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    head->next->next->next->next->next = head->next;   //Looping condition for linked list

     
    if (detectLoop(head))
        printf("Loop is ther in LL!\n");
    else
        printf("No loop in LL.\n");

    return 0;
}
