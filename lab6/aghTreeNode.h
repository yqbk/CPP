#ifndef AGHTREENODE_H
#define AGHTREENODE_H

template<class T>
class aghTreeNode
{
    public:
        aghTreeNode();
        ~aghTreeNode();
        void setDane(T dane);
        void setPrawy(aghTreeNode<T>* wskPrawy);
        void setLewy(aghTreeNode<T>* wskLewy);
        void setPoprzedni(aghTreeNode<T>* wskPoprzedni);
        aghTreeNode<T>* getPrawy();
        aghTreeNode<T>* getLewy();
        aghTreeNode<T>* getPoprzedni();
        T getDane();
    protected:
    private:
        aghTreeNode<T>* wskPrawy;
        aghTreeNode<T>* wskLewy;
        aghTreeNode<T>* wskPoprzedni;
        T dane;

};

#endif // AGHTREENODE_H
