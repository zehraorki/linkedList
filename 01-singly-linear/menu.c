#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
}node;

node* addhead(node* head,int value) {
    node * yeni = (node*)malloc(sizeof(node));
    yeni->data=value;
    yeni->next=head;

    return yeni;
}
node* addlast(node* head,int value) {
    node * yeni = (node*)malloc(sizeof(node));
    yeni->data=value;
    yeni->next=NULL;

    if (head==NULL) {
        return yeni;
    }

    node* iter=head;
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


void destroy(node**head) {
    node*iter=*head;
    while (iter!=NULL) {
        node*temp=iter;
        iter=iter->next;
        free(temp);
    }
    *head=NULL;
}
void printList(node*head) {
    node*iter=head;
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }
    printf("NULL\n");
}
void listInfo(node*head) {
    if (head==NULL) {
        printf("Liste bos\n");
        return;
    }
    node*iter=head;
    while (iter!=NULL) {
        printf("Elemanin Degeri: %d\n",iter->data);
        printf("Elemanin Adresi: %p\n",(void*)iter);
        printf("Sonraki Dugumun Adresi: %p\n",(void*)iter->next);
        iter=iter->next;
        printf("*************\n");
    }
}
void printReverse(node*head) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }
    node*iter=head;
    node* newhead=NULL;
    while (iter!=NULL) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->data = iter->data;
        newnode->next = newhead;
        newhead=newnode;
        iter=iter->next;
    }
    printList(newhead);
    destroy(&newhead);

}

node* removeNode(node* head,int value) {
    if (head==NULL) {
        printf("Liste bos\n");
        return NULL;
    }

    if (head->data==value) {
        node*temp2=head;
        head=head->next;
        free(temp2);
        return head;
    }
    node* iter=head;
    while (iter->next != NULL && iter->next->data != value) {
        iter = iter->next;
    }
    if (iter->next == NULL) {
        printf("Aranan deger bulunamadi!\n");
        return head;
    }
    node*temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return head;

}

node* copy(node* head) {
    if (head==NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    node*iter=head;
    node* newhead=NULL;
    node* tail=NULL;

    while (iter!=NULL) {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=iter->data;
        newnode->next=NULL;

        if (newhead==NULL) {
            newhead=newnode;
            tail=newnode;
        }else {
            tail->next=newnode;
            tail=newnode;
        }
        iter=iter->next;
    }
    return newhead;
}
node* concatenate(node* list1,node*list2) {
    if (list1==NULL) {
        return list2;
    }
    if (list2==NULL) {
        return list1;
    }
    node*iter=list1;
    while (iter->next!=NULL) {
        iter=iter->next;
    }
    iter->next=list2;
    return list1;
}
int count(node*head) {
    node*iter=head;
    int i=0;
    while (iter!=NULL) {
        iter=iter->next;
        i++;
    }
    return i;
}
node* locate(node*head,int value) {
    if (head==NULL) {
        printf("Liste bos\n");
        return NULL;
    }
    node*iter=head;
    while (iter!=NULL && iter->data!=value) {
        iter=iter->next;
    }
    if (iter==NULL) {
        return NULL;
    }else {
        return iter;
    }
}

int main(void) {
    int secim, veri,i,n,target;
    node*head=NULL;
    node*liste2=NULL;
    node*kopya=NULL;
    node*aranan=NULL;
    while (1) {
        printf("\n*** Tek Bagli Dogrusal Liste Menusune Hos Geldiniz ***\n");
        printf("1-Listenin Basina Eleman Ekle\n"
               "2-Listenin Sonuna Eleman Ekle\n"
               "3-Listenin Arasına Eleman Ekle\n"
               "4-Listeyi Yazdir\n"
               "5-Listedeki Eleman Bilgilerini Yazdir\n"
               "6-Listeyi Tersten Yazdir\n"
               "7-Listedeki Eleman Sayisi Hesapla\n"
               "8-Listede Eleman Ara\n"
               "9-Yeni Liste Olustur ve Listeleri Birlestir\n"
               "10-Listenin Kopyasını Olustur ve Yazdir\n"
               "11-Listeden Eleman Sil\n"
               "12-Listeyi Tamamen Sil\n"
               "0-Cikis\n");
        printf("Lutfen secim yapiniz: ");
        scanf("%d",&secim);

        switch (secim) {
            case 1:
                printf("Basa Eklemek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=addhead(head,veri);
                printf("%d Listenin Basina Eklendi!\n",veri);
                break;
            case 2:
                printf("Sona Eklemek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=addlast(head,veri);
                printf("%d Listenin Sonuna Eklendi!\n",veri);
                break;
            case 3:
                printf("Hangi Elemandan Sonra Eklenecek:");
                scanf("%d",&target);
                printf("Araya Eklemek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=insertAfter(head,veri,target);
                printf("%d Listenin Arasına Eklendi!\n",veri);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                listInfo(head);
                break;
            case 6:
                printf("Listenizin Tersi: \n");
                printReverse(head);
                break;
            case 7:
                printf("Listedeki Eleman Sayisi: %d\n",count(head));
                break;
            case 8:
                printf("Aradiginiz Deger: ");
                scanf("%d",&veri);
                aranan=locate(head,veri);
                if (aranan != NULL) {
                    printf("Dugum Adresi: %p, Veri: %d\n", (void*)aranan, aranan->data);
                }else {
                    printf("Aradiginiz deger bulunamadi!\n");
                }
                break;
            case 9:
                printf("Ikinci listeye kac eleman eklemek istersiniz? ");
                scanf("%d", &n);
                liste2 = NULL;
                for (i = 0; i < n; i++) {
                    printf("%d. eleman: ", i + 1);
                    scanf("%d", &veri);
                    liste2 = addlast(liste2, veri);
                }
                printf("Ikinci Liste: ");
                printList(liste2);

                head = concatenate(head, liste2);
                liste2 = NULL;
                printf("Birlestirilmis Yeni Liste: ");
                printList(head);
                break;
            case 10:
                printf("Listenizin Kopyasi Olusturuluyor..\n");
                kopya=copy(head);
                printList(kopya);
                destroy(&kopya);
                break;
            case 11:
                printf("Silmek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=removeNode(head,veri);
                printf("%d Listeden Silindi!\n",veri);
                break;
            case 12:
                printf("Liste Temizleniyor..\n");
                destroy(&head);
                printf("Liste Temizlendi!\n");
                break;
            case 0:
                destroy(&head);
                printf("Cikis Yapiliyor..\n");
                return 0;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
    return 0;
}
