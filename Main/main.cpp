#include <iostream>
#include <vector>

#include "Sequence/Callbacks/Snat.h"
#include "Sequence/Callbacks/Smap.h"
#include "Sequence/Sequence.h"
#include "Sequence/Utils.h"

using namespace seq;

template <typename T>
void printSeq(Sequence<T>* s, uint16_t count)
{
  if (count == 0)
    return;
  std::cout << s->head() << std::endl;
  printSeq(s->tail(), count-1);
}

int main(int argc, char**)
{
  Snat<int>::fType f = [](int x) { std::cout << "a\n"; return x+1;};
  Snat<int> callback(f, 0);
  Sequence<int>* s = new Sequence<int>(callback);

  std::vector<Sequence<int>*> v;
  ssplit<int>(s, 3, v);
  printSeq<int>(v[1], 14);
  return 0;
}
