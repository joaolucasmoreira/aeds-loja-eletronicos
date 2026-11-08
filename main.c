#include <stdio.h>
#include "produto/produto.h"
#include "cliente/cliente.h"
#include "fila/fila.h"
#include "pilha/pilha.h"
#include "arvore/arvore.h"

int main(void) {
    Produto produto1 = {101, "RTX 5060", "MSI", "Placa de video", 2499.90f, 5};
    Produto produto2 = {201, "Ryzen 5500x3d", "AMD", "Processador", 1200.00f, 2};
    Produto produto3 = {150, "SSD 1TB", "Kingston", "Armazenamento", 399.90f, 8};
    Cliente cliente1 = {"12345678900", "Joao Lucas", "31999998888", "joao@email.com", "Sao Goncalo - MG"};
    Cliente cliente2 = {"98765432100", "Maria Silva", "31988887777", "maria@email.com", "Ouro Preto - MG"};
    Cliente cliente3 = {"11122233344", "Carlos Souza", "31977776666", "carlos@email.com", "Itabirito - MG"};

    printf("\n========== PARTE 1 - PRODUTOS EM VETOR =========\n");
    Produto produtos[MAX_PRODUTOS]; int totalProdutos = 0;
    inserirProduto(produtos, &totalProdutos, produto1);
    inserirProduto(produtos, &totalProdutos, produto2);
    printf("\nBusca do produto 101: ");
    int pos = buscarProduto(produtos, totalProdutos, 101);
    if (pos >= 0) printf("%s encontrado.\n", produtos[pos].nome); else printf("nao encontrado.\n");
    printf("Listagem dos produtos do vetor:\n"); listarProdutos(produtos, totalProdutos);
    removerProduto(produtos, &totalProdutos, 201);
    printf("Apos remocao:\n"); listarProdutos(produtos, totalProdutos);

    printf("\n========== LISTA ENCADEADA - CLIENTES =========\n");
    ListaClientes clientes; inicializarListaClientes(&clientes);
    inserirCliente(&clientes, cliente1); inserirCliente(&clientes, cliente2); inserirCliente(&clientes, cliente3);
    printf("\nLista de clientes:\n"); listarClientes(clientes);
    NoCliente *encontrado = buscarCliente(clientes, "98765432100");
    printf("Busca por CPF 98765432100: %s\n", encontrado ? encontrado->dados.nome : "nao encontrado");
    removerCliente(&clientes, "12345678900");
    printf("Lista depois da remocao:\n"); listarClientes(clientes);

    printf("\n========== FILA - ATENDIMENTO =========\n");
    FilaClientes fila; inicializarFila(&fila);
    inserirFila(&fila, cliente1); inserirFila(&fila, cliente2); inserirFila(&fila, cliente3);
    printf("Ordem de atendimento (FIFO):\n"); listarFila(&fila);
    printf("Busca na fila pelo CPF 98765432100: %s\n", buscarFila(&fila, "98765432100") ? "cliente encontrado" : "nao encontrado");
    Cliente atendido; removerFila(&fila, &atendido);
    printf("Fila apos atender o primeiro cliente:\n"); listarFila(&fila);

    printf("\n========== PILHA - HISTORICO DE OPERACOES =========\n");
    PilhaOperacoes pilha; inicializarPilha(&pilha);
    inserirPilha(&pilha, "Cadastro do produto RTX 5060");
    inserirPilha(&pilha, "Cadastro do cliente Maria Silva");
    inserirPilha(&pilha, "Remocao do produto Ryzen 5500x3d");
    printf("Historico (LIFO, mais recente primeiro):\n"); listarPilha(&pilha);
    printf("Busca por operacao: %s\n", buscarPilha(&pilha, "Cadastro do cliente Maria Silva") ? "encontrada" : "nao encontrada");
    char operacaoRemovida[TAM_OPERACAO]; removerPilha(&pilha, operacaoRemovida);
    printf("Historico apos remover a ultima operacao:\n"); listarPilha(&pilha);

    printf("\n========== ARVORE BINARIA DE BUSCA - PRODUTOS =========\n");
    ArvoreProdutos arvore; inicializarArvore(&arvore);
    inserirArvore(&arvore, produto1); inserirArvore(&arvore, produto2); inserirArvore(&arvore, produto3);
    printf("Produtos em ordem crescente de codigo:\n"); listarArvore(arvore);
    NoArvore *produtoEncontrado = buscarArvore(arvore, 150);
    printf("Busca pelo codigo 150: %s\n", produtoEncontrado ? produtoEncontrado->produto.nome : "nao encontrado");
    removerArvore(&arvore, 150);
    printf("Arvore apos remocao do codigo 150:\n"); listarArvore(arvore);

    liberarListaClientes(&clientes); liberarFila(&fila); liberarPilha(&pilha); liberarArvore(&arvore);
    printf("\n========== FIM DOS TESTES =========\n");
    return 0;
}
