#ifndef BIBLIOTECAISTORIE_H
#define BIBLIOTECAISTORIE_H

#include "biblioteca.h"

class BibliotecaIstorie : public Biblioteca {
public:
    BibliotecaIstorie(const std::string& nume, const std::string& locatie);

    Biblioteca* clone() const override;
    void afiseaza(std::ostream& out) const override;
    std::string tipBiblioteca() const override;
};

#endif