
#include "Wave Format Extensible.h"

using namespace System::Text;
using namespace Bardez::Projects::DirectX::Sound;


/// <summary>WAVEFORMATEX Win32 constructor</summary>
WaveFormatExtensible::WaveFormatExtensible(WAVEFORMATEXTENSIBLE waveEx)
{
	//WAVEFORMATEX
	this->formatTag = waveEx.Format.wFormatTag;
	this->numberChannels = waveEx.Format.nChannels;
	this->samplesPerSec = waveEx.Format.nSamplesPerSec;
	this->averageBytesPerSec = waveEx.Format.nAvgBytesPerSec;
	this->blockAlignment = waveEx.Format.nBlockAlign;
	this->bitsPerSample = waveEx.Format.wBitsPerSample;
	this->size = waveEx.Format.cbSize;

	//WAVEFORMATEXTENSIBLE REMAINDER
	this->samples = waveEx.Samples.wSamplesPerBlock;
	this->channelMask = waveEx.dwChannelMask;
	this->subFormat =  System::Guid
		(waveEx.SubFormat.Data1, waveEx.SubFormat.Data2, waveEx.SubFormat.Data3,
			waveEx.SubFormat.Data4[0], waveEx.SubFormat.Data4[1], waveEx.SubFormat.Data4[2], waveEx.SubFormat.Data4[3], 
			waveEx.SubFormat.Data4[4], waveEx.SubFormat.Data4[5], waveEx.SubFormat.Data4[6], waveEx.SubFormat.Data4[7]
		);
}

#pragma region Methods
/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
/// <returns>A String representing the WaveFormatExtensible Object contents</returns>
String^ WaveFormatExtensible::ToDescriptionString()
{
	String^ desc = nullptr;

	StringBuilder^ builder = gcnew StringBuilder();
	//base type
	builder->Append(((WaveFormatEx^)this)->ToDescriptionString());

	//remainder data
	builder->Append("\tNumber of samples:                 ");
	builder->Append(this->samples);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tAudio channel positions(s):        ");
	builder->Append(this->channelMask);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tFormat GUID identifier:            ");
	builder->Append(this->subFormat.ToString());
	builder->AppendLine(System::String::Empty);

	desc = builder->ToString();
	
	return desc;
}

/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged WAVEFORMATEX struct</returns>
WAVEFORMATEXTENSIBLE WaveFormatExtensible::ToUnmanaged()
{
	WAVEFORMATEXTENSIBLE waveext;

	waveext.Format = WaveFormatEx::ToUnmanaged();		//base data
	waveext.Samples.wSamplesPerBlock = this->samples;	//union data
	waveext.dwChannelMask = this->channelMask;
		
	array<System::String^>^ guid = this->subFormat.ToString()->Split('-');
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