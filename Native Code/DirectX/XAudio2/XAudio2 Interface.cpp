
#include "Unmanaged Engine Callback Base.h"
#include "Unmanaged Voice Callback Base.h"
#include "XAudio2 Interface.h"
#include "Wave Format Ex API Converter.h"
#include "Wave Format Extensible API Converter.h"

//used to force the linker to link to the correct library
#pragma comment(lib, "ole32.lib") //for CoInitializeEX, CoCreateInstance

using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Pointer to an XAudio2 interface object</summary>
System::IntPtr XAudio2Interface::PtrXAudio2::get()
{
	return this->ptrXAudio2;
}

/// <summary>Pointer to an XAudio2 interface object</summary>
void XAudio2Interface::PtrXAudio2::set(System::IntPtr value)
{
	this->ptrXAudio2 = value;
}

/// <summary>Property to access the XAudio pointer, wrapping to a .NET IntPtr</summary>
IXAudio2* XAudio2Interface::XAudio2::get()
{
	return reinterpret_cast<IXAudio2*>(this->ptrXAudio2.ToPointer());
}

/// <summary>Property to access the XAudio pointer, wrapping to a .NET IntPtr</summary>
void XAudio2Interface::XAudio2::set(IXAudio2* value)
{
	this->ptrXAudio2 = IntPtr(value);
}
#pragma endregion



#pragma region Construction
/// <summary>Default construtor</summary>
XAudio2Interface::XAudio2Interface()
{
	this->XAudio2 = NULL;
}
#pragma endregion



#pragma region Destruction
/// <summary>Destrutor</summary>
/// <remarks>Dispose()</remarks>
XAudio2Interface::~XAudio2Interface()
{
	this->DisposeUnmanaged();
}

/// <summary>Destrutor</summary>
/// <remarks>Finalize()</remarks>
XAudio2Interface::!XAudio2Interface()
{
	this->DisposeUnmanaged();
}

/// <summary>Destrutor logic, disposes the object</summary>
/// <remarks>There are only managed references, so either Finalize or Dispose would be calling</remarks>
void XAudio2Interface::DisposeUnmanaged()
{
	// Dispose the XAudio2 interface
	if (this->XAudio2)
	{
		this->XAudio2->Release();
		this->XAudio2 = NULL;
        CoUninitialize();
	}
}
#pragma endregion



#pragma region Methods
/// <summary>Creates &amp; initializes the XAudio2 Interface</summary>
/// <returns>A new XAudio2Interface object instance</returns>
XAudio2Interface^ XAudio2Interface::NewInstance()
{
	XAudio2Interface^ newInstance = gcnew XAudio2Interface();

	#ifndef _XBOX
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	#endif
	
	//Initialize XAudio2 pointer
	IXAudio2* ptr = newInstance->XAudio2;

	HRESULT result;

	//write a new address to the pointer
	if (FAILED( result = XAudio2Create(&ptr, 0, XAUDIO2_DEFAULT_PROCESSOR) ) )
		throw gcnew System::Exception(System::String::Concat("Error instantiating the XAudio2 interface: ", ((ResultCode)result).ToString()));
	else
		newInstance->XAudio2 = ptr;

	return newInstance;
}
					
