#include<stdio.h>

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int target;
    printf("Enter the roatation value:");
    scanf("%d",&target);
    target=target%10;

    int temp[10];
    int j=0;
    int k=(10-target);

    for(int i=k;i<10;i++){
        temp[j]=arr[i];
        j++;
    }

    for(int i=0;i<k;i++){
        temp[j]=arr[i];
        j++;
    }
    printf("After roattion the array becomes:");
    for(int i=0;i<10;i++){
        printf(" %d ",temp[i]);
    }
    return 0;
}