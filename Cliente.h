#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private: 
    std::string nome;
    std::string cpf;
public:
    Cliente();
    Cliente(std::string nome, std::string cpf);
    std::string getnome();
    std::string getcpf();
    void setnomeecpf(std::string nome, std::string cpf);
};

#endif