
#include "Source Voice.h"

using namespace Bardez::Projects::DirectX::XAudio2;

#pragma region Properties
/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
IXAudio2SourceVoice* SourceVoice::XAudio2SourceVoice::get()
{
	return reinterpret_cast<IXAudio2SourceVoice*>(this->ptrVoice.ToPointer());
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
void SourceVoice::XAudio2SourceVoice::set(IXAudio2SourceVoice* value)
{
	this->ptrVoice = System::IntPtr(value);
}

/// <summary>Reference to the voice callback object for this source voice</summary>
VoiceCallback^ SourceVoice::Callback::get()
{
	return this->callback;
}

/// <summary>Reference to the voice callback object for this source voice</summary>
/// <param name="value">Instance to reference</param>
void SourceVoice::Callback::set(VoiceCallback^ value)
{
	this->callback = value;
}
#pragma endregion
					


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="pointer">Pointer to an XAudio2 source voice interface object</param>
/// <param name="callback">Callback instance to reference</param>
SourceVoice::SourceVoice(IXAudio2SourceVoice* pointer, VoiceCallback^ callback)
{
	this->XAudio2SourceVoice = pointer;
	this->callback = callback;
}
#pragma endregion



#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
SourceVoice::~SourceVoice()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
SourceVoice::!SourceVoice()
{
	this->DisposeUnmanaged();
}
#pragma endregion


	
#pragma region Methods
/// <summary>Notifies a voice that no more buffers are coming after the last one that is currently in its queue.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Discontinuity()
{
	return (ResultCode)this->XAudio2SourceVoice->Discontinuity();
}

/// <summary>Stops looping this voice when it reaches the end of the current loop.</summary>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::ExitLoop(System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->ExitLoop(operationSet);
}

/// <summary>Removes all pending audio buffers from this voice's queue.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::FlushSourceBuffers()
{
	return (ResultCode)this->XAudio2SourceVoice->FlushSourceBuffers();
}

/// <summary>Gets the frequency adjustment ratio of this voice.</summary>
/// <returns>The frequency adjustment ratio</returns>
System::Single SourceVoice::GetFrequencyRatio()
{
	float ratio;
	this->XAudio2SourceVoice->GetFrequencyRatio(&ratio);
	return ratio;
}

/// <summary>Gets this voice's current cursor position data.</summary>
/// <returns>A reference to the state of this voice</returns>
/// <remarks>
///		If a client needs to obtain the correlated positions of several voices
///		(i.e. to know exactly which sample of a given voice is playing when a given sample of another voice is playing)
///		it must make GetState calls in an XAudio2 engine callback, to ensure that none of the voices advance while the calls are being made.
///		See the XAudio2 Callbacks overview for information about using XAudio2 callbacks.
/// </remarks>
VoiceState^ SourceVoice::GetState()
{
	XAUDIO2_VOICE_STATE voiceState;

	this->XAudio2SourceVoice->GetState(&voiceState);

	return gcnew VoiceState(voiceState);
}

/// <summary>Sets the frequency adjustment ratio of this voice</summary>
/// <param name="ratio">Frequenct adjustment ratio to set</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::SetFrequencyRatio(System::Single ratio, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->SetFrequencyRatio(ratio, operationSet);
}

/// <summary>Sets the source data sample rate</summary>
/// <param name="sampleRate">New sample rate</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::SetSourceSampleRate(System::UInt32 sampleRate)
{
	return (ResultCode)this->XAudio2SourceVoice->SetSourceSampleRate(sampleRate);
}

/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Start(System::UInt32 flags, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->Start(flags, operationSet);
}

/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Start()
{
	return (ResultCode)this->Start(0, XAUDIO2_COMMIT_NOW);
}

/// <summary>Stops consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Stop(System::UInt32 flags, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->Stop(flags, operationSet);
}


/// <summary>Submits a data buffer to XAudio2</summary>
/// <param name="buffer">Audio buffer details &amp; data</param>
/// <param name="bufferWma">Additional buffer data for WMA streams. Nullable if PCM data.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		The voice processes and plays back the buffers in its queue in the order that they were submitted.
///		If the voice is started and has no buffers queued, the new buffer will start playing immediately.
///		If the voice is stopped, the buffer is added to the voice's queue and will be played when the voice starts.
///		If an explicit play region is specified, it must begin and end within the given audio buffer (or, in the compressed case, within the set of
///		samples that the buffer will decode to). In addition, the loop region cannot end past the end of the play region.
/// </remarks>
ResultCode SourceVoice::SubmitSourceBuffer(Bardez::Projects::DirectX::XAudio2::AudioBuffer^ buffer, WmaBuffer^ bufferWma)
{
	XAUDIO2_BUFFER nativeBuffer = buffer->ToUnmanaged();
	XAUDIO2_BUFFER_WMA* nativeWmaBuffer = NULL;
	
	if (bufferWma != nullptr)
		nativeWmaBuffer = &(bufferWma->ToUnmanaged());

	return (ResultCode)this->XAudio2SourceVoice->SubmitSourceBuffer(&nativeBuffer, nativeWmaBuffer);
}
#pragma endregion

