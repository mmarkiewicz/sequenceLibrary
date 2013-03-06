#include <vector>
#include <algorithm>
#include <functional>

#include "Sequence/Sequence.h"

namespace seq
{
  /*
   * return first n elements of the sequence s
   */
  template <typename T>
  void stake (Sequence<T>* s, size_t n, std::vector<T>& result)
  {
    result.clear();
    Sequence<T>* iter = s;
    while (n--)
    {
      result.push_back(iter->head());
      iter = iter->tail();
    }
  }

  /*
   * return n-th element of the sequence s
   */
  template <typename T>
  T snth (Sequence<T>* s, size_t n)
  {
    Sequence<T>* iter = s;
    while (n--)
      iter = iter->tail();

    return iter->head();
  }

  //--------------------------------------------------------------------//
  template <typename T>
  Sequence<T>* cut (Sequence<T>* s, size_t n)
  {
    Sequence<T>* iter = s;
    while (n--)
      iter = iter->tail();

    return iter;
  }

  template <typename T>
  void ssplit(Sequence<T>* s, size_t n, std::vector<Sequence<T>*>& result)
  {
    using namespace std::placeholders;

    result.clear();
    auto ss = new Sequence<Sequence<T>*>(Snat<Sequence<T>*>(std::bind(cut<T>, _1, n), s));

    typename Smap<Sequence<T>*, Sequence<T>*>::fType
    stl = [](Sequence<T>* _seq){return _seq->tail();};

    typename Snat<Sequence<Sequence<T>*>*>::fType
    smap_o_stl = [stl](Sequence<Sequence<T>*>* _seq)
                      {
                        return new Sequence<Sequence<T>*>(
                            Smap<Sequence<T>*, Sequence<T>*>(stl,_seq)
                          );
                      };
    auto sss = new Sequence<Sequence<Sequence<T>*>*>(Snat<Sequence<Sequence<T>*>*>(smap_o_stl, ss));

    typename Smap<Sequence<T>*,T>::fType
    shd = [](Sequence<T>* _seq){return _seq->head();};

    typename Smap<Sequence<Sequence<T>*>*, Sequence<T>*>::fType
    smap_o_shd = [shd](Sequence<Sequence<T>*>* _seq)
                      {
                        return new Sequence<T>(
                            Smap<Sequence<T>*, T>(shd,_seq)
                          );
                      };
    auto ss2 = new Sequence<Sequence<T>*>(
        Smap<Sequence<Sequence<T>*>*,Sequence<T>*>(smap_o_shd, sss));

    std::vector<Sequence<T>*> res;
    stake<Sequence<T>*>(ss2, n, res);
    result.assign(res.begin(), res.end());
  }
}
