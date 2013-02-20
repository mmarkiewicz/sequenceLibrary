#include <functional>
#include <utility>

namespace seq
{

template <typename T>
class Sequence;

template <typename T>
struct SequencePair : public std::pair<const T&, const Sequence<T>*> {};

template <typename T>
class SimpleCallback : public std::unary_function<void, const SequencePair<T>&>
{
  public:
    virtual ~SimpleCallback () {};
  private:
    SimpleCallback (const SimpleCallback<T>&);
    SimpleCallback& operator= (const SimpleCallback<T>&);
};

template <typename T>
class Lazy
{
  public:
    Lazy (const SimpleCallback<T>& construct);
    ~Lazy () = default;
    const SequencePair<T>& value ();

  private:
    const SimpleCallback<T> _construct;
    bool _constructed;
    SequencePair<T> _value;

    //avoid copying
    Lazy (const Lazy<T>&);
    Lazy& operator= (const Lazy<T>&);
};

}

