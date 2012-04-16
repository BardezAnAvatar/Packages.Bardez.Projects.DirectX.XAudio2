using System;
using System.Runtime.InteropServices;
using System.Text;

using Bardez.Projects.Win32.Audio;
using Bardez.Projects.DirectX.XAudio2.Enums;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed XAUDIO2_DEVICE_DETAILS structure</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct DeviceDetails
    {
        #region Fields
		/// <summary>String identifier for the audio device</summary>
        /// <remarks>API is a WCHAR DeviceID[256]</remarks>
		public String DeviceId;

		/// <summary>Friendly name suitable for display to a human</summary>
        /// <remarks>API is a WCHAR DisplayName[256]</remarks>
		public String DisplayName;

		/// <summary>Roles that the device should be used for</summary>
		public DeviceRole DeviceRole;

		/// <summary>The device's native PCM audio output format</summary>
		public WaveFormatExtensible OutputFormat;
        #endregion


        #region ToString override
		/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
		/// <returns>A String representing the DeviceDetails Object contents</returns>
		public override String ToString()
		{
			StringBuilder builder = new StringBuilder();
			builder.Append("\tDevice ID:       ");
			builder.Append(this.DeviceId);
			builder.AppendLine(String.Empty);
			builder.Append("\tDevice name:     ");
			builder.Append(this.DisplayName);
			builder.AppendLine(String.Empty);
			builder.Append("\tDevice Role:     ");
			builder.Append(this.DeviceRole.ToString());
			builder.AppendLine(String.Empty);
			builder.AppendLine("Output format:");
			builder.Append(this.OutputFormat.ToString());
			builder.AppendLine(String.Empty);

			return builder.ToString();
		}
        #endregion
    }
}