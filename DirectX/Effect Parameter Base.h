
#ifndef Bardez_Projects_Directx_XAPO_EffectParameterBase
#define Bardez_Projects_Directx_XAPO_EffectParameterBase

#include <windows.h>
#include <xaudio2.h>

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
					/// <summary>Base class for XAPO audio effect parameter classes</summary>
					public ref class EffectParameterBase abstract
					{
					#pragma region Members
					protected:
						/// <summary>The internal pointer</summary>
						System::IntPtr unmanagedStruct;
					#pragma endregion



					#pragma region Properties
					internal:
						/// <summary>Returns the internal pointer</summary>
						virtual property void* UnmanagedReference
						{
							void* get() abstract;
							void set(void* value) abstract;
						}

						/// <summary>Returns the unmanaged size</summary>
						virtual property System::UInt32 UnmanagedSize
						{
							System::UInt32 get() abstract;
							void set(System::UInt32 value) abstract;
						}
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generates a managed copy of an unmanaged parameter struct</summary>
						/// <param name="source">Source pointer to the unmanaged parameter struct</param>
						/// <returns>A Reference to the Managed copy</returns>
						virtual EffectParameterBase^ GenerateFromUnmanaged(void* source) abstract;
					#pragma endregion
					};
				}
			}
		}
	}
}

#endif
