#include "../include/emprestimo.h"

#include <string>
#include <iomanip>

Emprestimo::Emprestimo(shared_ptr<Livro> livro, int dias) {
    livro_ = livro;
    prazo_ = std::chrono::system_clock::now() + std::chrono::hours(24 * dias);
    notificacao_ = "";
}

shared_ptr<Livro> Emprestimo::getLivro() {
    return livro_;
}

const string Emprestimo::getPrazo() const{
    std::time_t prazo_time = std::chrono::system_clock::to_time_t(prazo_);
    std::tm prazo_tm = *std::localtime(&prazo_time);
    
    std::ostringstream prazo_stream;
    prazo_stream << std::put_time(&prazo_tm, "%d/%m/%Y");
    
    return prazo_stream.str();
}

void Emprestimo::verificaAtraso() {
    atrasado_ = std::chrono::system_clock::now() > prazo_;
}

const string Emprestimo::getNotificacao() {
    if(getAtraso()) {
        notificacao_ = "Livro " + livro_->getTitulo() + " está atrasado, data de devolucao foi " + getPrazo();
    }
    return notificacao_;
}

const bool Emprestimo::getAtraso() {
    verificaAtraso();
    return atrasado_;
}