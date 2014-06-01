
#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

template<class T>
class aghContainer
{
    public:

        //aghContainer();

        virtual ~aghContainer();

//------------------------------------------------------------------------

        virtual bool insert(int, T const&) = 0;  //wstawianie elementu do pojemnika

        //virtual T& at(int) const = 0;  //Metoda zwracaj¹ca wartoœæ elementu

        virtual int size(void)const = 0 ;  // Metoda zwracaj¹ca iloœæ elementów

        //virtual bool remove(int) = 0;   //Metoda usuwaj¹ca wybrany element

//------------------------------------------------------------------------

        void append(T const&); //dodawanie elementu do pojemnika

        bool replace(int, T const&);

        void clear(void); //Metoda oprozniajaca pojemniki

        bool isEmpty(void); //Metoda sprawdzaj¹ca czy pojemnik jest pusty

        int indexOf(T const& _value, int _from = 0) const;  //Metoda wyszukuj¹ca element w pojemniku przez wartoœæ od zadanego momentu

        bool contains(T const& _value, int _from = 0) const; //Metoda sprawdzaj¹ca czy dany element jest ju¿ w pojemniku

//------------------------------------------------------------------------
/*
        aghContainer<T> & operator=(aghContainer<T> const & right);

        aghContainer<T> & operator=(T const& element);


        bool operator==(aghContainer<T> const& right); //porownania

        bool operator!=(aghContainer<T> const& right);  //nierownosci


        aghContainer<T>& operator+=(aghContainer<T> const& right); //+=

        aghContainer<T>& operator+=(T const& element);


        aghContainer<T>& operator<<(T const& element);

        aghContainer<T>& operator<<(aghContainer<T> const& right);

        ostream& operator<<(ostream&, aghContainer<T> const& right);

*/
        T& operator[](int n) const; // []


};


//------------------------------------------------------------------------
//------------------------------------------------------------------------
#include "aghContainerImplem.h"
#endif //AGHCONTAINER_H
