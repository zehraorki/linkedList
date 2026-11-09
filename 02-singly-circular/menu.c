#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
}node;

node* insertAtFront(node* head,int value) {
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
node* insertAtEnd(node* head,int value) {
    node* new=(node*)malloc(sizeof(node));
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
    while (iter->next!=head) {
        iter=iter->next;
    }
    iter->next=new;
    new->next=head;

    return head;

}

node* insertAfter(node* head,int value,int target) {
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

void destroy(node**head) {
    if (head == NULL || *head == NULL) return;

    node* current = *head;
    node* iter = *head;
    while (iter->next != *head) {
        iter = iter->next;
    }
    iter->next = NULL;

    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;

}
void printList(node*head) {
    if (head==NULL) {
        printf("Bellek bos!!\n");
        return;
    }
    node*iter=head;

    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head: %d)\n",head->data);

}

node* removeNode(node* head,int value) {
    if (head==NULL) {
        printf("Bellek bos!\n");
        return NULL;
    }
    node*iter=head;
    node*newhead=NULL;

    if (head->data==value && head->next==head) {
        free(head);
        return NULL;
    }
    if (head->data==value) {
        while (iter->next!=head) {
            iter=iter->next;
        }
        newhead=head->next;
        iter->next=newhead;
        free(head);
        return newhead;

    }
    while (iter->next!=head) {
        if (iter->next->data==value) {
            node* temp=iter->next;
            iter->next=iter->next->next;
            free(temp);
            return head;
        }
        iter=iter->next;
    }
    printf("Aradiginiz deger bulunamadi\n");
    return head;

}

node* copy(node* head) {
    if (head==NULL) {
        printf("Liste bos\n");
        return NULL;
    }
    node* newhead=NULL;
    node*iter=head;
    do {
        newhead=insertAtEnd(newhead,iter->data);
        iter=iter->next;
    }while (iter!=head);
    return newhead;

}
node* concatenate(node* list1,node*list2) {
    if (list1==NULL ) {
        return list2;
    }
    if (list2==NULL ) {
        return list1;
    }
    node*iter=list1;
    while (iter->next!=list1) {
        iter=iter->next;
    }
    iter->next=list2;
    node*iter2=list2;
    while (iter2->next!=list2) {
        iter2=iter2->next;
    }
    iter2->next=list1;
    return list1;

}
int count(node*head) {
    if (head==NULL) {
        printf("Liste bos\n");
        return 0;
    }
    node*iter=head;
    int i=1;
    while (iter->next!=head) {
        i++;
        iter=iter->next;
    }
    return i;

}
node* locate(node*head,int value) {
    if (head == NULL) return NULL;
    node* iter = head;
    do {
        if (iter->data == value) return iter;
        iter = iter->next;
    } while (iter != head);
    return NULL;

}

int main(void) {
    int secim, veri,i,n,target;
    node*head=NULL;
    node*liste2=NULL;
    node*kopya=NULL;
    node*aranan=NULL;
    while (1) {
        printf("\n*** Tek Bagli Dairesel Liste Menusune Hos Geldiniz ***\n");
        printf("1-Listenin Basina Eleman Ekle\n"
               "2-Listenin Sonuna Eleman Ekle\n"
               "3-Listenin Arasına Eleman Ekle\n"
               "4-Listeyi Yazdir\n"
               "5-Listedeki Eleman Sayisi Hesapla\n"
               "6-Listede Eleman Ara\n"
               "7-Yeni Liste Olustur ve Listeleri Birlestir\n"
               "8-Listenin Kopyasını Olustur ve Yazdir\n"
               "9-Listeden Eleman Sil\n"
               "10-Listeyi Tamamen Sil\n"
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
                printf("Listedeki Eleman Sayisi: %d\n",count(head));
                break;
            case 6:
                printf("Aradiginiz Deger: ");
                scanf("%d",&veri);
                aranan=locate(head,veri);
                if (aranan != NULL) {
                    printf("Dugum Adresi: %p, Veri: %d\n", (void*)aranan, aranan->data);
                }else {
                    printf("Aradiginiz deger bulunamadi!\n");
                }
                break;
            case 7:
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
            case 8:
                printf("Listenizin Kopyasi Olusturuluyor..\n");
                kopya=copy(head);
                printList(kopya);
                destroy(&kopya);
                break;
            case 9:
                printf("Silmek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=removeNode(head,veri);
                printf("%d Listeden Silindi!\n",veri);
                break;
            case 10:
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
