#include "../include/interface.h"

Interface::Interface() {}

void Interface::areaLogin() {
    cout << "1 para logar, 2 para criar conta";
    int s;
    cin >> s;
    if (s == 1) {
        string login, senha;
        cin >> login >> senha;
        //checarUsuario(login, senha)
        /*
        if(user->getPermissao()){
            menuFuncionario();
        }
        else if(!user->getPermissao()){
            menuUsuario();
        }
        */
    } else if (s == 2) {
        cadastroUsuario();// criarUsuario
    }

}

void Interface::menuUsuario(){
    cout << "1 para ver os livros que ainda nao devolveu" << endl;
    cout << "2 para listar livros disponiveis para emprestimo" << endl;
    cout << "3 para ver notificacoes" << endl;
    int s;
    cin >> s;
    if (s == 1){
        //listarAlugados();
        cout << "1 para devolver livro" << endl;
        int x;
        cin >> x;
        if(x == 1){
            cout << "digite o id:" << endl;
            int id;
            cin >> id;
            cout << "digite o acervo:" << endl;
            //
            //devolverLivro(id, acervo);
        } else {
            //sair
        }
    
    } else if (s == 2){
        cout << "1 para listar todos" << endl;
        cout << "2 para listar por titulo" << endl;
        cout << "3 para listar por genero" << endl;
        cout << "4 para listar por autor" << endl;
        int p;
        cin >> p;
        if (p == 1){
            //listarLivros();
        } else if (p == 2){
            cout << "titulo:";
            string titulo;
            cin >> titulo;
            //listarLivrosTitulo(titulo);
        } else if (p == 3){
            cout << "genero:";
            string genero;
            cin >> genero;
            Genero genero;
            //listarLivrosGenero(genero);
        } else if (p == 4){
            cout << "autor";
            string autor;
            cin >> autor;
            //listarLivrosAutor(autor);
        }
        cout << "1 para pedir emprestimo de livro" << endl;
        int x;
        cin >> x;
        if (x == 1){
            cout << "1 para alugar por titulo e autor 2 para alugar por id";
            int y;
            cin >> y;
            if (y == 1){

            } else if (y == 2){

            } else {
                //sair
            }
        } else {
            //sair
        }
    } else if (s == 3){
        //getNotificacoes();
    }
}

void Interface::menuFuncionario(){
    cout << "1 para adicionar 2 para remover";
    int s;
    cin >> s;
    if (s == 1){
        cout << "1 para adicionar livro 2 para adicionar funcionario";
        int p;
        cin >> p;
        if(p == 1){
            string livro, acervo;
            cin >> livro >> acervo;
        //Funcionario.adicionarLivro( livro,  acervo);    //passagem de parametro shared_ptr?
        } else if (p == 2){
            cadastroFuncionario();
        }
    } else if(s == 2){
        // removerLivro
    }
}

shared_ptr<Usuario> Interface::cadastroUsuario(){
    string login, senha;
    cin >> login >> senha;
    shared_ptr<Usuario> usuario = make_shared<Usuario>(login, senha);
        
    return usuario;
}

shared_ptr<Funcionario> Interface::cadastroFuncionario(){
    string login, senha;
    cin >> login >> senha;
    shared_ptr<Funcionario> funcionario = make_shared<Funcionario>(login, senha);

    return funcionario;
}