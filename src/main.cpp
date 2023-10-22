#include <iostream>
#include <string>
#include <memory>

#include "../include/livro.h"
#include "../include/biblioteca.h"
#include "../include/usuario.h"
#include "../include/funcionario.h"

using std::shared_ptr;

int main() {
    // Declarações iniciais
    shared_ptr<Livro> livro1 = std::make_shared<Livro>("HP", "J.K.R", Genero::FANTASIA);
    shared_ptr<Livro> livro2 = std::make_shared<Livro>("LOTR", "J.R.R", Genero::FANTASIA);
    shared_ptr<Livro> livro3 = std::make_shared<Livro>("Auto da Barca do Inferno", "Gil Vicente", Genero::DRAMA);

    Biblioteca biblioteca;

    shared_ptr<Funcionario> funcionario = std::make_shared<Funcionario>("adimin", "987654321");

    funcionario->adicionarLivro(livro1, biblioteca);
    funcionario->adicionarLivro(livro2, biblioteca);
    funcionario->adicionarLivro(livro3, biblioteca);
    

    // Testes da Classe Biblioteca
    std::cout << "Listando livros da Biblioteca" << "\n";
    
    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\n";
    std::cout << "Listando livros da Biblioteca de um Autor Especifico" << "\n";

    for(auto l : biblioteca.listarLivrosAutor("J.R.R")) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\n";
    std::cout << "Listando livros da Biblioteca de um Genero Especifico" << "\n";

    for(auto l : biblioteca.listarLivrosGenero(Genero::DRAMA)) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }


    // Testes da Classe Usuario
    shared_ptr<Usuario> usuario = std::make_shared<Usuario>("usuario", "987654321");

    std::cout << "Livro Alugado" << std::endl;
    usuario->alugarLivro(10001, biblioteca);

    std::cout << "\n\n";
    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
   
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\nListando livros da Biblioteca" << "\n";
    

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }   

    std::cout << "\nLivro Alugado" << std::endl;
    usuario->alugarLivro(10003, biblioteca);
    

    std::cout << "\n\n";
    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\nListando livros da Biblioteca" << "\n";

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    usuario->devolverLivro(10001, biblioteca);
    std::cout << "\nLivro Devolvido" << std::endl;


    std::cout << "\n\n";
    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }
    

    std::cout << "\n\nListando livros da Biblioteca" << "\n";
    

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }
    
    std::cout << "\n\nNotificacoes" << "\n";
    for(auto s : usuario->getNotificacoes()) {
        std::cout << s << std::endl;
    }

    return 0;
}