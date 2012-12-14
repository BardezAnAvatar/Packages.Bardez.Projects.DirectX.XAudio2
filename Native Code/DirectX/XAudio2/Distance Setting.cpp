

#include "Distance Setting.h"


using namespace System;
using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>Normalized distance. This must be within 0.0F to 1.0F.</summary>
Single DistanceSetting::Distance::get()
{
	return this->distance;
}

/// <summary>Normalized distance. This must be within 0.0F to 1.0F.</summary>
void DistanceSetting::Distance::set(Single value)
{
	this->distance = value;
}

/// <summary>DSP control setting</summary>
Single DistanceSetting::Setting::get()
{
	return this->setting;
}

/// <summary>DSP control setting</summary>
void DistanceSetting::Setting::set(Single value)
{
	this->setting = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
DistanceSetting::DistanceSetting()
{
	this->distance = 0.0F;
	this->setting = 0.0F;
}

/// <summary>Definition constructor</summary>
/// <param name="distance">Normalized distance. This must be within 0.0F to 1.0F.</param>
/// <param name="setting">DSP control setting</param>
DistanceSetting::DistanceSetting(Single distance, Single setting)
{
	this->distance = distance;
	this->setting = setting;
}
						
/// <summary>Unmanaged constructor</summary>
/// <param name="point">Unmanaged curve point to copy from.</param>
DistanceSetting^ DistanceSetting::FromUnmanaged(X3DAUDIO_DISTANCE_CURVE_POINT point)
{
	DistanceSetting^ managed = gcnew DistanceSetting(point.Distance, point.DSPSetting);
	return managed;
}
#pragma endregion



#pragma region Methods
/// <summary>Generated an unmanaged copy for API calls</summary>
/// <returns>An unmanaged copy for API calls</returns>
X3DAUDIO_DISTANCE_CURVE_POINT DistanceSetting::ToUnmanaged()
{
	X3DAUDIO_DISTANCE_CURVE_POINT unmanaged;

	unmanaged.Distance = this->distance;
	unmanaged.DSPSetting = this->setting;

	return unmanaged;
}
#pragma endregion