
#ifndef Bardez_Projects_Directx_XAudio2_DeviceRole
#define Bardez_Projects_Directx_XAudio2_DeviceRole

using namespace System;

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				[Flags]
				public enum struct DeviceRole : System::UInt32
				{
					NotDefaultDevice            = 0x0,
					DefaultConsoleDevice        = 0x1,
					DefaultMultimediaDevice     = 0x2,
					DefaultCommunicationsDevice = 0x4,
					DefaultGameDevice           = 0x8,
					GlobalDefaultDevice         = 0xF,
					InvalidDeviceRole			= ~GlobalDefaultDevice
				};
			}
		}
	}
}

#endif
