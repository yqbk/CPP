#ifndef TEST4_H
#define TEST4_H


class Test4: public Test 
{
   	public:

      	Test4(string strNazwaTestu, Generator* wskGenerator, int iIloscLosowan);

      	~Test4();

      	void testuj(void);

      	void print(ostream& = cout);

};

#endif 