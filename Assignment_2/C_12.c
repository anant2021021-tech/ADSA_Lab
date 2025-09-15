#include<stdio.h>

int sum_array(int ar[],int i,int sum){
    int temp=ar[i];
    sum=temp+sum_array(ar,i+1,sum);
    return sum;
}
int main(){
    int arr[10];
    int i;
    printf("Enter amount of sales:");
    for(i=0;i<10;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp;

    }
     printf("The total amount is %d",sum_array(arr,0,0));

    return 0;
}