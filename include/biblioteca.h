#ifndef __BIBLIOTECA_H__
#define __BIBLIOTECA_H__

#include <iostream>
#include <list>
#include <vector>

#include "../include/livro.h"

using std::string;
using std::list;
using std::vector;

class Biblioteca {
public:
    
    // Cria uma biblioteca vazia
    Biblioteca::Biblioteca();

    // Adiciona um livro na lista de livros da biblioteca    
    void adicionarLivro(Livro livro);

    // Adiciona todos os livros de um vector a lista de livros da biblioteca
    void adicionarLivros(vector<Livro> lista_livros);

    // Lista todos os livros da biblioteca
    vector<Livro> listarLivros();

    // Lista todos os livros do genero presentes na biblioteca
    // IMPORTANTE: Se o gênero do livro foi inserido incorretamente no construtor o livro não será listado
    vector<Livro> listarLivrosGenero(string genero);

    // Lista todos os livros do autor presentes na biblioteca
    vector<Livro> listarLivrosAutor(string autor);

    // retorna um ponteiro para o Livro na biblioteca de acordo com o titulo
    Livro* buscarLivroTitulo(string titulo);

    // retorna um ponteiro para o Livro na biblioteca de acordo com o ID
    Livro* buscarLivroID(int id);


private:
    list<Livro> livros_;
};

#endif