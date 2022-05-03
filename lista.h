#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define copyright "copyright@ Ana Beatriz Juvencio e Victor Motta"
#define MAXchar 50
#define MAXfloat 100000

typedef char nomes; //renomear o char para nomes
typedef float notas; //renomear o float para notas

struct aluno{ //dados dos alunos
    nomes aluno[MAXchar];
    notas nota;
};

struct lista{
    struct node *sentinela;
    unsigned quantidade;
};
typedef struct lista lista;

typedef struct Iterador{
    struct node *posicao;
    lista *estrutura;
}iterador;
typedef struct Iterador iterador;

//fun��es:
void inicializar_Lista(lista *li); //inicializa a lista
void inserirInicio_Lista(lista *li, nomes alunos[MAXchar], notas Nota); //insere no in�cio da lista
void insereFinal_Lista(lista *li, nomes alunos[MAXchar], notas Nota); //insere no final da lista
int removeInicio_Lista(lista *li, nomes result[MAXchar], notas *resultNota); //remove no in�cio da lista
int removeFinal_Lista(lista *li, nomes result[MAXchar], notas *resultNota);//remove no final da lista
int listaVazia(lista *li); //verifica se a lista est� vazia
void destruir_Lista(lista *li);//desaloca a mem�ria
//iterador:
iterador ultimo_Lista(lista *li); //achar o �ltimo elemento da lista
int proximo_Lista(iterador *i); //caminha elemento por elemento, indo para o pr�ximo
iterador primeiro_Lista(lista *li); //retorna o primeiro elemento da lista
iterador procuraPrimeiro_Lista(lista *li, nomes aluno[MAXchar]); //utilizada para procurar um elemento na lista
void insereDepois_Lista(iterador i, nomes aluno[MAXchar], notas Nota); //insere depois de uma refer�ncia
void removerDepois_Lista(iterador i, nomes result[MAXchar], notas *resultNotas); //remove depois de uma refer�ncia
int acabou_Lista(iterador i); //retorna o iterador
//imprimir:
void imprime_Lista(lista *li);
#endif // LISTA_H_INCLUDED
