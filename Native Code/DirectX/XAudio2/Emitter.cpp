

#include "Emitter.h"


using namespace System::Collections::Generic;
using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>
///		Value to be used for the inner radius calculations. If InnerRadius is 0, then no inner radius is used,
///		but <see cref="InnerRadiusAngle"/> may still be used. This value must be between 0.0F and MAX_FLT (3.402823466e+38F).
/// </summary>
Single Emitter::InnerRadius::get()
{
	return this->innerRadius;
}

/// <summary>
///		Value to be used for the inner radius calculations. If InnerRadius is 0, then no inner radius is used,
///		but <see cref="InnerRadiusAngle"/> may still be used. This value must be between 0.0F and MAX_FLT (3.402823466e+38F).
/// </summary>
void Emitter::InnerRadius::set(Single value)
{
	this->innerRadius = value;
}

/// <summary>Value to be used for the inner radius angle calculations. This value must be between 0.0f and X3DAUDIO_PI/4.0 (45 degrees).</summary>
Single Emitter::InnerRadiusAngle::get()
{
	return this->innerRadiusAngle;
}

/// <summary>Value to be used for the inner radius angle calculations. This value must be between 0.0f and X3DAUDIO_PI/4.0 (45 degrees).</summary>
void Emitter::InnerRadiusAngle::set(Single value)
{
	this->innerRadiusAngle = value;
}

/// <summary>Number of emitters defined by this Emitter. Must be greater than 0.</summary>
UInt32 Emitter::ChannelCount::get()
{
	return this->channelCount;
}

/// <summary>Number of emitters defined by this Emitter. Must be greater than 0.</summary>
void Emitter::ChannelCount::set(UInt32 value)
{
	this->channelCount = value;
}

/// <summary>
///		Distance from <see cref="Position" /> that channels will be placed if <see cref="ChannelCount" /> is greater than 1.
///		Only used with multi-channel emitters for matrix calculations. Must be greater than or equal to 0.0F.
///	</summary>
Single Emitter::ChannelRadius::get()
{
	return this->channelRadius;
}

/// <summary>
///		Distance from <see cref="Position" /> that channels will be placed if <see cref="ChannelCount" /> is greater than 1.
///		Only used with multi-channel emitters for matrix calculations. Must be greater than or equal to 0.0F.
///	</summary>
void Emitter::ChannelRadius::set(Single value)
{
	this->channelRadius = value;
}
						
/// <summary>
///		Table of channel positions, expressed as an azimuth in radians along the channel radius with respect to the front orientation vector
///		in the plane orthogonal to the top orientation vector. An azimuth of X3DAUDIO_2PI specifies a channel is a low-frequency effects (LFE) channel.
///		LFE channels are positioned at the emitter base and are calculated with respect to <see cref="CurveLFE" /> only, never <see cref="CurveVolume" />.
///		ChannelAzimuths must have at least <see cref="ChannelCount" /> elements. The table values must be within 0.0f to X3DAUDIO_2PI.
///		ChannelAzimuths is used with multi-channel emitters for matrix calculations.
///	</summary>
IList<Single>^ Emitter::ChannelAzimuths::get()
{
	return this->channelAzimuths;
}
						
/// <summary>
///		Table of channel positions, expressed as an azimuth in radians along the channel radius with respect to the front orientation vector
///		in the plane orthogonal to the top orientation vector. An azimuth of X3DAUDIO_2PI specifies a channel is a low-frequency effects (LFE) channel.
///		LFE channels are positioned at the emitter base and are calculated with respect to <see cref="CurveLFE" /> only, never <see cref="CurveVolume" />.
///		ChannelAzimuths must have at least <see cref="ChannelCount" /> elements. The table values must be within 0.0f to X3DAUDIO_2PI.
///		ChannelAzimuths is used with multi-channel emitters for matrix calculations.
///	</summary>
void Emitter::ChannelAzimuths::set(IList<Single>^ value)
{
	this->channelAzimuths = value;
}

