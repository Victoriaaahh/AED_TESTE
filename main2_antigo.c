#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    char *data;
    int topo;
    int capacidade;
} Pilha;
 
void init(Pilha *pilha, int cap) {
    pilha->data = (char *)malloc(cap* sizeof(char));
    pilha->capacidade = cap;
    pilha->topo = -1;
}
 
void add(Pilha *pilha, char *c) {
    if (pilha->topo > pilha->capacidade) {
        pilha->capacidade += 5;
        pilha->data = (char *)realloc(pilha->data, pilha->capacidade* sizeof(char));
    }
    pilha->data[++pilha->topo] = *c;
}
  
void invert(Pilha *pilha) {
    Pilha *p;
    p->topo = 0;
    p->data = (char *)malloc(pilha->capacidade* sizeof(char));
    for (int i = 0; i < (pilha->topo) /2; i++) {
        pilha->data[i] = pilha->data[pilha->capacidade - i];
    }
}
 
void substituir(Pilha *pilha) {
    for (int i = 0; i < pilha->topo; i++) {
        if (pilha->data[i] == '}') {
            pilha->data[i] = '{';
        }
        if (pilha->data[i] == ')') {
            pilha->data[i] = '(';
        }
        if (pilha->data[i] == ']') {
            pilha->data[i] = '[';
        }
    }
}
 
int comparar(Pilha *p, Pilha *b) {
    for(int i = 0; i < p->topo; i++) {
        if (p->data[i] == b->data[i]) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
 
 
int main() {
    char num[100];
    char x[100];
    char letra = '\0';
    Pilha *pilha1;
    Pilha *pilha2;
    init(pilha1, 20);
    init(pilha2, 20);
 
    while (letra != '!') {
        fgets(num, sizeof(num), stdin);
        for (int i = 0; i < 100; i++) {
            letra = num[i];
        }
    }
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        if (num[i] == '\n') {
            num[i] = '\0';
        }
    }
    if (num[0] == ']' || num[0] == '}' || num[0] == ')') {
        printf("mal formada\n");
        return 0;
    }
    if (num[len] == '(' || num[len] == '[' || num[len] == '{') {
        printf("mal formada\n");
        return 0;
    }
    for (int j = 0; j < len; j++) {
        x[j] = num[j];
        if (x[j] == '(' || x[j] == '[' || x[j] == '{') {
            letra = x[j];
            add(pilha1, &letra);
        }
        else if (x[j] == ')' || x[j] == ']' || x[j] == '}') {
            letra = x[j];
            add(pilha2, &letra);
        }
    }
    invert(pilha2);
    substituir(pilha2);
    if (comparar(pilha1, pilha2) == 1) {
        printf("bem formada\n");
    }
    else {
        printf("mal formada\n");
    }
 
    free(pilha1);
    free(pilha2);
    return 0;
}