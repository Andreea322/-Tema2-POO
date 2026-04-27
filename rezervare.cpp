#include "rezervare.h"
#include "client.h"

Rezervare::Rezervare(const Client& client, const std::string& carte, const std::string& biblioteca)
    : numeClient(client.getNume() + " " + client.getPrenume()),
      numeCarte(carte),
      biblioteca(biblioteca) {}

std::ostream& operator<<(std::ostream& out, const Rezervare& r) {
    out << r.getClient() << " a rezervat '" 
        << r.getCarte() << "' la " 
        << r.getBiblioteca();
    return out;
}

