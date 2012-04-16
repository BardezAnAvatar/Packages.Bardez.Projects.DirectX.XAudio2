using System;
using System.Runtime.InteropServices;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed version of XAUDIO2_BUFFER struct</summary>
    /// <remarks>May be freed once assigned via SubmitSourceBuffer, but not the internal pointer</remarks>
    [StructLayout(LayoutKind.Sequential)]
    public struct AudioBuffer
    {
        #region Constants
        public const UInt32 XAUDIO2_END_OF_STREAM = 0x0040;
        public const UInt32 XAUDIO2_MAX_BUFFER_BYTES = 0x80000000;
        public const UInt32 XMA_READBUFFER_MAX_BYTES = 0x7FF800;
        public const UInt32 XAUDIO2_MAX_LOOP_COUNT = 254;
        public const UInt32 XAUDIO2_LOOP_INFINITE = 255;
        #endregion


        #region Fields
        /// <summary>Flags that provide additional infor for the buffer.</summary>
	    /// <value>May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</value>
	    public UInt32 Flags;

	    /// <summary>Raw audio data of the PCM or WMA/XMA data.</summary>
	    /// <value>
	    ///		PCM length must be no larger than XAUDIO2_MAX_BUFFER_BYTES (0x80000000).
	    ///		XMA length must be no larger than XMA_READBUFFER_MAX_BYTES (4095u * 2048u = 8386560 = 0x7FF800).
	    /// </value>
	    public Byte[] AudioData;

	    /// <summary>First sample of the audio data to start playing</summary>
	    /// <remarks>XMA requires 128 modular alignment</remarks>
	    public UInt32 PlayBegin;

	    /// <summary>Length of sample of the audio data to play</summary>
	    /// <value>0 means entire buffer, but playBegin must also be 0</value>
	    /// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block.</remarks>
	    public UInt32 PlayLength;

	    /// <summary>First sample to loop from.</summary>
	    /// <value>Must be within the range of playBegin and playLength. Must be zero for xWMA. Must be 0 if count is 0.</value>
	    /// <remarks>XMA requires 128 modular alignment</remarks>
	    public UInt32 LoopBegin;

	    /// <summary>Length of samples to loop</summary>
	    /// <value>Must be within the range of playBegin and playLength. Must be 0 if count is 0.</value>
	    /// <remarks>XMA requires 128 modular alignment. ADPCM must be a multiple of samples per block. xWMA must be 0 or whole sample length</remarks>
	    public UInt32 LoopLength;

	    /// <summary>Count of iterations to loop</summary>
	    /// <value>Must be between 0 and XAUDIO2_MAX_LOOP_COUNT (254). To continuously loop, set to XAUDIO2_LOOP_INFINITE (255).</value>
	    /// <remarks>xWMA must be 0 or else flags must be set to XAUDIO2_END_OF_STREAM (0x0040)</remarks>
	    public UInt32 LoopCount;

	    /// <summary>Pointer to a buffer context, defined and used by the client software.</summary>
	    public IntPtr Context;
        #endregion


        #region Construction
		/// <summary>Default constructor</summary>
		public AudioBuffer()
        {
            this.Flags = 0U;
            this.AudioData = null;
            this.PlayBegin = 0U;
            this.PlayLength = 0U;
            this.LoopBegin = 0U;
            this.LoopLength = 0U;
            this.LoopCount = 0;
            this.Context = IntPtr.Zero;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="flagsCreation">Buffer flags. May be 0 or XAUDIO2_END_OF_STREAM (0x0040)</param>
		/// <param name="data">Audio data stream</param>
		/// <param name="beginPlay">Sample # within audio data to start playing</param>
		/// <param name="lengthPlay">Length of audio samples to play</param>
		/// <param name="beginLoop">Location to sample to start looping from</param>
		/// <param name="lengthLoop">Length of audio samples to loop</param>
		/// <param name="countLoop">Number of loops to complete looping</param>
		/// <param name="ptrContext">Client context pointer for this buffer</param>
        public AudioBuffer(UInt32 flagsCreation, Byte[] data, UInt32 beginPlay, UInt32 lengthPlay, UInt32 beginLoop, UInt32 lengthLoop, UInt32 countLoop, IntPtr ptrContext)
        {
            this.Flags = flagsCreation;
            this.AudioData = data;
            this.PlayBegin = beginPlay;
            this.PlayLength = lengthPlay;
            this.LoopBegin = beginLoop;
            this.LoopLength = lengthLoop;
            this.LoopCount = countLoop;
            this.Context = ptrContext;
        }
        #endregion
    }
}