/**
* \file aghDlist.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 8.06.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy szablonu aghDlist dziedziczącej po klasie aghSlist
*/

#ifndef AGHDLIST_H
#define AGHDLIST_H

/**
* \class aghDlist
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 8.06.2014
* \brief Klasa aghDlist dziedzicząca po klasie aghSlist
*/
template<class T>
class aghDlist : public aghSlist<T>
{
    private:

       aghDnode<T>* ptrRoot;   ///< poczatek listy
       aghDnode<T>* ptrEnd;    ///< koniec listy

       int rozmiar;

       /**
       * @brief Metoda wirtualna ktora tworzy zalazek listy
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
       void nowaLista(T const &);


       /**
       * @brief Metoda wirtualna ktora dodaje na poczatku
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
       void dodajPocz(T const &);

       /**
       * @brief Metoda wirtualna ktora dodaje na koncu
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
       void dodajEnd(T const &);

       /**
       * @brief Metoda wirtualna ktora dodaje na danym indexie
       * @param element - dane ktore dodajemy do listy
       * @param index - index
       * @return Nic nie zwraca
       */
       void dodaj(T const &, int);


       /**
       * @brief Metoda wirtualna ktora usuwa z poczatku listy
       * @return Nic nie zwraca
       */
       void usunPocz();

       /**
       * @brief Metoda wirtualna ktora usuwa z konca listy
       * @return Nic nie zwraca
       */
       void usunEnd();

       /**
       * @brief Metoda wirtualna ktora usuwa z danego indexu listy
       * @param index - index
       * @return Nic nie zwraca
       */
       void usun(int);


       /**
       * @brief Metoda wirtualna ktora pobiera dany wezel
       * @param index - index
       * @return Nic nie zwraca
       */
       aghDnode<T>* getNode(int) const; 


    public:

       /**
       * @brief Konstruktor
       */
        aghDlist();

       /**
       * @brief Konstruktor parametrowy
       * @param element - pojemnik
       */
        aghDlist(aghContainer<T> & element);

       /**
       * @brief Konstruktor kopiujący
       * @param element - pojemnik
       */
       aghDlist(aghDlist<T> const &);

       /**
       * @brief Dekonstruktor
       */
        ~aghDlist();

       /**
       * @brief Metoda która pobiera ilosc elementow (nadpisuje metode ktora klasa dziedziczy)
       * @return Liczba elementow
       */
        int size(void) const; 


//------------------------------------------------------------------------
       /**
       * @brief Operator =
       * @param right - element
       * @return Pojemnik
       */
        aghDlist<T>& operator=(aghDlist<T> const &);
};

//------------------------------------------------------------------------
#endif