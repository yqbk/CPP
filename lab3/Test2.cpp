#include "aghInclude.h"



Test2::Test2(string strNazwaTestu, int iIloscLosowan, Generator *wskGenerator)
{
    this->strNazwaTestu = strNazwaTestu;
    this->iIloscLosowan = iIloscLosowan;
    this->wskGenerator = wskGenerator;
    this->wyniki = new int[iIloscLosowan];
    this->iIloscPierwszych = 0;
}

Test2::~Test2()
{
    delete []wyniki;
}

void Test2::testuj()
{
    for (int i = 0; i < this->iIloscLosowan; i++)
    {
        this->wskGenerator->losuj();
        this->wyniki[i] = this->wskGenerator->getWylosowana();
    }

    int count = 16; // 16 liczb pierwszych, żeby zmniejszyć złożoność obliczeniową

    int *pierwsze = new int [count];

    for (int i = 0; i < count; ++i)  
        pierwsze[i] = fib(i);   

    for (int i = 0; i < this->iIloscLosowan; i++)        
        for (int j = 0; j < count; j++)        
            if(wyniki[i] == pierwsze[j]) ++iIloscPierwszych;
   
    cout << "\n\n" << "Ilosc pierwszych: " << iIloscPierwszych << endl;


}
