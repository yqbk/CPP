#ifndef TEST3_H
#define TEST3_H

class Test3 : public Test
{

    protected:

        int **powtorzenia;

    public:

        Test3(string strNazwaTestu, int iIloscLosowan, Generator *wskGenerator);
        ~Test3();
        void testuj();



};

#endif