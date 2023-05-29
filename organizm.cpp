#include "organizm.h"

Organizm::Organizm(unsigned short dlugoscZycia,
                   unsigned short limitPosilkow,
                   unsigned short kosztPotomka):
    limitPosilkow(limitPosilkow),
    kosztPotomka(kosztPotomka),
    licznikZycia(dlugoscZycia),
    licznikPosilkow(0)
{

}

bool Organizm::posilek() {
    if(glodny()) {
        licznikPosilkow++;
        return true;
    }
    return false;
}

bool Organizm::potomek() {
    if(paczkujacy()) {
        licznikPosilkow -= kosztPotomka;
        return true;
    }
    return false;
}

void Organizm::krokSymulacji() {
    if(zywy())
        licznikZycia--;
}
