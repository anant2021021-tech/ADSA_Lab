// Online C compiler to run C program online
#include <stdio.h>
 int fibnci_num(int n){
     if(n<0)printf("Invalid number.");
     if(n==0||n==1||n==2)return 1;
     return fibnci_num(n-1)+fibnci_num(n-2)+fibnci_num(n-3);

 }

int main() {
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);
     printf("Fibonacci number at thi place is %d",fibnci_num(a));

    return 0;
}