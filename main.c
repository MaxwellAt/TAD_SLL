#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SLL.h"

typedef struct {
    char nome[30];
    int vitorias;
    float pontuacao;
} Time;

void listarTimes(SLList *lista){
    int ind = 0;
    Time *var = (Time*) sllGetFirstCur(lista);
    if(var != NULL){
        do{
            printf("Time %d: \n",ind + 1);
            printf("Nome: %s ,Vitorias: %d ,Pontuacao: %.2f \n", var->nome, var->vitorias, var->pontuacao);
            var = (Time*)sllGetNext(lista);
            ind++;
        }while(var != NULL);
    }else{
        printf("----------Lista vazia--------\n");
    }
}

int cmp(void* a, void* b){
    Time *pa = (Time *) a;
    Time *pb = (Time*) b;
    if(pa != NULL && pb != NULL){
        if(strcmp(pa->nome,pb->nome) == 0 && pa->vitorias == pb->vitorias && pa->pontuacao == pb->pontuacao){
            return TRUE;
        }
        return FALSE;
    }
    return -1;
}

int listaClean(SLList* lista){
    if(lista != NULL){
        while(sllRemoveLast(lista) != NULL);
        return TRUE;
    }
    return FALSE;
}

int main(){
    SLList *lista = NULL;

    do{
        printf("1 - Criar lista \n");
        printf("2 - Inserir um time \n");
        printf("3 - Remover um time \n");
        printf("4 - Consultar um time \n");
        printf("5 - Listar os times \n");
        printf("6 - Destruir a lista \n");
        printf("7 - Esvaziar a lista \n");
        printf("0 - Sair \n");
        printf("Deseja realizar qual operacao? \n ");

        int opcao;
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                if(lista!= NULL){
                    printf("Lista já criada\n");
                    printf("Primeiro destrua a lista anterior\n");
                    printf("\n");
                    break;
                }
                lista = sllCreate();
                if(lista != NULL){
                    printf("Lista criada com sucesso!\n");
                    printf("\n");
                }else{
                    printf("Não foi possível criar a lista. Tente novamente. \n");
                    printf("\n");
                }
                break;
            }
            case 2:{
                Time *time = (Time *) malloc(sizeof(Time));
                if(lista != NULL && time != NULL){
                    printf("Nome: ");
                    scanf("%s", time->nome);
                    printf("Vitorias: ");
                    scanf("%d", &time->vitorias);
                    printf("Pontuacao: ");
                    scanf("%f", &time->pontuacao);
                    if(sllInsertAsLast(lista, time) == TRUE){
                        printf("Time inserido com sucesso\n");
                        printf("\n");
                    }else{
                        printf("Erro ao inserir time\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 3:{
                Time *time = (Time *) malloc(sizeof(Time));
                if(lista != NULL && time != NULL){
                    printf("Nome: ");
                    scanf("%s", time->nome);
                    printf("Vitorias: ");
                    scanf("%d", &time->vitorias);
                    printf("Pontuacao: ");
                    scanf("%f", &time->pontuacao);
                    if(sllRemoveSpec(lista, time, cmp) != NULL){
                        printf("Time removido com sucesso! \n");
                        printf("\n");
                    }else{
                        printf("Time não encontrado\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 4:{
                Time *time = (Time*) malloc(sizeof(Time));
                if(lista != NULL && time != NULL){
                    printf("Nome: ");
                    scanf("%s", time->nome);
                    printf("Vitorias: ");
                    scanf("%d", &time->vitorias);
                    printf("Pontuacao: ");
                    scanf("%f", &time->pontuacao);

                    Time *chave = (Time*) sllQuerySpec(lista, time, cmp);
                    if(chave != NULL){
                        printf("Time encontrado ! \n");
                        printf("Nome: %s, Vitorias: %d, Pontuacao: %.2f \n", chave->nome, chave->vitorias, chave->pontuacao);
                        printf("\n");
                    }else{
                        printf("Time não encontrado \n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 5:{
                if(lista != NULL){
                    printf("Aqui estão os times da lista: \n");
                    listarTimes(lista);
                    printf("\n");
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 6:{
                if(lista != NULL){
                    if(sllDestroy(lista) == TRUE){
                        printf("Lista destruída\n");
                        printf("\n");
                        lista = NULL;
                    }else{
                        printf("Lista não destruída\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 7:{
                if(lista != NULL){
                    if(listaClean(lista) == TRUE){
                        printf("Lista esvaziada\n");
                        printf("\n");
                    }else{
                        printf("Lista não esvaziada\n");
                        printf("\n");
                    }
                }else{
                    printf("Lista não criada\n");
                    printf("\n");
                }
                break;
            }
            case 0:{
                printf("Sistema encerrado com sucesso! \n");
                return 0;
            }
            default:{
                printf("Opção inválida \n");
                printf("\n");
                break;
            }
        }
    }while(TRUE);

}