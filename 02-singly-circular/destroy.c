#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

void destroy(node**head) {
    if (head==NULL || *head==NULL) {
        printf("Liste zaten bos\n");
        return;
    }
    node*iter=*head;
    while (iter->next!=(*head)) {
        node*temp=iter->next;
        iter->next=temp->next;
        free(temp);
    }
    free(*head);
    *head=NULL;
}

void printList(node*head) {
    if (head==NULL) {
        printf("Liste bos!\n");
        return;
    }
    node*iter=head;
    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head:%d)\n",head->data);
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

    node*root=n1;
    printList(root);
    destroy(&root);
    printList(root);

    return 0;
}
