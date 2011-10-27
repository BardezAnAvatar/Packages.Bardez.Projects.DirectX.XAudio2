
#ifndef Bardez_Projects_Directx_XAudio2_PerformanceData
#define Bardez_Projects_Directx_XAudio2_PerformanceData

#include <XAudio2.h>

using namespace System;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed version of XAUDIO2_PERFORMANCE_DATA structure</summary>
				public ref class PerformanceData
				{
				#pragma region Members
				protected:
					/// <summary>Number of CPU cycles spent on audio since last call to StartEngine or GetPerformanceData</summary>
					System::UInt64 audioCyclesSinceLastQuery;
					
					/// <summary>Number of CPU cycles (current CPU) since last call to StartEngine or GetPerformanceData</summary>
					System::UInt64 totalCyclesSinceLastQuery;
					
					/// <summary>The fewest CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
					System::UInt32 minCyclesPerQuantum;
					
					/// <summary>The most CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
					System::UInt32 maxCyclesPerQuantum;
					
					/// <summary>Total memory in use</summary>
					System::UInt32 memoryUsage;
					
					/// <summary>Minimum delay between read time and render time</summary>
					System::UInt32 latencyInSamples;
					
					/// <summary>Number of audio dropouts (please define) since engine started</summary>
					System::UInt32 glitchCount;
					
					/// <summary>Number of currently active source voices playing</summary>
					System::UInt32 activeSources;

					/// <summary>Number of existing source voices</summary>
					System::UInt32 totalSources;
					
					/// <summary>Number of currently active submix voices playing</summary>
					System::UInt32 activeSubmixes;
					
					/// <summary>Number of currently active resampler xAPOs</summary>
					System::UInt32 activeResamplers;
					
					/// <summary>Number of currently active matrix mix xAPOs</summary>
					System::UInt32 activeMatrixMix;
					
					/// <summary>Number of currently active/decoding XMA source voices</summary>
					/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
					System::UInt32 activeXmaSourceVoices;
					
					/// <summary>Number of currently active XMA streams</summary>
					/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
					System::UInt32 activeXmaStreams;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Number of CPU cycles spent on audio since last call to StartEngine or GetPerformanceData</summary>
					property System::UInt64 AudioCyclesSinceLastQuery
					{
						System::UInt64 get();
						void set(System::UInt64 value);
					}
					
					/// <summary>Number of CPU cycles (current CPU) since last call to StartEngine or GetPerformanceData</summary>
					property System::UInt64 TotalCyclesSinceLastQuery
					{
						System::UInt64 get();
						void set(System::UInt64 value);
					}
					
					/// <summary>The fewest CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
					property System::UInt32 MinCyclesPerQuantum
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>The most CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
					property System::UInt32 MaxCyclesPerQuantum
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Total memory in use</summary>
					property System::UInt32 MemoryUsage
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Minimum delay between read time and render time</summary>
					property System::UInt32 LatencyInSamples
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of audio dropouts (please define) since engine started</summary>
					property System::UInt32 GlitchCount
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active source voices playing</summary>
					property System::UInt32 ActiveSources
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}

					/// <summary>Number of existing source voices</summary>
					property System::UInt32 TotalSources
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active submix voices playing</summary>
					property System::UInt32 ActiveSubmixes
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active resampler xAPOs</summary>
					property System::UInt32 ActiveResamplers
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active matrix mix xAPOs</summary>
					property System::UInt32 ActiveMatrixMix
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active/decoding XMA source voices</summary>
					/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
					property System::UInt32 ActiveXmaSourceVoices
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
					
					/// <summary>Number of currently active XMA streams</summary>
					/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
					property System::UInt32 ActiveXmaStreams
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
				#pragma endregion
					


				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					PerformanceData() {}

					/// <summary>Definition constructor</summary>
					/// <param name="audioCycles">Number of audio cycles</param>
					/// <param name="totalCycles">Number of CPU cycles</param>
					/// <param name="minQuantumCycles">Minimum number of audio cycles per quantum</param>
					/// <param name="maxQuantumCycles">Maximum number of audio cycles per quantum</param>
					/// <param name="memoryUsed">Memory in use</param>
					/// <param name="latency">Latency of audio rendering</param>
					/// <param name="glitches">Number of glitches encountered</param>
					/// <param name="sourcesActive">Number of active source voices</param>
					/// <param name="sourcesTotal">Number of existing source voices</param>
					/// <param name="submixes">Number of active submix voices</param>
					/// <param name="resamplers">Number of active resampler xAPOs</param>
					/// <param name="matrixMixes">Number of active matrix mix xAPOs</param>
					/// <param name="sourcesXma">Number of decoding XMA source voices</param>
					/// <param name="streamsXma">Number of active XMA streams</param>
					PerformanceData(System::UInt64 audioCycles, System::UInt64 totalCycles, System::UInt32 minQuantumCycles, System::UInt32 maxQuantumCycles,
						System::UInt32 memoryUsed, System::UInt32 latency, System::UInt32 glitches, System::UInt32 sourcesActive, System::UInt32 sourcesTotal,
						System::UInt32 submixes, System::UInt32 resamplers, System::UInt32 matrixMixes, System::UInt32 sourcesXma, System::UInt32 streamsXma);

					
				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="data">Unmanaged source struct</param>
					PerformanceData(XAUDIO2_PERFORMANCE_DATA data);
				#pragma endregion
					


				#pragma region Methods
				internal:
					/// <summary>Generates an unmanaged version of the data</summary>
					/// <returns>An unmanaged version of the wrapped struct</returns>
					XAUDIO2_PERFORMANCE_DATA ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif