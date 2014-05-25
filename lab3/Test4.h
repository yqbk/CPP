/**
* \file Test4.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik naglowkowy z testem Pi
*/

#ifndef TEST4_H
#define TEST4_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Test4
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \brief Klasa Testu Pi dziedziczaca po klasie Test
*/

class Test4: public Test 
{
	private:

		double *wynikiFib = NULL;	///tabela wyników

   	public:

       /**
       * @brief Konstruktor parametrowy
       * @param strNazwaTestu - nazwa testu
       * @param wskGenerator - wskaznik na generator
       * @param iIloscLosowan - Ilosc liczb do wylosowania
       */
      	Test4(string strNazwaTestu, Generator* wskGenerator, int iIloscLosowan);

       /**
       * @brief Dekonstruktor
       */
      	~Test4();

       /**
       * @brief Metoda do testowania generatora
       * @return Nic nie zwraca
       */
        void testuj();

       /**
       * @brief Metoda wypisujaca wyniki do strumienia
       * @return Nic nie zwraca
       */
        void print(ostream& = cout);
};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif 