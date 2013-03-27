
#include "Effect Descriptor.h"


using namespace Bardez::Projects::DirectX::XAudio2;
using namespace Bardez::Projects::DirectX::XAudio2::XAPO;


#pragma region Properties
/// <summary>Reference to the effect object</summary>
IEffectBase^ EffectDescriptor::Effect::get()
{
	return this->effect;
}

/// <summary>Reference to the effect object</summary>
void EffectDescriptor::Effect::set(IEffectBase^ value)
{
	this->effect = value;
}

/// <summary>Indicates whether or not to start the effect as enabled</summary>
System::Boolean EffectDescriptor::InitialState::get()
{
	return this->initialState;
}

/// <summary>Indicates whether or not to start the effect as enabled</summary>
void EffectDescriptor::InitialState::set(System::Boolean value)
{
	this->initialState = value;
}

/// <summary>Number of channels the effect should output</summary>
System::UInt32 EffectDescriptor::OutputChannels::get()
{
	return this->outputChannels;
}

/// <summary>Number of channels the effect should output</summary>
void EffectDescriptor::OutputChannels::set(System::UInt32 value)
{
	this->outputChannels = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="effectObject">Reference to an effect object</param>
/// <param name="enabled">Flag indicating whether the effect enabled initially</param>
/// <param name="channels">Output number of channels</param>
EffectDescriptor::EffectDescriptor(IEffectBase^ effectObject, System::Boolean enabled, System::UInt32 channels)
{
	this->effect = effectObject;
	this->initialState = enabled;
	this->outputChannels = channels;
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_FILTER_PARAMETERS struct</returns>
XAUDIO2_EFFECT_DESCRIPTOR EffectDescriptor::ToUnmanaged()
{
	XAUDIO2_EFFECT_DESCRIPTOR effect;

	//BOOL is defined separately as both a long and an int; since int can go to long but not vice versa, go with Int32
	effect.InitialState = System::Convert::ToInt32(this->initialState);

	effect.pEffect = this->Effect->UnmanagedPointer;
	effect.OutputChannels = this->outputChannels;

	return effect;
}
#pragma endregion

