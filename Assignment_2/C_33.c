 #include<stdio.h>

int main(){ 
    int arr[]={1,2,3,5,4,6,8,7,9};
    for(int i=0;i<9;i++){
        int temp=arr[i];
        if((temp&1)==0){
            printf("Even\n");
        }else{
            printf("Odd\n");
        }
    }
    return 0;
}