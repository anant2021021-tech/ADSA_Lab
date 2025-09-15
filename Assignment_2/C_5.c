#include <stdio.h>

int main() {
    int arr[10];
    int sum;

    printf("Enter 10 customer IDs:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter ID to be searched: ");
    scanf("%d", &sum);
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == sum) {
            printf("Present at index %d\n", i);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("ID not found!\n");
    }

    return 0;
}
