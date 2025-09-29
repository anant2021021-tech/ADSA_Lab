struct node{
    int data;
    struct node *next;
};

int main(){
    struct node l1;
    l1.data=4;
    l1.next=&l1;

    printf("Node data:%d",l1.data);
    printf("Next Node adress:%u",l1.next);
    


    return 0;
}