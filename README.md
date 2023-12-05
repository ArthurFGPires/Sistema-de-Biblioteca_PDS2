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

# Descrição das Classes
## Classe: Livro

- **Responsabilidades:**
  - Manter informações sobre um livro, incluindo título, autor, gênero, ID e status de empréstimo.
  - Gerar IDs aleatórios para cada livro.
  - Permitir empréstimo e devolução do livro.

- **Colaborações:**
  - Nenhuma relação de colaboração

A classe `Livro` é projetada para representar informações sobre livros, incluindo seus detalhes, ID e status de empréstimo. Ela fornece métodos para interagir com essas informações, permitindo o empréstimo e a devolução de livros, além de gerar IDs exclusivos para cada instância da classe.

Descrição dos métodos:

*Livro*
--------------------------------------------------------------
- titulo : string
- autor : string
- genero : Genero
- id : int
- emprestado : bool
+ getTitulo() : string     // Retorna o título
+ getAutor() : string      // Retorna o nome do Autor
+ getGenero() : Genero     // Retorna o genero do Livro
+ getId() : int            // Retorna o Id do livro
+ getEmprestado() : bool   // Retorna se o livro está disponível para empréstimo
+ emprestar() : void       // Altera o status de empréstimo do livro para verdadeiro
+ devolucao() : void       // Altera o status de empréstimo do livro para falso


## Classe: Biblioteca

- **Responsabilidades:**
  - Manter uma lista de livros disponíveis na biblioteca.
  - Adicionar livros à biblioteca.
  - Remover livros da biblioteca.
  - Listar livros disponíveis na biblioteca.
  - Listar livros com base no título, autor e gênero.
  - Gerar empréstimos de livros presentes na biblioteca.
  - Realizar a devolução de livros à biblioteca.

- **Colaborações:**
  - Colabora com a classe `Livro` para armazenar informações sobre os livros.
  - Colabora com a classe `User` para emprestar livros para usuários e permitir manipulações de funcionários.

A classe `Biblioteca` é responsável por gerenciar os livros disponíveis na biblioteca, permitindo adicionar, remover, listar, emprestar e devolver livros. Ela mantém uma lista de ponteiros para os livros disponíveis e colabora com as classes `Livro` e `User` para realizar operações de empréstimo e devolução.

Descrição dos métodos:

*Biblioteca*
--------------------------------------------------------------
- livros : list<shared_ptr<Livro>>

+ adicionarLivro(shared_ptr<Livro> livro, User& user) : void           // Adiciona um livro à biblioteca se o usuário for credenciado
+ removerLivro(int id, User& user) : void                              // Remove um livro da biblioteca se o usuário for credenciado
+ listarLivros() : list<shared_ptr<Livro>>                             // Retorna uma lista de livros disponíveis na biblioteca
+ listarLivrosGenero(Genero genero) : list<shared_ptr<Livro>>          // Retorna uma lista de livros disponíveis na biblioteca com o gênero específico
+ listarLivrosAutor(const string& autor) : list<shared_ptr<Livro>>     // Retorna uma lista de livros disponíveis na biblioteca com o autor específico
+ buscarLivro(string titulo, string autor) : shared_ptr<Livro>         // Busca livro com título e autor especificados
+ buscarLivro(int id) : shared_ptr<Livro>                              // Busca livro com o ID especificado
+ emprestarLivro(string titulo, string autor) : shared_ptr<Livro>      // Empresta o livro com título e autor especificados; se houver mais de um livro na biblioteca, um deles será emprestado
+ emprestarLivro(int id) : shared_ptr<Livro>                           // Empresta o livro com o ID indicado
+ devolverLivro(shared_ptr<Livro> livro) : void                        // Altera o status de empréstimo do livro especificado

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

Descrição dos metodos:

*Empréstimo*
--------------------------------------------------------------
- livro : shared_ptr<Livro>
- data_emprestimo : time_point
- prazo : time_point
- notificacao : string
- atrasado : bool

