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
        const TYPE(SequencePair)& value ();

      private:
        TYPE(SimpleCallback) _construct;
        bool _constructed;
        TYPE(SequencePair)* _value;

        //avoid copying
        Lazy (const Lazy<T>&);
        Lazy& operator= (const Lazy<T>&);
    };

  template<typename T>
    Lazy<T>::Lazy (TYPE(SimpleCallback) construct) : 
      _constructed(false)
    {
      _construct = construct;
    }

  template<typename T>
    const TYPE(SequencePair)& Lazy<T>::value()
    {
      if (!_constructed)
      {
        auto val = (_construct)();
        std::cout << val.first << std::endl;
        _value = &val;
        _constructed = true;
      }

      return *_value;
    }
}


#endif