/// <summary>
///		Volume-level distance curve, which is used only for matrix calculations.
///		NULL specifies a specialized default curve that conforms to the inverse square law, such that when distance is between 0.0f
///		and <see cref="CurveDistanceScaler" /> × 1.0f, no attenuation is applied. When distance is greater than <see cref="CurveDistanceScaler" /> × 1.0f,
///		the amplification factor is (<see cref="CurveDistanceScaler" /> × 1.0f)/distance. At a distance of <see cref="CurveDistanceScaler" /> × 2.0f,
///		the sound will be at half volume or -6 dB, at a distance of <see cref="CurveDistanceScaler" /> × 4.0f, the sound will be at one quarter volume or -12 dB,
///		and so on. <see cref="CurveVolume" /> and pLFECurve are independent of each other. <see cref="curveVolume" /> does not affect LFE channel volume.
///	</summary>
IList<DistanceSetting^>^ Emitter::CurveVolume::get()
{
	return this->curveVolume;
}

/// <summary>
///		Volume-level distance curve, which is used only for matrix calculations.
///		NULL specifies a specialized default curve that conforms to the inverse square law, such that when distance is between 0.0f
///		and <see cref="CurveDistanceScaler" /> × 1.0f, no attenuation is applied. When distance is greater than <see cref="CurveDistanceScaler" /> × 1.0f,
///		the amplification factor is (<see cref="CurveDistanceScaler" /> × 1.0f)/distance. At a distance of <see cref="CurveDistanceScaler" /> × 2.0f,
///		the sound will be at half volume or -6 dB, at a distance of <see cref="CurveDistanceScaler" /> × 4.0f, the sound will be at one quarter volume or -12 dB,
///		and so on. <see cref="CurveVolume" /> and pLFECurve are independent of each other. <see cref="curveVolume" /> does not affect LFE channel volume.
///	</summary>
void Emitter::CurveVolume::set(IList<DistanceSetting^>^ value)
{
	this->curveVolume = value;
}

/// <summary>
///		LFE roll-off distance curve, or NULL to use default curve: [0.0f, <see cref="CurveDistanceScaler" /> ×1.0f], [<see cref="CurveDistanceScaler" /> ×1.0f, 0.0f].
///		A NULL value for CurveLFE specifies a default curve that conforms to the inverse square law with distances &lt;= <see cref="CurveDistanceScaler" />
///		clamped to no attenuation. <see cref="CurveVolume" /> and CurveLFE are independent of each other. CurveLFE does not affect non LFE channel volume.
///	</summary>
IList<DistanceSetting^>^ Emitter::CurveLFE::get()
{
	return this->curveLFE;
}

/// <summary>
///		LFE roll-off distance curve, or NULL to use default curve: [0.0f, <see cref="CurveDistanceScaler" /> ×1.0f], [<see cref="CurveDistanceScaler" /> ×1.0f, 0.0f].
///		A NULL value for CurveLFE specifies a default curve that conforms to the inverse square law with distances &lt;= <see cref="CurveDistanceScaler" />
///		clamped to no attenuation. <see cref="CurveVolume" /> and CurveLFE are independent of each other. CurveLFE does not affect non LFE channel volume.
///	</summary>
void Emitter::CurveLFE::set(IList<DistanceSetting^>^ value)
{
	this->curveLFE = value;
}

/// <summary>
///		Low-pass filter (LPF) direct-path coefficient distance curve, or NULL to use the default curve:
///		[0.0f, 1.0f], [1.0f, 0.75f]. CurveLpfDirect is only used for LPF direct-path calculations. 
///	</summary>
IList<DistanceSetting^>^ Emitter::CurveLpfDirect::get()
{
	return this->curveLpfDirect;
}

/// <summary>
///		Low-pass filter (LPF) direct-path coefficient distance curve, or NULL to use the default curve:
///		[0.0f, 1.0f], [1.0f, 0.75f]. CurveLpfDirect is only used for LPF direct-path calculations. 
///	</summary>
void Emitter::CurveLpfDirect::set(IList<DistanceSetting^>^ value)
{
	this->curveLpfDirect = value;
}

/// <summary>
///		LPF reverb-path coefficient distance curve, or NULL to use default curve: [0.0f, 0.75f], [1.0f, 0.75f].
///		CurveLpfReverb is only used for LPF reverb path calculations.
///	</summary>
IList<DistanceSetting^>^ Emitter::CurveLpfReverb::get()
{
	return this->curveLpfReverb;
}

/// <summary>
///		LPF reverb-path coefficient distance curve, or NULL to use default curve: [0.0f, 0.75f], [1.0f, 0.75f].
///		CurveLpfReverb is only used for LPF reverb path calculations.
///	</summary>
void Emitter::CurveLpfReverb::set(IList<DistanceSetting^>^ value)
{
	this->curveLpfReverb = value;
}

