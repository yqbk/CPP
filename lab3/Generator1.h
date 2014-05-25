/**
* \file Generator1.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy generatora wbudowanego
*/

#ifndef GENERATOR1_H
#define GENERATOR1_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Generator1
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa generatora wbudowanego
*/

class Generator1 : public Generator
{
    public:

       /**
       * @brief Konstruktor parametrowy
       * @param iPoczatek - poczatek przedzialu  
       * @param iKoniec - koniec przedzialu
       * @param seed - ziarno (wartosc poczatkowa)
       * @param strNazwaGeneratora - nazwa generatora
       */
        Generator1(int iPoczatek, int iKoniec, int seed, string strNazwaGeneratora);

       /**
       * @brief Dekonstruktor
       */
        ~Generator1();

       /**
       * @brief Metoda losujaca liczby
       * @return Nic nie zwraca 
       */
        void losuj();

};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif