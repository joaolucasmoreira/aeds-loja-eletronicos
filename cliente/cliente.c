
#include <stdio.h>
#include <string.h>
#include "cliente.h"

int inserirCliente(Cliente clientes[], int *totalClientes, Cliente novo) {
    if (*totalClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return 0;
    }

    clientes[*totalClientes] = novo;
    (*totalClientes)++;

    printf("Cliente %s cadastrado com sucesso!\n", novo.nome);
    return 1;
}

int buscarCliente(Cliente clientes[], int totalClientes, char cpfCnpj[]) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(clientes[i].cpfCnpj, cpfCnpj) == 0) {
            return i;
        }
    }

    return -1;
}

void listarClientes(Cliente clientes[], int totalClientes) {
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        printf("\n--- Cliente %d ---\n", i + 1);
        printf("CPF/CNPJ: %s\n", clientes[i].cpfCnpj);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Endereco: %s\n", clientes[i].endereco);
    }
}

int removerCliente(Cliente clientes[], int *totalClientes, char cpfCnpj[]) {
    int posicao = buscarCliente(clientes, *totalClientes, cpfCnpj);

    if (posicao == -1) {
        printf("Cliente nao encontrado!\n");
        return 0;
    }

    for (int i = posicao; i < *totalClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    (*totalClientes)--;

    printf("Cliente removido com sucesso!\n");
    return 1;
}
