#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* insertAfter(node*head,int target,int value) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }

    node* iter = head;
    do {
        if (iter->data == target) {
            node* new = (node*)malloc(sizeof(node));
            if (new == NULL) {
                printf("Bellek Hatasi!\n");
                return head;
            }
            new->data = value;
            new->next = iter->next;
            iter->next = new;
            return head;
        }
        iter = iter->next;
    } while (iter != head);
    printf("Aranan deger (%d) listede bulunamadi!\n", target);
    return head;
    
}

void printList(node*head) {
    if (head==NULL) {
        printf("Bellek bos!\n");
    }
    node*iter=head;
    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head: %d)\n",head->data);
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
    printf("***********\n");

    root=insertAfter(root,10,15);
    printList(root);

    return 0;
}
