
#include "Voice Details.h"


using namespace Bardez::Projects::DirectX::XAudio2;


/****************************
*	Property Definitions	*
****************************/
/// <summary>Flags to create voice, abstracted values by voice type</summary>
System::UInt32 Bardez::Projects::DirectX::XAudio2::VoiceDetails::CreationFlags::get()
{
	return this->creationFlags;
}

/// <summary>Flags to create voice, abstracted values by voice type</summary>
/// <param name="value">Value to set</param>
void Bardez::Projects::DirectX::XAudio2::VoiceDetails::CreationFlags::set(System::UInt32 value)
{
	 this->creationFlags = value;
}

/// <summary>Number of expected input channels</summary>
System::UInt32 Bardez::Projects::DirectX::XAudio2::VoiceDetails::InputChannels::get()
{
	return this->inputChannels;
}

/// <summary>Number of expected input channels</summary>
/// <param name="value">Value to set</param>
void Bardez::Projects::DirectX::XAudio2::VoiceDetails::InputChannels::set(System::UInt32 value)
{
	this->inputChannels = value;
}

/// <summary>Expected input sample sample rate</summary>
System::UInt32 Bardez::Projects::DirectX::XAudio2::VoiceDetails::InputSampleRate::get()
{
	return this->inputSampleRate;
}

/// <summary>Expected input sample sample rate</summary>
/// <param name="value">Value to set</param>
void Bardez::Projects::DirectX::XAudio2::VoiceDetails::InputSampleRate::set(System::UInt32 value)
{
	this->inputSampleRate = value;
}


/********************
*	Construction	*
********************/
/// <summary>Definition constructor</summary>
/// <param name="flagsCreation">Creation flags</param>
/// <param name="channels">Number of input channels</param>
/// <param name="rate">Input sample rate</param>
Bardez::Projects::DirectX::XAudio2::VoiceDetails::VoiceDetails(System::UInt32 flagsCreation, /*System::UInt32 flagsActive,*/ System::UInt32 channels, System::UInt32 rate)
{
	this->creationFlags = flagsCreation;
	//this->activeFlags = flagsActive;
	this->inputChannels = channels;
	this->inputSampleRate = rate;
}

/// <summary>Unmanaged constructor</summary>
/// <param name="details">Unmanaged XAUDIO2_VOICE_DETAILS struct</param>
Bardez::Projects::DirectX::XAudio2::VoiceDetails::VoiceDetails(XAUDIO2_VOICE_DETAILS details)
{
	this->creationFlags = details.CreationFlags;
	//this->activeFlags = details.ActiveFlags;
	this->inputChannels = details.InputChannels;
	this->inputSampleRate = details.InputSampleRate;
}


/************
*	Methods	*
************/
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_VOICE_DETAILS struct</returns>
XAUDIO2_VOICE_DETAILS Bardez::Projects::DirectX::XAudio2::VoiceDetails::ToUnmanaged()
{
	XAUDIO2_VOICE_DETAILS details;
	
	details.CreationFlags = this->creationFlags;
	//details.ActiveFlags = this->activeFlags;
	details.InputChannels = this->inputChannels;
	details.InputSampleRate = this->inputSampleRate;

	return details;
}


#pragma region Misdefined struct code
/*
//
//
//
// <param name="flagsActive">Active flags</param>
//
// <summary>Flags currently set on voice</summary>
//System::UInt32 Bardez::Projects::DirectX::XAudio2::VoiceDetails::ActiveFlags::get()
//{
//	return this->activeFlags;
//}
//
// <summary>Flags currently set on voice</summary>
//void Bardez::Projects::DirectX::XAudio2::VoiceDetails::ActiveFlags::set(System::UInt32 value)
//{
//	this->activeFlags = value;
//}

// <summary>Flags currently set on voice</summary>
System::UInt32 activeFlags;

// <summary>Flags currently set on voice</summary>
property System::UInt32 ActiveFlags
{
	System::UInt32 get();
	void set(System::UInt32 value);
}
*/
#pragma endregion