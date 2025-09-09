// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int x,y;
    char opppp;
    printf("Enter the first number: ");
    scanf("%d",&x);
    printf("Enter the second number: ");
    scanf("%d",&y);

    printf("Enter operation to be performend:");
    scanf(" %c", &opppp);
    
   switch (opppp) {
    case '+':
        printf("%d + %d = %d\n", x, y, x + y);
        break;

    case '-':
        printf("%d - %d = %d\n", x, y, x - y);
        break;

    case '*':
        printf("%d * %d = %d\n", x, y, x * y);
        break;
    case '/':
        printf("%d / %d = %d\n", x, y, x / y);
        break;
    default:
        printf("Invalid Operator Input\n");
    }
    return 0;
}