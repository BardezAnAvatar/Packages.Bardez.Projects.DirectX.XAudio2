
#ifndef Bardez_Projects_Directx_XAPO_IEffectParameter
#define Bardez_Projects_Directx_XAPO_IEffectParameter

#include <windows.h>
#include <xaudio2.h>


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
					/// <summary>Interface for XAPO audio effect parameter classes</summary>
					public interface class IEffectParameter
					{
					#pragma region Methods
						/// <summary>Repopulated the managed copy from an unmanaged parameter struct</summary>
						/// <param name="source">Source pointer to the unmanaged parameter struct</param>
						/// <param name="size">Size of data located at the source pointer</param>
						/// <returns>A Reference to the Managed copy</returns>
						void RepopulateFromUnmanaged(const void* source, System::UInt32 size);

						/// <summary>Generates the unmanaged data required for this type</summary>
						/// <param name="unmanaged">Output pointer to the unmanaged parameter struct</param>
						/// <param name="size">Output pointer to the size of data located at the source pointer</param>
						void ToUnmanaged(void*& unmanaged, UInt32& size);

						/// <summary>Releases up native memory allocated for an unmanaged parameters structure</summary>
						/// <param name="data">The structure to release memory for</param>
						void ReleaseMemory(void*& data);
					#pragma endregion
					};
				}
			}
		}
	}
}

#endif

