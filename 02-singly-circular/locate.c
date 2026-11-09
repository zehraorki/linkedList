#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
}node;

node* locate(node*head,int value) {
    if (head==NULL) {
        printf("Liste bos\n");
        return NULL;
    }
    node*iter=head;
    while (iter->next!=head) {
        if (iter->data==value) {
            return iter;
        }
        iter=iter->next;
    }
    if (iter->data == value) {
        return iter;
    }
    return NULL;


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

    node*result=locate(root,50);
    if (result==NULL) {
        printf("Aradiginiz deger bulunamadi\n");
    }else {
        printf("Elemanin Adresi: %p\n",(void*)result);

    }
    return 0;
}
