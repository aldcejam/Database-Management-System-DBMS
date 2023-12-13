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

### Criar uma nova tupla (linha ou registro) na tabela

<ol>
    <li>Usuário deve informar o nome da tabela</li>
    <li>sistema deve solicitar os valores de cada uma das colunas</li>
    <li>Verifica a chave primária.</li>
    <li>sistema deve verificar a chave primária *Em uma tabela deve existir um e apenas um valor de chave primária. Se o usuário informar uma chave que já existe, sistema deve emitir uma mensagem de erro e não deve inserir o registro*
</li> 
</ol>

### Listar todos os dados de uma tabela

<ol>
    <li>Usuário deve informar qual a tabela para serem listados os dados</li>
    <li>os dados deverão ser obtidos a partir do arquivo que armazena o conteúdo da tabela;</li>
</ol>

### Pesquisar valor em uma tabela

<ol>
    <li>Usuário deverá informar o nome da tabela onde realizará a pesquisa</li>
    <li>Sistema deverá fornecer as colunas disponíveis na tabela o usuário deverá selecionar uma delas</li>
    <li>Sistema deverá solicitar o valor para pesquisar, disponibilizando algumas opções
        <ul>
            <li>valores maior que o valor informado</li>
            <li>valores maior ou igual que o valor informado</li>
            <li>valores igual o valor informado</li>
            <li>valores menor que o valor informado</li>
            <li>valores menor ou igual que o valor informado</li>
            <li>valores próximo ao valor informado</li>
        </ul>
    </li>
</ol>


### Apagar uma tupla (registro ou linha) de uma tabela ###

<ol>
    <li>Usuário deve informar o nome da tabela e a chave primária da tupla a ser apagada</li>
</ol>

### Apagar uma tabela ###

<ol>
    <li>usuário deverá fornecer o nome da tabela a ser apagada</li>
</ol> 