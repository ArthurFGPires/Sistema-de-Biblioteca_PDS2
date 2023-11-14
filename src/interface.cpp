#include "../include/interface.h"

map<string, Genero> stringToGenero = {
    {"FICCAO", Genero::FICCAO},
    {"DRAMA", Genero::DRAMA},
    {"SUSPENSE", Genero::SUSPENSE},
    {"ROMANCE", Genero::ROMANCE},
    {"NOVELA", Genero::NOVELA},
    {"CIENTIFICO", Genero::CIENTIFICO},
    {"FANTASIA", Genero::FANTASIA}
};


Interface::Interface(Biblioteca& biblioteca) {
    biblioteca_ = biblioteca;

    shared_ptr<Funcionario> funcionario = std::make_shared<Funcionario>("adimin", "987654321");
    users_.push_back(funcionario);

    shared_ptr<Livro> livro1 = std::make_shared<Livro>("HP", "J.K.R", Genero::FANTASIA);
    shared_ptr<Livro> livro2 = std::make_shared<Livro>("LOTR", "J.R.R", Genero::FANTASIA);
    shared_ptr<Livro> livro3 = std::make_shared<Livro>("Auto da Barca do Inferno", "Gil Vicente", Genero::DRAMA);
    shared_ptr<Livro> livro4 = std::make_shared<Livro>("Duna", "Frank Herbert", Genero::DRAMA);
    shared_ptr<Livro> livro5 = std::make_shared<Livro>("Jogos Vorazes", "Suazanna Collins", Genero::FICCAO);

    funcionario->adicionarLivro(livro1, biblioteca_);
    funcionario->adicionarLivro(livro2, biblioteca_);
    funcionario->adicionarLivro(livro3, biblioteca_);
    funcionario->adicionarLivro(livro4, biblioteca_);
    funcionario->adicionarLivro(livro5, biblioteca_);
}

shared_ptr<User> Interface::areaLogin() {
}

void Interface::menuUsuario(shared_ptr<Usuario> usuario) {
}

void Interface::menuFuncionario(shared_ptr<Funcionario> funcionario) {
   
}

void Interface::cadastroUsuario() {
    system("clear");
    cout << "Cadastro Usuario" << endl;
    cout << "======================" << endl;

    bool valido = true;
    string login, senha;

    do {
        cout << "Insira um login: ";
        getline(cin, login);

        for(auto user : users_) {
            if(user->getLogin() == login) {
                valido = false;
                cout << "\nEste usuário já existe, insira outro" << endl;
            }
        }

    } while (valido == false);

    do {
        cout << "Insira uma Senha: ";
        getline(cin, senha);

        for(auto user : users_) {
            if(!user->validarSenha(senha)) {
                valido = false;
                cout << "\nSenha Inválida, insira outra" << endl;
            }
        }
        
    } while (valido == false);

    shared_ptr<Usuario> novo_usuario = make_shared<Usuario>(login, senha);
    users_.push_back(novo_usuario);
}

void Interface::cadastroFuncionario() {
    system("clear");
    cout << "Cadastro Funcionario" << endl;
    cout << "======================" << endl;

    bool valido = true;
    string login, senha;

    do {
        cout << "Insira um login: ";

        for(auto user : users_) {
            if(user->getLogin() == login) {
                valido = false;
                cout << "\nEste usuário já existe, insira outro" << endl;
            }
        }

    } while (valido == false);

    do {
        cout << "Insira uma Senha: ";

        for(auto user : users_) {
            if(!user->validarSenha(senha)) {
                valido = false;
                cout << "\nSenha Inválida, insira outra" << endl;
            }
        }
        
    } while (valido == false);

    shared_ptr<Funcionario> novo_funcioario = make_shared<Funcionario>(login, senha);
    users_.push_back(novo_funcioario);
}