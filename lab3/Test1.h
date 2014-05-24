#ifndef TEST1_H
#define TEST1_H
#include "Test.h"


class Test1 : public Test
{
    public:
        Test1(string strNazwaTestu, int iIloscLosowan, Generator *wskGenerator);
        ~Test1();
        void testuj();

    protected:
        int iIloscParzystych;
        int iIloscNieparzystych;
    private:
};

#endif // TEST1_H
