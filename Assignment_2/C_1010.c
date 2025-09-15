#include<stdio.h>

int main(){
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
     
    printf("Before swapping a = %d and b = %d",a,b);
    printf("\n");
    a=a^b;
    b=a^b;
    a=a^b;

    printf("After swaps a = %d and b = %d",a,b);
    return 0;
}