#include "../include/user.h"

User::User(string login, string senha, int permissao)
{
  if (validarSenha(senha))
  {
    login_ = login;
    senha_ = senha;
    nivelPermissao_ = permissao;
  }
}

string User::getLogin()
{
  return login_;
}

int User::getPermissao()
{
  return nivelPermissao_;
}

bool User::checarUsuario(string login, string senha)
{
  return (login == getLogin()) && (senha == getSenha());
}

// Função Auxiliar: Checa se a senha é valida para criar usuario
bool User::validarSenha(const string &senha)
{
  if (senha.size() > 50 || senha.size() < 6)
    return false;

  auto pos_space = senha.find(' ');
  if (pos_space != senha.npos)
    return false;

  auto pos_seq = senha.find("123456");
  if (pos_seq != senha.npos)
    return false;

  return true;
}

User::~User() {}