
#include "WMA Buffer.h"

using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Array of sizes of decoded packets</summary>
array<System::UInt32>^ WmaBuffer::PacketDecodedSizes::get()
{
	return this->packetDecodedSizes;
}

/// <summary>Array of sizes of decoded packets</summary>
void WmaBuffer::PacketDecodedSizes::set(array<System::UInt32>^ value)
{
	this->packetDecodedSizes = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="packetSizes">Array indicating sizes of decoded packets</param>
WmaBuffer::WmaBuffer(array<System::UInt32>^ packetSizes)
{
	this->packetDecodedSizes = packetSizes;
}
					
/// <summary>Unmanaged constructor</summary>
/// <param name="buffer">Unmanaged XAUDIO2_BUFFER_WMA struct</param>
WmaBuffer::WmaBuffer(XAUDIO2_BUFFER_WMA buffer)
{
	this->packetDecodedSizes = gcnew array<System::UInt32>(buffer.PacketCount);
	//Marshal has no UInt32 copy. lame.

	for (System::UInt32 i = 0; i < buffer.PacketCount; ++i)
		this->packetDecodedSizes[i] = buffer.pDecodedPacketCumulativeBytes[i];
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_BUFFER_WMA struct</returns>
XAUDIO2_BUFFER_WMA WmaBuffer::ToUnmanaged()
{
	XAUDIO2_BUFFER_WMA buffer;

	buffer.PacketCount = this->packetDecodedSizes->Length;
	
	//struct is const and connot be written. Use an interim pointer.
	UINT32* packetBytes = new UINT32[buffer.PacketCount];
		
	//copy; Marshal has no UInt32 copy. lame.
	for (System::UInt32 i = 0; i < buffer.PacketCount; ++i)
		packetBytes[i] = this->packetDecodedSizes[i];
	
	//Assign the const pointer to the interim, copied array
	buffer.pDecodedPacketCumulativeBytes = packetBytes;

	return buffer;
}
#pragma endregion

