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
  if(insert(size(), element) == false) 
  {
    cout << "\n\n error Container append\n";
      throw aghException(0, "Operacja nie powiodla sie", __FILE__, __LINE__);    
  }
}

//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::replace(int index, T const & element)
{

	bool wynik = false;

	if(index < 0 || index >= size()) 
  {
    cout << "\n\n error Container replace\n";
    	throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
  }

    else
    {
    	wynik = remove(index);

    	if(wynik)
        	wynik = insert(index, element);        	
    }

    return wynik;
}

//------------------------------------------------------------------------
template<class T> void aghContainer<T>::clear(void) 
{
   while(size())
      remove(size()-1);   
}

//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::isEmpty(void) const
{
    return ( size() == 0 );
}

//------------------------------------------------------------------------
template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
	 if(_from >= size() || _from < 0)
   {
    cout << "\n\n error Container indexof\n";
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
   }

   else
   {
    	for (int i = _from; i < size(); i++)    	
        	if (at(i) == _value)        	
            	return i;   	
	 }
  
   return -1;
}

//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{
	if(_from >= size() || _from < 0)
  {
    cout << "\n\n error Container contains\n";
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
  }

  else  
      return (indexOf(_value, _from) != -1);
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghContainer<T> const & aghContainer<T>::operator=(aghContainer<T> const & right)
{
	if(this != &right)
	{
      cout << "\n\n nie rowne, przeypisanei\n\n";
		  if(!this->isEmpty())
			   this->clear();

		  *this += right;
	}

	return *this;
}

//------------------------------------------------------------------------
template<class T>
T & aghContainer<T>::operator[](int n) const
{
  if(n < 0 || n >= size())
  {
    cout << "\n\n error Container append\n";
      throw aghException(1, "Niepoprawny index", __FILE__, __LINE__);
  }

  else
      return at(n);
}

//------------------------------------------------------------------------
template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right) const
{	
	bool wynik = (size() == right.size());

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
    {
      cout << "\n przepisuje\n";
      append(right[i]);
    }
   
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
template<class M> ostream & operator<<(ostream& stream, aghContainer<M> const & right) 
{
   for(int i = 0; i < right.size(); i++) 
      stream << right[i] << endl;
   
   return stream;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
#endif