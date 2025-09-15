 #include<stdio.h>

int main(){ 
    int arr[]={1,2,3,5,4,6,8,7,9};
    for(int i=0;i<10;i++){
        if(arr[i]%2==0){
            printf("Even\n");
        }else{
            printf("Odd\n");
            
        }
    }
    return 0;
}