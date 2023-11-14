#ifndef __EMPRESTIMO_H__
#define __EMPRESTIMO_H__

#include "biblioteca.h"
#include "livro.h"

#include <chrono>
#include <memory>

using std::shared_ptr;

class Emprestimo {
public:
    // Cria um novo empréstimo de um determinado livro 
    // Por padrão da um prazo de 7 dias para devolução
    // Caso o necessite que o empréstimo seja proolongado, crie um novo emprestimo
    // PRÉ-CONDIÇÃO: dias deve ser maior que 0
    Emprestimo(shared_ptr<Livro> livro, int dias = 7);

    // Retorna o livro referente ao emprestimo
    shared_ptr<Livro> getLivro();

    // Retorna o prazo de entrega do livro
    const string getPrazo();

    // Retorna uma string referente a notificação
    // Se o livro não estiver atrasado retorna uma string vazia
    const string getNotificacao();

    //Verifica se o livro está atrasado
    void verificaAtraso();

    // Retorna se o livro está atrasado ou não
    const bool getAtraso();

private:
    shared_ptr<Livro> livro_;
    std::chrono::system_clock::time_point prazo_;
    string notificacao_;
    bool atrasado_;
};

#endif