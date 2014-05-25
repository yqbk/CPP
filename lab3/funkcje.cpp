#include "aghInclude.h"


int fib(int n) 
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

void multiTesty(Generator *wskGenerator)
{
	
	cout << "\n\n------------------------------------------------------";
	cout << "\nTesty dla: " << wskGenerator->getNazwa() << "\n";

    Test1 test1("Parzyste i nieparzyste", wskGenerator, 100);
    test1.testuj();
    test1.print();

    cout << endl;
    Test2 test2("Pierwsze", wskGenerator, 100);
    test2.testuj();
    test2.print();

    cout << endl;
    Test3 test3("Powtorzenia", wskGenerator, 100);
    test3.testuj();
    test3.print();

    cout << endl;
    Test4 test4("Pi", wskGenerator, 100);
    test4.testuj();
    test4.print();

    cout << "\n------------------------------------------------------";
    

}
