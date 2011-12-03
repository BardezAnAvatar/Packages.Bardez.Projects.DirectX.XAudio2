
#include "Unmanaged Engine Callback Base.h"


using namespace Bardez::Projects::DirectX::XAudio2;
using namespace Bardez::Projects::Win32;


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="callback">Managed class that implements the ummanaged methods below</param>
UnmanagedEngineCallbackBase::UnmanagedEngineCallbackBase(EngineCallback^ callback)
{
	this->managedCallback = callback;
}
#pragma endregion
					


#pragma region Methods
/// <summary>Called after a critical system error occurs</summary>
/// <param name="error">Passed in error code</param>
void UnmanagedEngineCallbackBase::OnCriticalError(HRESULT error)
{
	this->managedCallback->OnCriticalError((ResultCode)error);
}
					
/// <summary>Called just after an audio processing pass ends</summary>
void UnmanagedEngineCallbackBase::OnProcessingPassEnd()
{
	this->managedCallback->OnProcessingPassEnd();
}
					
/// <summary>Called just after an audio processing pass starts</summary>
void UnmanagedEngineCallbackBase::OnProcessingPassStart()
{
	this->managedCallback->OnProcessingPassStart();
}
#pragma endregion

