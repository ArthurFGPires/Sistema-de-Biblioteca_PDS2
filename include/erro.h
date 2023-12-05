#ifndef __ERRO_H__
#define __ERRO_H__

#include <iostream>
#include <exception>

class Erro : public std::exception
{
private:
  std::string mensagem_;

public:
  Erro(const std::string &mensagem) : mensagem_(mensagem) {}

  const char *what() const noexcept override
  {
    return mensagem_.c_str();
  }
};

#endif