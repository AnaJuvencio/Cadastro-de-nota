# Cadastro de nota
Trabalho desenvolvido em linguagem C, no primeiro ano de faculdade, para a disciplina de Estrutura de Dados.

### Estrutura de Dados:
* Lista ✅
* Deque ✅

### Objetivo do projeto:
Criar uma aplicação que utilize as estruturas acima. O foco para correção seria o uso correto de ambas.

### Aplicação:
O programa foi desenvolvido para receber os nomes dos alunos e suas respectivas notas de uma prova. Com base nisso, o usuário terá a oportunidadede escolher a operação que deseja realizar, desde a inserção até a remoção desses dados. Para guardar essas informações utilizamos a **Lista**, e para receber o material removido dessa estrutura, utilizamos o **Deque**, que assumiu o papel de `lixeira`. Dessa forma, o utente poderá resgatar os elementos excluídos da lista, entre outras funcionalidades que serão expecificadas abaixo.

### Lista:
A Estrutura do tipo `Lista`, é uma sequência de elementos do mesmo tipo, podemos dizer também, que essa estrutura é uma sequência de structs, que são os nós da lista ligados entre si. Nós nunca temos acesso imediato aos dados, acessamos através de ponteiros, no qual cada nó possui. Pode ser um ponteiro somente para o sucessor, como em uma lista simplesmete encadeada.
