# AEDS I - Loja de Eletrônicos

Projeto em C desenvolvido para as atividades avaliativas da disciplina.

## Estruturas implementadas
- **Vetor:** cadastro de produtos (implementação da Parte 1 mantida).
- **Lista encadeada:** cadastro de clientes, com inserção, busca, listagem e remoção.
- **Fila:** clientes aguardando atendimento (FIFO).
- **Pilha:** histórico de operações da loja (LIFO).
- **Árvore binária de busca:** catálogo de produtos organizado pelo código. A listagem em ordem central apresenta os códigos em ordem crescente.

Todas as estruturas da Parte 2 possuem operações de inserir, remover, buscar e listar.

## Compilação (GCC)
Na pasta raiz do projeto, execute:

```bash
gcc main.c produto/produto.c cliente/cliente.c fila/fila.c pilha/pilha.c arvore/arvore.c -o main.exe
```

No PowerShell, execute:

```powershell
.\main.exe
```
