#ifndef FILA_H
#define FILA_H
#include "../cliente/cliente.h"

typedef struct NoFila {
    Cliente cliente;
    struct NoFila *prox;
} NoFila;
typedef struct {
    NoFila *inicio;
    NoFila *fim;
} FilaClientes;

void inicializarFila(FilaClientes *fila);
int inserirFila(FilaClientes *fila, Cliente cliente);
int removerFila(FilaClientes *fila, Cliente *removido);
NoFila *buscarFila(FilaClientes *fila, const char cpfCnpj[]);
void listarFila(FilaClientes *fila);
void liberarFila(FilaClientes *fila);
#endif
