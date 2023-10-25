# Sistema-de-Biblioteca_PDS2
Grupo:
  * Arthur Ferreira Gonçalves Pires
  * João Victor Vial Leite Soares
  * Lúcia Helena Ribeiro da Silva Capanema
  * João Vitor Batista Camargos

# Objetivo do Trabalho
O propósito do nosso trabalho é criar um sistema que se assemelhe a uma biblioteca virtual, empregando os princípios da Programação Orientada a Objetos (POO) e outros conceitos aprendidos na disciplina de Programação e Desenvolvimento de Software 2 (PDS 2).
Para a modelagem das classes do projeto, fizemos o uso de User Stories e cartões CRC.

# User Stories
  * Como usuário, desejo me cadastrar no sistema caso não tenha uma conta. 
  * Como usuário, quero poder verificar a disponibilidade de livros na biblioteca para empréstimo.
  * Como usuário, desejo ser informado se meus empréstimos estão dentro do prazo de devolução.
  * Como usuário, desejo a capacidade de alugar e devolver livros.
  * Como usuário, gostaria de receber notificações se meus livros estiverem atrasados.
  * Como usuário, gostaria de pesquisar livros na biblioteca pelo título e autor.
  * Como funcionário, desejo ser capaz de cadastrar novos livros e remover livros presentes na biblioteca.

# Cartões CRC
## Classe: Livro

- **Responsabilidades:**
  - Manter informações sobre um livro, incluindo título, autor, gênero, ID e status de empréstimo.
  - Gerar IDs aleatórios para cada livro.
  - Permitir empréstimo e devolução do livro.

- **Colaborações:**
  - Nenhuma relação de colaboração

A classe `Livro` é projetada para representar informações sobre livros, incluindo seus detalhes, ID e status de empréstimo. Ela fornece métodos para interagir com essas informações, permitindo o empréstimo e a devolução de livros, além de gerar IDs exclusivos para cada instância da classe.



## Classe: Biblioteca

- **Responsabilidades:**
  - Manter uma lista de livros disponíveis na biblioteca.
  - Adicionar livros à biblioteca.
  - Remover livros da biblioteca.
  - Listar livros disponíveis na biblioteca.
  - Listar livros com base no título, autor e gênero.
  - Emprestar livros para usuários.
  - Realizar a devolução de livros à biblioteca.

- **Colaborações:**
  - Colabora com a classe `Livro` para armazenar informações sobre os livros.
  - Colabora com a classe `User` para emprestar livros para usuários e permitir manipulações de funcionários.

A classe `Biblioteca` é responsável por gerenciar os livros disponíveis na biblioteca, permitindo adicionar, remover, listar, emprestar e devolver livros. Ela mantém uma lista de ponteiros para os livros disponíveis e colabora com as classes `Livro` e `User` para realizar operações de empréstimo e devolução.


## Classe: Emprestimo

- **Responsabilidades:**
  - Representar um empréstimo de um livro da biblioteca.
  - Definir um prazo de devolução padrão de 7 dias, que pode ser alterado.
  - Calcular e gerenciar o prazo de entrega e notificação de atraso.
  - Verificar se o livro está atrasado e fornecer informações sobre o atraso.

- **Colaborações:**
  - Colabora com a classe `Livro` para manter informações sobre o livro emprestado.
  - Colabora com a classe `Biblioteca` para gerenciar os empréstimos.

A classe `Emprestimo` representa um empréstimo de um livro da biblioteca, permitindo que os usuários definam um prazo de devolução. Ela calcula o prazo de entrega e verifica se o livro está atrasado, fornecendo notificações apropriadas. A classe colabora com `Livro` para manter informações sobre o livro emprestado e pode ser gerenciada pela classe `Biblioteca` ou outra classe relacionada ao sistema de empréstimo de livros.


## Classe: User (Classe Mãe para Funcionario e Usuario)

- **Responsabilidades:**
  - Representar um usuário genérico do sistema.
  - Manter informações básicas do usuário, como login, senha e nível de permissão.
  - Verificar se um usuário e senha são válidos.
  - Fornecer informações de login e permissão.

- **Colaborações:**
  - Serve como classe mãe para as classes `Funcionario` e `Usuario`, herdando suas funcionalidades e estrutura.
  - Pode ser estendida para adicionar funcionalidades específicas para diferentes tipos de usuários no sistema.

A classe `User` é uma classe mãe que encapsula informações genéricas de usuário, como login, senha e permissão. Ela fornece métodos para verificar a validade do login e senha e colabora com subclasses, como `Funcionario` e `Usuario`, para estender seu comportamento de acordo com as necessidades específicas de diferentes tipos de usuários no sistema.


## Classe: Usuario

- **Responsabilidades:**
  - Representar um usuário do sistema, estendendo a classe `User`.
  - Manter uma lista de livros alugados pelo usuário.
  - Adicionar e remover livros na lista de alugados.
  - Obter notificações e prazos dos livros alugados.

- **Colaborações:**
  - Herda funcionalidades da classe `User` para gerenciar informações de login e permissão.
  - Colabora com a classe `Biblioteca` para alugar e devolver livros.
  - Usa a classe `Emprestimo` para rastrear empréstimos de livros.

A classe `Usuario` representa um usuário do sistema que pode alugar e devolver livros da biblioteca. Ela herda as informações de login e permissão da classe `User` e adiciona funcionalidades específicas do usuário, como o rastreamento de livros alugados, notificações e prazos de devolução.


## Classe: Funcionario

- **Responsabilidades:**
  - Representar um funcionário do sistema, estendendo a classe `User`.
  - Ter a capacidade de adicionar livros ao acervo da biblioteca.

- **Colaborações:**
  - Herda funcionalidades da classe `User` para gerenciar informações de login e permissão.
  - Colabora com a classe `Biblioteca` para adicionar livros ao acervo.

A classe `Funcionario` representa um funcionário do sistema que possui permissões especiais para adicionar livros ao acervo da biblioteca. Ela herda as informações de login e permissão da classe `User` e adiciona funcionalidades específicas para funcionários, como a capacidade de adicionar livros ao acervo da biblioteca.


## Classe: Interface

- **Responsabilidades:**
  - Fornecer uma interface de usuário para interagir com o sistema.
  - Inicializar o menu e a interface, que pode ser utilizada em uma futura implementação gráfica.
  - Permitir ao usuário fazer login ou abrir a seção de cadastro de usuário.
  - Oferecer um menu para usuários onde eles podem visualizar livros emprestados, listar livros disponíveis na biblioteca, solicitar empréstimo, devolver livros e verificar notificações.
  - Oferecer um menu para funcionários onde eles podem adicionar ou remover livros da biblioteca e adicionar novos funcionários.
  - Fornecer a funcionalidade de cadastrar um usuário.
  - Fornecer a funcionalidade de cadastrar um funcionário.

- **Colaborações:**
  - Colabora com outras classes, como `Usuario`, `Funcionario`, `Biblioteca`, etc., para executar as operações e interações do usuário.

A classe `Interface` é projetada para fornecer uma interface de usuário para interagir com o sistema, permitindo que usuários façam login, naveguem pelos menus, realizem operações específicas para cada tipo de usuário (como usuário ou funcionário) e efetuem cadastros. Ela colabora com outras classes do sistema para realizar as operações e interações necessárias.

