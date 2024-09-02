#ifndef APLICACAO_H
#define APLICACAO_H

#include "Pilha_publico.h"

/*Struct para o aluno, caso o usuário deseje empilhar esse
tipo de dado*/
typedef struct{
    char nome[20];
    char curso[50];
    int idade;
} aluno;

/*Funções que a aplicação tem acesso direto e não
interferem no TDA da pilha*/
void ImprimirItem(void *elemento, int tipo, int opcao);
int VerificarInsercao(int tipo, int opcao);
int Menu(pilha *p, int opcao, int tipo, int tamInfo);

#endif