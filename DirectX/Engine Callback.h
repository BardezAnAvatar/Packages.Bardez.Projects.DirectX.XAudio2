
#ifndef Bardez_Projects_Directx_XAudio2_EngineCallback
#define Bardez_Projects_Directx_XAudio2_EngineCallback

#include "Callback Delegates.h"
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
					property System::IntPtr CallbackPointer
					{
						System::IntPtr get();
						void set(System::IntPtr value);
					}
				#pragma endregion


					

				#pragma region Events
				protected:
					/// <summary>Event for when an engine cirital error is raised</summary>
					event XAudio2EngineCriticalErrorHandler^ criticalError;

					/// <summary>Event for when an engine processing pass ends</summary>
					event XAudio2EngineProcessingPassEndHandler^ processingPassEnd;

					/// <summary>Event for when an engine processing pass starts</summary>
					event XAudio2EngineProcessingPassStartHandler^ processingPassStart;
				#pragma endregion


									
				#pragma region Event Exposure
				public:
					/// <summary>Event for when an engine cirital error is raised</summary>
					event XAudio2EngineCriticalErrorHandler^ CriticalError
					{
						void add(XAudio2EngineCriticalErrorHandler^ handler);
						void remove(XAudio2EngineCriticalErrorHandler^ handler);
						void raise(ResultCode error);
					}

					/// <summary>Event for when an engine processing pass ends</summary>
					event XAudio2EngineProcessingPassEndHandler^ ProcessingPassEnd
					{
						void add(XAudio2EngineProcessingPassEndHandler^ handler);
						void remove(XAudio2EngineProcessingPassEndHandler^ handler);
						void raise();
					}

					/// <summary>Event for when an engine processing pass starts</summary>
					event XAudio2EngineProcessingPassStartHandler^ ProcessingPassStart
					{
						void add(XAudio2EngineProcessingPassStartHandler^ handler);
						void remove(XAudio2EngineProcessingPassStartHandler^ handler);
						void raise();
					}
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