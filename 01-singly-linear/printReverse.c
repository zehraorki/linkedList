#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* addhead(node* head, int key) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = key;
    temp->next = head;
    return temp;
}
void printList(node*head) {
    node*iter=head;
    while(iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}

void clear(node**head) {
    node*iter=*head;
    while (iter!=NULL) {
        node*temp=iter;
        iter=iter->next;
        free(temp);
    }
    *head=NULL;
}
void print_reverse(node* head) {
    node* head2=NULL;
    node* temp=head;
    while (temp!=NULL) {
        head2 = addhead(head2, temp->data);
        temp=temp->next;
    }
    printList(head2);
    clear(&head2);
}

int main(void) {
    node* root=NULL;
    root=addhead(root,10);
    root=addhead(root,20);
    root=addhead(root,30);
    root=addhead(root,40);
    root=addhead(root,50);

    printf("Listenin İlk Hali: \n");
    printList(root);

    printf("Listenin Tersi: \n");
    print_reverse(root);

    clear(&root);
    
    return 0;
}
