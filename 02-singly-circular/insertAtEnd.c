#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}node;

node* insertAtEnd(node*head,int value) {
    node* new=(node*)malloc(sizeof(node));
    if (new==NULL) {
        printf("Bellek hatasi!!\n");
        return head;
    }
    new->data=value;
    if (head==NULL) {
        new->next=new;
        return new;
    }
    node*iter=head;
    while (iter->next!=head) {
        iter=iter->next;
    }
    iter->next=new;
    new->next=head;

    return head;
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
    node*root=NULL;
    root=insertAtEnd(root,5);
    root=insertAtEnd(root,15);
    root=insertAtEnd(root,25);

    printList(root);

    return 0;
}
