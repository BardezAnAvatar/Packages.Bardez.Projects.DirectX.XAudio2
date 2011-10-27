
#ifndef Bardez_Projects_Directx_Wave_FormatEx
#define Bardez_Projects_Directx_Wave_FormatEx

#include <windows.h>
#include <xaudio2.h>

using namespace System;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace Sound
			{
				/// <summary>Managed representation of Win32 WAVEFORMATEX structure</summary>
				public ref class WaveFormatEx
				{
				#pragma region Members
				protected:
					/// <summary>Integer identifier of the format</summary>
					System::UInt16 formatTag;

					/// <summary>Number of audio channels</summary>
					System::UInt16 numberChannels;

					/// <summary>Audio sample rate</summary>
					System::UInt32 samplesPerSec;

					/// <summary>Bytes per second (possibly approximate)</summary>
					System::UInt32 averageBytesPerSec;

					/// <summary>Size in bytes of a sample block (all channels)</summary>
					System::UInt16 blockAlignment;

					/// <summary>Size in bits of a single per-channel sample</summary>
					/// <remarks>16 bit is optimal for XAudio2, 32 bit following, then other formats.</remarks>
					System::UInt16 bitsPerSample;

					/// <summary>
					///		Bytes of extra data appended to this struct. Explains the length of bytes in addition to this struct,
					///		essentially the extra size of child instances.
					/// </summary>
					System::UInt16 size;
				#pragma endregion
				


				#pragma region Properties
				public:
					/// <summary>Integer identifier of the format</summary>
					property System::UInt16 FormatTag
					{
						System::UInt16 get();
						void set(System::UInt16 value);
					}

					/// <summary>Number of audio channels</summary>
					property System::UInt16 NumberChannels
					{
						System::UInt16 get();
						void set(System::UInt16 value);
					}

					/// <summary>Audio sample rate</summary>
					property System::UInt32 SamplesPerSec
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Bytes per second (possibly approximate)</summary>
					property System::UInt32 AverageBytesPerSec
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Size in bytes of a sample block (all channels)</summary>
					property System::UInt16 BlockAlignment
					{
						System::UInt16 get();
						void set(System::UInt16 value);
					}

					/// <summary>Size in bits of a single per-channel sample</summary>
					/// <remarks>16 bit is optimal for XAudio2, 32 bit following, then other formats.</remarks>
					property System::UInt16 BitsPerSample
					{
						System::UInt16 get();
						void set(System::UInt16 value);
					}

					/// <summary>Bytes of extra data appended to this struct</summary>
					property System::UInt16 Size
					{
						System::UInt16 get();
						void set(System::UInt16 value);
					}
				#pragma endregion
					


				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					WaveFormatEx() { }

				internal:
					/// <summary>Unmanaged WAVEFORMATEX Win32 constructor</summary>
					WaveFormatEx(WAVEFORMATEX wave);
				#pragma endregion
					

						
				#pragma region Methods
				public:
					/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
					/// <returns>A String representing the WaveFormatEx Object contents</returns>
					String^ ToDescriptionString();

				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged WAVEFORMATEX struct</returns>
					WAVEFORMATEX ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}


#endif