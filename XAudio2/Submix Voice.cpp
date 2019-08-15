

#include "Submix Voice.h"


using namespace Bardez::Projects::DirectX::XAudio2;


#pragma region Properties
/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
IXAudio2SubmixVoice* SubmixVoice::XAudio2SubmixVoice::get()
{
	return reinterpret_cast<IXAudio2SubmixVoice*>(this->ptrVoice.ToPointer());
}

/// <summary>Property to access the XAudio2MasteringVoice pointer, wrapping to a .NET IntPtr</summary>
void SubmixVoice::XAudio2SubmixVoice::set(IXAudio2SubmixVoice* value)
{
	this->ptrVoice = System::IntPtr(value);
}
#pragma endregion
					


#pragma region Construction
/// <summary>Definition constructor</summary>
/// <param name="pointer">Pointer to an XAudio2 submix voice interface object</param>
SubmixVoice::SubmixVoice(IXAudio2SubmixVoice* pointer)
{
	this->XAudio2SubmixVoice = pointer;
}
#pragma endregion
					


#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
SubmixVoice::~SubmixVoice()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
SubmixVoice::!SubmixVoice()
{
	this->DisposeUnmanaged();
}
#pragma endregion


