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


Interface::Interface(Biblioteca& biblioteca) : biblioteca_(biblioteca) {
    shared_ptr<Funcionario> funcionario = std::make_shared<Funcionario>("adimin", "987654321", biblioteca_);
    users_.push_back(funcionario);

    shared_ptr<Livro> livro1 = std::make_shared<Livro>("HP", "J.K.R", Genero::FANTASIA);
    shared_ptr<Livro> livro2 = std::make_shared<Livro>("LOTR", "J.R.R", Genero::FANTASIA);
    shared_ptr<Livro> livro3 = std::make_shared<Livro>("Auto da Barca do Inferno", "Gil Vicente", Genero::DRAMA);
    shared_ptr<Livro> livro4 = std::make_shared<Livro>("Duna", "Frank Herbert", Genero::DRAMA);
    shared_ptr<Livro> livro5 = std::make_shared<Livro>("Jogos Vorazes", "Suazanna Collins", Genero::FICCAO);

    funcionario->adicionarLivro(livro1);
    funcionario->adicionarLivro(livro2);
    funcionario->adicionarLivro(livro3);
    funcionario->adicionarLivro(livro4);
    funcionario->adicionarLivro(livro5);

}

shared_ptr<User> Interface::areaLogin() {
    int sel;
    do {
        system("clear");
        cout << "1) Logar" << endl;
        cout << "2) Cadastrar" << endl;
        cout << "3) Sair" << endl;
        cin >> sel;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(sel == 1) {
            system("clear");

            cout << "Login : ";
            string login;
            getline(cin, login);

            cout << "Senha : ";
            string senha;
            getline(cin, senha);

            for(auto user : users_) {
                if(user->checarUsuario(login, senha))
                    return user;
            }

        } else if (sel == 2) {
            cadastroUsuario();
        } else if (sel == 3) {
            cout << "Saindo....." << endl;
            return nullptr;
        } else {
            cout << "Comando Inválido" << endl;
            cin.get();
        }

    } while(sel != 3);
}

void Interface::menuUsuario(shared_ptr<Usuario> usuario) {
    int sel;
    
    do {
        system("clear");
        cout << "Livros Alugados" << endl;
        cout << "-------------------------------" << endl;
        for(auto livro : usuario->listarAlugados()) {
            cout << *livro << endl;
        }
        cout << "-------------------------------" << endl;
        cout << "\n\n";

        cout << "Menu Usuário" << endl;
        cout << "-------------------------------" << endl;
        cout << "1) Listar livros da Biblioteca" << endl;
        cout << "2) Alugar Livro" << endl;
        cout << "3) Devolver Livro" << endl;
        cout << "4) Sair" << endl;

        cin >> sel;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(sel == 1) {
            cout << "\n\n";
            int op_listar;
            cout << "1) Listar todos os livros disponíveis" << endl;
            cout << "2) Listar livros com um título específico" << endl;
            cout << "3) Listar livros de um autor específico" << endl;
            cout << "4) Listar livros de um gênero específico" << endl;
            
            cin >> op_listar;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            list<shared_ptr<Livro>> lista;
            string pesquisa;

            switch (op_listar)
            {
            case 1:
                lista = biblioteca_.listarLivros();
                break;
            
            case 2:
                cout << "Insira o título: ";
                getline(cin, pesquisa);
                lista = biblioteca_.listarLivrosTitulo(pesquisa);
                break; 

            case 3:
                cout << "Insira o Autor: ";
                getline(cin, pesquisa);
                lista = biblioteca_.listarLivrosAutor(pesquisa);
                break;
            
            case 4:
                cout << "Insira o Gênero: ";
                getline(cin, pesquisa);
                lista = biblioteca_.listarLivrosGenero(stringToGenero[pesquisa]);

                break;

            default:
                break;
            }
            for(auto livro : lista) {
                cout << *livro;
            }
            cin.get();

        } else if(sel == 2) {
            system("clear");

            int sel_alugar;
            cout << "1) Buscar Livro" << endl;
            cout << "2) Alugar Livro por ID" << endl;
            cout << "3) Alugar Livro por Título e Autor" << endl;

            cin >> sel_alugar;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if(sel_alugar == 1) {
                string titulo, autor;
                cout << "Insira o Título: ";
                getline(cin, titulo);
                cout << "Insira o Autor: ";
                getline(cin, autor);

                shared_ptr<Livro> livro = biblioteca_.buscarLivro(titulo, autor);
                if(livro) {
                    cout << "\nResultado: " << endl;
                    // cout << livro;
                    cout << *livro;
                    
                    cout << "\nDeseja Alugar este livro? [Y/n]: ";
                    char alugar;
                    cin >> alugar;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    if(alugar == 'Y' || alugar == 'y') {
                        usuario->alugarLivro(livro->getId());
                    }
                } else {
                    cout << "Livro não encontrado." << endl;
                    cin.get();
                }
                

            } else if(sel_alugar == 2) {
                int id;
                cout << "Insira o ID: ";
                cin >> id;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                usuario->alugarLivro(id);

            } else if(sel_alugar == 3) {
                string titulo, autor;
                cout << "Insira o Título: ";
                getline(cin, titulo);
                cout << "Insira o Autor: ";
                getline(cin, autor);

                usuario->alugarLivro(titulo, autor);
            } else {
                cout << "Operação Inválida" << endl;
                cin.get();
            }

        } else if(sel == 3) {
            cout << "\nInsira o ID do livro a ser devolvido: ";
            int id;
            cin >> id;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            usuario->devolverLivro(id);
            
        } else if(sel == 4) {
            cout << "Saindo......." << endl;
            cin.get();
        } else {
            cout << "Operação Inválida, insira outra" << endl;
            cin.get();
        }
        

    } while(sel != 4);
}

