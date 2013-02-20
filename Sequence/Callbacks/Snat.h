#include "Lazy/Lazy.h"

namespace seq
{

template <typename T>
class Snat : public SimpleCallback<T>
{
  public:
    struct fType : public std::unary_function<T,T> {};
    SequencePair<T> operator() (void);
    Snat (const fType& f, const T& start) : _f(f), _start(start) {}

  protected:
    const T& _start;
    const fType& _f;
};

template <typename T>
class SnatP : public Snat<T>
{
  public:
    SequencePair<T> operator() (void);
};

}
