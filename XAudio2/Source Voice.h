

#ifndef Bardez_Projects_Directx_XAudio2_SourceVoice
#define Bardez_Projects_Directx_XAudio2_SourceVoice

#include <XAudio2.h>
#include "Audio Buffer.h"
#include "Version.h"
#include "Voice.h"
#include "Voice Callback.h"
#include "Voice State.h"
#include "WMA Buffer.h"

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Source Voice voice for the Voice audio graph</summary>
				/// <remarks>
				///		You must send voice data to a mastering voice to be heard, either directly or through intermediate submix voices.
				///	</remarks>
				public ref class SourceVoice : Voice
				{
				#pragma region Constants
				public:
					/// <summary>Constant count of maximum buffers for a source voice that can be queued.</summary>
					static const System::UInt32 MaximumBuffersQueued = XAUDIO2_MAX_QUEUED_BUFFERS;
				#pragma endregion


				#pragma region Fields
				protected:
					/// <summary>Reference to the voice callback object for this source voice</summary>
					VoiceCallback^ callback;
				#pragma endregion



				#pragma region Properties
				internal:
					/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
					property IXAudio2SourceVoice* XAudio2SourceVoice
					{
						IXAudio2SourceVoice* get();
						void set(IXAudio2SourceVoice* value);
					}

				public:
					/// <summary>Reference to the voice callback object for this source voice</summary>
					property VoiceCallback^ Callback
					{
						VoiceCallback^ get();
						void set(VoiceCallback^ value);
					}
				#pragma endregion



				#pragma region Construction
				internal:
					/// <summary>Definition constructor</summary>
					/// <param name="pointer">Pointer to an XAudio2 source voice interface object</param>
					/// <param name="callback">Callback instance to reference</param>
					SourceVoice(IXAudio2SourceVoice* pointer, VoiceCallback^ callback);
				#pragma endregion



				#pragma region Destruction
				public:
					/// <summary>Destructor</summary>
					/// <remarks>Dispose()</remarks>
					~SourceVoice();

					/// <summary>Destructor</summary>
					/// <remarks>Finalize()</remarks>
					!SourceVoice();
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Notifies a voice that no more buffers are coming after the last one that is currently in its queue.</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Discontinuity();

					/// <summary>Stops looping this voice when it reaches the end of the current loop.</summary>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode ExitLoop(System::UInt32 operationSet);

					/// <summary>Removes all pending audio buffers from this voice's queue.</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode FlushSourceBuffers();

					/// <summary>Gets the frequency adjustment ratio of this voice.</summary>
					/// <returns>The frequency adjustment ratio</returns>
					System::Single GetFrequencyRatio();

					/// <summary>Gets this voice's current cursor position data.</summary>
					/// <returns>A reference to the state of this voice</returns>
					/// <remarks>
					///		If a client needs to obtain the correlated positions of several voices
					///		(i.e. to know exactly which sample of a given voice is playing when a given sample of another voice is playing)
					///		it must make GetState calls in an XAudio2 engine callback, to ensure that none of the voices advance while the calls are being made.
					///		See the XAudio2 Callbacks overview for information about using XAudio2 callbacks.
					/// </remarks>
					VoiceState^ GetState();

					/// <summary>Sets the frequency adjustment ratio of this voice</summary>
					/// <param name="ratio">Frequenct adjustment ratio to set</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>The frequency adjustments I've seen indicate a Doppler factor being set</remarks>
					ResultCode SetFrequencyRatio(System::Single ratio, System::UInt32 operationSet);

					/// <summary>Sets the source data sample rate</summary>
					/// <param name="sampleRate">New sample rate</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode SetSourceSampleRate(System::UInt32 sampleRate);

					/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
					/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Start(System::UInt32 flags, System::UInt32 operationSet);

					/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Start();

					/// <summary>Stops consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
					/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Stop(System::UInt32 flags, System::UInt32 operationSet);

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
					ResultCode SubmitSourceBuffer(Bardez::Projects::DirectX::XAudio2::AudioBuffer^ buffer, WmaBuffer^ bufferWma);
				#pragma endregion
				};
			}
		}
	}
}

#endif

