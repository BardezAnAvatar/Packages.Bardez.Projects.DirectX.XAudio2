
#ifndef Bardez_Projects_Directx_XAudio2
#define Bardez_Projects_Directx_XAudio2

#include <windows.h>
#include <xaudio2.h>

//used to force the linker to link to the correct library
#pragma comment(lib, "ole32.lib") //for CoInitializeEX, CoCreateInstance

#include "Debug Configuration.h"
#include "Device Details.h"
#include "Engine Callback.h"
#include "Mastering Voice.h"
#include "Performance Data.h"
#include "Processor.h"
#include "Source Voice.h"
#include "Submix Voice.h"
#include "Version.h"
#include "Voice Callback.h"

using namespace System;
using namespace Bardez::Projects::BasicStructures::Win32;
using namespace Bardez::Projects::BasicStructures::Win32::Audio;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Provides a managed interface to the XAudio2 DirectX WinAPI</summary>
				/// <remarks>
				///		The XAudio2 interface works with an XAudio2 and a voice Audio Graph.
				///		The graph has three types: Source, Submix, and Master.
				///		Source is, of course, the source. In a base logical sense, it is the wave binary data.
				///		Submix is an intermediary, a passthrough and perhaps a manipulation point.
				///		Mastering is the final node on the graph before outputting to a physical audio device.
				///
				///		As such, an IXAudio2 interfce object is to be instantiated, then a voice, then output to a mastering voice.
				/// </remarks>
				public ref class XAudio2Interface //: System::IDisposable //implied by setting a ~Destructor
				{
				#pragma region Constants & Flags
				public:
					ref class VoiceFlags
					{
					public:
						/// <summary>No sample rate conversion is available on the voice. The voice's outputs must have the same sample rate.</summary>
						/// <remarks>This flag causes the voice to behave as though the XAUDIO2_VOICE_NOPITCH flag also is specified.</remarks>
						/// <value>0x0004</value>
						static const System::UInt32 NoSampleRateConversion = XAUDIO2_VOICE_NOSRC;

						/// <summary>No pitch control is available on the voice.</summary>
						/// <value>0x0002</value>
						static const System::UInt32 NoPitchControl = XAUDIO2_VOICE_NOPITCH;

						/// <summary>The filter effect should be available on this voice.</summary>
						/// <value>0x0008</value>
						static const System::UInt32 FilterEffectAvailable = XAUDIO2_VOICE_USEFILTER;

						/// <summary>System default number of audio channels</summary>
						/// <remarks>Used in CreateMasteringVoice.</remarks>
						/// <value>0x0000</value>
						static const System::UInt32 DefaultAudioChannelCount = XAUDIO2_DEFAULT_CHANNELS;

						/// <summary>Maximum channels in an audio stream</summary>
						/// <value>64</value>
						static const System::UInt32 MaximumAudioChannelCount = XAUDIO2_MAX_AUDIO_CHANNELS;

						/// <summary>System default sample rate</summary>
						/// <remarks>Used in CreateMasteringVoice. Translates into 44.1k or 48k depending on the driver</remarks>
						/// <value>0x0000</value>
						static const System::UInt32 DefaultSampleRate = XAUDIO2_DEFAULT_SAMPLERATE;

						/// <summary>Minimum audio sample rate supported</summary>
						/// <remarks>1000?</remarks>
						static const System::UInt32 MinimumSampleRate = XAUDIO2_MIN_SAMPLE_RATE;

						/// <summary>Maximum audio sample rate supported</summary>
						/// <remarks>200000?</remarks>
						static const System::UInt32 MaximumSampleRate = XAUDIO2_MAX_SAMPLE_RATE;

						/// <summary>XAudio2 constant indicating that the stream is expected to close after this buffer is finished.</summary>
						/// <value>0x0040U</value>
						static const System::UInt32 EndOfStream = XAUDIO2_END_OF_STREAM;
					};
				#pragma endregion


				#pragma region Members
				protected:
					/// <summary>Pointer to an XAudio2 interface object</summary>
					System::IntPtr ptrXAudio2;
				#pragma endregion



				#pragma region Properties
				protected:
					/// <summary>Property to access the XAudio pointer, wrapping to a .NET IntPtr</summary>
					property IXAudio2* XAudio2Handle
					{
						IXAudio2* get();
						void set(IXAudio2* value);
					}
				#pragma endregion



				#pragma region Construction
				internal:
					/// <summary>Default construtor</summary>
					XAudio2Interface();
				#pragma endregion



				#pragma region Destruction
				public:
					/// <summary>Destructor</summary>
					/// <remarks>Dispose()</remarks>
					~XAudio2Interface();

					/// <summary>Destructor</summary>
					/// <remarks>Finalize()</remarks>
					!XAudio2Interface();

					/// <summary>Destructor logic, disposes the object</summary>
					/// <remarks>There are only managed references, so either Finalize or Dispose would be calling</remarks>
					void DisposeUnmanaged();
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Creates &amp; initializes the XAudio2 Interface</summary>
					/// <returns>A new XAudio2Interface object instance</returns>
					static XAudio2Interface^ NewInstance();

					/// <summary>Applies the set of operation identified with operationSet</summary>
					/// <param name="operationSet">Operation set of the effect (XAUDIO2_COMMIT_NOW == 0?), identifiying a batch</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CommitChanges(System::UInt32 operationSet);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
					/// <param name="effectChain">List of effects for the mastering voice</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels, System::UInt32 sampleRate);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice, System::UInt32 channels);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="masteringVoice">Mastering voice reference to assign</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateMasteringVoice(MasteringVoice^% masteringVoice);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
					/// <param name="effectChain">List of effects for the mastering voice</param>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <param name="deviceIndex">Index of the output device. 0 means default.</param>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 deviceIndex);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">Flags that specify behavior of the mastering voice. Must be 0.</param>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice(System::UInt32 channels, System::UInt32 sampleRate);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice(System::UInt32 channels);

					/// <summary>Creates a mastering voice associated with this instance of XAudio2</summary>
					/// <returns>A new Mastering voice reference.</returns>
					MasteringVoice^ CreateMasteringVoice();

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="sourceVoice">Source voice reference to assign</param>
					/// <param name="format">Format of the source voice data</param>
					/// <param name="flags">
					///		Flags that specify behavior of the mastering voice.
					///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
					///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
					/// </param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format, System::UInt32 flags);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="sourceVoice">Source voice reference to assign</param>
					/// <param name="format">Format of the source voice data</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateSourceVoice(SourceVoice^% sourceVoice, WaveFormatEx^ format);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio, VoiceCallback^ callback);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags, System::Single freqRatio);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="format">Format of the source voice data</param>
					/// <param name="flags">
					///		Flags that specify behavior of the mastering voice.
					///		Must be 0 or binary OR of any of: XAUDIO2_VOICE_NOPITCH (0x0002), XAUDIO2_VOICE_NOSRC (0x0004),
					///		XAUDIO2_VOICE_USEFILTER (0x0008), and XAUDIO2_VOICE_MUSIC (0x0010).
					/// </param>
					/// <returns>A new Source voice reference.</returns>
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format, System::UInt32 flags);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="format">Format of the source voice data</param>
					/// <returns>A new Source voice reference.</returns>
					SourceVoice^ CreateSourceVoice(WaveFormatEx^ format);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					ResultCode CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="submixVoice">Submix voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">
					///		Flags that specify behavior of the submix voice.
					///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
					/// </param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="submixVoice">Submix voice reference to assign</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode CreateSubmixVoice(SubmixVoice^% submixVoice, System::UInt32 channels, System::UInt32 sampleRate);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SubmixVoice^ CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends, System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SubmixVoice^ CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage, System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
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
					SubmixVoice^ CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags, System::UInt32 stage);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <param name="flags">
					///		Flags that specify behavior of the submix voice.
					///		Must be 0 or binary OR XAUDIO2_VOICE_USEFILTER (0x0008)
					/// </param>
					/// <returns>A new Submix voice reference.</returns>
					SubmixVoice^ CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate, System::UInt32 flags);

					/// <summary>Creates a Source voice associated with this instance of XAudio2</summary>
					/// <param name="channels">Number of input channels</param>
					/// <param name="sampleRate">Input sample rate</param>
					/// <returns>A new Submix voice reference.</returns>
					SubmixVoice^ CreateSubmixVoice(System::UInt32 channels, System::UInt32 sampleRate);

