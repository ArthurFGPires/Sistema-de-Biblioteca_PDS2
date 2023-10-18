#ifndef __USUARIO_H__
#define __USUARIO_H__

#include "livro.h"
#include "biblioteca.h"
#include "emprestimo.h"
#include "user.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Usuario : public User {
public:

    Usuario(const string& login, const string& senha);

    // Retorna um vector com os livros alugados
    vector<shared_ptr<Livro>> listarAlugados();
    
    // Adiciona um livro a lista de alugados do usuário
    // Procura o Livro por titulo e autor
    void alugarLivro(string titulo, string autor, Biblioteca& acervo);

    // Adiciona um livro a lista de alugados do usuário
    // Procura o Livro por id
    void alugarLivro(int id, Biblioteca& acervo);

    void devolverLivro(int id, Biblioteca& acervo);

private:
    vector<shared_ptr<Emprestimo>> alugados_;
};

#endif