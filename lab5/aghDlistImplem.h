#ifndef AGHDLISTIMPLEM_H
#define AGHDLISTIMPLEM_H
//------------------------------------------------------------------------
//------------------------------------------------------------------------

template<class T>
aghDlist<T>::aghDlist()
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;
}

template<class T>
aghDlist<T>::aghDlist(aghContainer<T> & element)
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

    this->aghContainer<T>::operator =(element);
}

template<class T> 
aghDlist<T>::aghDlist(aghDlist<T> const & element) 
{
    this->ptrRoot = NULL;
    this->ptrEnd = NULL;

   this->aghContainer<T>::operator =(element);
}

template<class T>
aghDlist<T>::~aghDlist()
{
    if(!this->isEmpty())
      this->clear();

    this->ptrRoot = NULL;
    this->ptrEnd = NULL;
}

template<class T>
int aghDlist<T>::size() const
{    
   int ileEl = 0;

   aghDnode<T>* aktualny = ptrRoot;
   while(aktualny != NULL) 
   {    
      ileEl++;
      aktualny = aktualny->getNext();
   }
   return ileEl;
}

//------------------------------------------------------------------------
template<class T>
void aghDlist<T>::nowaLista(T const& element)
{
    aghDnode<T>* newElement = new aghDnode<T>(element, NULL, NULL);

    this->ptrEnd = newElement;
    this->ptrRoot = newElement;
}

template<class T>
void aghDlist<T>::dodajPocz(T const& element)
{
    if (ptrRoot == NULL)
    {
        nowaLista(element);
    }
    else
    {
        aghDnode<T>* newElement = new aghDnode<T>(element, NULL, ptrRoot);

        this->ptrRoot->setPrev(newElement);
        this->ptrRoot = newElement; 
    }
}

template<class T>
void aghDlist<T>::dodajEnd(T const& element)
{
    aghDnode<T>* newElement = new aghDnode<T>(element, ptrEnd, NULL);
  
    this->ptrEnd->setNext(newElement);
    this->ptrEnd = newElement; 
}

template<class T>
void aghDlist<T>::dodaj(T const & element, int index)
{    
    aghDnode<T>* aktualny = this->ptrRoot;

    for (int i = 0; i < index; i++)            
        aktualny = aktualny->getNext(); 

    aghDnode<T>* newElement = new aghDnode<T>(element, aktualny->getPrev(), aktualny);           

    newElement->getPrev()->setNext(newElement);
    aktualny->setPrev(newElement);
}

//------------------------------------------------------------------------
template<class T>
void aghDlist<T>::usunPocz()
{
    aghDnode<T>* aktualny = this->ptrRoot;

    this->ptrRoot = aktualny->getNext();
    delete aktualny;
}

template<class T>
void aghDlist<T>::usunEnd()
{
    aghDnode<T>* aktualny = this->ptrEnd;

    this->ptrEnd = aktualny->getPrev();
    delete aktualny;
}

template<class T>
void aghDlist<T>::usun(int index)
{
    aghDnode<T>* poprzednik = this->ptrRoot;

    for (int i = 0; i < index - 1; i++)        
        poprzednik = poprzednik->getNext();

    aghDnode<T>* doUsuniecia = poprzednik->getNext();

    if(doUsuniecia->getNext() != NULL)
    {        
        aghDnode<T>* nastepnik = doUsuniecia->getNext();
        nastepnik->setPrev(doUsuniecia->getPrev());
        poprzednik->setNext(doUsuniecia->getNext());
    }    
    else
        poprzednik->setNext(NULL);

    delete doUsuniecia;
}

//------------------------------------------------------------------------
template<class T> 
aghDnode<T>* aghDlist<T>::getNode(int n) const 
{

   if(n >= size() || n < 0) 
      throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);

   else 
   {
        aghDnode<T>* temp = ptrRoot;

        for (int i = 0; i < n; i++)
            temp = temp->getNext();

        return temp;
   }

}

//------------------------------------------------------------------------
template<class T> 
aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const & element) 
{
   this->aghContainer<T>::operator=(element);
   return *this;
}

#endif
