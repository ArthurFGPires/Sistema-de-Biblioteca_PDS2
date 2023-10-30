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

using namespace std;


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

#endif