#include "stdafx.h"
#include "Logger.h"


Logger::Logger()
{
}
Logger::~Logger()
{
}
void Logger::Open()
{
   fopen_s(&file, "d:\\CLRium\\Profiler.log", "w");
}
void Logger::Write(const char* str)
{
  fprintf(file, str);
}
void Logger::WriteWideString(const wchar_t* str)
{
  fwprintf(file, str);
}
void Logger::WriteInt(int i)
{
  fprintf(file, "0x%X", i);
}
void Logger::WriteLine(const char* str)
{
  fprintf(file, "%s\n", str);
}
void Logger::Close()
{
  if (file != NULL)
    fclose(file);
}
