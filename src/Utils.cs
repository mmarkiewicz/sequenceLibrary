using System;
using System.Collections.Generic;

namespace SequenceLibrary
{
	public class Utils
	{
		private Utils ()
		{
		}
		
		public static Sequence zeroS = SequenceFactory.Snat (x => 0);
		
		/**
		 * Calculates the Cantor distance between two sequences with the given precision
		 */
		public static double CantorDistance (Sequence s1, Sequence s2, double precision = Double.Epsilon)
		{
			double dist = 1.0;
			while (dist > precision) {
				if (s1.Hd != s1.Hd) return dist;
				dist *= 0.5;
				s1 = s1.Tl; s2 = s2.Tl;
			}
			return dist;
		}
		
		/**
		 * Approximates the Besicovitch pseudo distance between two sequences 
		 * restricting the size of cell
		 */
		public static double BesicovitchDistance (Sequence s1, Sequence s2, int maxSize = 1000000)
		{
			int diffs = 0;
			for (int n=1; n<=maxSize; ++n) {
				if (s1.Hd != s2.Hd) diffs++;
				s1 = s1.Tl; s2 = s2.Tl;
			}
			
			return ((double)diffs) / maxSize;
		}
		
		public static double Density (Sequence s1, int maxSize = 1000000)
		{
			return BesicovitchDistance (s1, zeroS, maxSize);
		}
	}
}

