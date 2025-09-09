// Online C compiler to run C program online
#include <stdio.h>
 int factorial(int n){
     if(n<0)printf("Invalid number.");
     if(n==0||n==1)return 1;
     return n*factorial(n-1);
 }

int main() {
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);
     printf("Factorial of this number is %d",factorial(a));

    return 0;
}