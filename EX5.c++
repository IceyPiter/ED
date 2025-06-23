#include <iostream>
#include <string>

class NoTarefa {
public:
    std::string descricao;
    NoTarefa* proximo;

    NoTarefa(std::string desc) : descricao(desc), proximo(nullptr) {}
};

class ListaTarefas {
private:
    NoTarefa* cabeca;

public:
    ListaTarefas() : cabeca(nullptr) {}

    ~ListaTarefas() {
        NoTarefa* atual = cabeca;
        while (atual != nullptr) {
            NoTarefa* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        cabeca = nullptr;
    }

    void adicionarTarefa(const std::string& descricao) {
        NoTarefa* novoNo = new NoTarefa(descricao);
        if (cabeca == nullptr) {
            cabeca = novoNo;
        } else {
            NoTarefa* atual = cabeca;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novoNo;
        }
        std::cout << "Tarefa \"" << descricao << "\" adicionada." << std::endl;
    }

    void removerTarefa(const std::string& descricao) {
        if (cabeca == nullptr) {
            std::cout << "A lista de tarefas está vazia." << std::endl;
            return;
        }

        if (cabeca->descricao == descricao) {
            NoTarefa* temp = cabeca;
            cabeca = cabeca->proximo;
            delete temp;
            std::cout << "Tarefa \"" << descricao << "\" removida." << std::endl;
            return;
        }

        NoTarefa* atual = cabeca;
        NoTarefa* anterior = nullptr;
        while (atual != nullptr && atual->descricao != descricao) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual != nullptr) {
            anterior->proximo = atual->proximo;
            delete atual;
            std::cout << "Tarefa \"" << descricao << "\" removida." << std::endl;
        } else {
            std::cout << "Tarefa \"" << descricao << "\" não encontrada na lista." << std::endl;
        }
    }

    void listarTarefas() const {
        if (cabeca == nullptr) {
            std::cout << "A lista de tarefas está vazia." << std::endl;
            return;
        }
        std::cout << "Lista de Tarefas:" << std::endl;
        NoTarefa* atual = cabeca;
        int i = 1;
        while (atual != nullptr) {
            std::cout << i++ << ". " << atual->descricao << std::endl;
            atual = atual->proximo;
        }
    }
};


int main() {
    ListaTarefas minhasTarefas;

    minhasTarefas.adicionarTarefa("Comprar mantimentos");
    minhasTarefas.adicionarTarefa("Pagar contas");
    minhasTarefas.adicionarTarefa("Estudar C++");
    minhasTarefas.adicionarTarefa("Fazer exercícios");

    minhasTarefas.listarTarefas();

    minhasTarefas.removerTarefa("Pagar contas");
    minhasTarefas.removerTarefa("Tarefa inexistente");

    minhasTarefas.listarTarefas();

    minhasTarefas.removerTarefa("Comprar mantimentos");
    minhasTarefas.removerTarefa("Fazer exercícios");
    minhasTarefas.removerTarefa("Estudar C++");
    minhasTarefas.removerTarefa("Estudar C++");

    minhasTarefas.listarTarefas();

    return 0;
}
