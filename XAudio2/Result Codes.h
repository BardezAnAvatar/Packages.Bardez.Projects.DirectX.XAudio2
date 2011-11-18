
#ifndef Bardez_Projects_Directx_XAudio2_ErrorCodes
#define Bardez_Projects_Directx_XAudio2_ErrorCodes

namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				/// <remarks>See http://msdn.microsoft.com/en-us/library/cc704587%28v=prot.10%29.aspx for more HRESULT codes</remarks>
				public enum struct ResultCode : System::UInt32
				{
					XAudio2_Error_INVALID_CALL          = 0x88960001,
					XAudio2_Error_XMA_DECODER_ERROR     = 0x88960002,
					XAudio2_Error_XAPO_CREATION_FAILED  = 0x88960003,
					XAudio2_Error_DEVICE_INVALIDATED	= 0x88960004,
					XAudio2_Error_ALREADY_INITIALIZED   = 0xFFFFFFFE,	//not referenced?
					Success_OK							= 0x00000000,
					Error_NotImplemented				= 0x80004001,
					Error_ClassNotRegistered			= 0x80040154,	//not installed
					Error_OperationAborted				= 0x80004004,
					Error_AccessDenied					= 0x80070005,
					Error_Failure						= 0x80004005,
					Error_InvalidHandle					= 0x80070006,
					Error_InvalidArgument				= 0x80070057,
					Error_NoSuchInterfaceSupported		= 0x80004002,
					Error_OutOfMemory					= 0x8007000E,
					Error_InvalidPointer				= 0x80004003,
					Error_UnexpectedFailure				= 0x8000FFFF,
					Error_Pending						= 0x8000000A,
					Error_NoSuchInterface				= 0x80000004,

				};
			}
		}
	}
}

#endif
