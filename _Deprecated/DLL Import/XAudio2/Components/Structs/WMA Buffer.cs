using System;
using System.Runtime.InteropServices;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed version of XAUDIO2_BUFFER_WMA struct</summary>
    /// <remarks>May be freed once assigned via SubmitSourceBuffer</remarks>
    [StructLayout(LayoutKind.Sequential)]
    public struct WmaBuffer
    {
        #region Fields
		/// <summary>Array of sizes of decoded packets</summary>
        public UInt32[] PacketDecodedSizes;
        #endregion


		#region Construction
		/// <summary>Default constructor</summary>
		public WmaBuffer()
        {
            this.PacketDecodedSizes = null;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="packetSizes">Array indicating sizes of decoded packets</param>
        public WmaBuffer(UInt32[] packetSizes)
        {
            this.PacketDecodedSizes = packetSizes;
        }
        #endregion
    }
}