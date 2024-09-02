#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacao.h"

/*Essa função tem como objetivo apresentar para o usuário o elemento do topo da pilha
(de acordo com o seu tipo), o qual foi retornado pela função Top(). E/OU retornar o 
elemento que foi desempilhado, o qual foi retornado pela função Pop().*/
void ImprimirItem(void *elemento, int tipo, int opcao){

    char msg[100];
    char mat[20]; /*Variável de auxílio para strings*/

    /*Definindo a mensagem que será apresentada para o usuário*/
    if(opcao == 6){
        strcpy(msg, "\nO elemento removido foi:");
    }else{
        strcpy(msg, "\nO elemento do topo é:");
    }

    switch (tipo){
        case 1:
            /*O elemento é uma struct, retorna apenas o nome*/
            printf("%s %s\n", msg, ((aluno *)elemento)->nome);    

            break;
        case 2:
            /*O elemento é um float*/
            printf("%s %.2f\n", msg, *(float *)elemento);
            
            break;
        case 3:
            /*O elemento é um caracter*/
            printf("%s %c\n", msg, *(int *) elemento);
            
            break;
        case 4:
            /*O elemento é um inteiro*/
            printf("%s %d\n", msg, *(int *) elemento);
            
            break;
        case 5:
            /*O elemento é uma string*/
            strcpy(mat, elemento);
            printf("%s %s\n", msg, mat);
            
            break;
        default:
            break;
    }
}

/*Dado que uma pilha só pode ter elementos de um determinado tipo, esta função
verifica se, ao selecionar uma opção de empilhar, o usuário selecionou o mesmo
tipo do elemento inicial*/    
int VerificarInsercao(int tipo, int opcao){
    if(opcao == 1 && tipo == 1){
        return 1; /*struct*/
    }else{
        if(opcao == 2 && tipo == 2){
            return 2; /*float*/
        }else{
            if(opcao == 3 && tipo == 3){
                return 3; /*char*/
            }else{
                if(opcao == 4 && tipo == 4){
                    return 4; /*int*/
                }else{
                    if(opcao == 5 && tipo == 5){
                         return 5; /*string*/
                    }else{
                        /*Se o usuário tentar colocar um tipo diferente do
                        primeiro colocado na pilha (i.e., opcao != tipo) ele vai 
                        cair na opção inválida (default) do menu*/
                        printf("\nVocê está tentando empilhar um tipo diferente do inicial.\n");
                        return 14;
                    }
                }
            }
        }
    }

    return 0;
}

