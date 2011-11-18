		
#ifndef Bardez_Projects_Directx_XAudio2_UnmanagedEngineCallbackBase
#define Bardez_Projects_Directx_XAudio2_UnmanagedEngineCallbackBase

#include <msclr\auto_gcroot.h>
#include <XAudio2.h>
#include "Engine Callback.h"

/************************************************************
*	Reference												*
*	for C/++ -> .NET and .NET -> C/++ callbacks				*
*	http://tweakbits.com/UnmanagedToManagedCallback.cpp		*
*	http://tweakbits.com/ManagedToUnmanagedCallback.cpp		*
************************************************************/

using namespace Bardez::Projects::DirectX::XAudio2;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Callback from the XAudio2 engine</summary>
				public class UnmanagedEngineCallbackBase : public IXAudio2EngineCallback
				{
				#pragma region Members
				protected:
					/// <summary>Managed class that implements the ummanaged methods below</summary>
					/// <remarks>see: http://msdn.microsoft.com/en-us/library/aa730837%28v=vs.80%29.aspx for auto_gcroot</remarks>
					msclr::auto_gcroot<EngineCallback^> managedCallback;
				#pragma endregion



				#pragma region Construction
				public:
					/// <summary>Definition constructor</summary>
					/// <param name="callback">Managed class that implements the ummanaged methods below</param>
					UnmanagedEngineCallbackBase(EngineCallback^ callback);
				#pragma endregion
					


				#pragma region Methods
				public:
					/********************************************************************
					*	Note: Documentation says virtual void should be fine, but		*
					*	compiler requires "virtual COM_DECLSPEC_NOTHROW void __stdcall"	*
					********************************************************************/
					/// <summary>Called after a critical system error occurs</summary>
					/// <param name="error">Passed in error code</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnCriticalError(HRESULT error);
					
					/// <summary>Called just after an audio processing pass ends</summary>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnProcessingPassEnd();
					
					/// <summary>Called just after an audio processing pass starts</summary>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnProcessingPassStart();
				#pragma endregion
				};
			}
		}
	}
}

#endif