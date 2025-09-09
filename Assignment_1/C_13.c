#include<stdio.h>

int main(){
    int arr[]={25,45,75,84,7,58,95,6,5};
    int max_val = arr[0];

    int n = sizeof(arr) / sizeof(arr[0]); 

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    printf("The maximum value in the array is: %d\n", max_val);



    return 0;
}