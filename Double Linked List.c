#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tranverse(node *head);
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
        else if(pilih == 'p' || pilih == 'P') {
            tranverse(head);
            getch();
        }
        else if(pilih == 'q' || pilih == 'Q')
            printf("Keluar dari program.\n");
        else {
            printf("Pilihan tidak valid!\n");
            getch();
        }
    } while (pilih != 'q');
    
    return 0;
}

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = bil;
        pNew->left = NULL;
        pNew->right = *head;

        if (*head != NULL) {
            (*head)->left = pNew; 
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

    while (pCur != NULL && pCur->data != pos) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("Data tidak ditemukan!\n");
        getch();
        return;
    }

    pNew = (node *)malloc(sizeof(node));
    if (pNew == NULL) {
        printf("Alokasi memori gagal");
        getch();
    } else {
        pNew->data = bil;
        pNew->left = pCur;
        pNew->right = pCur->right;

        if (pCur->right != NULL) {
            pCur->right->left = pNew;
        }
        pCur->right = pNew;
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
    printf("List contains: \n");
    while (pWalker != NULL) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->right;
    }
    printf("NULL\n");
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
        pNew->right = NULL;

        if (*head == NULL) {
            pNew->left = NULL;
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->right != NULL) {
                pCur = pCur->right;
            }
            pCur->right = pNew;
            pNew->left = pCur;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void hapusAwal(node **head){
    node *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else {
        pDel = *head;
        *head = (*head)->right;

        if (*head != NULL) {
            (*head)->left = NULL;
        }

        free(pDel);
        printf("Data di awal telah dihapus.\n");
    }
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

        while (pCur != NULL && pCur->data != bil) {
            pCur = pCur->right;
        }

        if (pCur == NULL) {
            printf("Data tidak ditemukan!\n");
        } else {
            pDel = pCur;

            if (pDel->left != NULL) {
                pDel->left->right = pDel->right;
            }
            if (pDel->right != NULL) {
                pDel->right->left = pDel->left;
            }

            free(pDel);
            printf("Data di tengah telah dihapus.\n");
        }
    }
    getch();
}

//========================================================

void hapusAkhir(node **head){
    node *pCur, *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else {
        pCur = *head;

        while (pCur->right != NULL) {
            pCur = pCur->right;
        }

        if (pCur->left != NULL) {
            pCur->left->right = NULL;
        } else {
            *head = NULL;
        }

        free(pCur);
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

    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di doubly linked list!\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->right;
    }

    if (!found) {
        printf("Data %d tidak ditemukan di doubly linked list.\n", bil);
    }
    getch();
}

//========================================================

void hitungData(node *head){
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->right;
    }

    printf("Jumlah data di doubly linked list: %d\n", count);
    getch();
}

//========================================================

void jumlahkanData(node *head){
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->right;
    }

    printf("Jumlah total data di doubly linked list: %d\n", sum);
    getch();
}
