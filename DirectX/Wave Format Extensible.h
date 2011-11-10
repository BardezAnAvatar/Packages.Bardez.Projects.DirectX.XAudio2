
#ifndef Bardez_Projects_Directx_WaveFormatExtensible
#define Bardez_Projects_Directx_WaveFormatExtensible

#include <windows.h>
#include <xaudio2.h>
#include "Wave Format Ex.h"

using namespace System;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace Sound
			{
				/// <summary>Managed representation of Win32 WAVEFORMATEXTENSIBLE structure, inheriting the WaveFormatEx structure</summary>
				public ref class WaveFormatExtensible : WaveFormatEx
				{
				protected:
					/// <summary>Union of three fields here</summary>
					System::UInt16 samples;

					/// <summary>Positions of the audio channels</summary>
					System::UInt32 channelMask;

					/// <summary>Format identifier GUID</summary>
					System::Guid subFormat;

				public:
					/// <summary>Base WAVEFORMATEX data</summary>
					/// <remarks>Keeping with the base type paradigm in C/++</remarks>
					property WaveFormatEx^ Format
					{
						WaveFormatEx^ get()
						{
							return (WaveFormatEx^)this;
						}
					}

					/// <summary>Union of three fields here: wValidBitsPerSample, wSamplesPerBlock, and wReserved</summary>
					property System::UInt16 Samples
					{
						System::UInt16 get()
						{
							return samples;
						}
						void set(System::UInt16 value)
						{
							this->samples = value;
						}
					}
					
					/// <summary>Union of three fields here: wValidBitsPerSample, wSamplesPerBlock, and wReserved</summary>
					property System::UInt16 ValidBitsPerSample
					{
						System::UInt16 get()
						{
							return samples;
						}
						void set(System::UInt16 value)
						{
							this->samples = value;
						}
					}
					
					/// <summary>Union of three fields here: wValidBitsPerSample, wSamplesPerBlock, and wReserved</summary>
					property System::UInt16 Reserved
					{
						System::UInt16 get()
						{
							return samples;
						}
						void set(System::UInt16 value)
						{
							this->samples = value;
						}
					}

					/// <summary>Positions of the audio channels</summary>
					property System::UInt32 ChannelMask
					{
						System::UInt32 get()
						{
							return channelMask;
						}
						void set(System::UInt32 value)
						{
							this->channelMask = value;
						}
					}

					/// <summary>Format identifier GUID</summary>
					property System::Guid SubFormat
					{
						System::Guid get()
						{
							return subFormat;
						}
						void set(System::Guid value)
						{
							this->subFormat = value;
						}
					}
					


				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					WaveFormatExtensible() { }

				internal:
					/// <summary>WAVEFORMATEX Win32 constructor</summary>
					WaveFormatExtensible(WAVEFORMATEXTENSIBLE waveEx);
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
					/// <returns>A String representing the WaveFormatEx Object contents</returns>
					String^ ToDescriptionString();

				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged WAVEFORMATEX struct</returns>
					WAVEFORMATEXTENSIBLE ToUnmanaged() new;
				#pragma endregion
				};
			}
		}
	}
}


#endif
