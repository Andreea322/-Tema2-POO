#ifndef BIBLIOTECALITERE_H
#define BIBLIOTECALITERE_H

#include <string>
#include <ostream>
#include "biblioteca.h"
class BibliotecaLitere : public Biblioteca {
    public:
    BibliotecaLitere(const std::string& nume, const std::string& locatie);
    Biblioteca* clone() const override ;
    void afiseaza(std::ostream& out) const override;
    std::string tipBiblioteca() const override;

};
#endif