#include "client.h"        
#include "rezervare.h"
#include "biblioteca.h"
#include "exceptii.h"
#include "carte.h"


int Biblioteca::totalBiblioteci = 0;

Biblioteca::Biblioteca(const std::string& nume, const std::string& locatie)
    : nume(nume), locatie(locatie) {
    totalBiblioteci++;
}

Biblioteca::Biblioteca(const Biblioteca& other) : nume(other.nume), locatie(other.locatie), carti(other.carti),  rezervari(other.rezervari) {}



Biblioteca& Biblioteca::operator=(const Biblioteca& other) {
    if (this != &other) {
        nume = other.nume;
        locatie = other.locatie;
        carti = other.carti;
        rezervari = other.rezervari;
    }
    return *this;
}

void Biblioteca::print(std::ostream& out) const {
    afiseaza(out); 
}
std::ostream& operator<<(std::ostream& out, const Biblioteca& b) {
    b.print(out);  
    return out;
}
void Biblioteca::afiseazaRezervari(std::ostream& out) const {
    out << "Rezervari in biblioteca " << nume << ":\n";
    for (const auto& r : rezervari) {
        out << r << "\n";
    }
}
void Biblioteca::adaugaCarte(const Carte& c) {
    carti.push_back(c);
}
bool Biblioteca::cautaCarte(const std::string& numeCarte) const{
    for (const auto& c : carti) {
        if(c.getNume()== numeCarte) {
            return true;
        }
    }
    return false;
}

void Biblioteca::rezervaCarte(const Client& client, const std::string& numeCarte) {
    if (client.getNume().empty()) {
        throw RezervareInvalida();
    }

    if (!cautaCarte(numeCarte)){
        throw CarteInexistenta(numeCarte);
    }

    for (const auto& r : rezervari) {
        if (r.getCarte() == numeCarte) {
            throw CarteDejaRezervata(numeCarte);
        }
    }

    Rezervare r(client, numeCarte, nume);
    rezervari.push_back(r);
    
}
void Biblioteca::afiseazaCarti(std::ostream& out) const {
    out<< "Cartile din biblioteca "<<nume<<": "<<std::endl;
    for(const auto& c : carti) {
        out<<c<<" ";
    }
}

int Biblioteca::getTotalBiblioteci() {
    return totalBiblioteci;
}
