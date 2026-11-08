#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

void inicializarListaClientes(ListaClientes *lista) {
    *lista = NULL;
}

int inserirCliente(ListaClientes *lista, Cliente novo) {
    NoCliente *atual = *lista;
    while (atual != NULL) {
        if (strcmp(atual->dados.cpfCnpj, novo.cpfCnpj) == 0) {
            printf("Ja existe cliente com esse CPF/CNPJ!\n");
            return 0;
        }
        atual = atual->prox;
    }

    NoCliente *novoNo = (NoCliente *) malloc(sizeof(NoCliente));
    if (novoNo == NULL) {
        printf("Erro: memoria insuficiente para cadastrar cliente.\n");
        return 0;
    }
    novoNo->dados = novo;
    novoNo->prox = NULL;

    if (*lista == NULL) {
        *lista = novoNo;
    } else {
        atual = *lista;
        while (atual->prox != NULL) atual = atual->prox;
        atual->prox = novoNo;
    }
    printf("Cliente %s cadastrado na lista com sucesso!\n", novo.nome);
    return 1;
}

NoCliente *buscarCliente(ListaClientes lista, const char cpfCnpj[]) {
    while (lista != NULL) {
        if (strcmp(lista->dados.cpfCnpj, cpfCnpj) == 0) return lista;
        lista = lista->prox;
    }
    return NULL;
}

void listarClientes(ListaClientes lista) {
    if (lista == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    int i = 1;
    while (lista != NULL) {
        printf("\n--- Cliente %d ---\n", i++);
        printf("CPF/CNPJ: %s\nNome: %s\nTelefone: %s\nE-mail: %s\nEndereco: %s\n",
               lista->dados.cpfCnpj, lista->dados.nome, lista->dados.telefone,
               lista->dados.email, lista->dados.endereco);
        lista = lista->prox;
    }
}

int removerCliente(ListaClientes *lista, const char cpfCnpj[]) {
    NoCliente *atual = *lista, *anterior = NULL;
    while (atual != NULL && strcmp(atual->dados.cpfCnpj, cpfCnpj) != 0) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Cliente nao encontrado na lista!\n");
        return 0;
    }
    if (anterior == NULL) *lista = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    printf("Cliente removido da lista com sucesso!\n");
    return 1;
}

void liberarListaClientes(ListaClientes *lista) {
    NoCliente *atual = *lista;
    while (atual != NULL) {
        NoCliente *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *lista = NULL;
}
