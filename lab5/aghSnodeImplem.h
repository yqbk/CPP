#ifndef AGHSNODEIMPLEM_H
#define AGHSNODEIMPLEM_H


template<class T>
aghSnode<T>::aghSnode()
{
    this->ptrNext = NULL;
}

template<class T>
aghSnode<T>::aghSnode(T data)
{
    this->data = data;
    this->ptrNext = NULL;
}

template<class T>
aghSnode<T>::~aghSnode()
{

}

template<class T>
T& aghSnode<T>::getData()
{
    return this->data;
}

template<class T>
void aghSnode<T>::setData(T data)
{
    this->data = data;
}

template<class T>
aghSnode<T>* aghSnode<T>::getNext() const
{
    return this->ptrNext;
}

template<class T>
void aghSnode<T>::setNext(aghSnode<T>* ptrNext)
{
    this->ptrNext = ptrNext;
}

#endif
