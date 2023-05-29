#ifndef USTAWIENIASYMULACJI_H
#define USTAWIENIASYMULACJI_H
#include <iostream>

class UstawieniaSymulacji
{
public:
    const char
        znakGlon = '*',
        znakGrzyb = '#',
        znakBakteria = '@',
        znakTrup = '+',
        znakNieokreslony = '?',
        znakPustaNisza = '_',
        znakSeparator = ' ';

    unsigned short
        glonZycieMin = 3,
        glonZycieMax = 6,
        glonKosztPotomka = 1,
        glonLimitPosilkow = 6,

        grzybZycieMin = 6,
        grzybZycieMax = 10,
        grzybKosztPotomka = 1,
        grzybLimitPosilkow = 6,

        bakteriaZycieMin = 7,
        bakteriaZycieMax = 13,
        bakteriaKosztPotomka = 2,
        bakteriaLimitPosilkow = 6;

    bool poprawnyZnakNiszy(char znak) const {
        return znak == znakGlon ||
                znak == znakGrzyb ||
                znak == znakBakteria ||
                znak == znakTrup ||
                znak == znakPustaNisza;
    }
    bool poprawnySeparator(char znak) const {
        return znak == znakSeparator;
    }
private:
    UstawieniaSymulacji(){}
    UstawieniaSymulacji(UstawieniaSymulacji&);
public:
    static UstawieniaSymulacji& pobierzUstawienia() {
        static UstawieniaSymulacji ustawienia;
        return ustawienia;
    }
};
#endif // USTAWIENIASYMULACJI_H
