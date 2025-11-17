#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *left, *right;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL) return 0;
    return node->height;
}
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
int getBalance(struct Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    printf("Rotation Performed: RIGHT (LL Case)\n");

    return x;
}
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    printf("Rotation Performed: LEFT (RR Case)\n");

    return y;
}


struct Node* insert(struct Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // RR
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // LR
    if (balance > 1 && data > node->left->data) {
        printf("Rotation Performed: LEFT-RIGHT (LR Case)\n");
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && data < node->right->data) {
        printf("Rotation Performed: RIGHT-LEFT (RL Case)\n");
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {             
                *root = *temp;
            }

            free(temp);
        } 
        else {
            struct Node* temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);


    if (balance > 1 && getBalance(root->left) >= 0) {
        printf("Rotation Performed: RIGHT (LL Case)\n");
        return rightRotate(root);
    }

    
    if (balance > 1 && getBalance(root->left) < 0) {
        printf("Rotation Performed: LEFT-RIGHT (LR Case)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0) {
        printf("Rotation Performed: LEFT (RR Case)\n");
        return leftRotate(root);
    }

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        printf("Rotation Performed: RIGHT-LEFT (RL Case)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int getTreeHeight(struct Node* root) {
    return height(root);
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter values to insert:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nAVL Tree Deletion:\n");
    int d;

    printf("Enter number of deletions: ");
    scanf("%d", &d);

    while (d--) {
        printf("\nEnter value to delete: ");
        scanf("%d", &value);

        root = deleteNode(root, value);

        printf("Height of Tree: %d\n", getTreeHeight(root));
    }

    return 0;
}
