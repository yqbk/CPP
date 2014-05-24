#ifndef TEST_H
#define TEST_H

class Test
{
    protected:

        string strNazwaTestu;
        int iIloscLosowan;
        int *wyniki;
        Generator *wskGenerator;

    public:

        Test();
        ~Test();
        virtual void testuj() = 0;


};

#endif 