#ifndef _LAZY_LAZY_H_
#define _LAZY_LAZY_H_

#include <iostream>
#include "Common/Types.h"

namespace seq
{

  template <typename T>
    class Sequence;

  template <typename T>
    class Lazy
    {
      public:
        Lazy (TYPE(SimpleCallback) construct);
        ~Lazy () = default;
        const TYPE(SequencePair) value ();

      private:
        TYPE(SimpleCallback) _construct;
        bool _constructed;
        T _value;
        Sequence<T>* _tail;

        //avoid copying
        Lazy (const Lazy<T>&);
        Lazy& operator= (const Lazy<T>&);
    };

  template<typename T>
    Lazy<T>::Lazy (TYPE(SimpleCallback) construct) : 
      _constructed(false),
      _tail(0)
    {
      _construct = construct;
    }

  template<typename T>
    const TYPE(SequencePair) Lazy<T>::value()
    {
      if (!_constructed)
      {
        auto val = (_construct)();
        _value = val.first;
        _tail = val.second;
        _constructed = true;
      }

      return std::make_pair(_value, _tail);
    }
}


#endif
