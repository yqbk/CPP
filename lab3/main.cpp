#include "aghInclude.h"



int main()
{

  //  ofstream plik;
 //   plik.open("plik.txt", ios::trunc | ios::app);

//    if (plik.is_open())
    //{

    	srand(time(NULL));





    	Generator1 generator1(4, 100, "Generator rand()");    

    	cout << endl << generator1.getNazwa() << endl;    
    	for (int i = 0; i < 10; ++i)
    	{
    		generator1.losuj();
			//generator1.print(plik);
			generator1.print();
    	}    

    	multiTesty(& generator1);


    //------------------------------------------------------
    	cout << "\n\nNowy generator... \n\n";

    	Generator3 generator3(0, 100, 127, 97, time(0));    

   		for (int i = 0; i < 10; ++i)
    	{
    		generator3.losuj();
			//generator3.print(plik);
			generator3.print();
    	}

    	multiTesty(& generator3);




    /*


cout << "\n\nNowy generator... \n\n";




    //------------------------------------------------------
    Generator2 generator2(1, 100, rand() % 1000 + 100, 1311, 172, "Generator Multiplikatywny LCG");    

    generator2.nazwa();    
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

    cout << endl;
    Test4 test4a("Pi", & generator2, 100);
    test4a.testuj();
    test4a.print();

    cout << "\n------------------------------------------------------";
    //------------------------------------------------------


cout << "\n\nNowy generator... \n\n";


    Generator3 generator3(0, 100, 127, 97, time(0));    

    cout << endl << generator3.getNazwa() << endl;    
    for (int i = 0; i < 10; ++i)
    {
    	generator3.losuj();
		generator3.print(plik);
		generator3.print();
    }

        cout << endl;
    Test4 test4a("Pi", & generator3, 100);
    test4a.testuj();
    test4a.print();

    cout << "\n------------------------------------------------------";
    //------------------------------------------------------



*/

  //  plik.close();
	//}

	//else
	//	throw aghException(3, "Nie udalo sie otworzyc pliku", __FILE__, __LINE__);


    return 0;
}