

#ifndef XAUDIO2_Volume_Meter_Levels
#define XAUDIO2_Volume_Meter_Levels


#include "IEffectParameter.h"
extern "C"
{
	#include <XAudio2fx.h>
}


using namespace System;
using namespace System::Collections::Generic;
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
					/// <summary>Managed representation of an XAudio2 XAUDIO2FX_VOLUMEMETER_LEVELS structure</summary>
					/// <remarks>Host to an I3DL2 standard compliant parameter set</remarks>
					public ref class VolumeMeterLevels : public IEffectParameter
					{
					#pragma region Fields
					protected:
						/// <summary>Collection of values indicating maximum absolute level for each channel over a processing pass</summary>
						/// <value>Must have <see cref="channelCount" /> elements or may be null if <see cref="rootMeanSquareLevels" /> is non-null.</value>
						IList<Single>^ peakLevels;

						/// <summary>Collection of values indicating maximum Root Mean Square level for each channel over a processing pass</summary>
						/// <value>Must have <see cref="channelCount" /> elements or may be null if <see cref="peakLevels" /> is non-null.</value>
						IList<Single>^ rootMeanSquareLevels;

						/// <summary>Number of channels being processed by the volume meter APO</summary>
						UInt32 channelCount;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Collection of values indicating maximum absolute level for each channel over a processing pass</summary>
						/// <value>Must have <see cref="ChannelCount" /> elements or may be null if <see cref="RootMeanSquareLevels" /> is non-null.</value>
						property IList<Single>^ PeakLevels
						{
							IList<Single>^ get();
							void set(IList<Single>^ value);
						}

						/// <summary>Collection of values indicating maximum Root Mean Square level for each channel over a processing pass</summary>
						/// <value>Must have <see cref="ChannelCount" /> elements or may be null if <see cref="PeakLevels" /> is non-null.</value>
						property IList<Single>^ RootMeanSquareLevels
						{
							IList<Single>^ get();
							void set(IList<Single>^ value);
						}

						/// <summary>Number of channels being processed by the volume meter APO</summary>
						property UInt32 ChannelCount
						{
							UInt32 get();
							void set(UInt32 value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						VolumeMeterLevels();

						/// <summary>Definition constructor</summary>
						/// <param name="peaks">Peak levels table</param>
						/// <param name="rms">Root mean square levels table</param>
						/// <param name="channels">Number of channels being processed</param>
						VolumeMeterLevels(IList<Single>^ peaks, IList<Single>^ rms, UInt32 channels);

					internal:
						/// <summary>Unmanaged constructor</summary>
						/// <param name="unmanaged">Source XAUDIO2FX_VOLUMEMETER_LEVELS structure</param>
						VolumeMeterLevels(const XAUDIO2FX_VOLUMEMETER_LEVELS* unmanaged);
						
						/// <summary>Unmanaged copy method</summary>
						/// <param name="unmanaged">Source XAUDIO2FX_VOLUMEMETER_LEVELS structure</param>
						void DefineFromUnmanaged(const XAUDIO2FX_VOLUMEMETER_LEVELS* unmanaged);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Returns an unmanaged version of this object</summary>
						/// <returns>An unmanaged XAUDIO2FX_VOLUMEMETER_LEVELS struct pointer</returns>
						XAUDIO2FX_VOLUMEMETER_LEVELS* ToUnmanaged();

						/// <summary>Releases up native memory allocated for an unmanaged XAUDIO2FX_VOLUMEMETER_LEVELS</summary>
						/// <param name="levels">The structure to release memory for</param>
						static void ReleaseMemory(XAUDIO2FX_VOLUMEMETER_LEVELS*& levels);

					public:
						/// <summary>Repopulated the managed copy from an unmanaged parameter struct</summary>
						/// <param name="source">Source pointer to the unmanaged parameter struct</param>
						/// <param name="size">Size of data located at the source pointer</param>
						/// <returns>A Reference to the Managed copy</returns>
						virtual void RepopulateFromUnmanaged(const void* source, UInt32 size);

						/// <summary>Generates the unmanaged data required for this type</summary>
						/// <param name="unmanaged">Output pointer to the unmanaged parameter struct</param>
						/// <param name="size">Output pointer to the size of data located at the source pointer</param>
						virtual void ToUnmanaged(void*& unmanaged, UInt32& size);

						/// <summary>Releases up native memory allocated for an unmanaged parameters structure</summary>
						/// <param name="data">The structure to release memory for</param>
						virtual void ReleaseMemory(void*& data);
					#pragma endregion
					};
				}
			}
		}
	}
}


#endif

