/**
* \file Test.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy abstrakcyjnej testu
*/

#ifndef TEST_H
#define TEST_H

// ---------------------------------------------------------
// ---------------------------------------------------------
/**
* \class Test
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 25.05.2014
* \brief Klasa abstrakcyjna Testu
*/

class Test
{
    protected:

        string strNazwaTestu;       //Nazwa Testu
        int iIloscLosowan;          //Ilosc liczb do wylosowania
        int *wyniki;                //Tablica wynikow
        Generator *wskGenerator;    //Wskaznik na generator do testu


    public:
// ---------------------------------------------------------     
       /**
       * @brief Konstruktor 
       */
        Test();

       /**
       * @brief Konstruktor parametrowy
       * @param strNazwaTestu - nazwa testu
       * @param Generator* - wskaznik na generator
       * @param iIloscLosowan - Ilosc liczb do wylosowania
       * @return No value returns
       */
        Test(string strNazwaTestu, Generator*, int iIloscLosowan);

       /**
       * @brief Dekonstruktor
       */
        virtual ~Test();

       /**
       * @brief Metoda zmianiajaca rozmiar / tworzaca tablice wynikow
       * @return Nic nie zwraca 
       */
        void resize();

       /**
       * @brief Metoda kasujaca tablice wynikow
       * @return Nic nie zwraca 
       */
        void clear(); 


// ---------------------------------------------------------
       /**
       * @brief Metoda wirtualna do testowania generatora
       * @return Nic nie zwraca 
       */
        virtual void testuj() = 0;       


// ---------------------------------------------------------
       /**
       * @brief Metoda ustawiajaca wskaznik
       * @param Generator* - wskaznik na generator
       * @return Nic nie zwraca 
       */
        void setGenerator(Generator*);

       /**
       * @brief Metoda ustawiajaca ilosc losowan
       * @param iIloscLosowan - ilosc losowan
       * @return Nic nie zwraca 
       */
        void setIloscLosowan(int iIloscLosowan);

       /**
       * @brief Metoda ustawiajaca nazwe testu
       * @param strNazwaTestu - nazwa testu
       * @return Nic nie zwraca 
       */
        void setNazwa(string strNazwaTestu);

       /**
       * @brief Metoda ustawiajaca wynik o danym indeksie
       * @param n - nr indeksu
       * @param value - wartosc
       * @return Nic nie zwraca 
       */
        void setWyniki(int n, int value);


// ---------------------------------------------------------
       /**
       * @brief Metoda pobierajaca wartosc wyniku o indeksie n
       * @param n - nr indeksu
       * @return Poczatek przedzialu
       */
        int getWyniki(int n);

       /**
       * @brief Metoda pobierajaca ilosc losowan
       * @return Ilosc losowan
       */
        int getIloscLosowan();

       /**
       * @brief Metoda pobierajaca nazwe testu
       * @return Nazwa testu
       */
        string getNazwa();

       /**
       * @brief Metoda pobierajaca wskaznik na generator
       * @return Wskaznik na generator
       */
        Generator* getGenerator();

        /*
        int getSampleSize(void);

        void setSampleSize(int);
        */


// ---------------------------------------------------------   


       /**
       * @brief Metoda wirtualna wypisujaca wylosowane liczby do strumienia
       * @return Nic nie zwraca
       */
        virtual void print(ostream & = cout);
        

};
// ---------------------------------------------------------  
// ---------------------------------------------------------  
#endif 