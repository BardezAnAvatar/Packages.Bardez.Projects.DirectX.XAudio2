
#ifndef Bardez_Projects_Directx_XAudio2_TraceMask
#define Bardez_Projects_Directx_XAudio2_TraceMask

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Enumerator for Tracemask flags</summary>
				[System::Flags]
				public enum struct TraceMask : System::UInt32
				{
					None = 0UL,

					LogErrors = XAUDIO2_LOG_ERRORS,				//1

					/// <remarks>Implies LogErrors</remarks>
					LogWarnings = XAUDIO2_LOG_WARNINGS,			//2

					LogInfo = XAUDIO2_LOG_INFO,					//4

					/// <remarks>Implies LogInfo</remarks>
					LogDetail = XAUDIO2_LOG_DETAIL,				//8

					LogApiCalls = XAUDIO2_LOG_API_CALLS,		//16

					/// <remarks>Implies LogApiCalls</remarks>
					LogFuncCalls = XAUDIO2_LOG_FUNC_CALLS,		//32

					LogTiming = XAUDIO2_LOG_TIMING,				//64
					LogLocks = XAUDIO2_LOG_LOCKS,				//128
					LogMemory = XAUDIO2_LOG_MEMORY,				//256
					LogStreaming = XAUDIO2_LOG_STREAMING		//4096
				};
			}
		}
	}
}

#endif
