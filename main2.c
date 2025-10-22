#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int topo;
    int capacidade;
} Pilha;

void init(Pilha *pilha, int cap) {
    pilha->data = malloc(cap * sizeof(char));
    pilha->capacidade = cap;
    pilha->topo = -1;
}

void add(Pilha *pilha, char c) {
    if (pilha->topo >= pilha->capacidade - 1) {
        pilha->capacidade += 5;
        pilha->data = realloc(pilha->data, pilha->capacidade * sizeof(char));
    }
    pilha->data[++pilha->topo] = c;
}

void invert(Pilha *pilha) {
    for (int i = 0; i <= pilha->topo / 2; i++) {
        char temp = pilha->data[i];
        pilha->data[i] = pilha->data[pilha->topo - i];
        pilha->data[pilha->topo - i] = temp;
    }
}

void substituir(Pilha *pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        if (pilha->data[i] == '}') pilha->data[i] = '{';
        else if (pilha->data[i] == ')') pilha->data[i] = '(';
        else if (pilha->data[i] == ']') pilha->data[i] = '[';
    }
}

int comparar(Pilha *p, Pilha *b) {
    if (p->topo != b->topo) return 0;
    for (int i = 0; i <= p->topo; i++) {
        if (p->data[i] != b->data[i]) return 0;
    }
    return 1;
}

int main() {
    char c;
    Pilha pilha1;
    Pilha pilha2;
    init(&pilha1, 20);
    init(&pilha2, 20);

    while (1) {
        // Lê um caractere e ignora ENTERs extras
        if (scanf(" %c", &c) != 1) continue;

        if (c == '!') break; // sai do loop

        // ignora caracteres que não são (), {}, []
        if (c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}')
            continue;

        // adiciona nas pilhas conforme o tipo
        if (c == '(' || c == '[' || c == '{')
            add(&pilha1, c);
        else if (c == ')' || c == ']' || c == '}')
            add(&pilha2, c);
    }

    invert(&pilha2);
    substituir(&pilha2);

    if (comparar(&pilha1, &pilha2))
        printf("bem formada\n");
    else
        printf("mal formada\n");

    free(pilha1.data);
    free(pilha2.data);
    return 0;
}
