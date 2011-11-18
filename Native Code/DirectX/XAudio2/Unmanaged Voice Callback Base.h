		
#ifndef Bardez_Projects_Directx_XAudio2_UnmanagedVoiceCallbackBase
#define Bardez_Projects_Directx_XAudio2_UnmanagedVoiceCallbackBase

#include <msclr\auto_gcroot.h>
#include <XAudio2.h>
#include "Voice Callback.h"

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
				/// <summary>Callback from the XAudio2 voice</summary>
				public class UnmanagedVoiceCallbackBase : public IXAudio2VoiceCallback
				{
				#pragma region Members
				protected:
					/// <summary>Managed class that implements the ummanaged methods below</summary>
					/// <remarks>see: http://msdn.microsoft.com/en-us/library/aa730837%28v=vs.80%29.aspx for auto_gcroot</remarks>
					msclr::auto_gcroot<VoiceCallback^> managedCallback;
				#pragma endregion



				#pragma region Construction
				public:
					/// <summary>Definition constructor</summary>
					/// <param name="callback">Managed class that implements the ummanaged methods below</param>
					UnmanagedVoiceCallbackBase(VoiceCallback^ callback);
				#pragma endregion
					


				#pragma region Methods
				public:
					/********************************************************************
					*	Note: Documentation says virtual void should be fine, but		*
					*	compiler requires "virtual COM_DECLSPEC_NOTHROW void __stdcall"	*
					********************************************************************/
					/// <summary>Called when the voice finishes processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnBufferEnd(void* bufferContext);

					/// <summary>Called when the voice starts processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnBufferStart(void* bufferContext);

					/// <summary>Called when the voice finishes processing a loop</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnLoopEnd(void* bufferContext);

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnStreamEnd();

					/// <summary>Called when the voice encounters a critical error</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					/// <param name="error">Error encountered</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnVoiceError(void* bufferContext, HRESULT error);

					/// <summary>Called just after the processing pass for the voice ends</summary>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnVoiceProcessingPassEnd();

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
					virtual COM_DECLSPEC_NOTHROW void __stdcall OnVoiceProcessingPassStart(UINT32 bytesRequired);
				#pragma endregion
				};
			}
		}
	}
}

#endif