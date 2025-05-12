# Projeto: Sistema_Bancario_Simples

Um programa em C++ que simula um sistema bancário simples, incluindo classes para Clientes e Contas Bancárias, e com ações de depósito, saque e transferência implementadas.

---

## Sumário

- [1. Estrutura](#1-estrutura)
- [2. Descrição das Classes](#2-descricao_das_classes)
- [3. Como Compilar e Executar](#3-como_compilar_e_executar)

---

## Estrutura <a name="1-estrutura"></a>
```
Sistema_Bancario_Simples/
├── .gitignore
├── Cliente.cpp
├── Cliente.h
├── ContaBancaria.cpp
├── ContaBancaria.h
├── Makefile
├── README.md
└── main.cpp
```

## Descrição das Classes <a name="2-descricao_das_classes"></a>

### Cliente

Classe responsável por armazenar informações básicas de um cliente:

- `nome`: String correspondente ao nome do cliente.
- `cpf`: String correspondente CPF do cliente.

Construtores:
- `Cliente()`: Inicializa o cliente sem informações.
- `Cliente(std::string nome, std::string cpf)`: Inicializa o cliente com `nome` e `cpf` já atribuídos.

Métodos:
- `getnome()`: Retorna o `nome`.
- `getcpf()`: Retorna o `cpf`.
- `setnomeecpf(string nome, string cpf)`: Recebe um nome e um cpf e redefine o `nome` e o `cpf` do cliente com esses parâmetros.

### ContaBancaria
Classe que representa uma conta bancária e possui um objeto da classe `Cliente`:
- `numero`: Inteiro correspondente ao número da conta.
- `saldo`: Valor flutuante correspondente ao saldo da conta.
- `titular`: Cliente correspondente ao titular da conta.

Construtores:
- `ContaBancaria(int numero, Cliente titular)`: Inicializa a conta com `numero` e `titular` já atribuídos.
- `ContaBancaria(int numero, Cliente titular, double saldo)`: Inicializa a conta com `numero`, `titular` e `saldo` já atribuídos.

Métodos:
- `depositar(double valor)`: Deposita um valor, aumentando o `saldo`, e se o valor for nulo ou negativo, não realiza a ação. Ambos os casos são informados na saída.
- `sacar(double valor)`: Saca um valor, diminuido o `saldo`, e se o valor for negativo ou a conta não tiver saldo suficiente, não realiza a ação. Ambos os casos são informados na saída.
- `transferir(double valor, ContaBancaria conta)`: Transfere um valor de uma conta para outra, aumentando o `saldo` da conta recebida como parâmetro e diminuindo o `saldo` da conta que utilizou o método, e se o valor for nulo ou negativo, não finaliza a ação. Ambos os casos são informados na saída.
- `transferir(double valor, ContaBancaria conta1, ContaBancaria conta2)`: Transfere um valor distribuído igualmente de uma conta para duas outras, aumentando o `saldo` das duas contas recebidas como parâmetros e diminuindo o `saldo` da conta que utilizou o método, e se o valor for nulo ou negativo, não finaliza a ação. Ambos os casos são informados na saída.
- `exibirSaldo()`: Exibe na saída o `saldo`.
- `exibirInformacoes()`: Exibe na saída todas as informações da conta (`nome` e `cpf` do `titular`, `numero` e `saldo`).

## Como Compilar e Executar <a name="3-como_compilar_e_executar"></a>

1. Compile o projeto com o `g++`, e com ajuda do Makefile:

```bash
make
```

2. Execute o programa:
```bash
./Sistema_Bancario_Simples
```