/*Função de menu, aqui são implementadas as opções apresentadas
para o usuário na função main*/
int Menu(pilha *p, int opcao, int tipo, int tamInfo){
    /*Variáveis de entrada, serão inicializadas pelo usuário*/
    float notaFloat;
    char materia[20];
    char notaChar;
    int notaInt;
    void *elemento;
    aluno a;

    int retorno;
    
    switch (opcao){
        case 0:
            /*Caso 0: Sair*/
            printf("\n\n#########################\n");
            printf("\nEncerrando o programa!\n");
            printf("\n#########################\n");

            break;

        case 1:
            /*Caso 1: Inserir struct*/
            printf("\nInforme o nome do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (a.nome, 20, stdin);
            
            printf("\nInforme a idade do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%d", &a.idade);
            
            printf("\nInforme o curso do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (a.curso, 50, stdin);
            
            /*Definindo o tamanho da informação*/
            tamInfo = sizeof(a); 

            /*Empilhando*/
            retorno = Push(p, &a, tamInfo);

            if(retorno == 0){
                printf("\nAluno inserido com sucesso!\n");
            }else{
                printf("\nErro ao inserir o aluno!\n");
            }

            break;

        case 2:
            /*Caso 2: Inserir float*/
            printf("\nInforme a nota do aluno (float):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%f", &notaFloat);

            /*Defininfo o tamanho da informação*/
            tamInfo = sizeof(notaFloat);

            /*Empilhando*/
            retorno = Push(p, &notaFloat, tamInfo);
            
            if(retorno == 0){
                printf("\nNota inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a nota!\n");
            }

            break;

        case 3:
            /*Caso 3: Inserir char*/
            printf("\nInforme o conceito do aluno (char):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%c", &notaChar);

            /*Definindo tamanho da informação*/
            tamInfo = sizeof(notaChar);

            /*Empilhando*/
            retorno = Push(p, &notaChar, tamInfo);

            if(retorno == 0){
                printf("\nConceito inserido com sucesso!\n");
            }else{
                printf("\nErro ao inserir o conceito!\n");
            }

            break;

        case 4:
            /*Caso 4: Inserir int*/
            printf("\nInforme a nota do aluno (int):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%d", &notaInt);

            /*Definindo tamanho da informação*/
            tamInfo = sizeof(notaInt);

            /*Empilhando*/
            retorno = Push(p, &notaInt, tamInfo);

            if(retorno == 0){
                printf("\nNota inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a nota!\n");
            }

            break;

        case 5:
            /*Caso 5: Inserir string*/
            printf("\nInforme a matéria (string):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (materia, 20, stdin);

            /*Definindo tamanho da informação*/
            tamInfo = sizeof(materia);
            
            /*Empilhando*/
            retorno = Push(p, &materia, tamInfo);

            if(retorno == 0){
                printf("\nMatéria inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a matéria!\n");
            }

            break;

        case 6:
            /*Caso 6: Desempilhar*/
            elemento = Pop(p);

            /*Se o elemento retornado pela função Pop() for igual a 
            NULL significa que a pilha estava vazia */
            if(elemento != NULL){
                /*Se o elemento for diferente de NULL então imprime o
                elemento removido em tela*/
                ImprimirItem(elemento, tipo, opcao);
            }

            /*Dado que na função Pop foi alocado espaço de memória para esse
            elemento, aqui estamos liberando esse espaço*/
            free(elemento);

            break;

        case 7:
            /*Caso 7: Imprimir elemento do topo*/

            /*Busca no topo*/
            elemento = Top(p);

            /*Se o elemento retornado pela função Top() for igual a 
            NULL significa que a pilha estava vazia */
            if (elemento != NULL){
                /*Se o elemento for diferente de NULL então imprime o elemento
                do topo em tela*/
                ImprimirItem(elemento, tipo, opcao);
            }
            
            /*Dado que na função Top foi alocado espaço de memória para esse
            elemento, aqui estamos liberando esse espaço*/
            free(elemento);

            break;

        case 8:
            /*Caso 8: Verificar pilha cheia*/
            retorno = IsFull(p);

            if(retorno == 0){
                printf("\nA pilha está cheia!\n");
            }else{
                printf("\nA pilha não está cheia!\n");
            }

            break;
        
        case 9:
            /*Caso 9: Verificar pilha vazia*/
            retorno = IsEmpty(p);

            if(retorno == 0){
                printf("\nA pilha está vazia!\n");
            }else{
                printf("\nA pilha não está vazia!\n");
            }

            break;

        case 10:
            /*Caso 10: Ver tamanho da pilha*/
            retorno = TamPilha(p);

            /*-1 significa que a pilha está vazia*/
            if(retorno != -1){
                printf("\nO tamanho da pilha é %d\n", retorno);
            }

            break;
    
        default:
            printf("\nOpção inválida!\n");

            break;
    }

    /*Retorna o tamanho da informação que foi inserida na pilha*/
    return tamInfo; 
}

int main (void) {
    /*Inicializando a pilha e as demais variáveis*/
    int opcao = -1;
    int tipo = 0;
    int tamInfo = 0;
    pilha *p = Init(tamInfo);

    /*Enquanto o usuário não digita 0 para encerrar a aplicação, a mesma fica no
    loop apresentando o menu*/
    while(opcao != 0){
        printf("\n\n############ ATENÇÃO!! ############\n");
        printf("É permitido empilhar somente dados do mesmo tipo!\n");
        
        printf("\n\n############ MENU ############\n");
        printf("Escolha uma opção:\n");

        printf("0.  Sair\n");
        printf("1.  Inserir aluno (empilhar struct)\n");
        printf("2.  Inserir nota do aluno (empilhar float)\n");
        printf("3.  Inserir conceito do aluno (empilhar caracter)\n");
        printf("4.  Inserir nota do aluno (empilhar int)\n");
        printf("5.  Inserir matéria (empilhar string)\n");
        printf("6.  Desempilhar\n");
        printf("7.  Ver elemento do topo\n");
        printf("8.  Verificar se a pilha está cheia\n");
        printf("9.  Verificar se a pilha está vazia\n");
        printf("10. Ver o tamanho da pilha\n\n");
    
        scanf("%d", &opcao);

        /*Se tipo == 0 significa que ainda não foi inserido nenhum elemento na pilha.
        Então o tipo da pilha será correspondente a opção selecionada no menu.*/
        if(tipo == 0 && (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5)){
            tipo = opcao;
            
        }else{
            /*Senão significa que já foi inserido algo na pilha, então não é permitido adicionar
            um tipo diferente. Ou seja, isso vale apenas para as opções que envolvem o empilhamento*/
            if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5){
                /*Verifica se a opção selecionada corresponde ao tipo dos elementos da pilha*/
                opcao = VerificarInsercao(tipo, opcao); 
            }
        }

        /*Chamada da função Menu*/
        tamInfo = Menu(p, opcao, tipo, tamInfo);

    }

    /*Ao encerrar a aplicação a pilha será destruída*/
    Destroy(p); 

    return 0;
}
