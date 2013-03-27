

#include "Environmental Reverb Parameters.h"


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace Bardez::Projects::DirectX::XAudio2::FX;


#pragma region Constants
/// <summary>Constant for default preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Default::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_DEFAULT;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}
						
/// <summary>Constant for generic preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Generic::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_GENERIC;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}
						
/// <summary>Constant for padded cell preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::PaddedCell::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_PADDEDCELL;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

						
/// <summary>Constant for a generic "room" preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::GenericRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_ROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for bathroom preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::BathRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_BATHROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for living room preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::LivingRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_LIVINGROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for stone room preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::StoneRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_STONEROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for auditorium preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Auditorum::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_AUDITORIUM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for concert hall preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::ConcertHall::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_CONCERTHALL;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for cave preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Cave::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_CAVE;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for arena preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Arena::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_ARENA;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for hangar preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Hangar::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_HANGAR;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for carpeted hallway preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::CarpetedHallway::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_CARPETEDHALLWAY;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for hallway preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Hallway::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_HALLWAY;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for stone corridor preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::StoneCorridor::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_STONECORRIDOR;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for alley preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Alley::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_ALLEY;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for forest preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Forest::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_FOREST;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for city preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::City::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_CITY;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for mountains preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Mountains::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_MOUNTAINS;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for quarry preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Quarry::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_QUARRY;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for plain preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Plain::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_PLAIN;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for parking lot preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::ParkingLot::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_PARKINGLOT;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for sewer pipe preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::SewerPipe::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_SEWERPIPE;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for underwater preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Underwater::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_UNDERWATER;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for small room preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::SmallRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_SMALLROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for medium room preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::MediumRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_MEDIUMROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for large room preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::LargeRoom::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_LARGEROOM;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for medium hall preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::MediumHall::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_MEDIUMHALL;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for large hall preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::LargeHall::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_LARGEHALL;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}

/// <summary>Constant for plate preset</summary>
EnvironmentalReverbParameters^ EnvironmentalReverbParameters::Plate::get()
{
	XAUDIO2FX_REVERB_PARAMETERS unmanaged;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS preset = XAUDIO2FX_I3DL2_PRESET_PLATE;
	XAUDIO2FX_REVERB_I3DL2_PARAMETERS* presetPointer = &preset;
	ReverbConvertI3DL2ToNative(presetPointer, &unmanaged);
	return gcnew EnvironmentalReverbParameters(&unmanaged);
}
#pragma endregion



#pragma region Properties
/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
Single EnvironmentalReverbParameters::WetDryMix::get()
{
	return this->wetDryMix;
}

/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
void EnvironmentalReverbParameters::WetDryMix::set(Single value)
{
	this->wetDryMix = value;
}
						
#pragma region Delay Times
/// <summary>The delay time of the first reflection relative to the direct path</summary>
/// <value>Clamped from 0 to 300, in miliseconds</value>
UInt32 EnvironmentalReverbParameters::ReflectionsDelay::get()
{
	return this->reflectionsDelay;
}
						
/// <summary>The delay time of the first reflection relative to the direct path</summary>
/// <value>Clamped from 0 to 300, in miliseconds</value>
void EnvironmentalReverbParameters::ReflectionsDelay::set(UInt32 value)
{
	this->reflectionsDelay = value;
}

/// <summary>Delay of reverb relative to the first reflection</summary>
/// <value>Clamped from 0 to 85, in miliseconds</value>
Byte EnvironmentalReverbParameters::ReverbDelay::get()
{
	return this->reverbDelay;
}

/// <summary>Delay of reverb relative to the first reflection</summary>
/// <value>Clamped from 0 to 85, in miliseconds</value>
void EnvironmentalReverbParameters::ReverbDelay::set(Byte value)
{
	this->reverbDelay = value;
}
						
/// <summary>Delay for the left rear output and right rear output</summary>
/// <value>Clamped from 0 to 5, in miliseconds</value>
Byte EnvironmentalReverbParameters::RearDelay::get()
{
	return this->rearDelay;
}
						
/// <summary>Delay for the left rear output and right rear output</summary>
/// <value>Clamped from 0 to 5, in miliseconds</value>
void EnvironmentalReverbParameters::RearDelay::set(Byte value)
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
Byte EnvironmentalReverbParameters::PositionLeft::get()
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
void EnvironmentalReverbParameters::PositionLeft::set(Byte value)
{
	this->positionLeft = value;
}
						
