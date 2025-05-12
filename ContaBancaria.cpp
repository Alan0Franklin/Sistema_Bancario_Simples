#include <iostream>
#include "Cliente.h"
#include "ContaBancaria.h"

// Inicializar uma Conta Bancária sem saldo
ContaBancaria::ContaBancaria(int numero, Cliente &titular){
    this->numero = numero;
    this->titular = titular;
    this->saldo = 0;
}

// Inicializar uma Conta Bancária com saldo 
// Mostra mensagem de erro caso haja tentativa de inicializar com saldo negativo
ContaBancaria::ContaBancaria(int numero, Cliente &titular, double saldo){
    this->numero = numero;
    this->titular = titular;
    if (saldo < 0){
        this->saldo = 0;
        std::cout << "Erro: Operação de criar conta com saldo inicial de R$ " << saldo << " da conta " << this->numero << " não cumprida. Motivo: Não pode haver saldo negativo." << std::endl;
    }
    else{this->saldo = saldo;}
}

// Depositar valor na Conta Bancária
// Mostra mensagem de erro caso tente ser depositado valor negativo ou nulo
void ContaBancaria::depositar(double valor){
    if (valor <= 0){
        std::cout << "Erro: Operação de depósito de R$ " << valor << " na conta " << this->numero << " não cumprida. Motivo: Valor negativo ou nulo." << std::endl;
    }
    else{
        this->saldo += valor;
        std::cout << "Depositado: R$ " << valor << " na conta " << this->numero << std::endl;
    }
}

// Sacar valor na Conta Bancária
// Mostra mensagem de erro caso não haja saldo suficiente ou caso tente ser sacado valor negativo
void ContaBancaria::sacar(double valor){
    if (valor <= 0){
        std::cout << "Erro: Operação de sacar de R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Valor negativo ou nulo." << std::endl;
    }
    else if (this->saldo >= valor){
        this->saldo -= valor;
        std::cout << "Sacado: R$ " << valor << " da conta " << this->numero << std::endl;
    }
    else {std::cout << "Erro: Operação de sacar R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Não há saldo suficiente." << std::endl;}
}

// Transferir valor de uma conta para outra
// Mostra mensagem de erro caso não haja saldo suficiente ou caso tente ser transferido valor negativo
void ContaBancaria::transferir(double valor, ContaBancaria &conta){
    if (valor <= 0){
        std::cout << "Erro: Operação de transferir R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Valor negativo ou nulo." << std::endl;
    }
    else if (this->saldo >= valor){
        this->saldo -= valor;
        conta.saldo += valor;
        std::cout << "Transferido: R$ " << valor << " da conta " << this->numero << " para a conta " << conta.numero << std::endl;
    }
    else {std::cout << "Erro: Operação de transferir R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Não há saldo suficiente." << std::endl;}
}

// Transferir valor distribuido igualmente de uma conta para duas outras
// Mostra mensagem de erro caso não haja saldo suficiente ou caso tente ser transferido valor negativo ou nulo
void ContaBancaria::transferir(double valor, ContaBancaria &conta1, ContaBancaria &conta2){
    if (valor <= 0){
        std::cout << "Erro: Operação de transferir R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Valor negativo ou nulo." << std::endl;
    }
    else if (this->saldo >= valor){
        this->saldo -= valor;
        conta1.saldo += valor/2;
        conta2.saldo += valor/2;
        std::cout << "Transferido: R$ " << valor/2 << " para cada conta (" << conta1.numero << " e " << conta2.numero << ") da conta " << this->numero << std::endl;
    }
    else {std::cout << "Erro: Operação de transferir R$ " << valor << " da conta " << this->numero << " não cumprida. Motivo: Não há saldo suficiente." << std::endl;}
}

// Exibir saldo atual da conta
void ContaBancaria::exibirSaldo(){std::cout << "Saldo atual da conta " << this->numero << ": R$ " << this->saldo << std::endl;}

// Exibir todas as informações da conta (Nome do titular, CPF do titular, Número da conta e Saldo atual da conta)
void ContaBancaria::exibirInformacoes(){
    std::cout << "Titular: " << this->titular.getnome() << ", CPF: " << this->titular.getcpf() << std::endl << "Número da Conta: " << this->numero << ", Saldo: R$ " << this->saldo << std::endl;
}
