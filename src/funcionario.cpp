#include "../include/funcionario.h"

Funcionario::Funcionario(const string& login, const string& senha, Biblioteca& biblioteca) 
: User(login, senha, 1),  biblioteca_(biblioteca) {}

void Funcionario::adicionarLivro(shared_ptr<Livro> livro) {
    biblioteca_.adicionarLivro(livro, *this);
}

void Funcionario::removerLivro(int id) {
    biblioteca_.removerLivro(id, *this);
}