#include "bibliotecaIstorie.h"
#include "biblioteca.h"
BibliotecaIstorie::BibliotecaIstorie(const std::string& nume, const std::string& locatie) : Biblioteca(nume, locatie) {}
Biblioteca* BibliotecaIstorie::clone() const {
    return new BibliotecaIstorie(*this);
}
void BibliotecaIstorie::afiseaza(std::ostream& out) const{
    out<<"Istorie" <<nume<<" - "<<locatie;
}
std::string BibliotecaIstorie::tipBiblioteca() const {
    return "Biblioteca Istorie";
}