#if _XAUDIO2_VERSION_ < 8
					/// <summary>Returns the number of audio output devices available.</summary>
					/// <returns>A UInt32 describing the device count</returns>
					System::UInt32 GetDeviceCount();

					/// <summary>Gets the device details from XAudio2</summary>
					/// <param name="index">Index of the device to be described</param>
					/// <returns>A reference to a DeviceDetails instance describing the audio device</returns>
					DeviceDetails^ GetDeviceDetails(System::UInt32 index);
#endif

					/// <summary>Gets the current resource usage detailed data</summary>
					/// <returns>The performance info inside a data structure</returns>
					PerformanceData^ GetPerformanceData();

					/// <summary>Initializes the XAudio2 object</summary>
					/// <param name="flags">Flags indicating behavior. Must be 0.</param>
					/// <param name="processor">Processor to run this instance on</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Initialize(System::UInt32 flags, Processors processor);

#if _XAUDIO2_VERSION_ < 8
					/// <summary>Initializes the XAudio2 object</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode Initialize();
#endif

					/// <summary>Adds a callback pointer to the engine callback list</summary>
					/// <param name="callback">Callback to add</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode RegisterForCallbacks(EngineCallback^ callback);

					/// <summary>Sets the debug configuration data</summary>
					void SetDebugConfiguration(DebugConfiguration^ config);

					/// <summary>Starts the audio processing thread</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					ResultCode StartEngine();

					/// <summary>Stops the audio processing thread</summary>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					void StopEngine();

					/// <summary>Removes a callback pointer to the engine callback list</summary>
					/// <param name="callback">Callback to remove</param>
					/// <returns>S_OK on success, otherwise an error code.</returns>
					void UnregisterForCallbacks(EngineCallback^ callback);

					/****************************
					*	Excluded COM Methods	*
					****************************/
					/*
					STDMETHOD(QueryInterface) (THIS_ REFIID riid, __deref_out void** ppvInterface) PURE;
					STDMETHOD_(ULONG, AddRef) (THIS) PURE;
					STDMETHOD_(ULONG, Release) (THIS) PURE;
					*/
				#pragma endregion



				#pragma region Helper Methods
				internal:
					/// <summary>Gets a pointer to an XAudio2 effect chain for the API</summary>
					/// <param name="effectChain">List of effects for the voice</param>
					/// <returns>A pointer to a XAUDIO2_EFFECT_CHAIN struct</returns>
					static XAUDIO2_EFFECT_CHAIN* GetEffectChain(System::Collections::Generic::IList<EffectDescriptor^>^ effectChain);

					/// <summary>Gets a pointer to an XAudio2 voice output structure for the API</summary>
					/// <param name="sends">List of Voice sends for the generating voice</param>
					/// <returns>A pointer to a XAUDIO2_VOICE_SENDS struct</returns>
					static XAUDIO2_VOICE_SENDS* GetVoiceSends(System::Collections::Generic::IList<VoiceSendDescriptor^>^ sends);
				#pragma endregion
				};
			}
		}
	}
}

#endif

