#ifndef SRODOWISKO_H
#define SRODOWISKO_H
#include <string>
#include <sstream>
#include <fstream>
#include "projekt_enum.h"

class Nisza;

class Mieszkaniec;

class Sasiedztwo;

class Srodowisko{
public:
    const unsigned int wiersze, kolumny;
    const unsigned long liczbaNisz;
private:
    Nisza ** nisza;
public:
    static Srodowisko czytajZPliku(std::string nazwaPliku);
    Srodowisko(unsigned int _wiersze, unsigned int _kolumny);
    ~Srodowisko();
    void lokuj(Mieszkaniec * mieszkaniec, unsigned int wiersz, unsigned int kolumna);
    Sasiedztwo ustalSasiedztwo(unsigned int wiersz, unsigned int kolumna) const;
    unsigned long liczba(RodzajMieszkanca rodzaj) const;
    bool martwy();
    void wykonajSkok(unsigned int wiersz, unsigned int kolumna);
    void wykonajAkcje(unsigned int wiersz, unsigned int kolumna);
    void wykonajKrokSymulacji();
    std::string doTekstu() const;
    void operator++(int) { wykonajKrokSymulacji(); }
    bool operator!() { return !martwy(); }

};
std::ostream & operator<<(std::ostream & strumien, const Srodowisko & srodowisko);
#endif //SRODOWISKO_H
