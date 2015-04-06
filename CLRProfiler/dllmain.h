// dllmain.h : Declaration of module class.

class CCLRProfilerModule : public ATL::CAtlDllModuleT< CCLRProfilerModule >
{
public :
	DECLARE_LIBID(LIBID_CLRProfilerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CLRPROFILER, "{2ED95C82-B19C-49C3-BE8E-765EC16CF33B}")
};

extern class CCLRProfilerModule _AtlModule;
