#include "../include/interface.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void areaLogin() {
    cout << "1 para logar, 2 para criar conta";
    int s;
    cin >> s;
    if (s == 1) {
        string login, senha;
        cin >> login >> senha;
        User* user = new User(login, senha, 1);
        if(user->getPermissao()){
            menuFuncionario();
        }
        else if(!user->getPermissao()){
            menuUsuario();
        }
    } else if (s == 2) {
        string login1 , senha1;
        cout<<"Digite seu usuario e sua senha"<<endl;
        cout<<"Usuario:";
        cin>>login1;
        cout<<"Senha:";
        cin>>senha1;
        User* aux=new User(login1 , senha1 , 1);
        usuarios_.push_back(aux);
      
    }

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