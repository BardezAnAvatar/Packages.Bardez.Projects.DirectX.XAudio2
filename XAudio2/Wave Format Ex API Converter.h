
#ifndef Bardez_Projects_DirectX_XAudio2_WaveFormatExConverter
#define Bardez_Projects_DirectX_XAudio2_WaveFormatExConverter

#include <windows.h>

using namespace System;
using namespace Bardez::Projects::Win32::Audio;

#include <Windows.h>

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Converts types between WAVEFORMATEX Win32 API and .NET reference classes</summary>
				/// <remarks>Code was originally in the class itself, marked internal, but moving the class proved to be problematic when linking, so maing a converter class.</remarks>
				private ref class WaveFormatExWin32Converter abstract sealed
				{
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged WAVEFORMATEX struct</returns>
					static WAVEFORMATEX To_WAVEFORMATEX(WaveFormatEx^ waveFormat);
					
					/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
					static WaveFormatEx^ BuildWaveFormatEx(WAVEFORMATEX waveFormat);
				};
			}
		}
	}
}

#endif

