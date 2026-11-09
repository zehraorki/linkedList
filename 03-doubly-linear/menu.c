#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
    struct node*prev;
}node;

node* insertAtFront(node* head,int value) {
    node* new=(node*)malloc(sizeof(node));
    new->data=value;
    new->prev=NULL;

    if (head==NULL) {
        new->next=NULL;
        return new;
    }
    head->prev=new;
    new->next=head;
    return new;

}
node* insertAtEnd(node* head,int value) {
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

node* insertAfter(node* head,int value,int target) {
    if (head==NULL) {
        return NULL;
    }

    node*iter=head;
    while (iter!=NULL) {
        if (iter->data==target) {
            node* new=(node*)malloc(sizeof(node));
            if (new == NULL) return head;
            new->data=value;
            new->next=iter->next;;
            new->prev=iter;

            if (iter->next != NULL) {
                iter->next->prev = new;
            }
            iter->next=new;
            return head;
        }
        iter=iter->next;
    }
    printf("Hedef (%d) bulunamadi!\n", target);
    return head;

}

node* destroy(node*head) {
    if (head==NULL) {
        return NULL;
    }
    while (head!=NULL) {
        node*temp=head;
        head=head->next;
        free(temp);
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
void printListReverse(node*head) {
    if (head==NULL) {
        return;
    }
    node*iter=head;
    while (iter->next!=NULL) {
        iter=iter->next;
    }  //son dugumde
    while (iter!=NULL) {
        printf("%d -> ",iter->data);
        iter=iter->prev;
    }
    printf("NULL\n");
}


node* removeNode(node* head,int value) {
    if (head==NULL) {
        return NULL;
    }
    if (head->data==value) {
        node*temp=head;
        head=head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    node*iter=head;
    while (iter != NULL && iter->data != value) {
        iter=iter->next;
    }
    if (iter == NULL) {
        printf("Eleman (%d) bulunamadi!\n", value);
        return head;
    }
    iter->prev->next=iter->next;
    if (iter->next!=NULL) {
        iter->next->prev=iter->prev;
    }
    free(iter);
    return head;

}

node* copy(node* head) {
    if (head==NULL) {
        return NULL;
    }
    node* new=NULL;
    node*iter=head;
    while (iter!=NULL) {
        new=insertAtEnd(new,iter->data);
        iter=iter->next;
    }
    return new;

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
    list2->prev=iter;
    return list1;

}
int count(node*head) {
    if (head==NULL) {
        return 0;
    }
    node*iter=head;
    int i=0;
    while (iter!=NULL) {
        i++;
        iter=iter->next;
    }
    return i;

}
node* locate(node*head,int value) {
    if (head==NULL) {
        return NULL;
    }
    node*iter=head;
    while (iter!=NULL) {
        if (iter->data==value) {
            return iter;
        }
        iter=iter->next;
    }
    return NULL;

}

int main(void) {
    int secim, veri,i,n,target;
    node*head=NULL;
    node*liste2=NULL;
    node*kopya=NULL;
    node*aranan=NULL;
    while (1) {
        printf("\n*** Çift Bagli Dogrusal Liste Menusune Hos Geldiniz ***\n");
        printf("1-Listenin Basina Eleman Ekle\n"
               "2-Listenin Sonuna Eleman Ekle\n"
               "3-Listenin Arasına Eleman Ekle\n"
               "4-Listeyi Yazdir\n"
               "5-Listeyi Tersten Yazdir\n"
               "6-Listedeki Eleman Sayisi Hesapla\n"
               "7-Listede Eleman Ara\n"
               "8-Yeni Liste Olustur ve Listeleri Birlestir\n"
               "9-Listenin Kopyasını Olustur ve Yazdir\n"
               "10-Listeden Eleman Sil\n"
               "11-Listeyi Tamamen Sil\n"
               "0-Cikis\n");
        printf("Lutfen secim yapiniz: ");
        scanf("%d",&secim);

        switch (secim) {
            case 1:
                printf("Basa Eklemek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=insertAtFront(head,veri);
                printf("%d Listenin Basina Eklendi!\n",veri);
                break;
            case 2:
                printf("Sona Eklemek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=insertAtEnd(head,veri);
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
                printListReverse(head);
                break;
            case 6:
                printf("Listedeki Eleman Sayisi: %d\n",count(head));
                break;
            case 7:
                printf("Aradiginiz Deger: ");
                scanf("%d",&veri);
                aranan=locate(head,veri);
                if (aranan != NULL) {
                    printf("Dugum Adresi: %p, Veri: %d\n", (void*)aranan, aranan->data);
                }else {
                    printf("Aradiginiz deger bulunamadi!\n");
                }
                break;
            case 8:
                printf("Ikinci listeye kac eleman eklemek istersiniz? ");
                scanf("%d", &n);
                liste2 = NULL;
                for (i = 0; i < n; i++) {
                    printf("%d. eleman: ", i + 1);
                    scanf("%d", &veri);
                    liste2 = insertAtEnd(liste2, veri);
                }
                printf("Ikinci Liste: ");
                printList(liste2);

                head = concatenate(head, liste2);
                liste2 = NULL;
                printf("Birlestirilmis Yeni Liste: ");
                printList(head);
                break;
            case 9:
                printf("Listenizin Kopyasi Olusturuluyor..\n");
                kopya=copy(head);
                printList(kopya);
                destroy(kopya);
                break;
            case 10:
                printf("Silmek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=removeNode(head,veri);
                printf("%d Listeden Silindi!\n",veri);
                break;
            case 11:
                printf("Liste Temizleniyor..\n");
                head=destroy(head);
                printf("Liste Temizlendi!\n");
                break;
            case 0:
                head=destroy(head);
                printf("Cikis Yapiliyor..\n");
                return 0;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
    return 0;
}
