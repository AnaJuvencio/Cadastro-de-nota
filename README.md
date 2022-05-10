# Cadastro de nota
Trabalho desenvolvido em linguagem C, no primeiro ano de faculdade, para a disciplina de Estrutura de Dados.

## Estrutura de Dados:
* Lista ✅
* Deque ✅

## Objetivo do projeto:
Criar uma aplicação que utilize as estruturas acima. O foco para correção seria o uso correto de ambas.

## Aplicação:
O programa foi desenvolvido para receber os nomes dos alunos e suas respectivas notas de uma prova. Com base nisso, o usuário terá a oportunidadede escolher a operação que deseja realizar, desde a inserção até a remoção desses dados. Para guardar essas informações utilizamos a **Lista**, e para receber o material removido dessa estrutura, utilizamos o **Deque**, que assumiu o papel de `lixeira`. Dessa forma, o utente poderá resgatar os elementos excluídos da lista, entre outras funcionalidades que serão explicadas abaixo.

## Lista:
A Estrutura do tipo `Lista`, é uma sequência de elementos do mesmo tipo, podemos dizer também, que essa estrutura é uma sequência de structs, que são os nós da lista ligados entre si. Nós nunca temos acesso imediato aos dados, acessamos através de ponteiros, no qual cada nó possui. Pode ser um ponteiro somente para o sucessor, como em uma lista simplesmente encadeada.

<img src="https://github.com/anabias/Cadastro-de-nota/blob/main/listaSimple.jpg" alt="Lista simplesmente encadeada" width="500"/>

Ou um ponteiro para o sucessor e o antecessor, como uma lista duplamente encadeada.

<img src="https://github.com/anabias/Cadastro-de-nota/blob/main/listaDupla.jpg" alt="Lista duplamente encadeada" width="500"/>

## Deque: 
A estrutura do tipo `Deque`, é conhecida como fila de duas extremidades (Double Ended QUEue, isto é, fila com duas saídas), ou seja, essa estrutura é um tipo especial de fila. O que faz o deque diferente é o fato de que a inserção de novos itens pode ocorrer no início ou no final e sua remoção também. Observe:

<img src="https://github.com/anabias/Cadastro-de-nota/blob/main/dequeImg.jpg" alt="Deque" width="500"/>

## Sentinela:
Em listas encadeadas podemos usar o `sentinela` para a busca de chaves. Ele torna a lista circular pois fica no fim e no início dessa estrutura, então ao invés de verificar as extremidades sendo igual a **NULL**, averiguamos se elas retornam o sentinela.

<img src="https://github.com/anabias/Cadastro-de-nota/blob/main/sentinela-img.jpg" alt="Sentinela" width="600"/>

## Iterador:
O `iterador` é um mecanismo criado para percorrer a estrutura (todos os elementos), porém ele não exibe sua representação (estrutura do iterador) interna para o usuário.
