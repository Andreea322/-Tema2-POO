#ifndef CLIENT_H
#define CLIENT_H

#include <string>
class Client {
private:
    std::string nume;
    std::string prenume;
    std::string telefon;

public:
    Client(const std::string& nume, const std::string& prenume, const std::string& telefon);
    inline std::string getNume() const { return nume; }
    inline std::string getPrenume() const { return prenume; }
};
#endif