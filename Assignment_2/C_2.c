 #include<stdio.h>

int main(){
    int arr[10];
    int i;
    int sum=0;
    printf("Enter temperatures this week:");
    for(i=0;i<7;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp; 
    }
    for(i=0;i<7;i++){
        int temp;
        temp=arr[i];
        if(sum<temp){
            sum=temp;
        }

        
    }
     printf("The maximum temprature this week is %d",sum);

    return 0;
}