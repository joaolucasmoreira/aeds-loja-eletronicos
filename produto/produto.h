#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[100];
    char marca[50];
    char categoria[50];
    float preco;
    int quantidade;
} Produto;

int inserirProduto(Produto produtos[], int *totalProdutos, Produto novo);
int buscarProduto(Produto produtos[], int totalProdutos, int codigo);
void listarProdutos(Produto produtos[], int totalProdutos);
int removerProduto(Produto produtos[], int *totalProdutos, int codigo);

#endif