/// <summary>Applies the set of operation identified with operationSet</summary>
/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CommitChanges(System::UInt32 operationSet)
{
	return (ResultCode)this->XAudio2->CommitChanges(operationSet);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	IXAudio2MasteringVoice* ptr;
	XAUDIO2_EFFECT_CHAIN* chain = GetEffectChain(effectChain);	//static method

	ResultCode result = (ResultCode)this->XAudio2->CreateMasteringVoice(&ptr, channels, sampleRate, flags, deviceIndex, chain);
	masteringVoice = gcnew MasteringVoice(ptr);

	return result;
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex)
{
	return this->CreateMasteringVoice(masteringVoice, channels, sampleRate, flags, deviceIndex, nullptr);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags)
{
	return this->CreateMasteringVoice(masteringVoice, channels, sampleRate, flags, 0);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate)
{
	return this->CreateMasteringVoice(masteringVoice, channels, sampleRate, 0);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels)
{
	return this->CreateMasteringVoice(masteringVoice, channels, XAUDIO2_DEFAULT_SAMPLERATE /* 0 */);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="masteringVoice">Mastering voice reference to assign</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateMasteringVoice(MasteringVoice^% masteringVoice)
{
	return this->CreateMasteringVoice(masteringVoice, XAUDIO2_DEFAULT_CHANNELS /* 0 */);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	MasteringVoice^ voice = nullptr;
	this->CreateMasteringVoice(voice, channels, sampleRate, flags, deviceIndex, effectChain);
	return voice;
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex)
{
	return this->CreateMasteringVoice(channels, sampleRate, flags, deviceIndex, nullptr);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags)
{
	return this->CreateMasteringVoice(channels, sampleRate, flags, 0);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate)
{
	return this->CreateMasteringVoice(channels, sampleRate, 0);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice(System::UInt32 channels)
{
	return this->CreateMasteringVoice(channels, XAUDIO2_DEFAULT_SAMPLERATE /* 0 */);
}

/// <summary>Crates a mastering voice associated with this instance of XAudio2</summary>
/// <returns>A new Mastering voice reference.</returns>
MasteringVoice^ XAudio2Interface::CreateMasteringVoice()
{
	return this->CreateMasteringVoice(XAUDIO2_DEFAULT_CHANNELS /* 0 */);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <param name="sends">List of voices to output to</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	IXAudio2SourceVoice* ptr = NULL;
	XAUDIO2_EFFECT_CHAIN* chain = GetEffectChain(effectChain);	//static method
	XAUDIO2_VOICE_SENDS* output = GetVoiceSends(sends);			//static method
	WAVEFORMATEX sourceFormat = WaveFormatExWin32Converter::To_WAVEFORMATEX(format);
	IXAudio2VoiceCallback* voiceCallback = NULL;

	if (callback != nullptr)
	{
		voiceCallback = new UnmanagedVoiceCallbackBase(callback);
		callback->CallbackPointer = System::IntPtr(voiceCallback);
	}

#pragma region decprecated code
	/*
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(&ptr, &sourceFormat, flags, freqRatio, voiceCallback, output, chain);
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(&ptr, &sourceFormat, 0, 2.0f, NULL, NULL, NULL);

	//pin_ptr<IXAudio2SourceVoice*> source = &ptr;
	//pin_ptr<WAVEFORMATEX> wave = &sourceFormat;
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(source, wave, 0, 2.0f, NULL, NULL, NULL);
	
	//pin_ptr<IXAudio2SourceVoice*> source = &ptr;
	//WAVEFORMATEX wave = {0};
	//wave.wBitsPerSample = 16;
	//wave.cbSize = 22;
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(source, &wave, 0, 2.0f, NULL, NULL, NULL);
	
	//OMG, THIS WORKS. IT WAS THE DEREFERENCE that was ghey@
	
	//IXAudio2SourceVoice* ptrTop = NULL;
	//IXAudio2SourceVoice** ptrSrc = &ptrTop;
	//WAVEFORMATEX* wave = new WAVEFORMATEX;
	//wave->cbSize = 16;
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(ptrSrc, wave);
	*/

	//WAVEFORMATEX* wave = new WAVEFORMATEX;

	//////copy from format unmanaged
	//wave->wFormatTag = sourceFormat.wFormatTag;
	//wave->nChannels = sourceFormat.nChannels;
	//wave->nSamplesPerSec = sourceFormat.nSamplesPerSec;
	//wave->nAvgBytesPerSec = sourceFormat.nAvgBytesPerSec;
	//wave->nBlockAlign = sourceFormat.nBlockAlign;
	//wave->wBitsPerSample = sourceFormat.wBitsPerSample;
	//wave->cbSize = sourceFormat.cbSize;

	////works less badly, at least, if no copy
	//ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(&ptr, wave);
#pragma endregion
	
	ResultCode result = (ResultCode)this->XAudio2->CreateSourceVoice(&ptr, &sourceFormat, flags, freqRatio, voiceCallback, output, chain);
	sourceVoice = gcnew SourceVoice(ptr);
	return result;
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <param name="sends">List of voices to output to</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends)
{
	return this->CreateSourceVoice(sourceVoice, format, flags, freqRatio, callback, sends, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback)
{
	return this->CreateSourceVoice(sourceVoice, format, flags, freqRatio, callback, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the source voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio)
{
	return this->CreateSourceVoice(sourceVoice, format, flags, freqRatio, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags)
{
	return this->CreateSourceVoice(sourceVoice, format, flags, XAUDIO2_DEFAULT_FREQ_RATIO /* 2.0f */);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="sourceVoice">Source voice reference to assign</param>
/// <param name="format">Format of the source voice data</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format)
{
	return this->CreateSourceVoice(sourceVoice, format, 0);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <param name="sends">List of voices to output to</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	SourceVoice^ voice;
	this->CreateSourceVoice(voice, format, flags, freqRatio, callback, sends, effectChain);
	return voice;
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <param name="sends">List of voices to output to</param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends)
{
	return this->CreateSourceVoice(format, flags, freqRatio, callback, sends, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <param name="callback">Client-defined callback interface</param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback)
{
	return this->CreateSourceVoice(format, flags, freqRatio, callback, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the source voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <param name="freqRatio">
///		Highest allowabe frequency ratio that can be set for this voice. Must be between XAUDIO2_MIN_FREQ_RATIO (1/1024.0f) and XAUDIO2_MAX_FREQ_RATIO (1024.0f).
///		Default is XAUDIO2_DEFAULT_FREQ_RATIO (2.0f).
///	</param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio)
{
	return this->CreateSourceVoice(format, flags, freqRatio, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <param name="flags">
///		Flags that specify behavior of the mastering voice.
///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
/// </param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags)
{
	return this->CreateSourceVoice(format, flags, XAUDIO2_DEFAULT_FREQ_RATIO /* 2.0f */);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="format">Format of the source voice data</param>
/// <returns>A new Source voice reference.</returns>
SourceVoice^ XAudio2Interface::CreateSourceVoice(WaveFormatEx^ format)
{
	return this->CreateSourceVoice(format, 0);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="submixVoice">Submix voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <param name="sends">List of voices to output to</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	IXAudio2SubmixVoice* ptr;
	XAUDIO2_EFFECT_CHAIN* chain = GetEffectChain(effectChain);	//static method
	XAUDIO2_VOICE_SENDS* output = GetVoiceSends(sends);			//static method

	ResultCode result = (ResultCode)this->XAudio2->CreateSubmixVoice(&ptr, channels, sampleRate, flags, stage, output, chain);
	submixVoice = gcnew SubmixVoice(ptr);

	return result;
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="submixVoice">Submix voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <param name="sends">List of voices to output to</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends)
{
	return this->CreateSubmixVoice(submixVoice, channels, sampleRate, flags, stage, sends, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="submixVoice">Submix voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage)
{
	return this->CreateSubmixVoice(submixVoice, channels, sampleRate, flags, stage, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="submixVoice">Submix voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags)
{
	return this->CreateSubmixVoice(submixVoice, channels, sampleRate, flags, 0);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="submixVoice">Submix voice reference to assign</param>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate)
{
	return this->CreateSubmixVoice(submixVoice, channels, sampleRate, 0);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <param name="sends">List of voices to output to</param>
/// <param name="effectChain">List of effects for the mastering voice</param>
/// <returns>A new Submix voice reference.</returns>
SubmixVoice^ XAudio2Interface::CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends, System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	SubmixVoice^ voice;
	this->CreateSubmixVoice(voice, channels, sampleRate, flags, stage, sends, effectChain);
	return voice;
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <param name="sends">List of voices to output to</param>
/// <returns>A new Submix voice reference.</returns>
SubmixVoice^ XAudio2Interface::CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::List<VoiceSendDescriptor^>^ sends)
{
	return this->CreateSubmixVoice(channels, sampleRate, flags, stage, sends, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <param name="stage">
///		Arbitrary number specifying when this voice is processed, in respect to other submix voices.
///		Less is earlier. Ones equal are processed in order. Cannot output to a submix voice of lesser stage.
///		Note: this would apear to be used by a branching output.
///	</param>
/// <returns>A new Submix voice reference.</returns>
SubmixVoice^ XAudio2Interface::CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage)
{
	return this->CreateSubmixVoice(channels, sampleRate, flags, stage, nullptr);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <param name="flags">
///		Flags that specify behavior of the submix voice.
///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
/// </param>
/// <returns>A new Submix voice reference.</returns>
SubmixVoice^ XAudio2Interface::CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags)
{
	return this->CreateSubmixVoice(channels, sampleRate, flags, 0);
}

/// <summary>Crates a Source voice associated with this instance of XAudio2</summary>
/// <param name="channels">Number of input channels</param>
/// <param name="sampleRate">Input sample rate</param>
/// <returns>A new Submix voice reference.</returns>
SubmixVoice^ XAudio2Interface::CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate)
{
	return this->CreateSubmixVoice(channels, sampleRate, 0);
}

#if _XAUDIO2_VERSION_ < 8
/// <summary>Gets the device count from XAudio2</summary>
/// <returns>A UInt32 describing the number of audio devices</returns>
System::UInt32 XAudio2Interface::GetDeviceCount()
{
	UINT32 count;
	//pin_ptr<UINT32> ptrCount = &count;

	if (this->XAudio2)
		this->XAudio2->GetDeviceCount(&count);

	System::UInt32 clrCount = count;

	return clrCount;
}

/// <summary>Gets the device details from XAudio2</summary>
/// <param name="index">Index of the device to be described</param>
/// <returns>A reference to a DeviceDetails instance describing the audio device</returns>
DeviceDetails^ XAudio2Interface::GetDeviceDetails(System::UInt32 index)
{
	DeviceDetails^ detail = nullptr;
	XAUDIO2_DEVICE_DETAILS details;

	if (this->XAudio2)
	{
		this->XAudio2->GetDeviceDetails(index, &details);

		detail = gcnew DeviceDetails();
		detail->DeviceId = gcnew String(details.DeviceID);
		detail->DisplayName = gcnew String(details.DisplayName);
		detail->Device_Role = (DeviceRole)details.Role;
		detail->OutputFormat = WaveFormatExtensibleWin32Converter::BuildWaveFormatExtensible(details.OutputFormat);
	}

	return detail;
}
#endif

/// <summary>Gets the current resource usage detailed data</summary>
/// <returns>The performance info inside a data structure</returns>
PerformanceData^ XAudio2Interface::GetPerformanceData()
{
	XAUDIO2_PERFORMANCE_DATA data;
	this->XAudio2->GetPerformanceData(&data);
	return gcnew PerformanceData(data);
}

/// <summary>Initializes the XAudio2 object</summary>
/// <param name="flags">Flags indicating behavior. Must be 0.</param>
/// <param name="processor">Processor to run this instance on</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::Initialize(System::UInt32 flags, Processors processor)
{
	return (ResultCode)this->XAudio2->Initialize(flags, (XAUDIO2_PROCESSOR)processor);
}

/// <summary>Initializes the XAudio2 object</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::Initialize()
{
	return (ResultCode)this->Initialize(0U, Processors::XAUDIO2_DEFAULT_PROCESSOR);
}

/// <summary>Adds a callback pointer to the engine callback list</summary>
/// <param name="callback">Callback to add</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::RegisterForCallbacks(EngineCallback^ callback)
{
	//create new callback
	UnmanagedEngineCallbackBase* unmanagedCallback = new UnmanagedEngineCallbackBase(callback);
	
	//back reference the unmanaged callback object
	callback->CallbackPointer = System::IntPtr(unmanagedCallback);

	//register
	return (ResultCode)this->XAudio2->RegisterForCallbacks(unmanagedCallback);
}

/// <summary>Sets the debug configuration data</summary>
void XAudio2Interface::SetDebugConfiguration(DebugConfiguration^ config)
{
	XAUDIO2_DEBUG_CONFIGURATION debugConfiguration = config->ToUnmanaged();
	this->XAudio2->SetDebugConfiguration(&debugConfiguration);
}
					
/// <summary>Starts the audio processing thread</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
ResultCode XAudio2Interface::StartEngine()
{
	return (ResultCode)this->XAudio2->StartEngine();
}
					
/// <summary>Stops the audio processing thread</summary>
/// <returns>S_OK on success, otherwise an error code.</returns>
void XAudio2Interface::StopEngine()
{
	this->XAudio2->StopEngine();
}

/// <summary>Removes a callback pointer to the engine callback list</summary>
/// <param name="callback">Callback to remove</param>
/// <returns>S_OK on success, otherwise an error code.</returns>
void XAudio2Interface::UnregisterForCallbacks(EngineCallback^ callback)
{
	this->XAudio2->UnregisterForCallbacks((UnmanagedEngineCallbackBase*)(callback->CallbackPointer.ToPointer()));
}
#pragma endregion


					
#pragma region Helper Methods
/// <summary>Gets a pointer to an XAudio2 effect chain for the API</summary>
/// <param name="effectChain">List of effects for the voice</param>
/// <returns>A pointer to a XAUDIO2_EFFECT_CHAIN struct</returns>
XAUDIO2_EFFECT_CHAIN* XAudio2Interface::GetEffectChain(System::Collections::Generic::List<EffectDescriptor^>^ effectChain)
{
	XAUDIO2_EFFECT_CHAIN* chain;

	if (effectChain == nullptr || effectChain->Count < 1)
		chain = NULL;
	else
	{
		chain = new XAUDIO2_EFFECT_CHAIN;
		chain->EffectCount = System::Convert::ToUInt32(effectChain->Count);
		chain->pEffectDescriptors = new XAUDIO2_EFFECT_DESCRIPTOR[effectChain->Count];

		// copy effect chain
		for (System::Int32 i = 0; i < effectChain->Count; ++i)
			chain->pEffectDescriptors[i] = effectChain[i]->ToUnmanaged();
	}

	return chain;
}

/// <summary>Gets a pointer to an XAudio2 voice output structure for the API</summary>
/// <param name="sends">List of Voice sends for the generating voice</param>
/// <returns>A pointer to a XAUDIO2_VOICE_SENDS struct</returns>
XAUDIO2_VOICE_SENDS* XAudio2Interface::GetVoiceSends(System::Collections::Generic::List<VoiceSendDescriptor^>^ sends)
{
	XAUDIO2_VOICE_SENDS* output = NULL;

	if (sends != nullptr && sends->Count > 0)
	{
		output = new XAUDIO2_VOICE_SENDS;
		output->SendCount = System::Convert::ToUInt32(sends->Count);
		output->pSends = new XAUDIO2_SEND_DESCRIPTOR[sends->Count];

		// copy effect chain
		for (System::Int32 i = 0; i < sends->Count; ++i)
			output->pSends[i] = sends[i]->ToUnmanaged();
	}

	return output;
}
#pragma endregion


