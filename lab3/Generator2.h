/**
* \file Generator2.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy generatora Multiplikatywnego LCG dziedziczony po klasie Generator
*/

#ifndef GENERATOR2_H
#define GENERATOR2_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Generator2
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa generatora Multiplikatywnego LCG dziedziczona po klasie Generator
*/

class Generator2 : public Generator
{

	private:

		unsigned long long x;			///wartosc x liczby
		unsigned long long mnoznik;		///mnoznik
		unsigned long long modul;		///modul z liczby
		unsigned long long add;			///liczba ktora dodajemy

    public:

       /**
       * @brief Konstruktor parametrowy
       * @param iPoczatek - poczatek przedzialu  
       * @param iKoniec - koniec przedzialu
       * @param seed - ziarno (wartosc poczatkowa)
       * @param mnoznik - mnoznik przez ktory mnozymy
       * @param add - liczba ktora dodajemy
       * @param modul - modul z liczby
       * @param strNazwaGeneratora - nazwa generatora
       */
        Generator2(int iPoczatek, int iKoniec, unsigned long long seed, unsigned long long mnoznik, unsigned long long add, unsigned long long modul, string strNazwaGeneratora);

       /**
       * @brief Konstruktor parametrowy
       * @param iPoczatek - poczatek przedzialu  
       * @param iKoniec - koniec przedzialu
       * @param seed - ziarno (wartosc poczatkowa)
       * @param mnoznik - mnoznik przez ktory mnozymy
       * @param add - liczba ktora dodajemy
       * @param modul - modul z liczby
       * @param strNazwaGeneratora - nazwa generatora
       * @return Zwraca wylosowana liczbe (bez przedzialow)
       */
        unsigned long long LCG(unsigned long long mnoznik, unsigned long long  seed, unsigned long long modul);

       /**
       * @brief Dekonstruktor
       */
        ~Generator2();

       /**
       * @brief Metoda losujaca liczby
       * @return Nic nie zwraca 
       */
        void losuj();

};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif
