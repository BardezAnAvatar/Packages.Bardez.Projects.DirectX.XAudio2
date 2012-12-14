
#ifndef Bardez_Projects_DirectX_X3DAudioCalculationFlags
#define Bardez_Projects_DirectX_X3DAudioCalculationFlags


#include <XAudio2.h>
#include <X3DAudio.h>

using namespace System;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>CLR-exposed enumerator describing flags for calculating 3D audio effects</summary>
				public enum struct X3DAudioCalculationFlags : UInt32
				{
					/// <summary>Enables matrix coefficient table calculation.</summary>
					Matrix							= X3DAUDIO_CALCULATE_MATRIX,

					/// <summary>Enables delay time array calculation (stereo only).</summary>
					Delay							= X3DAUDIO_CALCULATE_DELAY,

					/// <summary>Enables low pass filter (LPF) direct-path coefficient calculation.</summary>
					LowPassFilterDirect				= X3DAUDIO_CALCULATE_LPF_DIRECT,

					/// <summary>Enables LPF reverb-path coefficient calculation.</summary>
					LowPassFilterReverberation		= X3DAUDIO_CALCULATE_LPF_REVERB,

					/// <summary>Enables reverb send level calculation.</summary>
					Reverberation					= X3DAUDIO_CALCULATE_REVERB,

					/// <summary>Enables Doppler shift factor calculation.</summary>
					Doppler							= X3DAUDIO_CALCULATE_DOPPLER,

					/// <summary>Enables emitter-to-listener interior angle calculation.</summary>
					EmitterAngle					= X3DAUDIO_CALCULATE_EMITTER_ANGLE,

					/// <summary>
					///		Fills the center channel with silence. This flag allows you to keep a 6-channel matrix so you
					///		do not have to remap the channels, but the center channel will be silent.
					///		This flag is only valid if you also set X3DAUDIO_CALCULATE_MATRIX.
					/// </summary>
					ZeroCenter						= X3DAUDIO_CALCULATE_ZEROCENTER,

					/// <summary>
					///		Applies an equal mix of all source channels to a low frequency effect (LFE) destination channel.
					///		It only applies to matrix calculations with a source that does not have an LFE channel
					///		and a destination that does have an LFE channel. This flag is only valid if you also set
					///		X3DAUDIO_CALCULATE_MATRIX.
					/// </summary>
					RedirectToLowFrequencyEffect	= X3DAUDIO_CALCULATE_REDIRECT_TO_LFE,
				};
			}
		}
	}
}

#endif

