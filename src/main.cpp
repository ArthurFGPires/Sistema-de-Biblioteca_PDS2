#include <iostream>
#include <string>
#include <memory>

#include "../include/livro.h"
#include "../include/biblioteca.h"
#include "../include/usuario.h"
#include "../include/funcionario.h"
#include "../include/interface.h"

using std::shared_ptr;


int main() {
    Biblioteca biblioteca;
    Interface menu(biblioteca);

    shared_ptr<User> user_logado = menu.areaLogin();

    if(user_logado) {
        if(user_logado->getPermissao() == 0) {
            shared_ptr<Usuario> usuario = dynamic_pointer_cast<Usuario>(user_logado);
            menu.menuUsuario(usuario);

        } else {
            shared_ptr<Funcionario> funcioario = dynamic_pointer_cast<Funcionario>(user_logado);
            menu.menuFuncionario(funcioario);

        }
    }

    return 0;
}