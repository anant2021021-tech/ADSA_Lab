#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build balanced BST from sorted array
struct Node* buildBalancedBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    struct Node* root = createNode(arr[mid]);

    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);

    return root;
}

// Queue for level-order traversal
struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1) return NULL;
    struct Node* temp = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}

int isEmpty() {
    return front == -1;
}

// Level-order traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);
        if (curr->right)
            enqueue(curr->right);
    }
}

int main() {
    int n;
    printf("Enter number of elements in sorted array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements (sorted): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildBalancedBST(arr, 0, n - 1);

    printf("\nLevel-Order Traversal of Balanced BST:\n");
    levelOrder(root);

    printf("\n");
    return 0;
}