/// <summary>Reverb send level distance curve, or NULL to use default curve: [0.0f, 1.0f], [1.0f, 0.0f].</summary>
IList<DistanceSetting^>^ Emitter::CurveReverb::get()
{
	return this->curveReverb;
}

/// <summary>Reverb send level distance curve, or NULL to use default curve: [0.0f, 1.0f], [1.0f, 0.0f].</summary>
void Emitter::CurveReverb::set(IList<DistanceSetting^>^ value)
{
	this->curveReverb = value;
}
						
/// <summary>
///		Curve distance scaler that is used to scale normalized distance curves to user-defined world units, and/or to exaggerate their effect.
///		This does not affect any other calculations. The value must be within the range FLT_MIN to FLT_MAX (1.175494351e-38F to 3.402823466e+38F).
///		CurveDistanceScaler is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
///	</summary>
Single Emitter::CurveDistanceScaler::get()
{
	return this->curveDistanceScaler;
}
						
/// <summary>
///		Curve distance scaler that is used to scale normalized distance curves to user-defined world units, and/or to exaggerate their effect.
///		This does not affect any other calculations. The value must be within the range FLT_MIN to FLT_MAX (1.175494351e-38F to 3.402823466e+38F).
///		CurveDistanceScaler is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
///	</summary>
void Emitter::CurveDistanceScaler::set(Single value)
{
	this->curveDistanceScaler = value;
}

/// <summary>
///		Doppler shift scaler that is used to exaggerate Doppler shift effect.
///		DopplerScaler is only used for Doppler calculations and does not affect any other calculations.
///		The value must be within the range 0.0f to FLT_MAX (3.402823466e+38F).
///	</summary>
Single Emitter::DopplerScaler::get()
{
	return this->dopplerScaler;
}

