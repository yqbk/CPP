#include "aghInclude.h"



Generator1::Generator1(int iPoczatek, int iKoniec, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->strNazwaGeneratora = strNazwaGeneratora;
    srand(time(NULL));
}

void Generator1::losuj()
{
    this->iWylosowana = rand()%(this->iKoniec - this->iPoczatek) + this->iPoczatek;
}
