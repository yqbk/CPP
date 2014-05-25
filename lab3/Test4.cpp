#include "aghInclude.h"       //Pi test


Test4::Test4(string strNazwaTestu, Generator* wskGenerator, int iIloscLosowan) : Test(strNazwaTestu, wskGenerator, iIloscLosowan)
{
    if(wynikiFib != NULL) 
      throw aghException(2, "wynikiFib znajduja sie w pamieci", __FILE__, __LINE__);
   
   else 
   {
      wynikiFib = new double[iIloscLosowan];

      for(int i = 0; i < iIloscLosowan; i++)
         wynikiFib[i] = 0.0; 
   }
}


Test4::~Test4() 
{
   if(wynikiFib != NULL)
      delete [] wynikiFib;

   wynikiFib = NULL;
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
         wynikiFib[i] = pi;
      } 

      else
         wynikiFib[i] = 100;
   }
}


void Test4::print(ostream & output) 
{
   output << "\nTest Pi: \n";

   for (int i = 0; i < iIloscLosowan; ++i)   
      output << " " << wynikiFib[i] << " " ; 
}