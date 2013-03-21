

#include "Volume Meter Levels.h"


using namespace Bardez::Projects::DirectX::XAudio2::FX;


#pragma region Properties
/// <summary>Collection of values indicating maximum absolute level for each channel over a processing pass</summary>
/// <value>Must have <see cref="ChannelCount" /> elements or may be null if <see cref="RootMeanSquareLevels" /> is non-null.</value>
IList<Single>^ VolumeMeterLevels::PeakLevels::get()
{
	return this->peakLevels;
}

/// <summary>Collection of values indicating maximum absolute level for each channel over a processing pass</summary>
/// <param name="value">Must have <see cref="ChannelCount" /> elements or may be null if <see cref="RootMeanSquareLevels" /> is non-null.</param>
void VolumeMeterLevels::PeakLevels::set(IList<Single>^ value)
{
	this->peakLevels = value;
}

/// <summary>Collection of values indicating maximum Root Mean Square level for each channel over a processing pass</summary>
/// <value>Must have <see cref="ChannelCount" /> elements or may be null if <see cref="PeakLevels" /> is non-null.</value>
IList<Single>^ VolumeMeterLevels::RootMeanSquareLevels::get()
{
	return this->rootMeanSquareLevels;
}

/// <summary>Collection of values indicating maximum Root Mean Square level for each channel over a processing pass</summary>
/// <param name="value">Must have <see cref="ChannelCount" /> elements or may be null if <see cref="PeakLevels" /> is non-null.</param>
void VolumeMeterLevels::RootMeanSquareLevels::set(IList<Single>^ value)
{
	this->rootMeanSquareLevels = value;
}

/// <summary>Number of channels being processed by the volume meter APO</summary>
UInt32 VolumeMeterLevels::ChannelCount::get()
{
	return this->channelCount;
}

/// <summary>Number of channels being processed by the volume meter APO</summary>
/// <value>Number of channels to be processed by the volume meter APO</value>
void VolumeMeterLevels::ChannelCount::set(UInt32 value)
{
	this->channelCount = value;
}
#pragma endregion


#pragma region Properties
/// <summary>Returns the internal pointer</summary>
void* VolumeMeterLevels::DataPointer::get()
{
	return static_cast<void*>(this->unmanagedStruct.ToPointer());
}

/// <summary>Returns the internal pointer</summary>
void VolumeMeterLevels::DataPointer::set(void* value)
{
	this->unmanagedStruct = IntPtr(value);
}

/// <summary>Returns the unmanaged size</summary>
System::UInt32 VolumeMeterLevels::UnmanagedSize::get()
{
	return this->unmanagedSize;
}

/// <summary>Returns the unmanaged size</summary>
void VolumeMeterLevels::UnmanagedSize::set(System::UInt32 value)
{
	this->unmanagedSize = value;
}

/// <summary>Native pointer to the effect parameters</summary>
XAUDIO2FX_VOLUMEMETER_LEVELS* VolumeMeterLevels::UnmanagedPointer::get()
{
	return static_cast<XAUDIO2FX_VOLUMEMETER_LEVELS*>(this->unmanagedStruct.ToPointer());
}

