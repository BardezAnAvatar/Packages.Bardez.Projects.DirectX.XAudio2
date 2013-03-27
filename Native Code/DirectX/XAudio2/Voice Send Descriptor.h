

#ifndef Bardez_Projects_Directx_XAudio2_VoiceDescriptor
#define Bardez_Projects_Directx_XAudio2_VoiceDescriptor


#include <xaudio2.h>


using namespace System;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				//Forward declaration
				ref class Voice;


				/// <summary>Defines the voice output to another voice. Managed wrapper of XAUDIO2_SEND_DESCRIPTOR.</summary>
				public ref class VoiceSendDescriptor
				{
				#pragma region Members
				protected:
					/// <summary>Indicates whether filter should be used on data sent to the voice.</summary>
					/// <value>Flags can be 0 or XAUDIO2_SEND_USEFILTER (0x0080)</value>
					System::UInt32 flags;

					/// <summary>Voice to be the target of the send. Cannot be null without error.</summary>
					Voice^ outputVoice;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Indicates whether filter should be used on data sent to the voice.</summary>
					/// <value>Flags can be 0 or XAUDIO2_SEND_USEFILTER (0x0080)</value>
					property System::UInt32 Flags
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Voice to be the target of the send. Cannot be null without error.</summary>
					property Voice^ OutputVoice
					{
						Voice^ get();
						void set(Voice^ value);
					}
				#pragma endregion



				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					VoiceSendDescriptor() {}

					/// <summary>Definition constructor</summary>
					/// <param name="flag">Indicates whether filter should be used on data sent to the voice</param>
					/// <param name="target">Voice to be the target of the send. Cannot be null without error</param>
					VoiceSendDescriptor(System::UInt32 flag, Voice^ target);
				#pragma endregion

				

				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_SEND_DESCRIPTOR struct</returns>
					XAUDIO2_SEND_DESCRIPTOR ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif

