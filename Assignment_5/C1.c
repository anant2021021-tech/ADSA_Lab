//Revesrsal of singly linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int d;
    struct node* next;
};

struct node *insert_LL(struct node*head,int r){
    struct node* first=(struct node*)malloc(sizeof(struct node));
    first->d=r;
    first->next=NULL;
    if(head==NULL){
        head=first;
        return head;
    }else{
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=first;
        return head;
    }

}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->d);
        head = head->next;
    }
    printf("NULL\n");
}
struct node* reverse_LL_It(struct node*head){
      struct node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;     
        current->next = prev;     
        prev = current;           
        current = next;           
    }
    return prev; 
}

struct node* reverseRecursive(struct node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct node* rest = reverseRecursive(head->next);
    head->next->next = head;  
    head->next = NULL;        
    return rest;              
}

int main(){  

    struct node* head=(struct node*)malloc(sizeof(struct node));
    head=NULL;
     head=insert_LL(head,2);
     head=insert_LL(head,3);
     head=insert_LL(head,4);
     head=insert_LL(head,5);
     head=insert_LL(head,6);
     
     printf("Original list::");
    display(head);
    //head=reverse_LL_It(head);  
    head=reverseRecursive(head);

    printf("After reversal::");
    display(head);



     return 0;
}