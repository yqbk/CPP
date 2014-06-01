#ifndef AGHVECTORIMPLEM_H
#define AGHVECTORIMPLEM_H


//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghVector<T>::aghVector()
{
    dane = NULL;
    iRozmiar = 10;
    count = 0;    

    resize(iRozmiar);

}

template<class T>
aghVector<T>::aghVector(aghVector<T> const & kopia) 
{
   *this = kopia;
}

/*
template<class T>
aghVector<T>::aghVector(aghVector<T> const & other) 
{
    dane = NULL;
    iRozmiar = 0;
    count = 0;    


    this->aghContainer<T>::operator =(other);
}
*/

template<class T>
aghVector<T>::aghVector(aghContainer<T> const & other) 
{

    dane = NULL;
    iRozmiar = 0;
    count = 0;   

    //resize(iRozmiar); 

    //*this = other;
   //this->aghContainer<T>::operator =(other);

}

template<class T>
aghVector<T>::~aghVector()
{
    kasuj();
}


//------------------------------------------------------------------------
template<class T>
void aghVector<T>::powieksz()
{
    resize(iRozmiar + 1);
    iRozmiar++;
}

template<class T>
int aghVector<T>::wolneMiejsce()
{
    return iRozmiar - count;
}


//------------------------------------------------------------------------

template<class T>
void aghVector<T>::resize(int nowyRozmiar)
{
    if(nowyRozmiar < 0)
    {
        cout << "\n\n blad resize\n";
      throw aghException(3, "Blad pamieci", __FILE__, __LINE__);
    }

    else
    {
        T *temp = new T[nowyRozmiar];

        if(dane != NULL) 
        {
            for(int i = 0; i < nowyRozmiar && i < size(); i++)       
                temp[i] = dane[i];
            
            this->kasuj();
        }

        //memcpy(temp, dane, nowyRozmiar*sizeof(T) );                
    
        this->iRozmiar = nowyRozmiar;
        this->count = size() < nowyRozmiar ? size() : nowyRozmiar;  
        this->dane = temp;
    }
}



template<class T>
void aghVector<T>::kasuj()
{
    if( dane != NULL)
        delete [] dane;

    dane = NULL;
}


//------------------------------------------------------------------------
template<class T>
int aghVector<T>::size() const
{
   return count;
}

template<class T>
T& aghVector<T>::at(int index) const
{
    if( (index < 0) || (index >= iRozmiar) ) 
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

    else
        return dane[index];   
}


template<class T>
bool aghVector<T>::insert(int index, T const& element)
{
    if( (index < 0) || (index >= iRozmiar) ) 
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
    else
    {
        if( wolneMiejsce() == 0)
        {
            powieksz();
            cout << "\n\nPowiekszam...\n";
        }

        for (int i = index + 1; i <= size(); ++i)         
            dane[i] = dane[i-1];    
        
        dane[index] = element;
        count++;
        
        return true;
    }

   return false;
}


template<class T>
bool aghVector<T>::remove(int index) 
{   
    if( (index < 0) || (index >= iRozmiar) ) 
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

    else
    {
        if(size() > 0 && index <= size())
        {
            for (int i = index; i < size(); ++i)
                dane[i] = dane[i+1];

            dane[size()].~T();  //!!!!!!!  -1

            resize(iRozmiar - 1);
            count--;

            return true; 
        }

    }

   return false;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif