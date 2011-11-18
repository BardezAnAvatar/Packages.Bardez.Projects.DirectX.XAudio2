#ifndef Bardez_Projects_Directx_XAudio2_WmaBuffer
#define Bardez_Projects_Directx_XAudio2_WmaBuffer


#include <xaudio2.h>


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed version of XAUDIO2_BUFFER_WMA struct</summary>
				/// <remarks>May be freed once assigned via SubmitSourceBuffer</remarks>
				public ref class WmaBuffer
				{
				#pragma region Members
				protected:
					/// <summary>Array of sizes of decoded packets</summary>
					array<System::UInt32>^ packetDecodedSizes;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Array of sizes of decoded packets</summary>
					property array<System::UInt32>^ PacketDecodedSizes
					{
						array<System::UInt32>^ get();
						void set(array<System::UInt32>^ value);
					}
				#pragma endregion
				


				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					WmaBuffer() {}

					/// <summary>Definition constructor</summary>
					/// <param name="packetSizes">Array indicating sizes of decoded packets</param>
					WmaBuffer(array<System::UInt32>^ packetSizes);
					
				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="buffer">Unmanaged XAUDIO2_BUFFER_WMA struct</param>
					WmaBuffer(XAUDIO2_BUFFER_WMA buffer);
				#pragma endregion


				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_BUFFER_WMA struct</returns>
					XAUDIO2_BUFFER_WMA ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif