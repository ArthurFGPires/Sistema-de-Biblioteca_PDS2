#ifndef __LIVRO_H__
#define __LIVRO_H__

#include <iostream>

using std::string;


class Livro {
public:
    // Cria um Livro com o Titulo, autor, genero,id aleatório e emprestado = false
    // IMPORTANTE: Gênero pode ser de um dos tipos (Ficcao, Drama, Suspense, Romance, Novela, Cientifico, Fantasia)
    // PRÉ-CONDIÇÃO: titulo e autor devem ser strings não nulas
    Livro(string titulo, string autor, string genero);

    // Retorna o título do livro
    string getTitulo();
    
    // Retorna o nome do Autor do livro
    string getAutor();

    // Retorna o Genero do Livro
    string getGenero();

    // Retorna o código ID do livro
    int getId();

    // Retorna o status de emprestimo do livro
    bool getEmprestado();

    // Altera o status do livro emprestado para verdadeiro
    void emprestar();

    // Altera o status do Livro emprestado para falso
    void devolucao();

private:
    string titulo_;
    string autor_;
    string genero_;
    int id_;
    bool emprestado_;

    static int proximo_ID;
};

#endif