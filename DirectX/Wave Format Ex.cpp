
#include "Wave Format Ex.h"

using namespace System::Text;
using namespace Bardez::Projects::DirectX::Sound;
				


#pragma region Properties
/// <summary>Integer identifier of the format</summary>
System::UInt16 WaveFormatEx::FormatTag::get()
{
	return this->formatTag;
}

/// <summary>Integer identifier of the format</summary>
void WaveFormatEx::FormatTag::set(System::UInt16 value)
{
	this->formatTag = value;
}

/// <summary>Number of audio channels</summary>
System::UInt16 WaveFormatEx::NumberChannels::get()
{
	return this->numberChannels;
}

/// <summary>Number of audio channels</summary>
void WaveFormatEx::NumberChannels::set(System::UInt16 value)
{
	this->numberChannels = value;
}

/// <summary>Audio sample rate</summary>
System::UInt32 WaveFormatEx::SamplesPerSec::get()
{
	return this->samplesPerSec;
}

/// <summary>Audio sample rate</summary>
void WaveFormatEx::SamplesPerSec::set(System::UInt32 value)
{
	this->samplesPerSec = value;
}

/// <summary>Bytes per second (possibly approximate)</summary>
System::UInt32 WaveFormatEx::AverageBytesPerSec::get()
{
	return this->averageBytesPerSec;
}

/// <summary>Bytes per second (possibly approximate)</summary>
void WaveFormatEx::AverageBytesPerSec::set(System::UInt32 value)
{
	this->averageBytesPerSec = value;
}

/// <summary>Size in bytes of a sample block (all channels)</summary>
System::UInt16 WaveFormatEx::BlockAlignment::get()
{
	return this->blockAlignment;
}

/// <summary>Size in bytes of a sample block (all channels)</summary>
void WaveFormatEx::BlockAlignment::set(System::UInt16 value)
{
	this->blockAlignment = value;
}

/// <summary>Size in bits of a single per-channel sample</summary>
/// <remarks>16 bit is optimal for XAudio2, 32 bit following, then other formats.</remarks>
System::UInt16 WaveFormatEx::BitsPerSample::get()
{
	return this->bitsPerSample;
}

/// <summary>Size in bits of a single per-channel sample</summary>
/// <remarks>16 bit is optimal for XAudio2, 32 bit following, then other formats.</remarks>
void WaveFormatEx::BitsPerSample::set(System::UInt16 value)
{
	this->bitsPerSample = value;
}

/// <summary>Bytes of extra data appended to this struct</summary>
System::UInt16 WaveFormatEx::Size::get()
{
	return this->size;
}

/// <summary>Bytes of extra data appended to this struct</summary>
void WaveFormatEx::Size::set(System::UInt16 value)
{
	this->size = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
WaveFormatEx::WaveFormatEx(WAVEFORMATEX wave)
{
	this->formatTag = wave.wFormatTag;
	this->numberChannels = wave.nChannels;
	this->samplesPerSec = wave.nSamplesPerSec;
	this->averageBytesPerSec = wave.nAvgBytesPerSec;
	this->blockAlignment = wave.nBlockAlign;
	this->bitsPerSample = wave.wBitsPerSample;
	this->size = wave.cbSize;
}
#pragma endregion



#pragma region Methods
/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
/// <returns>A String representing the WaveFormatEx Object contents</returns>
String^ WaveFormatEx::ToDescriptionString()
{
	String^ desc = nullptr;

	StringBuilder^ builder = gcnew StringBuilder();
	builder->Append("\tFormat tag:                        ");
	builder->Append(this->formatTag);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tNumber of Channels:                ");
	builder->Append(this->numberChannels);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tSamples per Second:                ");
	builder->Append(this->samplesPerSec);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tAverage # of Bytes per Second:     ");
	builder->Append(this->averageBytesPerSec);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tBlock Alignment:                   ");
	builder->Append(this->blockAlignment);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tBits per Sample:                   ");
	builder->Append(this->bitsPerSample);
	builder->AppendLine(System::String::Empty);
	builder->Append("\tSize of extended data:             ");
	builder->Append(this->size);
	builder->AppendLine(System::String::Empty);

	desc = builder->ToString();
	
	return desc;
}

/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged WAVEFORMATEX struct</returns>
WAVEFORMATEX WaveFormatEx::ToUnmanaged()
{
	WAVEFORMATEX wave;

	wave.wFormatTag = this->formatTag;
	wave.nChannels = this->numberChannels;
	wave.nSamplesPerSec = this->samplesPerSec;
	wave.nAvgBytesPerSec = this->averageBytesPerSec;
	wave.nBlockAlign = this->blockAlignment;
	wave.wBitsPerSample = this->bitsPerSample;
	wave.cbSize = this->size;

	return wave;
}
#pragma endregion