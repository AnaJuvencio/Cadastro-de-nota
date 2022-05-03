/*
    Esse projeto foi desenvolvido para realizar um cadastro de notas de alunos,
    o usu�rio poder� inserir o t�tulo da prova, quantos alunos ele pretende inserir
    no momento, o nome do aluno e sua nota correspondente. Essas informa��es ser�o
    guardadas na estrutura Lista.
    Nesse trabalho, incluimos uma lixeira, que montamos com a estrutura Deque. Sendo assim,
    al�m de inserir informa��es, o cliente tamb�m poder� excluir seus dados temporariamente,
    podendo recuperar, ou permanentemente, de acordo com sua escolha.
    Criamos v�rias opera��es que podem ser realizadas, quais s�o elas e suas fun��es est�o
    explicadas no c�digo.
    O idioma foi adaptado para o Portugu�s. Essa informa��o � importante para inser��o dos dados.
    Modelo de nota(exemplo): 9,5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lista.h"
#include "deque.h"
#define MAXchar 50

int main()
{
    setlocale(LC_ALL, "Portuguese"); //define o idioma
    printf("-------------------------PROJETO: CADASTRO DE NOTAS------------------\n");
    printf("------------%s--------------\n\n", copyright);//autores do c�digo

    //vari�veis utilizadas na estrutura Lista:
    char opcoes[10], nomes[MAXchar], resultIni[MAXchar], resultFim[MAXchar], inserir_Depois[MAXchar], remover_Depois[MAXchar], titulo_Prova[MAXchar];
    iterador result_Procura_Primeiro,  ultimoEle;
    float notaAluno = 0, resultNota = 0;

    //vari�veis utilizadas na estrutura Deque:
    int elementosT = 0;
    float resultIniNotas, resultFinalNotas;// T = total
    char guardaNome[MAXchar];

    //inicializa a lista:
    lista li; inicializar_Lista(&li);


    //Corpo do c�digo:
    printf("DIGITE O T�TULO DA PROVA:\n");
    scanf(" %[^\n]", titulo_Prova);
    printf("DIGITE QUANTOS ALUNOS PRETENDE INSERIR:\n");
    scanf("%d", &elementosT); //tamanho do deque

    //inicializa o deque
    Deque *dq = inicializa_Deque(elementosT);

    do{
        printf("DIGITE A OPERA��O QUE DESEJA FAZER:\n");
        scanf("%s", opcoes);

        if((strcmp("sair", opcoes)) == 0){
            break;
        }
        else if((strcmp("inserirI", opcoes)) == 0){ //inserir no inicio da lista
            printf("DIGITE O NOME DO ALUNO:\n");
            scanf(" %[^\n]", nomes);
            printf("DIGITE A NOTA DESSE ALUNO:\n");
            scanf("%f", &notaAluno);
            inserirInicio_Lista(&li, nomes, notaAluno);

        }
        else if((strcmp("inserirF", opcoes)) == 0){ //inserir no final da lista
            printf("DIGITE O NOME DO ALUNO:\n");
            scanf(" %[^\n]", nomes);
            printf("DIGITE A NOTA DESSE ALUNO:\n");
            scanf("%f", &notaAluno);
            insereFinal_Lista(&li, nomes, notaAluno);
        }
        else if((strcmp("inserirD", opcoes)) == 0){ //inserir Depois de algu�m (utilizar o nome como refer�ncia)
            if(listaVazia(&li) == 1){
                printf("N�o tem aluno na lista para inserir depois dele.\n");
            }else{
                printf("DESEJA INSERIR DEPOIS DE QUAL ALUNO?\n");
                scanf(" %[^\n]", inserir_Depois);

                result_Procura_Primeiro = procuraPrimeiro_Lista(&li, inserir_Depois);//procurar o aluno digitado pelo usu�rio na lista
                if(result_Procura_Primeiro.posicao == result_Procura_Primeiro.estrutura->sentinela){
                    printf("ERRO: O nome que usou como refer�ncia, n�o est� na lista\n"); //impress�o fora da biblioteca
                }else{
                    printf("DIGITE O NOME DO ALUNO QUE DESEJA INSERIR NA LISTA:\n");
                    scanf(" %[^\n]", nomes);
                    printf("DIGITE A NOTA DESSE ALUNO:\n");
                    scanf("%f", &notaAluno);
                    //insere na lista:
                    insereDepois_Lista(result_Procura_Primeiro, nomes, notaAluno);
                }
            }

        }
        else if((strcmp("removerD", opcoes)) == 0){ //remover depois de algu�m (utilizar o nome como refer�ncia)
            if(listaVazia(&li) == 1){ //verifica se est� vazia de novo para imprimir
                printf("A Lista j� est� vazia.\n");
            }else{
                printf("DESEJA REMOVER DEPOIS DE QUAL ALUNO?\n");
                scanf(" %[^\n]", remover_Depois);

                result_Procura_Primeiro = procuraPrimeiro_Lista(&li, remover_Depois); //procura o nome que o usu�rio informou
                ultimoEle = ultimo_Lista(&li);//ve o �ltimo elemento da lista

                if(result_Procura_Primeiro.posicao == result_Procura_Primeiro.estrutura->sentinela){//verifica se o nome est� na lista
                    printf("ERRO: O nome que usou como refer�ncia, n�o est� na lista.\n"); //impress�o fora da biblioteca
                }else if(ultimoEle.posicao == result_Procura_Primeiro.posicao){//verifica se � �ltimo elemento da lista para exibir a mensagem
                    printf("N�o tem mais alunos depois desse nome.\n");
                }else{//inserir na lixeira(deque)
                    if(dequeCheio(dq) == 1){
                        printf("ERRO: A lixeira est� cheia! Remova alguns itens ou esvazie a lixeira!\n");
                    }else{
                        removerDepois_Lista(result_Procura_Primeiro, resultIni, &resultNota);//manda a posi��o do nome que o usu�rio digitou para inserir depois dele
                        printf("Voc� removeu: Nome: %s   Nota: %.2f\n", resultIni, resultNota); //mostra o item removido
                        //insere na lixeira(deque):
                        insereInicio_Deque(dq, resultNota, resultIni);
                    }
                }
            }
        }
        else if((strcmp("removerI", opcoes)) == 0){ //remover do inicio da lista e inserir na lixeira(deque)
            if(listaVazia(&li) == 1){
                printf("A Lista j� est� vazia.\n");
            }else{
                if(dequeCheio(dq) == 1){//n�o remove se a lixeira estiver cheia
                    printf("ERRO: A lixeira est� cheia! Remova alguns itens ou esvazie a lixeira!\n");
                }else{
                    if(removeInicio_Lista(&li, resultIni, &resultNota) == 1){
                        printf("Voc� removeu: Nome: %s   Nota: %.2f\n", resultIni, resultNota);
                    }
                    //insere na lixeira:
                    insereInicio_Deque(dq, resultNota, resultIni);
                }
            }
        }
        else if((strcmp("removerF", opcoes)) == 0){//remover do final da lista e inserir na lixeira(deque)
            if(listaVazia(&li) == 1){
                 printf("A Lista j� est� vazia.\n");
            }else{
                if(dequeCheio(dq) == 1){
                    printf("ERRO: A lixeira est� cheia! Remova alguns itens ou esvazie a lixeira!\n");
                }else{
                    if(removeFinal_Lista(&li, resultFim, &resultNota) == 1){
                        printf("Voc� removeu: Nome: %s   Nota: %.2f\n", resultFim, resultNota);
                    }
                    //insere na lixeira:
                    insereInicio_Deque(dq, resultNota, resultFim);
                }

            }
        }
        else if((strcmp("listar", opcoes)) == 0){//mostrar Lista
            system("cls"); //limpar tela
            if(listaVazia(&li) == 1){
                printf("A lista est� vazia.\n");
            }else{
                printf("%s:\n", titulo_Prova);
                imprime_Lista(&li);
            }
        }
        else if((strcmp("lixeira", opcoes)) == 0){ //mostrar os itens na Lixeira
            system("cls"); //limpar tela
            if(dequeVazio(dq) == 1){
                printf("A lixeira est� vazia.\n");
            }else{
                printf("LIXEIRA:\n");
                imprime_Deque(dq);
            }
        }
        //opera��es com a lixeira:
        else if((strcmp("recuperarI", opcoes)) == 0){ //recuperar o inicio da lixeira (devolver o item para a lista)
             if(dequeVazio(dq) == 1){
                printf("A lixeira j� est� vazia.\n");
            }else{
                resultIniNotas = removeInicio_Deque(dq, guardaNome);
                printf("Voc� recuperou: Nome: %s   Nota: %.2f\n", guardaNome, resultIniNotas);
                //inserir na lista:
                insereFinal_Lista(&li, guardaNome, resultIniNotas);
            }
        }
        else if((strcmp("recuperarF", opcoes)) == 0){//recuperar o final da lixeira
             if(dequeVazio(dq) == 1){
                 printf("A lixeira j� est� vazia.\n");
            }else{
                resultFinalNotas = removeFinal_Deque(dq, guardaNome);
                printf("Voc� recuperou: Nome: %s   Nota: %.2f\n", guardaNome, resultFinalNotas);
                //inserir na lista:
                insereFinal_Lista(&li, guardaNome, resultFinalNotas);
            }
        }
        else if((strcmp("esvaziar", opcoes)) == 0){ //apaga tudo permanentemente da lixeira
            if(dequeVazio(dq) == 1){
                printf("A lixeira j� est� vazia.\n");
            }else{
                esvaziar(dq);
                printf("Voc� esvaziou a lixeira.\n");
            }
        }
        else if((strcmp("removeLixoI", opcoes)) == 0){ //remove o inicio da lixeira(deque), permanentemente
            if(dequeVazio(dq) == 1){
                printf("A lixeira j� est� vazia.\n");
            }else{
                resultIniNotas = removeInicio_Deque(dq, guardaNome);
                printf("Voc� removeu permanentemente: Nome: %s   Nota: %.2f\n", guardaNome, resultIniNotas);
            }
        }
        else if((strcmp("removeLixoF", opcoes)) == 0){//remove o final da lixeira(deque), permanentemente
            if(dequeVazio(dq) == 1){
                printf("A lixeira j� est� vazia.\n");
            }else{
                resultFinalNotas = removeFinal_Deque(dq, guardaNome);
                printf("Voc� removeu permanentemente: Nome: %s   Nota: %.2f\n", guardaNome, resultFinalNotas);
            }
        }
        else{
            printf("ERRO: Opera��o inv�lida.\n");
        }
    }while((strcmp("sair", opcoes)) != 0); //opera��o para sair

    system("cls");

    destruir_Lista(&li); //desalocar a mem�ria
    liberaVetor_Deque(dq); //desalocar a mem�ria

    printf("Voc� saiu do programa.\n"); //mensagem final
    return 0;
}
