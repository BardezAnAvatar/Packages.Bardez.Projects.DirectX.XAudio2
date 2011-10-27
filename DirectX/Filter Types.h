
#ifndef Bardez_Projects_Directx_XAudio2_FilterTypes
#define Bardez_Projects_Directx_XAudio2_FilterTypes

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Indicates whether a filter is low pass, band pass, high pass, or notch.</summary>
				[System::Flags]
				public enum struct FilterTypes
				{
					[System::ComponentModel::DescriptionAttribute("Attenuates frequencies above the cutoff frequency.")]
					LowPassFilter,

					[System::ComponentModel::DescriptionAttribute("Attenuates frequencies outside a given range.")]
					BandPassFilter,

					[System::ComponentModel::DescriptionAttribute("Attenuates frequencies below the cutoff frequency.")]
					HighPassFilter,

					[System::ComponentModel::DescriptionAttribute("Attenuates frequencies inside a given range.")]
					NotchFilter
				};
			}
		}
	}
}

#endif
