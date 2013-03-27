

#include "Voice Send Descriptor.h"
#include "Voice.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Indicates whether filter should be used on data sent to the voice.</summary>
/// <value>Flags can be 0 or XAUDIO2_SEND_USEFILTER (0x0080)</value>
System::UInt32 VoiceSendDescriptor::Flags::get()
{
	return this->flags;
}

/// <summary>Indicates whether filter should be used on data sent to the voice.</summary>
/// <value>Flags can be 0 or XAUDIO2_SEND_USEFILTER (0x0080)</value>
void VoiceSendDescriptor::Flags::set(System::UInt32 value)
{
	this->flags = value;
}

/// <summary>Voice to be the target of the send. Cannot be null without error.</summary>
Voice^ VoiceSendDescriptor::OutputVoice::get()
{
	return this->outputVoice;
}

/// <summary>Voice to be the target of the send. Cannot be null without error.</summary>
void VoiceSendDescriptor::OutputVoice::set(Voice^ value)
{
	this->outputVoice = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="flag">Indicates whether filter should be used on data sent to the voice</param>
/// <param name="target">Voice to be the target of the send. Cannot be null without error</param>
VoiceSendDescriptor::VoiceSendDescriptor(System::UInt32 flag, Voice^ target)
{
	this->flags = flag;
	this->outputVoice = target;
}
#pragma endregion
				


#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_SEND_DESCRIPTOR struct</returns>
XAUDIO2_SEND_DESCRIPTOR VoiceSendDescriptor::ToUnmanaged()
{
	XAUDIO2_SEND_DESCRIPTOR send;

	send.Flags = this->flags;
	send.pOutputVoice = this->outputVoice->XAudio2Voice;

	return send;
}
#pragma endregion

