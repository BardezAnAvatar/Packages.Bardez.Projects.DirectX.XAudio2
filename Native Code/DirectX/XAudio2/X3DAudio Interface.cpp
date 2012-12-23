

#include "DSP Settings.h"
#include "X3DAudio Interface.h"


using namespace System;
using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>Gets the constant value of the X3DAudio's speed of sound</summary>
Single X3DAudio::SpeedOfSoundDefault::get()
{
	return X3DAUDIO_SPEED_OF_SOUND;
}
#pragma endregion



#pragma region Construction
/// <summary>X3DAudio constructor</summary>
/// <param name="channelMask">Assignment of channels to speaker positions. This value must not be zero.</param>
void X3DAudio::Initialize(UInt32 channelMask)
{
	X3DAudio::Initialize(channelMask, X3DAudio::SpeedOfSoundDefault);
}

/// <summary>X3DAudio constructor</summary>
/// <param name="channelMask">Assignment of channels to speaker positions. This value must not be zero.</param>
/// <param name="speedOfSound">Speed of sound, in user-defined world units per second. Use this value only for doppler calculations. It must be greater than or equal to FLT_MIN (1.175494351e-38F).</param>
void X3DAudio::Initialize(UInt32 channelMask, Single speedOfSound)
{
	//copy from manged to unmanaged
	pin_ptr<BYTE> pinHandle = &(X3DAudio::hX3DAudio[0]);
	BYTE* unmanaged = pinHandle;

	X3DAudioInitialize(channelMask, speedOfSound, unmanaged);
}
#pragma endregion



#pragma region Methods
/// <summary>Calculates DSP settings with respect to 3D parameters.</summary>
/// <param name="listener">Point of sound reception</param>
/// <param name="emitter">Point of sound emission</param>
/// <param name="flags">Flags indicating which calculations to perform</param>
/// <param name="settings">
///		Instance of a settings object to be used and later applied to the rendering graph.
///		The following members must be allocated (not set) before passing this structure to the this method:
///			* MatrixCoefficients
///			* DelayTimes
///			* ChannelCountSource
///			* ChannelCountDestination
///	</param>
void X3DAudio::CalculateAudio(Listener^ listener, Emitter^ emitter, X3DAudioCalculationFlags flags, DspSettings^ settings)
{
	//copy from manged to unmanaged
	pin_ptr<BYTE> pinHandle = &(X3DAudio::hX3DAudio[0]);
	const BYTE* unmanaged = pinHandle;

	//listener and emitter are just read-pointers
	X3DAUDIO_LISTENER* nativeListener = listener->ToUnmanaged();
	X3DAUDIO_EMITTER* nativeEmitter = emitter->ToUnmanaged();
	X3DAUDIO_DSP_SETTINGS* nativeSettings = settings->ToUnmanaged();

	//actual call
	X3DAudioCalculate(unmanaged, nativeListener, nativeEmitter, (UInt32)(flags), nativeSettings);

	//copy back the settings
	settings->PopulateFromUnmanaged(nativeSettings);

	/********************
	*	memory clean-up	*
	********************/
	Listener::ReleaseMemory(&nativeListener);
	Emitter::ReleaseMemory(&nativeEmitter);
	settings->ReleaseMemory(&nativeSettings);

	//unnecessary to copy back to managed handle, since it is passed in as const
	//X3DAudio::CopyFromUnmanged(unmanaged);
}
/*
/// <summary>Copies the Handle data from the managed static copy</summary>
/// <returns>An unmanaged copy of the handle data</returns>
X3DAUDIO_HANDLE X3DAudio::CopyFromManged()
{
	X3DAUDIO_HANDLE handle;

	for (Int32 index = 0; index < X3DAUDIO_HANDLE_BYTESIZE; ++index)
		handle[index] = X3DAudio::hX3DAudio[index];

	return handle;
}

/// <summary>Copies the Handle data from the ummanaged copy to the managed static copy</summary>
/// <param name="source">Unmanaged source to copy from</param>
void X3DAudio::CopyFromUnmanged(X3DAUDIO_HANDLE source)
{
	for (Int32 index = 0; index < X3DAUDIO_HANDLE_BYTESIZE; ++index)
		X3DAudio::hX3DAudio[index] = source[index];
}*/
#pragma endregion

