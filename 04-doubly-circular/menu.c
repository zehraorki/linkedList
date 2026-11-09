#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node*next;
    struct node*prev;
}node;

node* insertAtFront(node* head,int value) {
    node*new=(node*)malloc(sizeof(node));
    new->data=value;
    if (head==NULL) {
        new->next=new;
        new->prev=new;
        return new;
    }
    node*tail=head->prev;
    new->next=head;
    new->prev=tail;
    head->prev=new;
    tail->next=new;
    return new;

}
node* insertAtEnd(node* head,int value) {
    node*new=(node*)malloc(sizeof(node));
    new->data=value;
    if (head==NULL) {
        new->next=new;
        new->prev=new;
        return new;
    }
    node*tail=head->prev;
    new->next=head;
    new->prev=tail;
    head->prev=new;
    tail->next=new;
    return head;

}

node* insertAfter(node* head, int value, int target) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return NULL;
    }
    node* iter = head;
    do {
        if (iter->data == target) {
            node* new = (node*)malloc(sizeof(node));
            if (new == NULL) return head;

            new->data = value;
            new->next = iter->next;
            new->prev = iter;
            iter->next->prev = new;
            iter->next = new;
            return head;
        }
        iter = iter->next;
    } while (iter != head);

    printf("Hedef (%d) bulunamadi!\n", target);
    return head;
}

node* destroy(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return NULL;
    }
    node*tail=head->prev;
    tail->next=NULL;
    while (head!=NULL) {
        node*temp=head;
        head=head->next;
        free(temp);
    }
    return NULL;

}
void printList(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    node*iter=head;
    do {
        printf("%d -> ",iter->data);
        iter=iter->next;
    }while (iter!=head);
    printf("(head: %d)\n",head->data);


}
void printListReverse(node*head) {
    if (head==NULL) {
        printf("NULL\n");
        return;
    }
    node*iter=head->prev;
    do {
        printf("%d -> ",iter->data);
        iter=iter->prev;
    }while (iter!=head->prev);
    printf("(head: %d)\n",head->prev->data);

}

node* removeNode(node* head,int value) {
    if (head==NULL) {
        return NULL;
    }

    if (head->next==head && head->data==value) {
        free(head);
        return NULL;
    }
    if (head->data==value) {
        node*temp=head;
        node*tail=head->prev;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
        return head;
    }
    node*iter=head;
    do {
        if (iter->data==value) {
            iter->prev->next=iter->next;
            iter->next->prev=iter->prev;
            free(iter);
            return head;
        }
        iter=iter->next;
    }while (iter!=head);
    printf("Silmek istediginiz deger bulunamadi\n");
    return head;


}

node* copy(node* head) {
    if (head==NULL) {
        return NULL;
    }
    node* new=NULL;
    node*iter=head;
    do {
        new=insertAtEnd(new,iter->data);
        iter=iter->next;
    }while (iter!=head);
    return new;
}
node* concatenate(node* list1,node*list2) {
    if (list1==NULL) {
        return list2;
    }
    if (list2==NULL) {
        return list1;
    }
    node*tail=list1->prev;
    node*tail2=list2->prev;
    tail->next=list2;
    list2->prev=tail;
    tail2->next=list1;
    list1->prev=tail2;
    return list1;


}
int count(node*head) {
    if (head == NULL) {
        return 0;
    }
    node*iter=head;
    int i=0;
    do {
        i++;
        iter=iter->next;
    }while (iter!=head);
    return i;
}


int main(void) {
    int secim, veri,i,n,target;
    node*head=NULL;
    node*liste2=NULL;
    node*kopya=NULL;
    node*aranan=NULL;
    while (1) {
        printf("\n*** Çift Bagli Dairesel Liste Menusune Hos Geldiniz ***\n");
        printf("1-Listenin Basina Eleman Ekle\n"
               "2-Listenin Sonuna Eleman Ekle\n"
               "3-Listenin Arasına Eleman Ekle\n"
               "4-Listeyi Yazdir\n"
               "5-Listeyi Tersten Yazdir\n"
               "6-Listedeki Eleman Sayisi Hesapla\n"
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
                printListReverse(head);
                break;
            case 6:
                printf("Listedeki Eleman Sayisi: %d\n",count(head));
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
                kopya=destroy(kopya);
                break;
            case 9:
                printf("Silmek İstediginiz Deger: ");
                scanf("%d",&veri);
                head=removeNode(head,veri);
                printf("%d Listeden Silindi!\n",veri);
                break;
            case 10:
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
