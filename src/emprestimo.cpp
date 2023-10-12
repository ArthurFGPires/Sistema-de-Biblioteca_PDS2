#include "../include/emprestimo.h"

#include <string>
#include <iomanip>

Emprestimo::Emprestimo(Livro* livro, int dias = 7) {
    this->livro_ = livro;
    this->data_emprestimo_ = std::chrono::system_clock::now();
    this->prazo_ = data_emprestimo_ + std::chrono::hours(24 * dias);
    this->notificacao = "";
}

Livro* Emprestimo::getLivro() {
    return this->livro_;
}

const string Emprestimo::getPrazo() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    
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
        return "Livro " + this->livro_->getTitulo() + " esta atrasado, data de devolucao foi " + this->getPrazo();
    }
    return "";
}

const bool Emprestimo::getAtraso() {
    return this->atrasado_;
}