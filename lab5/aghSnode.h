#ifndef AGHSNODE_H
#define AGHSNODE_H

template<class T>
class aghSnode
{

    public:

        aghSnode(T data);
        aghSnode();
        ~aghSnode();

        T& getData();
        void setData(T data);

        aghSnode<T>* getNext();
        void setNext(aghSnode<T>* ptrNext);

    private:

       aghSnode<T>* ptrNext;

    protected:

        T data;

};


#endif
