#include "carte.h"
Carte::Carte(const std::string& nume, const std::string& autor, int an) : nume(nume), autor(autor), anulAparitiei(an) {}

std::ostream& operator<<(std::ostream& out, const Carte& c) {
    out << c.nume << " - " << c.autor << " (" << c.anulAparitiei << ")";
    return out;
}