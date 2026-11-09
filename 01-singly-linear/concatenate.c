#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node * concatenate(node*list1,node*list2) {
    node*iter1=list1;
    node*iter2=list2;

    if (iter1==NULL) {
        return iter2;
    }
    while (iter1->next!=NULL) {
        iter1=iter1->next;
    }
    iter1->next=iter2;
    return list1;

}

void printlist(node* head) {
    node* iter= head;
    while (iter!=NULL) {
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

int main(void) {
    node* n1 = (node*)malloc(sizeof(node));
    node* n2 = (node*)malloc(sizeof(node));
    node* n3 = (node*)malloc(sizeof(node));
    node* n4 = (node*)malloc(sizeof(node));
    node* n5 = (node*)malloc(sizeof(node));
    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = n5;
    n5->data = 50; n5->next = NULL;

    node* first =n1;

    node* s1 = (node*)malloc(sizeof(node));
    node* s2 = (node*)malloc(sizeof(node));
    node* s3 = (node*)malloc(sizeof(node));
    node* s4 = (node*)malloc(sizeof(node));
    node* s5 = (node*)malloc(sizeof(node));
    s1->data = 100; s1->next = s2;
    s2->data = 200; s2->next = s3;
    s3->data = 300; s3->next = s4;
    s4->data = 400; s4->next = s5;
    s5->data = 500; s5->next = NULL;

    node* second=s1;

    node* root =concatenate(first,second);
    printlist(root);

    clear(&root);

    return 0;
}
