#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

node* insertAtEnd(node*head,int value) {
    node* new=(node*)malloc(sizeof(node));
    new->data=value;
    new->next=NULL;

    if (head==NULL) {
        new->prev=NULL;
        return new;
    }
    node*iter=head;
    while (iter->next!=NULL) {
        iter=iter->next;
    }
    iter->next=new;
    new->prev=iter;
    return head;
}
node* locate(node*head,int target){
    if (head==NULL) {
        return NULL;
    }
    node*iter=head;
    while (iter!=NULL) {
        if (iter->data==target) {
            return iter;
        }
        iter=iter->next;
    }
    return NULL;
}
void printList(node*head) {
    if (head==NULL) {
        return;
    }
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

int main(){
    node* root=(node*)malloc(sizeof(node));
    root->data=40;
    root->prev=NULL;
    root->next=NULL;

    root=insertAtEnd(root,50);
    root=insertAtEnd(root,60);
    root=insertAtEnd(root,70);
    root=insertAtEnd(root,80);
    printList(root);

    node*result=locate(root,50);

    if (result!=NULL) {
        printf("Veri: %d\n",result->data);
        printf("Verinin Adresi: %p\n",result);
        printf("Sonraki Dugmun Adresi: %p\n",result->next);
        printf("Onceki Dugumun Adresi: %p\n",result->prev);
    }else {
        printf("Girdiginiz Deger Bulunamadi\n");
    }

    return 0;
}

