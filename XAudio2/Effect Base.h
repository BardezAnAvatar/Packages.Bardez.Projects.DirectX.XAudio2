
#ifndef Bardez_Projects_Directx_XAPO_EffectBase
#define Bardez_Projects_Directx_XAPO_EffectBase

#include <windows.h>
#include <xaudio2.h>
#include "Effect Parameter Base.h"


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
					/// <summary>Base class for XAPO audio effect classes</summary>
					public ref class EffectBase abstract
					{
					#pragma region Members
					protected:
						/// <summary>The parameters to this effect</summary>
						EffectParameterBase^ parameters;
						
						/// <summary>Pointer to the effect COM object/interface</summary>
						System::IntPtr effect;
					#pragma endregion

					#pragma region Properties
					public:
						/// <summary>The parameters to this effect</summary>
						property EffectParameterBase^ Parameters
						{
							EffectParameterBase^ get();
							void set(EffectParameterBase^ value);
						}

						/// <summary>Pointer to the effect COM object/interface</summary>
						property System::IntPtr Effect
						{
							System::IntPtr get();
							void set(System::IntPtr value);
						}

					internal:
						/// <summary>Unmanaged pointer to the effect COM object/interface</summary>
						property IUnknown* UnmanagedEffect
						{
							IUnknown* get();
							void set(IUnknown* value);
						}
					#pragma endregion
					};
				}
			}
		}
	}
}
#endif
