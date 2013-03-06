#ifndef _SEQUENCE_CALLBACK_SMAP_H_
#define _SEQUENCE_CALLBACK_SMAP_H_

#include <utility>
#include <memory>
#include "Sequence/Sequence.h"

namespace seq
{

  template <typename S, typename T>
  class Smap : public Type<T>::SimpleCallback
  {
    public:
      typedef std::function<T(S)> fType;
      typename Type<T>::SequencePair operator() (void);
      Smap (const fType f, Sequence<S>* const s) : _s(s), _f(f) {}

    protected:
      std::shared_ptr<Sequence<S>> _s;
      const fType _f;

  };

  template <typename S, typename T>
  typename Type<T>::SequencePair Smap<S,T>::operator() (void)
  {
    Smap<S,T> cb(_f,_s->tail());
    return std::make_pair(_f(_s->head()), new Sequence<T>(cb)); 
  }
}

#endif
