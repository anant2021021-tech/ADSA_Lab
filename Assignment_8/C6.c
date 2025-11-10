//
#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arr[], int left, int right) {
    int i, j, min, temp;
    for (i = left; i < right; i++) {
        min = i;
        for (j = i + 1; j <= right; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
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
void hybridSort(int arr[], int n, int chunkSize) {
    for (int i = 0; i < n; i += chunkSize) {
        int right = i + chunkSize - 1;
        if (right >= n)
            right = n - 1;
        selectionSort(arr, i, right);
    }

    printf("\nAfter Selection Sort on Each Chunk:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int size = chunkSize; size < n; size *= 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;
            if (mid >= n - 1)
                continue;
            if (right >= n)
                right = n - 1;
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n, chunkSize;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter chunk size: ");
    scanf("%d", &chunkSize);

    hybridSort(arr, n, chunkSize);

    printf("\nFinal Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
