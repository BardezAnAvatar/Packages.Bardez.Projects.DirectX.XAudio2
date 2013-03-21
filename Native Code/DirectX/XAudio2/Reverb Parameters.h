

#ifndef XAUDIO2_Reverberation_Parameters
#define XAUDIO2_Reverberation_Parameters


#include <XAudio2fx.h>
#include "IEffectParameter.h"


using namespace System;
using namespace Bardez::Projects::DirectX::XAudio2::XAPO;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				namespace FX
				{
					/// <summary>Managed representation of an XAudio2 XAUDIO2FX_REVERB_PARAMETERS structure</summary>
					public ref class ReverbParameters : public IEffectParameter
					{
					#pragma region Fields
					protected:
						/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						Single wetDryMix;
						
						#pragma region Delay Times
						/// <summary>The delay time of the first reflection relative to the direct path</summary>
						/// <value>Clamped from 0 to 300, in miliseconds</value>
						UInt32 reflectionsDelay;

						/// <summary>Delay of reverb relative to the first reflection</summary>
						/// <value>Clamped from 0 to 85, in miliseconds</value>
						Byte reverbDelay;

						/// <summary>Delay for the left rear output and right rear output</summary>
						/// <value>Clamped from 0 to 5, in miliseconds</value>
						Byte rearDelay;
						#pragma endregion

						
						#pragma region Indexed parameters
						/// <summary>Position of the left input within the simulated space relative to the listener</summary>
						/// <value>Clamped from 0 to 30, no units</value>
						/// <remarks>
						///		With PositionLeft set to the minimum value, the left input is placed close to the listener.
						///		In this position, early reflections are dominant, and the reverb decay is set back in the sound field and reduced in amplitude.
						///		With PositionLeft set to the maximum value, the left input is placed at a maximum distance from the listener within the simulated room.
						///		PositionLeft does not affect the reverb decay time (liveness of the room), only the apparent position of the source relative to the listener.
						///		Permitted range is from 0 to 30 (no units).
						/// </remarks>
						Byte positionLeft;
						
						/// <summary>Position of the right input within the simulated space relative to the listener</summary>
						/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
						/// <remarks>Same as <see cref="positionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
						Byte positionRight;

						/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
						/// <value>Clamped from 0 to 30, no units</value>
						Byte positionMatrixLeft;

						/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
						/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
						Byte positionMatrixRight;
						
						/// <summary>Controls the character of the individual wall reflections</summary>
						/// <value>Clamped from 0 to 15, no units</value>
						/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
						Byte earlyDiffusion;
						
						/// <summary>Controls the character of the individual wall reverberations</summary>
						/// <value>Clamped from 0 to 15, no units</value>
						/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
						Byte lateDiffusion;
						
						/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
						/// <value>Clamped from 0 to 12, no units</value>
						/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
						Byte lowEQGain;
						
						/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
						/// <value>Clamped from 0 to 9, no units</value>
						Byte lowEQCutoff;
						
						/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
						/// <value>Clamped from 0 to 8, no units</value>
						/// <remarks>A value of 8 yields no effective change</remarks>
						Byte highEQGain;
						
						/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="highEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
						/// <value>Clamped from 0 to 14, no units</value>
						Byte highEQCutoff;
						#pragma endregion


						#pragma region Direct parameters
						/// <summary>Sets the corner frequency of the low pass filter for the room effect</summary>
						/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
						/// <remarks>
						///		All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates.
						///		For example, setting ReflectionsDelay to 300ms gives a true 300ms delay when the reverb is hosted in a 48kHz voice,
						///		but becomes a 150ms delay when hosted in a 24kHz voice.
						///	</remarks>
						Single roomFilterFrequency;
						
						/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
						/// <value>Clamped from -100 to 0, in dB (decibels)</value>
						Single roomFilterMain;
						
						/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="roomFilterFrequency" />). </summary>
						/// <value>Clamped from -100 to 0, in dB (decibels)</value>
						Single roomFilterHighFrequency;

						/// <summary>Adjusts the intensity of the early reflections</summary>
						/// <value>Clamped from -100 to 20, in dB (decibels)</value>
						Single reflectionsGain;
						
						/// <summary>Adjusts the intensity of the reverberations</summary>
						/// <value>Clamped from -100 to 20, in dB (decibels)</value>
						Single reverbGain;
						
						/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
						/// <value>Clamped from 0.1 to infinity, in seconds</value>
						Single decayTime;
						
						/// <summary>Controls the modal density in the late field reverberation</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						/// <remarks>
						///		For colorless spaces, Density should be set to the maximum value (100).
						///		As Density is decreased, the sound becomes hollow (comb filtered).
						///		This is an effect that can be useful if you are trying to model a silo.
						///	</remarks>
						Single density;
						
						/// <summary>The apparent size of the acoustic space</summary>
						/// <value>Clamped from 1 to 100, in feet</value>
						Single roomSize;
						#pragma endregion
					#pragma endregion


						
					#pragma region Properties
					public:
						/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						property Single WetDryMix
						{
							Single get();
							void set(Single value);
						}
						
					#pragma region Delay Times
						/// <summary>The delay time of the first reflection relative to the direct path</summary>
						/// <value>Clamped from 0 to 300, in miliseconds</value>
						property UInt32 ReflectionsDelay
						{
							UInt32 get();
							void set(UInt32 value);
						}

						/// <summary>Delay of reverb relative to the first reflection</summary>
						/// <value>Clamped from 0 to 85, in miliseconds</value>
						property Byte ReverbDelay
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Delay for the left rear output and right rear output</summary>
						/// <value>Clamped from 0 to 5, in miliseconds</value>
						property Byte RearDelay
						{
							Byte get();
							void set(Byte value);
						}
					#pragma endregion

						
					#pragma region Indexed parameters
						/// <summary>Position of the left input within the simulated space relative to the listener</summary>
						/// <value>Clamped from 0 to 30, no units</value>
						/// <remarks>
						///		With PositionLeft set to the minimum value, the left input is placed close to the listener.
						///		In this position, early reflections are dominant, and the reverb decay is set back in the sound field and reduced in amplitude.
						///		With PositionLeft set to the maximum value, the left input is placed at a maximum distance from the listener within the simulated room.
						///		PositionLeft does not affect the reverb decay time (liveness of the room), only the apparent position of the source relative to the listener.
						///		Permitted range is from 0 to 30 (no units).
						/// </remarks>
						property Byte PositionLeft
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Position of the right input within the simulated space relative to the listener</summary>
						/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
						/// <remarks>Same as <see cref="PositionLeft" />, but affecting only the right input. Ignored in mono-in/mono-out mode.</remarks>
						property Byte PositionRight
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
						/// <value>Clamped from 0 to 30, no units</value>
						property Byte PositionMatrixLeft
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Gives a greater or lesser impression of distance from the source to the listener</summary>
						/// <value>Clamped from 0 to 30, no units, ignored when configured to mono</value>
						property Byte PositionMatrixRight
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Controls the character of the individual wall reflections</summary>
						/// <value>Clamped from 0 to 15, no units</value>
						/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
						property Byte EarlyDiffusion
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Controls the character of the individual wall reverberations</summary>
						/// <value>Clamped from 0 to 15, no units</value>
						/// <remarks>Set to minimum value to simulate a hard flat surface and to maximum value to simulate a diffuse surface</remarks>
						property Byte LateDiffusion
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Adjusts the decay time of low frequencies relative to the decay time at 1 kHz. This represents a gain in dB; add "-8" to the value specified to yield the actual gain in dB.</summary>
						/// <value>Clamped from 0 to 12, no units</value>
						/// <remarks>Since value -8 yields actual dB gain, a value of 8 (net = 0) results in the decay time of low frequencies being equal to the decay time at 1 kHz.</remarks>
						property Byte LowEQGain
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Sets the corner frequency of the low pass filter that is controlled by the LowEQGain parameter. Increments frequency in steps of 50, with 0 indicating 50 and 9 indicating 500.</summary>
						/// <value>Clamped from 0 to 9, no units</value>
						property Byte LowEQCutoff
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Adjusts the decay time of high frequencies relative to the decay time at 1 kHz. add "-8" to the value to yield the actual gain</summary>
						/// <value>Clamped from 0 to 8, no units</value>
						/// <remarks>A value of 8 yields no effective change</remarks>
						property Byte HighEQGain
						{
							Byte get();
							void set(Byte value);
						}
						
						/// <summary>Sets the corner frequency of the high pass filter that is controlled by the <see cref="HighEQGain" /> parameter. Value increments in 0.5 kHz, with 0 yielding 1kHz and 14 yielding 8 khZ</summary>
						/// <value>Clamped from 0 to 14, no units</value>
						property Byte HighEQCutoff
						{
							Byte get();
							void set(Byte value);
						}
					#pragma endregion


					#pragma region Direct parameters
						/// <summary>Sets the corner frequency of the low pass filter for the room effect</summary>
						/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
						/// <remarks>
						///		All parameters related to sampling rate or time are relative to a 48kHz sampling rate and must be scaled for use with other sampling rates.
						///		For example, setting ReflectionsDelay to 300ms gives a true 300ms delay when the reverb is hosted in a 48kHz voice,
						///		but becomes a 150ms delay when hosted in a 24kHz voice.
						///	</remarks>
						property Single RoomFilterFrequency
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</summary>
						/// <value>Clamped from -100 to 0, in dB (decibels)</value>
						property Single RoomFilterMain
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency (<see cref="RoomFilterFrequency" />). </summary>
						/// <value>Clamped from -100 to 0, in dB (decibels)</value>
						property Single RoomFilterHighFrequency
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Adjusts the intensity of the early reflections</summary>
						/// <value>Clamped from -100 to 20, in dB (decibels)</value>
						property Single ReflectionsGain
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Adjusts the intensity of the reverberations</summary>
						/// <value>Clamped from -100 to 20, in dB (decibels)</value>
						property Single ReverbGain
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Reverberation decay time at 1 kHz. This is the time that a full scale input signal decays by 60 dB</summary>
						/// <value>Clamped from 0.1 to infinity, in seconds</value>
						property Single DecayTime
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>Controls the modal density in the late field reverberation</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						/// <remarks>
						///		For colorless spaces, Density should be set to the maximum value (100).
						///		As Density is decreased, the sound becomes hollow (comb filtered).
						///		This is an effect that can be useful if you are trying to model a silo.
						///	</remarks>
						property Single Density
						{
							Single get();
							void set(Single value);
						}
						
						/// <summary>The apparent size of the acoustic space</summary>
						/// <value>Clamped from 1 to 100, in feet</value>
						property Single RoomSize
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						ReverbParameters();

						/// <summary>Definition constructor</summary>
						/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
						/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
						/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
						/// <param name="rearDelay">Delay for the left rear output and right rear output</param>
						/// <param name="positionLeft">Position of the left input within the simulated space relative to the listener</param>
						/// <param name="positionRight">Position of the right input within the simulated space relative to the listener</param>
						/// <param name="positionMatrixLeft">Gives a greater or lesser impression of distance from the source to the listener</param>
						/// <param name="positionMatrixRight">Gives a greater or lesser impression of distance from the source to the listener</param>
						/// <param name="earlyDiffusion">Controls the character of the individual wall reflections</param>
						/// <param name="lateDiffusion">Controls the character of the individual wall reverberations</param>
						/// <param name="lowEQgain">Adjusts the decay time of low frequencies relative to the decay time at 1 kHz</param>
						/// <param name="lowEQcutoff">Sets the corner frequency of the low pass filter that is controlled by the lowEQgain parameter</param>
						/// <param name="highEQgain">Adjusts the decay time of high frequencies relative to the decay time at 1 kHz</param>
						/// <param name="highEQcutoff">Sets the corner frequency of the high pass filter that is controlled by the highEQgain parameter</param>
						/// <param name="roomFilterFrequency">Sets the corner frequency of the low pass filter for the room effect</param>
						/// <param name="roomFilterMain">Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</param>
						/// <param name="roomFilterHighFrequency">Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency.</param>
						/// <param name="reflectionsGain">Adjusts the intensity of the early reflections</param>
						/// <param name="reverbGain">Adjusts the intensity of the reverberations</param>
						/// <param name="decayTime">Reverberation decay time at 1 kHz. </param>
						/// <param name="density">Controls the modal density in the late field reverberation</param>
						/// <param name="roomSize">The apparent size of the acoustic space</param>
						ReverbParameters(Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
							Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
							Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
							Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain, Single reverbGain,
							Single decayTime, Single density, Single roomSize);

					internal:
						/// <summary>Unmanaged copy constructor</summary>
						/// <param name="unmanaged">Unmanaged instance to copy from</param>
						ReverbParameters(XAUDIO2FX_REVERB_PARAMETERS* unmanaged);
						
						/// <summary>Unmanaged copy method</summary>
						/// <param name="unmanaged">Unmanaged instance to copy from</param>
						void DefineFromUnmanaged(XAUDIO2FX_REVERB_PARAMETERS* unmanaged);

					protected:
						/// <summary>Definition method</summary>
						/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
						/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
						/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
						/// <param name="rearDelay">Delay for the left rear output and right rear output</param>
						/// <param name="positionLeft">Position of the left input within the simulated space relative to the listener</param>
						/// <param name="positionRight">Position of the right input within the simulated space relative to the listener</param>
						/// <param name="positionMatrixLeft">Gives a greater or lesser impression of distance from the source to the listener</param>
						/// <param name="positionMatrixRight">Gives a greater or lesser impression of distance from the source to the listener</param>
						/// <param name="earlyDiffusion">Controls the character of the individual wall reflections</param>
						/// <param name="lateDiffusion">Controls the character of the individual wall reverberations</param>
						/// <param name="lowEQgain">Adjusts the decay time of low frequencies relative to the decay time at 1 kHz</param>
						/// <param name="lowEQcutoff">Sets the corner frequency of the low pass filter that is controlled by the lowEQgain parameter</param>
						/// <param name="highEQgain">Adjusts the decay time of high frequencies relative to the decay time at 1 kHz</param>
						/// <param name="highEQcutoff">Sets the corner frequency of the high pass filter that is controlled by the highEQgain parameter</param>
						/// <param name="roomFilterFrequency">Sets the corner frequency of the low pass filter for the room effect</param>
						/// <param name="roomFilterMain">Sets the pass band intensity level of the low-pass filter for both the early reflections and the late field reverberation</param>
						/// <param name="roomFilterHighFrequency">Sets the intensity of the low-pass filter for both the early reflections and the late field reverberation at the corner frequency.</param>
						/// <param name="reflectionsGain">Adjusts the intensity of the early reflections</param>
						/// <param name="reverbGain">Adjusts the intensity of the reverberations</param>
						/// <param name="decayTime">Reverberation decay time at 1 kHz. </param>
						/// <param name="density">Controls the modal density in the late field reverberation</param>
						/// <param name="roomSize">The apparent size of the acoustic space</param>
						void DefineReverbParameters(Single wetDry, UInt32 reflectionsDelay, Byte reverbDelay, Byte rearDelay,
							Byte positionLeft, Byte positionRight, Byte positionMatrixLeft, Byte positionMatrixRight,
							Byte earlyDiffusion, Byte lateDiffusion, Byte lowEQgain, Byte lowEQcutoff, Byte highEQgain, Byte highEQcutoff,
							Single roomFilterFrequency, Single roomFilterMain, Single roomFilterHighFrequency, Single reflectionsGain, Single reverbGain,
							Single decayTime, Single density, Single roomSize);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Returns an unmanaged version of this object</summary>
						/// <returns>An unmanaged XAUDIO2FX_REVERB_PARAMETERS struct pointer</returns>
						XAUDIO2FX_REVERB_PARAMETERS* ToUnmanaged();

						/// <summary>Generates the unmanaged data required for this type</summary>
						/// <param name="unmanaged">Output pointer to the unmanaged parameter struct</param>
						/// <param name="size">Output pointer to the size of data located at the source pointer</param>
						virtual void ToUnmanaged(void** unmanaged, UInt32* size);

						/// <summary>Releases up native memory allocated for an unmanaged XAUDIO2FX_REVERB_PARAMETERS</summary>
						/// <param name="levels">The structure to release memory for</param>
						static void ReleaseMemory(XAUDIO2FX_REVERB_PARAMETERS** reverb);

						/// <summary>Releases up native memory allocated for an unmanaged parameters structure</summary>
						/// <param name="data">The structure to release memory for</param>
						virtual void ReleaseMemory(void** data);

						/// <summary>Repopulated the managed copy from an unmanaged parameter struct</summary>
						/// <param name="source">Source pointer to the unmanaged parameter struct</param>
						/// <param name="size">Size of data located at the source pointer</param>
						/// <returns>A Reference to the Managed copy</returns>
						virtual void RepopulateFromUnmanaged(void* source, UInt32 size);
					#pragma endregion
					};
				}
			}
		}
	}
}


#endif

