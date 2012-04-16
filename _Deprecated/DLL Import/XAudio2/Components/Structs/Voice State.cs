using System;
using System.Runtime.InteropServices;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed XAUDIO2_VOICE_STATE structure</summary>
    /// <remarks>Represents the voice's current state and cursor position data. Do not destroy the pointer, as it is used over and again by the client.</remarks>
    [StructLayout(LayoutKind.Sequential)]
    public struct VoiceState
    {
		#region Members
		/// <summary>Context for the buffer, for the client to define and use during callbacks</summary>
		public IntPtr BufferContext;

		/// <summary>Number of bufferes currently queued, including current bufer</summary>
        public UInt32 BuffersQueued;

		/// <summary>Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag).</summary>
		/// <remarks>
		///		This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured,
		///		this parameter would be the length of the audio stream in samples. If you specify XAUDIO2_VOICE_NOSAMPLESPLAYED when you call IXAudio2SourceVoice::GetState,
		///		this member won't be calculated, and its value is unspecified on return from IXAudio2SourceVoice::GetState.
		///		IXAudio2SourceVoice::GetState takes about one-third as much time to complete when you specify XAUDIO2_VOICE_NOSAMPLESPLAYED. XAudio2 2.8+ only.
		/// </remarks>
        public UInt64 SamplesPlayed;
		#endregion


		#region Construction
		/// <summary>Default constructor</summary>
		public VoiceState()
        {
            this.BufferContext = IntPtr.Zero;
            this.BuffersQueued = 0U;
            this.SamplesPlayed = 0UL;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="buffer">Buffer context defined and used by the client</param>
		/// <param name="buffers">Number of buffers queued</param>
		/// <param name="samples">Number of samples played so far</param>
        public VoiceState(IntPtr buffer, UInt32 buffers, UInt64 samples)
        {
            this.BufferContext = buffer;
            this.BuffersQueued = buffers;
            this.SamplesPlayed = samples;
        }
        #endregion
    }
}