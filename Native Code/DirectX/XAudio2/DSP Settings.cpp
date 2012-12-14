

#include "DSP Settings.h"


using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>Matrix of volume level coefficients for source and destination channels</summary>
/// <remarks>This must be at least <see cref="ChannelCountSource" /> � <see cref="ChannelCountDestination" /> elements long.</remarks>
IList<Single>^ DspSettings::CoefficientsMatrix::get()
{
	return this->coefficientsMatrix;
}

/// <summary>Matrix of volume level coefficients for source and destination channels</summary>
/// <remarks>This must be at least <see cref="ChannelCountSource" /> � <see cref="ChannelCountDestination" /> elements long.</remarks>
void DspSettings::CoefficientsMatrix::set(IList<Single>^ value)
{
	this->coefficientsMatrix = value;
}

/// <summary>Delay time array, which receives delays for each destination channel in milliseconds. This array must have at least <see cref="ChannelCountDestination" /> elements</summary>
IList<Single>^ DspSettings::DelayTimes::get()
{
	return this->delayTimes;
}

/// <summary>Delay time array, which receives delays for each destination channel in milliseconds. This array must have at least <see cref="ChannelCountDestination" /> elements</summary>
void DspSettings::DelayTimes::set(IList<Single>^ value)
{
	this->delayTimes = value;
}

/// <summary>Number of source channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
UInt32 DspSettings::ChannelCountSource::get()
{
	return this->channelCountSource;
}

/// <summary>Number of source channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
void DspSettings::ChannelCountSource::set(UInt32 value)
{
	this->channelCountSource = value;
}

/// <summary>Number of destination channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
UInt32 DspSettings::ChannelCountDestination::get()
{
	return this->channelCountDestination;
}

/// <summary>Number of destination channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
void DspSettings::ChannelCountDestination::set(UInt32 value)
{
	this->channelCountDestination = value;
}

/// <summary>LPF direct-path coefficient.</summary>
Single DspSettings::CoefficientLowPassFilterDirect::get()
{
	return this->coefficientLowPassFilterDirect;
}

/// <summary>LPF direct-path coefficient.</summary>
void DspSettings::CoefficientLowPassFilterDirect::set(Single value)
{
	this->coefficientLowPassFilterDirect = value;
}

/// <summary>LPF reverb-path coefficient.</summary>
Single DspSettings::CoefficientLowPassFilterReverberation::get()
{
	return this->coefficientLowPassFilterReverberation;
}

/// <summary>LPF reverb-path coefficient.</summary>
void DspSettings::CoefficientLowPassFilterReverberation::set(Single value)
{
	this->coefficientLowPassFilterReverberation = value;
}

/// <summary>Reverb send level.</summary>
Single DspSettings::ReverberationLevel::get()
{
	return this->reverberationLevel;
}

/// <summary>Reverb send level.</summary>
void DspSettings::ReverberationLevel::set(Single value)
{
	this->reverberationLevel = value;
}

/// <summary>Doppler shift factor. Scales the resampler ratio for Doppler shift effect, where: effective_frequency = DopplerFactor � original_frequency</summary>
Single DspSettings::DopplerFactor::get()
{
	return this->dopplerFactor;
}

/// <summary>Doppler shift factor. Scales the resampler ratio for Doppler shift effect, where: effective_frequency = DopplerFactor � original_frequency</summary>
void DspSettings::DopplerFactor::set(Single value)
{
	this->dopplerFactor = value;
}

/// <summary>Emitter-to-listener interior angle, expressed in radians with respect to the emitter's front orientation.</summary>
Single DspSettings::EmitterToListenerAngle::get()
{
	return this->emitterToListenerAngle;
}

/// <summary>Emitter-to-listener interior angle, expressed in radians with respect to the emitter's front orientation.</summary>
void DspSettings::EmitterToListenerAngle::set(Single value)
{
	this->emitterToListenerAngle = value;
}

/// <summary>Distance in user-defined world units from the listener to the emitter base position.</summary>
Single DspSettings::EmitterToListenerDistance::get()
{
	return this->emitterToListenerDistance;
}

/// <summary>Distance in user-defined world units from the listener to the emitter base position.</summary>
void DspSettings::EmitterToListenerDistance::set(Single value)
{
	this->emitterToListenerDistance = value;
}

/// <summary>Component of emitter velocity vector projected onto emitter-to-listener vector in user-defined world units per second.</summary>
Single DspSettings::EmitterVelocity::get()
{
	return this->emitterVelocity;
}

/// <summary>Component of emitter velocity vector projected onto emitter-to-listener vector in user-defined world units per second.</summary>
void DspSettings::EmitterVelocity::set(Single value)
{
	this->emitterVelocity = value;
}

/// <summary>Component of listener velocity vector projected onto the emitter -> listener vector in user-defined world units per second.</summary>
Single DspSettings::ListenerVelocity::get()
{
	return this->listenerVelocity;
}

