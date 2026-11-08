#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(PilhaOperacoes *pilha) { pilha->topo = NULL; }
int inserirPilha(PilhaOperacoes *pilha, const char descricao[]) {
    NoPilha *novo = malloc(sizeof(NoPilha));
    if (!novo) { printf("Erro de memoria ao inserir na pilha.\n"); return 0; }
    snprintf(novo->descricao, TAM_OPERACAO, "%s", descricao);
    novo->prox = pilha->topo; pilha->topo = novo;
    printf("Operacao registrada: %s\n", novo->descricao); return 1;
}
int removerPilha(PilhaOperacoes *pilha, char removida[]) {
    if (!pilha->topo) { printf("Historico vazio!\n"); return 0; }
    NoPilha *temp = pilha->topo;
    if (removida) snprintf(removida, TAM_OPERACAO, "%s", temp->descricao);
    pilha->topo = temp->prox;
    printf("Ultima operacao removida: %s\n", temp->descricao);
    free(temp); return 1;
}
NoPilha *buscarPilha(PilhaOperacoes *pilha, const char descricao[]) {
    for (NoPilha *a = pilha->topo; a; a = a->prox) if (strcmp(a->descricao, descricao) == 0) return a;
    return NULL;
}
void listarPilha(PilhaOperacoes *pilha) {
    if (!pilha->topo) { printf("Historico vazio.\n"); return; }
    int i = 1; for (NoPilha *a = pilha->topo; a; a = a->prox) printf("%d - %s\n", i++, a->descricao);
}
void liberarPilha(PilhaOperacoes *pilha) { char texto[TAM_OPERACAO]; while (pilha->topo) removerPilha(pilha, texto); }
