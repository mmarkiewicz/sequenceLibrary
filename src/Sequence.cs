using System;
using System.Collections.Generic;

namespace SequenceLibrary
{
	public abstract class Sequence
	{
		protected internal struct Unit
		{
			public int _head;
			public Sequence _tail;
			
			public Unit (int h, Sequence t)
			{
				_head = h;
				_tail = t;
			}
		}
		
		protected Lazy<Unit> _unit;
		
		public int Hd 
		{ 
			get 
			{ 
				return this._unit.Value._head; 
			} 
		}
		
		public Sequence Tl
		{
			get
			{
				return this._unit.Value._tail;
			}
		}
		
		public List<int> Stake (int n)
		{
			if (n == 1) 
			{
				return new List<int> { this.Hd };
			}
			List<int> result = (this.Tl).Stake (n-1);
			result.Insert (0, this.Hd);
			return result; 
		}
	}
}

