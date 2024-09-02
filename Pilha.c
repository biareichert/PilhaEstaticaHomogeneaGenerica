#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha_privado.h"

/*Função Construtora: criar e inicializar a pilha*/
pilha *Init(int tamInfo){
    /*Alocação de memória para a pilha*/
    pilha *p = (pilha*) malloc(sizeof(pilha));

    if(!p){
        printf("\nErro ao criar a pilha!\n");
    }else{ 
        p->topo = -1; //pilha iniciando como vazia
        p->tamInfo = tamInfo; //inicializando o tamanho da informação
    }
    
    /*Retorna a pilha*/
    return p;
}

/*Função Destrutora: destruir a pilha*/
void Destroy(pilha *p){
    int i;

    /*Se a pilha não estiver vazia vamos percorre-la para
    liberar o espaço de memória do vetor*/
    if(IsEmpty(p) != 0){
        for(i = 0; i <= p->topo; i++){
            free(p->vetor[i]);
        }
    }

    free(p);

}

/*Função Manipuladora: empilhar*/
int Push(pilha *p, void *elemento, int tamInfo){
    
    if(IsFull(p) == 0){
        printf("\nA pilha está cheia, não foi possível empilhar!\n");
        return 1;

    }else{
        /*Setando o valor correto para o tamanho da informação que 
        será trabalhada na pilha*/
        p->tamInfo = tamInfo; 
        
        /*Alocando espaço de memória para o novo elemento*/
        p->vetor[p->topo + 1] = (void*) malloc(tamInfo);

        /*Cópia do novo elemento para a sua devida posição na pilha*/
        memcpy(p->vetor[p->topo + 1], elemento, tamInfo);

        /*Incrementando o topo da pilha já que foi adicionado um novo
        elemento*/
        p->topo++;
        
        return 0;
    }

    return 1;
}

/*Função Manipuladora: desempilhar*/
void *Pop(pilha *p){
    void *elemRemovido = NULL;

    if(IsEmpty(p) == 0){
        printf("\nA pilha está vazia, não foi possível desempilhar!\n");

    }else{
        /*Alocando espaço de memória para o elemento no qual será copiado
        o item que será removido da pilha*/
        elemRemovido = malloc(p->tamInfo);

        /*Cópia do elemento removido da pilha para a nova variável*/
        memcpy(elemRemovido, p->vetor[p->topo], p->tamInfo);

        /*Liberando espaço de memória da posição do vetor em que estava o elememto
        que foi removido*/
        free(p->vetor[p->topo]);

        /*Decrementando o topo da pilha já que foi removido um
        elemento*/
        p->topo--;

    }

    /*Retorna a cópia do elemento que foi removido da pilha*/
    return elemRemovido; 
}

/*Função de Acesso: realiza a busca no topo da pilha*/
void *Top(pilha *p){
     void *elemTopo = NULL;

    if(IsEmpty(p) == 0){
        printf("\nA pilha está vazia!\n");
    }else{
        /*Alocando espaço de memória para o elemento no qual será copiado
        o item que está no topo da pilha*/
        elemTopo = malloc(p->tamInfo);

        /*Cópia do elemento do topo da pilha para a nova variável*/
        memcpy(elemTopo, p->vetor[p->topo], p->tamInfo);
        
    }

    /*Retorna a cópia do elemento que está no topo da pilha*/
    return elemTopo; 
}


/*Função para verificar se a pilha está cheia*/
int IsFull(pilha *p){

    if(p->topo == MAXIMO -1){
        /*A pilha está cheia!*/
        return 0;
    }

    /*A pilha não está cheia!*/
    return 1;
}

/*Função para verificar se a pilha está vazia*/
int IsEmpty(pilha *p){

    if(p->topo == -1){
        /*A pilha está vazia!*/
        return 0;
    }

    /*A pilha não está vazia!*/
    return 1;
}

/*Função para verificar o tamanho da pilha*/
int TamPilha(pilha *p){

    if(IsEmpty(p) == 0){
        printf("\nA pilha está vazia!\n");

        return -1;
    }else{
        /*Retorna o tamanho da pilha*/
        return p->topo + 1;
    }

    /*Dado que o tamanho da pilha pode vir a ser 0 ou 1, optamos
    por retornar -1 caso tenha algo errado ou a pilha esteja vazia*/
    return -1;
}


