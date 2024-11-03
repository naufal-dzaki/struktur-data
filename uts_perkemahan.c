#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct node {
    char nama[50];
    char gender;
    struct node *left;
    struct node *right;
};
typedef struct node node;

int count = 0;

void tambahAkhir(node **head, char *nama, char gender);
void tranverse(node *head);
void hapusMahasiswa(node **head, char *nama);
void tambahKembar(node **head, char *nama1, char *nama2);
void pisahkanLingkaran(node *head, node **mahasiswaHead, node **mahasiswiHead);
int isFull();

int main() {
    node *head = NULL;
    node *mahasiswaHead = NULL, *mahasiswiHead = NULL;
    char pilih;
    char nama[50];
    char gender;

    do {
        system("cls");
        printf("Masukkan pilihan:\n");
        printf("1. Tambah mahasiswa ke lingkaran\n");
        printf("2. Hapus mahasiswa dari lingkaran\n");
        printf("3. Pisahkan lingkaran mahasiswa dan mahasiswi\n");
        printf("4. Lihat semua mahasiswa dalam lingkaran\n");
	    printf("MASUKKAN PILIHAN (tekan q untuk keluar): ");
	    fflush(stdin);
	    scanf(" %c", &pilih);
        
        if (pilih == '1') {
            printf("Masukkan nama mahasiswa: ");
            fflush(stdin);
            gets(nama);
            printf("Jenis kelamin (L/P): ");
            fflush(stdin);
            scanf(" %c", &gender);

            if (strcmp(nama, "Irsyad") == 0 || strcmp(nama, "irsyad") == 0 || strcmp(nama, "Arsyad") == 0 || strcmp(nama, "arsyad") == 0) {
                char namaKembar[50];
                printf("Masukkan nama saudara kembar: ");
                fflush(stdin);
                gets(namaKembar);
                tambahKembar(&head, nama, namaKembar);
            } else {
                tambahAkhir(&head, nama, gender);
            }
        } 
        else if (pilih == '2') {
            printf("Masukkan nama mahasiswa yang ingin dihapus: ");
            fflush(stdin);
            gets(nama);
            hapusMahasiswa(&head, nama);
        } 
        else if (pilih == '3') {
            pisahkanLingkaran(head, &mahasiswaHead, &mahasiswiHead);
            printf("Lingkaran sudah dipisahkan berdasarkan gender.\n");
            printf("Lingkaran Mahasiswa:\n");
            tranverse(mahasiswaHead);
            printf("Lingkaran Mahasiswi:\n");
            tranverse(mahasiswiHead);
            system("pause");
        }
        else if (pilih == '4') {
            tranverse(head);
            system("pause");
        } 
        else if (pilih != 'q') {
            printf("Pilihan tidak valid!\n");
            system("pause");
        }
    } while (pilih != 'q');
    
    return 0;
}

void tambahAkhir(node **head, char *nama, char gender) {
    if (isFull()) {
        printf("Lingkaran sudah penuh (maksimal 20 orang)!\n");
        system("pause");
        return;
    }

    node *pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        strcpy(pNew->nama, nama);
        pNew->gender = gender;

        if (*head == NULL) {
            *head = pNew;
            pNew->left = pNew;
            pNew->right = pNew;
        } else {
            node *pCur = (*head)->left;
            node *oldLeftNeighbor = pCur;

            if (strcmp(nama, "Cindy") == 0 || strcmp(nama, "cindy") == 0) {
                node *leftNeighbor = pCur;
                node *rightNeighbor = *head;

                if (leftNeighbor->gender == 'L' || rightNeighbor->gender == 'L') {
                    printf("Cindy tidak bisa ditambahkan, karena ada laki-laki di sebelahnya!\n");
                    free(pNew);
                    system("pause");
                    return;
                }
            }

            pCur->right = pNew;
            pNew->left = pCur;
            pNew->right = *head;
            (*head)->left = pNew;
            
			if(oldLeftNeighbor->nama == "Cindy" && (gender == "L" || gender == "l")){
             	printf("Cindy keluar dari lingkaran karena bersebelahan dengan laki-laki/n!");
            	hapusMahasiswa(head, "Cindy");
			}else if(oldLeftNeighbor->nama == "cindy" && (gender == "L" || gender == "l")){
            	printf("cindy keluar dari lingkaran karena bersebelahan dengan laki-laki/n!");
            	hapusMahasiswa(head, "cindy");
			}
        }

        count++;
        printf("%s berhasil ditambahkan ke lingkaran.\n", nama);
    } else {
        printf("Alokasi memori gagal!\n");
    }
    system("pause");
}

void tranverse(node *head) {
    if (head == NULL) {
        printf("Lingkaran kosong!\n");
        return;
    }

    node *pWalker = head;
    printf("Mahasiswa dalam lingkaran:\n");

    do {
        printf("%s (%c) -> ", pWalker->nama, pWalker->gender);
        pWalker = pWalker->right;
    } while (pWalker != head);

    printf("%s (%c)", head->nama, head->gender);
}

void hapusMahasiswa(node **head, char *nama) {
    if (*head == NULL) {
        printf("Lingkaran kosong!\n");
        system("pause");
        return;
    }

    node *pCur = *head;

    do {
        if (strcmp(pCur->nama, nama) == 0) {
            if (pCur->right == pCur) {
                *head = NULL;
            } else {
                pCur->left->right = pCur->right;
                pCur->right->left = pCur->left;

                if (pCur == *head) {
                    *head = pCur->right;
                }
            }

            free(pCur);
            count--;
            printf("Mahasiswa %s telah dihapus dari lingkaran.\n", nama);
            system("pause");
            return;
        }
        pCur = pCur->right;
    } while (pCur != *head);

    printf("Mahasiswa %s tidak ditemukan dalam lingkaran!\n");
    system("pause");
}

void tambahKembar(node **head, char *nama1, char *nama2) {
    if (isFull()) {
        printf("Lingkaran sudah penuh (maksimal 20 orang)!\n");
        system("pause");
        return;
    }

    tambahAkhir(head, nama1, 'L');
    tambahAkhir(head, nama2, 'L');
}

void pisahkanLingkaran(node *head, node **mahasiswaHead, node **mahasiswiHead) {
    if (head == NULL) {
        printf("Lingkaran kosong, tidak ada yang dipisahkan.\n");
        return;
    }

    node *pCur = head;

    do {
        if (pCur->gender == 'L' || pCur->gender == 'l') {
            tambahAkhir(mahasiswaHead, pCur->nama, pCur->gender);
        } else {
            tambahAkhir(mahasiswiHead, pCur->nama, pCur->gender);
        }
        pCur = pCur->right;
    } while (pCur != head); 
}

int isFull() {
    return count >= MAX;
}
