
#include "Audio Buffer.h"

using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Flags that provide additional infor for the buffer.</summary>
/// <value>May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</value>
System::UInt32 AudioBuffer::Flags::get()
{
	return this->flags;
}

/// <summary>Flags that provide additional infor for the buffer.</summary>
/// <value>May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</value>
void AudioBuffer::Flags::set(System::UInt32 value)
{
	this->flags = value;
}

/// <summary>Raw audio data of the PCM or WMA/XMA data.</summary>
array<System::Byte>^ AudioBuffer::AudioData::get()
{
	return this->audioData;
}

/// <summary>Raw audio data of the PCM or WMA/XMA data.</summary>
void AudioBuffer::AudioData::set(array<System::Byte>^ value)
{
	this->audioData = value;
}

/// <summary>First sample of the audio data to start playing</summary>
/// <remarks>XMA requires 128 modular alignment</remarks>
System::UInt32 AudioBuffer::PlayBegin::get()
{
	return this->playBegin;
}

/// <summary>First sample of the audio data to start playing</summary>
/// <remarks>XMA requires 128 modular alignment</remarks>
void AudioBuffer::PlayBegin::set(System::UInt32 value)
{
	this->playBegin = value;
}

/// <summary>Length of sample of the audio data to play</summary>
/// <value>0 means entire buffer, but playBegin must also be 0</value>
/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block.</remarks>
System::UInt32 AudioBuffer::PlayLength::get()
{
	return this->playLength;
}

/// <summary>Length of sample of the audio data to play</summary>
/// <value>0 means entire buffer, but playBegin must also be 0</value>
/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block.</remarks>
void AudioBuffer::PlayLength::set(System::UInt32 value)
{
	this->playLength = value;
}

/// <summary>First sample to loop from.</summary>
/// <value>Must be within the range of playBegin and playLength. Must be zero for xWMA. Must be 0 if count is 0.</value>
/// <remarks>XMA requires 128 modular alignment</remarks>
System::UInt32 AudioBuffer::LoopBegin::get()
{
	return this->loopBegin;
}

/// <summary>First sample to loop from.</summary>
/// <value>Must be within the range of playBegin and playLength. Must be zero for xWMA. Must be 0 if count is 0.</value>
/// <remarks>XMA requires 128 modular alignment</remarks>
void AudioBuffer::LoopBegin::set(System::UInt32 value)
{
	this->loopBegin = value;
}

/// <summary>Length of samples to loop</summary>
/// <value>Must be within the range of playBegin and playLength. Must be 0 if count is 0.</value>
/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block. xWMA must be 0 or whole sample length</remarks>
System::UInt32 AudioBuffer::LoopLength::get()
{
	return this->loopLength;
}

/// <summary>Length of samples to loop</summary>
/// <value>Must be within the range of playBegin and playLength. Must be 0 if count is 0.</value>
/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block. xWMA must be 0 or whole sample length</remarks>
void AudioBuffer::LoopLength::set(System::UInt32 value)
{
	this->loopLength = value;
}

/// <summary>Count of iterations to loop</summary>
/// <value>Must be between 0 and XAUDIO2_MAX_LOOP_COUNT (254). To continuously loop, set to XAUDIO2_LOOP_INFINITE (255).</value>
/// <remarks>xWMA must be 0 or else flags must be set to XAUDIO2_END_OF_STREAM (0x0040)</remarks>
System::UInt32 AudioBuffer::LoopCount::get()
{
	return this->loopCount;
}

/// <summary>Count of iterations to loop</summary>
/// <value>Must be between 0 and XAUDIO2_MAX_LOOP_COUNT (254). To continuously loop, set to XAUDIO2_LOOP_INFINITE (255).</value>
/// <remarks>xWMA must be 0 or else flags must be set to XAUDIO2_END_OF_STREAM (0x0040)</remarks>
void AudioBuffer::LoopCount::set(System::UInt32 value)
{
	this->loopCount = value;
}

/// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
System::IntPtr AudioBuffer::Context::get()
{
	return this->context;
}

/// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
void AudioBuffer::Context::set(System::IntPtr value)
{
	this->context = value;
}

/// <summary>Flags to create voice, abstracted values by voice type</summary>
void* AudioBuffer::BufferContext::get()
{
	return this->context.ToPointer();
}

