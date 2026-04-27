#ifndef BIBLIOTECADREPT_H
#define BIBLIOTECADREPT_H

#include <string>
#include <ostream>
#include "biblioteca.h"
class BibliotecaDrept : public Biblioteca {
    public:
    BibliotecaDrept(const std::string& nume, const std::string& locatie);
    Biblioteca* clone() const override;
    
    void afiseaza(std::ostream& out) const override;
    std::string tipBiblioteca() const override;

};
#endif
