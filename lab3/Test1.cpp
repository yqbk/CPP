#include "aghInclude.h"


Test1::Test1(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan) : Test(strNazwaTestu, wskGenerator, iIloscLosowan)
{
    this->iIloscParzystych = 0;
    this->iIloscNieparzystych = 0;
}


Test1::~Test1()
{
    delete []wyniki;
}


void Test1::testuj()
{
    for (int i = 0; i < this->iIloscLosowan; i++)
    {
        this->wskGenerator->losuj();
        this->wyniki[i] = this->wskGenerator->getWylosowana();
    }
    for (int i = 0; i < this->iIloscLosowan; i++)
    {
        if (this->wyniki[i]%2 == 0)
        {
            this->iIloscParzystych++;

        }
        else
        this->iIloscNieparzystych++;


    }
    cout << "\n\n" << "Ilosc parzystych: " << this->iIloscParzystych << endl;
    cout << "Ilosc nieparzystych: " << this->iIloscNieparzystych << endl;

}


void Test1::print(ostream & output) 
{
   output << "\nTest parzyste/nieparzyste: \n";

   Test::print(output);
}