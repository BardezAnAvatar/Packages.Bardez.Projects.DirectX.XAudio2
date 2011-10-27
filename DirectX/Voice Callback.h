
#ifndef Bardez_Projects_Directx_XAudio2_VoiceCallback
#define Bardez_Projects_Directx_XAudio2_VoiceCallback

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
				/// <remarks>This class does nothing, and must be inherited from and its methods overwritten to be of any use</remarks>
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
					property System::IntPtr CallbackPointer;
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Called when the voice finishes processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnBufferEnd(System::IntPtr bufferContext) { }

					/// <summary>Called when the voice starts processing a buffer</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnBufferStart(System::IntPtr bufferContext) { }

					/// <summary>Called when the voice finishes processing a loop</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					virtual void OnLoopEnd(System::IntPtr bufferContext) { }

					/// <summary>Called when the voice finishes processing an audio stream</summary>
					virtual void OnStreamEnd() { }

					/// <summary>Called when the voice encounters a critical error</summary>
					/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
					/// <param name="error">Error encountered</param>
					virtual void OnVoiceError(System::IntPtr bufferContext, ResultCode error) { }

					/// <summary>Called just after the processing pass for the voice ends</summary>
					virtual void OnVoiceProcessingPassEnd() { }

					/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
					/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
					virtual void OnVoiceProcessingPassStart(System::UInt32 bytesRequired) { }
				#pragma endregion
				};
			}
		}
	}
}

#endif