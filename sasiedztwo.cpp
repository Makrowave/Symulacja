#include "sasiedztwo.h"
#include <initializer_list>
#include "generatorlosowy.h"

RodzajMieszkanca *Sasiedztwo::elementWewnetrzny(Polozenie polozenie) {
    switch (polozenie) {
        case P: return &sasiad[1][2];
        case PG: return &sasiad[0][2];
        case G: return &sasiad[0][1];
        case LG: return &sasiad[0][0];
        case L: return &sasiad[1][0];
        case LD: return &sasiad[2][0];
        case D: return &sasiad[2][1];
        case PD: return &sasiad[2][2];
        case NIGDZIE: return nullptr;
    }
    return nullptr;
}

Polozenie Sasiedztwo::losujPolozenie()
{
    unsigned short min=0, max=8;
    return static_cast<Polozenie>(GeneratorLosowy::losujPomiedzy(min, max));
}

Sasiedztwo::Sasiedztwo(RodzajMieszkanca rodzaj)
{
    for(auto i: {0,1,2}) {
        for(auto j: {0,1,2}) {
            sasiad[i][j] = rodzaj;
        }
    }
    sasiad[1][1] = NIEZNANE;
}

void Sasiedztwo::okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj)
{
    if(polozenie!=NIGDZIE)
        *elementWewnetrzny(polozenie) = rodzaj;
}

RodzajMieszkanca Sasiedztwo::ktoJestSasiadem(Polozenie polozenie)
{
    if(polozenie!=NIGDZIE)
        return *elementWewnetrzny(polozenie);
    else
        return NIEZNANE;
}

unsigned short Sasiedztwo::ile(RodzajMieszkanca rodzaj) const
{
    unsigned short licznik = 0;
    for(int i: {0,1,2}) {
        for(int j: {1,2,3}) {
            if(i==1 && j==1)
                continue;
            if(sasiad[i][j]==rodzaj)
                licznik++;
        }
    }
    return licznik;
}

Polozenie Sasiedztwo::losujSasiada(RodzajMieszkanca rodzaj)
{
    if(ile(rodzaj)==0)
        return NIGDZIE;
    else {
        Polozenie polozenie = Sasiedztwo::losujPolozenie();
        while(ktoJestSasiadem(polozenie) != rodzaj)
            polozenie = Sasiedztwo::losujPolozenie();
        return polozenie;
    }
}

void Sasiedztwo::zmienIndeksyWgPolozenia(Polozenie polozenie, long &wiersz, long &kolumna)
{
    if(polozenie==PG || polozenie==P || polozenie==PD)
        kolumna++;
    else if(polozenie==LG || polozenie==L || polozenie==LD)
        kolumna--;

    if(polozenie==PG || polozenie==G || polozenie==LG)
        wiersz--;
    else if(polozenie==PD || polozenie==D || polozenie==LD)
        wiersz++;

}

void Sasiedztwo::zmienIndeksyWgPolozenia(Polozenie polozenie, unsigned int &wiersz, unsigned int &kolumna)
{
    long w = static_cast<long>(wiersz);
    long k = static_cast<long>(kolumna);

    zmienIndeksyWgPolozenia(polozenie, w, k);

    wiersz = static_cast<unsigned int>(w);
    kolumna = static_cast<unsigned int>(k);
}

