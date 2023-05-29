#include "nisza.h"

Nisza::Nisza(): lokator(nullptr){}

Nisza::Nisza(Nisza& innaNisza) {
    if(innaNisza.zajeta()) {
        lokator = innaNisza.lokator;
        innaNisza.lokator = nullptr;
    }
    else
        lokator = nullptr;
}

Nisza::~Nisza() {
    if(lokator != nullptr) delete lokator;
}

Nisza& Nisza::operator=(Nisza& innaNisza) {
    Mieszkaniec* tmp = lokator;
    lokator = innaNisza.lokator;
    innaNisza.lokator = tmp;
    return *this;
}

void Nisza::przyjmijLokatora(Mieszkaniec* lokatorBezdomny) {
    if(!zajeta()) {
        lokator = lokatorBezdomny;
        lokatorBezdomny = nullptr;
    }
}

Mieszkaniec* Nisza::oddajLokatora() {
    Mieszkaniec* tmp = nullptr;
    if(zajeta()) {
        tmp = lokator;
        lokator  = nullptr;
    }
    return tmp;
}

bool Nisza::lokatorZywy() const
{
    if(zajeta()) {
        RodzajMieszkanca r = lokator->kimJestes();
        return r==GLON || r==GRZYB || r==BAKTERIA;
    }
    else return false;
}

char Nisza::jakiSymbol() const
{
    if(!zajeta()) return UstawieniaSymulacji::pobierzUstawienia().znakPustaNisza;
    else return lokator->jakiSymbol();
}
