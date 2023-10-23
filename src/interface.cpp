#include <iostream>
#include <string>
#include "../include/user.h"
#include "../include/usuario.h"
#include "../include/funcionario.h"

using namespace std;

void tela_inicial(){
    cout << "1 para logar 2 para criar conta";
    int s;
    cin >> s;
    if(s == 1 ){
        string usuario = User::getLogin;
        string senha = User::getSenha;

        if(User::checarUsuario(usuario, senha)){

            if(User::getPermissao()){
                User::login_usuario();
            }
            else User::login_funcionario();
        }
    }
    else if (s == 2){
        // criarUsuario
    }
    
}
void login_usuario(){
    
}
void login_funcionario(){
    cout << "1 para adicionar 2 para remover";
    int s;
    cin >> s;
    if (s == 1){
        Funcionario::adicionarLivro(livro, acervo);
    }
    else if(s == 2){
        // removerLivro
    }
}