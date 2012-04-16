using System;
using System.ComponentModel;

namespace Bardez.Projects.DirectX.XAudio2.Enums
{
    /// <summary>Indicates whether a filter is low pass, band pass, high pass, or notch.</summary>
    [Flags]
    public enum FilterTypes
    {
		[Description("Attenuates frequencies above the cutoff frequency.")]
		LowPassFilter,

		[Description("Attenuates frequencies outside a given range.")]
		BandPassFilter,

		[Description("Attenuates frequencies below the cutoff frequency.")]
		HighPassFilter,

		[Description("Attenuates frequencies inside a given range.")]
		NotchFilter
    }
}