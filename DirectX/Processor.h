
#ifndef Bardez_Projects_Directx_XAudio2_Processors
#define Bardez_Projects_Directx_XAudio2_Processors

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <summary>Enumerator for processor numbers</summary>
				public enum struct Processors : System::UInt32
				{
					Processor1  = 0x00000001,
					Processor2  = 0x00000002,
					Processor3  = 0x00000004,
					Processor4  = 0x00000008,
					Processor5  = 0x00000010,
					Processor6  = 0x00000020,
					Processor7  = 0x00000040,
					Processor8  = 0x00000080,
					Processor9  = 0x00000100,
					Processor10 = 0x00000200,
					Processor11 = 0x00000400,
					Processor12 = 0x00000800,
					Processor13 = 0x00001000,
					Processor14 = 0x00002000,
					Processor15 = 0x00004000,
					Processor16 = 0x00008000,
					Processor17 = 0x00010000,
					Processor18 = 0x00020000,
					Processor19 = 0x00040000,
					Processor20 = 0x00080000,
					Processor21 = 0x00100000,
					Processor22 = 0x00200000,
					Processor23 = 0x00400000,
					Processor24 = 0x00800000,
					Processor25 = 0x01000000,
					Processor26 = 0x02000000,
					Processor27 = 0x04000000,
					Processor28 = 0x08000000,
					Processor29 = 0x10000000,
					Processor30 = 0x20000000,
					Processor31 = 0x40000000,
					Processor32 = 0x80000000,
					//XAUDIO2_ANY_PROCESSOR = 0xffffffff,
					//XAUDIO2_DEFAULT_PROCESSOR = XAUDIO2_ANY_PROCESSOR
					XAUDIO2_DEFAULT_PROCESSOR = 0xFFFFFFFF
				};
			}
		}
	}
}

#endif