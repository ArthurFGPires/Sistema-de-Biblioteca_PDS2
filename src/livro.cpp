#include "../include/livro.h"

int Livro::proximo_ID = 10001;

Livro::Livro(string titulo, string autor, Genero genero)
    : titulo_(titulo), autor_(autor), genero_(genero), emprestado_(false), id_(proximo_ID++){}

string Livro::getTitulo()
{
  return titulo_;
}

string Livro::getAutor()
{
  return autor_;
}

Genero Livro::getGenero()
{
  return genero_;
}

int Livro::getId()
{
  return id_;
}

bool Livro::getEmprestado()
{
  return emprestado_;
}

void Livro::emprestar()
{
  emprestado_ = true;
}

void Livro::devolucao()
{
  emprestado_ = false;
}

std::ostream &operator<<(std::ostream &out, Livro &livro)
{
  out << "Titulo: " << livro.getTitulo() << "\tAutor:" << livro.getAutor() << "\tGenêro: "
      << livro.generoParaString(livro.getGenero()) << "\tID: " << livro.getId();
  return out;
}

std::string Livro::generoParaString(Genero genero)
{
  switch (genero)
  {
  case Genero::FICCAO:
    return "Ficção";
  case Genero::DRAMA:
    return "Drama";
  case Genero::SUSPENSE:
    return "Suspense";
  case Genero::ROMANCE:
    return "Romance";
  case Genero::NOVELA:
    return "Novela";
  case Genero::CIENTIFICO:
    return "Científico";
  case Genero::FANTASIA:
    return "Fantasia";
  default:
    return "Desconhecido";
  }
}