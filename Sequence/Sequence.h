#include "Lazy/Lazy.h"

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
    const Sequence<T>* tail ();
    ~Sequence() = default;
    Sequence (const SimpleCallback<T>& callback) { 
      _data(callback);
    }

  protected:
    Lazy<T> _data;

  private:
    Sequence () = delete;
    Sequence (const Sequence<T>&);
    Sequence<T>& operator=(const Sequence<T>&);
};
  
}

