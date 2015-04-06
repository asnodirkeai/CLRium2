#include "stdafx.h"
#include "ProfilerCallbackImpl.h"


ProfilerCallbackImpl::ProfilerCallbackImpl()
{
}


ProfilerCallbackImpl::~ProfilerCallbackImpl()
{
}

HRESULT ProfilerCallbackImpl::QueryInterface(REFIID riid, void ** ppvObject)
{
  return S_OK;
}

ULONG ProfilerCallbackImpl::AddRef(void)
{
  return 0;
}

ULONG ProfilerCallbackImpl::Release(void)
{
  return 0;
}

HRESULT ProfilerCallbackImpl::Initialize(IUnknown * pICorProfilerInfoUnk)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::Shutdown(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AppDomainCreationStarted(AppDomainID appDomainId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AppDomainCreationFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AppDomainShutdownStarted(AppDomainID appDomainId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AppDomainShutdownFinished(AppDomainID appDomainId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AssemblyLoadStarted(AssemblyID assemblyId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AssemblyLoadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AssemblyUnloadStarted(AssemblyID assemblyId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::AssemblyUnloadFinished(AssemblyID assemblyId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ModuleLoadStarted(ModuleID moduleId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ModuleLoadFinished(ModuleID moduleId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ModuleUnloadStarted(ModuleID moduleId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ModuleUnloadFinished(ModuleID moduleId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ModuleAttachedToAssembly(ModuleID moduleId, AssemblyID AssemblyId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ClassLoadStarted(ClassID classId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ClassLoadFinished(ClassID classId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ClassUnloadStarted(ClassID classId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ClassUnloadFinished(ClassID classId, HRESULT hrStatus)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::FunctionUnloadStarted(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITCompilationStarted(FunctionID functionId, BOOL fIsSafeToBlock)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITCompilationFinished(FunctionID functionId, HRESULT hrStatus, BOOL fIsSafeToBlock)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITCachedFunctionSearchStarted(FunctionID functionId, BOOL * pbUseCachedFunction)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITCachedFunctionSearchFinished(FunctionID functionId, COR_PRF_JIT_CACHE result)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITFunctionPitched(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::JITInlining(FunctionID callerId, FunctionID calleeId, BOOL * pfShouldInline)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ThreadCreated(ThreadID threadId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ThreadDestroyed(ThreadID threadId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ThreadAssignedToOSThread(ThreadID managedThreadId, DWORD osThreadId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingClientInvocationStarted(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingClientSendingMessage(GUID * pCookie, BOOL fIsAsync)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingClientReceivingReply(GUID * pCookie, BOOL fIsAsync)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingClientInvocationFinished(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingServerReceivingMessage(GUID * pCookie, BOOL fIsAsync)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingServerInvocationStarted(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingServerInvocationReturned(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RemotingServerSendingReply(GUID * pCookie, BOOL fIsAsync)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::UnmanagedToManagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ManagedToUnmanagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeSuspendFinished(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeSuspendAborted(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeResumeStarted(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeResumeFinished(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeThreadSuspended(ThreadID threadId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RuntimeThreadResumed(ThreadID threadId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::MovedReferences(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ObjectAllocated(ObjectID objectId, ClassID classId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ObjectsAllocatedByClass(ULONG cClassCount, ClassID classIds[], ULONG cObjects[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ObjectReferences(ObjectID objectId, ClassID classId, ULONG cObjectRefs, ObjectID objectRefIds[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RootReferences(ULONG cRootRefs, ObjectID rootRefIds[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionThrown(ObjectID thrownObjectId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionSearchFunctionEnter(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionSearchFunctionLeave(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionSearchFilterEnter(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionSearchFilterLeave(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionSearchCatcherFound(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionOSHandlerEnter(UINT_PTR __unused)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionOSHandlerLeave(UINT_PTR __unused)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionUnwindFunctionEnter(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionUnwindFunctionLeave(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionUnwindFinallyEnter(FunctionID functionId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionUnwindFinallyLeave(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionCatcherEnter(FunctionID functionId, ObjectID objectId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionCatcherLeave(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::COMClassicVTableCreated(ClassID wrappedClassId, REFGUID implementedIID, void * pVTable, ULONG cSlots)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::COMClassicVTableDestroyed(ClassID wrappedClassId, REFGUID implementedIID, void * pVTable)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionCLRCatcherFound(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ExceptionCLRCatcherExecute(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::ThreadNameChanged(ThreadID threadId, ULONG cchName, WCHAR name[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::GarbageCollectionFinished(void)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[])
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::HandleCreated(GCHandleID handleId, ObjectID initialObjectId)
{
  return S_OK;
}

HRESULT ProfilerCallbackImpl::HandleDestroyed(GCHandleID handleId)
{
  return S_OK;
}