void Interface::menuFuncionario(shared_ptr<Funcionario> funcionario) {
    int sel;
    do {
        system("clear");
        cout << "Menu Funcionario" << endl;
        cout << "-----------------------" << endl;
        cout << "1) Adicionar Livro a Biblioteca" << endl;
        cout << "2) Remover Livro da Biblioteca" << endl;
        cout << "3) Cadastrar novo Funcionário" << endl;
        cout << "4) Sair" << endl;

        cin >> sel;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(sel == 1) {
            system("clear");
            string titulo, autor, genero;

            cout << "Insira o Título do Livro: ";
            getline(cin, titulo);

            cout << "Insira o Autor do Livro: ";
            getline(cin, autor);

            cout << "Insira o Gênero do Livro: ";
            getline(cin, genero);

            shared_ptr<Livro> novo_livro = make_shared<Livro>(titulo, autor, stringToGenero[genero]);
            funcionario->adicionarLivro(novo_livro);

            cout << "\nLivro Adicionado" << endl;
            cout << "Livros presentes na Biblioteca: " << endl;
            
            for(auto livro : biblioteca_.listarLivros()) {
                cout << *livro;
            }
            
            cin.get();

        } else if(sel == 2) {
            system("clear");
            cout << "Livros presentes na Biblioteca: " << endl;
            
            for(auto livro : biblioteca_.listarLivros()) {
                cout << *livro;
            }

            cout << "\nInsira o ID: ";
            int id;
            cin >> id;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            funcionario->removerLivro(id);
          
        } else if(sel == 3) {
            cadastroFuncionario();
        } else if(sel == 4) {
            cout << "Saindo......" << endl;
            cin.get();
        } else {
            cout << "Opção Inválida, selecione outra" << endl;
            cin.get();
        }
    } while(sel != 4);
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

    shared_ptr<Usuario> novo_usuario = make_shared<Usuario>(login, senha, biblioteca_);
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

    shared_ptr<Funcionario> novo_funcioario = make_shared<Funcionario>(login, senha, biblioteca_);
    users_.push_back(novo_funcioario);
}
