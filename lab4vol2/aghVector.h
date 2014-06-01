#ifndef AGHVECTOR_H
#define AGHVECTOR_H

#include "aghContainer.h"


template<class T>
class aghVector : public aghContainer<T>
{

    private:

        T *dane;
        int iRozmiar;
        int count;

        void resize(int nowyRozmiar);

        void kasuj();

        void powieksz();

        int wolneMiejsce();

    public:

        aghVector();

        aghVector(aghVector<T> const & kopia);

      	aghVector(aghContainer<T> const & other);

      	~aghVector();

//------------------------------------------------------------------------

        bool insert(int, T const &);  //wstawianie elementu do pojemnika

        T& at(int) const;  //Metoda zwracaj¹ca wartoœæ elementu

        int size(void) const;  // Metoda zwracaj¹ca iloœæ elementów

        bool remove(int);   //Metoda usuwaj¹ca wybrany element

//------------------------------------------------------------------------
aghVector<T>& operator=(aghVector<T> const& right);


};



//------------------------------------------------------------------------
//------------------------------------------------------------------------


#endif
