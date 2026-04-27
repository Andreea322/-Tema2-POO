#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <ostream>
class Carte {
private:
    std::string nume;
    std::string autor;
    int anulAparitiei;

public:
    Carte(const std::string& nume, const std::string& autor, int an);
    inline std::string getNume() const { return nume; }
    inline std::string getAutor() const { return autor; }
    inline int getAn() const { return anulAparitiei; }
    friend std::ostream& operator<<(std::ostream& out, const Carte& c);
};
#endif