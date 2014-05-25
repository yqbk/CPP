#include "aghInclude.h"       //Pi test


Test4::Test4(string strNazwaTestu, Generator* wskGenerator, int iIloscLosowan) : Test(strNazwaTestu, wskGenerator, iIloscLosowan)
{

}


Test4::~Test4() 
{

}


void Test4::testuj() 
{
   int r = wskGenerator->getKoniec() - wskGenerator->getPoczatek() + 1;
   int y = 0;

   for(int i = 0; i < iIloscLosowan; ++i) 
   {
      int counter = 0;
      int inCircle = 0;

      while(counter < iIloscLosowan) 
      {
         wskGenerator->losuj();
         int x = wskGenerator->getWylosowana() - wskGenerator->getPoczatek();
         counter = counter + 1;

         if(x * x + y * y <= r * r)
            inCircle++;

         y = x;
      }

      if(counter > 0) 
      {
         double pi = 4.0 * inCircle / counter;
         setWyniki(i, pi);
      } 

      else
         setWyniki(i, 100);
   }
}


void Test4::print(ostream & output) 
{
   output << "\nTest Pi: \n";

   Test::print(output);
}