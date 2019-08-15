

#ifndef Bardez_Projects_DirectX_X3DAudio_DSPSettings
#define Bardez_Projects_DirectX_X3DAudio_DSPSettings


#include <XAudio2.h>
#include <X3DAudio.h>
#include "X3DAudio Interface.h"


using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Represents the DSP (Digital Signal Processing) settings received from a 3D calculation call</summary>
				/// <remarks>
				///		The following members must be allocated (not set) before passing this structure to the <see cref="X3DAudio::CalculateAudio" /> method:
				///			* ChannelCountSource
				///			* ChannelCountDestination
				///
				///		NULLs are allowed if the corresponding computation flag(s) are unset
				///		(e.g.: CoefficientsMatrix may be null if X3DAudioCalculationFlags.Matrix is unset)
				///		Other values will not be calculated if the corresponding flags are unset.
				///	</remarks>
				public ref class DspSettings
				{
					#pragma region Fields
					protected:
						/// <summary>Matrix of volume level coefficients for source and destination channels</summary>
						/// <remarks>This must be at least <see cref="channelCountSource" /> × <see cref="channelCountDestination" /> elements long.</remarks>
						array<Single>^ coefficientsMatrix;

						/// <summary>Delay time array, which receives delays for each destination channel in milliseconds. This array must have at least <see cref="ChannelCountDestination" /> elements</summary>
						array<Single>^ delayTimes;

						/// <summary>Number of source channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
						UInt32 channelCountSource;

						/// <summary>Number of destination channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
						UInt32 channelCountDestination;

						/// <summary>LPF direct-path coefficient.</summary>
						Single coefficientLowPassFilterDirect;

						/// <summary>LPF reverb-path coefficient.</summary>
						Single coefficientLowPassFilterReverberation;

						/// <summary>Reverb send level.</summary>
						Single reverberationLevel;

						/// <summary>Doppler shift factor. Scales the resampler ratio for Doppler shift effect, where: effective_frequency = DopplerFactor × original_frequency</summary>
						Single dopplerFactor;

						/// <summary>Emitter-to-listener interior angle, expressed in radians with respect to the emitter's front orientation.</summary>
						Single emitterToListenerAngle;

						/// <summary>Distance in user-defined world units from the listener to the emitter base position.</summary>
						Single emitterToListenerDistance;

						/// <summary>Component of emitter velocity vector projected onto emitter-to-listener vector in user-defined world units per second.</summary>
						Single emitterVelocity;

						/// <summary>Component of listener velocity vector projected onto the emitter -> listener vector in user-defined world units per second.</summary>
						Single listenerVelocity;
						
						/// <summary>
						///		Pointer to data that will not be garbage collected. Used to get a pointer to the Byte Array without using
						///		Marshal to copy the data (which is unnecessarily slow). Populated in ToUnmanaged and referenced and cleared in
						///		PopulateFromUnmanaged.
						/// </summary>
						GCHandle matrixHandle;
						
						/// <summary>
						///		Pointer to data that will not be garbage collected. Used to get a pointer to the Byte Array without using
						///		Marshal to copy the data (which is unnecessarily slow). Populated in ToUnmanaged and referenced and cleared in
						///		PopulateFromUnmanaged.
						/// </summary>
						GCHandle delayHandle;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Matrix of volume level coefficients for source and destination channels</summary>
						/// <remarks>This must be at least <see cref="ChannelCountSource" /> × <see cref="ChannelCountDestination" /> elements long.</remarks>
						property array<Single>^ CoefficientsMatrix
						{
							array<Single>^ get();
							void set(array<Single>^ value);
						}

						/// <summary>Delay time array, which receives delays for each destination channel in milliseconds. This array must have at least <see cref="ChannelCountDestination" /> elements</summary>
						property array<Single>^ DelayTimes
						{
							array<Single>^ get();
							void set(array<Single>^ value);
						}

						/// <summary>Number of source channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
						property UInt32 ChannelCountSource
						{
							UInt32 get();
							void set(UInt32 value);
						}

						/// <summary>Number of destination channels. This must be initialized to the number of emitter channels before calling <see cref="X3DAudio::CalculateAudio" />.</summary>
						property UInt32 ChannelCountDestination
						{
							UInt32 get();
							void set(UInt32 value);
						}

						/// <summary>LPF direct-path coefficient.</summary>
						property Single CoefficientLowPassFilterDirect
						{
							Single get();
							void set(Single value);
						}

						/// <summary>LPF reverb-path coefficient.</summary>
						property Single CoefficientLowPassFilterReverberation
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Reverb send level.</summary>
						property Single ReverberationLevel
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Doppler shift factor. Scales the resampler ratio for Doppler shift effect, where: effective_frequency = DopplerFactor × original_frequency</summary>
						property Single DopplerFactor
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Emitter-to-listener interior angle, expressed in radians with respect to the emitter's front orientation.</summary>
						property Single EmitterToListenerAngle
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Distance in user-defined world units from the listener to the emitter base position.</summary>
						property Single EmitterToListenerDistance
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Component of emitter velocity vector projected onto emitter-to-listener vector in user-defined world units per second.</summary>
						property Single EmitterVelocity
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Component of listener velocity vector projected onto the emitter -> listener vector in user-defined world units per second.</summary>
						property Single ListenerVelocity
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Partial definition constructor</summary>
						/// <param name="sourceChannels">Number of source channels</param>
						/// <param name="destinationChannels">Number of destination channels</param>
						DspSettings(UInt32 sourceChannels, UInt32 destinationChannels);

					internal:
						/// <summary>Default constructor</summary>
						DspSettings();

						/// <summary>Constructs an instance from its unmanaged native equivalent</summary>
						static DspSettings^ FromUnmanaged(X3DAUDIO_DSP_SETTINGS* unmanaged);
					#pragma endregion



					#pragma region Destruction
					public:
						/// <summary>Destructor</summary>
						/// <remarks>Dispose()</remarks>
						~DspSettings();

						/// <summary>Destructor</summary>
						/// <remarks>Finalize()</remarks>
						!DspSettings();

					protected:
						/// <summary>Releases memory allocated for Coefficients Matrix and Delay Times arrays in unmanaged code</summary>
						void ReleaseUnmanaged();

						/// <summary>Releases the memory allocated for managed resources, such as arrays and so on</summary>
						void ReleaseManaged();
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Populates this instance from its unmanaged native equivalent</summary>
						void PopulateFromUnmanaged(X3DAUDIO_DSP_SETTINGS* unmanaged);

						/// <summary>Generates an unmanged native equivalent from this instance</summary>
						X3DAUDIO_DSP_SETTINGS* ToUnmanaged();

						/// <summary>Initializes this structure to default junk values</summary>
						void SetDefaultValues();

						/// <summary>Copies a source array of unmanaged FLOAT32 to a destination managed array of Singles</summary>
						/// <param name="source">Source to read from</param>
						/// <param name="count">Count of records to copy</param>
						/// <returns>The copied primitive array</returns>
						array<Single>^ CopyUnmanagedArray(FLOAT32* source, Int64 count);

						/// <summary>Releases up native memory allocated for this unmanaged X3DAUDIO_DSP_SETTINGS</summary>
						/// <param name="settings">Pointer to the DSP Settings to release memory for</param>
						void ReleaseMemory(X3DAUDIO_DSP_SETTINGS** settings);

					public:
						/// <summary>Generates a Coefficient Matrix for application to setting an output matrix for a voice</summary>
						/// <param name="sourceChannelCount">Number or channels in the source voice</param>
						/// <param name="destinationChannelCount">Number of channels in the destination voice</param>
						/// <returns>The matrix array, initialized to have no effect</returns>
						static array<Single>^ GenerateCoefficientMatrix(Int64 sourceChannelCount, Int64 destinationChannelCount);
					#pragma endregion
				};
			}
		}
	}
}


#endif

