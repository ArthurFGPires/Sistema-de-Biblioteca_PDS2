#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(shared_ptr<Livro> adicionar, User& user) {
    if(user.getPermissao() == 1) {
        livros_.push_back(adicionar);
    }
}

list<shared_ptr<Livro>> Biblioteca::listarLivros() {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if(!l->getEmprestado()) {
            lista_livros.push_back(l);
        }
    }
    return lista_livros;
}

list<shared_ptr<Livro>> Biblioteca::listarLivrosGenero(Genero genero) {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if (l->getGenero() == genero && !l->getEmprestado())
            lista_livros.push_back(l);
    }
    return lista_livros;
}

list<shared_ptr<Livro>> Biblioteca::listarLivrosAutor(string autor) {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if (l->getAutor() == autor)
            lista_livros.push_back(l);
    }
    return lista_livros;
}

shared_ptr<Livro> Biblioteca::buscarLivro(string titulo, string autor) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {
        if (titulo == (*it)->getTitulo() && autor == (*it)->getAutor()) {
            if (!(*it)->getEmprestado()) {
                return (*it); // Retorna um shared_ptr para uma cópia do livro
            }
        }
    }
    return nullptr;
}

shared_ptr<Livro> Biblioteca::buscarLivro(int id) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {
        if (id == (*it)->getId()) {
            if (!(*it)->getEmprestado()) {
                return (*it); // Retorna um shared_ptr para uma cópia do livro
            }
        }
    }
    return nullptr;
}

shared_ptr<Livro> Biblioteca::emprestarLivro(string titulo, string autor) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {
        if (titulo == (*it)->getTitulo() && autor == (*it)->getAutor()) {
            if (!(*it)->getEmprestado()) {
                (*it)->emprestar(); // Atualize o status de empréstimo
                return (*it); // Retorna um shared_ptr para uma cópia do livro
            }
        }
    }
    return nullptr;
}

shared_ptr<Livro> Biblioteca::emprestarLivro(int id) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {
        if (id == (*it)->getId()) {
            if (!(*it)->getEmprestado()) {
                (*it)->emprestar(); // Atualize o status de empréstimo
                return (*it); // Retorna um shared_ptr para uma cópia do livro
            }
        }
    }
    return nullptr;
}

void Biblioteca::devolverLivro(shared_ptr<Livro> livro) {
    livro->devolucao();
}