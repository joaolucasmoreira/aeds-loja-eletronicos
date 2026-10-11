#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    char cpfCnpj[20];
    char nome[100];
    char telefone[20];
    char email[100];
    char endereco[150];
} Cliente;

int inserirCliente(Cliente clientes[], int *totalClientes, Cliente novo);
int buscarCliente(Cliente clientes[], int totalClientes, char cpfCnpj[]);
void listarClientes(Cliente clientes[], int totalClientes);
int removerCliente(Cliente clientes[], int *totalClientes, char cpfCnpj[]);

#endif


