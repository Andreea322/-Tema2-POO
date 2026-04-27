#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <vector>
#include <iostream>

#include "carte.h"
#include "rezervare.h"

class Client;
class Biblioteca {
    protected:
    std::string nume, locatie;
    std::vector<Carte> carti;
    std::vector<Rezervare> rezervari;
    public:
    static int totalBiblioteci;
    static int getTotalBiblioteci();
    Biblioteca(const std::string& nume, const std::string& locatie);
    Biblioteca(const Biblioteca& other);
    Biblioteca& operator=(const Biblioteca& other);
    virtual Biblioteca* clone() const = 0;
    virtual ~Biblioteca()= default;
    virtual void afiseaza(std::ostream& out) const = 0;
    

    friend std::ostream& operator<<(std::ostream& out, const Biblioteca& b);
    void afiseazaRezervari(std::ostream& out) const;
    void print(std::ostream& out) const;
    void adaugaCarte(const Carte& c);
    virtual bool cautaCarte(const std::string& numeCarte) const;
    virtual void afiseazaCarti(std::ostream& out) const;
    void rezervaCarte(const Client& client, const std::string& numeCarte);
    virtual std::string tipBiblioteca() const=0;
};
#endif