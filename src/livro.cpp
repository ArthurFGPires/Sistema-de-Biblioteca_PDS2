#ifndef __LIVRO_CPP__
#define __LIVRO_CPP__

#include "../include/livro.h"


int Livro::proximo_ID = 10001;

Livro::Livro(string titulo, string autor, string genero) {
    this->titulo_ = titulo;
    this->autor_ = autor;
    this->genero_ = genero;
    this->emprestado_ = false;
    this->id_ = proximo_ID;
    proximo_ID++;
}


string Livro::getTitulo() {
    return this->titulo_;
}

string Livro::getAutor() {
    return this->autor_;
}

string Livro::getGenero() {
    return this->genero_;
}

int Livro::getId() {
    return this->id_;
}

bool Livro::getEmprestado() {
    return this->emprestado_;
}

#endif