+ getLivro() : shared_ptr<Livro>    // Retorna o livro referente ao empréstimo
+ getPrazo() : string               // Retorna o prazo para devolução em formato "DD/MM/AAAA"
+ getNotificacao() : string         // Retorna uma notificação em caso de atraso
+ verificaAtraso() : void           // Atualiza o status de atraso do emprestimo
+ getAtraso() : bool                // Retorna o valor do atributo atrasado

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

Descrição dos metodos:

*User*
--------------------------------------------------------------
- login : string
- senha : string
- nivelPermissao : int

+ getSenha() : string                                   // Retorna a senha do user (protegido)
+ getLogin() : string                                   // Retorna o login
+ getPermissao () : int                                 // Retorna o nível de permissão do user
+ checarUsuario(string login, string senha) : bool      // Retorna se os parametros passados correspondem ao user
+ validarSenha(const string& senha) : bool              // Retorna se a senha inserida é valida para cadastro

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

Descrição dos métodos:

*Usuario*
--------------------------------------------------------------
- alugados : vector<shared_ptr<Emprestimo>>
- biblioteca : Biblioteca

+ listarAlugados() : vector<shared_ptr<Livro>>                           // Lista os livros alugados pelo usuario
+ alugarLivro(const string& titulo, const string& autor) : void          // Aluga o livro especificado(Autor, titulo) na biblioteca
+ alugarLivro(const int id) : void                                       // Aluga o livro especificado(Id) na biblioteca especificada
+ devolverLivro(const int id) : void                                     // Devolve livro da lista de alugados para sua biblioteca
+ getNotificacoes() : vector<string>                                     // Retorna as notificações referentes aos emprestimos
+ getPrazos() : vector<string>                                           // Retorna o prazo de devolução para cada livro alugado


## Classe: Funcionario

- **Responsabilidades:**
  - Representar um funcionário do sistema, estendendo a classe `User`.
  - Ter a capacidade de adicionar livros ao acervo da biblioteca.
  - Adicionar Funcionários ao sistema

- **Colaborações:**
  - Herda funcionalidades da classe `User` para gerenciar informações de login e permissão.
  - Colabora com a classe `Biblioteca` para adicionar livros ao acervo.

A classe `Funcionario` representa um funcionário do sistema que possui permissões especiais para adicionar livros ao acervo da biblioteca. Ela herda as informações de login e permissão da classe `User` e adiciona funcionalidades específicas para funcionários, como a capacidade de adicionar livros ao acervo da biblioteca. Ela também pode adicionar um novo `Funcionario` ao sistema.

Descrição dos métodos:

*Funcionário*
--------------------------------------------------------------
- biblioteca : Bilioteca

+ adicionarLivro(shared_ptr<Livro> livro) : void          // Adiciona livro na biblioteca
+ removerLivro(const int id) : void                       // Remove livro da biblioteca

## Classe: Interface

- **Responsabilidades:**
  - Fornecer uma interface de usuário para interagir com o sistema.
  - Inicializar o sistema e o menu inicial.
  - Permitir ao usuário fazer login ou abrir a seção de cadastro de usuário.
  - Oferecer um menu para usuários onde eles podem visualizar livros emprestados, listar livros disponíveis na biblioteca, solicitar empréstimo, devolver livros e verificar notificações.
  - Oferecer um menu para funcionários onde eles podem adicionar ou remover livros da biblioteca e adicionar novos funcionários.
  - Fornecer a funcionalidade de cadastrar um usuário.
  - Fornecer a funcionalidade de cadastrar um funcionário.

- **Colaborações:**
  - Colabora com outras classes, como `Usuario`, `Funcionario`, `Biblioteca`, `Erro`, para executar as operações e interações do usuário.

A classe `Interface` é projetada para fornecer uma interface de usuário para interagir com o sistema, permitindo que usuários façam login, naveguem pelos menus, realizem operações específicas para cada tipo de usuário (como usuário ou funcionário) e efetuem cadastros. Ela colabora com outras classes do sistema para realizar as operações e interações necessárias.

Descrição dos Métodos:

