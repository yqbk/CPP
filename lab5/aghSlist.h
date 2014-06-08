#ifndef AGHSLIST_H
#define AGHSLIST_H

template<class T>
class aghSlist : public aghContainer<T>
{

    private:

        aghSnode<T>* ptrRoot;
        int iSize;

    public:

        aghSlist();
        aghSlist(aghContainer<T> & element);
        ~aghSlist();

        bool insert(int index, T const & element);
      	T& at(int) const;
        int size(void) const;
        bool remove(int index);

        aghSlist<T> & operator=(aghSlist<T> const & element); 


};


#endif
