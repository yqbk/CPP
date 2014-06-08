#ifndef AGHSNODE_H
#define AGHSNODE_H

template<class T>
class aghSnode
{

    private:

       aghSnode<T>* ptrNext;

    protected:

        T data;

    public:

        aghSnode(T data);
        aghSnode();
        ~aghSnode();

        T& getData();
        void setData(T data);

        aghSnode<T>* getNext() const;
        void setNext(aghSnode<T>* ptrNext);

};


#endif
