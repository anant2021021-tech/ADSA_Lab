//Implement selection sort on a singly linked list using node swaps.
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void selectionSort(struct Node** headRef) {
    struct Node *start, *min, *beforeMin, *r;
    
    for (start = *headRef; start && start->next; start = start->next) {
        min = start;
        beforeMin = NULL;
        r = start;
        while (r->next != NULL) {
            if (r->next->data < min->data) {
                min = r->next;
                beforeMin = r;
            }
            r = r->next;
        }

        if (min != start) {
            if (beforeMin != NULL)
                beforeMin->next = start;
            struct Node* temp = start->next;
            start->next = min->next;
            min->next = temp;
            if (start == *headRef)
                *headRef = min;
            else {
                struct Node* prev = *headRef;
                while (prev->next != start)
                    prev = prev->next;
                prev->next = min;
            }
            struct Node* tmp = start;
            start = min;
            min = tmp;
        }
        printf("List after iteration: ");
        printList(*headRef);
    }
}

int main() {
    struct Node* head = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    printf("\nOriginal List: ");
    printList(head);

    selectionSort(&head);

    printf("\nSorted List: ");
    printList(head);

    return 0;
}
