

#include "Mastering Voice.h"

using namespace Bardez::Projects::DirectX::XAudio2;

#pragma region Properties
/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
IXAudio2MasteringVoice* MasteringVoice::XAudio2MasteringVoice::get()
{
	return reinterpret_cast<IXAudio2MasteringVoice*>(this->ptrVoice.ToPointer());
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
void MasteringVoice::XAudio2MasteringVoice::set(IXAudio2MasteringVoice* value)
{
	this->ptrVoice = System::IntPtr(value);
}
#pragma endregion
					


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="pointer">Pointer to an XAudio2 mastering voice interface object</param>
MasteringVoice::MasteringVoice(IXAudio2MasteringVoice* pointer)
{
	this->XAudio2MasteringVoice = pointer;
}
#pragma endregion
					


#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
MasteringVoice::~MasteringVoice()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
MasteringVoice::!MasteringVoice()
{
	this->DisposeUnmanaged();
}
#pragma endregion


	
#pragma region Methods
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
array<System::Single>^ MasteringVoice::GetChannelVolumes(System::UInt32 channels)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <returns>A FilterParameter object containing filter parameter info</returns>
FilterParameter^ MasteringVoice::GetOutputFilterParameters(Voice^ destination)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
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
array<System::Single>^ MasteringVoice::GetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
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
ResultCode MasteringVoice::SetChannelVolumes(array<System::Single>^ volumes, System::UInt32 operationSet)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
}

/// <summary>Sets the voice's parameters</summary>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>
///		SetFilterParameters will fail if the voice was not created with the XAUDIO2_VOICE_USEFILTER flag.
///		This method is usable only on source and submix voices and has no effect on mastering voices.
/// </remarks>
ResultCode MasteringVoice::SetFilterParameters(FilterParameter^ parameter, System::UInt32 operationSet)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
}

/// <summary>Gets the voice's parameters</summary>
/// <param name="destination">Destination Voice the filter will output to</param>
/// <param name="parameter">A FilterParameter object containing filter parameter info</param>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode MasteringVoice::SetOutputFilterParameters(Voice^ destination, FilterParameter^ parameter, System::UInt32 operationSet)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
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
ResultCode MasteringVoice::SetOutputMatrix(Voice^ destination, System::UInt32 sourceChannels, System::UInt32 destinationChannels, array<System::Single>^ volumeMatrix, System::UInt32 operationSet)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
}

/// <summary>Designates a new set of submix or mastering Voice destinations to receive this Voice's output</summary>
/// <param name="voices">Array of set destination Voices.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
/// <remarks>if voices is null, it is sent to the current mastering voice. To not send anywhere, set size of the array to 0.</remarks>
ResultCode MasteringVoice::SetOutputVoices(array<VoiceSendDescriptor^>^ voices)
{
	throw gcnew InvalidOperationException("This action is not valid for mastering voices.");
}

#if _XAUDIO2_VERSION_ >= 8
/// <summary>Gets this voice's channel mask</summary>
/// <returns>The channel mask</returns>
/// <remarks>This correlates to the Wave Format Extensible's channelMask member</remarks>
System::UInt32 MasteringVoice::GetChannelMask()
{
	DWORD mask;
	this->XAudio2MasteringVoice->GetChannelMask(&mask);
	return mask;
}
#endif
#pragma endregion

