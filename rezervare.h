#ifndef REZERVARE_H
#define REZERVARE_H

#include <string>
#include <ostream>

class Client;
class Rezervare {
private:
    std::string numeClient;
    std::string numeCarte;
    std::string biblioteca;

public:
    Rezervare(const Client& client, const std::string& carte, const std::string& biblioteca);
    friend std::ostream& operator<<(std::ostream& out, const Rezervare& r);
    inline std::string getClient() const { return numeClient; }
    inline std::string getCarte() const { return numeCarte; }
    inline std::string getBiblioteca() const { return biblioteca; }
};
#endif