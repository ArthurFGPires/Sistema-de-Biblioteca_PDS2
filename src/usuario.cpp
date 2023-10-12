#include "../include/usuario.h"

vector<Livro*> Usuario::listarAlugados() {
    std::vector<Livro*> livrosAlugados;
    
    for (Emprestimo* emprestimo : alugados_) {
        livrosAlugados.push_back(emprestimo->getLivro());
    }
    
    return livrosAlugados;
}

void Usuario::alugarLivro(string titulo, string autor, Biblioteca& acervo) {
    Livro* livro = acervo.emprestarLivro(titulo, autor);

    if (livro) {
        Emprestimo* emprestimo = new Emprestimo(livro);
        this->alugados_.push_back(emprestimo);
        delete(emprestimo);
    }
}

void Usuario::alugarLivro(int id, Biblioteca& acervo) {
    Livro* livro = acervo.emprestarLivro(id);

    if (livro) {
        Emprestimo* emprestimo = new Emprestimo(livro);
        this->alugados_.push_back(emprestimo);
        delete(emprestimo);
    }
}

void Usuario::devolverLivro(int id, Biblioteca& acervo) {
    auto it = alugados_.begin();

    while (it != alugados_.end()) {
        if ((*it)->getLivro()->getId() == id) {
            Emprestimo* emprestimo = *it;
            it = alugados_.erase(it);
            delete emprestimo;
            break;
        } else {
            ++it;
        }
    }
    acervo.devolverLivro(acervo.buscarLivro(id));
}
