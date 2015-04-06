using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Launcher
{
  /// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
  public partial class MainWindow : Window
  {
    private string STR_AppPath = @"D:\CLRium\CLRium\CLRium\bin\Debug\CLRium.exe";
    private string STR_ProfilerDll = @"D:\CLRium\CLRium\Debug\CLRProfiler.dll";
    private string STR_ProfilerGUID = "{2ED95C82-B19C-49C3-BE8E-765EC16CF33B}";
    public MainWindow()
    {
      InitializeComponent();
    }

    private bool RegisterDll()
    {
      var startInfo = new ProcessStartInfo() {
        FileName = "regsvr32.exe",
        Arguments = string.Format("/s {0}", STR_ProfilerDll),
        UseShellExecute = false
      };
      var process = Process.Start(startInfo);
      process.WaitForExit();
      return process.ExitCode == 0;
    }
    private void Button_Click(object sender, RoutedEventArgs e)
    {
      if (!RegisterDll())
        return;

      var startInfo = new ProcessStartInfo() { FileName = STR_AppPath, UseShellExecute = false };

      startInfo.EnvironmentVariables["COR_ENABLE_PROFILING"] = "1";
      startInfo.EnvironmentVariables["COR_PROFILER"] = STR_ProfilerGUID;
      startInfo.EnvironmentVariables["COMPLUS_ProfAPI_ProfilerCompatibilitySetting"] = "EnableV2Profiler";

      var process = Process.Start(startInfo);
      process.WaitForExit();
    }
  }
}
