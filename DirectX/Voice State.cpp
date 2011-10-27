
#include "Voice State.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Context for the buffer, for the client to define and use during callbacks</summary>
System::IntPtr VoiceState::BufferContext::get()
{
	return this->bufferContext;
}

/// <summary>Context for the buffer, for the client to define and use during callbacks</summary>
void VoiceState::BufferContext::set(System::IntPtr value)
{
	this->bufferContext = value;
}

/// <summary>Number of bufferes currently queued, including current bufer</summary>
System::UInt32 VoiceState::BuffersQueued::get()
{
	return this->buffersQueued;
}

/// <summary>Number of bufferes currently queued, including current bufer</summary>
void VoiceState::BuffersQueued::set(System::UInt32 value)
{
	this->buffersQueued = value;
}

/// <summary>Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag).</summary>
/// <remarks>
///		This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured,
///		this parameter would be the length of the audio stream in samples. If you specify XAUDIO2_VOICE_NOSAMPLESPLAYED when you call IXAudio2SourceVoice::GetState,
///		this member won't be calculated, and its value is unspecified on return from IXAudio2SourceVoice::GetState.
///		IXAudio2SourceVoice::GetState takes about one-third as much time to complete when you specify XAUDIO2_VOICE_NOSAMPLESPLAYED. XAudio2 2.8+ only.
/// </remarks>
System::UInt64 VoiceState::SamplesPlayed::get()
{
	return this->samplesPlayed;
}

/// <summary>Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag).</summary>
/// <remarks>
///		This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured,
///		this parameter would be the length of the audio stream in samples. If you specify XAUDIO2_VOICE_NOSAMPLESPLAYED when you call IXAudio2SourceVoice::GetState,
///		this member won't be calculated, and its value is unspecified on return from IXAudio2SourceVoice::GetState.
///		IXAudio2SourceVoice::GetState takes about one-third as much time to complete when you specify XAUDIO2_VOICE_NOSAMPLESPLAYED. XAudio2 2.8+ only.
/// </remarks>
void VoiceState::SamplesPlayed::set(System::UInt64 value)
{
	this->samplesPlayed = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="buffer">Buffer context defined and used by the client</param>
/// <param name="buffers">Number of buffers queued</param>
/// <param name="samples">Number of samples played so far</param>
VoiceState::VoiceState(System::IntPtr buffer, System::UInt32 buffers, System::UInt64 samples)
{
	this->bufferContext = buffer;
	this->buffersQueued = buffers;
	this->samplesPlayed = samples;
}

/// <summary>Unmanaged constructor</summary>
/// <param name="state">Unmanaged XAUDIO2_VOICE_DETAILS struct</param>
VoiceState::VoiceState(XAUDIO2_VOICE_STATE state)
{
	this->bufferContext = System::IntPtr(state.pCurrentBufferContext);
	this->buffersQueued = state.BuffersQueued;
	this->samplesPlayed = state.SamplesPlayed;
}
#pragma endregion
				


#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_VOICE_STATE struct</returns>
XAUDIO2_VOICE_STATE VoiceState::ToUnmanaged()
{
	XAUDIO2_VOICE_STATE state;

	state.pCurrentBufferContext = this->bufferContext.ToPointer();
	state.BuffersQueued = this->buffersQueued;
	state.SamplesPlayed = this->samplesPlayed;

	return state;
}
#pragma endregion

