

#include "Performance Data.h"

using namespace Bardez::Projects::DirectX::XAudio2;



#pragma region Properties
/// <summary>Number of CPU cycles spent on audio since last call to StartEngine or GetPerformanceData</summary>
System::UInt64 PerformanceData::AudioCyclesSinceLastQuery::get()
{
	return this->audioCyclesSinceLastQuery;
}

/// <summary>Number of CPU cycles spent on audio since last call to StartEngine or GetPerformanceData</summary>
void PerformanceData::AudioCyclesSinceLastQuery::set(System::UInt64 value)
{
	this->audioCyclesSinceLastQuery = value;
}

/// <summary>Number of CPU cycles (current CPU) since last call to StartEngine or GetPerformanceData</summary>
System::UInt64 PerformanceData::TotalCyclesSinceLastQuery::get()
{
	return this->totalCyclesSinceLastQuery;
}

/// <summary>Number of CPU cycles (current CPU) since last call to StartEngine or GetPerformanceData</summary>
void PerformanceData::TotalCyclesSinceLastQuery::set(System::UInt64 value)
{
	this->totalCyclesSinceLastQuery = value;
}

/// <summary>The fewest CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
System::UInt32 PerformanceData::MinCyclesPerQuantum::get()
{
	return this->minCyclesPerQuantum;
}

/// <summary>The fewest CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
void PerformanceData::MinCyclesPerQuantum::set(System::UInt32 value)
{
	this->minCyclesPerQuantum = value;
}

/// <summary>The most CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
System::UInt32 PerformanceData::MaxCyclesPerQuantum::get()
{
	return this->maxCyclesPerQuantum;
}

/// <summary>The most CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
void PerformanceData::MaxCyclesPerQuantum::set(System::UInt32 value)
{
	this->maxCyclesPerQuantum = value;
}

/// <summary>Total memory in use</summary>
System::UInt32 PerformanceData::MemoryUsage::get()
{
	return this->memoryUsage;
}

/// <summary>Total memory in use</summary>
void PerformanceData::MemoryUsage::set(System::UInt32 value)
{
	this->memoryUsage = value;
}

/// <summary>Minimum delay between read time and render time</summary>
System::UInt32 PerformanceData::LatencyInSamples::get()
{
	return this->latencyInSamples;
}

/// <summary>Minimum delay between read time and render time</summary>
void PerformanceData::LatencyInSamples::set(System::UInt32 value)
{
	this->latencyInSamples = value;
}

/// <summary>Number of audio dropouts (please define) since engine started</summary>
System::UInt32 PerformanceData::GlitchCount::get()
{
	return this->glitchCount;
}

/// <summary>Number of audio dropouts (please define) since engine started</summary>
void PerformanceData::GlitchCount::set(System::UInt32 value)
{
	this->glitchCount = value;
}

/// <summary>Number of currently active source voices playing</summary>
System::UInt32 PerformanceData::ActiveSources::get()
{
	return this->activeSources;
}

/// <summary>Number of currently active source voices playing</summary>
void PerformanceData::ActiveSources::set(System::UInt32 value)
{
	this->activeSources = value;
}

/// <summary>Number of existing source voices</summary>
System::UInt32 PerformanceData::TotalSources::get()
{
	return this->totalSources;
}

/// <summary>Number of existing source voices</summary>
void PerformanceData::TotalSources::set(System::UInt32 value)
{
	this->activeSources = value;
}

/// <summary>Number of currently active submix voices playing</summary>
System::UInt32 PerformanceData::ActiveSubmixes::get()
{
	return this->activeSubmixes;
}

/// <summary>Number of currently active submix voices playing</summary>
void PerformanceData::ActiveSubmixes::set(System::UInt32 value)
{
	this->activeSubmixes = value;
}

/// <summary>Number of currently active resampler xAPOs</summary>
System::UInt32 PerformanceData::ActiveResamplers::get()
{
	return this->activeResamplers;
}

/// <summary>Number of currently active resampler xAPOs</summary>
void PerformanceData::ActiveResamplers::set(System::UInt32 value)
{
	this->activeResamplers = value;
}

/// <summary>Number of currently active matrix mix xAPOs</summary>
System::UInt32 PerformanceData::ActiveMatrixMix::get()
{
	return this->activeMatrixMix;
}

/// <summary>Number of currently active matrix mix xAPOs</summary>
void PerformanceData::ActiveMatrixMix::set(System::UInt32 value)
{
	this->activeMatrixMix = value;
}

/// <summary>Number of currently active/decoding XMA source voices</summary>
/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
System::UInt32 PerformanceData::ActiveXmaSourceVoices::get()
{
	return this->activeXmaSourceVoices;
}

