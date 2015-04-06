using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ILDasmTest
{
  public class Class1
  {
    public void DisplaySum(int x, int y)
    {
      int sum = x + y;
      if (sum > 0)
        Console.WriteLine(sum);
    }
  }
}
