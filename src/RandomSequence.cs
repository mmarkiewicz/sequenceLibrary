using System;

namespace SequenceLibrary
{
	internal class RandomSequence : Sequence
	{
		public RandomSequence (Random gen, int max = Int32.MaxValue)
		{
			this._unit = new Lazy<Sequence.Unit> (
				() => 
				{
					return new Unit (gen.Next (max), new RandomSequence (gen, max));
				});
		}
		
		
	}
}

