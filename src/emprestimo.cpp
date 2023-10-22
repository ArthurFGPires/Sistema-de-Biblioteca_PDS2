#include "../include/emprestimo.h"

#include <string>
#include <iomanip>

Emprestimo::Emprestimo(shared_ptr<Livro> livro, int dias) {
    this->livro_ = livro;
    this->data_emprestimo_ = std::chrono::system_clock::now();
    this->prazo_ = data_emprestimo_ + std::chrono::hours(24 * dias);
    this->notificacao_ = "";
}

shared_ptr<Livro> Emprestimo::getLivro() {
    return this->livro_;
}

const string Emprestimo::getPrazo() {
    std::time_t prazo_time = std::chrono::system_clock::to_time_t(prazo_);
    std::tm prazo_tm = *std::localtime(&prazo_time);
    
    std::ostringstream prazo_stream;
    prazo_stream << std::put_time(&prazo_tm, "%d/%m/%Y");
    
    return prazo_stream.str();
}

void Emprestimo::verificaAtraso() {
    this->atrasado_ = std::chrono::system_clock::now() > this->prazo_;
}

const string Emprestimo::getNotificacao() {
    if(this->getAtraso()) {
        this->notificacao_ = "Livro " + this->livro_->getTitulo() + " esta atrasado, data de devolucao foi " + this->getPrazo();
    }
    return this->notificacao_;
}

const bool Emprestimo::getAtraso() {
    this->verificaAtraso();
    return this->atrasado_;
}