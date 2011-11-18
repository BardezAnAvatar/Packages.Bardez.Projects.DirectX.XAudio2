
#include "Filter Parameter.h"

using namespace Bardez::Projects::DirectX::XAudio2;

/// <summary>Filter type indicating the type of filter pass of this filter.</summary>
FilterTypes FilterParameter::Type::get()
{
	return this->type;
}

/// <summary>Filter type indicating the type of filter pass of this filter.</summary>
void FilterParameter::Type::set(FilterTypes value)
{
	this->type = value;
}

/// <summary>
///		From MSDN: Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)).
///		The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY (1.0f).
///		The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds
///		to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired
///		cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for Frequency will be 1. 
/// </summary>
System::Single FilterParameter::Frequency::get()
{
	return this->frequency;
}

/// <summary>
///		From MSDN: Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)).
///		The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY (1.0f).
///		The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds
///		to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired
///		cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for Frequency will be 1. 
/// </summary>
void FilterParameter::Frequency::set(System::Single value)
{
	this->frequency = value;
}

/// <summary>
///		From MSDN: Reciprocal of Q factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values
///		result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0
///		and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ (1.5f). 
/// </summary>
System::Single FilterParameter::OneOverQ::get()
{
	return this->oneOverQ;
}

/// <summary>
///		From MSDN: Reciprocal of Q factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values
///		result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0
///		and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ (1.5f). 
/// </summary>
void FilterParameter::OneOverQ::set(System::Single value)
{
	this->oneOverQ = value;
}

/// <summary>Definition constructor</summary>
/// <param name="filterType">Filter type</param>
/// <param name="freq">Frequency</param>
/// <param name="oneQ">One over Q</param>
FilterParameter::FilterParameter(FilterTypes filterType, System::Single freq, System::Single oneQ)
{
	this->type = filterType;
	this->frequency = freq;
	this->oneOverQ = oneQ;
}

/// <summary>Definition constructor</summary>
/// <param name="params">Unmanaged parameters struct</param>
FilterParameter::FilterParameter(XAUDIO2_FILTER_PARAMETERS params)
{
	this->type = (FilterTypes)params.Type;
	this->frequency = params.Frequency;
	this->oneOverQ = params.OneOverQ;
}

/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2_FILTER_PARAMETERS struct</returns>
XAUDIO2_FILTER_PARAMETERS FilterParameter::ToUnmanaged()
{
	XAUDIO2_FILTER_PARAMETERS unmanaged;

	unmanaged.Type = (XAUDIO2_FILTER_TYPE)this->type;
	unmanaged.Frequency = this->frequency;
	unmanaged.OneOverQ = this->OneOverQ;

	return unmanaged;
}