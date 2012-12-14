
#ifndef Bardez_Projects_DirectX_XAudio2_WaveFormatExtensibleConverter
#define Bardez_Projects_DirectX_XAudio2_WaveFormatExtensibleConverter

#include <windows.h>

using namespace System;
using namespace Bardez::Projects::BasicStructures::Win32::Audio;

#include <Windows.h>
#include <XAudio2.h>

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Converts types between WAVEFORMATEXTENSIBLE Win32 API and .NET reference classes</summary>
				/// <remarks>Code was originally in the class itself, marked internal, but moving the class proved to be problematic when linking, so maing a converter class.</remarks>
				private ref class WaveFormatExtensibleWin32Converter abstract sealed
				{
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged WAVEFORMATEXTENSIBLE struct</returns>
					static WAVEFORMATEXTENSIBLE To_WAVEFORMATEXTENSIBLE(WaveFormatExtensible^ waveFormat);

					/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
					static WaveFormatEx^ BuildWaveFormatEx(WAVEFORMATEXTENSIBLE waveFormat);

					/// <summary>Unmanaged WAVEFORMATEXTENSIBLE Win32 constructor</summary>
					static WaveFormatExtensible^ BuildWaveFormatExtensible(WAVEFORMATEXTENSIBLE waveFormat);
				};
			}
		}
	}
}

#endif

