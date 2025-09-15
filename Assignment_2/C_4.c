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
     printf("Number of possible arrangments is %d",factorial(a));

    return 0;
}