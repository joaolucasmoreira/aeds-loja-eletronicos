#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    char cpfCnpj[20];
    char nome[100];
    char telefone[20];
    char email[100];
    char endereco[150];
} Cliente;

typedef struct NoCliente {
    Cliente dados;
    struct NoCliente *prox;
} NoCliente;

typedef NoCliente* ListaClientes;

void inicializarListaClientes(ListaClientes *lista);
int inserirCliente(ListaClientes *lista, Cliente novo);
NoCliente *buscarCliente(ListaClientes lista, const char cpfCnpj[]);
void listarClientes(ListaClientes lista);
int removerCliente(ListaClientes *lista, const char cpfCnpj[]);
void liberarListaClientes(ListaClientes *lista);

#endif
