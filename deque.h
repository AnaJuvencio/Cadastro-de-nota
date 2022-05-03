#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#define MAXchar 50

struct dados{ //dados do aluno
    float numInserir;
    char nomes[MAXchar];
};
typedef struct Deque Deque;

//Fun��es:
Deque *inicializa_Deque(int totalElementos); //inicializa o deque
void liberaVetor_Deque(Deque *dq); //desaloca a mem�ria
int dequeCheio(Deque *dq); //verifica se est� cheio
void insereInicio_Deque(Deque *dq, float valor, char nome[MAXchar]); //insere no in�cio do deque
void insereFinal_Deque(Deque *dq, float valor, char nome[MAXchar]); //insere no final do deque
int dequeVazio(Deque *dq); //verifica se est� vazio
float removeInicio_Deque(Deque* dq, char resultNome[MAXchar]); //remove o elemento do in�cio do deque
float removeFinal_Deque(Deque* dq, char resultNome[MAXchar]); //remove o elemento do final do deque
void esvaziar(Deque *dq); //limpar o deque
void imprime_Deque(Deque* dq); //imprimir na tela


#endif // DEQUE_H_INCLUDED
