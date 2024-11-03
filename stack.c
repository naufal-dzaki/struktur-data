#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_CAPACITY 10

struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

typedef struct {
    Node *top;
    int count;
} Stack;

void createStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, int data);
void pop(Stack *stack);
void top(Stack *stack);
void destroyStack(Stack *stack);
void stackCount(Stack *stack);

int main() {
    Stack stack;
    char choice;
    int value;

    createStack(&stack);

    do {
        system("cls");
        printf("Pilih opsi:\n");
        printf("1. Push Stack (Tambah data ke stack)\n");
        printf("2. Pop Stack (Hapus data dari stack)\n");
        printf("3. Stack Top (Tampilkan data teratas)\n");
        printf("4. Empty Stack (Cek apakah stack kosong)\n");
        printf("5. Full Stack (Cek apakah stack Penuh)\n");
        printf("6. Stack Count (Jumlah data dalam stack)\n");
        printf("7. Destroy Stack (Hancurkan stack)\n");
        printf("q. Keluar\n");
        printf("Masukkan pilihan: ");
        fflush(stdin);
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Masukkan data: ");
                scanf("%d", &value);
                push(&stack, value);
                getch();
                break;
            case '2':
                pop(&stack);
                getch();
                break;
            case '3':
                top(&stack);
                getch();
                break;
            case '4':
                printf(isEmpty(&stack) ? "Stack kosong\n" : "Stack tidak kosong\n");
                getch();
                break;
            case '5':
                printf(isFull(&stack) ? "Stack penuh\n" : "Stack tidak penuh\n");
                getch();
                break;
            case '6':
                stackCount(&stack);
                getch();
                break;
            case '7':
                destroyStack(&stack);
                getch();
                break;
            case 'q':
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                getch();
        }
    } while (choice != 'q');

    return 0;
}

void createStack(Stack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

int isFull(Stack *stack) {
    return stack->count == MAX_CAPACITY;
}

void push(Stack *stack, int data) {
	if (isFull(stack)) {
        printf("Stack penuh! Tidak dapat menambahkan data.\n");
	} else {
	    Node *newNode = (Node *)malloc(sizeof(Node));
	    if (newNode != NULL) {
	        newNode->data = data;
	        newNode->next = stack->top;
	        stack->top = newNode;
	        stack->count++;
	    } else {
	        printf("Alokasi memori gagal\n");
	    }
	}
}

void pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa pop!\n");
    }else{
	    Node *temp = stack->top;
	    int dataOut = temp->data;
	    stack->top = stack->top->next;
	    free(temp);
	    stack->count--;
    	
    	printf("Data %d berhasil di pop (hapus) dari stack\n", dataOut);
	}
}

void top(Stack *stack) {
    if (!isEmpty(stack))
    	printf("Data teratas: %d\n", stack->top->data);
	else
    	printf("Stack kosong, tidak ada data teratas!\n");
}

void stackCount(Stack *stack) {
	printf("Jumlah data dalam stack: %d\n", stack->count);
}

void destroyStack(Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    
	printf("Stack telah dihancurkan (destroy)\n");
}
