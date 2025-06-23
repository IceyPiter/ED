#include <iostream>
#include <deque>
#include <string>

class Ticket {
public:
    std::string descricao;
    bool prioritario;

    Ticket(std::string desc, bool prio) : descricao(desc), prioritario(prio) {}

    void exibir() const {
        std::cout << "Ticket: " << descricao << (prioritario ? " (Prioritário)" : " (Normal)") << std::endl;
    }
};

class SistemaTickets {
private:
    std::deque<Ticket> tickets;

public:
    void adicionarTicket(const std::string& descricao, bool prioritario) {
        Ticket novoTicket(descricao, prioritario);
        if (prioritario) {
            tickets.push_front(novoTicket);
            std::cout << "Ticket prioritário \"" << descricao << "\" adicionado ao início da fila." << std::endl;
        } else {
            tickets.push_back(novoTicket);
            std::cout << "Ticket normal \"" << descricao << "\" adicionado ao final da fila." << std::endl;
        }
    }

    void atenderTicket() {
        if (!tickets.empty()) {
            Ticket ticketAtendido = tickets.front();
            tickets.pop_front();
            std::cout << "Atendendo ticket: ";
            ticketAtendido.exibir();
        } else {
            std::cout << "Não há tickets para atender." << std::endl;
        }
    }

    void listarTickets() const {
        if (tickets.empty()) {
            std::cout << "Nenhum ticket na fila." << std::endl;
            return;
        }
        std::cout << "Tickets na fila (do primeiro ao último):" << std::endl;
        for (const auto& ticket : tickets) {
            ticket.exibir();
        }
    }
};


int main() {
    SistemaTickets sistema;

    sistema.adicionarTicket("Resolver problema de rede", false);
    sistema.adicionarTicket("Atendimento urgente CEO", true);
    sistema.adicionarTicket("Instalar novo software", false);
    sistema.adicionarTicket("Chamado crítico servidor", true);

    sistema.listarTickets();

    sistema.atenderTicket();
    sistema.atenderTicket();

    sistema.listarTickets();

    sistema.atenderTicket();
    sistema.atenderTicket();
    sistema.atenderTicket();

    return 0;
}
