#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* concatenate(node*list1,node*list2) {
    if (list1==NULL ) {
        return list2;
    }
    if (list2==NULL ) {
        return list1;
    }
    node*iter=list1;
    while (iter->next!=list1) {
        iter=iter->next;
    }
    iter->next=list2;
    node*iter2=list2;
    while (iter2->next!=list2) {
        iter2=iter2->next;
    }
    iter2->next=list1;
    return list1;
}

void printList(node*head) {
    if (head==NULL) {
        printf("Bellek bos!!\n");
        return;
    }
    node*iter=head;

    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head: %d)\n",head->data);
}

int main(void) {
    node* n1=(node*)malloc(sizeof(node));
    node* n2=(node*)malloc(sizeof(node));
    node* n3=(node*)malloc(sizeof(node));
    node* n4=(node*)malloc(sizeof(node));
    node* n5=(node*)malloc(sizeof(node));

    n1->data=10; n1->next=n2;
    n2->data=20; n2->next=n3;
    n3->data=30; n3->next=n4;
    n4->data=40; n4->next=n5;
    n5->data=50; n5->next=n1;
    node*root1=n1;

    node* s1=(node*)malloc(sizeof(node));
    node* s2=(node*)malloc(sizeof(node));
    node* s3=(node*)malloc(sizeof(node));
    node* s4=(node*)malloc(sizeof(node));
    node* s5=(node*)malloc(sizeof(node));

    s1->data=70; s1->next=s2;
    s2->data=80; s2->next=s3;
    s3->data=90; s3->next=s4;
    s4->data=100; s4->next=s5;
    s5->data=110; s5->next=s1;
    node*root2=s1;

    printf("1. Liste: \n");
    printList(root1);
    printf("2. Liste: \n");
    printList(root2);
    printf("Birlestirilmis Liste: \n");
    node*new=concatenate(root1,root2);
    printList(new);

    return 0;
}
