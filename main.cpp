#include <iostream>
#include "catalog.h"
#include "bibliotecaFMI.h"
#include "bibliotecaDrept.h"
#include "bibliotecaLitere.h"
#include "client.h"
#include "exceptii.h"
#include "carte.h"
#include "bibliotecaIstorie.h"
#include <fstream>

std::string stergere_(const std::string& text) {
    std::string rezultat = text;
    for (auto& c : rezultat) {
        if (c == '_')
            c = ' ';
    }
    return rezultat;
}

int main() {

    std::cout << "===== Sistem de gestionare a unor biblioteci =====\n";

    Catalog catalog;

    Biblioteca* fmi = new BibliotecaFMI("FMI", "Bucuresti");
    Biblioteca* drept = new BibliotecaDrept("Drept", "Bucuresti");
    Biblioteca* litere = new BibliotecaLitere("Litere", "Bucuresti");
    Biblioteca* istorie = new BibliotecaIstorie("Istorie", "Bucuresti");

    catalog.adaugaBiblioteca(fmi);
    catalog.adaugaBiblioteca(drept);
    catalog.adaugaBiblioteca(litere);
    catalog.adaugaBiblioteca(istorie);

    std::string tip, nume, autor;
    int an;

    while (fin >> tip >> nume >> autor >> an) {
        nume = stergere_(nume);
        autor = stergere_(autor);

        Biblioteca* b = catalog.getBiblioteca(tip);
        if (b)
            b->adaugaCarte(Carte(nume, autor, an));
        else
            std::cout << "Tip necunoscut\n";
    }

    std::cout << "\n--- Biblioteci ---\n";
    catalog.afiseazaBiblioteci(std::cout);

    std::string carte;
    std::cout << "\nIntrodu cartea pe care vrei sa o cauti: ";
    std::cin >> carte;
    carte = stergere_(carte);

    catalog.cautaCarte(carte, std::cout);

    std::string raspuns;
    std::cout << "\nVrei sa faci o rezervare? ";
    std::cin >> raspuns;

    while (raspuns == "Da" || raspuns == "da") {

        std::string numeC, prenumeC, telefon;

        std::cout << "Nume: ";
        std::cin >> numeC;

        std::cout << "Prenume: ";
        std::cin >> prenumeC;

        std::cout << "Telefon: ";
        std::cin >> telefon;

        Client client(numeC, prenumeC, telefon);

        std::string carteRez;
        std::cout << "Introdu cartea dorita: ";
        std::cin >> carteRez;
        carteRez = stergere_(carteRez);

        std::string tipBib;
        std::cout << "Biblioteca (FMI/Drept/Litere): ";
        std::cin >> tipBib;

        try {
            Biblioteca* b = catalog.getBiblioteca(tipBib);

            if (!b)
                throw BibliotecaException("Biblioteca invalida!");

            b->rezervaCarte(client, carteRez);

            std::cout << "Rezervare realizata cu succes!\n";

        } catch (const BibliotecaException& e) {
            std::cout << "Eroare: " << e.what() << "\n";
        }

        std::cout << "\nMai vrei sa faci o rezervare? ";
        std::cin >> raspuns;
    }

    std::string alegere;
    std::cout << "\nDin ce biblioteca vrei sa vezi rezervarile? (FMI/Drept/Litere): ";
    std::cin >> alegere;

    catalog.afiseazaRezervariBiblioteca(alegere, std::cout);

    std::cout << "\n--- Toate rezervarile ---\n";
    catalog.afiseazaToateRezervarile(std::cout);

    std::cout << "\nTotal biblioteci: ";
    std::cout << Biblioteca::getTotalBiblioteci() << "\n";

    return 0;
}

