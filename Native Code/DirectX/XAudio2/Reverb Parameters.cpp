

#include "Reverb Parameters.h"


using namespace System;
using namespace Bardez::Projects::DirectX::XAudio2::FX;


#pragma region Properties
/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
Single ReverbParameters::WetDryMix::get()
{
	return this->wetDryMix;
}

/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
void ReverbParameters::WetDryMix::set(Single value)
{
	this->wetDryMix = value;
}
						
#pragma region Delay Times
/// <summary>The delay time of the first reflection relative to the direct path</summary>
/// <value>Clamped from 0 to 300, in miliseconds</value>
UInt32 ReverbParameters::ReflectionsDelay::get()
{
	return this->reflectionsDelay;
}
						
/// <summary>The delay time of the first reflection relative to the direct path</summary>
/// <value>Clamped from 0 to 300, in miliseconds</value>
void ReverbParameters::ReflectionsDelay::set(UInt32 value)
{
	this->reflectionsDelay = value;
}

/// <summary>Delay of reverb relative to the first reflection</summary>
/// <value>Clamped from 0 to 85, in miliseconds</value>
Byte ReverbParameters::ReverbDelay::get()
{
	return this->reverbDelay;
}

/// <summary>Delay of reverb relative to the first reflection</summary>
/// <value>Clamped from 0 to 85, in miliseconds</value>
void ReverbParameters::ReverbDelay::set(Byte value)
{
	this->reverbDelay = value;
}
						
/// <summary>Delay for the left rear output and right rear output</summary>
/// <value>Clamped from 0 to 5, in miliseconds</value>
Byte ReverbParameters::RearDelay::get()
{
	return this->rearDelay;
}
						
/// <summary>Delay for the left rear output and right rear output</summary>
/// <value>Clamped from 0 to 5, in miliseconds</value>
void ReverbParameters::RearDelay::set(Byte value)
{
	this->rearDelay = value;
}
#pragma endregion

						
#pragma region Indexed parameters
/// <summary>Position of the left input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
/// <remarks>
///		With PositionLeft set to the minimum value, the left input is placed close to the listener.
///		In this position, early reflections are dominant, and the reverb decay is set back in the sound field and reduced in amplitude.
///		With PositionLeft set to the maximum value, the left input is placed at a maximum distance from the listener within the simulated room.
///		PositionLeft does not affect the reverb decay time (liveness of the room), only the apparent position of the source relative to the listener.
///		Permitted range is from 0 to 30 (no units).
/// </remarks>
Byte ReverbParameters::PositionLeft::get()
{
	return this->positionLeft;
}

/// <summary>Position of the left input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
/// <remarks>
///		With PositionLeft set to the minimum value, the left input is placed close to the listener.
///		In this position, early reflections are dominant, and the reverb decay is set back in the sound field and reduced in amplitude.
///		With PositionLeft set to the maximum value, the left input is placed at a maximum distance from the listener within the simulated room.
///		PositionLeft does not affect the reverb decay time (liveness of the room), only the apparent position of the source relative to the listener.
///		Permitted range is from 0 to 30 (no units).
/// </remarks>
void ReverbParameters::PositionLeft::set(Byte value)
{
	this->positionLeft = value;
}
						
/// <summary>Position of the right input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
/// <remarks>Same as <see cref="PositionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
Byte ReverbParameters::PositionRight::get()
{
	return this->positionRight;
}
						
