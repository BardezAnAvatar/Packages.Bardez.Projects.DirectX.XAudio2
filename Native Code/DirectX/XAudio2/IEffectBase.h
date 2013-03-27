
#ifndef Bardez_Projects_Directx_XAPO_EffectBase
#define Bardez_Projects_Directx_XAPO_EffectBase


#include <windows.h>
#include <xaudio2.h>
#include "IEffectParameter.h"


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
					/// <summary>Interface for defining XAPO audio effect classes</summary>
					public interface class IEffectBase : public IDisposable
					{
					#pragma region Properties
					public:
						/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
						property IUnknown* UnmanagedPointer
						{
							IUnknown* get();
							void set(IUnknown* value);
						}
					#pragma endregion



					#pragma region Methods
					public:
						/// <summary>Returns an empty instance of the related parameter type</summary>
						IEffectParameter^ CreateParameters();
					#pragma endregion
					};
				}
			}
		}
	}
}
#endif
