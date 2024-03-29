#include <iostream>
#include <vector>

// Classe base para a conta banc�ria
class ContaBancaria {
protected:
    double saldo;

public:
    ContaBancaria() : saldo(0) {}

    virtual void sacar(double valor) = 0;
    virtual void depositar(double valor) {
        saldo += valor;
    }

    double getSaldo() const {
        return saldo;
    }
};

// Classes espec�ficas para cada tipo de conta
class ContaCorrente : public ContaBancaria {
public:
    void sacar(double valor) override {
        if (valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$" << valor << " realizado da conta corrente.\n";
        } else {
            std::cout << "Saldo insuficiente na conta corrente.\n";
        }
    }
};

class ContaSalario : public ContaBancaria {
public:
    void sacar(double valor) override {
        if (valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$" << valor << " realizado da conta sal�rio.\n";
        } else {
            std::cout << "Saldo insuficiente na conta sal�rio.\n";
        }
    }
};

// Classe para controle e gerenciamento de contas
class Banco {
private:
    std::vector<ContaBancaria*> contas;

public:
    void adicionarConta(ContaBancaria* conta) {
        contas.push_back(conta);
    }

    void sacarDeTodasContas(double valor) {
        for (auto& conta : contas) {
            conta->sacar(valor);
        }
    }
};

// Implementa��o do Aspecto: Verifica��o de saldo
class VerificacaoDeSaldo {
public:
    void verificarSaldo(Banco& banco, double valor) {
        for (auto& conta : banco.contas) {
            if (valor > conta->getSaldo()) {
                std::cout << "Erro: Saldo insuficiente na conta.\n";
                return;
            }
        }
        banco.sacarDeTodasContas(valor);
    }
};

int main() {
    // Criando inst�ncias de contas
    ContaCorrente contaCorrente;
    ContaSalario contaSalario;

    // Criando o banco e adicionando contas
    Banco banco;
    banco.adicionarConta(&contaCorrente);
    banco.adicionarConta(&contaSalario);

    // Criando o aspecto de verifica��o de saldo
    VerificacaoDeSaldo aspecto;

    // Sacando de todas as contas com verifica��o de saldo
    aspecto.verificarSaldo(banco, 1000);

    // Exibindo saldos ap�s o saque
    std::cout << "Saldo conta corrente: R$" << contaCorrente.getSaldo() << std::endl;
    std::cout << "Saldo conta sal�rio: R$" << contaSalario.getSaldo() << std::endl;

    return 0;
}