/// <summary>
///		Doppler shift scaler that is used to exaggerate Doppler shift effect.
///		DopplerScaler is only used for Doppler calculations and does not affect any other calculations.
///		The value must be within the range 0.0f to FLT_MAX (3.402823466e+38F).
///	</summary>
void Emitter::DopplerScaler::set(Single value)
{
	this->dopplerScaler = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Partial definition constructor</summary>
/// <param name="channels">Number of channels for this emitter</param>
Emitter::Emitter(UInt32 channels) : Actor()
{
	this->innerRadius = 2.0F;
	this->innerRadiusAngle = X3DAUDIO_PI/4.0;
	this->channelCount = channels;
	this->channelRadius = 0.0F;
	this->channelAzimuths = nullptr;
	this->curveVolume = nullptr;
	this->curveLFE = nullptr;
	this->curveLpfDirect = nullptr;
	this->curveLpfReverb = nullptr;
	this->curveReverb = nullptr;
	this->curveDistanceScaler = 1.0F;
	this->dopplerScaler = 1.0F;
}

/// <summary>X3DAudio constructor</summary>
/// <param name="front">Orientation of front direction</param>
/// <param name="top">Orientation of top direction</param>
/// <param name="position">Position in user-defined world units</param>
/// <param name="velocity">Velocity vector in user-defined world units per second</param>
/// <param name="cone">Listener cone</param>
/// <param name="innerRadius">Value to be used for the inner radius calculations</param>
/// <param name="innerRadiusAngle">Value to be used for the inner radius angle calculations</param>
/// <param name="channelCount">Number of emitters defined</param>
/// <param name="channelRadius">Distance from <see cref="Position" /> that channels will be placed</param>
/// <param name="channelAzimuths">Table of channel positions</param>
/// <param name="curveVolume">Volume-level distance curve</param>
/// <param name="curveLFE">LFE roll-off distance curve</param>
/// <param name="curveLpfDirect">Low-pass filter (LPF) direct-path coefficient distance curve</param>
/// <param name="curveLpfReverb">LPF reverb-path coefficient distance curve</param>
/// <param name="curveReverb">Reverb send level distance curve</param>
/// <param name="curveDistanceScaler">Curve distance scaler that is used to scale normalized distance curves to user-defined world units</param>
/// <param name="dopplerScaler">Doppler shift scaler that is used to exaggerate Doppler shift effect</param>
Emitter::Emitter(Vector<Single>^ front, Vector<Single>^ top, Vector<Single>^ position, Vector<Single>^ velocity, Bardez::Projects::DirectX::X3DAudio::Cone^ cone,
	Single innerRadius, Single innerRadiusAngle, UInt32 channelCount, Single channelRadius, IList<Single>^ channelAzimuths,
	IList<DistanceSetting^>^ curveVolume, IList<DistanceSetting^>^ curveLFE, IList<DistanceSetting^>^ curveLpfDirect, IList<DistanceSetting^>^ curveLpfReverb, IList<DistanceSetting^>^ curveReverb,
	Single curveDistanceScaler, Single dopplerScaler) : Actor(front, top, position, velocity, cone)
{
	this->innerRadius = innerRadius;
	this->innerRadiusAngle = innerRadiusAngle;
	this->channelCount = channelCount;
	this->channelRadius = channelRadius;
	this->channelAzimuths = channelAzimuths;
	this->curveVolume = curveVolume;
	this->curveLFE = curveLFE;
	this->curveLpfDirect = curveLpfDirect;
	this->curveLpfReverb = curveLpfReverb;
	this->curveReverb = curveReverb;
	this->curveDistanceScaler = curveDistanceScaler;
	this->dopplerScaler = dopplerScaler;
}
						
/// <summary>X3DAudio constructor</summary>
/// <param name="emitter">Unmanaged emitter to copy from.</param>
Emitter^ Emitter::FromUnmanaged(X3DAUDIO_EMITTER* emitter)
{
	Emitter^ managed = nullptr;

	if (emitter != NULL)
	{
		Cone^ cone = nullptr;
		if (emitter->pCone != NULL)
			cone = Cone::FromUnmanaged(emitter->pCone);

		Vector<Single>^ front = Actor::CopyUnmanagedVector(emitter->OrientFront);
		Vector<Single>^ top = Actor::CopyUnmanagedVector(emitter->OrientTop);
		Vector<Single>^ position = Actor::CopyUnmanagedVector(emitter->Position);
		Vector<Single>^ velocity = Actor::CopyUnmanagedVector(emitter->Velocity);

		List<Single>^ azimuths = nullptr;
		if (emitter->pChannelAzimuths != NULL)
		{
			azimuths = gcnew List<Single>();
			for (UInt32 index = 0U; index < emitter->ChannelCount; ++index)
				azimuths->Add(emitter->pChannelAzimuths[index]);
		}

		IList<DistanceSetting^>^ curveVolume = Emitter::CopyCurveToList(emitter->pVolumeCurve);
		IList<DistanceSetting^>^ curveLfe = Emitter::CopyCurveToList(emitter->pLFECurve);
		IList<DistanceSetting^>^ curveLpfDirect = Emitter::CopyCurveToList(emitter->pLPFDirectCurve);
		IList<DistanceSetting^>^ curveLpfReverb = Emitter::CopyCurveToList(emitter->pLPFReverbCurve);
		IList<DistanceSetting^>^ curveReverb = Emitter::CopyCurveToList(emitter->pReverbCurve);

		managed = gcnew Emitter(front, top, position, velocity, cone,
			emitter->InnerRadius, emitter->InnerRadiusAngle, emitter->ChannelCount, emitter->ChannelRadius, azimuths,
			curveVolume, curveLfe, curveLpfDirect, curveLpfReverb, curveReverb,
			emitter->CurveDistanceScaler, emitter->DopplerScaler);
	}

	return managed;
}
#pragma endregion



#pragma region Methods
/// <summary>Generated an unmanaged copy for API calls</summary>
/// <returns>An unmanaged copy for API calls</returns>
X3DAUDIO_EMITTER* Emitter::ToUnmanaged()
{
	X3DAUDIO_EMITTER* emitter = new X3DAUDIO_EMITTER;
	
	X3DAUDIO_CONE* cone = NULL;
	if (this->cone != nullptr)
		cone = this->cone->ToUnmanaged();

	FLOAT32* azimuths = NULL;
	if (this->channelAzimuths != nullptr)
	{
		azimuths = new FLOAT32[this->channelAzimuths->Count];

		for (Int32 index = 0; index < this->channelAzimuths->Count; ++index)
			azimuths[index] = this->channelAzimuths[index];
	}

	//assign values
	emitter->pCone = cone;
	emitter->OrientFront = Actor::CopyManagedVector(this->orientFront);
	emitter->OrientTop = Actor::CopyManagedVector(this->orientTop);
	emitter->Position = Actor::CopyManagedVector(this->position);
	emitter->Velocity = Actor::CopyManagedVector(this->velocity);
	emitter->InnerRadius = this->innerRadius;
	emitter->InnerRadiusAngle = this->innerRadiusAngle;
	emitter->ChannelCount = this->channelCount;
	emitter->ChannelRadius = this->channelRadius;
	emitter->pChannelAzimuths = azimuths;
	emitter->pVolumeCurve = Emitter::GenerateCurveToArray(this->curveVolume);
	emitter->pLFECurve = Emitter::GenerateCurveToArray(this->curveLFE);
	emitter->pLPFDirectCurve = Emitter::GenerateCurveToArray(this->curveLpfDirect);
	emitter->pLPFReverbCurve = Emitter::GenerateCurveToArray(this->curveLpfReverb);
	emitter->pReverbCurve = Emitter::GenerateCurveToArray(this->curveReverb);
	emitter->CurveDistanceScaler = this->curveDistanceScaler;
	emitter->DopplerScaler = this->dopplerScaler;

	return emitter;
}

/// <summary>Copies an unmanaged X3DAudio distance curve into a managed copy</summary>
/// <param name="curve">Curve to copy</param>
IList<DistanceSetting^>^ Emitter::CopyCurveToList(X3DAUDIO_DISTANCE_CURVE* curve)
{
	List<DistanceSetting^>^ dspCurve = nullptr;

	if (curve != NULL)
	{
		if (curve->pPoints == NULL)
			throw gcnew NullReferenceException("X3DAUDIO_DISTANCE_CURVE pointer, curve, had a null pPoints member.");

		dspCurve = gcnew List<DistanceSetting^>();

		for (UInt32 index = 0U; index < curve->PointCount; ++index)
			dspCurve->Add(DistanceSetting::FromUnmanaged(curve->pPoints[index]));
	}

	return dspCurve;
}

/// <summary>Copies a managed distance curve into an unmanaged copy</summary>
/// <param name="curve">Curve to copy</param>
X3DAUDIO_DISTANCE_CURVE* Emitter::GenerateCurveToArray(IList<DistanceSetting^>^ curve)
{
	X3DAUDIO_DISTANCE_CURVE* dspCurve = NULL;

	if (curve != nullptr)
	{
		dspCurve = new X3DAUDIO_DISTANCE_CURVE;
		dspCurve->PointCount = Convert::ToUInt32(curve->Count);

		X3DAUDIO_DISTANCE_CURVE_POINT* points = new X3DAUDIO_DISTANCE_CURVE_POINT[dspCurve->PointCount];

		for (Int32 i = 0; i < curve->Count; ++i)
		{
			points[i].Distance = curve[i]->Distance;
			points[i].DSPSetting = curve[i]->Setting;
		}

		dspCurve->pPoints = points;
	}

	return dspCurve;
}

/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_EMITTER</summary>
/// <param name="emitter">Pointer to the emitter to release memory for</param>
void Emitter::ReleaseMemory(X3DAUDIO_EMITTER** emitter)
{
	if ((*emitter) != NULL)
	{
		if ((*emitter)->pChannelAzimuths != NULL)
		{
			delete [] (*emitter)->pChannelAzimuths;
			(*emitter)->pChannelAzimuths = NULL;
		}
		
		//release memory
		Cone::ReleaseMemory(&((*emitter)->pCone));
		Emitter::ReleaseMemory(&((*emitter)->pVolumeCurve));
		Emitter::ReleaseMemory(&((*emitter)->pLFECurve));
		Emitter::ReleaseMemory(&((*emitter)->pLPFDirectCurve));
		Emitter::ReleaseMemory(&((*emitter)->pLPFReverbCurve));
		Emitter::ReleaseMemory(&((*emitter)->pReverbCurve));
		
		//NULL out memory
		(*emitter)->pCone				= NULL;
		(*emitter)->pVolumeCurve		= NULL;
		(*emitter)->pLFECurve			= NULL;
		(*emitter)->pLPFDirectCurve		= NULL;
		(*emitter)->pLPFReverbCurve		= NULL;
		(*emitter)->pReverbCurve		= NULL;

		//free the emitter
		delete *emitter;
		*emitter = NULL;
	}
}

/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_DISTANCE_CURVE</summary>
/// <param name="curve">Pointer to the distance curve to release memory for</param>
void Emitter::ReleaseMemory(X3DAUDIO_DISTANCE_CURVE** curve)
{
	if ((*curve) != NULL)
	{
		//free curve points
		if ((*curve)->pPoints != NULL)
		{
			delete [] (*curve)->pPoints;
			(*curve)->pPoints = NULL;
		}

		//free the curve
		delete *curve;
		*curve = NULL;
	}
}
#pragma endregion