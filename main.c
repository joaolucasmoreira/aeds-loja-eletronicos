#include <stdio.h>
#include <string.h>
#include "produto/produto.h"
#include "cliente/cliente.h"

int main(void) {

    printf("\n===== TESTE DE PRODUTOS =====\n\n");

    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;

    Produto produto1 = {
        101,
        "RTX 5060",
        "MSI",
        "Placa de video",
        2499.90f,
        5
    };

    Produto produto2 = {
        201,
        "Ryzen 5500x3d",
        "AMD",
        "Processador",
        1200.00f,
        2
    };

    int resultado = inserirProduto(produtos, &totalProdutos, produto1);
    int resultado2 = inserirProduto(produtos, &totalProdutos, produto2);

    printf("\n===== TESTE DE BUSCADOR PRODUTOS =====\n\n");

    int posicaoTesteProdutos = buscarProduto(produtos, totalProdutos, 101);

    printf("\n--- PRODUTO CADASTRADO ---\n");
    if (posicaoTesteProdutos != -1) {
        printf("Produto encontrado: %s\n", produtos[posicaoTesteProdutos].nome);
        printf("Preco: R$ %.2f\n", produtos[posicaoTesteProdutos].preco);
    } else {
        printf("Produto nao encontrado!\n");
    }

    printf("\n--- PRODUTO NAO CADASTRADO ---\n");
    int posicaoTesteProdutos2 = buscarProduto(produtos, totalProdutos, 102);

    if (posicaoTesteProdutos2 != -1) {
        printf("Produto encontrado: %s\n", produtos[posicaoTesteProdutos2].nome);
        printf("Preco: R$ %.2f\n", produtos[posicaoTesteProdutos2].preco);
    } else {
        printf("Produto nao encontrado!\n");
    }

    printf("\n--- LISTAGEM INICIAL ---\n");

    listarProdutos(produtos, totalProdutos);

    printf("\n--- REMOCAO DO PRIMEIRO PRODUTO ---\n");

    removerProduto(produtos, &totalProdutos, 101);

    listarProdutos(produtos, totalProdutos);

    printf("\n--- REMOCAO DO SEGUNDO PRODUTO ---\n");

    removerProduto(produtos, &totalProdutos, 201);

    listarProdutos(produtos, totalProdutos);

    printf("\n===== TESTE DE CLIENTES =====\n");
    
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    Cliente cliente1 = {
    "12345678900",
    "Joao Lucas",
    "31999998888",
    "joao@email.com",
    "Sao Goncalo - MG"
};

Cliente cliente2 = {
    "98765432100",
    "Maria Silva",
    "31988887777",
    "maria@email.com",
    "Ouro Preto - MG"
};

inserirCliente(clientes, &totalClientes, cliente1);
inserirCliente(clientes, &totalClientes, cliente2);

printf("\n--- LISTAGEM INICIAL ---\n");
listarClientes(clientes, totalClientes);

printf("\n--- BUSCA DE CLIENTE ---\n");

int posicao = buscarCliente(clientes, totalClientes, "98765432100");

if (posicao != -1) {
    printf("Cliente encontrado: %s\n", clientes[posicao].nome);
} else {
    printf("Cliente nao encontrado!\n");
}

printf("\n--- BUSCA INEXISTENTE ---\n");

posicao = buscarCliente(clientes, totalClientes, "11111111111");

if (posicao != -1) {
    printf("Cliente encontrado: %s\n", clientes[posicao].nome);
} else {
    printf("Cliente nao encontrado!\n");
}

printf("\n--- REMOCAO DE CLIENTE ---\n");

removerCliente(clientes, &totalClientes, "12345678900");

printf("\n--- LISTAGEM APOS REMOCAO ---\n");
listarClientes(clientes, totalClientes);

    return 0;
}
//Alteração