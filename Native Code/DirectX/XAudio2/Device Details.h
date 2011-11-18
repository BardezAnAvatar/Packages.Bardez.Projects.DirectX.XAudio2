#ifndef Bardez_Projects_Directx_XAudio2_DEVICE_DETAILS
#define Bardez_Projects_Directx_XAudio2_DEVICE_DETAILS

#include "Device Role.h"
	
using namespace System;
using namespace System::Text;
using namespace Bardez::Projects::Win32::Audio;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Managed XAUDIO2_DEVICE_DETAILS structure</summary>
				public ref class DeviceDetails
				{
				protected:
					/// <summary>String identifier for the audio device</summary>
					System::String^ deviceId;

					/// <summary>Friendly name suitable for display to a human</summary>
					System::String^ displayName;

					/// <summary>Roles that the device should be used for</summary>
					DeviceRole deviceRole;

					/// <summary>The device's native PCM audio output format</summary>
					WaveFormatExtensible^ outputFormat;

				public:
					/// <summary>String identifier for the audio device</summary>
					property System::String^ DeviceId
					{
						String^ get()
						{
							return this->deviceId;
						}
						void set (String^ value)
						{
							this->deviceId = value;
						}
					}

					/// <summary>Friendly name suitable for display to a human</summary>
					property System::String^ DisplayName
					{
						System::String^ get()
						{
							return this->displayName;
						}
						void set (System::String^ value)
						{
							this->displayName = value;
						}
					}

					/// <summary>Roles that the device should be used for</summary>
					property DeviceRole Device_Role
					{
						DeviceRole get()
						{
							return this->deviceRole;
						}
						void set (DeviceRole value)
						{
							this->deviceRole = value;
						}
					}

					/// <summary>The device's native PCM audio output format</summary>
					property WaveFormatExtensible^ OutputFormat
					{
						WaveFormatExtensible^ get()
						{
							return this->outputFormat;
						}
						void set (WaveFormatExtensible^ value)
						{
							this->outputFormat = value;
						}
					}

				public:
					/// <summary>Generates a descriptive string (to be displayed to the end user)</summary>
					/// <returns>A String representing the DeviceDetails Object contents</returns>
					String^ ToDescriptionString()
					{
						String^ desc = nullptr;

						StringBuilder^ builder = gcnew StringBuilder();
						builder->Append("\tDevice ID:       ");
						builder->Append(this->deviceId);
						builder->AppendLine(System::String::Empty);
						builder->Append("\tDevice name:     ");
						builder->Append(this->displayName);
						builder->AppendLine(System::String::Empty);
						builder->Append("\tDevice Role:     ");
						builder->Append(this->deviceRole.ToString());
						builder->AppendLine(System::String::Empty);
						builder->AppendLine("\tOutput format:");
						builder->Append(this->outputFormat->ToDescriptionString());
						builder->AppendLine(System::String::Empty);

						desc = builder->ToString();
	
						return desc;
					}
				};
			}
		}
	}
}

#endif