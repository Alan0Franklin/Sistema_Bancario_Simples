#include <iostream>
#include "Cliente.h"
#include "ContaBancaria.h"

using namespace std;

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    // Criação de novo cliente
    cout << endl;
    Cliente cliente4("Alan", "444.444.444-44"), cliente5;

    // Adicionando informações ao cliente
    cliente5.setnomeecpf("Isaac", "555.555.555-55");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta4(1004, cliente1, -1);
    ContaBancaria conta5(1005, cliente1);

    // Bruno saca R$200 e tenta sacar R$200 uma segunda vez
    cout << endl;
    conta2.sacar(200);
    conta2.sacar(200);
    // Exibe o saldo atual da conta de Bruno
    conta2.exibirSaldo();

    // Carla deposita R$100 em sua conta
    cout << endl;
    conta3.depositar(100);

    // Carla tenta, primeiramente, transferir R$300 para Ana e, segundamente, transferir R$130 para Ana e Bruno
    conta3.transferir(300, conta1);
    conta3.transferir(260, conta1, conta2);

    // Exibe o saldo atual da conta de Carla
    conta3.exibirSaldo();
    return 0;
}
