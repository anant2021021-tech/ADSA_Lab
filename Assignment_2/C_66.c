#include <stdio.h>
void print_num(int n){
    if(n==0)return;
    printf("%d,",n);
    print_num(n-1);
}
int main() {
    int a;
    printf("Enter the number: ");
    scanf("%d",&a);
    print_num(a);


    return 0;
}