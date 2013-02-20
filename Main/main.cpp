#include <iostream>

#include "Sequence/Callbacks/Snat.h"

using namespace seq;

int main(int argc, char**)
{
  std::unary_function<int,int> f = [](int x) {std::cout << "wykonanie dla " << x << std::endl; return x+1;};
	Snat<int> callback(f, 1);

  Sequence<int>* s = new Sequence<int>(callback);
  for (int i=0; i<5; ++i)
  {
    std::cout << s->head() << std::endl;
    s = s->tail();
  }
  return 0;
}
