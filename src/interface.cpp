#include <iostream>
#include <string>
#include "interface.h"
#include "user.h" 
#include "usuario.h" 
#include "funcionario.h" 

using namespace std;

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

void menuUsuario(){
}

void menuFuncionario(){
    cout << "1 para adicionar 2 para remover";
    int s;
    cin >> s;
    if (s == 1){
        string livro, acervo;
        cin >> livro >> acervo ;
       // Funcionario Funcionario;
        //Funcionario.adicionarLivro( livro,  acervo);    //passagem de parametro shared_ptr?
    }
    else if(s == 2){
        // removerLivro
    }
}