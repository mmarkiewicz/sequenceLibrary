#include <iostream>

#include "Sequence/Callbacks/Snat.h"
#include "Sequence/Sequence.h"

using namespace seq;

int main(int argc, char**)
{
  Snat<int>::fType f = [](int x) {return x+1;};
  Snat<int> callback(f, 1);
  Sequence<int>* s = new Sequence<int>(callback);
  for (int i=0; i<5; ++i)
  {
    std::cout << s->head() << std::endl;
    s = s->tail();
  }
  return 0;
}
