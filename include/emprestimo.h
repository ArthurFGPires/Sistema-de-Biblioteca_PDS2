#ifndef __EMPRESTIMO_H__
#define __EMPRESTIMO_H__

#include "biblioteca.h"
#include "usuario.h"
#include "livro.h"

#include <chrono>

class Emprestimo {
public:
    // Cria um novo empréstimo de um determinado livro 
    // Por padrão da um prazo de 7 dias para devolução
    // Caso o necessite que o empréstimo seja proolongado, crie um novo emprestimo
    // PRÉ-CONDIÇÃO: dias deve ser maior que 0
    Emprestimo(Livro* livro, int dias = 7);

    // Retorna o livro referente ao emprestimo
    Livro* getLivro();

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
    Livro* livro_;
    std::chrono::system_clock::time_point data_emprestimo_;
    std::chrono::system_clock::time_point prazo_;
    string notificacao;
    bool atrasado_;
};

#endif