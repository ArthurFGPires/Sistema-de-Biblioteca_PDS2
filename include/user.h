#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include <string>

using std::string;

class User {
public:
    User(string login, string senha, int permissao);

    string getLogin();

    int getPermissao();

    bool checarUsuario(string login, string senha);

protected:
    
    string getSenha() {
        return this->senha_;
    }

private:
    string login_;
    string senha_;
    int nivelPermissao_;
};

#endif