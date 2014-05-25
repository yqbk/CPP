/**
* \file Test1.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik naglowkowy z testem parzyste/nieparzyste
*/

#ifndef TEST1_H
#define TEST1_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Test1
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \brief Klasa Testu parzyste/nieparzyste dziedziczaca po klasie Test
*/

class Test1: public Test
{
    protected:							

        int iIloscParzystych;		///Ilosc liczb parzystych
        int iIloscNieparzystych;	///Ilosc liczb nieparzystych

    public:

       /**
       * @brief Konstruktor parametrowy
       * @param strNazwaTestu - nazwa testu
       * @param wskGenerator - wskaznik na generator
       * @param iIloscLosowan - Ilosc liczb do wylosowania
       */
        Test1(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

       /**
       * @brief Dekonstruktor
       */
        ~Test1();

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