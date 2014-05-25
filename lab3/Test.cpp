#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------
Test::Test()
{
    
}

Test::Test(string strNazwaTestu, Generator* wskGenerator, int iIloscLosowan)
{
	setGenerator(wskGenerator);	
	setNazwa(strNazwaTestu);

	wyniki = NULL;

	setIloscLosowan(iIloscLosowan);
}

Test::~Test()
{
   clear();
   wskGenerator = NULL;

   strNazwaTestu = "";

   iIloscLosowan = 0;
}

// ---------------------------------------------------------
void Test::resize()
{
   if(wyniki != NULL) 
      throw aghException(2, "Wyniki znajduja sie w pamieci", __FILE__, __LINE__);
   
   else 
   {
      wyniki = new int[iIloscLosowan];

      for(int i = 0; i < iIloscLosowan; i++)
         wyniki[i] = 0; 	
   }
}

void Test::clear() 
{
   if(wyniki != NULL)
      delete [] wyniki;

   wyniki = NULL;
}


// ---------------------------------------------------------
void Test::setGenerator(Generator* generator)
{
	if (generator == NULL)
	{
		cout << "--2";
		throw aghException(1, "Zle dane wejsciowe", __FILE__, __LINE__);
		
	}
	else
		this->wskGenerator = generator; 
}

void Test::setIloscLosowan(int n)
{
	if (n <= 0)
	{
		cout << "--3";
		throw aghException(1, "Zle dane wejsciowe", __FILE__, __LINE__);
	}
	else
	{

		this->iIloscLosowan = n;

		clear();
		resize();
	}
}


void Test::setNazwa(string strNazwaTestu)
{
	this->strNazwaTestu = strNazwaTestu;
}
        

void Test::setWyniki(int n, int value)
{
	if(n > iIloscLosowan || wyniki == NULL)
	{
		cout << "--4";
		throw aghException(0, "Nie ma wynikow lub zly index", __FILE__, __LINE__);		
	}

	else
		wyniki[n] = value;
}


// ---------------------------------------------------------
Generator* Test::getGenerator()
{
	return wskGenerator;
}

int Test::getIloscLosowan()
{
	return iIloscLosowan;
}

string Test::getNazwa()
{
	return strNazwaTestu;
}

int Test::getWyniki(int n)
{
	if(wyniki == NULL || n > iIloscLosowan)
	{
		cout << "--1";
		throw aghException(0, "Nie ma wynikow lub zly index", __FILE__, __LINE__);
		
	}

	else
		return wyniki[n];
}


// ---------------------------------------------------------
void Test::print(ostream & output) 
{
	for (int i = 0; i < iIloscLosowan; ++i)	
		output << " " << getWyniki(i) << " " ;	
   
}