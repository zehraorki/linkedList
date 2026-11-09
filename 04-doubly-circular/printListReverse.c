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
void printListReverse(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    node*iter=head->prev;
    do {
        printf("%d -> ",iter->data);
        iter=iter->prev;
    }while (iter!=head->prev);
    printf("(head: %d)\n",head->prev->data);
}

int main() {
    node* root=(node*)malloc(sizeof(node));
    root->data=20;
    root->prev=root;
    root->next=root;
    root=insertAtEnd(root,30);
    root=insertAtEnd(root,40);
    root=insertAtEnd(root,50);
    printListReverse(root);
    return 0;
}
