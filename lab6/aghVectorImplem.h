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

    this->aghContainer<T>::operator =(other);
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
        cout << "\n\n error resize\n";
      throw aghException(3, "Blad pamieci", __FILE__, __LINE__);    
    }

    else
    {
        int ileEl = size() < nowyRozmiar ? size() : nowyRozmiar;
        T *temp = new T[nowyRozmiar];

        if(dane != NULL) 
        {
            int minsize = count < nowyRozmiar ? count : nowyRozmiar;
            memcpy(temp, dane, minsize*sizeof(T));
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
    count = 0;
    iRozmiar = 0;
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
    if( (index < 0) || (index >= size()) ) 
    {
        cout << "\n\n error at\n";
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
    }

    else
        return dane[index];   
}

template<class T>
bool aghVector<T>::insert(int index, T const& element)
{
    if( (index < 0) || (index > iRozmiar)) 
    {
        cout << "\n\n error insert\n";
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
    }

    else
    {
        if( wolneMiejsce() <= 0)  
		{    
			if(wolneMiejsce() == 0)
				powieksz();			

			else			
				for( int i = 0; i < (iRozmiar - count); i++)			
            			powieksz();			
			
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
    if( (index < 0) || index > iRozmiar) 
    {
        cout << "\n\n error remove\n";
        throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
    }

    else
    {

        if(size() > 0)
        {  

            for (int i = index; i < size()-1; ++i)
                dane[i] = dane[i+1];
                // max: dane[size()-2] = dane[size()-1];
            resize(iRozmiar - 1);
			
           
        }
        return true; 
    }
   return false;
}

template<class T>
aghVector<T>& aghVector<T>::operator=(aghVector<T> const & right)
{
    this->aghContainer<T>::operator =(right);
        return *this;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif
