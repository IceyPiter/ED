#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Documento {
public:
    std::string titulo;
    int paginas;
    int prioridade;

    Documento(std::string titulo, int paginas, int prioridade)
        : titulo(titulo), paginas(paginas), prioridade(prioridade) {}

    void exibir() const {
        std::cout << "Titulo: " << titulo << ", Paginas: " << paginas << ", Prioridade: " << prioridade << std::endl;
    }
};

struct CompareDocumento {
    bool operator()(const Documento& d1, const Documento& d2) {
        return d1.prioridade > d2.prioridade;
    }
};

class FilaImpressao {
private:
    std::priority_queue<Documento, std::vector<Documento>, CompareDocumento> fila;

public:
    void adicionarDocumento(const std::string& titulo, int paginas, int prioridade) {
        Documento novoDocumento(titulo, paginas, prioridade);
        fila.push(novoDocumento);
        std::cout << "Documento \"" << titulo << "\" adicionado a fila de impressao com prioridade " << prioridade << "." << std::endl;
    }

    void imprimirProximo() {
        if (!fila.empty()) {
            Documento docImpresso = fila.top();
            fila.pop();
            std::cout << "Imprimindo documento: ";
            docImpresso.exibir();
        } else {
            std::cout << "A fila de impressão está vazia." << std::endl;
        }
    }

    void listarDocumentos() const {
        if (fila.empty()) {
            std::cout << "Nenhum documento na fila de impressao." << std::endl;
            return;
        }
        std::cout << "Documentos na fila de impressao (por prioridade):" << std::endl;
        std::priority_queue<Documento, std::vector<Documento>, CompareDocumento> temp_fila = fila;
        while (!temp_fila.empty()) {
            temp_fila.top().exibir();
            temp_fila.pop();
        }
    }
};


int main() {
    FilaImpressao impressora;

    impressora.adicionarDocumento("Relatorio Mensal", 20, 2);
    impressora.adicionarDocumento("Urgente - CEO", 5, 1);
    impressora.adicionarDocumento("Foto de Ferias", 1, 3);
    impressora.adicionarDocumento("Apresentacao", 15, 2);

    impressora.listarDocumentos();

    impressora.imprimirProximo();
    impressora.imprimirProximo();

    impressora.listarDocumentos();

    impressora.imprimirProximo();
    impressora.imprimirProximo();
    impressora.imprimirProximo();

    return 0;
}
