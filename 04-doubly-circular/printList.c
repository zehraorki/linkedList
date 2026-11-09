#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;
node* insertAtEnd(node*head,int value) {
    node*new=(node*)malloc(sizeof(node));
    new->data=value;
    if (head==NULL) {
        new->next=new;
        new->prev=new;
        return new;
    }                                  
    node*tail=head->prev;
    new->next=head;
    new->prev=tail;
    head->prev=new;
    tail->next=new;
    return head;
}
void printList(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    node*iter=head;
    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head: %d)\n",head->data);
}

int main() {
    node* root=(node*)malloc(sizeof(node));
    root->data=20;
    root->prev=root;
    root->next=root;
    root=insertAtEnd(root,30);
    root=insertAtEnd(root,40);
    root=insertAtEnd(root,50);
    printList(root);
    return 0;
}