/// <summary>Native pointer to the effect parameters</summary>
void VolumeMeterLevels::UnmanagedPointer::set(XAUDIO2FX_VOLUMEMETER_LEVELS* value)
{
	this->unmanagedStruct = IntPtr(value);
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
VolumeMeterLevels::VolumeMeterLevels()
{
	this->unmanagedStruct = IntPtr::Zero;	//set to NULL

	this->channelCount = 0;
	this->peakLevels = gcnew List<Single>();
	this->rootMeanSquareLevels = gcnew List<Single>();
}

/// <summary>Definition constructor</summary>
/// <param name="peaks">Peak levels table</param>
/// <param name="rms">Root mean square levels table</param>
/// <param name="channels">Number of channels being processed</param>
VolumeMeterLevels::VolumeMeterLevels(IList<Single>^ peaks, IList<Single>^ rms, UInt32 channels)
{
	this->unmanagedStruct = IntPtr::Zero;	//set to NULL

	this->channelCount = channels;
	this->peakLevels = peaks;
	this->rootMeanSquareLevels = rms;
}

/// <summary>Unmanaged constructor</summary>
/// <param name="unmanaged">Source XAUDIO2FX_VOLUMEMETER_LEVELS structure</param>
VolumeMeterLevels::VolumeMeterLevels(XAUDIO2FX_VOLUMEMETER_LEVELS* unmanaged)
{
	this->unmanagedStruct = IntPtr(unmanaged);

	this->channelCount = unmanaged->ChannelCount;
	this->peakLevels = nullptr;
	this->rootMeanSquareLevels = nullptr;

	if (unmanaged->pPeakLevels != NULL)
	{
		this->peakLevels = gcnew List<Single>();

		for (UInt32 index = 0; index < unmanaged->ChannelCount; ++index)
			this->peakLevels->Add(unmanaged->pPeakLevels[index]);
	}

	if (unmanaged->pRMSLevels != NULL)
	{
		this->rootMeanSquareLevels = gcnew List<Single>();
		for (UInt32 index = 0; index < unmanaged->ChannelCount; ++index)
			this->rootMeanSquareLevels->Add(unmanaged->pRMSLevels[index]);
	}
}
#pragma endregion



#pragma region Destruction
/// <summary>Destructor</summary>
/// <remarks>Dispose()</remarks>
VolumeMeterLevels::~VolumeMeterLevels()
{
	this->DisposeUnmanaged();
	GC::SuppressFinalize(this);
}

/// <summary>Destructor</summary>
/// <remarks>Finalize()</remarks>
VolumeMeterLevels::!VolumeMeterLevels()
{
	this->DisposeUnmanaged();
}

/// <summary>Destructor logic, disposes the object</summary>
void VolumeMeterLevels::DisposeUnmanaged()
{
	if (this->unmanagedStruct != IntPtr::Zero)
	{
		XAUDIO2FX_VOLUMEMETER_LEVELS* pointer = this->UnmanagedPointer;
		VolumeMeterLevels::ReleaseMemory(&pointer);
		this->unmanagedStruct = IntPtr::Zero;
	}
}
#pragma endregion



#pragma region Methods
/// <summary>Returns an unmanaged version of this object</summary>
/// <returns>An unmanaged XAUDIO2FX_VOLUMEMETER_LEVELS struct</returns>
XAUDIO2FX_VOLUMEMETER_LEVELS VolumeMeterLevels::ToUnmanaged()
{
	XAUDIO2FX_VOLUMEMETER_LEVELS levels;
	levels.ChannelCount = this->channelCount;

	if (this->peakLevels == nullptr)
		levels.pPeakLevels = NULL;
	else
	{
		levels.pPeakLevels = new Single[this->peakLevels->Count];
		for (Int32 index = 0; index < this->peakLevels->Count; ++index)
			levels.pPeakLevels[index] = this->peakLevels[index];
	}

	if (this->rootMeanSquareLevels == nullptr)
		levels.pRMSLevels = NULL;
	else
	{
		levels.pRMSLevels = new Single[this->rootMeanSquareLevels->Count];
		for (Int32 index = 0; index < this->rootMeanSquareLevels->Count; ++index)
			levels.pRMSLevels[index] = this->rootMeanSquareLevels[index];
	}

	return levels;
}

/// <summary>Releases up native memory allocated for an unmanaged XAUDIO2FX_VOLUMEMETER_LEVELS</summary>
/// <param name="levels">The pointer to the structure to release memory for</param>
void VolumeMeterLevels::ReleaseMemory(XAUDIO2FX_VOLUMEMETER_LEVELS** levels)
{
	if (levels != NULL && (*levels) != NULL)
	{
		if ((*levels)->pPeakLevels != NULL)
		{
			delete [] (*levels)->pPeakLevels;
			(*levels)->pPeakLevels = NULL;
		}

		if ((*levels)->pRMSLevels != NULL)
		{
			delete [] (*levels)->pRMSLevels;
			(*levels)->pRMSLevels = NULL;
		}

		delete (*levels);
		levels = NULL;
	}
}

/// <summary>Generates a managed copy of an unmanaged parameter struct</summary>
/// <param name="source">Source pointer to the unmanaged parameter struct</param>
/// <param name="size">Size of data located at the source pointer</param>
/// <returns>A Reference to the Managed copy</returns>
VolumeMeterLevels^ VolumeMeterLevels::GenerateFromUnmanaged(void* source, UInt32 size)
{
	VolumeMeterLevels^ levels = nullptr;

	if (source != NULL)
		levels = gcnew VolumeMeterLevels(reinterpret_cast<XAUDIO2FX_VOLUMEMETER_LEVELS*>(source));

	return levels;
}
#pragma endregion

