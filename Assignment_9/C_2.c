#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


struct Queue {
    struct Node *arr[100];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, struct Node *node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue *q) {
    if (isEmpty(q)) return NULL;
    struct Node *temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

struct Node* createNode(int data) {
    if (data == -1) return NULL;   // -1 indicates NULL node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* buildTree() {
    int data;
    printf("Enter root value (-1 for no node): ");
    scanf("%d", &data);

    struct Node *root = createNode(data);
    if (!root) return NULL;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node *curr = dequeue(&q);

        printf("Enter left child of %d (-1 for no node): ", curr->data);
        scanf("%d", &data);
        curr->left = createNode(data);
        if (curr->left) enqueue(&q, curr->left);

        printf("Enter right child of %d (-1 for no node): ", curr->data);
        scanf("%d", &data);
        curr->right = createNode(data);
        if (curr->right) enqueue(&q, curr->right);
    }
    return root;
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return 1 + (leftH > rightH ? leftH : rightH);
}

int countLeafNodes(struct Node *root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right)+1;
}

int main() {
    struct Node *root = buildTree();
    printf("Height of the binary tree is::%d",height(root));
    printf("\n");
    printf("Total number of nodes in binary trees::%d",countLeafNodes(root));
    return 0;
}

