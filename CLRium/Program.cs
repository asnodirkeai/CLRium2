using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace CLRium
{
  class Program
  {
    static void Main(string[] args)
    {
      //Console.WriteLine("Hello profiler: Main thread");
      //Task.Factory.StartNew(() => Console.WriteLine("Hello profiler: Background thread"));
      //var thread = new Thread(() => Console.WriteLine("Hello profiler: Background thread"));
      //thread.IsBackground = true;
      //thread.Start();
      var testClass = new TestClass();
      testClass.Abs(-2);
      testClass.Abs(2);

      Console.WriteLine("Alan Turing was born at {0}", 
        testClass.AlansBirthDay.ToLongDateString());

      Console.ReadKey();
    }
  }
}
