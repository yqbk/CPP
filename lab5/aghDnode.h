#ifndef AGHDNODE_H
#define AGHDNODE_H

template<class T>
class aghDnode : public aghSnode<T>
{

    public:

        aghDnode(T data);
        aghDnode();
        ~aghDnode();

        void setNext(aghDnode<T>* ptrNext);
        aghDnode<T>* getNext();

        void setPrev(aghDnode<T>* ptrPrev);
        aghDnode<T>* getPrev();

    private:

       aghDnode<T>* ptrNext;
       aghDnode<T>* ptrPrev;


};


#endif