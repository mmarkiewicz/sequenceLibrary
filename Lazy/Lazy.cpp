#include "Lazy/Lazy.h"

namespace seq
{
  template<typename T>
  Lazy<T>::Lazy (const TYPE(SimpleCallback)& construct) : 
    _construct(construct), 
    _constructed(false)
  {}

  template<typename T>
  const TYPE(SequencePair)& Lazy<T>::value()
  {
    if (!_constructed)
    {
      _value = _construct();
      _constructed = true;
    }
    
    return _value;
  }
}

