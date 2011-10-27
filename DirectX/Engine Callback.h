
#ifndef Bardez_Projects_Directx_XAudio2_EngineCallback
#define Bardez_Projects_Directx_XAudio2_EngineCallback

#include "Result Codes.h"

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Callback from the XAudio2 engine</summary>
				public ref class EngineCallback
				{
				#pragma region Members
				internal:
					/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
					System::IntPtr callbackPointer;
				#pragma endregion



				#pragma region Properties
				internal:
					/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
					property System::IntPtr CallbackPointer;
				#pragma endregion



				#pragma region Methods
				public:
					/// <summary>Called after a critical system error occurs</summary>
					/// <param name="error">Passed in error code</param>
					virtual void OnCriticalError(ResultCode error) { }

					/// <summary>Called just after an audio processing pass ends</summary>
					virtual void OnProcessingPassEnd() { }

					/// <summary>Called just after an audio processing pass starts</summary>
					virtual void OnProcessingPassStart() { }
				#pragma endregion
				};
			}
		}
	}
}

#endif