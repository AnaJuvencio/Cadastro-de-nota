#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAXchar 50

typedef char nomes;
typedef float notas;

typedef struct node{
    struct node *ant;
    struct aluno dados;
    struct node *prox;
}no;

void inicializar_Lista(lista *li){//inicializa
    no *n = (no*) malloc(sizeof(no));
    n->prox = n->ant = li->sentinela = n;
    li->quantidade = 0;
}
void inserirInicio_Lista(lista *li, nomes alunos[MAXchar], notas Nota){
    no *n = (no*) malloc(sizeof(no)); //cria o um novo nó
    strcpy(n->dados.aluno,alunos);
    n->dados.nota = Nota;
    n->prox = li->sentinela->prox;
    n->ant = li->sentinela;
    li->sentinela->prox = n;
    n->prox->ant = n;
    li->quantidade++;
}
void insereFinal_Lista(lista *li, nomes alunos[MAXchar], notas Nota){
    no *n = (no*) malloc(sizeof(no));
    strcpy(n->dados.aluno,alunos);
    n->dados.nota = Nota;
    n->prox = li->sentinela;
    n->ant = li->sentinela;
    li->sentinela->ant->prox = n;
    n->ant = li->sentinela->ant;
    li->sentinela->ant = n;
    li->quantidade++;
}
int removeInicio_Lista(lista *li, nomes result[MAXchar], notas *resultNotas){
    no *n = li->sentinela->prox;
    if(n != li->sentinela){
        if(result != NULL && *resultNotas != -1){
            strcpy(result,n->dados.aluno);//guarda para exibir na main
            *resultNotas = n->dados.nota;//guarda para exibir na main
        }
        n->prox->ant = n->ant;
        n->ant->prox = n->prox;
        free(n);
        li->quantidade--;
        return 1;
    }
    return 0;
}
int removeFinal_Lista(lista *li, nomes result[MAXchar], notas *resultNotas){
    no *n = li->sentinela->ant;
    if(n != li->sentinela){
        if(result != NULL && *resultNotas != -1){
            strcpy(result,n->dados.aluno); //guarda para exibir na main
            *resultNotas = n->dados.nota; //guarda para exibir na main
        }
        n->prox->ant = n->ant;
        n->ant->prox = n->prox;
        free(n);
        li->quantidade--;
        return 1;
    }
    return 0;
}
int listaVazia(lista *li){
    return li->sentinela->prox == li->sentinela;
}

void destruir_Lista(lista *li){
    while(!listaVazia(li))
        removeInicio_Lista(li, NULL, -1);
    free(li->sentinela);
}

//--------------iterador:------------------------------------


iterador ultimo_Lista(lista *li) {
    iterador i;
    i.posicao = li->sentinela->ant;
    i.estrutura = li;
    return i;
}

int proximo_Lista(iterador *i) {
    if(!acabou_Lista(*i) && i != NULL){
        i->posicao = i->posicao->prox;
        return 1;
    }
    return 0;
}

int anterior_Lista(iterador *i) {
    if(!acabou_Lista(*i) && i != NULL){
        i->posicao = i->posicao->ant;
        return 1;
    }
    return 0;
}
iterador primeiro_Lista(lista *li) {
    iterador i;
    i.posicao = li->sentinela->prox;
    i.estrutura = li;
    return i;
}

iterador procuraPrimeiro_Lista(lista *li, nomes aluno[MAXchar]){
    iterador iteradorId = primeiro_Lista(li);
    while((strcmp(iteradorId.posicao->dados.aluno, aluno)) != 0){
            if(acabou_Lista(iteradorId) == 1)
                return iteradorId;//se não encontrar retorna iterador pra o sentinela
            proximo_Lista(&iteradorId);
    }
    return iteradorId; //quando encontrar retorna o iterador para esse elemento
}
void insereDepois_Lista(iterador i, nomes aluno[MAXchar], notas Nota){
    if(!(acabou_Lista(i))){
        no *n = (no*) malloc(sizeof(no));
        strcpy(n->dados.aluno, aluno);
        n->dados.nota = Nota;
        n->prox = i.posicao->prox;
        n->ant = i.posicao;
        i.posicao->prox = n;
        n->prox->ant = n;
        i.estrutura->quantidade++;
    }

}
void removerDepois_Lista(iterador i, nomes result[MAXchar], notas *resultNotas){
    if(!acabou_Lista(i)){
        no *aux = i.posicao->prox;

        if(result != NULL && *resultNotas != -1){
            strcpy(result,aux->dados.aluno); //guarda o resultado para mostrar
            *resultNotas = aux->dados.nota;//guarda o resultado para mostrar
        }
        aux = i.posicao;
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        aux = aux->prox;
        i.estrutura->quantidade--;
        free(aux);
    }
}
int acabou_Lista(iterador i) {
    return i.posicao == i.estrutura->sentinela;
}
//imprimir lista:
void imprime_Lista(lista *li){
    no *n = li->sentinela->prox;
    while(n != li->sentinela){
        printf("Nome: %s  -  ", n->dados.aluno);
        printf("Nota: %.2f\n", n->dados.nota);
        printf("-------------------------------------\n");
        n = n->prox;
    }
}
