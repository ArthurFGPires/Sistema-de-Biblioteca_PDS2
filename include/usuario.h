#ifndef __USUARIO_H__
#define __USUARIO_H__

#include "livro.h"
#include "biblioteca.h"
#include "emprestimo.h"

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Usuario {
public:
    
    // Retorna um vector com os livros alugados
    vector<Livro*> listarAlugados();
    
    // Adiciona um livro a lista de alugados do usuário
    // Procura o Livro por titulo e autor
    void alugarLivro(string titulo, string autor, Biblioteca& acervo);

    // Adiciona um livro a lista de alugados do usuário
    // Procura o Livro por id
    void alugarLivro(int id, Biblioteca& acervo);

    void devolverLivro(int id, Biblioteca& acervo);

private:
    string login_;
    string senha_;
    vector<Emprestimo*> alugados_;
};

#endif