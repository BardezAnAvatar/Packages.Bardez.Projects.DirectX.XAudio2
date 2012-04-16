using System;
using System.Runtime.InteropServices;

using Bardez.Projects.DirectX.XAudio2.Enums;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed version of XAUDIO2_PERFORMANCE_DATA structure</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct PerformanceData
    {
        #region Fields
        /// <summary>Number of CPU cycles spent on audio since last call to StartEngine or GetPerformanceData</summary>
        public UInt64 AudioCyclesSinceLastQuery;

        /// <summary>Number of CPU cycles (current CPU) since last call to StartEngine or GetPerformanceData</summary>
        public UInt64 TotalCyclesSinceLastQuery;

        /// <summary>The fewest CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
        public UInt32 MinCyclesPerQuantum;

        /// <summary>The most CPU cycles spent on processing any sinle audio quantum since last call to StartEngine or GetPerformanceData</summary>
        public UInt32 MaxCyclesPerQuantum;

        /// <summary>Total memory in use</summary>
        public UInt32 MemoryUsage;

        /// <summary>Minimum delay between read time and render time</summary>
        public UInt32 LatencyInSamples;

        /// <summary>Number of audio dropouts (please define) since engine started</summary>
        public UInt32 GlitchCount;

        /// <summary>Number of currently active source voices playing</summary>
        public UInt32 ActiveSources;

        /// <summary>Number of existing source voices</summary>
        public UInt32 TotalSources;

        /// <summary>Number of currently active submix voices playing</summary>
        public UInt32 ActiveSubmixes;

        /// <summary>Number of currently active resampler xAPOs</summary>
        public UInt32 ActiveResamplers;

        /// <summary>Number of currently active matrix mix xAPOs</summary>
        public UInt32 ActiveMatrixMix;

        /// <summary>Number of currently active/decoding XMA source voices</summary>
        /// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
        public UInt32 ActiveXmaSourceVoices;

        /// <summary>Number of currently active XMA streams</summary>
        /// <remarks>Unsupported in Windows as of XAudio2 version 7</remarks>
        public UInt32 ActiveXmaStreams;
        #endregion


        #region Construction
        /// <summary>Default constructor</summary>
        public PerformanceData()
        {
            this.AudioCyclesSinceLastQuery = 0UL;
            this.TotalCyclesSinceLastQuery = 0UL;
            this.MinCyclesPerQuantum = 0U;
            this.MaxCyclesPerQuantum = 0U;
            this.MemoryUsage = 0U;
            this.LatencyInSamples = 0U;
            this.GlitchCount = 0U;
            this.ActiveSources = 0U;
            this.TotalSources = 0U;
            this.ActiveSubmixes = 0U;
            this.ActiveResamplers = 0U;
            this.ActiveMatrixMix = 0U;
            this.ActiveXmaSourceVoices = 0U;
            this.ActiveXmaStreams = 0U;
        }

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
        public PerformanceData(UInt64 audioCycles, UInt64 totalCycles, UInt32 minQuantumCycles, UInt32 maxQuantumCycles,
            UInt32 memoryUsed, UInt32 latency, UInt32 glitches, UInt32 sourcesActive, UInt32 sourcesTotal,
            UInt32 submixes, UInt32 resamplers, UInt32 matrixMixes, UInt32 sourcesXma, UInt32 streamsXma)
        {
            this.AudioCyclesSinceLastQuery = audioCycles;
            this.TotalCyclesSinceLastQuery = totalCycles;
            this.MinCyclesPerQuantum = minQuantumCycles;
            this.MaxCyclesPerQuantum = maxQuantumCycles;
            this.MemoryUsage = memoryUsed;
            this.LatencyInSamples = latency;
            this.GlitchCount = glitches;
            this.ActiveSources = sourcesActive;
            this.TotalSources = sourcesTotal;
            this.ActiveSubmixes = submixes;
            this.ActiveResamplers = resamplers;
            this.ActiveMatrixMix = matrixMixes;
            this.ActiveXmaSourceVoices = sourcesXma;
            this.ActiveXmaStreams = streamsXma;
        }
        #endregion
    }
}