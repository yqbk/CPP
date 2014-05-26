#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
Generator::Generator()
{

}

Generator::Generator(int iPoczatek, int iKoniec, int seed, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->setNazwa(strNazwaGeneratora);    
    this->setSeed(seed);
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

void Generator::setSeed(int seed)
{
    this->seed = seed;
}

// ---------------------------------------------------------
int Generator::getPoczatek() const
{
    return iPoczatek;
}

int Generator::getKoniec() const
{
    return iKoniec;
}

string Generator::getNazwa() const
{
    return strNazwaGeneratora;
}

int Generator::getWylosowana() const
{
    return iWylosowana;
}

int Generator::getSeed() const
{
    return seed;
}

// ---------------------------------------------------------
void Generator::print(ostream & output) const 
{
  output << " " << getWylosowana() << " " ; 
}

void Generator::nazwa(ostream & output) const
{
	output << "\n\n" << getNazwa() << "\n" ; 
}

// ---------------------------------------------------------
// ---------------------------------------------------------
