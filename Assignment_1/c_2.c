// Online C compiler to run C program online
#include <stdio.h>
void check_num(int tk){
    if(tk%2==0){
        printf("It is a even token.");
    }else{
        printf("It is a odd token.");
    }
}
int main() {
    int token;
    
    printf("Enter token number:");
    scanf("%d",&token);
    
    check_num(token);

    return 0;
}