#include "../include/usuario.h"

Usuario::Usuario(const string& login, const string& senha, Biblioteca& biblioteca) 
: User(login, senha, 0), alugados_(), biblioteca_(biblioteca) {}

vector<shared_ptr<Livro>> Usuario::listarAlugados() {
    vector<std::shared_ptr<Livro>> livrosAlugados;
    
    for (const auto& emprestimo : alugados_) {
        std::shared_ptr<Livro> livro = emprestimo->getLivro();
        livrosAlugados.push_back(livro);
    }
    
    return livrosAlugados;
}

void Usuario::alugarLivro(string titulo, string autor) {
    shared_ptr<Livro> livro = biblioteca_.emprestarLivro(titulo, autor);

    if (livro) {
        shared_ptr<Emprestimo> emprestimo = std::make_shared<Emprestimo>(livro);
        alugados_.push_back(emprestimo);
    }
}

void Usuario::alugarLivro(int id) {
    std::shared_ptr<Livro> livro = biblioteca_.emprestarLivro(id);

    if (livro) {
        shared_ptr<Emprestimo> emprestimo = std::make_shared<Emprestimo>(livro);
        alugados_.push_back(emprestimo);
    }
}

void Usuario::devolverLivro(int id) {
    auto it = alugados_.begin();

    while (it != alugados_.end()) {
        if ((*it)->getLivro()->getId() == id) {
            shared_ptr<Livro> livro = (*it)->getLivro();
            biblioteca_.devolverLivro(livro);
            
            it = alugados_.erase(it);
            break;
        } 
        else {
            ++it;
        }
    }
}

vector<string> Usuario::getNotificacoes() {
    vector<string> notificacoes;
    for(auto e : alugados_) {
        if(e->getNotificacao().size() > 0) {
            notificacoes.push_back(e->getNotificacao());
        }
    }

    if(notificacoes.size() == 0) notificacoes.push_back("Nenhuma Notificação");

    return notificacoes;
}

vector<string> Usuario::getPrazos() {
    vector<string> prazos;
    for(auto e : alugados_) {
        prazos.push_back(e->getPrazo());
    }

    return prazos;
}