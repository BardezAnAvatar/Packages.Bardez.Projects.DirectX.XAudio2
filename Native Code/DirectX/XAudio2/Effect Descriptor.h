
#ifndef Bardez_Projects_Directx_XAudio2_EffectDescriptor
#define Bardez_Projects_Directx_XAudio2_EffectDescriptor


#include <xaudio2.h>
#include "IEffectBase.h"


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
				/// <summary>Defines parameters of a voice/filter.</summary>
				public ref class EffectDescriptor
				{
				#pragma region Members
				protected:
					/// <summary>Reference to the effect object</summary>
					IEffectBase^ effect;

					/// <summary>Indicates whether or not to start the effect as enabled</summary>
					System::Boolean initialState;

					/// <summary>Number of channels the effect should output</summary>
					System::UInt32 outputChannels;
				#pragma endregion



				#pragma region Properties
				public:
					/// <summary>Reference to the effect object</summary>
					property IEffectBase^ Effect
					{
						IEffectBase^ get();
						void set(IEffectBase^ value);
					}

					/// <summary>Indicates whether or not to start the effect as enabled</summary>
					property System::Boolean InitialState
					{
						System::Boolean get();
						void set(System::Boolean value);
					}

					/// <summary>Number of channels the effect should output</summary>
					property System::UInt32 OutputChannels
					{
						System::UInt32 get();
						void set(System::UInt32 value);
					}
				#pragma endregion



				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					EffectDescriptor() {}

					/// <summary>Definition constructor</summary>
					/// <param name="effectObject">Reference to an effect object</param>
					/// <param name="enabled">Flag indicating whether the effect enabled initially</param>
					/// <param name="channels">Output number of channels</param>
					EffectDescriptor(IEffectBase^ effectObject, System::Boolean enabled, System::UInt32 channels);
				#pragma endregion
				


				#pragma region Methods
				internal:
					/// <summary>Returns an unmanaged version of this object</summary>
					/// <returns>An unmanaged XAUDIO2_FILTER_PARAMETERS struct</returns>
					XAUDIO2_EFFECT_DESCRIPTOR ToUnmanaged();
				#pragma endregion
				};
			}
		}
	}
}

#endif

