
#ifndef Bardez_Projects_Directx_XAudio2_CallbackDelegates
#define Bardez_Projects_Directx_XAudio2_CallbackDelegates

#include "Result Codes.h"

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				#pragma region Voice Callback
                /// <summary>Delegate for when a voice buffer finishes</summary>
                /// <param name="bufferContext">IntPtr for a buffer context</param>
				public delegate void XAudio2VoiceBufferEndHandler(System::IntPtr bufferContext);

                /// <summary>Delegate for when a voice buffer starts</summary>
                /// <param name="bufferContext">IntPtr for a buffer context</param>
                public delegate void XAudio2VoiceBufferStartHandler(System::IntPtr bufferContext);

                /// <summary>Delegate for when a voice loop ends</summary>
                /// <param name="bufferContext">IntPtr for a buffer context</param>
                public delegate void XAudio2VoiceLoopEndHandler(System::IntPtr bufferContext);

                /// <summary>Delegate for when a voice stream ends</summary>
                public delegate void XAudio2VoiceStreamEndHandler();

                /// <summary>Delegate for when a voice error is raised</summary>
                /// <param name="bufferContext">IntPtr for a buffer context</param>
                /// <param name="error">Error encountered</param>
				public delegate void XAudio2VoiceErrorHandler(System::IntPtr bufferContext, ResultCode error);

                /// <summary>Delegate for when a voice processing pass ends</summary>
                public delegate void XAudio2VoiceProcessingPassEndHandler();

                /// <summary>Delegate for when a voice processing pass starts</summary>
                /// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
                public delegate void XAudio2VoiceProcessingPassStartHandler(System::UInt32 bytesRequired);
				#pragma endregion



				#pragma region Engine Callback
                /// <summary>Delegate for when an engine cirital error is raised</summary>
                /// <param name="error">Error encountered</param>
                public delegate void XAudio2EngineCriticalErrorHandler(ResultCode error);

                /// <summary>Delegate for when an engine processing pass ends</summary>
                public delegate void XAudio2EngineProcessingPassEndHandler();

                /// <summary>Delegate for when an engine processing pass starts</summary>
                public delegate void XAudio2EngineProcessingPassStartHandler();
				#pragma endregion
			}
		}
	}
}

#endif
