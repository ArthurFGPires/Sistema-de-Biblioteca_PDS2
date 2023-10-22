#include "../include/funcionario.h"

Funcionario::Funcionario(const string& login, const string& senha) : User(login, senha, 1) {}

void Funcionario::adicionarLivro(shared_ptr<Livro> livro, Biblioteca& acervo) {
    acervo.adicionarLivro(livro, *this);
}
