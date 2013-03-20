

#include "Reverb Parameters I3DL2.h"


using namespace Bardez::Projects::DirectX::XAudio2::FX;


#pragma region Properties
/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
Single ReverbParametersI3DL2::WetDryMix::get()
{
	return this->wetDryMix;
}

/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
/// <value>Clamped from 0 to 100, indicating a percentage</value>
void ReverbParametersI3DL2::WetDryMix::set(Single value)
{
	this->wetDryMix = value;
}

/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
Int32 ReverbParametersI3DL2::Room::get()
{
	return this->room;
}

/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
void ReverbParametersI3DL2::Room::set(Int32 value)
{
	this->room = value;
}

/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
Int32 ReverbParametersI3DL2::RoomHF::get()
{
	return this->roomHF;
}

/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
void ReverbParametersI3DL2::RoomHF::set(Int32 value)
{
	this->roomHF = value;
}

/// <value>Clamped from 0.0 to 10.0</value>
Single ReverbParametersI3DL2::RoomRolloffFactor::get()
{
	return this->roomRolloffFactor;
}

/// <value>Clamped from 0.0 to 10.0</value>
void ReverbParametersI3DL2::RoomRolloffFactor::set(Single value)
{
	this->roomRolloffFactor = value;
}

/// <value>Clamped from 0.1 to 20.0, in seconds</value>
Single ReverbParametersI3DL2::DecayTime::get()
{
	return this->decayTime;
}

/// <value>Clamped from 0.1 to 20.0, in seconds</value>
void ReverbParametersI3DL2::DecayTime::set(Single value)
{
	this->decayTime = value;
}

/// <value>Clamped from 0.1 to 2.0</value>
Single ReverbParametersI3DL2::DecayHFRatio::get()
{
	return this->decayHFRatio;
}

/// <value>Clamped from 0.1 to 2.0</value>
void ReverbParametersI3DL2::DecayHFRatio::set(Single value)
{
	this->decayHFRatio = value;
}

/// <value>Clamped from -10000 to 1000, in mB (hundredths of decibels)</value>
Int32 ReverbParametersI3DL2::Reflections::get()
{
	return this->reflections;
}

/// <value>Clamped from -10000 to 1000, in mB (hundredths of decibels)</value>
void ReverbParametersI3DL2::Reflections::set(Int32 value)
{
	this->reflections = value;
}

/// <value>Clamped from 0.0 to 0.3, in seconds</value>
Single ReverbParametersI3DL2::ReflectionsDelay::get()
{
	return this->reflectionsDelay;
}

/// <value>Clamped from 0.0 to 0.3, in seconds</value>
void ReverbParametersI3DL2::ReflectionsDelay::set(Single value)
{
	this->reflectionsDelay = value;
}

/// <value>Clamped from -10000 to 2000, in mB (hundredths of decibels)</value>
Int32 ReverbParametersI3DL2::Reverb::get()
{
	return this->reverb;
}

/// <value>Clamped from -10000 to 2000, in mB (hundredths of decibels)</value>
void ReverbParametersI3DL2::Reverb::set(Int32 value)
{
	this->reverb = value;
}

/// <value>Clamped from 0.0 to 0.1, in seconds</value>
Single ReverbParametersI3DL2::ReverbDelay::get()
{
	return this->reverbDelay;
}

/// <value>Clamped from 0.0 to 0.1, in seconds</value>
void ReverbParametersI3DL2::ReverbDelay::set(Single value)
{
	this->reverbDelay = value;
}

/// <value>Clamped from 0 to 100, indicating a percentage</value>
Single ReverbParametersI3DL2::Diffusion::get()
{
	return this->diffusion;
}

/// <value>Clamped from 0 to 100, indicating a percentage</value>
void ReverbParametersI3DL2::Diffusion::set(Single value)
{
	this->diffusion = value;
}

/// <value>Clamped from 0 to 100, indicating a percentage</value>
Single ReverbParametersI3DL2::Density::get()
{
	return this->density;
}

/// <value>Clamped from 0 to 100, indicating a percentage</value>
void ReverbParametersI3DL2::Density::set(Single value)
{
	this->density = value;
}

/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
Single ReverbParametersI3DL2::HFReference::get()
{
	return this->hfReference;
}

/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
void ReverbParametersI3DL2::HFReference::set(Single value)
{
	this->hfReference = value;
}
#pragma endregion


