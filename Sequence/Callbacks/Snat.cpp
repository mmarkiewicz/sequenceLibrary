#include "Sequence/Callbacks/Snat.h"

namespace seq
{

template <typename T>
SequencePair<T> Snat<T>::operator() (void)
{
  return std::make_pair(_start, new Sequence<T>(SnatP<T>(_f, _start)));
}

template <typename T>
SequencePair<T> SnatP<T>::operator() (void)
{
  const T& val = this->_f (this->_start);
  return std::make_pair(val, new Sequence<T>(SnatP<T>(this->_f, val)));
}

}
