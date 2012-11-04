using System;

namespace SequenceLibrary
{
	internal class SmapSequence : Sequence
	{
		public SmapSequence (SequenceFactory.SnatDelegate f, Sequence s)
		{
			this._unit = new Lazy<Sequence.Unit> (
				() => 
				{
					return new Unit (f(s.Hd), new SmapSequence (f, s.Tl));
				});
		}
	}
}

