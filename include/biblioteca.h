#ifndef __BIBLIOTECA_H__
#define __BIBLIOTECA_H__

#include <iostream>
#include <list>
#include <vector>

#include "livro.h"
#include "usuario.h"

using std::string;
using std::list;
using std::vector;

class Biblioteca {
public:
    
    // Cria uma biblioteca vazia
    Biblioteca::Biblioteca();

    // Adiciona um livro na lista de livros da biblioteca    
    void adicionarLivro(const Livro& livro);

    // Adiciona todos os livros de um vector a lista de livros da biblioteca
    void adicionarLivros(const vector<Livro>& lista_livros);

    // retorna um vector de ponteiros para todos os livros da biblioteca
    list<Livro> listarLivros();

    // Lista todos os livros do genero presentes na biblioteca
    // IMPORTANTE: Se o gênero do livro foi inserido incorretamente no construtor o livro não será listado
    list<Livro> listarLivrosGenero(string genero);

    // retorna um vector com ponteiros para todos os livros do autor presentes na biblioteca
    list<Livro> listarLivrosAutor(string titulo);

    // retorna um ponteiro para o Livro na biblioteca de acordo com o titulo
    // Caso o livro não esteja na biblioteca retorna um ponteiro nulo
    Livro* buscarLivro(string titulo, string autor);

    // retorna um ponteiro para o Livro na biblioteca de acordo com o ID
    // Caso o livro não esteja na biblioteca retorna um ponteiro nulo
    Livro* buscarLivro(int id);

    // Empresta um livro para o Usuario especificado
    // Recebe o titulo e o autor para encontrar o livro
    Livro* emprestarLivro(string titulo, string autor);

    // Empresta um livro para o Usuario especificado
    // Recebe o id para encontrar o livro
    Livro* emprestarLivro(int id);

    // Realiza a devolução de um livro para a biblioteca
    void devolverLivro(Livro* livro);


private:
    list<Livro> livros_;
};

#endif