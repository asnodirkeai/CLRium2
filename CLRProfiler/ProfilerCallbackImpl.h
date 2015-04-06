#pragma once
#include <cor.h>
#include <corprof.h>

class ProfilerCallbackImpl : public ICorProfilerCallback2
{
public:
  ProfilerCallbackImpl();
  ~ProfilerCallbackImpl();

  // Inherited via ICorProfilerCallback2
  STDMETHOD (QueryInterface)(REFIID riid, void ** ppvObject) override;
  STDMETHOD_ (ULONG, AddRef)(void) override;
  STDMETHOD_ (ULONG, Release)(void) override;
  STDMETHOD (Initialize)(IUnknown * pICorProfilerInfoUnk) override;
  STDMETHOD (Shutdown)(void) override;
  STDMETHOD (AppDomainCreationStarted)(AppDomainID appDomainId) override;
  STDMETHOD (AppDomainCreationFinished)(AppDomainID appDomainId, HRESULT hrStatus) override;
  STDMETHOD (AppDomainShutdownStarted)(AppDomainID appDomainId) override;
  STDMETHOD (AppDomainShutdownFinished)(AppDomainID appDomainId, HRESULT hrStatus) override;
  STDMETHOD (AssemblyLoadStarted)(AssemblyID assemblyId) override;
  STDMETHOD (AssemblyLoadFinished)(AssemblyID assemblyId, HRESULT hrStatus) override;
  STDMETHOD (AssemblyUnloadStarted)(AssemblyID assemblyId) override;
  STDMETHOD (AssemblyUnloadFinished)(AssemblyID assemblyId, HRESULT hrStatus) override;
  STDMETHOD (ModuleLoadStarted)(ModuleID moduleId) override;
  STDMETHOD (ModuleLoadFinished)(ModuleID moduleId, HRESULT hrStatus) override;
  STDMETHOD (ModuleUnloadStarted)(ModuleID moduleId) override;
  STDMETHOD (ModuleUnloadFinished)(ModuleID moduleId, HRESULT hrStatus) override;
  STDMETHOD (ModuleAttachedToAssembly)(ModuleID moduleId, AssemblyID AssemblyId) override;
  STDMETHOD (ClassLoadStarted)(ClassID classId) override;
  STDMETHOD (ClassLoadFinished)(ClassID classId, HRESULT hrStatus) override;
  STDMETHOD (ClassUnloadStarted)(ClassID classId) override;
  STDMETHOD (ClassUnloadFinished)(ClassID classId, HRESULT hrStatus) override;
  STDMETHOD (FunctionUnloadStarted)(FunctionID functionId) override;
  STDMETHOD (JITCompilationStarted)(FunctionID functionId, BOOL fIsSafeToBlock) override;
  STDMETHOD (JITCompilationFinished)(FunctionID functionId, HRESULT hrStatus, BOOL fIsSafeToBlock) override;
  STDMETHOD (JITCachedFunctionSearchStarted)(FunctionID functionId, BOOL * pbUseCachedFunction) override;
  STDMETHOD (JITCachedFunctionSearchFinished)(FunctionID functionId, COR_PRF_JIT_CACHE result) override;
  STDMETHOD (JITFunctionPitched)(FunctionID functionId) override;
  STDMETHOD (JITInlining)(FunctionID callerId, FunctionID calleeId, BOOL * pfShouldInline) override;
  STDMETHOD (ThreadCreated)(ThreadID threadId) override;
  STDMETHOD (ThreadDestroyed)(ThreadID threadId) override;
  STDMETHOD (ThreadAssignedToOSThread)(ThreadID managedThreadId, DWORD osThreadId) override;
  STDMETHOD (RemotingClientInvocationStarted)(void) override;
  STDMETHOD (RemotingClientSendingMessage)(GUID * pCookie, BOOL fIsAsync) override;
  STDMETHOD (RemotingClientReceivingReply)(GUID * pCookie, BOOL fIsAsync) override;
  STDMETHOD (RemotingClientInvocationFinished)(void) override;
  STDMETHOD (RemotingServerReceivingMessage)(GUID * pCookie, BOOL fIsAsync) override;
  STDMETHOD (RemotingServerInvocationStarted)(void) override;
  STDMETHOD (RemotingServerInvocationReturned)(void) override;
  STDMETHOD (RemotingServerSendingReply)(GUID * pCookie, BOOL fIsAsync) override;
  STDMETHOD (UnmanagedToManagedTransition)(FunctionID functionId, COR_PRF_TRANSITION_REASON reason) override;
  STDMETHOD (ManagedToUnmanagedTransition)(FunctionID functionId, COR_PRF_TRANSITION_REASON reason) override;
  STDMETHOD (RuntimeSuspendStarted)(COR_PRF_SUSPEND_REASON suspendReason) override;
  STDMETHOD (RuntimeSuspendFinished)(void) override;
  STDMETHOD (RuntimeSuspendAborted)(void) override;
  STDMETHOD (RuntimeResumeStarted)(void) override;
  STDMETHOD (RuntimeResumeFinished)(void) override;
  STDMETHOD (RuntimeThreadSuspended)(ThreadID threadId) override;
  STDMETHOD (RuntimeThreadResumed)(ThreadID threadId) override;
  STDMETHOD (MovedReferences)(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[]) override;
  STDMETHOD (ObjectAllocated)(ObjectID objectId, ClassID classId) override;
  STDMETHOD (ObjectsAllocatedByClass)(ULONG cClassCount, ClassID classIds[], ULONG cObjects[]) override;
  STDMETHOD (ObjectReferences)(ObjectID objectId, ClassID classId, ULONG cObjectRefs, ObjectID objectRefIds[]) override;
  STDMETHOD (RootReferences)(ULONG cRootRefs, ObjectID rootRefIds[]) override;
  STDMETHOD (ExceptionThrown)(ObjectID thrownObjectId) override;
  STDMETHOD (ExceptionSearchFunctionEnter)(FunctionID functionId) override;
  STDMETHOD (ExceptionSearchFunctionLeave)(void) override;
  STDMETHOD (ExceptionSearchFilterEnter)(FunctionID functionId) override;
  STDMETHOD (ExceptionSearchFilterLeave)(void) override;
  STDMETHOD (ExceptionSearchCatcherFound)(FunctionID functionId) override;
  STDMETHOD (ExceptionOSHandlerEnter)(UINT_PTR __unused) override;
  STDMETHOD (ExceptionOSHandlerLeave)(UINT_PTR __unused) override;
  STDMETHOD (ExceptionUnwindFunctionEnter)(FunctionID functionId) override;
  STDMETHOD (ExceptionUnwindFunctionLeave)(void) override;
  STDMETHOD (ExceptionUnwindFinallyEnter)(FunctionID functionId) override;
  STDMETHOD (ExceptionUnwindFinallyLeave)(void) override;
  STDMETHOD (ExceptionCatcherEnter)(FunctionID functionId, ObjectID objectId) override;
  STDMETHOD (ExceptionCatcherLeave)(void) override;
  STDMETHOD (COMClassicVTableCreated)(ClassID wrappedClassId, REFGUID implementedIID, void * pVTable, ULONG cSlots) override;
  STDMETHOD (COMClassicVTableDestroyed)(ClassID wrappedClassId, REFGUID implementedIID, void * pVTable) override;
  STDMETHOD (ExceptionCLRCatcherFound)(void) override;
  STDMETHOD (ExceptionCLRCatcherExecute)(void) override;
  STDMETHOD (ThreadNameChanged)(ThreadID threadId, ULONG cchName, WCHAR name[]) override;
  STDMETHOD (GarbageCollectionStarted)(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason) override;
  STDMETHOD (SurvivingReferences)(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[]) override;
  STDMETHOD (GarbageCollectionFinished)(void) override;
  STDMETHOD (FinalizeableObjectQueued)(DWORD finalizerFlags, ObjectID objectID) override;
  STDMETHOD (RootReferences2)(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[]) override;
  STDMETHOD (HandleCreated)(GCHandleID handleId, ObjectID initialObjectId) override;
  STDMETHOD (HandleDestroyed)(GCHandleID handleId) override;
};

