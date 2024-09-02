#ifndef PILHA_PUBLICO_H
#define PILHA_PUBLICO_H

/*Chamada da struct da pilha*/
typedef struct pilha pilha;

/*Funções da pilha, aqui tem-se acesso a manipulação da pilha*/
pilha *Init(int tamInfo); //Função construtora
void Destroy(pilha *p); //Função destrutora
void *Top(pilha *p); //Função de acesso
void *Pop(pilha *p); //Função manipuladora
int Push(pilha *p, void *elemento, int tamInfo); //Função manipuladora
int IsFull(pilha *p); //Função de acesso
int IsEmpty(pilha *p); //Função de acesso
int TamPilha(pilha *p); //Função de acesso

#endif
