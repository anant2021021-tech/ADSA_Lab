#include<stdio.h>

int main(){
    int n;
    int amt;
    printf("Enter a elctric units used: ");
    scanf("%d",&n);



    if(n<=100){
        amt=5*n;

    }else if(n>100 & n<=200){
        amt=500+7*(n-100);

    }else{
        amt=1200+10*(n-200);

    }

    printf("Total electricity bill is: %d", amt);

    return 0;
}