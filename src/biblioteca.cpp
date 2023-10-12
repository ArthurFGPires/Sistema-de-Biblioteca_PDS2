#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(const Livro& adicionar) {
    livros_.push_back(adicionar);
}

void Biblioteca::adicionarLivros(const vector<Livro>& lista_livros) {
    for (const Livro& l : lista_livros) {
        livros_.push_back(l);
    }
}

list<Livro> Biblioteca::listarLivros() {
    list<Livro> lista_livros;
    for (auto& l : livros_) {
        if(!l.getEmprestado()) {
            lista_livros.push_back(l);
        }
    }
    return lista_livros;
}

list<Livro> Biblioteca::listarLivrosGenero(string genero) {
    list<Livro> lista_livros;
    for (auto& l : livros_) {
        if (l.getGenero() == genero && !l.getEmprestado())
            lista_livros.push_back(l);
    }
    return lista_livros;
}

list<Livro> Biblioteca::listarLivrosAutor(string autor) {
    list<Livro> lista_livros;
    for (auto& l : livros_) {
        if (l.getAutor() == autor)
            lista_livros.push_back(l);
    }
    return lista_livros;
}

Livro* Biblioteca::buscarLivro(string titulo, string autor) {
    for (auto& l : livros_) {
        if (titulo == l.getTitulo() && autor == l.getAutor())
            return &l;
    }
    return nullptr;
}

Livro* Biblioteca::buscarLivro(int id) {
    for (auto& l : livros_) {
        if (id == l.getId())
            return &l;
    }
    return nullptr;
}

Livro* Biblioteca::emprestarLivro(string titulo, string autor) {
    Livro* livro = buscarLivro(titulo, autor);

    if (livro && !livro->getEmprestado()) {
        livro->emprestar();
        return livro;
    } else {
        return nullptr;
    }
}

Livro* Biblioteca::emprestarLivro(int id) {
    Livro* livro = buscarLivro(id);

    if (livro && !livro->getEmprestado()) {
        livro->emprestar();
        return livro;
    } else {
        return nullptr;
    }
}

void Biblioteca::devolverLivro(Livro* livro) {
    if (livro) {
        livro->devolucao();
    }
}