/// <summary>Flags to create voice, abstracted values by voice type</summary>
void AudioBuffer::BufferContext::set(void* value)
{
	this->context = System::IntPtr(value);
}
#pragma endregion


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="flagsCreation">Buffer flags. May be 0 or XAUDIO2_END_OF_STREAM</param>
/// <param name="data">Audio data stream</param>
/// <param name="beginPlay">Sample # within audio data to start playing</param>
/// <param name="lengthPlay">Length of audio samples to play</param>
/// <param name="beginLoop">Location to sample to start looping from</param>
/// <param name="lengthLoop">Length of audio samples to loop</param>
/// <param name="countLoop">Number of loops to complete looping</param>
/// <param name="ptrContext">Client context pointer for this buffer</param>
AudioBuffer::AudioBuffer(System::UInt32 flagsCreation, array<System::Byte>^ data, System::UInt32 beginPlay, System::UInt32 lengthPlay, System::UInt32 beginLoop, System::UInt32 lengthLoop, System::UInt32 countLoop, System::IntPtr ptrContext)
{
	this->flags = flagsCreation;
	this->audioData = data;
	this->playBegin = beginPlay;
	this->playLength = playLength;
	this->loopBegin = beginLoop;
	this->loopLength = lengthLoop;
	this->loopCount = countLoop;
	this->context = ptrContext;
}
					
/// <summary>Unmanaged constructor</summary>
/// <param name="buffer">Unmanaged XAUDIO2_BUFFER struct</param>
AudioBuffer::AudioBuffer(XAUDIO2_BUFFER buffer)
{
	this->flags = buffer.Flags;

	this->audioData = gcnew array<System::Byte>(buffer.AudioBytes);

	// to avoid a cannot convert error from const BYTE *, have to directly cast it to void*; reinterpret_cast gives no love.
	System::Runtime::InteropServices::Marshal::Copy(System::IntPtr((void*)(buffer.pAudioData)), this->audioData, 0, System::Convert::ToInt32(buffer.AudioBytes));
	
	this->playBegin = buffer.PlayBegin;
	this->playLength = buffer.PlayLength;
	this->loopBegin = buffer.LoopBegin;
	this->loopLength = buffer.LoopLength;
	this->loopCount = buffer.LoopCount;
	this->context = System::IntPtr(buffer.pContext);
}
#pragma endregion
					


#pragma region Destruction
/// <summary>Destrutor</summary>
/// <remarks>Dispose()</remarks>
AudioBuffer::~AudioBuffer()
{
	this->DisposeUnmanaged();
	this->audioData = nullptr;
}

/// <summary>Destrutor</summary>
/// <remarks>Finalize()</remarks>
AudioBuffer::!AudioBuffer()
{
	this->DisposeUnmanaged();
}

/// <summary>Destrutor logic, disposes the object</summary>
void AudioBuffer::DisposeUnmanaged()
{
	// Dispose this voice
	if (this->gcHandle.IsAllocated)
	{
		this->gcHandle.Free();
		//no way to set GCHandle to nullptr, etc? Setting is IntPtr to IntPtr.Zero errors.
	}
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_BUFFER struct</returns>
XAUDIO2_BUFFER AudioBuffer::ToUnmanaged()
{
	XAUDIO2_BUFFER buffer;

	buffer.Flags = this->flags;
	
	//Copy the data. Slow/glitches during audio and video playback
	//buffer.AudioBytes = this->audioData->Length;
	//buffer.pAudioData = new unsigned char[this->audioData->Length];
	//System::Runtime::InteropServices::Marshal::Copy(this->audioData, 0, System::IntPtr((void*)(buffer.pAudioData)), buffer.AudioBytes);

	if (this->audioData == nullptr)
	{
		buffer.AudioBytes = 0U;
		buffer.pAudioData = NULL;
	}
	else	//pinning the pointer is worthless, because XAudio2 will still need it once the submission is complete
	{
		buffer.AudioBytes = this->audioData->Length;

		//set garbage collection to a no-no
        this->gcHandle = System::Runtime::InteropServices::GCHandle::Alloc(this->audioData, System::Runtime::InteropServices::GCHandleType::Pinned);
		buffer.pAudioData = reinterpret_cast<const BYTE*>(this->gcHandle.AddrOfPinnedObject().ToPointer());
	}

	buffer.PlayBegin = this->playBegin;
	buffer.PlayLength = this->playLength;
	buffer.LoopBegin = this->loopBegin;
	buffer.LoopLength = this->loopLength;
	buffer.LoopCount = this->loopCount;
	buffer.pContext = this->context.ToPointer();

	return buffer;
}
#pragma endregion