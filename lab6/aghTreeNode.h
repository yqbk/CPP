#ifndef AGHTREENODE_H
#define AGHTREENODE_H

template<class T>
class aghTreeNode
{
	private:

        aghTreeNode<T>* wskPrawy;
        aghTreeNode<T>* wskLewy;
        aghTreeNode<T>* wskPoprzedni;

        T dane;

    public:

        aghTreeNode();
        aghTreeNode(T, aghTreeNode<T>* = NULL, aghTreeNode<T>* = NULL, aghTreeNode<T>* = NULL);
        ~aghTreeNode();

        void setDane(T dane);
        void setPrawy(aghTreeNode<T>* wskPrawy);
        void setLewy(aghTreeNode<T>* wskLewy);
        void setPoprzedni(aghTreeNode<T>* wskPoprzedni);
        void setNode(T, aghTreeNode<T>* = NULL, aghTreeNode<T>* = NULL, aghTreeNode<T>* = NULL);

        aghTreeNode<T>* getPrawy() const;
        aghTreeNode<T>* getLewy() const;
        aghTreeNode<T>* getPoprzedni() const;

        T& getDane();

};

#endif // AGHTREENODE_H