/// <summary>Component of listener velocity vector projected onto the emitter -> listener vector in user-defined world units per second.</summary>
void DspSettings::ListenerVelocity::set(Single value)
{
	this->listenerVelocity = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
DspSettings::DspSettings()
{
	this->SetDefaultValues();
}

/// <summary>Partial definition constructor</summary>
/// <param name="sourceChannels">Number of source channels</param>
/// <param name="destinationChannels">Number of destination channels</param>
DspSettings::DspSettings(UInt32 sourceChannels, UInt32 destinationChannels)
{
	this->SetDefaultValues();

	this->channelCountSource = sourceChannels;
	this->channelCountDestination = destinationChannels;
}

/// <summary>Constructs an instance from its unmanaged native equivalent</summary>
DspSettings^ DspSettings::FromUnmanaged(X3DAUDIO_DSP_SETTINGS* unmanaged)
{
	DspSettings^ managed = nullptr;

	if (unmanaged != NULL)
	{
		managed = gcnew DspSettings();
		managed->PopulateFromUnmanaged(unmanaged);
	}

	return managed;
}
#pragma endregion



#pragma region Methods
/// <summary>Populates this instance from its unmanaged native equivalent</summary>
void DspSettings::PopulateFromUnmanaged(X3DAUDIO_DSP_SETTINGS* unmanaged)
{
	if (unmanaged != NULL)
	{
		this->channelCountSource					= unmanaged->SrcChannelCount;
		this->channelCountDestination				= unmanaged->DstChannelCount;
		this->coefficientsMatrix					= (IList<Single>^)(DspSettings::CopyUnmanagedArray(unmanaged->pMatrixCoefficients, unmanaged->SrcChannelCount * unmanaged->DstChannelCount));
		this->delayTimes							= (IList<Single>^)(DspSettings::CopyUnmanagedArray(unmanaged->pDelayTimes, unmanaged->DstChannelCount));
		this->coefficientLowPassFilterDirect		= unmanaged->LPFDirectCoefficient;
		this->coefficientLowPassFilterReverberation	= unmanaged->LPFReverbCoefficient;
		this->reverberationLevel					= unmanaged->ReverbLevel;
		this->dopplerFactor							= unmanaged->DopplerFactor;
		this->emitterToListenerAngle				= unmanaged->EmitterToListenerAngle;
		this->emitterToListenerDistance				= unmanaged->EmitterToListenerDistance;
		this->emitterVelocity						= unmanaged->EmitterVelocityComponent;
		this->listenerVelocity						= unmanaged->ListenerVelocityComponent;
	}
}

/// <summary>Generates an unmanged native equivalent from this instance</summary>
X3DAUDIO_DSP_SETTINGS* DspSettings::ToUnmanaged()
{
	X3DAUDIO_DSP_SETTINGS* unmanaged = new X3DAUDIO_DSP_SETTINGS;

	//copy settings
	unmanaged->SrcChannelCount = this->channelCountSource;
	unmanaged->DstChannelCount = this->channelCountDestination;

	return unmanaged;
}

/// <summary>Initializes this structure to default junk values</summary>
void DspSettings::SetDefaultValues()
{
	this->channelCountSource						= 0U;
	this->channelCountDestination					= 0U;
	this->coefficientsMatrix						= nullptr;
	this->delayTimes								= nullptr;
	this->coefficientLowPassFilterDirect			= Single::NaN;
	this->coefficientLowPassFilterReverberation		= Single::NaN;
	this->reverberationLevel						= Single::NaN;
	this->dopplerFactor								= Single::NaN;
	this->emitterToListenerAngle					= Single::NaN;
	this->emitterToListenerDistance					= Single::NaN;
	this->emitterVelocity							= Single::NaN;
	this->listenerVelocity							= Single::NaN;
}

///// <summary>Copies a source array of unmanaged Primitives to a destination managed array of primitives</summary>
///// <param name="Primitive">Type of primitive to copy</param>
///// <param name="source">Source to read from</param>
///// <param name="count">Count of records to copy</param>
///// <returns>The copied primitive array</returns>
//generic<class Primitive>
//array<Primitive>^ DspSettings::CopyUnmanagedArray(void* source, Int64 count)
//{
//	array<Primitive>^ managed = nullptr;
//
//	if (source != NULL)
//	{
//		managed = gcnew array<Primitive>(count);
//
//		for (Int64 index = 0; index < count; ++index)
//		{
//			managed[index] = source[index];
//		}
//	}
//
//	return managed;
//}

/// <summary>Copies a source array of unmanaged FLOAT32 to a destination managed array of Singles</summary>
/// <param name="source">Source to read from</param>
/// <param name="count">Count of records to copy</param>
/// <returns>The copied Single array</returns>
array<Single>^ DspSettings::CopyUnmanagedArray(FLOAT32* source, Int64 count)
{
	array<Single>^ managed = nullptr;
	if (source != NULL)
	{
		array<Single>^ delays = gcnew array<Single>(count);
			
		for (Int64 index = 0; index < count; ++index)
			managed[index] = source[index];
	}

	return managed;
}

/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_DSP_SETTINGS</summary>
/// <param name="settings">Pointer to the DSP Settings to release memory for</param>
void DspSettings::ReleaseMemory(X3DAUDIO_DSP_SETTINGS** settings)
{
	if ((*settings) != NULL)
	{
		if ((*settings)->pMatrixCoefficients != NULL)
		{
			delete [] (*settings)->pMatrixCoefficients;
			(*settings)->pMatrixCoefficients = NULL;
		}

		if ((*settings)->pDelayTimes != NULL)
		{
			delete [] (*settings)->pDelayTimes;
			(*settings)->pDelayTimes = NULL;
		}

		delete *settings;
		*settings = NULL;
	}
}
#pragma endregion

