#pragma once
#include "ProfilerCallbackImpl.h"
#include "CLRProfiler_i.h"

using namespace ATL;

class ProfilerCallback : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<ProfilerCallback, &CLSID_ProfilerCallback>,
  public ProfilerCallbackImpl
{
public:
  ProfilerCallback();
  ~ProfilerCallback();

  DECLARE_REGISTRY_RESOURCEID(IDR_CLRPROFILER)
  BEGIN_COM_MAP(ProfilerCallback)
    COM_INTERFACE_ENTRY(ICorProfilerCallback)
    COM_INTERFACE_ENTRY(ICorProfilerCallback2)
  END_COM_MAP()

  STDMETHOD(Initialize)(IUnknown * pICorProfilerInfoUnk) override;
  STDMETHOD(Shutdown)(void) override;
  STDMETHOD(ModuleLoadStarted)(ModuleID moduleId) override;
  STDMETHOD(JITCompilationStarted)(FunctionID functionId, BOOL fIsSafeToBlock) override;
  STDMETHOD(ThreadCreated)(ThreadID threadId) override;
  STDMETHOD(ThreadDestroyed)(ThreadID threadId) override;
};
OBJECT_ENTRY_AUTO(__uuidof(ProfilerCallback), ProfilerCallback)

