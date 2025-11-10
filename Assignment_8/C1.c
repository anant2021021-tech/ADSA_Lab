//Implement selection sort on an array of integers and print the array after each iteration to show the sorting progress.
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the index of the smallest element in the unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first unsorted element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Print array after each iteration
        printf("Iteration %d: ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSelection Sort Progress:\n");
    selectionSort(arr, n);

    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
