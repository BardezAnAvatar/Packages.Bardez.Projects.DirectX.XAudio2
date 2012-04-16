using System;
using System.Runtime.InteropServices;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Defines the voice output to another voice. Managed wrapper of XAUDIO2_SEND_DESCRIPTOR.</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct VoiceSendDescriptor
    {
        #region Constants
        public const UInt32 XAUDIO2_SEND_USEFILTER = 0x0080;
        #endregion


        #region Fields
        /// <summary>Indicates whether filter should be used on data sent to the voice.</summary>
		/// <value>Flags can be 0 or XAUDIO2_SEND_USEFILTER (0x0080)</value>
		public UInt32 Flags;

		/// <summary>Voice to be the target of the send. Cannot be null without error.</summary>
		public Voice OutputVoice;
		#endregion
        

		#region Construction
		/// <summary>Default constructor</summary>
		public VoiceSendDescriptor()
        {
            this.Flags = 0U;
            this.OutputVoice = null;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="flag">Indicates whether filter should be used on data sent to the voice</param>
		/// <param name="target">Voice to be the target of the send. Cannot be null without error</param>
		public VoiceSendDescriptor(UInt32 flag, Voice target)
        {
            this->Flags = flag;
            this->OutputVoice = target;
        }
        #endregion
    }
}