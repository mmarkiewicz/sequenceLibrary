using System;

namespace SequenceLibrary
{
	internal class SnatSequence : Sequence
	{
		public SnatSequence (SequenceFactory.SnatDelegate fun, int n)
		{
			this._unit = new Lazy<Sequence.Unit> (
				() => 
				{
					return new Unit (fun(n), new SnatSequence (fun, n+1));
				});
		}
	}
}

