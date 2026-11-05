#ifndef Celula_h
#define Celula_h
#include "cliente.h"

typedef struct
{
    Cliente x;
    struct Tcelula* pProx;
}Tcelula;

typedef struct 
{
    Tcelula* pPrimeiro;
    Tcelula* pUltimo;
}Tlista;


#endif