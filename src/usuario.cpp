#include "../include/usuario.h"

Usuario::Usuario(const string &login, const string &senha, Biblioteca &biblioteca)
    : User(login, senha, 0), alugados_(), biblioteca_(biblioteca) {}

vector<shared_ptr<Livro>> Usuario::listarAlugados()
{
  vector<std::shared_ptr<Livro>> livrosAlugados;

  for (const auto &emprestimo : alugados_)
  {
    std::shared_ptr<Livro> livro = emprestimo->getLivro();
    livrosAlugados.push_back(livro);
  }

  return livrosAlugados;
}

void Usuario::alugarLivro(const string &titulo, const string &autor)
{
  try
  {
    shared_ptr<Emprestimo> emprestimo = biblioteca_.emprestarLivro(titulo, autor);

    if (emprestimo)
    {
      alugados_.push_back(emprestimo);
    }
  }
  catch (const Erro &erro)
  {
    throw;
  }
}

void Usuario::alugarLivro(const int id)
{
  try
  {
    shared_ptr<Emprestimo> emprestimo = biblioteca_.emprestarLivro(id);

    if (emprestimo)
    {
      alugados_.push_back(emprestimo);
    }
  }
  catch (const Erro &e)
  {
    throw;
  }
}

void Usuario::devolverLivro(const int id)
{
  for (auto it = alugados_.begin(); it != alugados_.end(); ++it)
  {
    if ((*it)->getLivro()->getId() == id)
    {
      (*it)->getLivro()->devolucao();
      alugados_.erase(it);
      return;
    }
  }
  throw Erro("Erro: ID não encontrado na lista de emprestimos");
}

vector<string> Usuario::getNotificacoes()
{
  vector<string> notificacoes;
  for (auto e : alugados_)
  {
    if (e->getNotificacao().size() > 0)
    {
      notificacoes.push_back(e->getNotificacao());
    }
  }

  if (notificacoes.size() == 0)
    notificacoes.push_back("Nenhuma Notificação");

  return notificacoes;
}

vector<string> Usuario::getPrazos()
{
  vector<string> prazos;
  for (auto e : alugados_)
  {
    prazos.push_back(e->getPrazo());
  }

  return prazos;
}