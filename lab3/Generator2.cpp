#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
Generator2::Generator2(int iPoczatek, int iKoniec, unsigned long long seed, unsigned long long mnoznik, unsigned long long add, unsigned long long modul, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->setNazwa(strNazwaGeneratora);
    this->setSeed(seed);
    this->mnoznik = mnoznik;
    this->add = add;
    this->modul = modul;
    this->x = getSeed(); 
}


Generator2::~Generator2()
{

}

// ---------------------------------------------------------
unsigned long long Generator2::LCG(unsigned long long mnoznik, unsigned long long  seed, unsigned long long modul)
{

    unsigned long long b, n, r;
 
    r = 0;
    n = 1;
    b = 1;

    while (n <= 64)
    {
        if ((mnoznik & b) != 0)
        r = (r + x) % modul;
        x = (x + x) % modul;
        b *= 2;
        n++;
    }
 
    return r;
}


void Generator2::losuj()
{
	x = (LCG(mnoznik, x, modul) + add) % modul;

    this->iWylosowana = iPoczatek + (x % (iKoniec - iPoczatek + 1));
}

// ---------------------------------------------------------
// ---------------------------------------------------------