#ifndef _SEQUENCE_CALLBACK_SNAT_H_
#define _SEQUENCE_CALLBACK_SNAT_H_

#include "Lazy/Lazy.h"

namespace seq
{

  template <typename T>
    class Snat : public Type<T>::SimpleCallback
  {
    public:
      typedef std::function<T(T)> fType;
      TYPE(SequencePair) operator() (void);
      Snat (const fType& f, const T& start) : _start(start), _f(f) {}

    protected:
      const T& _start;
      const fType _f;
  };

  template <typename T>
    class SnatP : public Snat<T>
  {
    public:
      SnatP (const typename Snat<T>::fType& f, const T& start) : Snat<T>(f,start) {}
      TYPE(SequencePair) operator() (void);
  };


  template <typename T>
    TYPE(SequencePair) Snat<T>::operator() (void)
    {
      return std::make_pair(_start, new Sequence<T>(SnatP<T>(_f, _start)));
    }

  template <typename T>
    TYPE(SequencePair) SnatP<T>::operator() (void)
    {
      const T& val = this->_f (this->_start);
      return std::make_pair(val, new Sequence<T>(SnatP<T>(this->_f, val)));
    }

}

#endif
