/**
* \file Generator.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy abstrakcyjnej generatora
*/

#ifndef GENERATOR_H
#define GENERATOR_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Generator
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa abstrakcyjna generatora
*/

class Generator
{
    protected:

        int iPoczatek;              ///Poczatek przedzialu
        int iKoniec;                ///Koniec przedzialu
        int seed;                   ///Ziarno
        string strNazwaGeneratora;  ///Nazwa generatora
        int iWylosowana;            ///Wylosowana liczba


    public:
// ---------------------------------------------------------     
       /**
       * @brief Konstruktor 
       */
        Generator();

       /**
       * @brief Konstruktor parametrowy
       * @param iPoczatek - poczatek przedzialu
       * @param iKoniec - koniec przedzialu
       * @param seed - ziarno (warosc poczatkowa)
       * @param strNazwaGeneratora - nazwa generatora
       */
        Generator(int iPoczatek, int iKoniec, int seed, string strNazwaGeneratora);

       /**
       * @brief Dekonstruktor
       */
        virtual ~Generator();
        

// ---------------------------------------------------------
       /**
       * @brief Metoda wirtualna do losowania liczby
       * @return Nic nie zwraca 
       */
        virtual void losuj() = 0;   


// ---------------------------------------------------------
       /**
       * @brief Metoda ustawiajaca poczatek
       * @param iPoczatek - poczatek przedzialu
       * @return Nic nie zwraca 
       */
        void setPoczatek(int iPoczatek);

       /**
       * @brief Metoda ustawiajaca koniec
       * @param iKoniec - poczatek przedzialu
       * @return Nic nie zwraca 
       */
        void setKoniec(int iKoniec);

       /**
       * @brief Metoda ustawiajaca nazwe
       * @param strNazwaGeneratora - poczatek przedzialu
       * @return Nic nie zwraca 
       */
        void setNazwa(string strNazwaGeneratora);

       /**
       * @brief Metoda ustawiajaca ziarno (seed)
       * @param int - ziarno
       * @return Nic nie zwraca 
       */
        void setSeed(int);

// ---------------------------------------------------------
       /**
       * @brief Metoda pobierajaca poczatek przedzialu
       * @return Poczatek przedzialu
       */
        int getPoczatek();

       /**
       * @brief Metoda pobierajaca koniec przedzialu
       * @return Koniec przedzialu
       */
        int getKoniec();

       /**
       * @brief Metoda pobierajaca ziarno
       * @return Ziarno
       */
        int getSeed();

       /**
       * @brief Metoda pobierajaca wylosowana liczbe
       * @return Wylosowana liczba
       */
        int getWylosowana();

       /**
       * @brief Metoda pobierajaca nazwe generatora
       * @return Nazwa generatora
       */
        string getNazwa();

// ---------------------------------------------------------
       /**
       * @brief Metoda wypisujaca nazwe generatora do strumienia
       * @return Nic nie zwraca
       */
        void nazwa(ostream & = cout);

       /**
       * @brief Metoda wypisujaca wylosowana liczbe do strumienia
       * @return Nic nie zwraca
       */
        void print(ostream & = cout);        


};

// ---------------------------------------------------------
// ---------------------------------------------------------
#endif
