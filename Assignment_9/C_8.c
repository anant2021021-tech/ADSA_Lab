#include <stdio.h>
#include <stdlib.h>

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
int checkAVL(struct Node* root, int* balanced) {
    if (root == NULL)
        return 0;

    int lh = checkAVL(root->left, balanced);
    int rh = checkAVL(root->right, balanced);

    if (lh == -1 || rh == -1) {
        *balanced = 0;
        return -1;
    }

    int bf = lh - rh;
    printf("Node %d → Balance Factor = %d\n", root->data, bf);

    if (bf < -1 || bf > 1) {
        *balanced = 0;
        return -1;
    }

    return 1 + (lh > rh ? lh : rh);
}
int isAVL(struct Node* root) {
    int balanced = 1;
    checkAVL(root, &balanced);
    return balanced;
}

int main() {

    
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);

    printf("Balance Factors:\n");
    int result = isAVL(root);

    if (result)
        printf("\nThe tree IS height-balanced (AVL).\n");
    else
        printf("\nThe tree is NOT height-balanced (NOT AVL).\n");

    return 0;
}
