

#include "Environmental Reverb Effect.h"
#include "Environmental Reverb Parameters.h"


using namespace Bardez::Projects::BasicStructures::Win32;
using namespace Bardez::Projects::DirectX::XAudio2::FX;
using namespace Bardez::Projects::DirectX::XAudio2::XAPO;


#pragma region Properties
/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
IUnknown* EnvironmentalReverbEffect::UnmanagedPointer::get()
{
	return reinterpret_cast<IUnknown*>(this->nativeEffect.ToPointer());
}

/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
void EnvironmentalReverbEffect::UnmanagedPointer::set(IUnknown* value)
{
	this->nativeEffect = IntPtr(value);
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
EnvironmentalReverbEffect::EnvironmentalReverbEffect()
{
	this->CreateReverb(0U);
}

/// <summary>Definition constructor</summary>
/// <param name="flags">Flags used when constructing hte reverb. Must be 0.</param>
EnvironmentalReverbEffect::EnvironmentalReverbEffect(UInt32 flags)
{
	
	this->CreateReverb(flags);
}

/// <summary>Definition method</summary>
/// <param name="flags">Flags used when constructing hte reverb. Must be 0.</param>
void EnvironmentalReverbEffect::CreateReverb(UInt32 flags)
{
	IUnknown* reverbEffect;
    HRESULT hr = XAudio2CreateReverb(&reverbEffect, flags);
	if (FAILED (hr))
	{
		ResultCode result = (ResultCode)hr;
		throw gcnew ApplicationException(String::Format("Encountered failure while creating the reverb effect. Code {0}; Description {1}", hr, result.ToString()));
	}
}
#pragma endregion



#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
EnvironmentalReverbEffect::~EnvironmentalReverbEffect()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
EnvironmentalReverbEffect::!EnvironmentalReverbEffect()
{
	this->DisposeUnmanaged();
}

/// <summary>Destructor logic, disposes the object</summary>
void EnvironmentalReverbEffect::DisposeUnmanaged()
{
	IUnknown* reverbEffect = this->UnmanagedPointer;
	if (reverbEffect != NULL)
	{
		reverbEffect->Release();
		reverbEffect = NULL;
	}

	this->UnmanagedPointer = NULL;
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an empty instance of the related parameter type</summary>
IEffectParameter^ EnvironmentalReverbEffect::CreateParameters()
{
	return gcnew EnvironmentalReverbParameters();
}
#pragma endregion