/// <summary>Position of the right input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
/// <remarks>Same as <see cref="PositionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
void ReverbParameters::PositionRight::set(Byte value)
{
	this->positionRight = value;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
Byte ReverbParameters::PositionMatrixLeft::get()
{
	return this->positionMatrixLeft;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
void ReverbParameters::PositionMatrixLeft::set(Byte value)
{
	this->positionMatrixLeft = value;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
Byte ReverbParameters::PositionMatrixRight::get()
{
	return this->positionMatrixRight;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
void ReverbParameters::PositionMatrixRight::set(Byte value)
{
	this->positionMatrixRight = value;
}
						
/// <summary>Controls the character of the individual wall reflections</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
Byte ReverbParameters::EarlyDiffusion::get()
{
	return this->earlyDiffusion;
}
						
/// <summary>Controls the character of the individual wall reflections</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
void ReverbParameters::EarlyDiffusion::set(Byte value)
{
	this->earlyDiffusion = value;
}
						
/// <summary>Controls the character of the individual wall reverberations</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
Byte ReverbParameters::LateDiffusion::get()
{
	return this->lateDiffusion;
}
						
/// <summary>Controls the character of the individual wall reverberations</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
void ReverbParameters::LateDiffusion::set(Byte value)
{
	this->lateDiffusion = value;
}
						
/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
/// <value>Clamped from 0 to 12, no units</value>
/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
Byte ReverbParameters::LowEQGain::get()
{
	return this->lowEQGain;
}
						
/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
/// <value>Clamped from 0 to 12, no units</value>
/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
void ReverbParameters::LowEQGain::set(Byte value)
{
	this->lowEQGain = value;
}
						
/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
/// <value>Clamped from 0 to 9, no units</value>
Byte ReverbParameters::LowEQCutoff::get()
{
	return this->lowEQCutoff;
}
						
/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
/// <value>Clamped from 0 to 9, no units</value>
void ReverbParameters::LowEQCutoff::set(Byte value)
{
	this->lowEQCutoff = value;
}
						
/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
/// <value>Clamped from 0 to 8, no units</value>
/// <remarks>A value of 8 yields no effective change</remarks>
Byte ReverbParameters::HighEQGain::get()
{
	return this->highEQGain;
}
						
/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
/// <value>Clamped from 0 to 8, no units</value>
/// <remarks>A value of 8 yields no effective change</remarks>
void ReverbParameters::HighEQGain::set(Byte value)
{
	this->highEQGain = value;
}
						
/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="HighEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
/// <value>Clamped from 0 to 14, no units</value>
Byte ReverbParameters::HighEQCutoff::get()
{
	return this->highEQCutoff;
}
						
/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="HighEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
/// <value>Clamped from 0 to 14, no units</value>
void ReverbParameters::HighEQCutoff::set(Byte value)
{
	this->highEQCutoff = value;
}
#pragma endregion


#pragma region Direct parameters
/// <summary>Sets the corner frequency of the low pass filter for the room effect</summary>
/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
/// <remarks>
///		All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates.
///		For example, setting ReflectionsDelay to 300ms gives a true 300ms delay when the reverb is hosted in a 48kHz voice,
///		but becomes a 150ms delay when hosted in a 24kHz voice.
///	</remarks>
Single ReverbParameters::RoomFilterFrequency::get()
{
	return this->roomFilterFrequency;
}

/// <summary>Sets the corner frequency of the low pass filter for the room effect</summary>
/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
/// <remarks>
///		All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates.
///		For example, setting ReflectionsDelay to 300ms gives a true 300ms delay when the reverb is hosted in a 48kHz voice,
///		but becomes a 150ms delay when hosted in a 24kHz voice.
///	</remarks>
void ReverbParameters::RoomFilterFrequency::set(Single value)
{
	this->roomFilterFrequency = value;
}
						
/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
Single ReverbParameters::RoomFilterMain::get()
{
	return this->roomFilterMain;
}
						
/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
void ReverbParameters::RoomFilterMain::set(Single value)
{
	this->roomFilterMain = value;
}
						
/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="RoomFilterFrequency" />). </summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
Single ReverbParameters::RoomFilterHighFrequency::get()
{
	return this->roomFilterMain;
}
						
/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="RoomFilterFrequency" />). </summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
void ReverbParameters::RoomFilterHighFrequency::set(Single value)
{
	this->roomFilterMain = value;
}
						
/// <summary>Adjusts the intensity of the early reflections</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
Single ReverbParameters::ReflectionsGain::get()
{
	return this->reflectionsGain;
}
						
/// <summary>Adjusts the intensity of the early reflections</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
void ReverbParameters::ReflectionsGain::set(Single value)
{
	this->reflectionsGain = value;
}
						
/// <summary>Adjusts the intensity of the reverberations</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
Single ReverbParameters::ReverbGain::get()
{
	return this->reverbGain;
}
						
/// <summary>Adjusts the intensity of the reverberations</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
void ReverbParameters::ReverbGain::set(Single value)
{
	this->reverbGain = value;
}
						
/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
/// <value>Clamped from 0.1 to infinity, in seconds</value>
Single ReverbParameters::DecayTime::get()
{
	return this->decayTime;
}
						
/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
/// <value>Clamped from 0.1 to infinity, in seconds</value>
void ReverbParameters::DecayTime::set(Single value)
{
	this->decayTime = value;
}
						
/// <summary>Controls the modal density in the late field reverberation</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
/// <remarks>
///		For colorless spaces, Density should be set to the maximum value (100).
///		As Density is decreased, the sound becomes hollow (comb filtered).
///		This is an effect that can be useful if you are trying to model a silo.
///	</remarks>
Single ReverbParameters::Density::get()
{
	return this->density;
}
						
/// <summary>Controls the modal density in the late field reverberation</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
/// <remarks>
///		For colorless spaces, Density should be set to the maximum value (100).
///		As Density is decreased, the sound becomes hollow (comb filtered).
///		This is an effect that can be useful if you are trying to model a silo.
///	</remarks>
void ReverbParameters::Density::set(Single value)
{
	this->density = value;
}
						
/// <summary>The apparent size of the acoustic space</summary>
/// <value>Clamped from 1 to 100, in feet</value>
Single ReverbParameters::RoomSize::get()
{
	return this->roomSize;
}
						
/// <summary>The apparent size of the acoustic space</summary>
/// <value>Clamped from 1 to 100, in feet</value>
void ReverbParameters::RoomSize::set(Single value)
{
	this->roomSize = value;
}
#pragma endregion


#pragma region Effect Parameter Base properties
/// <summary>Native pointer to the effect parameters</summary>
XAUDIO2FX_REVERB_PARAMETERS* ReverbParameters::UnmanagedPointer::get()
{
	return static_cast<XAUDIO2FX_REVERB_PARAMETERS*>(this->unmanagedStruct.ToPointer());
}

/// <summary>Native pointer to the effect parameters</summary>
void ReverbParameters::UnmanagedPointer::set(XAUDIO2FX_REVERB_PARAMETERS* value)
{
	this->unmanagedStruct = IntPtr(value);
}

/// <summary>Returns the internal pointer</summary>
void* ReverbParameters::DataPointer::get()
{
	return static_cast<void*>(this->unmanagedStruct.ToPointer());
}

/// <summary>Returns the internal pointer</summary>
void ReverbParameters::DataPointer::set(void* value)
{
	this->unmanagedStruct = IntPtr(value);
}

/// <summary>Returns the unmanaged size</summary>
UInt32 ReverbParameters::UnmanagedSize::get()
{
	return this->UnmanagedSize;
}

/// <summary>Returns the unmanaged size</summary>
void ReverbParameters::UnmanagedSize::set(UInt32 value)
{
	this->UnmanagedSize = value;
}
#pragma endregion
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
ReverbParameters::ReverbParameters()
{
	this->DefineReverbParameters
		(
			XAUDIO2FX_REVERB_DEFAULT_WET_DRY_MIX,
			XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_DELAY,
			XAUDIO2FX_REVERB_DEFAULT_REVERB_DELAY,
			XAUDIO2FX_REVERB_DEFAULT_REAR_DELAY,
			XAUDIO2FX_REVERB_DEFAULT_POSITION,
			XAUDIO2FX_REVERB_DEFAULT_POSITION,
			XAUDIO2FX_REVERB_DEFAULT_POSITION_MATRIX,
			XAUDIO2FX_REVERB_DEFAULT_POSITION_MATRIX,
			XAUDIO2FX_REVERB_DEFAULT_EARLY_DIFFUSION,
			XAUDIO2FX_REVERB_DEFAULT_LATE_DIFFUSION,
			XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_GAIN,
			XAUDIO2FX_REVERB_DEFAULT_LOW_EQ_CUTOFF,
			XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_GAIN,
			XAUDIO2FX_REVERB_DEFAULT_HIGH_EQ_CUTOFF,
			XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_FREQ,
			XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_MAIN,
			XAUDIO2FX_REVERB_DEFAULT_ROOM_FILTER_HF,
			XAUDIO2FX_REVERB_DEFAULT_REFLECTIONS_GAIN,
			XAUDIO2FX_REVERB_DEFAULT_REVERB_GAIN,
			XAUDIO2FX_REVERB_DEFAULT_DECAY_TIME,
			XAUDIO2FX_REVERB_DEFAULT_DENSITY,
			XAUDIO2FX_REVERB_DEFAULT_ROOM_SIZE
		);
}

/// <summary>Definition constructor</summary>
/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
/// <param name="rearDelay">Delay for the left rear output and right rear output</param>
/// <param name="positionLeft">Position of the left input within the simulated space relative to the listener</param>
/// <param name="positionRight">Position of the right input within the simulated space relative to the listener</param>
/// <param name="positionMatrixLeft">Gives a greater or lesser impression of distance from the source to the listener</param>
/// <param name="positionMatrixRight">Gives a greater or lesser impression of distance from the source to the listener</param>
/// <param name="earlyDiffusion">Controls the character of the individual wall reflections</param>
/// <param name="lateDiffusion">Controls the character of the individual wall reverberations</param>
/// <param name="lowEQgain">Adjusts the decay time of low frequencies relative to the decay time at 1 kHz</param>
/// <param name="lowEQcutoff">Sets the corner frequency of the low pass filter that is controlled by the lowEQgain parameter</param>
/// <param name="highEQgain">Adjusts the decay time of high frequencies relative to the decay time at 1 kHz</param>
/// <param name="highEQcutoff">Sets the corner frequency of the high pass filter that is controlled by the highEQgain parameter</param>
/// <param name="roomFilterFrequency">Sets the corner frequency of the low pass filter for the room effect</param>
/// <param name="roomFilterMain">Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</param>
/// <param name="roomFilterHighFrequency">Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency.</param>
/// <param name="reflectionsGain">Adjusts the intensity of the early reflections</param>
/// <param name="reverbGain">Adjusts the intensity of the reverberations</param>
/// <param name="decayTime">Reverberation decay time at 1 kHz. </param>
/// <param name="density">Controls the modal density in the late field reverberation</param>
/// <param name="roomSize">The apparent size of the acoustic space</param>
ReverbParameters::ReverbParameters(
	Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
	Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
	Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
	Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain, Single reverbGain,
	Single decayTime, Single density, Single roomSize)
{
	this->DefineReverbParameters
		( wetDry, reflectionsDelay, reverbDelay, rearDelay, positionLeft, positionRight, positionMatrixLeft, positionMatrixRight,
			earlyDiffusion, lateDiffusion, lowEQgain, lowEQcutoff, highEQgain, highEQcutoff,
			roomFilterFrequency, roomFilterMain, roomFilterHighFrequency, reflectionsGain, reverbGain,
			decayTime, density, roomSize
		);
}

/// <summary>Unmanaged copy constructor</summary>
/// <param name="unmanaged">Unmanaged instance to copy from</param>
ReverbParameters::ReverbParameters(XAUDIO2FX_REVERB_PARAMETERS* unmanaged)
{
	throw gcnew NotImplementedException("I need to think about this.");
}

/// <summary>Definition method</summary>
/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
/// <param name="rearDelay">Delay for the left rear output and right rear output</param>
/// <param name="positionLeft">Position of the left input within the simulated space relative to the listener</param>
/// <param name="positionRight">Position of the right input within the simulated space relative to the listener</param>
/// <param name="positionMatrixLeft">Gives a greater or lesser impression of distance from the source to the listener</param>
/// <param name="positionMatrixRight">Gives a greater or lesser impression of distance from the source to the listener</param>
/// <param name="earlyDiffusion">Controls the character of the individual wall reflections</param>
/// <param name="lateDiffusion">Controls the character of the individual wall reverberations</param>
/// <param name="lowEQgain">Adjusts the decay time of low frequencies relative to the decay time at 1 kHz</param>
/// <param name="lowEQcutoff">Sets the corner frequency of the low pass filter that is controlled by the lowEQgain parameter</param>
/// <param name="highEQgain">Adjusts the decay time of high frequencies relative to the decay time at 1 kHz</param>
/// <param name="highEQcutoff">Sets the corner frequency of the high pass filter that is controlled by the highEQgain parameter</param>
/// <param name="roomFilterFrequency">Sets the corner frequency of the low pass filter for the room effect</param>
/// <param name="roomFilterMain">Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</param>
/// <param name="roomFilterHighFrequency">Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency.</param>
/// <param name="reflectionsGain">Adjusts the intensity of the early reflections</param>
/// <param name="reverbGain">Adjusts the intensity of the reverberations</param>
/// <param name="decayTime">Reverberation decay time at 1 kHz. </param>
/// <param name="density">Controls the modal density in the late field reverberation</param>
/// <param name="roomSize">The apparent size of the acoustic space</param>
void ReverbParameters::DefineReverbParameters(Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain, Single reverbGain,
Single decayTime, Single density, Single roomSize)
{
	throw gcnew NotImplementedException("I need to think about this.");
}
#pragma endregion



#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
ReverbParameters::~ReverbParameters()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
ReverbParameters::!ReverbParameters()
{
	this->DisposeUnmanaged();
}

/// <summary>Destructor logic, disposes the object</summary>
void ReverbParameters::DisposeUnmanaged()
{
	if (this->unmanagedStruct != IntPtr::Zero)
	{
		XAUDIO2FX_REVERB_PARAMETERS* pointer = this->UnmanagedPointer;
		ReverbParameters::ReleaseMemory(&pointer);
		this->unmanagedStruct = IntPtr::Zero;
	}
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2FX_REVERB_PARAMETERS struct</returns>
XAUDIO2FX_REVERB_PARAMETERS ReverbParameters::ToUnmanaged()
{
	throw gcnew NotImplementedException("I need to think about this.");
}


/// <summary>Releases up native memory allocated for an unmanaged XAUDIO2FX_REVERB_PARAMETERS</summary>
/// <param name="reverb">The structure to release memory for</param>
void ReverbParameters::ReleaseMemory(XAUDIO2FX_REVERB_PARAMETERS** reverb)
{
	if (reverb != NULL && (*reverb) != NULL)
	{
		delete (*reverb);
		reverb = NULL;
	}
}


/// <summary>Generates a managed copy of an unmanaged parameter struct</summary>
/// <param name="source">Source pointer to the unmanaged parameter struct</param>
/// <param name="size">Size of data located at the source pointer</param>
/// <returns>A Reference to the Managed copy</returns>
ReverbParameters^ ReverbParameters::GenerateFromUnmanaged(void* source, UInt32 size)
{
	ReverbParameters^ levels = nullptr;

	if (source != NULL)
		levels = gcnew ReverbParameters(reinterpret_cast<XAUDIO2FX_REVERB_PARAMETERS*>(source));

	return levels;
}
#pragma endregion

