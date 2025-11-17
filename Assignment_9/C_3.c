#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isBST(struct Node* root, int min, int max) {
    if (root == NULL)
        return 1;


    if (root->data < min || root->data > max)
        return 0;

    return isBST(root->left, min, root->data - 1) &&
           isBST(root->right, root->data + 1, max);
}

int main() {
    

    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->right->left = createNode(15);

    if (isBST(root, INT_MIN, INT_MAX))
        printf("The tree IS a Binary Search Tree.\n");
    else
        printf("The tree is NOT a Binary Search Tree.\n");

    return 0;
}
