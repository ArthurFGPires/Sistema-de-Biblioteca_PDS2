#ifndef __USUARIO_H__
#define __USUARIO_H__

#include "biblioteca.h"
#include "livro.h"
#include "user.h"
#include "emprestimo.h"

#include <iostream>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

class Usuario : public User {
public:

    Usuario(const string& login, const string& senha);

    // Retorna um vector com os livros alugados
    vector<shared_ptr<Livro>> listarAlugados();
    
    // Adiciona um livro à lista de alugados do usuário
    // Procura o Livro por título e autor
    void alugarLivro(string titulo, string autor, Biblioteca& acervo);

    // Adiciona um livro à lista de alugados do usuário
    // Procura o Livro por ID
    void alugarLivro(int id, Biblioteca& acervo);

    // Devolve um livro da lista de alugados
    void devolverLivro(int id, Biblioteca& acervo);

    // Retorna um vector com todas as notificações para o usuario
    vector<string> getNotificacoes();

    vector<string> getPrazos();

private:
    vector<shared_ptr<Emprestimo>> alugados_;
};

#endif
