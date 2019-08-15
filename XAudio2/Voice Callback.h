
#ifndef Bardez_Projects_Directx_XAudio2_VoiceCallback
#define Bardez_Projects_Directx_XAudio2_VoiceCallback

#include "Callback Delegates.h"

using namespace Bardez::Projects::BasicStructures::Win32;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Callback base from the XAudio2 voice</summary>
				/// <remarks>This class exposes events that can be attached to in the event of a callback</remarks>
				public ref class VoiceCallback
				{
				#pragma region Members
				internal:
					/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
					System::IntPtr callbackPointer;
				#pragma endregion



				#pragma region Properties
				internal:
					/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
					property System::IntPtr CallbackPointer
					{
						System::IntPtr get();
						void set(System::IntPtr value);
					}
				#pragma endregion



				#pragma region Events
				protected:
					/// <summary>Called when the voice finishes processing a buffer</summary>
					/// <remarks>
					///		OnBufferEnd is guaranteed to be called just after the last byte of the current buffer has
					///		been consumed and before the first byte of the next buffer is consumed. This callback can be
					///		used to overwrite or release the audio data referenced by the completed buffer, and to update
					///		other state associated with the voice as appropriate.
					/// </remarks>
					event XAudio2VoiceBufferEndHandler^ bufferEnd;

					/// <summary>Called when the voice starts processing a buffer</summary>
					/// <remarks>
					///		OnBufferStart is guaranteed to be called just before the first byte of the current buffer
					///		is consumed. It is appropriate to use this callback for changes to the voice state such as
					///		the following:
					///		1) Submitting a new buffer to the voice
					///		2) Adjusting the volume, pitch, and effect parameters of the voice
					///		3) Enabling or disabling an effect in the voice's effect chain
					///
					///		All the actions listed above are synchronous when performed in an XAudio2 callback, so the
					///		changes will take effect immediately, affecting the buffer that is about to start.
					///
					///		It is also safe to use this callback to write audio data to the buffer directly, which
					///		can be useful for low-latency streaming scenarios. However, as with all XAudio2 callbacks,
					///		no work should be done that uses a significant amount of processor time or could block
					///		execution, including synchronous disk or network reads.
					/// </remarks>
					event XAudio2VoiceBufferStartHandler^ bufferStart;

					/// <summary>Called when the voice finishes processing a loop</summary>
					/// <remarks>
					///		OnLoopEnd is not sample-accurate; that is, actions in the callback do not occur at the
					///		exact moment that a given sample is being processed. It is only guaranteed to be called
					///		shortly after the last sample in the loop has been processed.
					/// </remarks>
					event XAudio2VoiceLoopEndHandler^ loopEnd;

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					/// <remarks>
					///		The OnStreamEnd callback indicates that XAudio2 has finished consuming the last buffer
					///		submitted to the voice. The state of the audio after OnStreamEnd has been called depends
					///		on the type (PCM, XMA, and WMA) of audio data being processed. With PCM data, all audio is
					///		guaranteed to have been played and the voice can be stopped or destroyed safely.
					///		With XMA and WMA data, the audio data has been processed after the callback and the memory
					///		associated with the buffer can be released, but the audio has not necessarily finished playing.
					///		To ensure the voice is not cut off, allow time—up to the length of the last buffer in
					///		samples—to pass before stopping or destroying the voice.
					/// 
					///		The OnStreamEnd callback only indicates that an XAUDIO2_BUFFER with the XAUDIO2_END_OF_STREAM
					///		flag set has been processed. The callback is strictly informational and does not change the
					///		state of the source voice that triggered it. A voice stays in the start state until
					///		IXAudio2SourceVoice::Stop is called and will continue to play submitted source buffers and to
					///		trigger additional callbacks.
					///	
					///		OnStreamEnd is guaranteed to be called just after the last byte of the current buffer has been
					///		consumed.
					///	</remarks>
					event XAudio2VoiceStreamEndHandler^ streamEnd;

					/// <summary>Called when the voice encounters a critical error</summary>
					/// <remarks>
					///		OnVoiceError is called in the event of an error during voice processing, such as a hardware
					///		XMA decoder error on the Xbox 360. The arguments report which buffer was being processed at
					///		the time of the error, and its ResultCode. If the error is not recoverable by destroying and
					///		re-creating the voice, the OnCriticalError engine callback will be called as well.
					/// </remarks>
					event XAudio2VoiceErrorHandler^ error;

					/// <summary>Called just after the processing pass for the voice ends</summary>
					event XAudio2VoiceProcessingPassEndHandler^ processingPassEnd;

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					/// <remarks>This probably is the event to raise when requesting more data.</remarks>
					event XAudio2VoiceProcessingPassStartHandler^ processingPassStart;
				#pragma endregion



				#pragma region Event Exposure
				public:
					/// <summary>Called when the voice finishes processing a buffer</summary>
					event XAudio2VoiceBufferEndHandler^ BufferEnd
					{
						void add(XAudio2VoiceBufferEndHandler^ handler);
						void remove(XAudio2VoiceBufferEndHandler^ handler);
						void raise(System::IntPtr bufferContext);
					}

					/// <summary>Called when the voice starts processing a buffer</summary>
					event XAudio2VoiceBufferStartHandler^ BufferStart
					{
						void add(XAudio2VoiceBufferStartHandler^ handler);
						void remove(XAudio2VoiceBufferStartHandler^ handler);
						void raise(System::IntPtr bufferContext);
					}

					/// <summary>Called when the voice finishes processing a loop</summary>
					event XAudio2VoiceLoopEndHandler^ LoopEnd
					{
						void add(XAudio2VoiceLoopEndHandler^ handler);
						void remove(XAudio2VoiceLoopEndHandler^ handler);
						void raise(System::IntPtr bufferContext);
					}

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					event XAudio2VoiceStreamEndHandler^ StreamEnd
					{
						void add(XAudio2VoiceStreamEndHandler^ handler);
						void remove(XAudio2VoiceStreamEndHandler^ handler);
						void raise();
					}

					/// <summary>Called when the voice encounters a critical error</summary>
					event XAudio2VoiceErrorHandler^ Error
					{
						void add(XAudio2VoiceErrorHandler^ handler);
						void remove(XAudio2VoiceErrorHandler^ handler);
						void raise(System::IntPtr bufferContext, ResultCode error);
					}

					/// <summary>Called just after the processing pass for the voice ends</summary>
					event XAudio2VoiceProcessingPassEndHandler^ ProcessingPassEnd
					{
						void add(XAudio2VoiceProcessingPassEndHandler^ handler);
						void remove(XAudio2VoiceProcessingPassEndHandler^ handler);
						void raise();
					}

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					event XAudio2VoiceProcessingPassStartHandler^ ProcessingPassStart
					{
						void add(XAudio2VoiceProcessingPassStartHandler^ handler);
						void remove(XAudio2VoiceProcessingPassStartHandler^ handler);
						void raise(System::UInt32 bytesRequired);
					}
				#pragma endregion



				#pragma region Event Invokation
				internal:
					/// <summary>Called when the voice finishes processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void RaiseBufferEnd(System::IntPtr bufferContext);

					/// <summary>Called when the voice starts processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void RaiseBufferStart(System::IntPtr bufferContext);

					/// <summary>Called when the voice finishes processing a loop</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void RaiseLoopEnd(System::IntPtr bufferContext);

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					virtual void RaiseStreamEnd();

					/// <summary>Called when the voice encounters a critical error</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					/// <param name="error">Error encountered</param>
					virtual void RaiseVoiceError(System::IntPtr bufferContext, ResultCode error);

					/// <summary>Called just after the processing pass for the voice ends</summary>
					virtual void RaiseVoiceProcessingPassEnd();

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
					virtual void RaiseVoiceProcessingPassStart(System::UInt32 bytesRequired);
				#pragma endregion
				};
			}
		}
	}
}

#endif