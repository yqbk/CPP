#ifndef AGHTREEIMPLEM_H
#define AGHTREEIMPLEM_H

template<class T>
aghTree<T>::aghTree()
{
    this->wskRoot = NULL;
    this->iRozmiar = 0;
}

template<class T>
aghTree<T>::aghTree(aghContainer<T> & kopia)
{
    this->wskRoot = NULL;
    this->iRozmiar = 0;

    this->aghContainer<T>::operator=(kopia);
}

template<class T>
aghTree<T>::~aghTree()
{
    for (int i = 0; i < size()-1; ++i)    
    	remove(0);   	

	this->wskRoot = NULL;
    this->iRozmiar = 0;    
}

//--------------------------------------------------------------------------
template<class T>
void aghTree<T>::setRoot(aghTreeNode<T>* wskRoot)
{
    this->wskRoot = wskRoot;
}

template<class T>
void aghTree<T>::setRozmiar(unsigned int iRozmiar)
{
    this->iRozmiar = iRozmiar;
}

//--------------------------------------------------------------------------
template<class T>
aghTreeNode<T>* aghTree<T>::getRoot() const
{
    return this->wskRoot;
}

template<class T>
aghTreeNode<T>* aghTree<T>::getNajmniejszy(aghTreeNode<T>* node) const
{
	aghTreeNode<T>* temp;

	if(node != NULL)
	{
		temp = node;
		while(temp->getLewy() != NULL)
			temp = temp->getLewy();
	}
	return temp;
}

template<class T>
int aghTree<T>::getLength(aghTreeNode<T>* node) const
{
  aghTreeNode<T>* temp;
  int counter = 0;

  if(node != NULL)
  {
    temp = node;
    while(temp->getLewy() != NULL)
    {
      temp = temp->getLewy();
      counter++;
    }
  }
  return counter;
}

template<class T>
aghTreeNode<T>* aghTree<T>::getNode(int index) const
{

	aghTreeNode<T>* wynik = NULL;
 	int counter = 0;

	if (index < 0)
		throw aghException(0, "Niepoprawny index",__FILE__, __LINE__);

	else
	{
		if(index >= size())		
			index = size();		

		int counter = -1;

 		aghTreeNode<T>* temp = wskRoot; 		

 		while(!wynik)
 		{
 			temp = getNajmniejszy(temp);

 			if(++counter == index)
 				wynik = temp;

 			while(!temp->getPrawy() && !wynik)
 			{
 				if(temp != temp->getPoprzedni()->getPrawy())
 				{
 					temp = temp->getPoprzedni();
 					if(++counter == index)
 						wynik = temp;
 				}
 				else
 				{
 					while(temp->getPoprzedni()->getPrawy() == temp)
 						temp = temp->getPoprzedni();

 					temp = temp->getPoprzedni();

 					if(++counter == index)
 						wynik = temp;
 				}
 			}

 			if(!wynik)
 				temp = temp->getPrawy();
 		}
 	}
 	return wynik;

}


//--------------------------------------------------------------------------


template<class T>
bool aghTree<T>::insert(int index, T const & element)
{

    if(wskRoot == NULL)
    {
        aghTreeNode<T>* punkt = new aghTreeNode<T>(element);

        this->setRoot(punkt);
        wskRoot->setDane(element);
    }
    else
    {
    	aghTreeNode<T>* temp = wskRoot;
    	aghTreeNode<T>* punkt = NULL;
    	
    	while(temp)
    	{
    		punkt = temp;
    		temp = element < temp->getDane() ? temp = temp->getLewy() : temp->getPrawy();
    	} 

		aghTreeNode<T>* wstawiany = new aghTreeNode<T>(element, punkt, NULL, NULL);

    	if(wstawiany->getDane() < punkt->getDane())
    		punkt->setLewy(wstawiany);
    	else
    		punkt->setPrawy(wstawiany);   

	}
	iRozmiar++;

	return true;
}


template<class T>
T& aghTree<T>::at(int index) const
{
	if (index <0 || index > size())
		throw aghException(0, "Niepoprawny index", __FILE__, __LINE__);
	else
		return getNode(index)->getDane();
}



template<class T>
int aghTree<T>::size(void) const
{
    return this->iRozmiar;
}

template<class T>
bool aghTree<T>::remove(int index)
{
  if(index < 0 || index >= size())
    throw aghException(0, "niepoprawny index", __FILE__, __LINE__);

   aghTreeNode<T>* temp, *temp1;
   aghTreeNode<T>* usuwany = getNode(index);
   bool result;

      if(!usuwany->getLewy() || !usuwany->getPrawy())
         temp = usuwany;
      else
      {
      	//----------------------------------------
      	aghTreeNode < T > * podstawienie = NULL;
      if(usuwany->getPrawy())
         podstawienie = getNajmniejszy(usuwany->getPrawy());
      else 
      {
         aghTreeNode<T>* tempp;
         podstawienie = usuwany;

         do {
            tempp = podstawienie;
            podstawienie = podstawienie->getPoprzedni();
         } while(podstawienie && (podstawienie->getLewy() != tempp));
      }

      	//----------------------------------------
         temp = podstawienie;
      }


      if(temp->getLewy())
         temp1 = temp->getLewy();
      else
         temp1 = temp->getPrawy();
     

      if(temp1)
         temp1->setPoprzedni(temp->getPoprzedni());


      if(!temp->getPoprzedni())
         setRoot(temp1);
      else if(temp == temp->getPoprzedni()->getLewy())
         temp->getPoprzedni()->setLewy(temp1);
      else
         temp->getPoprzedni()->setPrawy(temp1);


      if(temp != usuwany)
         usuwany->setDane(temp->getDane());

      delete temp;
      iRozmiar--;


  return true;

}

template<class T>
aghTree<T> const & aghTree<T>::operator=(aghTree<T> const & right)
{
	this->aghContainer<T>::operator=(right);

	return *this;
}

#endif


