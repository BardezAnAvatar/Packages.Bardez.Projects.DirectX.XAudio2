

#include "Cone.h"


using namespace System;
using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</summary>
Single Cone::InnerAngle::get()
{
	return this->innerAngle;
}

/// <summary>Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</summary>
void Cone::InnerAngle::set(Single value)
{
	this->innerAngle = value;
}

/// <summary>Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</summary>
Single Cone::OuterAngle::get()
{
	return this->outerAngle;
}

/// <summary>Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</summary>
void Cone::OuterAngle::set(Single value)
{
	this->outerAngle = value;
}

/// <summary>Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</summary>
Single Cone::InnerVolume::get()
{
	return this->innerVolume;
}

/// <summary>Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</summary>
void Cone::InnerVolume::set(Single value)
{
	this->innerVolume = value;
}

/// <summary>Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</summary>
Single Cone::OuterVolume::get()
{
	return this->outerVolume;
}

/// <summary>Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</summary>
void Cone::OuterVolume::set(Single value)
{
	this->outerVolume = value;
}

/// <summary>LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
Single Cone::InnerLPF::get()
{
	return this->innerLPF;
}

/// <summary>LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
void Cone::InnerLPF::set(Single value)
{
	this->innerLPF = value;
}

/// <summary>LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
Single Cone::OuterLPF::get()
{
	return this->outerLPF;
}

/// <summary>LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
void Cone::OuterLPF::set(Single value)
{
	this->outerLPF = value;
}

/// <summary>Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</summary>
Single Cone::InnerReverb::get()
{
	return this->innerReverb;
}

/// <summary>Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</summary>
void Cone::InnerReverb::set(Single value)
{
	this->innerReverb = value;
}

/// <summary>Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</summary>
Single Cone::OuterReverb::get()
{
	return this->outerReverb;
}

/// <summary>Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</summary>
void Cone::OuterReverb::set(Single value)
{
	this->outerReverb = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
/// <remarks>Generates an omnidirectional cone</remarks>
Cone::Cone()
{
	this->innerAngle = X3DAUDIO_2PI;
	this->outerAngle = X3DAUDIO_2PI;
	this->innerVolume = 1.0F;
	this->outerVolume = 1.0F;
	this->innerLPF = 0.0F;
	this->outerLPF = 0.0F;
	this->innerReverb = 0.0F;
	this->outerReverb = 0.0F;
}

/// <summary>Definition constructor</summary>
/// <param name="innerAngle">Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</param>
/// <param name="outerAngle">Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</param>
/// <param name="innerVolume">Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</param>
/// <param name="outerVolume">Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</param>
/// <param name="innerLPF">LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
/// <param name="outerLPF">LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
/// <param name="innerReverb">Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</param>
/// <param name="outerReverb">Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</param>
Cone::Cone(Single innerAngle, Single outerAngle, Single innerVolume, Single outerVolume, Single innerLPF, Single outerLPF, Single innerReverb, Single outerReverb)
{
	this->innerAngle = innerAngle;
	this->outerAngle = outerAngle;
	this->innerVolume = innerVolume;
	this->outerVolume = outerVolume;
	this->innerLPF = innerLPF;
	this->outerLPF = outerLPF;
	this->innerReverb = innerReverb;
	this->outerReverb = outerReverb;
}

/// <summary>Constructs a managed audio cone from an unmanaged source</summary>
/// <param name="cone">Unmanaged source cone to copy from</param>
Cone^ Cone::FromUnmanaged(X3DAUDIO_CONE* cone)
{
	Cone^ managed = nullptr;
	
	if (cone != NULL)
		managed = gcnew Cone(cone->InnerAngle, cone->OuterAngle, cone->InnerVolume, cone->OuterVolume, cone->InnerLPF, cone->OuterLPF, cone->InnerReverb, cone->OuterReverb);
	
	return managed;
}
#pragma endregion



#pragma region Methods
/// <summary>Generated an unmanaged copy for API calls</summary>
/// <returns>An unmanaged copy for API calls</returns>
X3DAUDIO_CONE* Cone::ToUnmanaged()
{
	X3DAUDIO_CONE* cone = new X3DAUDIO_CONE;

	cone->InnerAngle = this->innerAngle;
	cone->OuterAngle = this->outerAngle;
	cone->InnerVolume = this->innerVolume;
	cone->OuterVolume = this->outerVolume;
	cone->InnerLPF = this->innerLPF;
	cone->OuterLPF = this->outerLPF;
	cone->InnerReverb = this->innerReverb;
	cone->OuterReverb = this->outerReverb;

	return cone;
}

/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_CONE</summary>
/// <param name="cone">Pointer to the cone to release memory for</param>
void Cone::ReleaseMemory(X3DAUDIO_CONE** cone)
{
	if (*cone != NULL)
		delete *cone;

	*cone = NULL;
}
#pragma endregion

