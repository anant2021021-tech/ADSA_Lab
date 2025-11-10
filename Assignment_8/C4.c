//Write a function to merge two sorted linked lists into one sorted linked list. Do not use arrays or extra data structures.
#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
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

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists into one sorted list
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // If either list is empty
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* mergedHead = NULL;
    struct Node* tail = NULL;

    // Initialize mergedHead
    if (list1->data <= list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }
    tail = mergedHead;

    // Traverse both lists
    while (list1 && list2) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes (if any)
    if (list1)
        tail->next = list1;
    else
        tail->next = list2;

    return mergedHead;
}

// Main function to test
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged = NULL;

    int n1, n2, val;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter elements (in sorted order): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter elements (in sorted order): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("\nFirst List: ");
    printList(list1);
    printf("Second List: ");
    printList(list2);

    merged = mergeSortedLists(list1, list2);

    printf("\nMerged Sorted List: ");
    printList(merged);

    return 0;
}
