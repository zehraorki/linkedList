#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* copy(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* temp=head;
    node* newHead=NULL;
    node* tail=NULL;

    while (temp!=NULL) {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=temp->data;
        newnode->next=NULL;

        if (newHead == NULL) {
            newHead = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        temp = temp->next;
    }
    return newHead;
}

void printList(node*head){
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

void clear(node**head) {
    node*iter=*head;
    while (iter!=NULL) {
        node*temp=iter;
        iter=iter->next;
        free(temp);
    }
    *head=NULL;
}

int main(void) {
    node *n1=(node*)malloc(sizeof(node));
    node *n2=(node*)malloc(sizeof(node));
    node *n3=(node*)malloc(sizeof(node));
    node *n4=(node*)malloc(sizeof(node));

    n1->data=5; n1->next=n2;
    n2->data=15; n2->next=n3;
    n3->data=25; n3->next=n4;
    n4->data=35; n4->next=NULL;

    node* root=n1;
    printf("Birinci Liste: \n");
    printList(root);
    printf("İkinci Liste: \n");
    node* new= copy(root);
    printList(new);

    clear(&root);
    clear(&new);
    printf("Lİsteler temizlendi. \n");

    return 0;
}
