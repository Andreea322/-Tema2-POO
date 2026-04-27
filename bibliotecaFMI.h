#ifndef BIBLIOTECAFMI_H
#define BIBLIOTECAFMI_H

#include <string>
#include <ostream>
#include "biblioteca.h"
class BibliotecaFMI : public Biblioteca {
    public:
    BibliotecaFMI(const std::string& nume, const std::string& locatie);
    Biblioteca* clone() const override;
    void afiseaza(std::ostream& out) const override;
    std::string tipBiblioteca() const override;

};
#endif