#pragma region Construction
/// <summary>Default constructor</summary>
/// <remarks>See http://www.iasig.org/pubs/3dl2v1a.pdf for the I3DL2 spec</remarks>
ReverbParametersI3DL2::ReverbParametersI3DL2()
{
	//uses the defaults specified on page 15 of the referenced spec
	this->DefineReverb(100.0f, -10000, 0, 0.0f, 1.0f, 0.5f, -10000, 0.02f, -10000, 0.04f, 100.0f, 100.0f, 5000.0f);
}

/// <summary>Definition constructor</summary>
/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
/// <param name="room">Intensity level and low-pass filter for the room effect</param>
/// <param name="roomHF">Attenuation at high frequencies relative to the intensity at low frequencies</param>
/// <param name="roomRolloff">Rolloff of room effect intensity vs. distance</param>
/// <param name="decayTime">Reverberation decay time at low frequencies</param>
/// <param name="decayRatio">Ratio of high-frequency decay time relative to low-frequency decay time</param>
/// <param name="reflections">Adjusts intensity level of early reflections (relative to Room value)</param>
/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
/// <param name="reverb">Adjusts intensity of late reverberation (relative to Room value)</param>
/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
/// <param name="diffusion">Controls the echo density in the late reverberation decay</param>
/// <param name="density">Controls the modal density in the late reverberation decay</param>
/// <param name="hfRef">Reference high frequency</param>
/// <remarks>See http://www.iasig.org/pubs/3dl2v1a.pdf for the I3DL2 spec</remarks>
ReverbParametersI3DL2::ReverbParametersI3DL2(Single wetDry, Int32 room, Int32 roomHF, Single roomRolloff, Single decayTime, Single decayRatio, Int32 reflections, Single reflectionsDelay, Int32 reverb, Single reverbDelay, Single diffusion, Single density, Single hfRef)
{
	this->DefineReverb(wetDry, room, roomHF, roomRolloff, decayTime, decayRatio, reflections, reflectionsDelay, reverb, reverbDelay, diffusion, density, hfRef);
}

/// <summary>Definition constructor</summary>
/// <param name="managed">Managed XAUDIO2FX_REVERB_I3DL2_PARAMETERS struct to copy from</param>
ReverbParametersI3DL2::ReverbParametersI3DL2(XAUDIO2FX_REVERB_I3DL2_PARAMETERS managed)
{
	this->DefineReverb(managed.WetDryMix, managed.Room, managed.RoomHF, managed.RoomRolloffFactor, managed.DecayTime, managed.DecayHFRatio, managed.Reflections, managed.ReflectionsDelay, managed.Reverb, managed.ReverbDelay, managed.Diffusion, managed.Density, managed.HFReference);
}

/// <summary>Definition method</summary>
/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
/// <param name="room">Intensity level and low-pass filter for the room effect</param>
/// <param name="roomHF">Attenuation at high frequencies relative to the intensity at low frequencies</param>
/// <param name="roomRolloff">Rolloff of room effect intensity vs. distance</param>
/// <param name="decayTime">Reverberation decay time at low frequencies</param>
/// <param name="decayRatio">Ratio of high-frequency decay time relative to low-frequency decay time</param>
/// <param name="reflections">Adjusts intensity level of early reflections (relative to Room value)</param>
/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
/// <param name="reverb">Adjusts intensity of late reverberation (relative to Room value)</param>
/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
/// <param name="diffusion">Controls the echo density in the late reverberation decay</param>
/// <param name="density">Controls the modal density in the late reverberation decay</param>
/// <param name="hfRef">Reference high frequency</param>
void ReverbParametersI3DL2::DefineReverb(Single wetDry, Int32 room, Int32 roomHF, Single roomRolloff, Single decayTime, Single decayRatio, Int32 reflections, Single reflectionsDelay, Int32 reverb, Single reverbDelay, Single diffusion, Single density, Single hfRef)
{
	this->wetDryMix = wetDry;
	this->room = room;
	this->roomHF = roomHF;
	this->roomRolloffFactor = roomRolloff;
	this->decayTime = decayTime;
	this->reflections = reflections;
	this->reflectionsDelay = reflectionsDelay;
	this->reverb = reverb;
	this->reverbDelay = reverbDelay;
	this->diffusion = diffusion;
	this->density = density;
	this->hfReference = hfRef;
}
#pragma endregion

