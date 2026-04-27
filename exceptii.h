#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>
class BibliotecaException : public std::runtime_error {
public:
    explicit BibliotecaException(const std::string& msg)
        : std::runtime_error(msg) {}
};
class CarteInexistenta : public BibliotecaException {
public:
    explicit CarteInexistenta(const std::string& numeCarte)
        : BibliotecaException("Cartea nu exista: " + numeCarte) {}
};
class RezervareInvalida : public BibliotecaException {
public:
    RezervareInvalida()
        : BibliotecaException("Rezervare invalida!") {}
};
class CarteDejaRezervata : public BibliotecaException {
public:
    CarteDejaRezervata(const std::string& numeCarte)
        : BibliotecaException("Cartea este deja rezervata: " + numeCarte) {}
};
#endif