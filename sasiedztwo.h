#ifndef SASIEDZTWO_H
#define SASIEDZTWO_H

#include "projekt_enum.h"

class Sasiedztwo
{
private:
    RodzajMieszkanca sasiad[3][3];
    RodzajMieszkanca* elementWewnetrzny(Polozenie polozenie);
    static Polozenie losujPolozenie();
public:
    Sasiedztwo(RodzajMieszkanca rodzaj = NIEZNANE);
    void okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj);
    RodzajMieszkanca ktoJestSasiadem(Polozenie polozenie);
    unsigned short ile(RodzajMieszkanca rodzaj) const;
    Polozenie losujSasiada(RodzajMieszkanca rodzaj);
    static void zmienIndeksyWgPolozenia(
            Polozenie polozenie, long& wiersz, long& kolumna);
    static void zmienIndeksyWgPolozenia(
            Polozenie polozenie, unsigned int& wiersz, unsigned int& kolumna);
};

#endif // SASIEDZTWO_H
