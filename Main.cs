using System;
using SequenceLibrary;

namespace SequenceLibraryTest
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Sequence nat = SequenceFactory.Snat (x => x);
			Sequence s = SequenceFactory.Smap (x => 2*x - 3, nat);
			foreach (int e in (s.Stake (10)))
			{
				Console.WriteLine (e);
			}
		}
	}
}
