#include <stdio.h>
#include "produto.h"

int inserirProduto(Produto produtos[], int *totalProdutos, Produto novo) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Estoque de cadastros cheio!\n");
        return 0;
    }

    produtos[*totalProdutos] = novo;
    (*totalProdutos)++;

    printf("Produto %s cadastrado com sucesso!\n", produtos[*totalProdutos - 1].nome);
    return 1;
}

int buscarProduto(Produto produtos[], int totalProdutos, int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void listarProdutos(Produto produtos[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalProdutos; i++) {
        printf("\n--- Produto %d ---\n", i + 1);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Marca: %s\n", produtos[i].marca);
        printf("Categoria: %s\n", produtos[i].categoria);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }
}

int removerProduto(Produto produtos[], int *totalProdutos, int codigo) {
    int posicao = buscarProduto(produtos, *totalProdutos, codigo);

    if (posicao == -1) {
        printf("Produto nao encontrado!\n");
        return 0;
    }

    for (int i = posicao; i < *totalProdutos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }

    (*totalProdutos)--;

    printf("Produto removido com sucesso!\n");
    return 1;
}