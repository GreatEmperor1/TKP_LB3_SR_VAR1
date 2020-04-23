// dllmain.h : Declaration of module class.

class CServerModule : public ATL::CAtlDllModuleT< CServerModule >
{
public :
	DECLARE_LIBID(LIBID_ServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SERVER, "{43ADB22E-A89D-4F65-B60C-731499E3051E}")
};

extern class CServerModule _AtlModule;
