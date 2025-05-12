#include <string>
#include "Cliente.h"

// Inicializar um Cliente sem suas informações
Cliente::Cliente(){}

// Inicializar um Cliente com suas informações
Cliente::Cliente(std::string nome, std::string cpf){
    this->nome = nome;
    this->cpf = cpf;
}

// Método que retorna o nome do Cliente
std::string Cliente::getnome() {return this->nome;}

// Método que retorna o cpf do Cliente
std::string Cliente::getcpf(){return this-> cpf;}

// Método para estabelecer o nome e o cpf do Cliente (principalmente se ele foi instanciado sem suas informações)
void Cliente::setnomeecpf(std::string nome, std::string cpf){
    this->nome = nome;
    this->cpf = cpf;
}