#ifndef AGHVECTORIMPLEM_H
#define AGHVECTORIMPLEM_H


//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghVector<T>::aghVector()
{
    dane = NULL;
    iRozmiar = 1;
    count = 0;    

    resize(iRozmiar);

}


template<class T>
aghVector<T>::aghVector(aghContainer<T> const & other) 
{

    dane = NULL;
    iRozmiar = 1;
    count = 0;   
    
    resize(iRozmiar);

    for(int i=0; i<other.size(); i++)
    {
        this->append(other[i]);

        if(wolneMiejsce() == 0)
            powieksz();
    }
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
      throw aghException(3, "Blad pamieci", __FILE__, __LINE__);    

    else
    {
        T *temp = new T[nowyRozmiar];

        int ileEl = size() < nowyRozmiar ? size() : nowyRozmiar;

        if(dane != NULL) 
        {
            int roznica = nowyRozmiar - size();

            
            if (roznica < 0)      
                for (int i = size(); i > nowyRozmiar ; --i)                
                    dane[i].~T(); 
            

            for(int i = 0; i < nowyRozmiar && i < size(); i++)       
                temp[i] = dane[i];

            //memcpy(temp, dane, nowyRozmiar*sizeof(T) ); 
            
            this->kasuj();
        }                       
    
        this->iRozmiar = nowyRozmiar;
        this->count = ileEl;        
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
    if( (index < 0)) 
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

    else
    {
        if(index > iRozmiar)
            for (int i = 0; i < index - iRozmiar; ++i)
                powieksz();

        if( wolneMiejsce() == 0)            
            powieksz();


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
    if( (index < 0)) 
        //throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
        cout << "\ntralala\n";

    else
    {
        if(index >= 0 && index <= iRozmiar)
        {
            if(size() > 0)
            {
                T *temp= new T[iRozmiar -1];

                int j=0;
                for(int i=0; i<size(); i++)
                {
                    if (i != index)
                    {
                        temp[j]=dane[i];
                        j++;
                    }
                }

                delete [] dane;
                dane = temp;
                count--;
                iRozmiar--;
/*

                for (int i = index; i < size(); ++i)
                    dane[i] = dane[i+1];

                //dane[size()].~T(); 

                resize(iRozmiar - 1);
                count--;
                */
            }

            return true; 
        
        }
        else
            cout << "\n\nwyskakuje\n";

    }

   return false;
}

template<class T>
aghVector<T>& aghVector<T>:: operator=(aghVector<T> const& right){

this->aghContainer<T>::operator =(right);
   return *this;

}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif