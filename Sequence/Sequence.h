#include <functional>
#include <utility>

namespace seq
{
template<typename T>
class Lazy;

template<typename T>
class SequenceFactory;

template<typename T>
class Sequence
{
  friend class SequenceFactory<T>;

  public:
    const T& head ();
    const Sequence<T>* tail ();

  protected:
    Lazy<std::pair<T,Sequence<T>*>> _data;

  private:
    //avoid constructing, Sequences can be constructed only through subclasses
    Sequence () = delete;
    //avoid copying
    Sequence (const Sequence<T>&);
    Sequence<T>& operator=(const Sequence<T>&);
};
  
}

