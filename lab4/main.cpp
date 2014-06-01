#include "aghInclude.h"
using namespace std;

int main()
{
    aghVector<int> vector(4);
    vector.append(2);
    cout << vector.size() << endl;   //ile jest wsadzonych elementow do wektora
    cout << vector.at(0) << endl;
    vector.append(0);
    vector.append(3);
    cout << vector.size() << endl;   //ile jest wsadzonych elementow do wektora
    cout << vector.at(2) << endl;
    vector.insert(0, 9);
    cout << vector.size() << endl;
    cout << vector.at(0) << endl;
    return 0;

}
