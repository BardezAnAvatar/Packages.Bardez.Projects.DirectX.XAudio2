

#ifndef Bardez_Projects_DirectX_XAudio2_XAPO_ReverbEffect
#define Bardez_Projects_DirectX_XAudio2_XAPO_ReverbEffect


extern "C"
{
	#include <XAudio2fx.h>
}
#include "IEffectBase.h"


using namespace System;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				namespace XAPO
				{
					/// <summary>Managed wrapper representing the built-in reverb XAPO effect</summary>
					public ref class EnvironmentalReverbEffect : public IEffectBase
					{
					#pragma region Fields
					protected:
						/// <summary>Pointer to the COM XAPO Reverb effect</summary>
						IntPtr nativeEffect;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
						virtual property IUnknown* UnmanagedPointer
						{
							IUnknown* get();
							void set(IUnknown* value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						EnvironmentalReverbEffect();

						/// <summary>Definition constructor</summary>
						/// <param name="flags">Flags used when constructing the reverb. Must be 0.</param>
						EnvironmentalReverbEffect(UInt32 flags);

					protected:
						/// <summary>Definition method</summary>
						/// <param name="flags">Flags used when constructing the reverb. Must be 0.</param>
						void CreateReverb(UInt32 flags);
					#pragma endregion



					#pragma region Destruction
					public:
						/// <summary>Destructor</summary>
						/// <remarks>Dispose()</remarks>
						~EnvironmentalReverbEffect();

						/// <summary>Destructor</summary>
						/// <remarks>Finalize()</remarks>
						!EnvironmentalReverbEffect();

						/// <summary>Destructor logic, disposes the object</summary>
						void DisposeUnmanaged();
					#pragma endregion



					#pragma region Methods
					public:
						/// <summary>Returns an empty instance of the related parameter type</summary>
						virtual IEffectParameter^ CreateParameters();
					#pragma endregion
					};
				}
			}
		}
	}
}


#endif

