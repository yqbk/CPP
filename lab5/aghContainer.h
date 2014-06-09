/**
* \file aghContainer.h
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 31.05.2014
* \version 1.0
* \brief Plik nagłówkowy z deklarajcą klasy szablonu aghContainer
*/

#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

/**
* \class aghContainer
* \authors Jakub Syrek & Katarzyna Żukowska
* \date 31.05.2014
* \brief Klasa szablonu aghContainer
*/
template<class T>
class aghContainer
{
    public:

       /**
       * @brief Dekonstruktor
       */
        virtual ~aghContainer();

//------------------------------------------------------------------------
       /**
       * @brief Metoda virtualna która "wklada" element do pojemnika
       * @param index - index
       * @param element - wrzucany element
       * @return Wartosc logiczna
       */
        virtual bool insert(int index, T const & element) = 0; 

       /**
       * @brief Metoda virtualna która pobiera element z pojemnika
       * @param index - index
       * @return Pobrany element
       */
      	virtual T& at(int) const = 0;

       /**
       * @brief Metoda virtualna która pobiera ilosc elementow
       * @return Liczba elementow
       */
        virtual int size(void) const = 0 ; 

       /**
       * @brief Metoda virtualna która usuwa element
       * @param index - index
       * @return Wartosc logiczna
       */
        virtual bool remove(int index) = 0;   
        
//------------------------------------------------------------------------
       /**
       * @brief Metoda która wrzuca element do kontenera
       * @param element - element
       * @return Nic nie zwraca
       */
        void append(T const&); 

       /**
       * @brief Metoda która zamienia elementy
       * @param index - index 
       * @param element - element do zamiany
       * @return Wartosc logiczna
       */
        bool replace(int, T const &);

       /**
       * @brief Metoda która czysci pojemnik
       * @return Nic nie zwraca
       */
        void clear(void); 

       /**
       * @brief Metoda która sprawdza czy pojemnik jest pusty
       * @return Wartosc logiczna
       */
        bool isEmpty(void) const; 

       /**
       * @brief Metoda wyszukująca element w pojemniku przez wartość od zadanego momentu
       * @param _value - element
       * @param _from - od
       * @return Wartosc elementu
       */
        int indexOf(T const& , int  = 0) const;  

       /**
       * @brief Metoda sprawdzająca czy dany element jest już w pojemniku
       * @param _value - element
       * @param _from - od
       * @return Wartosc logiczna
       */
        bool contains(T const& , int  = 0) const; 

//------------------------------------------------------------------------
       /**
       * @brief Operator []
       * @param index - index
       * @return Element
       */
        T& operator[](int) const;

       /**
       * @brief Operator =
       * @param right - element
       * @return Pojemnik
       */
        aghContainer<T> const & operator=(aghContainer<T> const &);

       /**
       * @brief Operator ==
       * @param right - element
       * @return Wartosc logiczna
       */
        bool operator==(aghContainer<T> const &) const;

       /**
       * @brief Operator !=
       * @param right - element
       * @return Wartosc logiczna
       */
        bool operator!=(aghContainer<T> const &) const;

       /**
       * @brief Operator +=
       * @param right - element
       * @return Pojemnik
       */
        aghContainer<T> & operator+=(aghContainer<T> const &);

       /**
       * @brief Operator +=
       * @param Element - element
       * @return Pojemnik
       */
        aghContainer<T> & operator+=(T const &);

       /**
       * @brief Operator <<
       * @param element - element
       * @return Pojemnik
       */
        aghContainer<T> & operator<<(T const &);

       /**
       * @brief Operator <<
       * @param right - pojemnik
       * @return Pojemnik
       */
        aghContainer<T> & operator<<(aghContainer<T> const &);
        
       /**
       * @brief Operator <<
       * @param right - pojemnik
       * @param ostream - strumien
       * @return Pojemnik
       */
        template<class M> friend ostream& operator<<(ostream&, aghContainer<M> const&);

};

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif
