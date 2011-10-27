#ifndef Bardez_Projects_Directx_XAudio2_VoiceState
#define Bardez_Projects_Directx_XAudio2_VoiceState


#include <xaudio2.h>
#include "Audio Buffer.h"


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed XAUDIO2_VOICE_STATE structure</summary>
				/// <remarks>Represents the voice's current state and cursor position data. Do not destroy the pointer, as it is used over and again by the client.</remarks>
				public ref class VoiceState
				{
				#pragma region Members
				protected:
					/// <summary>Context for the buffer, for the client to define and use during callbacks</summary>
					System::IntPtr bufferContext;

					/// <summary>Number of bufferes currently queued, including current bufer</summary>
					System::UInt32 buffersQueued;

					/// <summary>Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag).</summary>
					/// <remarks>
					///		This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured,
					///		this parameter would be the length of the audio stream in samples. If you specify XAUDIO2_VOICE_NOSAMPLESPLAYED when you call IXAudio2SourceVoice::GetState,
					///		this member won't be calculated, and its value is unspecified on return from IXAudio2SourceVoice::GetState.
					///		IXAudio2SourceVoice::GetState takes about one-third as much time to complete when you specify XAUDIO2_VOICE_NOSAMPLESPLAYED. XAudio2 2.8+ only.
					/// </remarks>
					System::UInt64 samplesPlayed;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Context for the buffer, for the client to define and use during callbacks</summary>
					property System::IntPtr BufferContext
					{
						System::IntPtr get();
						void set(System::IntPtr value);
					}

					/// <summary>Number of bufferes currently queued, including current bufer</summary>
					property System::UInt32 BuffersQueued
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag).</summary>
					/// <remarks>
					///		This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured,
					///		this parameter would be the length of the audio stream in samples. If you specify XAUDIO2_VOICE_NOSAMPLESPLAYED when you call IXAudio2SourceVoice::GetState,
					///		this member won't be calculated, and its value is unspecified on return from IXAudio2SourceVoice::GetState.
					///		IXAudio2SourceVoice::GetState takes about one-third as much time to complete when you specify XAUDIO2_VOICE_NOSAMPLESPLAYED. XAudio2 2.8+ only.
					/// </remarks>
					property System::UInt64 SamplesPlayed
					{
						System::UInt64 get();
						void set(System::UInt64 value);
					}
				#pragma endregion



				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					VoiceState() {}

					/// <summary>Definition constructor</summary>
					/// <param name="buffer">Buffer context defined and used by the client</param>
					/// <param name="buffers">Number of buffers queued</param>
					/// <param name="samples">Number of samples played so far</param>
					VoiceState(System::IntPtr buffer, System::UInt32 buffers, System::UInt64 samples);

				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="state">Unmanaged XAUDIO2_VOICE_DETAILS struct</param>
					VoiceState(XAUDIO2_VOICE_STATE state);
				#pragma endregion
				


				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_VOICE_STATE struct</returns>
					XAUDIO2_VOICE_STATE ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif