#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
Generator2::Generator2(int iPoczatek, int iKoniec, unsigned long seed, unsigned long mnoznik, unsigned long add, unsigned long modul, string strNazwaGeneratora)
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
unsigned long Generator2::LCG(unsigned long mnoznik, unsigned long  seed, unsigned long modul)
{

    unsigned long b, n, r;
 
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