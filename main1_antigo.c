#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    int cap;
    int inicio;
    int fim;
    int tam;
} FCirc;

void init_Fila(FCirc *f, int cap) {
    f->data = (int *)malloc(cap * sizeof(int));
    f->cap = cap;
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}

void add(FCirc *f, int valor) {
    if (f->tam == f->cap) {
        f->data[f->fim] = valor;
        f->fim = (f->fim + 1) % f->cap;
        f->inicio = (f->inicio + 1) % f->cap; 
    } else {
        f->data[f->fim] = valor;
        f->fim = (f->fim + 1) % f->cap;
        f->tam++;
    }
    
}

int remove(FCirc *f) {
    if (f->tam == 0) {
        printf("fila vazia\n");
        return 0;
    }
    printf("%d\n", f->data[f->inicio]);
    f->inicio = (f->inicio + 1) % f->cap;
    f->tam--;
} // CONFERIR 

void increase(FCirc *f, int k) { // FAZER

}

int listar(FCirc *f) { // FAZER

}

void print(FCirc *f) { // FAZER

}

void end(FCirc *f) { // RODAR
    free(FCir->data);
    free(FCirc);
    break;
}

int main() {
    scanf("%s", comando);



    return 0;
}

int main() {

    free(pila.data);
    return 0;
}
