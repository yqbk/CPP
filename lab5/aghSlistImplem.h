#ifndef AGHSLISTIMPLEM_H
#define AGHSLISTIMPLEM_H

template<class T>
aghSlist<T>::aghSlist()
{
    this->iSize = 0;
    this->ptrRoot = NULL;
}

template<class T>
aghSlist<T>::aghSlist(aghContainer<T> & element)
{
    this->iSize = 0;
    this->ptrRoot = NULL;

    this->aghContainer<T>::operator =(element);
}

template<class T>
aghSlist<T>::~aghSlist()
{
    if(!this->isEmpty())
      this->clear();

    this->iSize = 0;
    this->ptrRoot = NULL;
}

 template<class T>
 bool aghSlist<T>::insert(int index, T const & element)
 {
     if (index < 0 || index > this->size())
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

     aghSnode<T>* newElement = new aghSnode<T>(element);

     if (this->ptrRoot == NULL)     
        this->ptrRoot = newElement;
     
     if (index == 0)
     {
         newElement->setNext(this->ptrRoot);
         this->ptrRoot = newElement;
     }
     else
     {
         aghSnode<T>* aktualny = this->ptrRoot;

         for (int i = 0; i < index - 1; i++)         
             aktualny = aktualny->getNext();         

         newElement->setNext(aktualny->getNext());
         aktualny->setNext(newElement);
     }
     
     this->iSize++;
     return true;
}

template<class T>
T& aghSlist<T>::at(int index) const
{
    if(index < 0 || index >= this->size())
    {
        throw aghException(0, "out of range", __FILE__, __LINE__);
    }

    aghSnode<T>* tmp = this->ptrRoot;
    for(int i=0; i < index; i++)
    {
        tmp = tmp->getNext();
    }
    return tmp->getData();
}

template<class T>
int aghSlist<T>::size(void) const
{
    return this->iSize;
}

template<class T>
bool aghSlist<T>::remove(int index)
{
    if (index < 0 || index >= this->size())
    {
        return false;
    }
    if (index == 0)
    {
        aghSnode<T>* aktualny = this->ptrRoot;
        this->ptrRoot = aktualny->getNext();
        delete aktualny;
    }
    else
    {
        aghSnode<T>* aktualny = this->ptrRoot;
        for (int i = 0; i < index - 1; i++)
        {
            aktualny = aktualny->getNext();
        }
        aghSnode<T>* doUsuniecia = aktualny;
        doUsuniecia = doUsuniecia->getNext();
        aktualny->setNext(doUsuniecia->getNext());
        delete doUsuniecia;
    }
    this->iSize--;
    return true;
}

template<class T> 
aghSlist<T> & aghSlist<T>::operator=(aghSlist<T> const & element)
{
   this->aghContainer<T>::operator=(element);
   return *this;
}

#endif
