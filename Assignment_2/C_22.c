 #include<stdio.h>

int main(){
    int arr[10];
    int i,j;
    printf("Enter temperatures this week:");
    for(i=0;i<7;i++){
        int temp;
        scanf("%d",&temp);
        arr[i]=temp; 
    }
    for(i=0;i<7;i++){
        for(j=i+1;j<6;j++){
        if(arr[i]>arr[j]){
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }  
        }
    }

     printf("The maximum temprature this week is %d",arr[2]);

    return 0;
}