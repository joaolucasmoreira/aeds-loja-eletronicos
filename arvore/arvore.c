#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void inicializarArvore(ArvoreProdutos *raiz) { *raiz = NULL; }
int inserirArvore(ArvoreProdutos *raiz, Produto produto) {
    if (*raiz == NULL) {
        NoArvore *novo = malloc(sizeof(NoArvore));
        if (!novo) { printf("Erro de memoria ao inserir na arvore.\n"); return 0; }
        novo->produto = produto; novo->esquerda = NULL; novo->direita = NULL; *raiz = novo;
        printf("Produto %s inserido na arvore.\n", produto.nome); return 1;
    }
    if (produto.codigo == (*raiz)->produto.codigo) { printf("Ja existe produto com esse codigo na arvore!\n"); return 0; }
    if (produto.codigo < (*raiz)->produto.codigo) return inserirArvore(&(*raiz)->esquerda, produto);
    return inserirArvore(&(*raiz)->direita, produto);
}
NoArvore *buscarArvore(ArvoreProdutos raiz, int codigo) {
    while (raiz) { if (codigo == raiz->produto.codigo) return raiz; raiz = codigo < raiz->produto.codigo ? raiz->esquerda : raiz->direita; }
    return NULL;
}
void listarArvore(ArvoreProdutos raiz) {
    if (!raiz) return;
    listarArvore(raiz->esquerda);
    printf("Codigo: %d | Nome: %s | Marca: %s | Preco: R$ %.2f | Estoque: %d\n", raiz->produto.codigo, raiz->produto.nome, raiz->produto.marca, raiz->produto.preco, raiz->produto.quantidade);
    listarArvore(raiz->direita);
}
int removerArvore(ArvoreProdutos *raiz, int codigo) {
    if (*raiz == NULL) return 0;
    if (codigo < (*raiz)->produto.codigo) return removerArvore(&(*raiz)->esquerda, codigo);
    if (codigo > (*raiz)->produto.codigo) return removerArvore(&(*raiz)->direita, codigo);
    NoArvore *temp = *raiz;
    if (!temp->esquerda) *raiz = temp->direita;
    else if (!temp->direita) *raiz = temp->esquerda;
    else {
        NoArvore *sucessor = temp->direita;
        while (sucessor->esquerda) sucessor = sucessor->esquerda;
        temp->produto = sucessor->produto;
        return removerArvore(&temp->direita, sucessor->produto.codigo);
    }
    free(temp); printf("Produto de codigo %d removido da arvore.\n", codigo); return 1;
}
void liberarArvore(ArvoreProdutos *raiz) {
    if (!*raiz) return;
    liberarArvore(&(*raiz)->esquerda); liberarArvore(&(*raiz)->direita); free(*raiz); *raiz = NULL;
}
