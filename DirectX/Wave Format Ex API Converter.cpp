
#include "Wave Format Ex API Converter.h"

using namespace System::Text;
using namespace Bardez::Projects::DirectX::XAudio2;


/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
WaveFormatEx^ WaveFormatExWin32Converter::BuildWaveFormatEx(WAVEFORMATEX waveFormat)
{
	WaveFormatEx^ wave = gcnew WaveFormatEx();
	
	wave->FormatTag = waveFormat.wFormatTag;
	wave->NumberChannels = waveFormat.nChannels;
	wave->SamplesPerSec = waveFormat.nSamplesPerSec;
	wave->AverageBytesPerSec = waveFormat.nAvgBytesPerSec;
	wave->BlockAlignment = waveFormat.nBlockAlign;
	wave->BitsPerSample = waveFormat.wBitsPerSample;
	wave->Size = waveFormat.cbSize;

	return wave;
}

/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged WAVEFORMATEX struct</returns>
WAVEFORMATEX WaveFormatExWin32Converter::To_WAVEFORMATEX(WaveFormatEx^ waveFormat)
{
	WAVEFORMATEX wave;

	wave.wFormatTag = waveFormat->FormatTag;
	wave.nChannels = waveFormat->NumberChannels;
	wave.nSamplesPerSec = waveFormat->SamplesPerSec;
	wave.nAvgBytesPerSec = waveFormat->AverageBytesPerSec;
	wave.nBlockAlign = waveFormat->BlockAlignment;
	wave.wBitsPerSample = waveFormat->BitsPerSample;
	wave.cbSize = waveFormat->Size;

	return wave;
}

