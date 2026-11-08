#ifndef PILHA_H
#define PILHA_H
#define TAM_OPERACAO 150

typedef struct NoPilha {
    char descricao[TAM_OPERACAO];
    struct NoPilha *prox;
} NoPilha;
typedef struct { NoPilha *topo; } PilhaOperacoes;

void inicializarPilha(PilhaOperacoes *pilha);
int inserirPilha(PilhaOperacoes *pilha, const char descricao[]);
int removerPilha(PilhaOperacoes *pilha, char removida[]);
NoPilha *buscarPilha(PilhaOperacoes *pilha, const char descricao[]);
void listarPilha(PilhaOperacoes *pilha);
void liberarPilha(PilhaOperacoes *pilha);
#endif
