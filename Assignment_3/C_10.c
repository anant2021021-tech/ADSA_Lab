#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    bool duplicate = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) break;
    }

    if (duplicate)
        printf("True: Array contains duplicates.\n");
    else
        printf("False: All elements are distinct.\n");

    return 0;
}
