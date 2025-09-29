#include<stdio.h>
#include<math.h>

int main(){
    int secnd_larg;
    int larg;
    int arr[10]={100,100,-1000,1000,500,-10012,10,12,12,32};
    larg=arr[0];
    secnd_larg=arr[0];
    for(int i=0;i<10;i++){
        if(arr[i]>larg){
            secnd_larg=larg;
            larg=arr[i];
            
        }else if((arr[i]>secnd_larg) && (arr[i]<larg)){
            secnd_larg=arr[i];
        }

    }

    printf("Second largest number:%d",secnd_larg);
    return 0;
}