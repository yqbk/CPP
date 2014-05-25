#include "aghInclude.h"


Test3::Test3(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan) : Test(strNazwaTestu, wskGenerator, iIloscLosowan)
{
    powtorzenia = new int*[iIloscLosowan];

    for (int i = 0; i < iIloscLosowan; ++i)
    {
        powtorzenia[i] = new int[2];
        powtorzenia[i][0] = 0;
        powtorzenia[i][1] = 0;
    }
}


Test3::~Test3()
{

}


void Test3::testuj()
{
    for (int i = 0; i < this->iIloscLosowan; i++)
    {
        this->wskGenerator->losuj();
        this->wyniki[i] = this->wskGenerator->getWylosowana();

        powtorzenia[i][0] = wyniki[i];
        powtorzenia[i][1] = 0;
    }

    max = 0;
    index = 0;

    for (int i = 0; i < iIloscLosowan; ++i)
    {
        for (int j = 0; j < iIloscLosowan; ++j)
        {
            if(powtorzenia[i][0] == wyniki[j]) 
                ++powtorzenia[i][1];

            if(powtorzenia[i][1] > max)
            {
                max = powtorzenia[i][1];
                index = i;           
            }
        }
    }
}


void Test3::print(ostream & output) 
{
   output << "\nTest najwiekszej liczby powtorzen: \n";

   Test::print(output);

   output << "\n\n" << "Najwiecej razy powtorzyla sie liczba: " << wyniki[index] << ", " << max << " razy." << endl; 
}