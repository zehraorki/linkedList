#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
void printList(node*head){
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

node* destroy(node*head) {
    if (head == NULL) {
        return NULL;
    }
    destroy(head->next);
    free(head);
    return NULL;
}

int main(void) {
    node *n1=(node*)malloc(sizeof(node));
    node *n2=(node*)malloc(sizeof(node));
    node *n3=(node*)malloc(sizeof(node));
    node *n4=(node*)malloc(sizeof(node));

    n1->data=5;  n1->next=n2;
    n2->data=15; n2->next=n3;
    n3->data=25; n3->next=n4;
    n4->data=35; n4->next=NULL;

    node* root=n1;
    printList(root);
    printf("Liste temizlenecek :\n");
    root=destroy(root);
    printList(root);

    return 0;
}
