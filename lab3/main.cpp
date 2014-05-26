#include "aghInclude.h"


//------------------------------------------------------
//------------------------------------------------------
int main()
{

    ofstream plik;
    plik.open("plik.txt", ios::trunc | ios::out);

    if( plik.good() == true )
    {    	

//------------------------------------------------------
    	Generator1 generator1(1, 100, 1, "Generator rand()");    

    	prezentacjaGeneratora(& generator1, plik);

    	multiTesty(& generator1, plik);
//------------------------------------------------------
    	Generator2 generator2(1, 100, time(NULL), 69069, 0, pow(2, 32), "Generator Multiplikatywny LCG");  //Super-Duper   

    	prezentacjaGeneratora(& generator2, plik);

    	multiTesty(& generator2, plik);
//------------------------------------------------------
    	Generator3 generator3(0, 100, 127, 97, time(NULL), "Generator Fibonacciego");   

    	prezentacjaGeneratora(& generator3, plik);

    	multiTesty(& generator3, plik);
//------------------------------------------------------
    	
	}

	else
		throw aghException(3, "Nie udalo sie otworzyc pliku", __FILE__, __LINE__);


    plik.close();

    return 0;
}

//------------------------------------------------------
//------------------------------------------------------