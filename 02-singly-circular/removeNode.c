#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* removeNode(node* head,int value) {
    if (head==NULL) {
        printf("Bellek bos!\n");
        return NULL;
    }
    node*iter=head;
    node*newhead=NULL;

    if (head->data==value && head->next==head) {
        free(head);
        return NULL;
    }
    if (head->data==value) {
        while (iter->next!=head) {    // 3 5 7 8
            iter=iter->next;
        }
        newhead=head->next;   // yeni head belirlendi
        iter->next=newhead;   //son eleman yeni head e baglandi
        free(head);           //eski head silindi
        return newhead;       //yeni head döndürüldü

    }
    while (iter->next!=head) {
        if (iter->next->data==value) {
            node* temp=iter->next;
            iter->next=iter->next->next;
            free(temp);
            return head;
        }
        iter=iter->next;
    }
    printf("Aradiginiz deger bulunamadi\n");
    return head;
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
    node*root=(node*)malloc(sizeof(node));
    root->data=5;
    root->next=(node*)malloc(sizeof(node));
    root->next->data=10;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->data=20;
    root->next->next->next=root;


    printList(root);
    printf("**************\n");
    root=removeNode(root,10);
    printList(root);

    return 0;
}
