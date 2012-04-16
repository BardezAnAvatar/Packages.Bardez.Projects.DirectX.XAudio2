using System;
using System.Runtime.InteropServices;

using Bardez.Projects.DirectX.XAudio2.Enums;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Defines parameters of a voice/filter.</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct FilterParameter
    {
        #region Constants
        public const Single XAUDIO2_MAX_FILTER_ONEOVERQ = 1.5F;
        public const Single XAUDIO2_MAX_FILTER_FREQUENCY = 1.0F;
        #endregion


        #region Fields
        /// <summary>Filter type indicating the type of filter pass of this filter.</summary>
        public FilterTypes Type;

        /// <summary>
        ///		From MSDN: Filter radian frequency calculated as (2 * sin(pi * (desired filter cutoff frequency) / sampleRate)).
        ///		The frequency must be greater than or equal to 0 and less than or equal to XAUDIO2_MAX_FILTER_FREQUENCY (1.0f).
        ///		The maximum frequency allowable is equal to the source sound's sample rate divided by six which corresponds
        ///		to the maximum filter radian frequency of 1. For example, if a sound's sample rate is 48000 and the desired
        ///		cutoff frequency is the maximum allowable value for that sample rate, 8000, the value for Frequency will be 1. 
        /// </summary>
        public Single Frequency;

        /// <summary>
        ///		From MSDN: Reciprocal of Q factor. Controls how quickly frequencies beyond Frequency are dampened. Larger values
        ///		result in quicker dampening while smaller values cause dampening to occur more gradually. Must be greater than 0
        ///		and less than or equal to XAUDIO2_MAX_FILTER_ONEOVERQ (1.5f). 
        /// </summary>
        public Single OneOverQ;
        #endregion


        #region Constrction
        /// <summary>Default constructor</summary>
        public FilterParameter()
        {
            this.Type = FilterTypes.NotchFilter;
            this.Frequency = 0.0F;
            this.OneOverQ = 0.0F;
        }

        /// <summary>Definition constructor</summary>
        /// <param name="filterType">Filter type</param>
        /// <param name="freq">Frequency</param>
        /// <param name="oneOverQ">One over Q</param>
        public FilterParameter(FilterTypes filterType, Single freq, Single oneOverQ)
        {
            this.Type = filterType;
            this.Frequency = freq;
            this.OneOverQ = oneOverQ;
        }
        #endregion
    }
}