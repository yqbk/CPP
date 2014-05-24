#include "aghInclude.h"

	//Multiplikatywny LCG


Generator2::Generator2(int iPoczatek, int iKoniec, int seed, int mnoznik, int add, int modul, string strNazwaGeneratora)
{
    this->setPoczatek(iPoczatek);
    this->setKoniec(iKoniec);
    this->strNazwaGeneratora = strNazwaGeneratora;
    this->seed = seed;
    this->mnoznik = mnoznik;
    this->modul = modul;
    this->add = add;


cout << endl << getSeed() << endl;    

}


void Generator2::losuj()
{
	if (seed == 0) ++seed;

	seed = ((mnoznik * seed) + add) % modul;

    this->iWylosowana = seed;

    cout << getWylosowana() << " ";


}
