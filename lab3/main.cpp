#include "aghInclude.h"



int main()
{

    ofstream plik;
    plik.open("plik.txt", ios::trunc | ios::out);

    if( plik.good() == true )
    {

    	

//------------------------------------------------------
    	Generator1 generator1(1, 100, 1, "Generator rand()");    

    	prezentacjaGeneratora(& generator1);

    	multiTesty(& generator1);
//------------------------------------------------------
    	Generator2 generator2(1, 100, rand() % 1000 + 100, 17, 100, "Generator Multiplikatywny LCG");    

    	prezentacjaGeneratora(& generator2);

    	multiTesty(& generator2);
//------------------------------------------------------
    	Generator3 generator3(0, 100, 127, 97, time(NULL), "Generator Fibonacciego");   

    	prezentacjaGeneratora(& generator3);

    	multiTesty(& generator3);
//------------------------------------------------------

    	plik.close();
	}

	else
		throw aghException(3, "Nie udalo sie otworzyc pliku", __FILE__, __LINE__);


    return 0;
}