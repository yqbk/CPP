/**
* \file aghVector.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 31.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy szablonu aghVector dziedziczącej po klasie aghContainer
*/

#ifndef AGHVECTOR_H
#define AGHVECTOR_H

/**
* \class aghVector
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 31.05.2014
* \brief Klasa aghVector dziedzicząca po klasie aghContainer
*/
template<class T>
class aghVector : public aghContainer<T>
{

    private:          
   
        T *dane;        ///< wskaznik na tablice dane

        int iRozmiar;   ///< Rozmiar tablicy

        int count;      ///< ilosc elementow

       /**
       * @brief Metoda która zmienia rozmiar pojemnika
       * @param nowyRozmiar - nowy Rozmiar
       * @return Nic nie zwraca
       */
        void resize(int nowyRozmiar);

       /**
       * @brief Metoda usuwa pamiec przydzielona do tablicy
       * @return Nic nie zwraca
       */
        void kasuj();

       /**
       * @brief Metoda zwieksza rozmiar tablicy o jeden
       * @return Nic nie zwraca
       */
        void powieksz();

       /**
       * @brief Sprawdza czy w tablicy jest wolne miejsce
       * @return Ilosc wolnych miejsc
       */
        int wolneMiejsce();

    public:

       /**
       * @brief Konstruktor
       */
        aghVector();

       /**
       * @brief Konstruktor kopiujący
       * @param right - pojemnik
       */
       aghVector(aghContainer<T> const &);

        /**
       * @brief Dekonstruktor
       */
        ~aghVector();

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
        T& at(int index) const;

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
        aghVector<T>& operator=(aghVector<T> const& right);


};

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif
