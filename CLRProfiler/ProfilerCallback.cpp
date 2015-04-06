#include "stdafx.h"
#include "ProfilerCallback.h"
#include "Logger.h"
#include "Function.h"

Logger* logger = NULL;
CComQIPtr<ICorProfilerInfo> profilerInfo;
CComQIPtr<ICorProfilerInfo2> profilerInfo2;

Function* GetFunction(FunctionID functionId)
{
  Function* result = new Function();

  mdToken methodToken = 0;
  IMetaDataImport* metaDataImport;

  wchar_t methodName[FILENAME_MAX];
  wchar_t typeName[FILENAME_MAX];
  wchar_t assemblyName[FILENAME_MAX];

  HRESULT hr = S_OK;
  hr = profilerInfo->GetTokenAndMetaDataFromFunction(functionId, IID_IMetaDataImport, (LPUNKNOWN *)&metaDataImport, &methodToken);
  if (FAILED(hr))
    return NULL;
  ModuleID moduleId;
  hr = profilerInfo2->GetFunctionInfo2(functionId, NULL, NULL, &moduleId, NULL, 0, NULL, NULL);
  if (FAILED(hr))
    return NULL;
  mdTypeDef classTypeDef;
  hr = metaDataImport->GetMethodProps(methodToken, &classTypeDef, methodName, FILENAME_MAX, 0, 0, 0, 0, 0, 0);
  if (FAILED(hr))
    return NULL;
  hr = metaDataImport->GetTypeDefProps(classTypeDef, typeName, FILENAME_MAX, 0, 0, 0);
  if (FAILED(hr))
    return NULL;
  hr = metaDataImport->GetScopeProps(assemblyName, FILENAME_MAX, 0, NULL);
  if (FAILED(hr))
    return NULL;

  result->MethodToken = methodToken;
  result->ModuleId = moduleId;
  result->Name.assign(methodName);
  result->TypeName.assign(typeName);
  result->AssemblyName.assign(assemblyName);
  return result;
}

void __stdcall Enter(
  FunctionID functionID,
  UINT_PTR clientData,
  COR_PRF_FRAME_INFO func,
  COR_PRF_FUNCTION_ARGUMENT_INFO   *argumentInfo)
{
  Function* function = GetFunction(functionID);
  if (function == NULL)
    return;
  /*
  logger->Write("Enter ");
  logger->WriteWideString(function->Name.c_str());
  logger->Write(" ");
  logger->WriteWideString(function->TypeName.c_str());
  logger->Write(" ");
  logger->WriteWideString(function->AssemblyName.c_str());
  logger->WriteLine("");
  */
}

void __stdcall Leave(
  FunctionID             functionID,
  UINT_PTR              clientData,
  COR_PRF_FRAME_INFO         func,
  COR_PRF_FUNCTION_ARGUMENT_INFO   *argumentInfo)
{
  Function* function = GetFunction(functionID);
  if (function == NULL)
    return;
  /*
  logger->Write("Leave ");
  logger->WriteWideString(function->Name.c_str());
  logger->Write(" ");
  logger->WriteWideString(function->TypeName.c_str());
  logger->Write(" ");
  logger->WriteWideString(function->AssemblyName.c_str());
  logger->WriteLine("");
  */
}

_declspec(naked) void __stdcall MyFunctionEnter(
  FunctionID funcId,
  UINT_PTR clientData,
  COR_PRF_FRAME_INFO func,
  COR_PRF_FUNCTION_ARGUMENT_INFO *argumentInfo)
{
  _asm {
    push ebp
    mov ebp, esp
    pushad
    mov   eax, [ebp + 0x14]   //argumentInfo
    push  eax
    mov   ecx, [ebp + 0x10]   //func
    push  ecx
    mov   edx, [ebp + 0x0C]   //clientData
    push  edx
    mov   eax, [ebp + 0x08]   //funcID
    push  eax
    call Enter
    popad
    pop ebp
    ret 16
  }
}
_declspec(naked) void __stdcall MyFunctionLeave(
  FunctionID funcId,
  UINT_PTR clientData,
  COR_PRF_FRAME_INFO func,
  COR_PRF_FUNCTION_ARGUMENT_RANGE *retvalRange
  )
{
  _asm {
    push ebp
    mov ebp, esp
    pushad
    mov   eax, [ebp + 0x14]   //argumentInfo
    push  eax
    mov   ecx, [ebp + 0x10]   //func
    push  ecx
    mov   edx, [ebp + 0x0C]   //clientData
    push  edx
    mov   eax, [ebp + 0x08]   //funcID
    push  eax
    call Leave
    popad
    pop ebp
    ret 16
  }
}
_declspec(naked) void __stdcall MyFunctionTailCall(
  FunctionID funcId,
  UINT_PTR clientData,
  COR_PRF_FRAME_INFO func)
{
  _asm {
    ret 12
  }
}
UINT_PTR _stdcall FunctionMapper(FunctionID functionID, BOOL *pbHookFunction)
{
  Function* function = GetFunction(functionID);
  if (function == NULL)
    return (UINT_PTR)functionID;

  *pbHookFunction = function != NULL && function->AssemblyName == wstring(L"CLRium.exe");
  return (UINT_PTR)functionID;
}


