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

node* concatenate(node*list1,node*list2) {
    if (list1==NULL) {
        return list2;
    }
    if (list2==NULL) {
        return list1;
    }
    node*iter=list1;
    while (iter->next!=NULL) {
        iter=iter->next;
    }
    iter->next=list2;
    list2->prev=iter;
    return list1;
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
    printf("Birinci Liste: \n");
    printList(root);

    node* root2=(node*)malloc(sizeof(node));
    root2->data=100;
    root2->prev=NULL;
    root2->next=NULL;

    root2=insertAtEnd(root2,110);
    root2=insertAtEnd(root2,120);
    root2=insertAtEnd(root2,130);
    root2=insertAtEnd(root2,140);
    printf("İkinci Liste: \n");
    printList(root2);

    printf("Birlesik Liste: \n");
    node*new=concatenate(root,root2);
    printList(new);
    
    return 0;
}

