#include "aghInclude.h"



Test3::Test3(string strNazwaTestu, int iIloscLosowan, Generator *wskGenerator)
{
    this->strNazwaTestu = strNazwaTestu;
    this->iIloscLosowan = iIloscLosowan;
    this->wskGenerator = wskGenerator;
    this->wyniki = new int[iIloscLosowan];
    powtorzenia = new int*[iIloscLosowan];

    for (int i = 0; i < iIloscLosowan; ++i)
    {
        powtorzenia[i] = new int[2];
    }
}

Test3::~Test3()
{
    delete []wyniki;

    for (int i = 0; i < iIloscLosowan; ++i)
    {
       delete [] powtorzenia[i];
    }
    delete [] powtorzenia;
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

    int max;
    int index;

    max = powtorzenia[0][0];
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
   
    cout << "\n\n" << "Najwiecej razy powtorzyla sie liczba: " << wyniki[index] << ", " << max << " razy." << endl;


}
