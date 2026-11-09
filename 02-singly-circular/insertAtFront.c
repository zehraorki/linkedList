#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node* insertAtFront(node*head,int value) {
    node*new=(node*)malloc(sizeof(node));
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
    while (iter->next != head) {
        iter=iter->next;
    }
    new->next=head;
    iter->next=new;
    return new;
}

void printList(node*head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }
    node* iter = head;
    do {
        printf("%d -> ", iter->data);
        iter = iter->next;
    } while (iter != head);
    printf("(head: %d)\n", head->data);
}

int main(void) {
    node* root = NULL;

    root = insertAtFront(root, 15);
    root = insertAtFront(root, 10);
    root = insertAtFront(root, 5);

    printList(root);
    return 0;
}
