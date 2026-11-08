#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(FilaClientes *fila) { fila->inicio = NULL; fila->fim = NULL; }
int inserirFila(FilaClientes *fila, Cliente cliente) {
    NoFila *novo = malloc(sizeof(NoFila));
    if (!novo) { printf("Erro de memoria ao inserir na fila.\n"); return 0; }
    novo->cliente = cliente; novo->prox = NULL;
    if (fila->fim == NULL) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
    printf("%s entrou na fila de atendimento.\n", cliente.nome);
    return 1;
}
int removerFila(FilaClientes *fila, Cliente *removido) {
    if (fila->inicio == NULL) { printf("Fila vazia!\n"); return 0; }
    NoFila *temp = fila->inicio;
    if (removido) *removido = temp->cliente;
    fila->inicio = temp->prox;
    if (fila->inicio == NULL) fila->fim = NULL;
    printf("Cliente %s saiu da fila.\n", temp->cliente.nome);
    free(temp); return 1;
}
NoFila *buscarFila(FilaClientes *fila, const char cpfCnpj[]) {
    NoFila *atual = fila->inicio;
    while (atual) { if (strcmp(atual->cliente.cpfCnpj, cpfCnpj) == 0) return atual; atual = atual->prox; }
    return NULL;
}
void listarFila(FilaClientes *fila) {
    if (!fila->inicio) { printf("Fila de atendimento vazia.\n"); return; }
    int pos = 1;
    for (NoFila *a = fila->inicio; a; a = a->prox) printf("%d - %s (CPF/CNPJ: %s)\n", pos++, a->cliente.nome, a->cliente.cpfCnpj);
}
void liberarFila(FilaClientes *fila) { Cliente c; while (fila->inicio) removerFila(fila, &c); }
