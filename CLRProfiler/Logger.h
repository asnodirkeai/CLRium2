#pragma once

class Logger
{
  FILE* file;
public:
  Logger();
  ~Logger();

  void Open();
  void Write(const char* str);
  void WriteLine(const char* str);
  void WriteWideString(const wchar_t* str);
  void WriteInt(int i);
  void Close();
};

