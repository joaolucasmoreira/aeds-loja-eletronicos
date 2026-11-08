#ifndef ARVORE_H
#define ARVORE_H
#include "../produto/produto.h"

typedef struct NoArvore {
    Produto produto;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;
typedef NoArvore* ArvoreProdutos;

void inicializarArvore(ArvoreProdutos *raiz);
int inserirArvore(ArvoreProdutos *raiz, Produto produto);
NoArvore *buscarArvore(ArvoreProdutos raiz, int codigo);
void listarArvore(ArvoreProdutos raiz);
int removerArvore(ArvoreProdutos *raiz, int codigo);
void liberarArvore(ArvoreProdutos *raiz);
#endif
