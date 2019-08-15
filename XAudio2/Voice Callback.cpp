
#include "Voice Callback.h"

using namespace Bardez::Projects::DirectX::XAudio2;

/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
System::IntPtr VoiceCallback::CallbackPointer::get()
{
	return this->callbackPointer;
}

/// <summary>Pointer for the callback instance of the unmanaged callback</summary>
void VoiceCallback::CallbackPointer::set(System::IntPtr value)
{
	this->callbackPointer = value;
}




/// <summary>Adds a voice finish processing delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::BufferEnd::add(XAudio2VoiceBufferEndHandler^ handler)
{
    this->bufferEnd += handler;
}

/// <summary>Removes a voice finish processing delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::BufferEnd::remove(XAudio2VoiceBufferEndHandler^ handler)
{
    this->bufferEnd -= handler;
}

/// <summary>Called when the voice finishes processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::BufferEnd::raise(System::IntPtr bufferContext)
{
    this->bufferEnd(bufferContext);
}

/// <summary>Adds a voice start processing delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::BufferStart::add(XAudio2VoiceBufferStartHandler^ handler)
{
    this->bufferStart += handler;
}

/// <summary>Removes a voice start processing delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::BufferStart::remove(XAudio2VoiceBufferStartHandler^ handler)
{
    this->bufferStart -= handler;
}

/// <summary>Called when the voice starts processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::BufferStart::raise(System::IntPtr bufferContext)
{
    this->bufferStart(bufferContext);
}

/// <summary>Adds a voice finish processing loop delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::LoopEnd::add(XAudio2VoiceLoopEndHandler^ handler)
{
    this->loopEnd += handler;
}

/// <summary>Removes a voice finish processing loop delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::LoopEnd::remove(XAudio2VoiceLoopEndHandler^ handler)
{
    this->loopEnd -= handler;
}

/// <summary>Called when the voice finishes processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::LoopEnd::raise(System::IntPtr bufferContext)
{
    this->loopEnd(bufferContext);
}

/// <summary>Adds a voice finish processing stream delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::StreamEnd::add(XAudio2VoiceStreamEndHandler^ handler)
{
    this->streamEnd += handler;
}

/// <summary>Removes a voice finish processing stream delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::StreamEnd::remove(XAudio2VoiceStreamEndHandler^ handler)
{
    this->streamEnd -= handler;
}

/// <summary>Called when the voice finishes processing a stream</summary>
void VoiceCallback::StreamEnd::raise()
{
    this->streamEnd();
}

/// <summary>Adds a voice error raise delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::Error::add(XAudio2VoiceErrorHandler^ handler)
{
    this->error += handler;
}

/// <summary>Removes a voice error raise delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::Error::remove(XAudio2VoiceErrorHandler^ handler)
{
    this->error -= handler;
}

/// <summary>Called when the voice has an error raised</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
/// <param name="error">Error raised from the voice</param>
void VoiceCallback::Error::raise(System::IntPtr bufferContext, ResultCode error)
{
    this->error(bufferContext, error);
}

/// <summary>Adds a voice finish processing pass delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::ProcessingPassEnd::add(XAudio2VoiceProcessingPassEndHandler^ handler)
{
    this->processingPassEnd += handler;
}

/// <summary>Removes a voice finish processing pass delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::ProcessingPassEnd::remove(XAudio2VoiceProcessingPassEndHandler^ handler)
{
    this->processingPassEnd -= handler;
}

/// <summary>Called when the voice finishes processing a pass</summary>
void VoiceCallback::ProcessingPassEnd::raise()
{
    this->processingPassEnd();
}

/// <summary>Adds a voice start processing pass delegate</summary>
/// <param name="handler">Delegate to add.</param>
void VoiceCallback::ProcessingPassStart::add(XAudio2VoiceProcessingPassStartHandler^ handler)
{
    this->processingPassStart += handler;
}

/// <summary>Removes a voice start processing pass delegate</summary>
/// <param name="handler">Delegate to remove.</param>
void VoiceCallback::ProcessingPassStart::remove(XAudio2VoiceProcessingPassStartHandler^ handler)
{
    this->processingPassStart -= handler;
}

/// <summary>Called when the voice starts processing a pass</summary>
/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
void VoiceCallback::ProcessingPassStart::raise(System::UInt32 bytesRequired)
{
    this->processingPassStart(bytesRequired);
}

/// <summary>Called when the voice finishes processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::RaiseBufferEnd(System::IntPtr bufferContext)
{
	this->BufferEnd(bufferContext);
}

/// <summary>Called when the voice starts processing a buffer</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::RaiseBufferStart(System::IntPtr bufferContext)
{
    this->BufferStart(bufferContext);
}

/// <summary>Called when the voice finishes processing a loop</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
void VoiceCallback::RaiseLoopEnd(System::IntPtr bufferContext)
{
    this->LoopEnd(bufferContext);
}

/// <summary>Called when the voice finishes processing an audio stream</summary>
void VoiceCallback::RaiseStreamEnd()
{
    this->StreamEnd();
}

/// <summary>Called when the voice encounters a critical error</summary>
/// <param name="bufferContext">Pointer to a buffer context, defined and used by the client software.</param>
/// <param name="error">Error encountered</param>
void VoiceCallback::RaiseVoiceError(System::IntPtr bufferContext, ResultCode error)
{
	this->Error(bufferContext, error);
}

/// <summary>Called just after the processing pass for the voice ends</summary>
void VoiceCallback::RaiseVoiceProcessingPassEnd()
{
    this->ProcessingPassEnd();
}

/// <summary>Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.</summary>
/// <param name="bytesRequired">The number of bytes that need to be submitted to avoid voice starvation</param>
void VoiceCallback::RaiseVoiceProcessingPassStart(System::UInt32 bytesRequired)
{
    this->ProcessingPassStart(bytesRequired);
}

