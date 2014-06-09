/**
* \file aghSlist.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 8.06.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy szablonu aghSlist dziedziczącej po klasie aghContainer
*/

#ifndef AGHSLIST_H
#define AGHSLIST_H

/**
* \class aghSlist
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 8.06.2014
* \brief Klasa aghSlist dziedzicząca po klasie aghContainer
*/
template<class T>
class aghSlist : public aghContainer<T>
{
    private:

        aghSnode<T>* ptrRoot;   ///< Poczatek listy

       /**
       * @brief Metoda wirtualna ktora tworzy zalazek listy
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
        virtual void nowaLista(T const &);


       /**
       * @brief Metoda wirtualna ktora dodaje na poczatku
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
        virtual void dodajPocz(T const &);

       /**
       * @brief Metoda wirtualna ktora dodaje na koncu
       * @param element - dane ktore dodajemy do listy
       * @return Nic nie zwraca
       */
        virtual void dodajEnd(T const &);

       /**
       * @brief Metoda wirtualna ktora dodaje na danym indexie
       * @param element - dane ktore dodajemy do listy
       * @param index - index
       * @return Nic nie zwraca
       */
        virtual void dodaj(T const &, int);


       /**
       * @brief Metoda wirtualna ktora usuwa z poczatku listy
       * @return Nic nie zwraca
       */
        virtual void usunPocz();

       /**
       * @brief Metoda wirtualna ktora usuwa z konca listy
       * @return Nic nie zwraca
       */
        virtual void usunEnd();

       /**
       * @brief Metoda wirtualna ktora usuwa z danego indexu listy
       * @param index - index
       * @return Nic nie zwraca
       */
        virtual void usun(int);


       /**
       * @brief Metoda wirtualna ktora pobiera dany wezel
       * @param index - index
       * @return Nic nie zwraca
       */
        virtual aghSnode<T>* getNode(int) const; 


    public:

       /**
       * @brief Konstruktor
       */
       aghSlist();

       /**
       * @brief Konstruktor parametrowy
       * @param element - pojemnik
       */
       aghSlist(aghContainer<T> & element);

       /**
       * @brief Konstruktor kopiujący
       * @param element - pojemnik
       */
       aghSlist(aghSlist<T> const &);

       /**
       * @brief Dekonstruktor
       */
       ~aghSlist();

//------------------------------------------------------------------------
       /**
       * @brief Metoda która "wklada" element do pojemnika
       * @param index - index
       * @param element - wrzucany element
       * @return Wartosc logiczna
       */
       bool insert(int index, T const & element);

       /**
       * @brief Metoda która pobiera element z pojemnika
       * @param index - index
       * @return Pobrany element
       */
       T& at(int) const;

       /**
       * @brief Metoda która pobiera ilosc elementow
       * @return Liczba elementow
       */
       int size(void) const; 

       /**
       * @brief Metoda która usuwa element
       * @param index - index
       * @return Wartosc logiczna
       */
       bool remove(int index);

//------------------------------------------------------------------------
       /**
       * @brief Operator =
       * @param right - element
       * @return Pojemnik
       */
       aghSlist<T> & operator=(aghSlist<T> const & element); 

};

//------------------------------------------------------------------------
#endif
