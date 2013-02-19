#include<functional>

namespace seq
{

template <typename T>
class Lazy
{
  public:
    typedef std::unary_function<void,T> ufT;
    Lazy<T> (const ufT& construct);
    const T& value ();

  private:
    const ufT _construct;
    bool _constructed;
    T _value;

    //avoid copying
    Lazy (const Lazy&);
    Lazy& operator= (const Lazy&);
};

}

