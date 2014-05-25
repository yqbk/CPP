#include "aghInclude.h"


// ---------------------------------------------------------
// ---------------------------------------------------------
int fib(int n) 
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

// ---------------------------------------------------------
void prezentacjaGeneratora(Generator *wskGenerator)
{
    ofstream plik;
    plik.open("plik.txt", ios::app);

    if( plik.good() == true )
    {
        plik << "\n\n******************************************************";
        cout << "\n\n******************************************************";

        cout << endl << wskGenerator->getNazwa() << endl;   
        plik << endl << wskGenerator->getNazwa() << endl;  

        for (int i = 0; i < 10; ++i)
        {
            wskGenerator->losuj();
            wskGenerator->print(plik);
            wskGenerator->print();
        }    
    }
}

// ---------------------------------------------------------
void multiTesty(Generator *wskGenerator)
{
    ofstream plik;
    plik.open("plik.txt", ios::app);

    if( plik.good() == true )
    {
	
	    cout << "\n\n------------------------------------------------------";
	    cout << "\nTesty dla: " << wskGenerator->getNazwa() << "\n";

        plik << "\n\n------------------------------------------------------";
        plik << "\nTesty dla: " << wskGenerator->getNazwa() << "\n";

        Test1 test1("Parzyste i nieparzyste", wskGenerator, 100);
        test1.testuj();
        test1.print();
        test1.print(plik);

        cout << endl;
        Test2 test2("Pierwsze", wskGenerator, 100);
        test2.testuj();
        test2.print();
        test2.print(plik);

        cout << endl;
        Test3 test3("Powtorzenia", wskGenerator, 100);
        test3.testuj();
        test3.print();
        test3.print(plik);

        cout << endl;
        Test4 test4("Pi", wskGenerator, 100);
        test4.testuj();
        test4.print();
        test4.print(plik);

        cout << "\n------------------------------------------------------";
        plik << "\n------------------------------------------------------";
   
    }
}

// ---------------------------------------------------------
// ---------------------------------------------------------