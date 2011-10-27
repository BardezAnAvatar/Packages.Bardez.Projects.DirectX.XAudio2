
#ifndef Bardez_Projects_Directx_XAudio2_DebugConfiguration
#define Bardez_Projects_Directx_XAudio2_DebugConfiguration


#include "Break Mask.h"
#include "Trace Mask.h"


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed XAUDIO2_DEBUG_CONFIGURATION structure</summary>
				public ref class DebugConfiguration
				{
				#pragma region Members
				protected:
					/// <summary>Enabled debug messages</summary>
					TraceMask maskTrace;
					
					/// <summary>Breaking messages</summary>
					BreakMask maskBreak;
					
					/// <summary>Dictates whether or not to log the thread ID with each message</summary>
					System::Boolean logThreadId;
					
					/// <summary>Dictates whether or not to log the file and line numbers (code?) with each message</summary>
					System::Boolean logFileline;
					
					/// <summary>Dictates whether or not to log the function names (code?) with each message</summary>
					System::Boolean logFunctionName;
					
					/// <summary>Dictates whether or not to log the timestamps with each message</summary>
					System::Boolean logTiming;
				#pragma endregion

					

				#pragma region Properties
				public:
					/// <summary>Enabled debug messages</summary>
					property TraceMask MaskTrace
					{
						TraceMask get();
						void set(TraceMask value);
					}
					
					/// <summary>Breaking messages</summary>
					property BreakMask MaskBreak
					{
						BreakMask get();
						void set(BreakMask value);
					}
					
					/// <summary>Dictates whether or not to log the thread ID with each message</summary>
					property System::Boolean LogThreadId
					{
						System::Boolean get();
						void set(System::Boolean value);
					}
					
					/// <summary>Dictates whether or not to log the file and line numbers (code?) with each message</summary>
					property System::Boolean LogFileline
					{
						System::Boolean get();
						void set(System::Boolean value);
					}
					
					/// <summary>Dictates whether or not to log the function names (code?) with each message</summary>
					property System::Boolean LogFunctionName
					{
						System::Boolean get();
						void set(System::Boolean value);
					}
					
					/// <summary>Dictates whether or not to log the timestamps with each message</summary>
					property System::Boolean LogTiming
					{
						System::Boolean get();
						void set(System::Boolean value);
					}
				#pragma endregion

					

				#pragma region Construction
				public:
					/// <summary>Default constructor</summary>
					DebugConfiguration() {}

					/// <summary>Definition constructor</summary>
					/// <param name="traceMsk">Tracing flags</param>
					/// <param name="breakMk">Breaking flags</param>
					/// <param name="threadId">Log the thread ID?</param>
					/// <param name="fileLine">Log the file and line numbers?</param>
					/// <param name="function">Log the function names?</param>
					/// <param name="timing">Log the timing?</param>
					DebugConfiguration(TraceMask traceMsk, BreakMask breakMk, System::Boolean threadId, System::Boolean fileLine, System::Boolean function, System::Boolean timing);
					
				internal:
					/// <summary>Unmanaged constructor</summary>
					/// <param name="config">Unmanaged source struct</param>
					DebugConfiguration(XAUDIO2_DEBUG_CONFIGURATION config);
				#pragma endregion
				


				#pragma region Methods
				internal:
					/// <summary>Generates an unmanaged version of the data</summary>
					/// <returns>An unmanaged version of the wrapped struct</returns>
					XAUDIO2_DEBUG_CONFIGURATION ToUnmanaged();
				};
			}
		}
	}
}

#endif
