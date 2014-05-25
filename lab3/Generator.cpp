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

// ---------------------------------------------------------
void Generator::print(ostream & output) 
{
  output << " " << getWylosowana() << " " ; 
}

void Generator::nazwa(ostream & output)
{
	output << "\n\n" << getNazwa() << "\n" ; 
}

// ---------------------------------------------------------
// ---------------------------------------------------------
