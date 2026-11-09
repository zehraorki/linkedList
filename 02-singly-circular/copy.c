#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
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

node*copy(node*head) {
    if (head==NULL) {
        printf("Liste bos\n");
        return NULL;
    }
    node* newhead=NULL;
    node*iter=head;
    do {
        newhead=insertAtEnd(newhead,iter->data);
        iter=iter->next;
    }while (iter!=head);
    return newhead;
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
    printf("Orijinal Liste: \n");
    printList(root);
    node*copyList=copy(root);
    printf("Kopya Liste: \n");
    printList(copyList);

    return 0;
}
