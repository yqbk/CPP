/**
* \file Generator2.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy generatora Fibonacciego
*/

#ifndef GENERATOR3_H
#define GENERATOR3_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Generator3
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa generatora generatora Fibonacciego
*/

class Generator3 : public Generator
{
	private:

      int size;       ///rozmiar tablicy
      int step;       ///krok generatora
      int* state;     ///tablica wyników

      static int i;   ///licznik

       /**
       * @brief Metoda przygotowujaca generator do uruchomienia
       * @return Nic nie zwraca 
       */
      void initializeGenerator(void);


    public:
// ---------------------------------------------------------
       /**
       * @brief Konstruktor
       */
    	Generator3();

       /**
       * @brief Konstruktor parametrowy
       * @param iPoczatek - poczatek przedzialu  
       * @param iKoniec - koniec przedzialu
       * @param _seed - ziarno (wartosc poczatkowa)
       * @param _size - wymiar tablicy
       * @param _step - krok generatora
       * @param strNazwaGeneratora - nazwa generatora
       */
      Generator3(int iPoczatek, int iKoniec, int _size, int _step, int _seed, string strNazwa); 

       /**
       * @brief Dekonstruktor
       */
       ~Generator3();

// ---------------------------------------------------------
       /**
       * @brief Resetowanie generatora
       * @param iPoczatek - poczatek przedzialu  
       * @param iKoniec - koniec przedzialu
       * @param _seed - ziarno (wartosc poczatkowa)
       * @param _size - wymiar tablicy
       * @param _step - krok generatora
       * @return Nic nie zwraca
       */
      void resetGenerator(int iPoczatek, int iKoniec, int _size, int _step, int _seed); 

       /**
       * @brief Metoda losujaca liczby
       * @return Nic nie zwraca 
       */
      void losuj();


// ---------------------------------------------------------
       /**
       * @brief Metoda pobierajaca rozmiar
       * @return Wartosc wymiaru
       */
      int getSize();

       /**
       * @brief Metoda pobierajaca krok
       * @return Wartosc kroku
       */
      int getStep();

       /**
       * @brief Metoda pobierajaca ziarno
       * @return Wartosc ziarna
       */
      int getSeed();


// ---------------------------------------------------------
       /**
       * @brief Metoda ustawiająca rozmiar
       * @return Nic nie zwraca 
       */
      void setSize(int);

       /**
       * @brief Metoda ustawiająca krok generatora
       * @return Nic nie zwraca 
       */
      void setStep(int);

       /**
       * @brief Metoda ustawiająca ziarno
       * @return Nic nie zwraca 
       */
      void setSeed(int);

};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif

