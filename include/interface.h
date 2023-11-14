#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "user.h"
#include "usuario.h"
#include "funcionario.h"
#include "biblioteca.h"
#include "emprestimo.h"
#include "livro.h"

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>

using namespace std;


class Interface {

public:
    // Construtor da interface gráfica
    Interface(Biblioteca& biblioteca);
    
    // Área q permite o usuário logar ou abrir seção de cadastro de usuário 
    shared_ptr<User> areaLogin();

    // Menu onde o usuário pode ver os livros que estão emprestados a ele, pedir para listar livros disponíveis na biblioteca, pedir empréstimo de livro, devolver livro e verificar suas notificações 
    void menuUsuario(shared_ptr<Usuario> usuario);

    // Menu onde o funcionário pode adicionar ou remover livros a biblioteca e adicionar novos funcionários
    void menuFuncionario(shared_ptr<Funcionario> funcionario);

    // Menu de cadastro de um usuário 
    void cadastroUsuario();

    // Menu de cadastro de um funcionário 
    void cadastroFuncionario();

private:
    vector<shared_ptr<User>> users_;
    Biblioteca biblioteca_;
};

#endif