ProfilerCallback::ProfilerCallback()
{
}
ProfilerCallback::~ProfilerCallback()
{
}

HRESULT ProfilerCallback::Initialize(IUnknown * pICorProfilerInfoUnk)
{
  logger = new Logger();
  logger->Open();
  logger->WriteLine("Initialize");

  HRESULT hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo, (LPVOID*)&profilerInfo);
  if (FAILED(hr))
    return E_FAIL;
  hr = pICorProfilerInfoUnk->QueryInterface(IID_ICorProfilerInfo2, (LPVOID*)&profilerInfo2);
  if (FAILED(hr))
    return E_FAIL;

  DWORD eventMask = (DWORD)(COR_PRF_MONITOR_JIT_COMPILATION | COR_PRF_MONITOR_MODULE_LOADS | COR_PRF_MONITOR_THREADS | COR_PRF_MONITOR_ENTERLEAVE);
  hr = profilerInfo->SetEventMask(eventMask);
  if (FAILED(hr))
    return S_FALSE;

  hr = profilerInfo2->SetEnterLeaveFunctionHooks2(MyFunctionEnter, MyFunctionLeave, MyFunctionTailCall);
  if (FAILED(hr))
    return S_FALSE;

  hr = profilerInfo2->SetFunctionIDMapper(FunctionMapper);
  if (FAILED(hr))
    return S_FALSE;

  return S_OK;
}

HRESULT ProfilerCallback::Shutdown(void)
{
  logger->WriteLine("Shutdown");
  logger->Close();
  delete logger;
  return S_OK;
}
HRESULT ProfilerCallback::ModuleLoadStarted(ModuleID moduleId)
{
  logger->WriteLine("ModuleLoadStarted");
  return S_OK;
}
HRESULT ProfilerCallback::JITCompilationStarted(FunctionID functionId, BOOL fIsSafeToBlock)
{
  //logger->WriteLine("JITCompilationStarted");
  Function* function = GetFunction(functionId);
  if (function == NULL)
    return S_OK;
  if (function->AssemblyName != wstring(L"CLRium.exe"))
    return S_OK;
  if (function->TypeName != wstring(L"CLRium.TestClass"))
    return S_OK;
  if (function->Name != wstring(L"get_AlansBirthDay"))
    return S_OK;
  
  ULONG methodSize = 0;
  LPCBYTE methodBodyBuffer = NULL;
  profilerInfo2->GetILFunctionBody(function->ModuleId, function->MethodToken, &methodBodyBuffer, &methodSize);

  logger->WriteInt(methodSize);
  logger->WriteLine("");
  for (size_t i = 0; i < methodSize; i++)
  {
    logger->WriteInt(methodBodyBuffer[i]);
    logger->Write(", ");
  }

  unsigned char patchedMethodBody[] = {
    0x13, 0x30, 0x3, 0x0, 
    0x13, 0x0, 0x0, 0x0, 
    0x3, 0x0, 0x0, 0x11, 
    
    0x0, 0x20, 0xC8, 0x7, 0x0, 0x0, 0x1C, 0x1F, 0x17, 0x73, 0x13, 0x0, 0x0, 0xA, 0xA, 0x2B, 0x0, 0x6, 0x2A
  };

  ULONG patchedMethodSize = sizeof(patchedMethodBody);

  CComPtr<IMethodMalloc> methodMalloc;
  profilerInfo2->GetILFunctionBodyAllocator(function->ModuleId, &methodMalloc);

  unsigned char* pNewMethod = (unsigned char*)methodMalloc->Alloc(patchedMethodSize);
  memcpy(pNewMethod, patchedMethodBody, patchedMethodSize);

  profilerInfo2->SetILFunctionBody(function->ModuleId, function->MethodToken, (LPCBYTE)pNewMethod);

  return S_OK;
}
HRESULT ProfilerCallback::ThreadCreated(ThreadID threadId)
{
  logger->WriteLine("ThreadCreated");
  return S_OK;
}
HRESULT ProfilerCallback::ThreadDestroyed(ThreadID threadId)
{
  logger->WriteLine("ThreadDestroyed");
  return S_OK;
}
