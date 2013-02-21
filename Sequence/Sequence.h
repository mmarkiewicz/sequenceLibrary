#ifndef _SEQUENCE_SEQUENCE_H_
#define _SEQUENCE_SEQUENCE_H_

#include "Lazy/Lazy.h"
#include "Common/Types.h"

namespace seq
{
  template<typename T>
    class SequenceFactory;

  template<typename T>
    class Sequence
    {
      friend class SequenceFactory<T>;

      public:
      const T& head ();
      Sequence<T>* const tail ();
      ~Sequence() = default;
      Sequence (TYPE(SimpleCallback) callback) : _data(callback) {}

      protected:
      Lazy<T> _data;

      private:
      Sequence () = delete;
      Sequence (const Sequence<T>&);
      Sequence<T>& operator=(const Sequence<T>&);
    };

  template <typename T>
    const T& Sequence<T>::head ()
    {
      auto data = _data.value();
      return data.first;
    }

  template <typename T>
    Sequence<T>* const Sequence<T>::tail ()
    {
      auto data = _data.value();
      return data.second;
    }

}


#endif
