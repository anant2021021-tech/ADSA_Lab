//
#include <stdio.h>
#include <stdlib.h>
struct Frame {
    int left;
    int right;
    int mid;
    int stage; 
};

#define MAX 100
struct Stack {
    struct Frame items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, struct Frame f) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->items[++s->top] = f;
}

struct Frame pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->items[s->top--];
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void iterativeMergeSort(int arr[], int n) {
    struct Stack stack;
    initStack(&stack);

    struct Frame initial = {0, n - 1, 0, 0};
    push(&stack, initial);

    while (!isEmpty(&stack)) {
        struct Frame f = pop(&stack);

        if (f.stage == 0) { 
            if (f.left < f.right) {
                f.mid = (f.left + f.right) / 2;

                struct Frame mergeFrame = {f.left, f.right, f.mid, 1};
                push(&stack, mergeFrame);

                
                struct Frame rightFrame = {f.mid + 1, f.right, 0, 0};
                struct Frame leftFrame = {f.left, f.mid, 0, 0};
                push(&stack, rightFrame);
                push(&stack, leftFrame);
            }
        } else if (f.stage == 1) { 
            merge(arr, f.left, f.mid, f.right);

            printf("Merged [%d..%d]: ", f.left, f.right);
            for (int i = f.left; i <= f.right; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nInitial Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    iterativeMergeSort(arr, n);

    printf("\nFinal Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
