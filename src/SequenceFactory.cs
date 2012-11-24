using System;

namespace SequenceLibrary
{
	public class SequenceFactory
	{
		/* delegates using for creating sequences */
		public delegate int SnatDelegate (int x);
		
		/* privarte constructor */
		private SequenceFactory ()
		{
		}
		
		public static Sequence Snat (SnatDelegate f) 
		{
			return new SnatSequence (f, 0);
		}
		
		public static Sequence Smap (SnatDelegate f, Sequence s)
		{
			return new SmapSequence (f, s);
		}
		
		public static Sequence Rand (Random gen, Int32 max = Int32.MaxValue)
		{
			return new RandomSequence (gen, max);
		}
	}
}

