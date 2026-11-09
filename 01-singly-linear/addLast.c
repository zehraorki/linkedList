#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* addlast(node* head,int value) {
    node* yeni=(node*)malloc(sizeof(node));
    yeni->data=value;
    yeni->next=NULL;

    if (head == NULL) {
        return yeni;
    }

    node*iter=head;
    while (iter->next!=NULL) {
        iter=iter->next;
        }
    iter->next=yeni;
    return head;

}

void printList(node*head) {
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

void freeList(node*head) {
    node*iter=head;
    while (iter!=NULL) {
        node* temp=iter;
        iter=iter->next;
        free(temp);
    }
}

int main(void) {
    node* root=(node*)malloc(sizeof(node));
    root->data=5;
    root->next=(node*)malloc(sizeof(node));
    root->next->data=10;
    root->next->next=NULL;

    printf("Listenin İlk Hali : \n");
    printList(root);

    printf("Listenin Son Hali: \n");
    root=addlast(root,15);
    printList(root);

    freeList(root);


    return 0;
}
