//
#include <stdio.h>

void partialSelectionSort(int arr[], int n, int k) {
    int i, j, minIndex, temp;
    for (i = 0; i < k; i++) {
        minIndex = i;

        
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }


        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printf("Iteration %d: ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k (number of smallest elements to sort): ");
    scanf("%d", &k);

    if (k > n || k <= 0) {
        printf("Invalid value of k!\n");
        return 0;
    }

    printf("\nPartial Selection Sort Progress:\n");
    partialSelectionSort(arr, n, k);

    printf("\nPartially Sorted Array (first %d elements sorted): ", k);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
