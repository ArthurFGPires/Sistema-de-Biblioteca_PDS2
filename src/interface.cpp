#include <iostream>
#include <string>
#include "user.h" 
#include "usuario.h" 
#include "funcionario.h" 

using namespace std;

void tela_inicial() {
    cout << "1 para logar, 2 para criar conta";
    int s;
    cin >> s;
    if (s == 1) {
        string login, senha;
        cin >> login >> senha;
        User* user = new User(login, senha, 1);
        if(user->getPermissao()){
            login_funcionario();
        }
        else if(!user->getPermissao()){
            login_usuario();
        }
    } else if (s == 2) {
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
        string livro, acervo;
        cin >> livro >> acervo ;
       // Funcionario Funcionario;
        //Funcionario.adicionarLivro( livro,  acervo);    //passagem de parametro shared_ptr?
    }
    else if(s == 2){
        // removerLivro
    }
}