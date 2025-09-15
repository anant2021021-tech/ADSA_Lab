#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char str[20];  
    int i, len, flag = 0;

    printf("Enter a number: ");
    scanf("%d", &num);
    sprintf(str, "%d", num);
    len = strlen(str);
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("%d is a Palindrome\n", num);
    } else {
        printf("%d is NOT a Palindrome\n", num);
    }

    return 0;
}
