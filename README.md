# Sistema de Gerenciamento de Banco de Dados (SGBD) - ITP #

## Descrição do Projeto ##
O projeto consiste na implementação de um Sistema de Gerenciamento de Banco de Dados (SGBD) simplificado, baseado no modelo relacional. Este SGBD, denominado ITP, tem como objetivo explorar os conceitos abordados na disciplina ITP, não sendo destinado para uso em produção por sistemas de informação.

Funcionalidades
Criar uma tabela

O usuário deve fornecer o nome da tabela.
Os tipos de dados para as colunas podem ser os tipos primitivos em C (char, int, float e double) e strings.
Os valores são armazenados em arquivo.
Na criação da tabela, é solicitado um nome de coluna para ser a chave primária.
A chave primária deve ser obrigatoriamente do tipo inteiro sem sinal.
Listar todas as tabelas

Exibe as tabelas existentes para o usuário.
Criar uma nova tupla (linha ou registro) na tabela

O usuário informa o nome da tabela.
O sistema solicita os valores de cada coluna.
Verifica a chave primária.
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