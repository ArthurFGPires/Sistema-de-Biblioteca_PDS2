#include "../include/biblioteca.h"

Biblioteca::Biblioteca() {}

void Biblioteca::adicionarLivro(shared_ptr<Livro> adicionar, User& user) {
    if(user.getPermissao() == 1) {
        livros_.push_back(adicionar);
    } else {
        throw Erro("Erro: Usuario não tem permissão para executar essa ação");
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
    } else {
        throw Erro("Erro: Usuário não tem permissão para tal ação");
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

list<shared_ptr<Livro>> Biblioteca::listarLivrosGenero(const string& genero) {
    std::map<string, Genero> stringToGenero = {
        {"FICCAO", Genero::FICCAO},
        {"DRAMA", Genero::DRAMA},
        {"SUSPENSE", Genero::SUSPENSE},
        {"ROMANCE", Genero::ROMANCE},
        {"NOVELA", Genero::NOVELA},
        {"CIENTIFICO", Genero::CIENTIFICO},
        {"FANTASIA", Genero::FANTASIA}
    };
    
    auto it = stringToGenero.find(genero);
    if(it != stringToGenero.end()) {
        list<shared_ptr<Livro>> lista_livros;
        for (auto& l : livros_) {
            if (l->getGenero() == stringToGenero[genero] && !l->getEmprestado())
                lista_livros.push_back(l);
        }
        return lista_livros;
    } else {
        throw Erro("Erro: Genero Inválido");
    }
}

list<shared_ptr<Livro>> Biblioteca::listarLivrosAutor(const string& autor) {
    list<shared_ptr<Livro>> lista_livros;
    for (auto& l : livros_) {
        if (l->getAutor() == autor)
            lista_livros.push_back(l);
    }
    return lista_livros;
}

shared_ptr<Livro> Biblioteca::buscarLivro(const string& titulo, const string& autor) {
    auto it = std::find_if(livros_.begin(), livros_.end(), [titulo, autor](const auto& livro) {
        return livro->getTitulo() == titulo && livro->getAutor() == autor && !livro->getEmprestado();
    });

    if (it != livros_.end()) {
        return *it;
    } else {
        throw Erro("Erro: Livro não encontrado");
    }
}

shared_ptr<Livro> Biblioteca::buscarLivro(const int id) {
    auto it = std::find_if(livros_.begin(), livros_.end(), [id](const auto& livro) {
        return livro->getId() == id && !livro->getEmprestado();
    });

    if (it != livros_.end()) {
        return *it;
    } else {
        throw Erro("Erro: Livro não encontrado");
    }
}

shared_ptr<Emprestimo> Biblioteca::emprestarLivro(const string& titulo, const string& autor) {
    try {
        shared_ptr<Livro> livro = buscarLivro(titulo, autor);

        livro->emprestar();
        return std::make_shared<Emprestimo>(livro, 0, 0, 1);
    } catch (const Erro& e) {
        throw;
    }
}

shared_ptr<Emprestimo> Biblioteca::emprestarLivro(const int id) {
    try {
        shared_ptr<Livro> livro = buscarLivro(id);

        livro->emprestar();
        return std::make_shared<Emprestimo>(livro, 0, 0, 1);
    } catch (const Erro& e) {
        throw;
    }
}
