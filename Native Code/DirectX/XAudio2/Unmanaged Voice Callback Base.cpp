
#include "Result Codes.h"
#include "Unmanaged Voice Callback Base.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="callback">Managed class that implements the ummanaged methods below</param>
UnmanagedVoiceCallbackBase::UnmanagedVoiceCallbackBase(VoiceCallback^ callback)
{
	this->managedCallback = callback;
}
#pragma endregion



#pragma region Methods
/// <summary>Called when the voice finishes processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void UnmanagedVoiceCallbackBase::OnBufferEnd(void* bufferContext)
{
	this->managedCallback->RaiseBufferEnd(System::IntPtr(bufferContext));
}

/// <summary>Called when the voice starts processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void UnmanagedVoiceCallbackBase::OnBufferStart(void* bufferContext)
{
	this->managedCallback->RaiseBufferStart(System::IntPtr(bufferContext));
}

/// <summary>Called when the voice finishes processing a loop</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void UnmanagedVoiceCallbackBase::OnLoopEnd(void* bufferContext)
{
	this->managedCallback->RaiseLoopEnd(System::IntPtr(bufferContext));
}

/// <summary>Called when the voice finishes processing an audio stream</summary>
void UnmanagedVoiceCallbackBase::OnStreamEnd()
{
	this->managedCallback->RaiseStreamEnd();
}

/// <summary>Called when the voice encounters a critical error</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
/// <param name="error">Error encountered</param>
void UnmanagedVoiceCallbackBase::OnVoiceError(void* bufferContext, HRESULT error)
{
	this->managedCallback->RaiseVoiceError(System::IntPtr(bufferContext), (ResultCode)error);
}

/// <summary>Called just after the processing pass for the voice ends</summary>
void UnmanagedVoiceCallbackBase::OnVoiceProcessingPassEnd()
{
	this->managedCallback->RaiseVoiceProcessingPassEnd();
}

/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
void UnmanagedVoiceCallbackBase::OnVoiceProcessingPassStart(UINT32 bytesRequired)
{
	this->managedCallback->RaiseVoiceProcessingPassStart(bytesRequired);
}
#pragma endregion

