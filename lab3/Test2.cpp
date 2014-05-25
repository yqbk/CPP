#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
Test2::Test2(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan) : Test(strNazwaTestu, wskGenerator, iIloscLosowan)
{
    this->iIloscPierwszych = 0;
}

// ---------------------------------------------------------
Test2::~Test2()
{

}

// ---------------------------------------------------------
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
}

// ---------------------------------------------------------
void Test2::print(ostream & output) 
{
   output << "\nTest ilosci liczb pierwszych: \n";

   Test::print(output);

   output << "\n\n" << "Ilosc pierwszych: " << iIloscPierwszych << endl;
}

// ---------------------------------------------------------
// ---------------------------------------------------------