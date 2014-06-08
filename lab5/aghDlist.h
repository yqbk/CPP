#ifndef AGHDLIST_H
#define AGHDLIST_H



template<class T>
class aghDlist : public aghContainer<T>
{
    public:

        aghDlist();
        aghDlist(aghContainer<T> & element);
        ~aghDlist();

        bool insert(int index, T const & element);
      	T& at(int) const;
        int size(void) const;
        bool remove(int index);

        aghDlist<T>& operator=(aghDlist<T> const &);

    private:

        aghDnode<T>* ptrRoot;
        aghDnode<T>* ptrEnd;
        int iSize;



};


#endif
