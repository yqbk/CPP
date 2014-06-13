#ifndef AGHSLISTIMPLEM_H
#define AGHSLISTIMPLEM_H

//------------------------------------------------------------------------
//------------------------------------------------------------------------
template<class T>
aghSlist<T>::aghSlist()
{
    this->ptrRoot = NULL;
}

template<class T>
aghSlist<T>::aghSlist(aghContainer<T> & element)
{
    this->ptrRoot = NULL;
    this->aghContainer<T>::operator =(element);
}

template<class T> 
aghSlist<T>::aghSlist(aghSlist<T> const & right) 
{
   ptrRoot = NULL;
   this->aghContainer<T>::operator =(right);
}

template<class T>
aghSlist<T>::~aghSlist()
{
    if(!this->isEmpty())
      this->clear();

    this->ptrRoot = NULL;
}

//------------------------------------------------------------------------
template<class T>
void aghSlist<T>::nowaLista(T const& element)
{
    aghSnode<T>* newElement = new aghSnode<T>(element);

    this->ptrRoot = newElement;
}

template<class T>
void aghSlist<T>::dodajPocz(T const& element)
{
    aghSnode<T>* newElement = new aghSnode<T>(element, ptrRoot);

    this->ptrRoot = newElement;
}

template<class T>
void aghSlist<T>::dodajEnd(T const& element)
{
    getNode(size() - 1)->setNext(new aghSnode<T>(element));   
}

template<class T>
void aghSlist<T>::dodaj(T const & element, int index)
{
    
    aghSnode<T>* aktualny = this->ptrRoot;

    for (int i = 0; i < index - 1; i++)         
        aktualny = aktualny->getNext();         

    aghSnode<T>* newElement = new aghSnode<T>(element, aktualny->getNext());
    aktualny->setNext(newElement);
}

template<class T>
void aghSlist<T>::usunPocz()
{
    aghSnode<T>* aktualny = this->ptrRoot;

    this->ptrRoot = aktualny->getNext();
    delete aktualny;
}

template<class T>
void aghSlist<T>::usunEnd()
{
    aghSnode<T>* aktualny = getNode(size() - 2);
    
    delete aktualny->getNext();
    aktualny->setNext(NULL);
}

template<class T>
void aghSlist<T>::usun(int index)
{
    aghSnode<T>* aktualny = this->ptrRoot;

    for (int i = 0; i < index - 1; i++)         
        aktualny = aktualny->getNext();       

    aghSnode<T>* doUsuniecia = aktualny;

    doUsuniecia = doUsuniecia->getNext();
    aktualny->setNext(doUsuniecia->getNext());

    delete doUsuniecia;
}

template<class T> 
aghSnode<T>* aghSlist<T>::getNode(int n) const 
{

   if(n >= size() || n < 0) 
      throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

   else 
   {
        aghSnode<T>* aktualny = ptrRoot;

        for (int i = 0; i < n; i++)
            aktualny = aktualny->getNext();

        return aktualny;
   }

}

//------------------------------------------------------------------------
 template<class T>
 bool aghSlist<T>::insert(int index, T const & element)
 {

    if (index < 0 || index > this->size())
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);            

    else
    {             
        if (index == 0) 
        {         
            dodajPocz(element);            
        }

        else
        if (index == size())
        {
            dodajEnd(element);            
        }

        else 
        {
            dodaj(element, index);            
        }

        return true;
    }
    return false;
}

template<class T>
T& aghSlist<T>::at(int index) const
{
    if (index < 0 || index > this->size())
        throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

    else    
        return getNode(index)->getData();    
}

template<class T>
int aghSlist<T>::size(void) const
{
   int ileEl = 0;

   aghSnode<T>* aktualny = ptrRoot;
   while(aktualny != NULL) 
   {    
      ileEl++;
      aktualny = aktualny->getNext();
   }
   return ileEl;
}

template<class T>
bool aghSlist<T>::remove(int index)
{
    if (index < 0 || index >= this->size())                         
        return false;
    
    if (index == 0)
    {                                                 
        usunPocz();
    }

    else
    if ( index == size())
    {
        usunEnd();
    }

    else
    {
        usun(index);
    }

    return true;
}

//------------------------------------------------------------------------
template<class T> 
aghSlist<T> & aghSlist<T>::operator=(aghSlist<T> const & element)
{
   this->aghContainer<T>::operator=(element);
   return *this;
}

#endif