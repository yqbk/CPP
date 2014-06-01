#ifndef AGHCONTAINERIMPLEM_H
#define AGHCONTAINERIMPLEM_H

template<class T>
aghContainer<T>::~aghContainer()
{

}


template<class T>
void aghContainer<T>::append(T const& element)
{
    this->insert(size(), element);
}

template<class T>
bool aghContainer<T>::replace(int index, T const& element)
{
    if (index >= 0 && index < size())
    {
        this->insert(index, element);
        return true;
    }
    return false;
}


template<class T>
void aghContainer<T>::clear(void)
{
    while (this->remove(size()));
}

template<class T>
bool aghContainer<T>::isEmpty(void)
{
    if (size() == 0)
    {
        return true;
    }
    return false;
}


template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
    //wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from.     Je¿eli takiego elementu nie ma to zwraca -1.

    if (_from < 0 )
    {
        return -1;
    }
    for (int i = _from; i < size(); i++)
    {
        if (this->at(i) == _value)
        {
            return i;
        }
    }
    return -1;
}



template<class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{

    if (this->indexOf(_value, _from) != -1)
    {
        return true;
    }
    return false;
}


/*
template<class T>
aghContainer<T> & aghContainer<T>::operator=(aghContainer<T> const & right)
{

}

template<class T>
aghContainer<T> & aghContainer<T>::operator=(T const& element)
{

}

template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{

}

template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{

}

template<class T>
aghContainer<T> & aghContainer<T>::operator+=(aghContainer<T> const& right)
{

}

template<class T>
aghContainer<T> & aghContainer<T>::operator+=(T const& element)
{

}

template<class T>
aghContainer<T> & aghContainer<T>::operator<<(T const& element)
{

}

template<class T>
aghContainer<T> & aghContainer<T>::operator<<(aghContainer<T> const& right)
{

}

template<class T>
ostream & aghContainer<T>::operator<<(ostream&, aghContainer<T> const& right)
{

}

template<class T>
T & aghContainer<T>::operator[](int n) const
{
    return at(n);
}

*/
#endif
