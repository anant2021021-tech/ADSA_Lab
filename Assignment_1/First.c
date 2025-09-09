//Hello World and Swap Two numbers.

#include <stdio.h>

void swap_number(int *a,int *b){
  int temp;
    temp=*a;
     *a=*b;
     *b=temp;


}

int main() {
    printf("Hello world\n");
    int a,b;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    
    printf("Before swapping a = %d and b = %d",a,b);
    printf("\n");
    swap_number(&a,&b);
    printf("After swaps a = %d and b = %d",a,b);
    
     



    return 0;
}