/// <summary>Position of the right input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
/// <remarks>Same as <see cref="PositionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
Byte EnvironmentalReverbParameters::PositionRight::get()
{
	return this->positionRight;
}
						
/// <summary>Position of the right input within the simulated space relative to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
/// <remarks>Same as <see cref="PositionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
void EnvironmentalReverbParameters::PositionRight::set(Byte value)
{
	this->positionRight = value;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
Byte EnvironmentalReverbParameters::PositionMatrixLeft::get()
{
	return this->positionMatrixLeft;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units</value>
void EnvironmentalReverbParameters::PositionMatrixLeft::set(Byte value)
{
	this->positionMatrixLeft = value;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
Byte EnvironmentalReverbParameters::PositionMatrixRight::get()
{
	return this->positionMatrixRight;
}
						
/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
void EnvironmentalReverbParameters::PositionMatrixRight::set(Byte value)
{
	this->positionMatrixRight = value;
}
						
/// <summary>Controls the character of the individual wall reflections</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
Byte EnvironmentalReverbParameters::EarlyDiffusion::get()
{
	return this->earlyDiffusion;
}
						
/// <summary>Controls the character of the individual wall reflections</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
void EnvironmentalReverbParameters::EarlyDiffusion::set(Byte value)
{
	this->earlyDiffusion = value;
}
						
/// <summary>Controls the character of the individual wall reverberations</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
Byte EnvironmentalReverbParameters::LateDiffusion::get()
{
	return this->lateDiffusion;
}
						
/// <summary>Controls the character of the individual wall reverberations</summary>
/// <value>Clamped from 0 to 15, no units</value>
/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
void EnvironmentalReverbParameters::LateDiffusion::set(Byte value)
{
	this->lateDiffusion = value;
}
						
/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
/// <value>Clamped from 0 to 12, no units</value>
/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
Byte EnvironmentalReverbParameters::LowEQGain::get()
{
	return this->lowEQGain;
}
						
/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
/// <value>Clamped from 0 to 12, no units</value>
/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
void EnvironmentalReverbParameters::LowEQGain::set(Byte value)
{
	this->lowEQGain = value;
}
						
/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
/// <value>Clamped from 0 to 9, no units</value>
Byte EnvironmentalReverbParameters::LowEQCutoff::get()
{
	return this->lowEQCutoff;
}
						
/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
/// <value>Clamped from 0 to 9, no units</value>
void EnvironmentalReverbParameters::LowEQCutoff::set(Byte value)
{
	this->lowEQCutoff = value;
}
						
/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
/// <value>Clamped from 0 to 8, no units</value>
/// <remarks>A value of 8 yields no effective change</remarks>
Byte EnvironmentalReverbParameters::HighEQGain::get()
{
	return this->highEQGain;
}
						
/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
/// <value>Clamped from 0 to 8, no units</value>
/// <remarks>A value of 8 yields no effective change</remarks>
void EnvironmentalReverbParameters::HighEQGain::set(Byte value)
{
	this->highEQGain = value;
}
						
/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="HighEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
/// <value>Clamped from 0 to 14, no units</value>
Byte EnvironmentalReverbParameters::HighEQCutoff::get()
{
	return this->highEQCutoff;
}
						
/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="HighEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
/// <value>Clamped from 0 to 14, no units</value>
void EnvironmentalReverbParameters::HighEQCutoff::set(Byte value)
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
Single EnvironmentalReverbParameters::RoomFilterFrequency::get()
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
void EnvironmentalReverbParameters::RoomFilterFrequency::set(Single value)
{
	this->roomFilterFrequency = value;
}
						
/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
Single EnvironmentalReverbParameters::RoomFilterMain::get()
{
	return this->roomFilterMain;
}
						
/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
void EnvironmentalReverbParameters::RoomFilterMain::set(Single value)
{
	this->roomFilterMain = value;
}
						
/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="RoomFilterFrequency" />). </summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
Single EnvironmentalReverbParameters::RoomFilterHighFrequency::get()
{
	return this->roomFilterMain;
}
						
/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="RoomFilterFrequency" />). </summary>
/// <value>Clamped from -100 to 0, in dB (decibels)</value>
void EnvironmentalReverbParameters::RoomFilterHighFrequency::set(Single value)
{
	this->roomFilterMain = value;
}
						
/// <summary>Adjusts the intensity of the early reflections</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
Single EnvironmentalReverbParameters::ReflectionsGain::get()
{
	return this->reflectionsGain;
}
						
/// <summary>Adjusts the intensity of the early reflections</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
void EnvironmentalReverbParameters::ReflectionsGain::set(Single value)
{
	this->reflectionsGain = value;
}
						
/// <summary>Adjusts the intensity of the reverberations</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
Single EnvironmentalReverbParameters::ReverbGain::get()
{
	return this->reverbGain;
}
						
/// <summary>Adjusts the intensity of the reverberations</summary>
/// <value>Clamped from -100 to 20, in dB (decibels)</value>
void EnvironmentalReverbParameters::ReverbGain::set(Single value)
{
	this->reverbGain = value;
}
						
/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
/// <value>Clamped from 0.1 to infinity, in seconds</value>
Single EnvironmentalReverbParameters::DecayTime::get()
{
	return this->decayTime;
}
						
/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
/// <value>Clamped from 0.1 to infinity, in seconds</value>
void EnvironmentalReverbParameters::DecayTime::set(Single value)
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
Single EnvironmentalReverbParameters::Density::get()
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
void EnvironmentalReverbParameters::Density::set(Single value)
{
	this->density = value;
}
						
/// <summary>The apparent size of the acoustic space</summary>
/// <value>Clamped from 1 to 100, in feet</value>
Single EnvironmentalReverbParameters::RoomSize::get()
{
	return this->roomSize;
}
						
/// <summary>The apparent size of the acoustic space</summary>
/// <value>Clamped from 1 to 100, in feet</value>
void EnvironmentalReverbParameters::RoomSize::set(Single value)
{
	this->roomSize = value;
}
#pragma endregion
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
EnvironmentalReverbParameters::EnvironmentalReverbParameters()
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
EnvironmentalReverbParameters::EnvironmentalReverbParameters(
	Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
	Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
	Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
	Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain, Single reverbGain,
	Single decayTime, Single density, Single roomSize)
{
	this->DefineReverbParameters
		(	wetDry, reflectionsDelay, reverbDelay, rearDelay, positionLeft, positionRight, positionMatrixLeft, positionMatrixRight,
			earlyDiffusion, lateDiffusion, lowEQgain, lowEQcutoff, highEQgain, highEQcutoff,
			roomFilterFrequency, roomFilterMain, roomFilterHighFrequency, reflectionsGain, reverbGain,
			decayTime, density, roomSize
		);
}

/// <summary>Unmanaged copy constructor</summary>
/// <param name="unmanaged">Unmanaged instance to copy from</param>
EnvironmentalReverbParameters::EnvironmentalReverbParameters(const XAUDIO2FX_REVERB_PARAMETERS* unmanaged)
{
	this->DefineFromUnmanaged(unmanaged);
}
						
/// <summary>Unmanaged copy method</summary>
/// <param name="unmanaged">Unmanaged instance to copy from</param>
void EnvironmentalReverbParameters::DefineFromUnmanaged(const XAUDIO2FX_REVERB_PARAMETERS* unmanaged)
{
	this->DefineReverbParameters
		(	unmanaged->WetDryMix, unmanaged->ReflectionsDelay, unmanaged->ReverbDelay, unmanaged->RearDelay,
			unmanaged->PositionLeft, unmanaged->PositionRight, unmanaged->PositionMatrixLeft, unmanaged->PositionMatrixRight,
			unmanaged->EarlyDiffusion, unmanaged->LateDiffusion, unmanaged->LowEQGain, unmanaged->LowEQCutoff,
			unmanaged->HighEQGain, unmanaged->HighEQCutoff,
			unmanaged->RoomFilterFreq, unmanaged->RoomFilterMain, unmanaged->RoomFilterHF,
			unmanaged->ReflectionsGain, unmanaged->ReverbGain, unmanaged->DecayTime, unmanaged->Density, unmanaged->RoomSize
		);
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
void EnvironmentalReverbParameters::DefineReverbParameters(Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
	Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
	Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
	Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain,
	Single reverbGain, Single decayTime, Single density, Single roomSize)
{
	this->wetDryMix = wetDry;
	this->reflectionsDelay = reflectionsDelay;
	this->reverbDelay = reverbDelay;
	this->rearDelay = rearDelay;
	this->positionLeft = positionLeft;
	this->positionRight = positionRight;
	this->positionMatrixLeft = positionMatrixLeft;
	this->positionMatrixRight = positionMatrixRight;
	this->earlyDiffusion = earlyDiffusion;
	this->lateDiffusion = lateDiffusion;
	this->lowEQGain = lowEQgain;
	this->lowEQCutoff = lowEQcutoff;
	this->highEQGain = highEQgain;
	this->highEQCutoff = highEQcutoff;
	this->roomFilterFrequency = roomFilterFrequency;
	this->roomFilterMain = roomFilterMain;
	this->roomFilterHighFrequency = roomFilterHighFrequency;
	this->reflectionsGain = reflectionsGain;
	this->reverbGain = reverbGain;
	this->decayTime = decayTime;
	this->density = density;
	this->roomSize = roomSize;
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2FX_REVERB_PARAMETERS struct pointer</returns>
XAUDIO2FX_REVERB_PARAMETERS* EnvironmentalReverbParameters::ToUnmanaged()
{
	XAUDIO2FX_REVERB_PARAMETERS* reverb = new XAUDIO2FX_REVERB_PARAMETERS;

	reverb->WetDryMix = this->wetDryMix;
	reverb->ReflectionsDelay = this->reflectionsDelay;
	reverb->ReverbDelay = this->reverbDelay;
	reverb->RearDelay = this->rearDelay;
	reverb->PositionLeft = this->positionLeft;
	reverb->PositionRight = this->positionRight;
	reverb->PositionMatrixLeft = this->positionMatrixLeft;
	reverb->PositionMatrixRight = this->positionMatrixRight;
	reverb->EarlyDiffusion = this->earlyDiffusion;
	reverb->LateDiffusion = this->lateDiffusion;
	reverb->LowEQGain = this->lowEQGain;
	reverb->LowEQCutoff = this->lowEQCutoff;
	reverb->HighEQGain = this->highEQGain;
	reverb->HighEQCutoff = this->highEQCutoff;
	reverb->RoomFilterFreq = this->roomFilterFrequency;
	reverb->RoomFilterMain = this->roomFilterMain;
	reverb->RoomFilterHF = this->roomFilterHighFrequency;
	reverb->ReflectionsGain = this->reflectionsGain;
	reverb->ReverbGain = this->reverbGain;
	reverb->DecayTime = this->decayTime;
	reverb->Density = this->density;
	reverb->RoomSize = this->roomSize;

	return reverb;
}

/// <summary>Generates the unmanaged data required for this type</summary>
/// <param name="unmanaged">Output pointer to the unmanaged parameter struct</param>
/// <param name="size">Output pointer to the size of data located at the source pointer</param>
void EnvironmentalReverbParameters::ToUnmanaged(void*& unmanaged, UInt32& size)
{
	XAUDIO2FX_REVERB_PARAMETERS* reverb = this->ToUnmanaged();
	size = Marshal::SizeOf(XAUDIO2FX_REVERB_PARAMETERS::typeid);

	unmanaged = reinterpret_cast<void*>(reverb);
}


/// <summary>Releases up native memory allocated for an unmanaged XAUDIO2FX_REVERB_PARAMETERS</summary>
/// <param name="reverb">The structure to release memory for</param>
void EnvironmentalReverbParameters::ReleaseMemory(XAUDIO2FX_REVERB_PARAMETERS*& reverb)
{
	if (reverb != NULL)
	{
		delete reverb;	//delete the struct
		reverb = NULL;
	}
}

/// <summary>Releases up native memory allocated for an unmanaged parameters structure</summary>
/// <param name="data">The structure to release memory for</param>
void EnvironmentalReverbParameters::ReleaseMemory(void*& data)
{
	XAUDIO2FX_REVERB_PARAMETERS* pointer = reinterpret_cast<XAUDIO2FX_REVERB_PARAMETERS*>(data);
	EnvironmentalReverbParameters::ReleaseMemory(pointer);
	data = reinterpret_cast<void*>(pointer);
}

/// <summary>Repopulated the managed copy from an unmanaged parameter struct</summary>
/// <param name="source">Source pointer to the unmanaged parameter struct</param>
/// <param name="size">Size of data located at the source pointer</param>
/// <returns>A Reference to the Managed copy</returns>
void EnvironmentalReverbParameters::RepopulateFromUnmanaged(const void* source, UInt32 size)
{
	this->DefineFromUnmanaged(reinterpret_cast<const XAUDIO2FX_REVERB_PARAMETERS*>(source));
}
#pragma endregion