*Interface*
--------------------------------------------------------------
+ iniciar() : void                                        // Inicia a interface de usuário
+ fazerLogin() : void                                     // Realiza o login do usuário ou funcionário
+ menuUsuario(Usuario& usuario) : void                    // Apresenta o menu para usuários
+ menuFuncionario(Funcionario& funcionario) : void        // Apresenta o menu para funcionários
+ cadastrarUsuario() : void                               // Cadastra um novo usuário
+ cadastrarFuncionario() : void                           // Cadastra um novo funcionário


## Classe: Erro

- **Responsabilidades**
  - Possibilitar a criação de erros personalizados no código
  - Permitir o tratamento de erros personalizados no código

-**Colaborações**
  - A classe `Erro` realiza a herança da classe da biblioteca padrão Exception.

A classe `Erro` permite a criação de instâncias de erro com mensagens personalizadas, fornecendo uma forma mais clara e específica de lidar com exceções no código. O construtor permite a definição da mensagem de erro ao criar um objeto Erro, e o método what() possibilita a recuperação da mensagem associada ao erro.

Descrição dos Métodos:

*Erro*
--------------------------------------------------------------
+ Erro(const string& mensagem) : mensagem(mensagem)  // Construtor que recebe e armazena uma mensagem de erro
+ what() : string                                    // Retorna a mensagem de erro associada ao objeto

# Funcionamento do Código

Para executar este código, siga os passos a seguir:

1. Abra o terminal.
2. Digite o comando `make run` e pressione Enter.
3. Isso criará uma pasta chamada "build" onde os arquivos compilados serão armazenados.
4. Na pasta raiz, um arquivo executável será gerado e automaticamente executado.

Ao iniciar, o código leva o usuário para uma página inicial. Nesta página, é possível realizar diversas ações, como:

- **Login:** Permite o acesso tanto para funcionários quanto para usuários. Caso um usuário e senha inválidos sejam inseridos, o usuário será redirecionado ao menu inicial.
  
- **Cadastro de Novo Usuário:** O sistema não inicia com nenhum usuário criado além do funcionário cujo login é `admin` e a senha é `987654321`. Ao criar um novo usuário, serão solicitados login e senha. Se o login inserido já existir, um novo nome de usuário será requisitado até que um nome válido seja fornecido. Em seguida, será requisitada uma senha que atenda aos critérios de validação.
  
- **Sair:** Permite sair do sistema.

#### Menu Funcionário

Ao entrar como funcionário, serão apresentadas 4 opções:

- **Adicionar Livro à Biblioteca:** Solicita informações do livro a ser adicionado à biblioteca. Após fornecer os dados, o livro é incorporado à coleção.

- **Remover Livro da Biblioteca:** Lista os livros disponíveis na biblioteca, solicitando o ID do livro a ser removido.

- **Cadastrar Novo Funcionário:** Funciona de maneira semelhante ao cadastro de um novo usuário, solicitando login e senha.

- **Sair:** Permite retornar ao menu inicial.

#### Menu Usuário

Após acessar como usuário, o menu exibe:

- **Listar Livros Alugados:** Apresenta a lista dos livros atualmente alugados pelo usuário, seguido das notificações relacionadas aos empréstimos.

- **Listar Livros da Biblioteca:** Permite escolher o tipo de livro a ser listado: por gênero, autor ou título.

- **Alugar Livro:** Oferece 3 opções para alugar: por ID, título e autor. Há também a possibilidade de buscar um livro e, caso o livro desejado seja encontrado, é possível efetuar o aluguel.

- **Devolver Livro:** Requer o ID do livro a ser devolvido à biblioteca.

- **Sair:** Volta ao menu inicial do sistema.

Essas funcionalidades oferecem uma interação simples e completa com o sistema, permitindo aos usuários e funcionários realizar ações diversas de acordo com suas permissões e necessidades.

Por motivos de teste do código, o tempo de empréstimo foi definido para 1 minuto, então após 1 minuto do empréstimo do livro, caso a tela seja atualizada, uma notificação surgirá informando o atraso.
