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

node* removeNode(node* head,int target) {
    if (head==NULL) {
        return NULL;
    }

    if (head->next==head && head->data==target) {
        free(head);
        return NULL;
    }
    if (head->data==target) {
        node*temp=head;
        node*tail=head->prev;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
        return head;
    }
    node*iter=head;
    do {
       if (iter->data==target) {
           iter->prev->next=iter->next;
           iter->next->prev=iter->prev;
           free(iter);
           return head;
       }
        iter=iter->next;
    }while (iter!=head);
    printf("Silmek istediginiz deger bulunamadi\n");
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


int main() {
    node* root=(node*)malloc(sizeof(node));
    root->data=20;
    root->prev=root;
    root->next=root;
    root=insertAtEnd(root,30);
    root=insertAtEnd(root,40);
    root=insertAtEnd(root,50);
    printList(root);
    printf("Düğüm siliniyor...\n");
    root=removeNode(root,30);
    printList(root);
    return 0;
}
