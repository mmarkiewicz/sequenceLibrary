#include "Lazy/Lazy.h"

namespace seq
{
  template<typename T>
  Lazy<T>::Lazy (const SimpleCallback<T>& construct) : 
    _construct(construct), 
    _constructed(false)
  {}

  template<typename T>
  const SequencePair<T>& Lazy<T>::value()
  {
    if (!_constructed)
    {
      _value = _construct();
      _constructed = true;
    }
    
    return _value;
  }
}

