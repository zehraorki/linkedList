#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* removeNode(node* head,int value) {
    if (head==NULL) {
        printf("Listede Boş\n");
        return NULL;
    }
    node* iter=head;
    if (head->data==value) {   //basta
        head=head->next;
        free(iter);
        return head;
    }
    while (iter->next!=NULL && iter->next->data!=value ) {
        iter=iter->next;
    }
    if (iter->next==NULL) {
        printf("Aranan deger bulunamadi");
        return head;
    }

    node* temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
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

int main(void) {
    node* n1 =(node*)malloc(sizeof(node));
    node* n2 =(node*)malloc(sizeof(node));
    node* n3 =(node*)malloc(sizeof(node));
    node* n4 =(node*)malloc(sizeof(node));
    node* n5 =(node*)malloc(sizeof(node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = n5;
    n5->data = 50; n5->next = NULL;

    node* root=n1;

    root= removeNode(n1,50);
    printList(root);


    return 0;
}
