
#include "Debug Configuration.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Enabled debug messages</summary>
TraceMask DebugConfiguration::MaskTrace::get()
{
	return this->maskTrace;
}

/// <summary>Enabled debug messages</summary>
void DebugConfiguration::MaskTrace::set(TraceMask value)
{
	this->maskTrace = value;
}

/// <summary>Breaking messages</summary>
BreakMask DebugConfiguration::MaskBreak::get()
{
	return this->maskBreak;
}

/// <summary>Breaking messages</summary>
void DebugConfiguration::MaskBreak::set(BreakMask value)
{
	this->maskBreak = value;
}

/// <summary>Dictates whether or not to log the thread ID with each message</summary>
System::Boolean DebugConfiguration::LogThreadId::get()
{
	return this->logThreadId;
}

/// <summary>Dictates whether or not to log the thread ID with each message</summary>
void DebugConfiguration::LogThreadId::set(System::Boolean value)
{
	this->logThreadId = value;
}

/// <summary>Dictates whether or not to log the file and line numbers (code?) with each message</summary>
System::Boolean DebugConfiguration::LogFileline::get()
{
	return this->logFileline;
}

/// <summary>Dictates whether or not to log the file and line numbers (code?) with each message</summary>
void DebugConfiguration::LogFileline::set(System::Boolean value)
{
	this->logFileline = value;
}

/// <summary>Dictates whether or not to log the function names (code?) with each message</summary>
System::Boolean DebugConfiguration::LogFunctionName::get()
{
	return this->logFunctionName;
}

/// <summary>Dictates whether or not to log the function names (code?) with each message</summary>
void DebugConfiguration::LogFunctionName::set(System::Boolean value)
{
	this->logFunctionName = value;
}

/// <summary>Dictates whether or not to log the timestamps with each message</summary>
System::Boolean DebugConfiguration::LogTiming::get()
{
	return this->logTiming;
}

/// <summary>Dictates whether or not to log the timestamps with each message</summary>
void DebugConfiguration::LogTiming::set(System::Boolean value)
{
	this->logTiming = value;
}
#pragma endregion

					

#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="traceMsk">Tracing flags</param>
/// <param name="breakMk">Breaking flags</param>
/// <param name="threadId">Log the thread ID?</param>
/// <param name="fileLine">Log the file and line numbers?</param>
/// <param name="function">Log the function names?</param>
/// <param name="timing">Log the timing?</param>
DebugConfiguration::DebugConfiguration(TraceMask traceMsk, BreakMask breakMk, System::Boolean threadId, System::Boolean fileLine, System::Boolean function, System::Boolean timing)
{
	this->maskTrace = traceMsk;
	this->maskBreak = breakMk;
	this->logThreadId = threadId;
	this->logFileline = fileLine;
	this->logFunctionName = function;
	this->logTiming = timing;
}
					
/// <summary>Unmanaged constructor</summary>
/// <param name="config">Unmanaged source struct</param>
DebugConfiguration::DebugConfiguration(XAUDIO2_DEBUG_CONFIGURATION config)
{
	this->maskTrace = (TraceMask)config.TraceMask;
	this->maskBreak = (BreakMask)config.BreakMask;
	this->logThreadId = System::Convert::ToBoolean(config.LogThreadID);
	this->logFileline = System::Convert::ToBoolean(config.LogFileline);
	this->logFunctionName = System::Convert::ToBoolean(config.LogFunctionName);
	this->logTiming = System::Convert::ToBoolean(config.LogTiming);
}
#pragma endregion
				


#pragma region Methods
/// <summary>Generates an unmanaged version of the data</summary>
/// <returns>An unmanaged version of the wrapped struct</returns>
XAUDIO2_DEBUG_CONFIGURATION DebugConfiguration::ToUnmanaged()
{
	XAUDIO2_DEBUG_CONFIGURATION config;

	config.TraceMask = (UINT32)(this->maskTrace);
	config.BreakMask = (UINT32)(this->maskBreak);
	config.LogThreadID = System::Convert::ToUInt32(this->logThreadId);
	config.LogFileline = System::Convert::ToUInt32(this->logFileline);
	config.LogFunctionName = System::Convert::ToUInt32(this->logFunctionName);
	config.LogTiming = System::Convert::ToUInt32(this->logTiming);

	return config;
}
