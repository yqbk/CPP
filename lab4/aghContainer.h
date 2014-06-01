
#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

template<class T>
class aghContainer
{
    public:

        //aghContainer();

        virtual ~aghContainer();

//------------------------------------------------------------------------

        virtual bool insert(int, T const&) = 0; 

      	virtual T& at(int) const = 0;

        virtual int size(void) const = 0 ; 

        virtual bool remove(int) = 0;   
//------------------------------------------------------------------------

        void append(T const&); 

        bool replace(int, T const &);

        void clear(void); 

        bool isEmpty(void) const; 

        int indexOf(T const& , int  = 0) const;  

        bool contains(T const& , int  = 0) const; 

//------------------------------------------------------------------------
        T& operator[](int) const;


        aghContainer<T> const & operator=(aghContainer<T> const &);


        bool operator==(aghContainer<T> const &) const;

        bool operator!=(aghContainer<T> const &) const;


        aghContainer<T> & operator+=(aghContainer<T> const &);

        aghContainer<T> & operator+=(T const &);


        aghContainer<T> & operator<<(T const &);

        aghContainer<T> & operator<<(aghContainer<T> const &);
        

        template<class U> friend ostream& operator<<(ostream&, aghContainer const&);


        


};


//------------------------------------------------------------------------
//------------------------------------------------------------------------

#endif