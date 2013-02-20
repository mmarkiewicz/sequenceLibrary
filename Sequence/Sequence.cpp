#include "Sequence/Sequence.h"

namespace seq 
{

template <typename T>
const T& Sequence<T>::head ()
{
  auto data = _data.value();
  return data.first;
}

template <typename T>
const Sequence<T>* Sequence<T>::tail ()
{
  auto data = _data.value();
  return data.second;
}
  
}

