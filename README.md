# Sistema de Gerenciamento de Banco de Dados (SGBD) - ITP

## Descrição do Projeto

O projeto consiste na implementação de um Sistema de Gerenciamento de Banco de Dados (SGBD) simplificado, baseado no modelo relacional. Este SGBD, denominado ITP, tem como objetivo explorar os conceitos abordados na disciplina ITP, não sendo destinado para uso em produção por sistemas de informação.

## Funcionalidades

### Criar uma tabela

<ol>
    <li>usuário deve informar o nome da tabela;</li>
    <li>os tipos de dados para as colunas poderão ser os tipos primitivos em C ( char, int, float e double) e strings;
    </li>
    <li>os valores deverão ser armazenados em arquivo;</li>
    <li>na criação da tabela deverá ser solicitado um nome de coluna para ser a chave primária *a chave primária deverá ser obrigatoriamente do tipo inteiro sem sinal*
    </li>
</ol>

### Listar todas as tabelas

<ol>
    <li>deverá mostrar para o usuário as tabelas existentes
    </li> 
</ol>


### Criar uma nova tupla (linha ou registro) na tabela ###

<ol>
    <li>Usuário deve informar o nome da tabela</li>
    <li>sistema deve solicitar os valores de cada uma das colunas</li>
    <li>Verifica a chave primária.</li>
    <li>sistema deve verificar a chave primária *Em uma tabela deve existir um e apenas um valor de chave primária. Se o usuário informar uma chave que já existe, sistema deve emitir uma mensagem de erro e não deve inserir o registro*
</li> 
</ol>

<li></li>

Uma tabela deve ter uma única chave primária. Se o usuário informar uma chave que já existe, o sistema emite uma mensagem de erro e não insere o registro.
Listar todos os dados de uma tabela

O usuário informa a tabela para listar os dados.
Os dados são obtidos a partir do arquivo que armazena o conteúdo da tabela.
Pesquisar valor em uma tabela

O usuário informa o nome da tabela para realizar a pesquisa.
O sistema fornece as colunas disponíveis.
O usuário seleciona uma coluna.
O sistema solicita o valor para pesquisa, oferecendo opções como maior que, maior ou igual a, igual a, menor que, menor ou igual a, próximo ao valor informado (aplica-se apenas a colunas do tipo string).
Apagar uma tupla (registro ou linha) de uma tabela

O usuário informa o nome da tabela e a chave primária da tupla a ser apagada.
Apagar uma tabela

O usuário fornece o nome da tabela a ser apagada.
