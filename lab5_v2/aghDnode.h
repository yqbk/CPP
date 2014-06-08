#ifndef AGHDNODE_H
#define AGHDNODE_H

template<class T>
class aghDnode : public aghSnode<T>
{
    private:

       aghDnode<T>* ptrNext;
       aghDnode<T>* ptrPrev;

    public:

        aghDnode(T data);
        aghDnode();
        ~aghDnode();

        void setNext(aghDnode<T>* ptrNext);
        aghDnode<T>* getNext() const;

        void setPrev(aghDnode<T>* ptrPrev);
        aghDnode<T>* getPrev() const;

};

#endif