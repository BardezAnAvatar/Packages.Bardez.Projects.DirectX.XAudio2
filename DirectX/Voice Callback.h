
#ifndef Bardez_Projects_Directx_XAudio2_VoiceCallback
#define Bardez_Projects_Directx_XAudio2_VoiceCallback

#include "Callback Delegates.h"
#include "Result Codes.h"

using namespace System;

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
					event XAudio2VoiceBufferEndHandler^ bufferEnd;

					/// <summary>Called when the voice starts processing a buffer</summary>
					event XAudio2VoiceBufferStartHandler^ bufferStart;

					/// <summary>Called when the voice finishes processing a loop</summary>
					event XAudio2VoiceLoopEndHandler^ loopEnd;

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					event XAudio2VoiceStreamEndHandler^ streamEnd;

					/// <summary>Called when the voice encounters a critical error</summary>
					event XAudio2VoiceErrorHandler^ error;

					/// <summary>Called just after the processing pass for the voice ends</summary>
					event XAudio2VoiceProcessingPassEndHandler^ processingPassEnd;

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
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



				#pragma region Methods
				internal:
					/// <summary>Called when the voice finishes processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnBufferEnd(System::IntPtr bufferContext);

					/// <summary>Called when the voice starts processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnBufferStart(System::IntPtr bufferContext);

					/// <summary>Called when the voice finishes processing a loop</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnLoopEnd(System::IntPtr bufferContext);

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					virtual void OnStreamEnd();

					/// <summary>Called when the voice encounters a critical error</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					/// <param name="error">Error encountered</param>
					virtual void OnVoiceError(System::IntPtr bufferContext, ResultCode error);

					/// <summary>Called just after the processing pass for the voice ends</summary>
					virtual void OnVoiceProcessingPassEnd();

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
					virtual void OnVoiceProcessingPassStart(System::UInt32 bytesRequired);
				#pragma endregion
				};
			}
		}
	}
}

#endif