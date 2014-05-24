#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------

Generator::Generator()
{

}

Generator::Generator(int iPoczatek, int iKoniec, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->strNazwaGeneratora = strNazwaGeneratora;
}


Generator::~Generator()
{

}

// ---------------------------------------------------------


void Generator::setPoczatek(int iPoczatek)
{
    this->iPoczatek = iPoczatek;
}

void Generator::setKoniec(int iKoniec)
{
    this->iKoniec = iKoniec;
}

void Generator::setNazwa(string strNazwaGeneratora)
{
    this->strNazwaGeneratora = strNazwaGeneratora;
}

int Generator::getPoczatek()
{
    return iPoczatek;
}

int Generator::getKoniec()
{
    return iKoniec;
}

string Generator::getNazwa()
{
    return strNazwaGeneratora;
}

int Generator::getWylosowana()
{
    return iWylosowana;
}

int Generator::getSeed()
{
    return seed;
}


void Generator::print(ostream & output) 
{
  output << " " << getWylosowana() << " " ; 
}


// ---------------------------------------------------------
// ---------------------------------------------------------
