#include <iostream>
#include <string>
#include <memory>

#include "../include/livro.h"
#include "../include/biblioteca.h"
#include "../include/usuario.h"
#include "../include/funcionario.h"

using std::shared_ptr;

void pausar_e_limpar_tela() {
    std::cout << "\n\nPressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada
    std::cin.get(); // Aguarda o pressionamento de Enter

    // Limpar a tela (aqui, é usado um comando específico para sistemas Unix/Linux)
    #if defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif
    // Para sistemas Windows, você pode usar o comando "cls"
    #ifdef _WIN32
        system("cls");
    #endif
}

int main() {
    // Declarações iniciais
    shared_ptr<Livro> livro1 = std::make_shared<Livro>("HP", "J.K.R", Genero::FANTASIA);
    shared_ptr<Livro> livro2 = std::make_shared<Livro>("LOTR", "J.R.R", Genero::FANTASIA);
    shared_ptr<Livro> livro3 = std::make_shared<Livro>("Auto da Barca do Inferno", "Gil Vicente", Genero::DRAMA);
    shared_ptr<Livro> livro4 = std::make_shared<Livro>("Duna", "Frank Herbert", Genero::DRAMA);
    shared_ptr<Livro> livro5 = std::make_shared<Livro>("Jogos Vorazes", "Suazanna Collins", Genero::FICCAO);


    Biblioteca biblioteca;

    shared_ptr<Funcionario> funcionario = std::make_shared<Funcionario>("adimin", "987654321");

    funcionario->adicionarLivro(livro1, biblioteca);
    funcionario->adicionarLivro(livro2, biblioteca);
    funcionario->adicionarLivro(livro3, biblioteca);
    funcionario->adicionarLivro(livro4, biblioteca);
    funcionario->adicionarLivro(livro5, biblioteca);
    funcionario->removerLivro(livro5->getId(), biblioteca);

    pausar_e_limpar_tela();
    // Testes da Classe Biblioteca
    std::cout << "Listando livros da Biblioteca" << "\n";
    
    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    pausar_e_limpar_tela();
    std::cout << "Listando livros da Biblioteca de um Autor Especifico" << "\n";

    for(auto l : biblioteca.listarLivrosAutor("J.R.R")) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    pausar_e_limpar_tela();
    std::cout << "Listando livros da Biblioteca de um Genero Especifico" << "\n";

    for(auto l : biblioteca.listarLivrosGenero(Genero::DRAMA)) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }


    // Testes da Classe Usuario
    shared_ptr<Usuario> usuario = std::make_shared<Usuario>("usuario", "987654321");

    pausar_e_limpar_tela();
    std::cout << "Livro Alugado" << std::endl;
    usuario->alugarLivro(10001, biblioteca);

    std::cout << "\n";
    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
   
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\nListando livros da Biblioteca" << "\n";
    

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }   

    pausar_e_limpar_tela();
    std::cout << "Livro Alugado" << std::endl;
    usuario->alugarLivro(10003, biblioteca);
    

    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    std::cout << "\n\nListando livros da Biblioteca" << "\n";

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }

    pausar_e_limpar_tela();
    usuario->devolverLivro(10001, biblioteca);
    std::cout << "Livro Devolvido" << std::endl;


    std::cout << "\n";
    std::cout << "Listando Livros alugados pelo Usuario" << std::endl;
    for(auto l : usuario->listarAlugados()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }
    

    std::cout << "\n\nListando livros da Biblioteca" << "\n";
    

    for(auto l : biblioteca.listarLivros()) {
        std::cout << "Titulo: " << l->getTitulo() << "\tAutor: " << l->getAutor() << "\tId: " << l->getId() << std::endl;
    }
    
    pausar_e_limpar_tela();
    std::cout << "Notificacoes" << "\n";
    for(auto s : usuario->getNotificacoes()) {
        std::cout << s << std::endl;
    }

    pausar_e_limpar_tela();

    return 0;
}