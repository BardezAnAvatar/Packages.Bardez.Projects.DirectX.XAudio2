
#ifndef Bardez_Projects_Directx_XAudio2_FilterParameter
#define Bardez_Projects_Directx_XAudio2_FilterParameter

#include <xaudio2.h>
#include "Filter Types.h"

using namespace System;
using namespace Bardez::Projects::DirectX::XAudio2;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Defines parameters of a voice/filter.</summary>
				public ref class FilterParameter
				{
				#pragma region Members
				protected:
					/// <summary>Filter type indicating the type of filter pass of this filter.</summary>
					FilterTypes type;

					/// <summary>
					///		From MSDN: Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)).
					///		The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY (1.0f).
					///		The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds
					///		to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired
					///		cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for Frequency will be 1. 
					/// </summary>
					System::Single frequency;

					/// <summary>
					///		From MSDN: Reciprocal of Quality factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values
					///		result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0
					///		and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ (1.5f). 
					/// </summary>
					System::Single oneOverQ;
				#pragma endregion

				#pragma region Properties
				public:
					/// <summary>Filter type indicating the type of filter pass of this filter.</summary>
					property FilterTypes Type
					{
						FilterTypes get();
						void set(FilterTypes);
					}

					/// <summary>
					///		From MSDN: Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)).
					///		The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY (1.0f).
					///		The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds
					///		to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired
					///		cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for Frequency will be 1. 
					/// </summary>
					property System::Single Frequency
					{
						System::Single get();
						void set(System::Single);
					}

					/// <summary>
					///		From MSDN: Reciprocal of Q factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values
					///		result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0
					///		and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ (1.5f). 
					/// </summary>
					property System::Single OneOverQ
					{
						System::Single get();
						void set(System::Single);
					}
				#pragma endregion

				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					FilterParameter() {}

					/// <summary>Definition constructor</summary>
					/// <param name="filterType">Filter type</param>
					/// <param name="freq">Frequency</param>
					/// <param name="oneQ">One over Q</param>
					FilterParameter(FilterTypes filterType, System::Single freq, System::Single oneQ);

				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="params">Unmanaged parameters struct</param>
					FilterParameter(XAUDIO2_FILTER_PARAMETERS params);
				#pragma endregion
				

				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_FILTER_PARAMETERS struct</returns>
					XAUDIO2_FILTER_PARAMETERS ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif
