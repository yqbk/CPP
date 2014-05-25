/**
* \file Test2.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik naglowkowy z testem liczb pierwszych
*/

#ifndef TEST2_H
#define TEST2_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Test2
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \brief Klasa Testu liczby pierwsze dziedziczaca po klasie Test
*/

class Test2: public Test
{
	protected:

        int iIloscPierwszych;	//Ilosc liczb pierwszych

    public:

       /**
       * @brief Konstruktor parametrowy
       * @param strNazwaTestu - nazwa testu
       * @param wskGenerator - wskaznik na generator
       * @param iIloscLosowan - Ilosc liczb do wylosowania
       */
        Test2(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

       /**
       * @brief Dekonstruktor
       */
        ~Test2();

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
