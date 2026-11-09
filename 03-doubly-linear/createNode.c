#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

int main(){
    node* root=(node*)malloc(sizeof(node));
    root->data=40;
    root->prev=NULL;
    root->next=NULL;
    printf("Veri: %d\n",root->data);
    printf("Verinin Adresi: %p\n",(void*)root);
    printf("Sonraki Dugumun Adresi: %p\n",(void*)root->next);
    printf("Onceki Dugumun Adresi: %p\n",(void*)root->prev);

    return 0;
}
