#ifndef PILHA_PRIVADO_H
#define PILHA_PRIVADO_H

#include "Pilha_publico.h"

/*Tamanho máximo da pilha*/
#define MAXIMO 100

/*Struct da pilha*/
typedef struct pilha{
    int topo; /*armazena o índice da posição do vetor em que foi 
    inserido o último elemento. A pilha inicia na posição 0. -1 significa
    que a pilha está vazia*/
    void *vetor[MAXIMO]; /*vetor de dados genéricos*/
    int tamInfo; /*tamanho da informação que será armazenada na pilha*/
} pilha;

#endif