#include "aghInclude.h"

// ---------------------------------------------------------
// ---------------------------------------------------------

generator::generator();
{

}

generator::generator(int _count, int _seed, string name)
{
  count = _count;
  seed = _seed;
  name = _name;
}

generator::~generator();
{

}

// ---------------------------------------------------------
void generator::nazwa(ostrem & stream) const
{
  stream << name << endl;
}

void generator::print(ostrem & stream) const
{
  stream << los << endl;
}




// ---------------------------------------------------------
// ---------------------------------------------------------
