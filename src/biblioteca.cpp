#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(shared_ptr<Livro> adicionar, User& user) {
    if(user.getPermissao() == 1) {
        livros_.push_back(adicionar);
    }
}

void Biblioteca::removerLivro(int id, User& user) {
    if(user.getPermissao()){
        list<shared_ptr<Livro>>::iterator it;

        for(it = livros_.begin(); it != livros_.end(); ++it) {
            if((*it)->getId() == id) {
                livros_.erase(it);
                break;
            }
        }
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

list<shared_ptr<Livro>> Biblioteca::listarLivrosTitulo(const string& titulo) {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if (l->getTitulo() == titulo && !l->getEmprestado())
            lista_livros.push_back(l);
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

list<shared_ptr<Livro>> Biblioteca::listarLivrosAutor(const string& autor) {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if (l->getAutor() == autor)
            lista_livros.push_back(l);
    }
    return lista_livros;
}

shared_ptr<Livro> Biblioteca::buscarLivro(string titulo, string autor) {
    auto it = std::find_if(livros_.begin(), livros_.end(), [titulo, autor](const auto& livro) {
        return livro->getTitulo() == titulo && livro->getAutor() == autor && !livro->getEmprestado();
    });

    if (it != livros_.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

shared_ptr<Livro> Biblioteca::buscarLivro(int id) {
    auto it = std::find_if(livros_.begin(), livros_.end(), [id](const auto& livro) {
        return livro->getId() == id && !livro->getEmprestado();
    });

    if (it != livros_.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

shared_ptr<Emprestimo> Biblioteca::emprestarLivro(string titulo, string autor) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {

        if (titulo == (*it)->getTitulo() && autor == (*it)->getAutor() && !(*it)->getEmprestado()) {
            
            (*it)->emprestar(); 
            return std::make_shared<Emprestimo>((*it));
        }
    }
    return nullptr;
}

shared_ptr<Emprestimo> Biblioteca::emprestarLivro(int id) {
    for (auto it = livros_.begin(); it != livros_.end(); ++it) {

        if (id == (*it)->getId() && !(*it)->getEmprestado()) {
            
            (*it)->emprestar(); 
            return std::make_shared<Emprestimo>((*it));
        }
    }
    return nullptr;
}
