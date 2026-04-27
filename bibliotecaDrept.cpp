#include "bibliotecaDrept.h"
#include "biblioteca.h"

BibliotecaDrept::BibliotecaDrept(const std::string& nume, const std::string& locatie) : Biblioteca(nume, locatie) {}

Biblioteca* BibliotecaDrept::clone() const {
    return new BibliotecaDrept(*this);
}

void BibliotecaDrept::afiseaza(std::ostream& out) const{
    out<<"Drept "<<nume<<" - "<<locatie;
}
std::string BibliotecaDrept::tipBiblioteca() const {
    return "Biblioteca Drept";
}
