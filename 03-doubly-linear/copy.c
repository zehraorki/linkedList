#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* insertAtEnd(node*head,int value) {
    node* new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;

    if (head==NULL) {
        new->prev=NULL;
        return new;
    }
    node*iter=head;
    while (iter->next!=NULL) {
        iter=iter->next;
    }
    iter->next=new;
    new->prev=iter;
    return head;
}

void printList(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

node* copy(node*head) {
    if (head==NULL) {
        return NULL;
    }
    node* new=NULL;
    node*iter=head;
    while (iter!=NULL) {
        new=insertAtEnd(new,iter->data);
        iter=iter->next;
    }
    return new;
}

int main(){
    node* root=(node*)malloc(sizeof(node));
    root->data=40;
    root->prev=NULL;
    root->next=NULL;

    root=insertAtEnd(root,50);
    root=insertAtEnd(root,60);
    root=insertAtEnd(root,70);
    root=insertAtEnd(root,80);
    printf("Orijinal Liste: \n");
    printList(root);

    printf("Kopya Liste: \n");
    node*kopya=copy(root);
    printList(kopya);

    return 0;
}

