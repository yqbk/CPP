#include "aghInclude.h"

int main()
{

    ofstream plik;
    plik.open("plik.txt", ios::trunc | ios::app);

    if (plik.is_open());

        srand(time(NULL));


    Generator1 generator1(4, 100, "Generator1");    

    cout << endl << generator1.getNazwa() << endl;    
    for (int i = 0; i < 10; ++i)
    {
    	generator1.losuj();
		generator1.print(plik);
		generator1.print();
    }
    


    //------------------------------------------------------
    cout << "\n\n";
    Test1 test1("Parzyste i nieparzyste", 100, &generator1);
    test1.testuj();

    cout << endl;
    Test2 test2("Pierwsze", 100, &generator1);
    test2.testuj();

    cout << endl;
    Test3 test3("Powtorzenia", 100, &generator1);
    test3.testuj();
    cout << "\n------------------------------------------------------";
    //------------------------------------------------------
    //------------------------------------------------------

plik << "\n\nNowy generatpr... \n\n";


    Generator2 generator2(1, 100, rand() % 1000 + 100, 13, 17, 87, "Generator Multiplikatywny LCG");    

    cout << endl << generator1.getNazwa() << endl;    
    for (int i = 0; i < 10; ++i)
    {
    	//cout << " " << generator1.getSeed();

    	generator2.losuj();
		generator2.print(plik);
		//generator2.print();
    }
    
    //------------------------------------------------------
    cout << "\n\n";
    Test1 test1a("Parzyste i nieparzyste", 100, &generator2);
    test1a.testuj();

    cout << endl;
    Test2 test2a("Pierwsze", 100, &generator2);
    test2a.testuj();

    cout << endl;
    Test3 test3a("Powtorzenia", 100, &generator2);
    test3a.testuj();
    cout << "\n------------------------------------------------------";
    //------------------------------------------------------
    //------------------------------------------------------


    plik.close();

    return 0;
}