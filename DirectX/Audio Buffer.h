
#ifndef Bardez_Projects_Directx_XAudio2_Buffer
#define Bardez_Projects_Directx_XAudio2_Buffer


#include <xaudio2.h>


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed version of XAUDIO2_BUFFER struct</summary>
				/// <remarks>May be freed once assigned via SubmitSourceBuffer, but not the internal pointer</remarks>
				public ref class AudioBuffer
				{
				#pragma region Members
				protected:
					/// <summary>Flags that provide additional infor for the buffer.</summary>
					/// <value>May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</value>
					System::UInt32 flags;

					/// <summary>Raw audio data of the PCM or WMA/XMA data.</summary>
					/// <value>
					///		PCM length must be no larger than XAUDIO2_MAX_BUFFER_BYTES (0x80000000).
					///		XMA length must be no larger than XMA_READBUFFER_MAX_BYTES (4095u * 2048u = 8386560 = 0x7FF800).
					/// </value>
					array<System::Byte>^ audioData;

					/// <summary>First sample of the audio data to start playing</summary>
					/// <remarks>XMA requires 128 modular alignment</remarks>
					System::UInt32 playBegin;

					/// <summary>Length of sample of the audio data to play</summary>
					/// <value>0 means entire buffer, but playBegin must also be 0</value>
					/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block.</remarks>
					System::UInt32 playLength;

					/// <summary>First sample to loop from.</summary>
					/// <value>Must be within the range of playBegin and playLength. Must be zero for xWMA. Must be 0 if count is 0.</value>
					/// <remarks>XMA requires 128 modular alignment</remarks>
					System::UInt32 loopBegin;

					/// <summary>Length of samples to loop</summary>
					/// <value>Must be within the range of playBegin and playLength. Must be 0 if count is 0.</value>
					/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block. xWMA must be 0 or whole sample length</remarks>
					System::UInt32 loopLength;

					/// <summary>Count of iterations to loop</summary>
					/// <value>Must be between 0 and XAUDIO2_MAX_LOOP_COUNT (254). To continuously loop, set to XAUDIO2_LOOP_INFINITE (255).</value>
					/// <remarks>xWMA must be 0 or else flags must be set to XAUDIO2_END_OF_STREAM (0x0040)</remarks>
					System::UInt32 loopCount;

					/// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
					System::IntPtr context;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Flags that provide additional infor for the buffer.</summary>
					/// <value>May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</value>
					property System::UInt32 Flags
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Raw audio data of the PCM or WMA/XMA data.</summary>
					property array<System::Byte>^ AudioData
					{
						array<System::Byte>^ get();
						void set(array<System::Byte>^ value);
					}

					/// <summary>First sample of the audio data to start playing</summary>
					/// <remarks>XMA requires 128 modular alignment</remarks>
					property System::UInt32 PlayBegin
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Length of sample of the audio data to play</summary>
					/// <value>0 means entire buffer, but playBegin must also be 0</value>
					/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block.</remarks>
					property System::UInt32 PlayLength
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>First sample to loop from.</summary>
					/// <value>Must be within the range of playBegin and playLength. Must be zero for xWMA. Must be 0 if count is 0.</value>
					/// <remarks>XMA requires 128 modular alignment</remarks>
					property System::UInt32 LoopBegin
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Length of samples to loop</summary>
					/// <value>Must be within the range of playBegin and playLength. Must be 0 if count is 0.</value>
					/// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block. xWMA must be 0 or whole sample length</remarks>
					property System::UInt32 LoopLength
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Count of iterations to loop</summary>
					/// <value>Must be between 0 and XAUDIO2_MAX_LOOP_COUNT (254). To continuously loop, set to XAUDIO2_LOOP_INFINITE (255).</value>
					/// <remarks>xWMA must be 0 or else flags must be set to XAUDIO2_END_OF_STREAM (0x0040)</remarks>
					property System::UInt32 LoopCount
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
					property System::IntPtr Context
					{
						System::IntPtr get();
						void set(System::IntPtr value);
					}

				internal:
					/// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
					property void* BufferContext
					{
						void* get();
						void set(void* value);
					}
				#pragma endregion
				


				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					AudioBuffer() {}

					/// <summary>Definition constructor</summary>
					/// <param name="flagsCreation">Buffer flags. May be 0 or XAUDIO2_END_OF_STREAM</param>
					/// <param name="data">Audio data stream</param>
					/// <param name="beginPlay">Sample # within audio data to start playing</param>
					/// <param name="lengthPlay">Length of audio samples to play</param>
					/// <param name="beginLoop">Location to sample to start looping from</param>
					/// <param name="lengthLoop">Length of audio samples to loop</param>
					/// <param name="countLoop">Number of loops to complete looping</param>
					/// <param name="ptrContext">Client context pointer for this buffer</param>
					AudioBuffer(System::UInt32 flagsCreation, array<System::Byte>^ data, System::UInt32 beginPlay, System::UInt32 lengthPlay, System::UInt32 beginLoop, System::UInt32 lengthLoop, System::UInt32 countLoop, System::IntPtr ptrContext);
					
				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="buffer">Unmanaged XAUDIO2_BUFFER struct</param>
					AudioBuffer(XAUDIO2_BUFFER buffer);
				#pragma endregion


				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_BUFFER struct</returns>
					XAUDIO2_BUFFER ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif
