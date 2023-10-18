#include "../include/usuario.h"

Usuario::Usuario(const string& login, const string& senha) : User(login, senha, 0) {}

vector<shared_ptr<Livro>> Usuario::listarAlugados() {
    vector<std::shared_ptr<Livro>> livrosAlugados;
    
    for (const auto& emprestimo : alugados_) {
        std::shared_ptr<Livro> livro = emprestimo->getLivro();
        livrosAlugados.push_back(livro);
    }
    
    return livrosAlugados;
}

void Usuario::alugarLivro(string titulo, string autor, Biblioteca& acervo) {
    shared_ptr<Livro> livro = acervo.emprestarLivro(titulo, autor);

    if (livro) {
        shared_ptr<Emprestimo> emprestimo = std::make_shared<Emprestimo>(livro);
        this->alugados_.push_back(emprestimo);
    }
}

void Usuario::alugarLivro(int id, Biblioteca& acervo) {
    std::shared_ptr<Livro> livro = acervo.emprestarLivro(id);

    if (livro) {
        shared_ptr<Emprestimo> emprestimo = std::make_shared<Emprestimo>(livro);
        this->alugados_.push_back(emprestimo);
    }
}

void Usuario::devolverLivro(int id, Biblioteca& acervo) {
    auto it = alugados_.begin();

    while (it != alugados_.end()) {
        if ((*it)->getLivro()->getId() == id) {
            it = alugados_.erase(it);
            break;
        } else {
            ++it;
        }
    }

    std::shared_ptr<Livro> livro = acervo.buscarLivro(id);
    if (livro) {
        acervo.devolverLivro(livro);
    }
}