/**
* \file Test3.h
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik naglowkowy z testem powtorzen
*/

#ifndef TEST3_H
#define TEST3_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Test3
* \authors Jakub Syrek & Katarzyna Zukowska
* \date 25.05.2014
* \brief Klasa Testu powtorzenia dziedziczaca po klasie Test
*/

class Test3: public Test
{
	private:

        int **powtorzenia;	///tabela z iloscia powtorzen 
        int max;			///maksymalna wartosc powtorzen
    	int index;			///indeks liczby z najwieksza iloscia powtorzen

    public:

       /**
       * @brief Konstruktor parametrowy
       * @param strNazwaTestu - nazwa testu
       * @param wskGenerator - wskaznik na generator
       * @param iIloscLosowan - Ilosc liczb do wylosowania
       */
        Test3(string strNazwaTestu, Generator *wskGenerator, int iIloscLosowan);

       /**
       * @brief Dekonstruktor
       */
        ~Test3();

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