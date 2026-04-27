#ifndef CATALOG_H
#define CATALOG_H

#include <string>
#include <ostream>
#include "biblioteca.h"
class Catalog {
private:
    std::vector<Biblioteca*> biblioteci;

public:
    void adaugaBiblioteca(const Biblioteca* b);

    void cautaCarte(const std::string& numeCarte, std::ostream& out) const;

    void afiseazaBiblioteci(std::ostream& out) const;
    void afiseazaToateRezervarile(std::ostream& out) const;
    void afiseazaRezervariBiblioteca(const std::string& tip, std::ostream& out) const;
    Biblioteca* getBiblioteca(const std::string& tip);
    ~Catalog(); 
};
#endif