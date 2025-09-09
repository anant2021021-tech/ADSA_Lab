#include<stdio.h>

int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

int main(){
    int number;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        int sum = sumOfDigits(number);
        printf("Sum of digits of %d is %d\n", number, sum);
    }
    return 0;
}