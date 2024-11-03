#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahkanData(node *head);

//========================================================

int main() {
    node *head;
    char pilih;

    head = NULL;
    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir\n");
        printf("4. Hapus data di awal\n");
        printf("5. Hapus data di tengah\n");
        printf("6. Hapus data di akhir\n");
        printf("7. Cari data\n");
        printf("8. Hitung jumlah data\n");
        printf("9. Jumlahkan seluruh data\n");
        printf("MASUKKAN PILIHAN (tekan p untuk mencetak isi list dan tekan q untuk keluar): ");
        fflush(stdin);
        scanf("%c", &pilih);
        
        if(pilih == '1')
            tambahAwal(&head);
        else if(pilih == '2')
            tambahData(&head);
        else if(pilih == '3')
            tambahAkhir(&head);
        else if(pilih == '4')
            hapusAwal(&head);
        else if(pilih == '5')
            hapusTengah(&head);
        else if(pilih == '6')
            hapusAkhir(&head);
        else if(pilih == '7')
            cariData(head);
        else if(pilih == '8')
            hitungData(head);
        else if(pilih == '9')
            jumlahkanData(head);
        else if(pilih == 'p' || pilih == 'P')
		{
            tranverse(head);
            getch();
		}
        else if(pilih == 'q' || pilih == 'Q')
            printf("Keluar dari program.\n");
        else
		{
            printf("Pilihan tidak valid!\n");
            getch();
		}
    } while (pilih != 'q');
    
    return 0;
}

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew, *pTail;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->next = *head;

        if (*head == NULL) {
            pNew->next = pNew;
        } else {
            pTail = *head;
            while (pTail->next != *head) {
                pTail = pTail->next;
            }
            pTail->next = pNew;
            pNew->next = *head;
        }

        *head = pNew;
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    if (pCur == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *head);

    pNew = (node *)malloc(sizeof(node));

    if (pNew == NULL) {
        printf("\nalokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->next = pCur->next;
        pCur->next = pNew;
    }
}

//========================================================

void tranverse(node *head){
    node *pWalker;

    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    system("cls");
    pWalker = head;
    do {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);
    printf("%d", head->data);
}

//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        pNew->next = *head;

        if (*head == NULL) {
            pNew->next = pNew;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head){
    node *pDel, *pCur;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else if ((*head)->next == *head) {
        pDel = *head;
        *head = NULL;
        free(pDel);
    } else {
        pCur = *head;
        while (pCur->next != *head) {
            pCur = pCur->next;
        }
        pDel = *head;
        *head = (*head)->next;
        pCur->next = *head;
        free(pDel);
    }
    printf("Data di awal telah dihapus.\n");
    getch();
}

//========================================================

void hapusTengah(node **head){
    int bil;
    node *pCur, *pDel;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan nilai yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong!\n");
    } else {
        pCur = *head;
        if (pCur->data == bil) {
            hapusAwal(head);
        } else {
            do {
                if (pCur->next->data == bil) break;
                pCur = pCur->next;
            } while (pCur->next != *head);

            if (pCur->next == *head) {
                printf("Data tidak ditemukan!\n");
            } else {
                pDel = pCur->next;
                pCur->next = pDel->next;
                free(pDel);
                printf("Data di tengah telah dihapus.\n");
            }
        }
    }
    getch();
}

//========================================================

void hapusAkhir(node **head){
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else if ((*head)->next == *head) {
        pDel = *head;
        *head = NULL;
        free(pDel);
        printf("Data di akhir telah dihapus.\n");
    } else {
        pCur = *head;
        while (pCur->next->next != *head) {
            pCur = pCur->next;
        }
        pDel = pCur->next;
        pCur->next = *head;
        free(pDel);
        printf("Data di akhir telah dihapus.\n");
    }
    getch();
}

//========================================================

void cariData(node *head){
    int bil;
    node *pCur = head;
    int found = 0;

    system("cls");
    printf("Masukkan data yang ingin dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    if (pCur == NULL) {
        printf("List kosong!\n");
        getch();
        return;
    }

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di circular linked list!\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->next;
    } while (pCur != head);

    if (!found) {
        printf("Data %d tidak ditemukan di circular linked list.\n", bil);
    }
    getch();
}

//========================================================

void hitungData(node *head){
    int count = 0;
    node *pCur = head;

    if (pCur == NULL) {
        printf("List kosong!\n");
    } else {
        do {
            count++;
            pCur = pCur->next;
        } while (pCur != head);

        printf("Jumlah data di circular linked list: %d\n", count);
    }
    getch();
}

//========================================================

void jumlahkanData(node *head){
    int sum = 0;
    node *pCur = head;

    if (pCur == NULL) {
        printf("List kosong!\n");
    } else {
        do {
            sum += pCur->data;
            pCur = pCur->next;
        } while (pCur != head);

        printf("Jumlah total data di circular linked list: %d\n", sum);
    }
    getch();
}
