#pragma once
#include <string>
using namespace std;

class Function
{
public:
  Function();
  ~Function();

  ULONG32 MethodToken;
  UINT_PTR ModuleId;

  wstring Name;
  wstring TypeName;
  wstring AssemblyName;
};

