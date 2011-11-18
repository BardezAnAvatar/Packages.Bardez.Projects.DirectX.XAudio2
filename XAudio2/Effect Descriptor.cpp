
#include "Effect Descriptor.h"

using namespace Bardez::Projects::DirectX::XAudio2;
using namespace Bardez::Projects::DirectX::XAudio2::XAPO;

#pragma region Properties
/// <summary>Reference to the effect object</summary>
EffectBase^ EffectDescriptor::Effect::get()
{
	return this->effect;
}

/// <summary>Reference to the effect object</summary>
void EffectDescriptor::Effect::set(EffectBase^ value)
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

/// <summary>Pointer to the effect COM object/interface</summary>
IUnknown* EffectDescriptor::UnmanagedEffect::get()
{
	return this->effect->UnmanagedEffect;
}

/// <summary>Pointer to the effect COM object/interface</summary>
void EffectDescriptor::UnmanagedEffect::set(IUnknown* value)
{
	this->effect->UnmanagedEffect = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="effectObject">Reference to an effect object</param>
/// <param name="enabled">Is the effect enabled?</param>
/// <param name="channels">Output number of channels</param>
EffectDescriptor::EffectDescriptor(EffectBase^ effectObject, System::Boolean enabled, System::UInt32 channels)
{
	this->effect = effectObject;
	this->initialState = enabled;
	this->outputChannels = channels;
}

///// <summary>Definition constructor</summary>
///// <param name="pointer">Pointer to the effect</param>
///// <param name="enabled">Is the effect enabled?</param>
///// <param name="channels">Output number of channels</param>
//EffectDescriptor::EffectDescriptor(IUnknown* pointer, System::Boolean enabled, System::UInt32 channels)
//{
//	this->effect = System::IntPtr(pointer);
//	this->initialState = enabled;
//	this->outputChannels = channels;
//}
//
///// <summary>Unmanaged constructor</summary>
///// <param name="params">Unmanaged parameters struct</param>
//EffectDescriptor::EffectDescriptor(XAUDIO2_EFFECT_DESCRIPTOR params)
//{
//	this->ptrEffect = System::IntPtr(params.pEffect);
//	this->initialState = System::Convert::ToBoolean(params.InitialState);
//	this->outputChannels = params.OutputChannels;
//}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_FILTER_PARAMETERS struct</returns>
XAUDIO2_EFFECT_DESCRIPTOR EffectDescriptor::ToUnmanaged()
{
	XAUDIO2_EFFECT_DESCRIPTOR effect;

	//BOOL is defined separately as both a long and an int; since int can go to long but not vice versa, go with Int32
	effect.InitialState = System::Convert::ToInt32(this->initialState);

	effect.pEffect = this->UnmanagedEffect;
	effect.OutputChannels = this->outputChannels;

	return effect;
}
#pragma endregion