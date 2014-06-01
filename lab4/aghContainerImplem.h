#ifndef AGHCONTAINERIMPLEM_H
#define AGHCONTAINERIMPLEM_H


//------------------------------------------------------------------------
template<class T>
aghContainer<T>::~aghContainer()
{

}


//------------------------------------------------------------------------
template<class T>
void aghContainer<T>::append(T const& element)
{
	if(! insert( size(), element) ) 
      throw aghException(0, "Operacja nie powiodla sie", __FILE__, __LINE__);    
}


//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::replace(int index, T const & element)
{

	bool wynik = false;

	if(index < 0 || index >= size()) 
    	throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

    else
    {
    	wynik = remove(index);

    	if(wynik)
        	insert(index, element);        	
    }

    return wynik;
}


//------------------------------------------------------------------------
template<class T> void aghContainer<T>::clear(void) {
   if(isEmpty()) {
      throw aghException(0, "Operation failed", __FILE__, __LINE__);
   } else {
      int length = size();
      for(int i = length; i > 0; i--)
         remove(i);
   }
   return;
}

//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::isEmpty(void) const
{
    return ( size() <= 0 );
}


//------------------------------------------------------------------------
template<class T>   ///nie wiem
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
	int wynik = -1;    

	if(_from >= size() || _from < 0)	// ?
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

  	else
  	{
    	for (int i = _from; i < size(); i++)    	
        	if (at(i) == _value)        	
            	return i;   	
	}
    return wynik;
}


//------------------------------------------------------------------------
template<class T>	// ?????
bool aghContainer<T>::contains(T const& _value, int _from) const
{
	bool wynik = false;

	if(_from >= size() || _from < 0)	// ?
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

  	else
  	{
    	if (indexOf(_value, _from) != -1)
			return true;					// ?????
    }
    return wynik;
}


//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghContainer<T> const & aghContainer<T>::operator=(aghContainer<T> const & right)

{
	if(this != &right)
	{
		if(!this->isEmpty())
			this->clear();

		*this += right;
	}

	return *this;
}


//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right) const
{
	bool wynik = false;

	wynik = (right.size() == size());

	if (wynik)
	{
		for (int i = 0; wynik && i < size(); ++i)		
			wynik = (right.at(i) == at(i));
	}
		
	return wynik;
}


//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right) const
{
	return !(*this == right);
}


//------------------------------------------------------------------------
template<class T>
aghContainer<T> & aghContainer<T>::operator+=(aghContainer<T> const& right)
{
   for(int i = 0; i < right.size(); i++) 
      append(right[i]);
   
   return *this;
}


//------------------------------------------------------------------------
template<class T>
aghContainer<T> & aghContainer<T>::operator+=(T const& element)
{
   append(element);
   return *this;
}


//------------------------------------------------------------------------
template<class T>
aghContainer<T> & aghContainer<T>::operator<<(T const& element)
{
	return *this += element;
}


//------------------------------------------------------------------------
template<class T>
aghContainer<T> & aghContainer<T>::operator<<(aghContainer<T> const& right)
{
	return *this += right;
}


//------------------------------------------------------------------------

template<class U> ostream& operator<<(ostream& stream, aghContainer<U> const& right) {
   for(int i = 0; i < right.size(); i++) {
      stream << right[i];
      stream << endl;
   }
   return stream;
}


//------------------------------------------------------------------------

template<class T>
T & aghContainer<T>::operator[](int n) const
{
	if(n < 0 || n >= size())
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);

  	else
    	return at(n);
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif