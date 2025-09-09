// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int num,reman;
    int revNum=0;
    printf("Enter the number: ");
    scanf("%d",&num);

    while (num != 0) {
        reman = num % 10; 
        revNum = revNum * 10 + reman; 
        num = num / 10; 
    }
    printf("Reverse of the nuber is %d",revNum);
    return 0;
}