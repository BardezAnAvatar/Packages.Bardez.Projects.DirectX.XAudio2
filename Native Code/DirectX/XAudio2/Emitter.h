

#ifndef Bardez_Projects_DirectX_X3DAudio_Emitter
#define Bardez_Projects_DirectX_X3DAudio_Emitter


#include <windows.h>
#include <XAudio2.h>
#include <X3DAudio.h>
#include "Actor.h"
#include "Cone.h"
#include "Distance Setting.h"


using namespace System;
using namespace System::Collections::Generic;
using namespace Bardez::Projects::BasicStructures::ThreeDimensional;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Represents a wrapper around an X3DAudio Emitter struct. Does not contain the actual struct.</summary>
				public ref class Emitter : Actor
				{
					#pragma region Fields
					protected:
						/// <summary>
						///		Value to be used for the inner radius calculations. If InnerRadius is 0, then no inner radius is used,
						///		but <see cref="innerRadiusAngle"/> may still be used. This value must be between 0.0F and MAX_FLT (3.402823466e+38F).
						/// </summary>
						Single innerRadius;

						/// <summary>Value to be used for the inner radius angle calculations. This value must be between 0.0f and X3DAUDIO_PI/4.0 (45 degrees).</summary>
						Single innerRadiusAngle;

						/// <summary>Number of emitters defined by this Emitter. Must be greater than 0.</summary>
						UInt32 channelCount;

						/// <summary>
						///		Distance from <see cref="Position" /> that channels will be placed if <see cref="channelCount" /> is greater than 1.
						///		Only used with multi-channel emitters for matrix calculations. Must be greater than or equal to 0.0F.
						///	</summary>
						Single channelRadius;
						
						/// <summary>
						///		Table of channel positions, expressed as an azimuth in radians along the channel radius with respect to the front orientation vector
						///		in the plane orthogonal to the top orientation vector. An azimuth of X3DAUDIO_2PI specifies a channel is a low-frequency effects (LFE) channel.
						///		LFE channels are positioned at the emitter base and are calculated with respect to <see cref="curveLFE" /> only, never <see cref="curveVolume" />.
						///		channelAzimuths must have at least <see cref="channelCount" /> elements. The table values must be within 0.0f to X3DAUDIO_2PI.
						///		channelAzimuths is used with multi-channel emitters for matrix calculations.
						///	</summary>
						array<Single>^ channelAzimuths;

						/// <summary>
						///		Volume-level distance curve, which is used only for matrix calculations.
						///		NULL specifies a specialized default curve that conforms to the inverse square law, such that when distance is between 0.0f
						///		and <see cref="curveDistanceScaler" /> × 1.0f, no attenuation is applied. When distance is greater than <see cref="curveDistanceScaler" /> × 1.0f,
						///		the amplification factor is (<see cref="curveDistanceScaler" /> × 1.0f)/distance. At a distance of <see cref="curveDistanceScaler" /> × 2.0f,
						///		the sound will be at half volume or -6 dB, at a distance of <see cref="curveDistanceScaler" /> × 4.0f, the sound will be at one quarter volume or -12 dB,
						///		and so on. <see cref="curveVolume" /> and <see cref="curveLFE" /> are independent of each other. <see cref="curveVolume" /> does not affect LFE channel volume.
						///	</summary>
						IList<DistanceSetting^>^ curveVolume;

						/// <summary>
						///		LFE roll-off distance curve, or NULL to use default curve: [0.0f, <see cref="curveDistanceScaler" /> × 1.0f], [<see cref="curveDistanceScaler" /> × 1.0f, 0.0f].
						///		A NULL value for curveLFE specifies a default curve that conforms to the inverse square law with distances &lt;= <see cref="curveDistanceScaler" />
						///		clamped to no attenuation. <see cref="curveVolume" /> and curveLFE are independent of each other. curveLFE does not affect non LFE channel volume.
						///	</summary>
						IList<DistanceSetting^>^ curveLFE;

						/// <summary>
						///		Low-pass filter (LPF) direct-path coefficient distance curve, or NULL to use the default curve:
						///		[0.0f, 1.0f], [1.0f, 0.75f]. curveLpfDirect is only used for LPF direct-path calculations. 
						///	</summary>
						IList<DistanceSetting^>^ curveLpfDirect;

						/// <summary>
						///		LPF reverb-path coefficient distance curve, or NULL to use default curve: [0.0f, 0.75f], [1.0f, 0.75f].
						///		curveLpfReverb is only used for LPF reverb path calculations.
						///	</summary>
						IList<DistanceSetting^>^ curveLpfReverb;

						/// <summary>Reverb send level distance curve, or NULL to use default curve: [0.0f, 1.0f], [1.0f, 0.0f].</summary>
						IList<DistanceSetting^>^ curveReverb;
						
						/// <summary>
						///		Curve distance scaler that is used to scale normalized distance curves to user-defined world units, and/or to exaggerate their effect.
						///		This does not affect any other calculations. The value must be within the range FLT_MIN to FLT_MAX (1.175494351e-38F to 3.402823466e+38F).
						///		CurveDistanceScaler is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						///	</summary>
						Single curveDistanceScaler;
						
						/// <summary>
						///		Doppler shift scaler that is used to exaggerate Doppler shift effect.
						///		dopplerScaler is only used for Doppler calculations and does not affect any other calculations.
						///		The value must be within the range 0.0f to FLT_MAX (3.402823466e+38F).
						///	</summary>
						Single dopplerScaler;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>
						///		Value to be used for the inner radius calculations. If InnerRadius is 0, then no inner radius is used,
						///		but <see cref="InnerRadiusAngle"/> may still be used. This value must be between 0.0F and MAX_FLT (3.402823466e+38F).
						/// </summary>
						property Single InnerRadius
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Value to be used for the inner radius angle calculations. This value must be between 0.0f and X3DAUDIO_PI/4.0 (45 degrees).</summary>
						property Single InnerRadiusAngle
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Number of emitters defined by this Emitter. Must be greater than 0.</summary>
						property UInt32 ChannelCount
						{
							UInt32 get();
							void set(UInt32 value);
						}

						/// <summary>
						///		Distance from <see cref="Position" /> that channels will be placed if <see cref="ChannelCount" /> is greater than 1.
						///		Only used with multi-channel emitters for matrix calculations. Must be greater than or equal to 0.0F.
						///	</summary>
						property Single ChannelRadius
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>
						///		Table of channel positions, expressed as an azimuth in radians along the channel radius with respect to the front orientation vector
						///		in the plane orthogonal to the top orientation vector. An azimuth of X3DAUDIO_2PI specifies a channel is a low-frequency effects (LFE) channel.
						///		LFE channels are positioned at the emitter base and are calculated with respect to <see cref="CurveLFE" /> only, never <see cref="CurveVolume" />.
						///		ChannelAzimuths must have at least <see cref="ChannelCount" /> elements. The table values must be within 0.0f to X3DAUDIO_2PI.
						///		ChannelAzimuths is used with multi-channel emitters for matrix calculations.
						///	</summary>
						property array<Single>^ ChannelAzimuths
						{
							array<Single>^ get();
							void set(array<Single>^ value);
						}

						/// <summary>
						///		Volume-level distance curve, which is used only for matrix calculations.
						///		NULL specifies a specialized default curve that conforms to the inverse square law, such that when distance is between 0.0f
						///		and <see cref="CurveDistanceScaler" /> × 1.0f, no attenuation is applied. When distance is greater than <see cref="CurveDistanceScaler" /> × 1.0f,
						///		the amplification factor is (<see cref="CurveDistanceScaler" /> × 1.0f)/distance. At a distance of <see cref="CurveDistanceScaler" /> × 2.0f,
						///		the sound will be at half volume or -6 dB, at a distance of <see cref="CurveDistanceScaler" /> × 4.0f, the sound will be at one quarter volume or -12 dB,
						///		and so on. <see cref="CurveVolume" /> and pLFECurve are independent of each other. <see cref="curveVolume" /> does not affect LFE channel volume.
						///	</summary>
						property IList<DistanceSetting^>^ CurveVolume
						{
							IList<DistanceSetting^>^ get();
							void set(IList<DistanceSetting^>^ value);
						}

						/// <summary>
						///		LFE roll-off distance curve, or NULL to use default curve: [0.0f, <see cref="CurveDistanceScaler" /> ×1.0f], [<see cref="CurveDistanceScaler" /> ×1.0f, 0.0f].
						///		A NULL value for CurveLFE specifies a default curve that conforms to the inverse square law with distances &lt;= <see cref="CurveDistanceScaler" />
						///		clamped to no attenuation. <see cref="CurveVolume" /> and CurveLFE are independent of each other. CurveLFE does not affect non LFE channel volume.
						///	</summary>
						property IList<DistanceSetting^>^ CurveLFE
						{
							IList<DistanceSetting^>^ get();
							void set(IList<DistanceSetting^>^ value);
						}

						/// <summary>
						///		Low-pass filter (LPF) direct-path coefficient distance curve, or NULL to use the default curve:
						///		[0.0f, 1.0f], [1.0f, 0.75f]. CurveLpfDirect is only used for LPF direct-path calculations. 
						///	</summary>
						property IList<DistanceSetting^>^ CurveLpfDirect
						{
							IList<DistanceSetting^>^ get();
							void set(IList<DistanceSetting^>^ value);
						}

						/// <summary>
						///		LPF reverb-path coefficient distance curve, or NULL to use default curve: [0.0f, 0.75f], [1.0f, 0.75f].
						///		CurveLpfReverb is only used for LPF reverb path calculations.
						///	</summary>
						property IList<DistanceSetting^>^ CurveLpfReverb
						{
							IList<DistanceSetting^>^ get();
							void set(IList<DistanceSetting^>^ value);
						}

						/// <summary>Reverb send level distance curve, or NULL to use default curve: [0.0f, 1.0f], [1.0f, 0.0f].</summary>
						property IList<DistanceSetting^>^ CurveReverb
						{
							IList<DistanceSetting^>^ get();
							void set(IList<DistanceSetting^>^ value);
						}
						
						/// <summary>
						///		Curve distance scaler that is used to scale normalized distance curves to user-defined world units, and/or to exaggerate their effect.
						///		This does not affect any other calculations. The value must be within the range FLT_MIN to FLT_MAX (1.175494351e-38F to 3.402823466e+38F).
						///		CurveDistanceScaler is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						///	</summary>
						property Single CurveDistanceScaler
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>
						///		Doppler shift scaler that is used to exaggerate Doppler shift effect.
						///		DopplerScaler is only used for Doppler calculations and does not affect any other calculations.
						///		The value must be within the range 0.0f to FLT_MAX (3.402823466e+38F).
						///	</summary>
						property Single DopplerScaler
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Partial definition constructor</summary>
						/// <param name="channels">Number of channels for this emitter</param>
						Emitter(UInt32 channels);

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
						Emitter(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Bardez::Projects::DirectX::X3DAudio::Cone^ cone,
							Single innerRadius, Single innerRadiusAngle, UInt32 channelCount, Single channelRadius, array<Single>^ channelAzimuths,
							IList<DistanceSetting^>^ curveVolume, IList<DistanceSetting^>^ curveLFE, IList<DistanceSetting^>^ curveLpfDirect, IList<DistanceSetting^>^ curveLpfReverb, IList<DistanceSetting^>^ curveReverb,
							Single curveDistanceScaler, Single dopplerScaler);
						
					internal:
						/// <summary>X3DAudio constructor</summary>
						/// <param name="emitter">Unmanaged emitter to copy from.</param>
						static Emitter^ FromUnmanaged(X3DAUDIO_EMITTER* emitter);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generated an unmanaged copy for API calls</summary>
						/// <returns>An unmanaged copy for API calls</returns>
						X3DAUDIO_EMITTER* ToUnmanaged();

						/// <summary>Copies an unmanaged X3DAudio distance curve into a managed copy</summary>
						/// <param name="curve">Curve to copy</param>
						static IList<DistanceSetting^>^ CopyCurveToList(X3DAUDIO_DISTANCE_CURVE* curve);

						/// <summary>Copies a managed distance curve into an unmanaged copy</summary>
						/// <param name="curve">Curve to copy</param>
						static X3DAUDIO_DISTANCE_CURVE* GenerateCurveToArray(IList<DistanceSetting^>^ curve);

						/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_EMITTER</summary>
						/// <param name="emitter">Pointer to the emitter to release memory for</param>
						static void ReleaseMemory(X3DAUDIO_EMITTER** emitter);

						/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_DISTANCE_CURVE</summary>
						/// <param name="curve">Pointer to the distance curve to release memory for</param>
						static void ReleaseMemory(X3DAUDIO_DISTANCE_CURVE** curve);
					#pragma endregion
				};
			}
		}
	}
}

#endif
