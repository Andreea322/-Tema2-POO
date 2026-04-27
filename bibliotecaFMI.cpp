#include "bibliotecaFMI.h"
#include "biblioteca.h"
BibliotecaFMI::BibliotecaFMI(const std::string& nume, const std::string& locatie) : Biblioteca(nume, locatie) {}
Biblioteca* BibliotecaFMI::clone() const {
    return new BibliotecaFMI(*this);
}
void BibliotecaFMI::afiseaza(std::ostream& out) const{
    out<<"FMI "<<nume<<" - "<<locatie;
}
std::string BibliotecaFMI::tipBiblioteca() const {
    return "Biblioteca FMI";
}