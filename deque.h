#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#define MAXchar 50

struct dados{ //dados do aluno
    float numInserir;
    char nomes[MAXchar];
};
typedef struct Deque Deque;

//Funções:
Deque *inicializa_Deque(int totalElementos); //inicializa o deque
void liberaVetor_Deque(Deque *dq); //desaloca a memória
int dequeCheio(Deque *dq); //verifica se está cheio
void insereInicio_Deque(Deque *dq, float valor, char nome[MAXchar]); //insere no início do deque
void insereFinal_Deque(Deque *dq, float valor, char nome[MAXchar]); //insere no final do deque
int dequeVazio(Deque *dq); //verifica se está vazio
float removeInicio_Deque(Deque* dq, char resultNome[MAXchar]); //remove o elemento do início do deque
float removeFinal_Deque(Deque* dq, char resultNome[MAXchar]); //remove o elemento do final do deque
void esvaziar(Deque *dq); //limpar o deque
void imprime_Deque(Deque* dq); //imprimir na tela


#endif // DEQUE_H_INCLUDED
