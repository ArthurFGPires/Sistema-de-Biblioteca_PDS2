#ifndef __USUARIO_H__
#define __USUARIO_H__

#include "biblioteca.h"
#include "livro.h"
#include "user.h"
#include "emprestimo.h"
#include "erro.h"

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using std::string;
using std::vector;
using std::shared_ptr;

class Usuario : public User {
public:

    Usuario(const string& login, const string& senha, Biblioteca& biblioteca);

    // Retorna um vector com os livros alugados
    vector<shared_ptr<Livro>> listarAlugados();
    
    // Adiciona um livro à lista de alugados do usuário
    // Procura o Livro por título e autor
    void alugarLivro(const string& titulo, const string& autor);

    // Adiciona um livro à lista de alugados do usuário
    // Procura o Livro por ID
    void alugarLivro(const int id);

    // Devolve um livro da lista de alugados
    void devolverLivro(const int id);

    // Retorna um vector com todas as notificações para o usuario
    vector<string> getNotificacoes();

    // Retorna um vector com todos os prazos dos livros
    vector<string> getPrazos();

private:
    vector<shared_ptr<Emprestimo>> alugados_;
    Biblioteca& biblioteca_;
};

#endif
