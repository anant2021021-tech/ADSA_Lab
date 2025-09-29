struct complex{
    int i;
    int j;
};
int main(){
    int temp1,temp2;
    struct complex c1;
    struct complex c2;
    printf("Enter  first complex number:");
    scanf("%d %d ",&c1.i, &c1.j);
    
    printf("Enter  second complex number:");
    scanf("%d %d ",&c2.i, &c2.j);

    printf("Before swapping c1 = %di %dj and c2 = %di %dj",c1.i,c1.j,c2.i,c2.j);
    printf("\n");

    temp1=c1.i;
    c1.i=c2.i;
    c2.i=temp1;

    temp2=c1.j;
    c1.j=c2.j;
    c2.j=temp2;
    


    printf("After swaps c1= %di %dj and c2 = %di %dj",c1.i,c1.j,c2.i,c2.j);
    
    
    
    return 0;
}