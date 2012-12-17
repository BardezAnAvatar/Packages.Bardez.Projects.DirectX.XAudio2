
#include "Wave Format Ex API Converter.h"
#include "Wave Format Extensible API Converter.h"

using namespace System::Text;
using namespace Bardez::Projects::DirectX::XAudio2;


/// <summary>Unmanaged WAVEFORMATEXTENSIBLE Win32 constructor</summary>
WaveFormatExtensible^ WaveFormatExtensibleWin32Converter::BuildWaveFormatExtensible(WAVEFORMATEXTENSIBLE waveFormat)
{
	WaveFormatExtensible^ wave = gcnew WaveFormatExtensible();

	//WAVEFORMATEX
	wave->FormatTag = waveFormat.Format.wFormatTag;
	wave->NumberChannels = waveFormat.Format.nChannels;
	wave->SamplesPerSec = waveFormat.Format.nSamplesPerSec;
	wave->AverageBytesPerSec = waveFormat.Format.nAvgBytesPerSec;
	wave->BlockAlignment = waveFormat.Format.nBlockAlign;
	wave->BitsPerSample = waveFormat.Format.wBitsPerSample;
	wave->Size = waveFormat.Format.cbSize;

	//WAVEFORMATEXTENSIBLE REMAINDER
	wave->Samples = waveFormat.Samples.wSamplesPerBlock;
	wave->ChannelMask = (SpeakerPositions)(waveFormat.dwChannelMask);
	wave->SubFormat =  System::Guid
		(waveFormat.SubFormat.Data1, waveFormat.SubFormat.Data2, waveFormat.SubFormat.Data3,
			waveFormat.SubFormat.Data4[0], waveFormat.SubFormat.Data4[1], waveFormat.SubFormat.Data4[2], waveFormat.SubFormat.Data4[3], 
			waveFormat.SubFormat.Data4[4], waveFormat.SubFormat.Data4[5], waveFormat.SubFormat.Data4[6], waveFormat.SubFormat.Data4[7]
		);

	return wave;
}

/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
WaveFormatEx^ WaveFormatExtensibleWin32Converter::BuildWaveFormatEx(WAVEFORMATEXTENSIBLE waveFormat)
{
	return WaveFormatExWin32Converter::BuildWaveFormatEx(waveFormat.Format);
}

/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged WAVEFORMATEXTENSIBLE struct</returns>
WAVEFORMATEXTENSIBLE WaveFormatExtensibleWin32Converter::To_WAVEFORMATEXTENSIBLE(WaveFormatExtensible^ waveFormat)
{	
	WAVEFORMATEXTENSIBLE waveext;

	waveext.Format = WaveFormatExWin32Converter::To_WAVEFORMATEX(waveFormat);	//base data
	waveext.Samples.wSamplesPerBlock = waveFormat->Samples;						//union data
	waveext.dwChannelMask = (System::UInt32)(waveFormat->ChannelMask);
		
	array<System::String^>^ guid = waveFormat->SubFormat.ToString()->Split('-');
	System::String^ long64 = System::String::Concat(guid[3], guid[4]);

	waveext.SubFormat.Data1 = System::UInt32::Parse(guid[0]);
	waveext.SubFormat.Data2 = System::UInt16::Parse(guid[1]);
	waveext.SubFormat.Data3 = System::UInt16::Parse(guid[2]);
	waveext.SubFormat.Data4[0] = System::Byte::Parse(long64->Substring(0, 2));
	waveext.SubFormat.Data4[1] = System::Byte::Parse(long64->Substring(2, 2));
	waveext.SubFormat.Data4[2] = System::Byte::Parse(long64->Substring(4, 2));
	waveext.SubFormat.Data4[3] = System::Byte::Parse(long64->Substring(6, 2));
	waveext.SubFormat.Data4[4] = System::Byte::Parse(long64->Substring(8, 2));
	waveext.SubFormat.Data4[5] = System::Byte::Parse(long64->Substring(10, 2));
	waveext.SubFormat.Data4[6] = System::Byte::Parse(long64->Substring(12, 2));
	waveext.SubFormat.Data4[7] = System::Byte::Parse(long64->Substring(14, 2));

	return waveext;
}

