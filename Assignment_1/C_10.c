#include <stdio.h>

int main() {
    int num;
    int count=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    while (num != 0) {
        count++;
        num = num / 10; 
    }
    printf("Number of digits in the number is %d",count);
    return 0;
}