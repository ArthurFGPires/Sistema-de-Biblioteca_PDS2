#pragma

#include <iostream>
#include "../include/livro.h"

using std::string;

int Livro::proximo_ID = 10001;

Livro::Livro(string titulo, string autor, string genero) {
    this->titulo_ = titulo;
    this->autor_ = autor;
    this->genero_ = genero;
    this->emprestado_ = false;
    this->id_ = proximo_ID;
    proximo_ID++;
}


string Livro::get_Titulo() {
    return this->titulo_;
}

string Livro::get_Autor() {
    return this->autor_;
}

string Livro::get_Genero() {
    return this->genero_;
}

int Livro::get_Id() {
    return this->id_;
}

bool Livro::get_emprestado() {
    return this->emprestado_;
}
