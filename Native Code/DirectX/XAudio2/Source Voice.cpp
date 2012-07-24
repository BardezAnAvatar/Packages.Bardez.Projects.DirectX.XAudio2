
#include "Source Voice.h"

using namespace Bardez::Projects::DirectX::XAudio2;

#pragma region Properties
/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
IXAudio2SourceVoice* SourceVoice::XAudio2SourceVoice::get()
{
	return reinterpret_cast<IXAudio2SourceVoice*>(this->ptrVoice.ToPointer());
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
void SourceVoice::XAudio2SourceVoice::set(IXAudio2SourceVoice* value)
{
	this->ptrVoice = System::IntPtr(value);
}

/// <summary>Reference to the voice callback object for this source voice</summary>
VoiceCallback^ SourceVoice::Callback::get()
{
	return this->callback;
}

/// <summary>Reference to the voice callback object for this source voice</summary>
/// <param name="value">Instance to reference</param>
void SourceVoice::Callback::set(VoiceCallback^ value)
{
	this->callback = value;
}
#pragma endregion
					


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="pointer">Pointer to an XAudio2 source voice interface object</param>
/// <param name="callback">Callback instance to reference</param>
SourceVoice::SourceVoice(IXAudio2SourceVoice* pointer, VoiceCallback^ callback)
{
	this->XAudio2SourceVoice = pointer;
	this->callback = callback;
}
#pragma endregion



#pragma region Destruction
/// <summary>Destrutor</summary>
/// <remarks>Dispose()</remarks>
SourceVoice::~SourceVoice()
{
	this->DisposeUnmanaged();
}

/// <summary>Destrutor</summary>
/// <remarks>Finalize()</remarks>
SourceVoice::!SourceVoice()
{
	this->DisposeUnmanaged();
}

/// <summary>Destrutor logic, disposes the object</summary>
void SourceVoice::DisposeUnmanaged()
{
	// Dispose this voice
	if (this->XAudio2SourceVoice)
	{
		this->XAudio2SourceVoice->DestroyVoice();
		this->XAudio2SourceVoice = NULL;
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
void SourceVoice::DestroyVoice()
{
	this->XAudio2SourceVoice->DestroyVoice();
	this->ptrVoice = IntPtr::Zero;
}

/// <summary>Disables an effect at the given index in the effect chain of the voice object.</summary>
/// <param name="effectIndex">Index of the effect to disable</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>A ResultCode indicating the result of the operation</returns>
ResultCode SourceVoice::DisableEffect(System::UInt32 effectIndex, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->DisableEffect(effectIndex, operationSet);
}

/// <summary>Enables an effect at the given index in the effect chain of the voice object.</summary>
/// <param name="effectIndex">Index of the effect to enable</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>A ResultCode indicating the result of the operation</returns>
ResultCode SourceVoice::EnableEffect(System::UInt32 effectIndex, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->EnableEffect(effectIndex, operationSet);
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
array<System::Single>^ SourceVoice::GetChannelVolumes(System::UInt32 channels)
{
	float* volumes = new float[channels];
	array<System::Single>^ outVolumes = gcnew array<System::Single>(channels);

	this->XAudio2SourceVoice->GetChannelVolumes(channels, volumes);

	for (System::UInt32 i = 0; i < channels; ++i)
		outVolumes[i] = volumes[i];

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
ResultCode SourceVoice::GetEffectParameters(System::UInt32 effectIndex, [System::Runtime::InteropServices::Out] EffectParameterBase^ %parameters)
{
	parameters = nullptr;
	void* parameter = this->effects[effectIndex]->Effect->Parameters->UnmanagedReference;
	System::UInt32 size = this->effects[effectIndex]->Effect->Parameters->UnmanagedSize;

	ResultCode result = (ResultCode)this->XAudio2SourceVoice->GetEffectParameters(effectIndex, parameter, size);

	if (result == ResultCode::Success_OK)
		parameters = this->effects[effectIndex]->Effect->Parameters->GenerateFromUnmanaged(parameter);

	return result;
}

/// <summary>Gets the state of the specified effect</summary>
/// <param name="effectIndex">Index of the effect to get the parameters of</param>
/// <returns>A Boolean indicating true if enabled, false if disabled</returns>
System::Boolean SourceVoice::GetEffectState(System::UInt32 effectIndex)
{
	BOOL enabled;
	this->XAudio2SourceVoice->GetEffectState(effectIndex, &enabled);
	return System::Convert::ToBoolean(enabled);
}

/// <summary>Gets the voice's parameters</summary>
/// <returns>A FilterParameter object containing filter parameter info</returns>
FilterParameter^ SourceVoice::GetFilterParameters()
{
	XAUDIO2_FILTER_PARAMETERS parameters;
	this->XAudio2SourceVoice->GetFilterParameters(&parameters);
	return gcnew FilterParameter(parameters);
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <returns>A FilterParameter object containing filter parameter info</returns>
FilterParameter^ SourceVoice::GetOutputFilterParameters(Voice^ destination)
{
	XAUDIO2_FILTER_PARAMETERS parameters;
	this->XAudio2SourceVoice->GetOutputFilterParameters(destination->XAudio2Voice, &parameters);
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
///		This method applies only to source and Source voices, because mastering voices write directly to the device with no matrix mixing.
///	</remarks>
array<System::Single>^ SourceVoice::GetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels)
{
	float* matrix = new float[sourceChannels * destinationChannels];
	this->XAudio2SourceVoice->GetOutputMatrix(destination->XAudio2Voice, sourceChannels, destinationChannels, matrix);

	array<System::Single>^ outMatrix = gcnew array<System::Single>(sourceChannels * destinationChannels);

	// copy from unmanaged to managed
	for (System::UInt32 i = 0; i < sourceChannels * destinationChannels; ++i)
		outMatrix[i] = matrix[i];

	return outMatrix;
}

/// <summary>Gets the details data of this object</summary>
/// <returns>A VoiceDetails reference to detail data</returns>
VoiceDetails^ SourceVoice::GetVoiceDetails()
{
	XAUDIO2_VOICE_DETAILS details;
	this->XAudio2SourceVoice->GetVoiceDetails(&details);
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
System::Single SourceVoice::GetVolume()
{
	float volume;
	this->XAudio2SourceVoice->GetVolume(&volume);
	return volume;
}

/// <summary>Sets the volume of the voice for each channel</summary>
/// <param name="volumes">Array of volumes for the voice.</param>
/// <param name="operationSet">Operation set to be applied.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		Only valid for either a source of a Source voice.
///		From MSDN:
///		Volume levels are expressed as floating-point amplitude multipliers between -224 to 224, with a maximum gain of 144.5 dB.
///		A volume level of 1 means there is no attenuation or gain and 0 means silence. Negative levels can be used to invert the audio's phase.
/// </remarks>
ResultCode SourceVoice::SetChannelVolumes(array<System::Single>^ volumes, System::UInt32 operationSet)
{
	float* unmanagedVol = new float[volumes->Length];
	System::Runtime::InteropServices::Marshal::Copy(volumes, 0, IntPtr(unmanagedVol), volumes->Length);
	return (ResultCode)this->XAudio2SourceVoice->SetChannelVolumes(volumes->Length, unmanagedVol, operationSet);
}
					
/// <summary>Replaces this Voice's effect chain.</summary>
/// <param name="chain">Effect chain to be applied. Passing null will remove existing effects.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		The number of output channels is constant upon creation, and the effects must honor that number.
///		If any portion of the effect chain fails, the entire chain fails and none of it is applied.
///		After attaching an effect, the client should no longer reference it, as XAudio2 will handle it going forward.
/// </remarks>
ResultCode SourceVoice::SetEffectChain(System::Collections::Generic::List<EffectDescriptor^>^ chain)
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

		result = (ResultCode)this->XAudio2SourceVoice->SetEffectChain(&effectChain);
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
ResultCode SourceVoice::SetEffectParameters(System::UInt32 effectIndex, EffectParameterBase^ parameters, System::UInt32 operationSet)
{
	void* parameter = parameters->UnmanagedReference;
	System::UInt32 size = parameters->UnmanagedSize;

	ResultCode result = (ResultCode)this->XAudio2SourceVoice->SetEffectParameters(effectIndex, parameter, size);

	return result;
}
					
/// <summary>Sets the voice's parameters</summary>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		SetFilterParameters will fail if the voice was not created with the XAUDIO2_VOICE_USEFILTER flag.
///		This method is usable only on source and Source voices and has no effect on mastering voices.
/// </remarks>
ResultCode SourceVoice::SetFilterParameters(FilterParameter^ parameter, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->SetFilterParameters(&(parameter->ToUnmanaged()), operationSet);
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::SetOutputFilterParameters(Voice^ destination, FilterParameter^ parameter, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->SetOutputFilterParameters(destination->XAudio2Voice, &(parameter->ToUnmanaged()), operationSet);
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
///		This method applies only to source and Source voices, because mastering voices write directly to the device with no matrix mixing.
///	</remarks>
ResultCode SourceVoice::SetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels, array<System::Single>^ volumeMatrix, System::UInt32 operationSet)
{
	float* unmanagedVol = new float[volumeMatrix->Length];
	System::Runtime::InteropServices::Marshal::Copy(volumeMatrix, 0, IntPtr(unmanagedVol), volumeMatrix->Length);

	return (ResultCode)this->XAudio2SourceVoice->SetOutputMatrix(destination->XAudio2Voice, sourceChannels, destinationChannels, unmanagedVol, operationSet);
}

/// <summary>Designates a new set of Submix or Mastering Voice destinations to receive this Voice's output</summary>
/// <param name="voices">Array of set destination Voices.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>if voices is null, it is sent to the current mastering voice. To not send anywhere, set size of the array to 0.</remarks>
ResultCode SourceVoice::SetOutputVoices(array<VoiceSendDescriptor^>^ voices)
{
	XAUDIO2_VOICE_SENDS sendList;
	sendList.SendCount = voices->Length;
	sendList.pSends = new XAUDIO2_SEND_DESCRIPTOR[voices->Length];
	
	//copy
	for (System::Int32 i = 0; i < voices->Length; ++i)
		sendList.pSends[i] = voices[i]->ToUnmanaged();

	return (ResultCode)this->XAudio2SourceVoice->SetOutputVoices(&sendList);
}

/// <summary>Sets the voice's volume output matrix for each channel</summary>
/// <param name="volume">Value of the oerall volume to set for this voice</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		From MSDN:
///		The master volume level is applied at different times depending on the type of voice. For Source and mastering voices the volume level is applied
///			just before the voice's built in filter and effect chain is applied. For source voices the master volume level is applied after
///			the voice's filter and effect chain is applied.
///		Volume levels are expressed as floating-point amplitude multipliers between -XAUDIO2_MAX_VOLUME_LEVEL and XAUDIO2_MAX_VOLUME_LEVEL (-224 to 224),
///			with a maximum gain of 144.5 dB. A volume level of 1.0 means there is no attenuation or gain and 0 means silence.
///			Negative levels can be used to invert the audio's phase.
/// </remarks>
ResultCode SourceVoice::SetVolume(System::Single volume, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->SetVolume(volume, operationSet);
}

/// <summary>Notifies a voice that no more buffers are coming after the last one that is currently in its queue.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Discontinuity()
{
	return (ResultCode)this->XAudio2SourceVoice->Discontinuity();
}

/// <summary>Stops looping this voice when it reaches the end of the current loop.</summary>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::ExitLoop(System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->ExitLoop(operationSet);
}

/// <summary>Removes all pending audio buffers from this voice's queue.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::FlushSourceBuffers()
{
	return (ResultCode)this->XAudio2SourceVoice->FlushSourceBuffers();
}

/// <summary>Gets the frequency adjustment ratio of this voice.</summary>
/// <returns>The frequency adjustment ratio</returns>
System::Single SourceVoice::GetFrequencyRatio()
{
	float ratio;
	this->XAudio2SourceVoice->GetFrequencyRatio(&ratio);
	return ratio;
}

/// <summary>Gets this voice's current cursor position data.</summary>
/// <returns>A reference to the state of this voice</returns>
/// <remarks>
///		If a client needs to obtain the correlated positions of several voices
///		(i.e. to know exactly which sample of a given voice is playing when a given sample of another voice is playing)
///		it must make GetState calls in an XAudio2 engine callback, to ensure that none of the voices advance while the calls are being made.
///		See the XAudio2 Callbacks overview for information about using XAudio2 callbacks.
/// </remarks>
VoiceState^ SourceVoice::GetState()
{
	XAUDIO2_VOICE_STATE voiceState;

	this->XAudio2SourceVoice->GetState(&voiceState);

	return gcnew VoiceState(voiceState);
}

/// <summary>Sets the frequency adjustment ratio of this voice</summary>
/// <param name="ratio">Frequenct adjustment ratio to set</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::SetFrequencyRatio(System::Single ratio, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->SetFrequencyRatio(ratio, operationSet);
}

/// <summary>Sets the source data sample rate</summary>
/// <param name="sampleRate">New sample rate</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::SetSourceSampleRate(System::UInt32 sampleRate)
{
	return (ResultCode)this->XAudio2SourceVoice->SetSourceSampleRate(sampleRate);
}

/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Start(System::UInt32 flags, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->Start(flags, operationSet);
}

/// <summary>Starts consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Start()
{
	return (ResultCode)this->Start(0, XAUDIO2_COMMIT_NOW);
}

/// <summary>Stops consumption and processing of audio by this voice. Delivers the result to any connected submix or mastering voices, or to the output device.</summary>
/// <param name="flags">Flags that control how the voice is started. Must be 0.</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode SourceVoice::Stop(System::UInt32 flags, System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2SourceVoice->Stop(flags, operationSet);
}


/// <summary>Submits a data buffer to XAudio2</summary>
/// <param name="buffer">Audio buffer details &amp; data</param>
/// <param name="bufferWma">Additional buffer data for WMA streams. Nullable if PCM data.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		The voice processes and plays back the buffers in its queue in the order that they were submitted.
///		If the voice is started and has no buffers queued, the new buffer will start playing immediately.
///		If the voice is stopped, the buffer is added to the voice's queue and will be played when the voice starts.
///		If an explicit play region is specified, it must begin and end within the given audio buffer (or, in the compressed case, within the set of
///		samples that the buffer will decode to). In addition, the loop region cannot end past the end of the play region.
/// </remarks>
ResultCode SourceVoice::SubmitSourceBuffer(Bardez::Projects::DirectX::XAudio2::AudioBuffer^ buffer, WmaBuffer^ bufferWma)
{
	XAUDIO2_BUFFER nativeBuffer = buffer->ToUnmanaged();
	XAUDIO2_BUFFER_WMA* nativeWmaBuffer = NULL;
	
	if (bufferWma != nullptr)
		nativeWmaBuffer = &(bufferWma->ToUnmanaged());

	return (ResultCode)this->XAudio2SourceVoice->SubmitSourceBuffer(&nativeBuffer, nativeWmaBuffer);
}

#pragma endregion