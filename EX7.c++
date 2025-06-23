#include <iostream>
#include <string>

class NoFoto {
public:
    std::string nomeArquivo;
    std::string descricao;
    NoFoto* proximo;
    NoFoto* anterior;

    NoFoto(std::string nome, std::string desc = "")
        : nomeArquivo(nome), descricao(desc), proximo(nullptr), anterior(nullptr) {}
};

class GaleriaFotos {
private:
    NoFoto* cabeca;
    NoFoto* cauda;
    NoFoto* fotoAtual;

public:
    GaleriaFotos() : cabeca(nullptr), cauda(nullptr), fotoAtual(nullptr) {}

    ~GaleriaFotos() {
        NoFoto* atual = cabeca;
        while (atual != nullptr) {
            NoFoto* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        cabeca = nullptr;
        cauda = nullptr;
        fotoAtual = nullptr;
    }

    void adicionarFoto(const std::string& nomeArquivo, const std::string& descricao = "") {
        NoFoto* novaFoto = new NoFoto(nomeArquivo, descricao);
        if (cabeca == nullptr) {
            cabeca = novaFoto;
            cauda = novaFoto;
            fotoAtual = novaFoto;
        } else {
            cauda->proximo = novaFoto;
            novaFoto->anterior = cauda;
            cauda = novaFoto;
        }
        std::cout << "Foto \"" << nomeArquivo << "\" adicionada à galeria." << std::endl;
    }

    void proximaFoto() {
        if (fotoAtual == nullptr) {
            std::cout << "A galeria está vazia." << std::endl;
        } else if (fotoAtual->proximo != nullptr) {
            fotoAtual = fotoAtual->proximo;
            std::cout << "Avançando para a próxima foto: " << fotoAtual->nomeArquivo << std::endl;
        } else {
            std::cout << "Esta é a última foto na galeria." << std::endl;
        }
    }

    void fotoAnterior() {
        if (fotoAtual == nullptr) {
            std::cout << "A galeria está vazia." << std::endl;
        } else if (fotoAtual->anterior != nullptr) {
            fotoAtual = fotoAtual->anterior;
            std::cout << "Voltando para a foto anterior: " << fotoAtual->nomeArquivo << std::endl;
        } else {
            std::cout << "Esta é a primeira foto na galeria." << std::endl;
        }
    }

    void exibirFotoAtual() const {
        if (fotoAtual != nullptr) {
            std::cout << "Foto atual: " << fotoAtual->nomeArquivo;
            if (!fotoAtual->descricao.empty()) {
                std::cout << " (" << fotoAtual->descricao << ")";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Nenhuma foto para exibir (galeria vazia)." << std::endl;
        }
    }

    void listarTodasAsFotos() const {
        if (cabeca == nullptr) {
            std::cout << "Galeria vazia." << std::endl;
            return;
        }
        std::cout << "Fotos na galeria:" << std::endl;
        NoFoto* atual = cabeca;
        int i = 1;
        while (atual != nullptr) {
            std::cout << i++ << ". " << atual->nomeArquivo;
            if (!atual->descricao.empty()) {
                std::cout << " (" << atual->descricao << ")";
            }
            std::cout << (atual == fotoAtual ? " (ATUAL)" : "") << std::endl;
            atual = atual->proximo;
        }
    }
};


int main() {
    GaleriaFotos minhaGaleria;

    minhaGaleria.adicionarFoto("paisagem.jpg", "Bela paisagem montanhosa");
    minhaGaleria.adicionarFoto("por_do_sol.png", "Pôr do sol na praia");
    minhaGaleria.adicionarFoto("cidade.jpeg", "Vista aérea da cidade");
    minhaGaleria.adicionarFoto("animal.gif", "Gatinho fofo");

    minhaGaleria.exibirFotoAtual();

    minhaGaleria.proximaFoto();
    minhaGaleria.proximaFoto();
    minhaGaleria.exibirFotoAtual();

    minhaGaleria.fotoAnterior();
    minhaGaleria.exibirFotoAtual();

    minhaGaleria.proximaFoto();
    minhaGaleria.proximaFoto();
    minhaGaleria.proximaFoto();
    minhaGaleria.exibirFotoAtual();

    minhaGaleria.fotoAnterior();
    minhaGaleria.fotoAnterior();
    minhaGaleria.fotoAnterior();
    minhaGaleria.fotoAnterior();
    minhaGaleria.exibirFotoAtual();

    minhaGaleria.listarTodasAsFotos();

    return 0;
}
