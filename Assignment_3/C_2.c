#include<stdio.h>

int main(){
    int arr[10]={2,3,4,5,6,7,8,9,10,1};
    int sum=0;
    int n = 10;
    int k=-1,l=-1;
    int target;
    printf("Enter the target value:");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==target){
                k=i;
                l=j;
                break;
            }
        }

        sum=0;
    }
    printf("Starting Index %d and ending index %d",k,l);
    return 0;

}