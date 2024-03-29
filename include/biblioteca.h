#ifndef __BIBLIOTECA_H__
#define __BIBLIOTECA_H__

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <map>

#include "livro.h"
#include "user.h"
#include "emprestimo.h"
#include "erro.h"

using std::list;
using std::shared_ptr;
using std::string;
using std::vector;

class Biblioteca
{
public:
  // Cria uma biblioteca vazia
  Biblioteca();

  // Adiciona um livro na lista de livros da biblioteca
  void adicionarLivro(shared_ptr<Livro> livro, User &user);

  // Remove um livro da biblioteca, só pode ser utilizada por um funcionário
  void removerLivro(const int id, User &user);

  // retorna um list de ponteiros para todos os livros disponiveis da biblioteca
  list<shared_ptr<Livro>> listarLivros();

  // Retorna um list de ponteiros para livros com o titulo passado como parametro
  list<shared_ptr<Livro>> listarLivrosTitulo(const string &titulo);

  // Lista todos os livros do genero presentes na biblioteca
  // IMPORTANTE: Se o gênero do livro foi inserido incorretamente no construtor o livro não será listado
  list<shared_ptr<Livro>> listarLivrosGenero(const string &genero);

  // retorna um list com ponteiros para todos os livros do autor presentes na biblioteca
  list<shared_ptr<Livro>> listarLivrosAutor(const string &autor);

  // retorna um ponteiro para o Livro na biblioteca de acordo com o titulo
  // Caso o livro não esteja na biblioteca retorna um ponteiro nulo
  shared_ptr<Livro> buscarLivro(const string &titulo, const string &autor);

  // retorna um ponteiro para o Livro na biblioteca de acordo com o ID
  // Caso o livro não esteja na biblioteca retorna um ponteiro nulo
  shared_ptr<Livro> buscarLivro(const int id);

  // Empresta um livro para o Usuario especificado
  // Recebe o titulo e o autor para encontrar o livro
  shared_ptr<Emprestimo> emprestarLivro(const string &titulo, const string &autor);

  // Empresta um livro para o Usuario especificado
  // Recebe o id para encontrar o livro
  shared_ptr<Emprestimo> emprestarLivro(const int id);

private:
  list<shared_ptr<Livro>> livros_;
};

#endif