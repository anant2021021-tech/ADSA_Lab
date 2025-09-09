// Online C compiler to run C program online
#include <stdio.h>

int palind_num(int num){
    int revNum=0;
    int reman;
    int origi=num;


while (num != 0) {
        reman = num % 10; 
        revNum = revNum * 10 + reman; 
        num = num / 10; 
    }
if(revNum==origi)return 1;
return 0;

}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    if(palind_num(num))
    {printf("The number is palindrome.");}
    else{
        printf("It is not a plaindrome.");
    }
    
    return 0;
}