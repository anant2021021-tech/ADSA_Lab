#include <stdio.h>

int main() {
    int arr[11];  
    int n = 10;   
    int key;
    printf("Enter %d customer IDs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter ID to be searched: ");
    scanf("%d", &key);
    arr[n] = key;
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    if (i < n) {
        printf("ID %d found at index %d\n", key, i);
    } else {
        printf("ID %d not found!\n", key);
    }

    return 0;
}
