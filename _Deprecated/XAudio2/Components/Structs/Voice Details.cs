using System;
using System.Runtime.InteropServices;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed XAUDIO2_VOICE_DETAILS structure</summary>
    /// <remarks>
    ///		The documentation definition
    ///		(http://msdn.microsoft.com/en-us/library/windows/desktop/microsoft.directx_sdk.xaudio2.xaudio2_voice_details%28v=vs.85%29.aspx)
    ///		conflicts with xaudio2.h definition
    ///	</remarks>
    [StructLayout(LayoutKind.Sequential)]
    public struct VoiceDetails
    {
        #region Fields
		/// <summary>Flags to create voice, abstracted values by voice type</summary>
		public UInt32 CreationFlags;

		/// <summary>Number of expected input channels</summary>
        public UInt32 InputChannels;

		/// <summary>Expected input sample sample rate</summary>
        public UInt32 InputSampleRate;
        #endregion
        

		#region Construction
		/// <summary>Default constructor</summary>
		public VoiceDetails()
        {
            this.CreationFlags = 0U;
            this.InputChannels = 0U;
            this.InputSampleRate = 0U;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="flagsCreation">Creation flags</param>
		/// <param name="channels">Number of input channels</param>
		/// <param name="rate">Input sample rate</param>
        public VoiceDetails(UInt32 flagsCreation, UInt32 channels, UInt32 rate)
        {
            this.CreationFlags = flagsCreation;
            this.InputChannels = channels;
            this.InputSampleRate = rate;
        }
		#endregion
    }
}