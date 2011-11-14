
#include "Engine Callback.h"

using namespace Bardez::Projects::DirectX::XAudio2;

/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
System::IntPtr EngineCallback::CallbackPointer::get()
{
	return this->callbackPointer;
}

/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
void EngineCallback::CallbackPointer::set(System::IntPtr value)
{
	this->callbackPointer = value;
}



/// <summary>Adds an engine critical error delegate</summary>
/// <param name="handler">Delegate to add.</param>
void EngineCallback::CriticalError::add(XAudio2EngineCriticalErrorHandler^ handler)
{
    this->criticalError += handler;
}

/// <summary>Removes an engine critical error delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void EngineCallback::CriticalError::remove(XAudio2EngineCriticalErrorHandler^ handler)
{
    this->criticalError -= handler;
}

/// <summary>Called when the engine encounters a critical error</summary>
/// <param name="error">Error raised from the engine</param>
void EngineCallback::CriticalError::raise(ResultCode error)
{
    this->criticalError(error);
}

/// <summary>Adds an engine end processing pass delegate</summary>
/// <param name="handler">Delegate to add.</param>
void EngineCallback::ProcessingPassEnd::add(XAudio2EngineProcessingPassEndHandler^ handler)
{
    this->processingPassEnd += handler;
}

/// <summary>Removes an engine end processing pass delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void EngineCallback::ProcessingPassEnd::remove(XAudio2EngineProcessingPassEndHandler^ handler)
{
    this->processingPassEnd -= handler;
}

/// <summary>Called when the engine ends a processing pass</summary>
void EngineCallback::ProcessingPassEnd::raise()
{
    this->processingPassEnd();
}

/// <summary>Adds an engine start processing pass delegate</summary>
/// <param name="handler">Delegate to add.</param>
void EngineCallback::ProcessingPassStart::add(XAudio2EngineProcessingPassStartHandler^ handler)
{
    this->processingPassStart += handler;
}

/// <summary>Removes an engine start processing pass delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void EngineCallback::ProcessingPassStart::remove(XAudio2EngineProcessingPassStartHandler^ handler)
{
    this->processingPassStart -= handler;
}

/// <summary>Called when the engine starts a processing pass</summary>
void EngineCallback::ProcessingPassStart::raise()
{
    this->processingPassStart();
}