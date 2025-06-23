#include <iostream>
#include <string>
#include <stdexcept>

class NoMusica {
public:
    std::string titulo;
    std::string artista;
    NoMusica* proximo;

    NoMusica(std::string titulo, std::string artista)
        : titulo(titulo), artista(artista), proximo(nullptr) {}
};

class PlaylistMusicas {
private:
    NoMusica* cabeca;
    NoMusica* cauda;

public:
    PlaylistMusicas() : cabeca(nullptr), cauda(nullptr) {}

    ~PlaylistMusicas() {
        NoMusica* atual = cabeca;
        while (atual != nullptr) {
            NoMusica* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        cabeca = nullptr;
        cauda = nullptr;
    }

    void adicionarMusica(const std::string& titulo, const std::string& artista) {
        NoMusica* novoNo = new NoMusica(titulo, artista);
        if (cabeca == nullptr) {
            cabeca = novoNo;
            cauda = novoNo;
        } else {
            cauda->proximo = novoNo;
            cauda = novoNo;
        }
        std::cout << "Música \"" << titulo << "\" de " << artista << " adicionada à playlist." << std::endl;
    }

    NoMusica tocarProxima() {
        if (cabeca == nullptr) {
            throw std::out_of_range("A playlist está vazia. Nenhuma música para tocar.");
        }

        NoMusica* musicaTocada = cabeca;
        NoMusica retornoMusica = *musicaTocada;
        
        cabeca = cabeca->proximo;
        if (cabeca == nullptr) {
            cauda = nullptr;
        }
        delete musicaTocada;

        std::cout << "Tocando próxima música: \"" << retornoMusica.titulo << "\" de " << retornoMusica.artista << std::endl;
        return retornoMusica;
    }

    void listarMusicas() const {
        if (cabeca == nullptr) {
            std::cout << "A playlist está vazia." << std::endl;
            return;
        }
        std::cout << "Playlist de Músicas:" << std::endl;
        NoMusica* atual = cabeca;
        int i = 1;
        while (atual != nullptr) {
            std::cout << i++ << ". Título: " << atual->titulo << ", Artista: " << atual->artista << std::endl;
            atual = atual->proximo;
        }
    }
};


int main() {
    PlaylistMusicas minhaPlaylist;

    minhaPlaylist.adicionarMusica("Bohemian Rhapsody", "Queen");
    minhaPlaylist.adicionarMusica("Stairway to Heaven", "Led Zeppelin");
    minhaPlaylist.adicionarMusica("Hotel California", "Eagles");

    minhaPlaylist.listarMusicas();

    try {
        minhaPlaylist.tocarProxima();
        minhaPlaylist.tocarProxima();
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    minhaPlaylist.listarMusicas();

    try {
        minhaPlaylist.tocarProxima();
        minhaPlaylist.tocarProxima();
    } catch (const std::out_of_range& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    minhaPlaylist.listarMusicas();

    return 0;
}
