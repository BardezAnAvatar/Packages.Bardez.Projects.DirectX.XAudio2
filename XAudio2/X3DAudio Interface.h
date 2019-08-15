
#ifndef Bardez_Projects_DirectX_X3DAudio_X3DAudio
#define Bardez_Projects_DirectX_X3DAudio_X3DAudio


#include <xaudio2.h>
#include <X3DAudio.h>
#include "Cone.h"
//#include "DSP Settings.h"
#include "Emitter.h"
#include "Listener.h"
#include "X3DAudio Calculation Flags.h"

//used to force the linker to link to the X3DAudio library
#pragma comment(lib, "X3DAudio.lib") //for CoInitializeEX, CoCreateInstance


using namespace System;
using namespace Bardez::Projects::DirectX::X3DAudio;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				//forward-declaration to allow for DSP Settings to reference X3DAudio's members
				ref class DspSettings;

				/// <summary>Represents a wrapper around an X3DAudio handle</summary>
				/// <remarks>There does not appear to be a destructor required</remarks>
				public ref class X3DAudio
				{
					#pragma region Fields
					protected:
						/// <summary>"Pointer" to an X3DAudio instance</summary>
						/// <remarks>This actually appears to be an array of 20 bytes rather than a pointer</remarks>
						array<Byte>^ hX3DAudio;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Exposes the constant value of the X3DAudio's speed of sound</summary>
						static property Single SpeedOfSoundDefault
						{
							/// <summary>Gets the constant value of the X3DAudio's speed of sound</summary>
							Single get();
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>X3DAudio constructor</summary>
						/// <param name="channelMask">Assignment of channels to speaker positions. This value must not be zero.</param>
						X3DAudio(UInt32 channelMask);

						/// <summary>X3DAudio constructor</summary>
						/// <param name="channelMask">Assignment of channels to speaker positions. This value must not be zero.</param>
						/// <param name="speedOfSound">Speed of sound, in user-defined world units per second. Use this value only for doppler calculations. It must be greater than or equal to FLT_MIN (1.175494351e-38F).</param>
						X3DAudio(UInt32 channelMask, Single speedOfSound);

						/// <summary>X3DAudio constructor</summary>
						/// <param name="channelMask">Assignment of channels to speaker positions. This value must not be zero.</param>
						/// <param name="speedOfSound">Speed of sound, in user-defined world units per second. Use this value only for doppler calculations. It must be greater than or equal to FLT_MIN (1.175494351e-38F).</param>
						void Initialize(UInt32 channelMask, Single speedOfSound);
					#pragma endregion



					#pragma region Methods
					public:
						/// <summary>Calculates DSP settings with respect to 3D parameters.</summary>
						/// <param name="listener">Point of sound reception</param>
						/// <param name="emitter">Point of sound emission</param>
						/// <param name="flags">Flags indicating which calculations to perform</param>
						/// <param name="settings">
						///		Instance of a settings object to be used and later applied to the rendering graph.
						///		The following members must be allocated (not set) before passing this structure to the this method:
						///			* MatrixCoefficients
						///			* DelayTimes
						///			* ChannelCountSource
						///			* ChannelCountDestination
						///	</param>
						void CalculateAudio(Listener^ listener, Emitter^ emitter, X3DAudioCalculationFlags flags, DspSettings^ settings);
					#pragma endregion
				};
			}
		}
	}
}

#endif
