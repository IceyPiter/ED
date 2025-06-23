#include <iostream>
#include <queue>
#include <string>

class Cliente {
public:
    std::string nome;
    int senha;

    Cliente(std::string nome, int senha) : nome(nome), senha(senha) {}

    void exibir() const {
        std::cout << "Nome: " << nome << ", Senha: " << senha << std::endl;
    }
};

class FilaBanco {
private:
    std::queue<Cliente> fila;
    int proxima_senha;

public:
    FilaBanco() : proxima_senha(1) {}

    void entrarNaFila(const std::string& nome) {
        Cliente novoCliente(nome, proxima_senha++);
        fila.push(novoCliente);
        std::cout << nome << " entrou na fila com a senha: " << novoCliente.senha << std::endl;
    }

    void atenderProximo() {
        if (!fila.empty()) {
            Cliente clienteAtendido = fila.front();
            fila.pop();
            std::cout << "Atendendo cliente: ";
            clienteAtendido.exibir();
        } else {
            std::cout << "A fila do banco está vazia." << std::endl;
        }
    }

    int tamanhoFila() const {
        return fila.size();
    }
};


int main() {
    FilaBanco banco;

    banco.entrarNaFila("Piter");
    banco.entrarNaFila("Gabe");
    banco.entrarNaFila("Thigas");

    std::cout << "Tamanho atual da fila: " << banco.tamanhoFila() << std::endl;

    banco.atenderProximo();
    banco.atenderProximo();

    std::cout << "Tamanho atual da fila: " << banco.tamanhoFila() << std::endl;

    banco.entrarNaFila("Daniel");
    banco.atenderProximo();
    banco.atenderProximo();
    banco.atenderProximo();

    return 0;
}
