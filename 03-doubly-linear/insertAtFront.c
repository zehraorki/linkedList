#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* insertAtFront(node*head,int value) {
    node* new=(node*)malloc(sizeof(node));
    new->data=value;
    new->prev=NULL;

    if (head==NULL) {
        new->next=NULL;
        return new;
    }
    head->prev=new;
    new->next=head;
    return new;
}

int main(){
    node* root=(node*)malloc(sizeof(node));
    root->data=40;
    root->prev=NULL;
    root->next=NULL;

    root=insertAtFront(root,50);
    printf("%d -> %d ",root->data,root->next->data);  //50->40


    return 0;
}
