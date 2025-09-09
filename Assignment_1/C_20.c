#include<stdio.h>

int binarySearch(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1; 
    }
    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
        return mid; 
    }
    else if (arr[mid] > target) {
        return binarySearch(arr, start, mid - 1, target);
    }
    else {
        return binarySearch(arr, mid + 1, end, target);
    }
}

int main(){
    int array[] = {10,20,30,40,50,60,70,90,100,120,130,165};
    int n = sizeof(array) / sizeof(array[0]); 
    int x;
    printf("Enter the Book_Id for search: ");
    scanf("%d", &x);

    int res = binarySearch(array, 0, n - 1, x);
    if (res != -1) {
        printf("Book found at index: %d\n", res);
    } else {
        printf("Book not found in the array.\n");
    }


    return 0;
}