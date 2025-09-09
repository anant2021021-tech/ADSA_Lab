// Online C compiler to run C program online
#include <stdio.h>

void largest_num(int a,int b,int c){
    if(a>b){
        if(a>c){
            printf("First Number is largest.");
        }else{
            printf("Third Number is largest.");
        }
    }else{
        if(b>c){
            printf("Second number is largest.");
        }else{
            printf("Third number is largest.");
        }
    }
}

int main() {
    int a,b,c;
    printf("Enter the first number: ");
    scanf("%d",&a);
    printf("Enter the second number: ");
    scanf("%d",&b);
    printf("Enter the third number: ");
    scanf("%d",&c);
    
    largest_num(a,b,c);

    return 0;
}