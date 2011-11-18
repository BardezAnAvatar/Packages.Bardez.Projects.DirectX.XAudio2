#include "Effect Base.h"

using namespace Bardez::Projects::DirectX::XAudio2::XAPO;

#pragma region Properties
/// <summary>The parameters to this effect</summary>
EffectParameterBase^ EffectBase::Parameters::get()
{
	return this->parameters;
}

/// <summary>The parameters to this effect</summary>
void EffectBase::Parameters::set(EffectParameterBase^ value)
{
	this->parameters = value;
}

/// <summary>Pointer to the effect COM object/interface</summary>
System::IntPtr EffectBase::Effect::get()
{
	return this->effect;
}

/// <summary>Pointer to the effect COM object/interface</summary>
void EffectBase::Effect::set(System::IntPtr value)
{
	this->effect = value;
}

/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
IUnknown* EffectBase::UnmanagedEffect::get()
{
	return reinterpret_cast<IUnknown*>(this->effect.ToPointer());
}

/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
void EffectBase::UnmanagedEffect::set(IUnknown* value)
{
	this->effect = System::IntPtr(value);
}
#pragma endregion