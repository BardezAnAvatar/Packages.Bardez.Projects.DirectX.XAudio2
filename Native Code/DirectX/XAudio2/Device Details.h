

#ifndef Bardez_Projects_Directx_XAudio2_DEVICE_DETAILS
#define Bardez_Projects_Directx_XAudio2_DEVICE_DETAILS


#include "Device Role.h"
	

using namespace System;
using namespace System::Text;
using namespace Bardez::Projects::BasicStructures::Win32::Audio;
using namespace Bardez::Projects::ReusableCode;


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
						StringBuilder^ builder = gcnew StringBuilder();

						this->WriteString(builder);

						String^ desc = builder->ToString();
	
						return desc;
					}
					
					/// <summary>This method prints a human-readable representation to the given StringBuilder</summary>
					/// <param name="builder">StringBuilder to write to</param>
					void WriteString(StringBuilder^ builder)
					{
						StringFormat::ToStringAlignment("Device ID", builder);
						builder->Append(this->deviceId);
						StringFormat::ToStringAlignment("Device name", builder);
						builder->Append(this->displayName);
						StringFormat::ToStringAlignment("Device Role", builder);
						builder->Append(this->deviceRole.ToString());
						StringFormat::ToStringAlignment("Output format", builder);
						this->outputFormat->WriteString(builder);
					}
				};
			}
		}
	}
}

#endif

