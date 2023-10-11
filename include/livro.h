#pragma

#include <iostream>

using std::string;


class Livro {
public:
    // Cria um Livro com o Titulo, autor, genero,id aleatório e emprestado = false
    // IMPORTANTE: Gênero pode ser de um dos tipos (Ficcao, Drama, Suspense, Romance, Novela, Cientifico, Fantasia)
    // PRÉ-CONDIÇÃO: titulo e autor devem ser strings não nulas
    Livro(string titulo, string autor, string genero);

    // Retorna o título do livro
    string get_Titulo();
    
    // Retorna o nome do Autor do livro
    string get_Autor();

    // Retorna o Genero do Livro
    string get_Genero();

    // Retorna o código ID do livro
    int get_Id();

    // Retorna o status de emprestimo do livro
    bool get_emprestado();

private:
    string titulo_;
    string autor_;
    string genero_;
    int id_;
    bool emprestado_;

    static int proximo_ID;
};