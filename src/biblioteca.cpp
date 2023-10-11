#ifndef __BIBLIOTECA_CPP__
#define __BIBLIOTECA_CPP__

#include "../include/biblioteca.h"

Biblioteca::Biblioteca () {}

void Biblioteca::adicionarLivro(Livro adicionar) {
    livros_.push_back(adicionar);
}

void Biblioteca::adicionarLivros(vector<Livro> lista_livros) {
    for(Livro l : lista_livros) {
        livros_.push_back(l);
    }
}

vector<Livro> Biblioteca::listarLivros() {
    vector<Livro> lista_livros;

    for(auto l : livros_) {
        lista_livros.push_back(l);
    }

    return lista_livros;
}

vector<Livro> Biblioteca::listarLivrosGenero(string genero) {
    vector<Livro> lista_livros;

    for(auto l : livros_) {
        if(l.getGenero() == genero)
            lista_livros.push_back(l);
    }

    return lista_livros;
}

vector<Livro> Biblioteca::listarLivrosAutor(string autor) {
    vector<Livro> lista_livros;

    for(auto l : livros_) {
        if(l.getAutor() == autor)
            lista_livros.push_back(l);
    }

    return lista_livros;
}

Livro* Biblioteca::buscarLivroTitulo(string titulo) {
    vector<Livro> lista = listarLivros();

    for(auto &l : lista) {
        if(titulo == l.getTitulo())
            return &l;
    }
    return nullptr;
}

Livro* Biblioteca::buscarLivroID(int id) {
    vector<Livro> lista = listarLivros();

    for(auto &l : lista) {
        if(id == l.getId())
            return &l;
    }
    return nullptr;
}

#endif