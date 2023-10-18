#include "../include/livro.h"

int Livro::proximo_ID = 10001;

Livro::Livro(string titulo, string autor, Genero genero) {
    titulo_ = titulo;
    autor_ = autor;
    genero_ = genero;
    emprestado_ = false;
    id_ = proximo_ID;
    proximo_ID++;
}

string Livro::getTitulo() {
    return titulo_;
}

string Livro::getAutor() {
    return autor_;
}

Genero Livro::getGenero() {
    return genero_;
}

int Livro::getId() {
    return id_;
}

bool Livro::getEmprestado() {
    return emprestado_;
}

void Livro::emprestar() {
    emprestado_ = true;
}

void Livro::devolucao() {
    emprestado_ = false;
}
