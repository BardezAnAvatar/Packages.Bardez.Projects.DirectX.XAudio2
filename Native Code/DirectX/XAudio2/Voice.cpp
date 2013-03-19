

#include "Voice.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Pointer to an XAudio2MasteringVoice interface object</summary>
System::IntPtr Voice::PtrVoice::get()
{
	return this->ptrVoice;
}

/// <summary>Pointer to an XAudio2MasteringVoice interface object</summary>
void Voice::PtrVoice::set(IntPtr value)
{
	this->ptrVoice = value;
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
IXAudio2Voice* Voice::XAudio2Voice::get()
{
	return reinterpret_cast<IXAudio2Voice*>(this->ptrVoice.ToPointer());
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
void Voice::XAudio2Voice::set(IXAudio2Voice* value)
{
	this->ptrVoice = IntPtr(value);
}
					
/// <summary>The list of effects</summary>
System::Collections::Generic::List<EffectDescriptor^>^ Voice::Effects::get()
{
	return this->effects;
}
					
/// <summary>The list of effects</summary>
void Voice::Effects::set(System::Collections::Generic::List<EffectDescriptor^>^ value)
{
	this->effects = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Unmanaged constructor</summary>
/// <param name="pointer">Unmanaged parameters struct</param>
Voice::Voice(IXAudio2Voice* pointer)
{
	this->XAudio2Voice = pointer;
}
#pragma endregion
					


#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
Voice::~Voice()
{
	this->DisposeUnmanaged();
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
Voice::!Voice()
{
	this->DisposeUnmanaged();
}

/// <summary>Destructor logic, disposes the object</summary>
void Voice::DisposeUnmanaged()
{
	// Dispose this voice
	if (this->XAudio2Voice)
	{
		this->XAudio2Voice->DestroyVoice();
		this->XAudio2Voice = NULL;
	}
}
#pragma endregion


	
#pragma region Methods
/// <summary>Destroys the voice.</summary>
/// <remarks>
///		Sets the internal pointer to null. Delete the reference to this object after use.
///		
///		Stops the voice as necessar, removing it from the audio graph.
///		Waits for audio thread to be idle, so may take a few ms.
///		Violates paradigm to call from within a callback, returning XAUDIO2_E_INVALID_CALL.
/// </remarks>
void Voice::DestroyVoice()
{
	this->XAudio2Voice->DestroyVoice();
	this->ptrVoice = IntPtr::Zero;
}

/// <summary>Disables an effect at the given index in the effect chain of the voice object.</summary>
/// <param name="effectIndex">Index of the effect to disable</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>A ResultCode indicating the result of the operation</returns>
ResultCode Voice::DisableEffect(System::UInt32 effectIndex, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2Voice->DisableEffect(effectIndex, operationSet);
}

/// <summary>Enables an effect at the given index in the effect chain of the voice object.</summary>
/// <param name="effectIndex">Index of the effect to enable</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>A ResultCode indicating the result of the operation</returns>
ResultCode Voice::EnableEffect(System::UInt32 effectIndex, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2Voice->EnableEffect(effectIndex, operationSet);
}

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
array<System::Single>^ Voice::GetChannelVolumes(System::UInt32 channels)
{
	float* volumes = new float[channels];
	array<System::Single>^ outVolumes = gcnew array<System::Single>(channels);

	this->XAudio2Voice->GetChannelVolumes(channels, volumes);

	for (System::UInt32 i = 0; i < channels; ++i)
		outVolumes[i] = volumes[i];

	//I just initialized the array, and the API copied into it. Now I'm done and this should not need to be persisted.
	//delete [] volumes;

	return outVolumes;
}
					
/// <summary>Gets the effect parameters of a specified effect</summary>
/// <param name="effectIndex">Index of the effect to get the parameters of</param>
/// <param name="parameters">Output EffectParameterBase class</param>
/// <returns>A ResultCode indicating the result of the operation. E_NOTIMPL indicates no generic parameter control interface.</returns>
/// <remarks>
///		From MSDN:
///		The data in [parameters] is completely effect-specific and determined by the implementation of the IXAPOParameters::SetParameters function.
///		The data passed to SetParameters can be used to set the state of the XAPO and control the behavior of the IXAPO::Process function.
/// </remarks>
ResultCode Voice::GetEffectParameters(System::UInt32 effectIndex, [System::Runtime::InteropServices::Out] EffectParameterBase^ %parameters)
{
	parameters = nullptr;
	void* parameter = this->effects[effectIndex]->Effect->Parameters->UnmanagedReference;
	System::UInt32 size = this->effects[effectIndex]->Effect->Parameters->UnmanagedSize;

	ResultCode result = (ResultCode)this->XAudio2Voice->GetEffectParameters(effectIndex, parameter, size);

	if (result == ResultCode::Success_OK)
		parameters = this->effects[effectIndex]->Effect->Parameters->GenerateFromUnmanaged(parameter);

	return result;
}

/// <summary>Gets the state of the specified effect</summary>
/// <param name="effectIndex">Index of the effect to get the parameters of</param>
/// <returns>A Boolean indicating true if enabled, false if disabled</returns>
System::Boolean Voice::GetEffectState(System::UInt32 effectIndex)
{
	BOOL enabled;
	this->XAudio2Voice->GetEffectState(effectIndex, &enabled);
	return System::Convert::ToBoolean(enabled);
}

/// <summary>Gets the voice's parameters</summary>
/// <returns>A FilterParameter object containing filter parameter info</returns>
FilterParameter^ Voice::GetFilterParameters()
{
	XAUDIO2_FILTER_PARAMETERS parameters;
	this->XAudio2Voice->GetFilterParameters(&parameters);
	return gcnew FilterParameter(parameters);
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <returns>A FilterParameter object containing filter parameter info</returns>
FilterParameter^ Voice::GetOutputFilterParameters(Voice^ destination)
{
	XAUDIO2_FILTER_PARAMETERS parameters;
	this->XAudio2Voice->GetOutputFilterParameters(destination->XAudio2Voice, &parameters);
	return gcnew FilterParameter(parameters);
}

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
array<System::Single>^ Voice::GetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels)
{
	float* matrix = new float[sourceChannels * destinationChannels];
	this->XAudio2Voice->GetOutputMatrix(destination->XAudio2Voice, sourceChannels, destinationChannels, matrix);

	array<System::Single>^ outMatrix = gcnew array<System::Single>(sourceChannels * destinationChannels);

	// copy from unmanaged to managed
	for (System::UInt32 i = 0; i < sourceChannels * destinationChannels; ++i)
		outMatrix[i] = matrix[i];

	//I just initialized the array, and the API copied into it. Now I'm done and this should not need to be persisted.
	//delete [] matrix;

	return outMatrix;
}

/// <summary>Gets the details data of this object</summary>
/// <returns>A VoiceDetails reference to detail data</returns>
VoiceDetails^ Voice::GetVoiceDetails()
{
	XAUDIO2_VOICE_DETAILS details;
	this->XAudio2Voice->GetVoiceDetails(&details);
	return gcnew VoiceDetails(details);
}

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
System::Single Voice::GetVolume()
{
	float volume;
	this->XAudio2Voice->GetVolume(&volume);
	return volume;
}

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
ResultCode Voice::SetChannelVolumes(array<System::Single>^ volumes, System::UInt32 operationSet)
{
	float* unmanagedVol = new float[volumes->Length];
	System::Runtime::InteropServices::Marshal::Copy(volumes, 0, IntPtr(unmanagedVol), volumes->Length);
	return (ResultCode)this->XAudio2Voice->SetChannelVolumes(volumes->Length, unmanagedVol, operationSet);
}
					
/// <summary>Replaces this Voice's effect chain.</summary>
/// <param name="chain">Effect chain to be applied. Passing null will remove existing effects.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		The number of output channels is constant upon creation, and the effects must honor that number.
///		If any portion of the effect chain fails, the entire chain fails and none of it is applied.
///		After attaching an effect, the client should no longer reference it, as XAudio2 will handle it going forward.
/// </remarks>
ResultCode Voice::SetEffectChain(System::Collections::Generic::List<EffectDescriptor^>^ chain)
{
	this->effects = chain;
	ResultCode result;

	if (this->effects == nullptr)
		result = (ResultCode)this->XAudio2Voice->SetEffectChain(NULL);
	else
	{
		XAUDIO2_EFFECT_CHAIN effectChain;

		effectChain.EffectCount = this->effects->Count;
		effectChain.pEffectDescriptors = new XAUDIO2_EFFECT_DESCRIPTOR[this->effects->Count];

		//copy descriptors
		for (System::Int32 i = 0; i < this->effects->Count; ++i)
			effectChain.pEffectDescriptors[i] = this->effects[i]->ToUnmanaged();

		result = (ResultCode)this->XAudio2Voice->SetEffectChain(&effectChain);
	}

	return result;
}
					
/// <summary>Sets the parameters for  an effect in this voice's effect in the chain as specified in the index</summary>
/// <param name="effectIndex">Index within the effect chain to set parameters for</param>
/// <param name="parameters">EffectParameterBase class to set</param>
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
ResultCode Voice::SetEffectParameters(System::UInt32 effectIndex, EffectParameterBase^ parameters, System::UInt32 operationSet)
{
	void* parameter = parameters->UnmanagedReference;
	System::UInt32 size = parameters->UnmanagedSize;

	ResultCode result = (ResultCode)this->XAudio2Voice->SetEffectParameters(effectIndex, parameter, size);

	return result;
}
					
/// <summary>Sets the voice's parameters</summary>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		SetFilterParameters will fail if the voice was not created with the XAUDIO2_VOICE_USEFILTER flag.
///		This method is usable only on source and submix voices and has no effect on mastering voices.
/// </remarks>
ResultCode Voice::SetFilterParameters(FilterParameter^ parameter, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2Voice->SetFilterParameters(&(parameter->ToUnmanaged()), operationSet);
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode Voice::SetOutputFilterParameters(Voice^ destination, FilterParameter^ parameter, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2Voice->SetOutputFilterParameters(destination->XAudio2Voice, &(parameter->ToUnmanaged()), operationSet);
}
					
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
ResultCode Voice::SetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels, array<System::Single>^ volumeMatrix, System::UInt32 operationSet)
{
	float* unmanagedVol = new float[volumeMatrix->Length];
	System::Runtime::InteropServices::Marshal::Copy(volumeMatrix, 0, IntPtr(unmanagedVol), volumeMatrix->Length);

	return (ResultCode)this->XAudio2Voice->SetOutputMatrix(destination->XAudio2Voice, sourceChannels, destinationChannels, unmanagedVol, operationSet);
}

/// <summary>Designates a new set of submix or mastering Voice destinations to receive this Voice's output</summary>
/// <param name="voices">Array of set destination Voices.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>if voices is null, it is sent to the current mastering voice. To not send anywhere, set size of the array to 0.</remarks>
ResultCode Voice::SetOutputVoices(array<VoiceSendDescriptor^>^ voices)
{
	XAUDIO2_VOICE_SENDS sendList;
	sendList.SendCount = voices->Length;
	sendList.pSends = new XAUDIO2_SEND_DESCRIPTOR[voices->Length];
	
	//copy
	for (System::Int32 i = 0; i < voices->Length; ++i)
		sendList.pSends[i] = voices[i]->ToUnmanaged();

	return (ResultCode)this->XAudio2Voice->SetOutputVoices(&sendList);
}

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
ResultCode Voice::SetVolume(System::Single volume, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2Voice->SetVolume(volume, operationSet);
}
#pragma endregion

