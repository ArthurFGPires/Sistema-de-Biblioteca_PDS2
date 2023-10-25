class Interface {

public:
    // Construtor da interface gráfica
    Interface();
    
    // Área q permite o usuário logar ou abrir seção de cadastro de usuário 
     void areaLogin();

    // Menu onde o usuário pode ver os livros que estão emprestados a ele, pedir para listar livros disponíveis na biblioteca, pedir empréstimo de livro, devolver livro e verificar suas notificações 
    void menuUsuario();

    // Menu onde o funcionário pode adicionar ou remover livros a biblioteca e adicionar novos funcionários
    void menuFuncionario();

     // Menu de cadastro de um usuário 
     shared_ptr<Usuario> cadastroUsuario();

    // Menu de cadastro de um funcionário 
    shared_ptr<Funcionario> cadastroFuncionario();
};