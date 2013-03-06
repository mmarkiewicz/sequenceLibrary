#ifndef _COMMON_TYPES_H_
#define _COMMON_TYPES_H_

#include <functional>
#include <utility>

#define TYPE(name) typename Type<T>::name

namespace seq
{
template <typename T>
class Sequence;

template <typename T>
class Type
{
  public:
    typedef typename std::pair<const T, Sequence<T>*> SequencePair;
    typedef std::function<TYPE(SequencePair) (void)> SimpleCallback;

  private:
    // This should not be constructed
    Type () = delete;
    Type (const Type&) = delete;
    Type& operator= (const Type&) = delete;
};

}

#endif
