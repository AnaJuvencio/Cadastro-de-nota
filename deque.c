#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#define MAXchar 50

struct Deque{
    int inicio, fim, qtd, elementosT; //elementosT é o tamanho do deque
    struct dados alunos[100];
};

Deque *inicializa_Deque(int totalElementos){
    Deque *dq;
    dq = (Deque*) malloc(sizeof(struct Deque));
    dq -> inicio = 0;
    dq -> fim = 0;
    dq -> qtd = 0;
    dq -> elementosT = totalElementos; //total de elementos guardado na estrutura
    return dq;
}
void liberaVetor_Deque(Deque *dq){
    free(dq);
}

int dequeCheio(Deque *dq){
    if (dq->qtd == dq->elementosT)
        return 1;//cheio
    else
        return 0;
}
void insereInicio_Deque(Deque *dq, float valor, char nome[MAXchar]){
    if(dequeCheio(dq) == 0){ //verifica se está cheio
        dq->inicio--;
        if(dq->inicio < 0)
            dq->inicio = dq->elementosT-1;
        strcpy(dq->alunos[dq->inicio].nomes, nome);
        dq->alunos[dq->inicio].numInserir = valor;
        dq->qtd++;
    }
}
void insereFinal_Deque(Deque *dq, float valor, char nome[MAXchar]){
    if(dequeCheio(dq) == 0){ //verifica se está cheio
        strcpy(dq->alunos[dq->fim].nomes, nome);
        dq->alunos[dq->fim].numInserir = valor;
        dq->fim = (dq->fim+1)%dq->elementosT;
        dq->qtd++;
    }
}
int dequeVazio(Deque *dq){
    if (dq->qtd == 0)
        return 1;//vazio
    else
        return 0;
}
float removeInicio_Deque(Deque *dq, char resultNome[MAXchar]){
    if(dequeVazio(dq) == 0){ //verifica se está vazio
        float guardarvalor = dq->alunos[dq->inicio].numInserir;
        strcpy(resultNome, dq->alunos[dq->inicio].nomes);
        dq->inicio = (dq->inicio+1)%dq->elementosT;
        dq->qtd--;
        return guardarvalor;
    }
    else{
        return 0;
    }
}
float removeFinal_Deque(Deque *dq, char resultNome[MAXchar]){
    if(dequeVazio(dq) == 0){ //verifica se está vazio
        dq->fim--;
        if(dq->fim < 0)
            dq->fim = dq->elementosT-1;
        strcpy(resultNome, dq->alunos[dq->fim].nomes);
        dq->qtd--;
        return dq->alunos[dq->fim].numInserir;
    }else{
        return 0;
    }
}
void esvaziar(Deque *dq){
    dq -> inicio = 0;
    dq -> fim = 0;
    dq -> qtd = 0;
}
void imprime_Deque(Deque *dq){
    int j, x = dq->inicio;
    for(j=0; j < dq->qtd; j++){
        printf("Nome: %s  -  ", dq->alunos[x].nomes);
        printf("Nota: %.2f\n", dq->alunos[x].numInserir);
        printf("-------------------------------\n");
        x = (x + 1) % dq->elementosT;
    }
}
