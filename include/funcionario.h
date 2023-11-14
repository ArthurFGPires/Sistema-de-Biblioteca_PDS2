#ifndef __FUNCIONARIO_H__
#define __FUNCIONARIO_H__

#include "user.h"
#include "livro.h"
#include "biblioteca.h"

#include <vector>

using std::vector;

class Funcionario : public User {
public:
    Funcionario(const string& login, const string& senha, Biblioteca& biblioteca);

    void adicionarLivro(shared_ptr<Livro> livro);

    void removerLivro(int id);

private:
    Biblioteca& biblioteca_;
};

#endif