using System;
using System.Collections.Generic;
using System.Linq;

namespace CLRium
{
  public class TestClass
  {
    public int Abs(int x)
    {
      if (x < 0)
        return -x;
      return x;
    }

    public DateTime AlansBirthDay
    {
      get { return new DateTime(1912, 6, 23); }
    }
    
  }
}
