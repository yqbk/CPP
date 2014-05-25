#include "aghInclude.h"

	//Multiplikatywny LCG


Generator2::Generator2(int iPoczatek, int iKoniec, unsigned long long seed, unsigned long long mnoznik, unsigned long long add, unsigned long long modul, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->setNazwa(strNazwaGeneratora);
    this->setSeed(seed);
    this->mnoznik = mnoznik;
    this->add = add;
    this->modul = modul;

    this->iWylosowana = 0;


cout << endl << getWylosowana() << endl;    

}


Generator2::~Generator2()
{

}


void Generator2::losuj()
{
	if (seed == 0) 
        ++seed;

	seed = ((mnoznik * seed) + add) % modul;

    this->iWylosowana = seed;

}
