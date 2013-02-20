#include <functional>

namespace seq
{
  template <typename T> 
	class Sequence;

  template <typename T>
  class SequenceFactory
  {
    public:
      SequenceFactory () = default;

    protected:

    private:
      SequenceFactory (const SequenceFactory&);
      SequenceFactory& operator= (const SequenceFactory&);
  };
}
