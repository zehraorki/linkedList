#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

int main(void) {
    node* root=(node*)malloc(sizeof(node));
    root->data=10;
    root->next=(node*)malloc(sizeof(node));
    root->next->data=20;
    root->next->next=NULL;

    free(root);
    free(root->next);
    return 0;
}
