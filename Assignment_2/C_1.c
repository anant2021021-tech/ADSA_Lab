#include<stdio.h>

int main(){
    int arr[10];
    int i=0;
    int sum=0;
    printf("Enter amount of sales:");
    for(i;i<10;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp;
        sum+=temp;
        
    }
     printf("The total amount is %d",sum);

    return 0;
}