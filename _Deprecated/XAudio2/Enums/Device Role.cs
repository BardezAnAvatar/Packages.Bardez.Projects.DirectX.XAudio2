using System;

namespace Bardez.Projects.DirectX.XAudio2.Enums
{
    public enum DeviceRole : uint /* UInt32 */
    {
		NotDefaultDevice            = 0x0,
		DefaultConsoleDevice        = 0x1,
		DefaultMultimediaDevice     = 0x2,
		DefaultCommunicationsDevice = 0x4,
		DefaultGameDevice           = 0x8,
		GlobalDefaultDevice         = 0xF,
		InvalidDeviceRole			= ~GlobalDefaultDevice
    }
}