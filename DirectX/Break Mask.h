
#ifndef Bardez_Projects_Directx_XAudio2_BreakMask
#define Bardez_Projects_Directx_XAudio2_BreakMask

#include <XAudio2.h>

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Enumerator for BreakMask flags</summary>
				[System::Flags]
				public enum struct BreakMask : System::UInt32
				{
					None = 0UL,

					LogErrors = XAUDIO2_LOG_ERRORS,				//1

					/// <remarks>Implies LogErrors</remarks>
					LogWarnings = XAUDIO2_LOG_WARNINGS			//2
				};
			}
		}
	}
}

#endif
