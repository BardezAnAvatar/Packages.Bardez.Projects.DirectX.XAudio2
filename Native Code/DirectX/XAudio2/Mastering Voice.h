
#ifndef Bardez_Projects_Directx_XAudio2_MasteringVoice
#define Bardez_Projects_Directx_XAudio2_MasteringVoice

#include <XAudio2.h>
#include "Version.h"
#include "Voice.h"

using namespace System;
using namespace Bardez::Projects::BasicStructures::Win32;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Mastering Voice destiation for the Voice audio graph</summary>
				public ref class MasteringVoice : Voice
				{
				#pragma region Properties
				internal:
					/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
					property IXAudio2MasteringVoice* XAudio2MasteringVoice
					{
						IXAudio2MasteringVoice* get();
						void set(IXAudio2MasteringVoice* value);
					}
				#pragma endregion



				#pragma region Construction
				internal:
					/// <summary>Definition constructor</summary>
					/// <param name="pointer">Pointer to an XAudio2 mastering voice interface object</param>
					MasteringVoice(IXAudio2MasteringVoice* pointer);
				#pragma endregion



				#pragma region Destruction
				public:
					/// <summary>Destructor</summary>
					/// <remarks>Dispose()</remarks>
					~MasteringVoice();

					/// <summary>Destructor</summary>
					/// <remarks>Finalize()</remarks>
					!MasteringVoice();

					/// <summary>Destructor logic, disposes the object</summary>
					void DisposeUnmanaged();
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Destroys the voice.</summary>
					/// <remarks>
					///		Stops the voice as necessary, removing it from the audio graph.
					///		Waits for audio thread to be idle, so may take a few ms.
					///		Violates paradigm to call from within a callback, returning XAUDIO2_E_INVALID_CALL.
					/// </remarks>
					virtual void DestroyVoice() override;

					/// <summary>Disables an effect at the given index in the effect chain of the voice object.</summary>
					/// <param name="effectIndex">Index of the effect to disable</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>A ResultCode indicating the result of the operation</returns>
					virtual ResultCode DisableEffect(System::UInt32 effectIndex, System::UInt32 operationSet) override;

					/// <summary>Enables an effect at the given index in the effect chain of the voice object.</summary>
					/// <param name="effectIndex">Index of the effect to enable</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>A ResultCode indicating the result of the operation</returns>
					virtual ResultCode EnableEffect(System::UInt32 effectIndex, System::UInt32 operationSet) override;

					/// <summary>Gets the volume levels of this voice, per channel</summary>
					/// <param name="channels">Count of the voice's channels</param>
					/// <returns>An array of Single objects depicting </returns>
					/// <remarks>
					///		Not valid for Mastering voices. In C API, the array must be pre-initialized,
					///		and is then populated. No reason for this for the .NET API.
					///		The volumes returned are after the voice's effects are applied.
					///
					///		From MSDN:
					///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
					///		A volume of 1 means there is no attenuation or gain, 0 means silence, and negative levels can be used to invert the audio's phase.
					/// </remarks>
					virtual array<System::Single>^ GetChannelVolumes(System::UInt32 channels) override;

					/// <summary>Gets the effect parameters of a specified effect</summary>
					/// <param name="effectIndex">Index of the effect to get the parameters of</param>
					/// <param name="parameters">Output EffectParameterBase class</param>
					/// <returns>A ResultCode indicating the result of the operation. E_NOTIMPL indicates no generic parameter control interface.</returns>
					/// <remarks>
					///		From MSDN:
					///		The data in [parameters] is completely effect-specific and determined by the implementation of the IXAPOParameters::SetParameters function.
					///		The data passed to SetParameters can be used to set the state of the XAPO and control the behavior of the IXAPO::Process function.
					/// </remarks>
					virtual ResultCode GetEffectParameters(System::UInt32 effectIndex, [System::Runtime::InteropServices::Out] IEffectParameter^ %parameters) override;

					/// <summary>Gets the state of the specified effect</summary>
					/// <param name="effectIndex">Index of the effect to get the parameters of</param>
					/// <returns>A Boolean indicating true if enabled, false if disabled</returns>
					virtual System::Boolean GetEffectState(System::UInt32 effectIndex) override;

					/// <summary>Gets the voice's parameters</summary>
					/// <returns>A FilterParameter object containing filter parameter info</returns>
					virtual FilterParameter^ GetFilterParameters() override;

					/// <summary>Gets the voice's parameters</summary>
					/// <param name="destination">Destination Voice the filter will output to</param>
					/// <returns>A FilterParameter object containing filter parameter info</returns>
					virtual FilterParameter^ GetOutputFilterParameters(Voice^ destination) override;

					/// <summary>Gets the voice's volume output matrix for each channel</summary>
					/// <param name="destination">Destination Voice to get the matrix for. If null, will get matrix for this Voice.</param>
					/// <param name="sourceChannels">Number of channels of the source Voice.</param>
					/// <param name="destinationChannels">Number of channels of the destination Voice.</param>
					/// <returns>
					///		From MSDN: An array of [size: sourceChannels * destinationChannels] volume levels sent to destination.
					///		The level sent from source channel S to destination channel D is returned in the form pLevelMatrix[DestinationChannels × S + D].
					///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
					///		A volume level of 1 means there is no attenuation or gain and 0 means silence.
					/// </returns>
					/// <remarks>
					///		This method applies only to source and submix voices, because mastering voices write directly to the device with no matrix mixing.
					///	</remarks>
					virtual array<System::Single>^ GetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels) override;

					/// <summary>Gets the details data of this object</summary>
					/// <returns>A VoiceDetails reference to detail data</returns>
					virtual VoiceDetails^ GetVoiceDetails() override;

					/// <summary>Gets the overall volume level of this voice.</summary>
					/// <returns>
					///		A Single-precision floating point integer describing the volume.
					///		From MSDN:
					///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
					///		A volume level of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase.
					///	</returns>
					/// <remarks>
					///		Always returns the volume most recently set by <see cref="SetVolume" /> This value may not yet be in effect.
					/// </remarks>
					virtual System::Single GetVolume() override;

					/// <summary>Sets the volume of the voice for each channel</summary>
					/// <param name="volumes">Array of volumes for the voice.</param>
					/// <param name="operationSet">Operation set to be applied.</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		Only valid for either a source of a submix voice.
					///		From MSDN:
					///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
					///		A volume level of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase.
					/// </remarks>
					virtual ResultCode SetChannelVolumes(array<System::Single>^ volumes, System::UInt32 operationSet) override;

					/// <summary>Replaces this Voice's effect chain.</summary>
					/// <param name="chain">Effect chain to be applied. Passing null will remove existing effects.</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		The number of output channels is constant upon creation, and the effects must honor that number.
					///		If any portion of the effect chain fails, the entire chain fails and none of it is applied.
					///		After attaching an effect, the client should no longer reference it, as XAudio2 will handle it going forward.
					/// </remarks>
					virtual ResultCode SetEffectChain(System::Collections::Generic::List<EffectDescriptor^>^ chain) override;

					/// <summary>Sets the parameters for  an effect in this voice's effect in the chain as specified in the index</summary>
					/// <param name="effectIndex">Index within the effect chain to set parameters for</param>
					/// <param name="parameters">Object array of parameters to set</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		From MSDN:
					///		The specific effect being used determines the valid size and format of the pParameters buffer. The call will
					///			fail if pParameters is invalid or if ParametersByteSize is not exactly the size that the effect expects.
					///			The client must take care to direct the SetEffectParameters call to the right effect. If this call is directed
					///			to a different effect that happens to accept the same parameter block size, the parameters will be interpreted
					///			differently. This may lead to unexpected results.
					///
					///		The memory pointed to by pParameters must not be freed immediately, because XAudio2 will need to refer to it later
					///			when the parameters actually are applied to the effect. This happens during the next audio processing pass if
					///			the OperationSet argument is XAUDIO2_COMMIT_NOW. Otherwise, the parameters are applied to the effect later,
					///			during the first processing pass after the IXAudio2::CommitChanges function is called with the same
					///			OperationSet argument.
					/// </remarks>
					virtual ResultCode SetEffectParameters(System::UInt32 effectIndex, IEffectParameter^ parameters, System::UInt32 operationSet) override;

					/// <summary>Sets the voice's parameters</summary>
					/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		SetFilterParameters will fail if the voice was not created with the XAUDIO2_VOICE_USEFILTER flag.
					///		This method is usable only on source and submix voices and has no effect on mastering voices.
					/// </remarks>
					virtual ResultCode SetFilterParameters(FilterParameter^ parameter, System::UInt32 operationSet) override;

					/// <summary>Gets the voice's parameters</summary>
					/// <param name="destination">Destination Voice the filter will output to</param>
					/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					virtual ResultCode SetOutputFilterParameters(Voice^ destination, FilterParameter^ parameter, System::UInt32 operationSet) override;

					/// <summary>Sets the voice's volume output matrix for each channel</summary>
					/// <param name="destination">Destination Voice to set the matrix for. If null and only one destination, will set for that destination Voice.</param>
					/// <param name="sourceChannels">Number of channels of the source Voice.</param>
					/// <param name="destinationChannels">Number of channels of the destination Voice.</param>
					/// <param name="volumeMatrix">
					///		From MSDN: An array of [size: sourceChannels * destinationChannels] volume levels sent to destination.
					///		See for details: http://msdn.microsoft.com/en-us/library/windows/desktop/microsoft.directx_sdk.ixaudio2voice.ixaudio2voice.setoutputmatrix%28v=vs.85%29.aspx
					///	</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		The level sent from source channel S to destination channel D is returned in the form pLevelMatrix[DestinationChannels × S + D].
					///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
					///		A volume level of 1 means there is no attenuation or gain and 0 means silence.
					///		This method applies only to source and submix voices, because mastering voices write directly to the device with no matrix mixing.
					///	</remarks>
					virtual ResultCode SetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels, array<System::Single>^ volumeMatrix, System::UInt32 operationSet) override;

					/// <summary>Designates a new set of submix or mastering Voice destinations to receive this Voice's output</summary>
					/// <param name="voices">Array of set destination Voices.</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>if voices is null, it is sent to the current mastering voice. To not send anywhere, set size of the array to 0.</remarks>
					virtual ResultCode SetOutputVoices(array<VoiceSendDescriptor^>^ voices) override;

					/// <summary>Sets the voice's volume output matrix for each channel</summary>
					/// <param name="volume">Value of the oerall volume to set for this voice</param>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					/// <remarks>
					///		From MSDN:
					///		The master volume level is applied at different times depending on the type of voice. For submix and mastering voices the volume level is applied
					///			just before the voice's built in filter and effect chain is applied. For source voices the master volume level is applied after
					///			the voice's filter and effect chain is applied.
					///		Volume levels are expressed as floating-point amplitude multipliers between -XAUDIO2_MAX_VOLUME_LEVEL and XAUDIO2_MAX_VOLUME_LEVEL (-224 to 224),
					///			with a maximum gain of 144.5 dB. A volume level of 1.0 means there is no attenuation or gain and 0 means silence.
					///			Negative levels can be used to invert the audio's phase.
					/// </remarks>
					virtual ResultCode SetVolume(System::Single volume, System::UInt32 operationSet) override;

#if _XAUDIO2_VERSION_ >= 8
					/// <summary>Gets this voice's channel mask</summary>
					/// <returns>The channel mask, which correlates to the Wave Format Extensible's channelMask member</returns>
					/// <remarks>This method was introduced in XAudio2 version 2.8</remarks>
					System::UInt32 GetChannelMask();
#endif
				#pragma endregion
				};
			}
		}
	}
}

#endif

