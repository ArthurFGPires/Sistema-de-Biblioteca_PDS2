#include "../include/funcionario.h"

Funcionario::Funcionario(const string &login, const string &senha, Biblioteca &biblioteca)
    : User(login, senha, 1), biblioteca_(biblioteca) {}

void Funcionario::adicionarLivro(shared_ptr<Livro> livro)
{
  try
  {
    biblioteca_.adicionarLivro(livro, *this);
  }
  catch (const Erro &e)
  {
    std::cout << e.what() << std::endl;
    std::cin.get();
  }
}

void Funcionario::removerLivro(const int id)
{
  try
  {
    biblioteca_.removerLivro(id, *this);
  }
  catch (const Erro &e)
  {
    std::cout << e.what() << std::endl;
    std::cin.get();
  }
}