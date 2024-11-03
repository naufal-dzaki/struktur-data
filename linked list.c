#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
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
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
}

//========================================================

void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   	system("cls");
	pWalker = head;
	while (pWalker != NULL){
   		printf("%d\t", pWalker -> data);
   		pWalker = pWalker -> next;
      	printf(" -> ");
	}
   printf("NULL");
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
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
        pNew->next = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->next != NULL) {
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
    node *pDel;

    if (*head == NULL) {
        printf("List kosong!\n");
    } else {
        pDel = *head;
        *head = (*head)->next;
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
        if (pCur->data == bil) {
            hapusAwal(head);
        } else {
            while (pCur->next != NULL && pCur->next->data != bil) {
                pCur = pCur->next;
            }
            if (pCur->next == NULL) {
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
	    } else if ((*head)->next == NULL) {
	        pDel = *head;
	        *head = NULL;
	        free(pDel);
	        printf("Data di akhir telah dihapus.\n");
	    } else {
	        pCur = *head;
	        while (pCur->next->next != NULL) {
	            pCur = pCur->next;
	        }
	        pDel = pCur->next;
	        pCur->next = NULL;
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

    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Data %d ditemukan di linked list!\n", bil);
            found = 1;
            break;
        }
        pCur = pCur->next;
    }

    if (!found) {
        printf("Data %d tidak ditemukan di linked list.\n", bil);
    }
    getch();
}

//========================================================

void hitungData(node *head){
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }

    printf("Jumlah data di linked list: %d\n", count);
    getch();
}

//========================================================

void jumlahkanData(node *head){
    int sum = 0;
    node *pCur = head;

    while (pCur != NULL) {
        sum += pCur->data;
        pCur = pCur->next;
    }

    printf("Jumlah total data di linked list: %d\n", sum);
    getch();
}
