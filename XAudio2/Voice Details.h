#ifndef Bardez_Projects_Directx_XAudio2_VoiceDetails
#define Bardez_Projects_Directx_XAudio2_VoiceDetails


#include <xaudio2.h>


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed XAUDIO2_VOICE_DETAILS structure</summary>
				/// <remarks>
				///		The documentation definition
				///		(http://msdn.microsoft.com/en-us/library/windows/desktop/microsoft.directx_sdk.xaudio2.xaudio2_voice_details%28v=vs.85%29.aspx)
				///		conflicts with xaudio2.h definition
				///	</remarks>
				public ref class VoiceDetails
				{
				#pragma region Members
				protected:
					/// <summary>Flags to create voice, abstracted values by voice type</summary>
					System::UInt32 creationFlags;

					/// <summary>Number of expected input channels</summary>
					System::UInt32 inputChannels;

					/// <summary>Expected input sample sample rate</summary>
					System::UInt32 inputSampleRate;
				#pragma endregion

				#pragma region Properties
				public:
					/// <summary>Flags to create voice, abstracted values by voice type</summary>
					property System::UInt32 CreationFlags
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Number of expected input channels</summary>
					property System::UInt32 InputChannels
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Expected input sample sample rate</summary>
					property System::UInt32 InputSampleRate
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
				#pragma endregion

				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					VoiceDetails() {}

					/// <summary>Definition constructor</summary>
					/// <param name="flagsCreation">Creation flags</param>
					/// <param name="channels">Number of input channels</param>
					/// <param name="rate">Input sample rate</param>
					VoiceDetails(System::UInt32 flagsCreation, /*System::UInt32 flagsActive,*/ System::UInt32 channels, System::UInt32 rate);

				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="details">Unmanaged XAUDIO2_VOICE_DETAILS struct</param>
					VoiceDetails(XAUDIO2_VOICE_DETAILS details);
				#pragma endregion
				

				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_VOICE_DETAILS struct</returns>
					XAUDIO2_VOICE_DETAILS ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif