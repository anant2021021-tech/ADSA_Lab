// Online C compiler to run C program online
#include <stdio.h>
#include<math.h>

int is_prime(int n){
    int i;
if(n<=1)printf("Invalid  numbers only positive numbers valid.");
for (i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return 0;
                break;    
            }
        }

return 1;
}

int main() {
    int n;
    printf("Enter a positive number: ");
    scanf("%d",&n);

if (is_prime(n) == 1) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }


    return 0;
}