/// <summary>Number of currently active/decoding XMA source voices</summary>
/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
void PerformanceData::ActiveXmaSourceVoices::set(System::UInt32 value)
{
	this->activeXmaSourceVoices = value;
}

/// <summary>Number of currently active XMA streams</summary>
/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
System::UInt32 PerformanceData::ActiveXmaStreams::get()
{
	return this->activeXmaStreams;
}

/// <summary>Number of currently active XMA streams</summary>
/// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
void PerformanceData::ActiveXmaStreams::set(System::UInt32 value)
{
	this->activeXmaStreams = value;
}
#pragma endregion
					


#pragma region Construction
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
PerformanceData::PerformanceData(System::UInt64 audioCycles, System::UInt64 totalCycles, System::UInt32 minQuantumCycles, System::UInt32 maxQuantumCycles,
	System::UInt32 memoryUsed, System::UInt32 latency, System::UInt32 glitches, System::UInt32 sourcesActive, System::UInt32 sourcesTotal,
	System::UInt32 submixes, System::UInt32 resamplers, System::UInt32 matrixMixes, System::UInt32 sourcesXma, System::UInt32 streamsXma)
{
	this->audioCyclesSinceLastQuery = audioCycles;
	this->totalCyclesSinceLastQuery	= totalCycles;
	this->minCyclesPerQuantum = minQuantumCycles;
	this->maxCyclesPerQuantum = maxQuantumCycles;
	this->memoryUsage = memoryUsed;
	this->latencyInSamples = latency;
	this->glitchCount = glitches;
	this->activeSources = sourcesActive;
	this->totalSources = sourcesTotal;
	this->activeSubmixes = submixes;
	this->activeResamplers = resamplers;
	this->activeMatrixMix = matrixMixes;
	this->activeXmaSourceVoices = sourcesXma;
	this->activeXmaStreams = streamsXma;
}

/// <summary>Unmanaged constructor</summary>
/// <param name="data">Unmanaged source struct</param>
PerformanceData::PerformanceData(XAUDIO2_PERFORMANCE_DATA data)
{
	this->audioCyclesSinceLastQuery = data.AudioCyclesSinceLastQuery;
	this->totalCyclesSinceLastQuery	= data.TotalCyclesSinceLastQuery;
	this->minCyclesPerQuantum = data.MinimumCyclesPerQuantum;
	this->maxCyclesPerQuantum = data.MaximumCyclesPerQuantum;
	this->memoryUsage = data.MemoryUsageInBytes;
	this->latencyInSamples = data.CurrentLatencyInSamples;
	this->glitchCount = data.GlitchesSinceEngineStarted;
	this->activeSources = data.ActiveSourceVoiceCount;
	this->totalSources = data.TotalSourceVoiceCount;
	this->activeSubmixes = data.ActiveSubmixVoiceCount;
	this->activeResamplers = data.ActiveResamplerCount;
	this->activeMatrixMix = data.ActiveMatrixMixCount;
	this->activeXmaSourceVoices = data.ActiveXmaSourceVoices;
	this->activeXmaStreams = data.ActiveXmaStreams;
}
#pragma endregion
					


#pragma region Methods
/// <summary>Generates an unmanaged version of the data</summary>
/// <returns>An unmanaged version of the wrapped struct</returns>
XAUDIO2_PERFORMANCE_DATA PerformanceData::ToUnmanaged()
{
	XAUDIO2_PERFORMANCE_DATA data;
	
	data.AudioCyclesSinceLastQuery = this->audioCyclesSinceLastQuery ;
	data.TotalCyclesSinceLastQuery = this->totalCyclesSinceLastQuery;
	data.MinimumCyclesPerQuantum = this->minCyclesPerQuantum;
	data.MaximumCyclesPerQuantum = this->maxCyclesPerQuantum;
	data.MemoryUsageInBytes = this->memoryUsage;
	data.CurrentLatencyInSamples = this->latencyInSamples;
	data.GlitchesSinceEngineStarted = this->glitchCount;
	data.ActiveSourceVoiceCount = this->activeSources;
	data.TotalSourceVoiceCount = this->totalSources;
	data.ActiveSubmixVoiceCount = this->activeSubmixes;
	data.ActiveResamplerCount = this->activeResamplers;
	data.ActiveMatrixMixCount = this->activeMatrixMix;
	data.ActiveXmaSourceVoices = this->activeXmaSourceVoices;
	data.ActiveXmaStreams = this->activeXmaStreams;

	return data;
}
#pragma endregion


