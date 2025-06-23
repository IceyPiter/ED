#include <iostream>
#include <string>

class EstadoTexto {
public:
    std::string texto;
    EstadoTexto* proximo;
    EstadoTexto* anterior;

    EstadoTexto(std::string txt) : texto(txt), proximo(nullptr), anterior(nullptr) {}
};

class EditorTexto {
private:
    EstadoTexto* cabeca;
    EstadoTexto* estadoAtual;

public:
    EditorTexto() : cabeca(nullptr), estadoAtual(nullptr) {
        EstadoTexto* novoEstado = new EstadoTexto("");
        cabeca = novoEstado;
        estadoAtual = novoEstado;
        std::cout << "Editor de texto inicializado com texto vazio." << std::endl;
    }

    ~EditorTexto() {
        EstadoTexto* atual = cabeca;
        while (atual != nullptr) {
            EstadoTexto* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        cabeca = nullptr;
        estadoAtual = nullptr;
    }

    void digitar(const std::string& novoTexto) {
        EstadoTexto* temp = estadoAtual->proximo;
        while (temp != nullptr) {
            EstadoTexto* next_to_delete = temp->proximo;
            delete temp;
            temp = next_to_delete;
        }
        estadoAtual->proximo = nullptr;

        EstadoTexto* novoEstado = new EstadoTexto(novoTexto);
        estadoAtual->proximo = novoEstado;
        novoEstado->anterior = estadoAtual;
        estadoAtual = novoEstado;

        std::cout << "Digitado: \"" << novoTexto << "\". Texto atual: \"" << estadoAtual->texto << "\"" << std::endl;
    }

    void undo() {
        if (estadoAtual != nullptr && estadoAtual->anterior != nullptr) {
            estadoAtual = estadoAtual->anterior;
            std::cout << "Desfeito. Texto atual: \"" << estadoAtual->texto << "\"" << std::endl;
        } else {
            std::cout << "Não há mais ações para desfazer." << std::endl;
        }
    }

    void redo() {
        if (estadoAtual != nullptr && estadoAtual->proximo != nullptr) {
            estadoAtual = estadoAtual->proximo;
            std::cout << "Refeito. Texto atual: \"" << estadoAtual->texto << "\"" << std::endl;
        } else {
            std::cout << "Não há mais ações para refazer." << std::endl;
        }
    }

    void exibirTextoAtual() const {
        if (estadoAtual != nullptr) {
            std::cout << "Texto atual no editor: \"" << estadoAtual->texto << "\"" << std::endl;
        } else {
            std::cout << "Editor vazio ou estado inválido." << std::endl;
        }
    }

    void listarHistorico() const {
        if (cabeca == nullptr) {
            std::cout << "Histórico de texto vazio." << std::endl;
            return;
        }
        std::cout << "Histórico de Texto:" << std::endl;
        EstadoTexto* atual = cabeca;
        int i = 0;
        while (atual != nullptr) {
            std::cout << i++ << ". " << atual->texto << (atual == estadoAtual ? " (ATUAL)" : "") << std::endl;
            atual = atual->proximo;
        }
    }
};


int main() {
    EditorTexto editor;

    editor.digitar("Olá mundo.");
    editor.digitar("Olá mundo. Esta é uma linha.");
    editor.digitar("Olá mundo. Esta é uma linha. E esta é a segunda.");

    editor.exibirTextoAtual();

    editor.undo();
    editor.exibirTextoAtual();

    editor.undo();
    editor.exibirTextoAtual();

    editor.redo();
    editor.exibirTextoAtual();

    editor.digitar("Olá mundo. Esta é uma linha. Novo texto adicionado aqui.");
    editor.exibirTextoAtual();

    editor.redo();

    editor.undo();
    editor.exibirTextoAtual();

    editor.listarHistorico();

    return 0;
}
