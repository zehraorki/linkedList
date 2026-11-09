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

node* concatenate(node*list1,node*list2) {
    if (list1==NULL) {
        return list2;
    }
    if (list2==NULL) {
        return list1;
    }
    node*tail=list1->prev;
    node*tail2=list2->prev;
    tail->next=list2;
    list2->prev=tail;
    tail2->next=list1;
    list1->prev=tail2;
    return list1;

}

int main() {
    node* root=(node*)malloc(sizeof(node));
    root->data=20;
    root->prev=root;
    root->next=root;
    root=insertAtEnd(root,30);
    root=insertAtEnd(root,40);
    root=insertAtEnd(root,50);

    node* root2=(node*)malloc(sizeof(node));
    root2->data=90;
    root2->prev=root2;
    root2->next=root2;
    root2=insertAtEnd(root2,100);
    root2=insertAtEnd(root2,110);
    root2=insertAtEnd(root2,120);

    printf("Birinci Liste: \n");
    printList(root);
    printf("İkinci Liste: \n");
    printList(root2);
    printf("Birleştirilmiş Liste: \n");
    node*new=concatenate(root,root2);
    printList(new);

    return 0;
}