#include "aghInclude.h"



Generator1::Generator1(int iPoczatek, int iKoniec, int seed, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->strNazwaGeneratora = strNazwaGeneratora;
    srand(time(seed));
}

Generator1::~Generator1()
{

}

void Generator1::losuj()
{
    this->iWylosowana = rand()%(this->iKoniec - this->iPoczatek) + this->iPoczatek;
}
