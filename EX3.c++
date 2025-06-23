#include <iostream>
#include <deque>
#include <string>

class HistoricoNavegacao {
private:
    std::deque<std::string> historico;
    int indiceAtual;

public:
    HistoricoNavegacao() : indiceAtual(-1) {}

    void visitarSite(const std::string& url) {
        while (historico.size() > indiceAtual + 1) {
            historico.pop_back();
        }
        historico.push_back(url);
        indiceAtual = historico.size() - 1;
        std::cout << "Visitou: " << url << std::endl;
    }

    void voltar() {
        if (indiceAtual > 0) {
            indiceAtual--;
            std::cout << "Voltando para: " << historico[indiceAtual] << std::endl;
        } else {
            std::cout << "Nao ha historico anterior." << std::endl;
        }
    }

    void avancar() {
        if (indiceAtual < static_cast<int>(historico.size()) - 1) {
            indiceAtual++;
            std::cout << "Avançando para: " << historico[indiceAtual] << std::endl;
        } else {
            std::cout << "Nao ha historico posterior." << std::endl;
        }
    }

    void limparHistorico() {
        historico.clear();
        indiceAtual = -1;
        std::cout << "Historico de navegaçao limpo." << std::endl;
    }

    void exibirHistoricoAtual() const {
        if (indiceAtual != -1 && indiceAtual < static_cast<int>(historico.size())) {
            std::cout << "Site atual: " << historico[indiceAtual] << std::endl;
        } else {
            std::cout << "Nenhum site atual (historico vazio ou invalido)." << std::endl;
        }
    }

    void listarTodoHistorico() const {
        if (historico.empty()) {
            std::cout << "Historico vazio." << std::endl;
            return;
        }
        std::cout << "Historico completo:" << std::endl;
        for (size_t i = 0; i < historico.size(); ++i) {
            std::cout << (i == static_cast<size_t>(indiceAtual) ? "-> " : "   ") << historico[i] << std::endl;
        }
    }
};

int main() {
    HistoricoNavegacao nav;

    nav.visitarSite("google.com");
    nav.visitarSite("youtube.com");
    nav.visitarSite("wikipedia.org");

    nav.exibirHistoricoAtual();

    nav.voltar();
    nav.exibirHistoricoAtual();

    nav.voltar();
    nav.exibirHistoricoAtual();

    nav.avancar();
    nav.exibirHistoricoAtual();

    nav.visitarSite("github.com");
    nav.exibirHistoricoAtual();
    nav.avancar();

    nav.listarTodoHistorico();

    nav.limparHistorico();
    nav.exibirHistoricoAtual();

    return 0;
}
