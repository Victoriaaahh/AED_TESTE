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
    
}

void increase(FCirc *f, int k) {

}

int listar(FCirc *f) {

}

void print(FCirc *f) {

}

void end() {
    break;
}

int main() {

    free(pila.data);
    return 0;
}
