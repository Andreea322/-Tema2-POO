#include "catalog.h"
#include "bibliotecaFMI.h"
#include "bibliotecaDrept.h"
#include "bibliotecaLitere.h"
#include "biblioteca.h"

Catalog::~Catalog() {
    for (auto b : biblioteci)
        delete b;
}

void Catalog::adaugaBiblioteca(const Biblioteca* b) {
    biblioteci.push_back(b->clone());  
}

void Catalog::cautaCarte(const std::string& numeCarte, std::ostream& out) const {
    bool gasit = false;

    for (const auto& b : biblioteci) {
        if (b->cautaCarte(numeCarte)) {
            out << "Gasita in: " << *b << "\n";
            gasit = true;
        }
    }

    if (!gasit) {
        out << "Cartea nu a fost gasita.\n";
    }
}

void Catalog::afiseazaBiblioteci(std::ostream& out) const {
    for (const auto& b : biblioteci) {
        out << *b << "\n";
    }
}
void Catalog::afiseazaToateRezervarile(std::ostream& out) const {
    for (const auto& b : biblioteci) {
        b->afiseazaRezervari(out);
        out << "\n";
    }
}
void Catalog::afiseazaRezervariBiblioteca(const std::string& tip, std::ostream& out) const {
    bool gasit = false;

    for (const auto& b : biblioteci) {

        if (tip == "FMI" && dynamic_cast<BibliotecaFMI*>(b)) {
            out << "\n--- Rezervari FMI ---\n";
            b->afiseazaRezervari(out);
            gasit = true;
        }
        else if (tip == "Drept" && dynamic_cast<BibliotecaDrept*>(b)) {
            out << "\n--- Rezervari Drept ---\n";
            b->afiseazaRezervari(out);
            gasit = true;
        }
        else if (tip == "Litere" && dynamic_cast<BibliotecaLitere*>(b)) {
            out << "\n--- Rezervari Litere ---\n";
            b->afiseazaRezervari(out);
            gasit = true;
        }
    }

    if (!gasit) {
        out << "Biblioteca inexistenta!\n";
    }
}
Biblioteca* Catalog::getBiblioteca(const std::string& tip) {
    for (auto b : biblioteci) {
        if (tip == "FMI" && b->tipBiblioteca() == "Biblioteca FMI")
            return b;

        if (tip == "Drept" && b->tipBiblioteca() == "Biblioteca Drept")
            return b;

        if (tip == "Litere" && b->tipBiblioteca() == "Biblioteca Litere")
            return b;
    }
    return nullptr;
}