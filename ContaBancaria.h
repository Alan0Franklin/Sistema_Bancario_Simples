#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include "Cliente.h"

class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;
public:
    ContaBancaria(int numero, Cliente &titular);
    ContaBancaria(int numero, Cliente &titular, double saldo);
    void depositar(double valor);
    void sacar(double valor);
    void transferir(double valor, ContaBancaria &conta);
    void transferir(double valor, ContaBancaria &conta1, ContaBancaria &conta2);
    void exibirSaldo();
    void exibirInformacoes();
};

#endif