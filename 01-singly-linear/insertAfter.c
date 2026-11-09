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
node* insertAfter(node* head, int value, int target) {
    if (head == NULL) {
        return NULL;
    }
    node* iter = head;
    while (iter != NULL) {
        if (iter->data == target) {
            node* new = (node*)malloc(sizeof(node));
            if (new == NULL) return head;

            new->data = value;
            new->next = iter->next;
            iter->next = new;
            return head;
        }
        iter = iter->next;
    }
    printf("Hedef eleman (%d) bulunamadi!\n", target);
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
    node* root=(node*)malloc(sizeof(node));
    root->data=5;
    root->next=(node*)malloc(sizeof(node));
    root->next->data=10;
    root->next->next=NULL;

    root=addlast(root,15);
    root=addlast(root,20);
    root=addlast(root,30);
    printList(root);
    root=insertAfter(root,25,20);
    printList(root);




    return 0;
}
