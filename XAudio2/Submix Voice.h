
#ifndef Bardez_Projects_Directx_XAudio2_SubmixVoice
#define Bardez_Projects_Directx_XAudio2_SubmixVoice

#include <XAudio2.h>
#include "Version.h"
#include "Voice.h"

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Submix Voice interim voice for the Voice audio graph</summary>
				/// <remarks>
				///		The [class] type exists solely because some of the base class methods are implemented differently for submix voices.
				///		Having a separate type for these voices helps client code to distinguish the different voice types and to benefit from C++ type safety.
				///	</remarks>
				public ref class SubmixVoice : Voice
				{
				#pragma region Properties
				internal:
					/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
					property IXAudio2SubmixVoice* XAudio2SubmixVoice
					{
						IXAudio2SubmixVoice* get();
						void set(IXAudio2SubmixVoice* value);
					}
				#pragma endregion
					


				#pragma region Construction
				internal:
					/// <summary>Definition constructor</summary>
					/// <param name="pointer">Pointer to an XAudio2 submix voice interface object</param>
					SubmixVoice(IXAudio2SubmixVoice* pointer);
				#pragma endregion
					


				#pragma region Destruction
				public:
					/// <summary>Destructor</summary>
					/// <remarks>Dispose()</remarks>
					~SubmixVoice();

					/// <summary>Destructor</summary>
					/// <remarks>Finalize()</remarks>
					!SubmixVoice();
				#pragma endregion
				};
			}
		}
	}
}

#endif

