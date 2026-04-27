#include "bibliotecaLitere.h"
#include "biblioteca.h"
BibliotecaLitere::BibliotecaLitere(const std::string& nume, const std::string& locatie) : Biblioteca(nume, locatie) {}
Biblioteca* BibliotecaLitere::clone() const {
    return new BibliotecaLitere(*this);
}
void BibliotecaLitere::afiseaza(std::ostream& out) const{
    out<<"Litere "<<nume<<" - "<<locatie;
}
std::string BibliotecaLitere::tipBiblioteca() const {
    return "Biblioteca Litere";
}