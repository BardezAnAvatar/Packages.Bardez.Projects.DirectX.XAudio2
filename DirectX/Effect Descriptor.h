
#ifndef Bardez_Projects_Directx_XAudio2_EffectDescriptor
#define Bardez_Projects_Directx_XAudio2_EffectDescriptor

#include <xaudio2.h>
#include "Effect Base.h"

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
					EffectBase^ effect;

					/// <summary>Indicates whether or not to start the effect as enabled</summary>
					System::Boolean initialState;

					/// <summary>Number of channels the effect should output</summary>
					System::UInt32 outputChannels;
				#pragma endregion

				#pragma region Properties
				public:
					/// <summary>Reference to the effect object</summary>
					property EffectBase^ Effect
					{
						EffectBase^ get();
						void set(EffectBase^ value);
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

				internal:
					/// <summary>Pointer to the effect COM object/interface</summary>
					property IUnknown* UnmanagedEffect
					{
						IUnknown* get();
						void set(IUnknown* value);
					}
				#pragma endregion

				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					EffectDescriptor() {}

					/// <summary>Definition constructor</summary>
					/// <param name="effectObject">Reference to an effect object</param>
					/// <param name="enabled">Is the effect enabled?</param>
					/// <param name="channels">Output number of channels</param>
					EffectDescriptor(EffectBase^ effectObject, System::Boolean enabled, System::UInt32 channels);

				//internal:
				//	/// <summary>Definition constructor</summary>
				//	/// <param name="pointer">Pointer to the effect</param>
				//	/// <param name="enabled">Is the effect enabled?</param>
				//	/// <param name="channels">Output number of channels</param>
				//	EffectDescriptor(IUnknown* pointer, System::Boolean enabled, System::UInt32 channels);

				//	/// <summary>Unmanaged constructor</summary>
				//	/// <param name="params">Unmanaged parameters struct</param>
				//	EffectDescriptor(XAUDIO2_EFFECT_DESCRIPTOR params);
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
