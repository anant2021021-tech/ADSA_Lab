#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(struct Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;   
    return node;
}
int getBalance(struct Node* n) {
    if (n == NULL) return 0;
    return height(n->left) - height(n->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    printf("Rotation performed: RIGHT ROTATION (LL Case)\n");
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    printf("Rotation performed: LEFT ROTATION (RR Case)\n");
    return y;
}


struct Node* insert(struct Node* node, int key) {

    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);

    else if (key > node->data)
        node->right = insert(node->right, key);

    else {
        printf("Duplicate keys not allowed!\n");
        return node;
    }


    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);
    // LL Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->data) {
        printf("Rotation performed: LEFT-RIGHT ROTATION (LR Case)\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->data) {
        printf("Rotation performed: RIGHT-LEFT ROTATION (RL Case)\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // balanced
}

void printBalance(struct Node* root) {
    if (root == NULL) return;
    printBalance(root->left);
    printf("Node %d → BF = %d\n", root->data, getBalance(root));
    printBalance(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nInsert value: ");
        scanf("%d", &val);

        root = insert(root, val);

        printf("\nBalance Factors after inserting %d:\n", val);
        printBalance(root);
        printf("-------------------------------\n");
    }

    return 0;
}
