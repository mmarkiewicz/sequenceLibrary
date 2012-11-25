using System;
using SequenceLibrary;

namespace SequenceLibraryTest
{
	class MainClass
	{
		private static void printS (Sequence s, int n)
		{
			while (n-- > 0) {
				Console.WriteLine (s.Hd);
				s = s.Tl;
			}
		}
		
		private static void cycle (Sequence baseS, Sequence x, int n)
		{
			while (n-- > 0) {
				Console.WriteLine (Utils.BesicovitchDistance (x, baseS));
				x = x.Tl;
			}
		}
		
		public static void Main (string[] args)
		{
			Random rand = new Random();
			Sequence s1 = SequenceFactory.Snat (x => (x%4 == 0 ? rand.Next(2) : 1));
			
			int baseN = 3;
			Sequence baseS = SequenceFactory.Snat (x => (x % baseN) == 0 ? rand.Next(2) : 0);
			
			double dens = Utils.Density (baseS);
			Console.WriteLine ("Upper bound: {0}", Math.Max(dens, 1.0 - dens));
			Console.WriteLine ("Density of s: {0}", Utils.Density (s1));
			cycle (baseS, s1, 30);
		}
	}
}
