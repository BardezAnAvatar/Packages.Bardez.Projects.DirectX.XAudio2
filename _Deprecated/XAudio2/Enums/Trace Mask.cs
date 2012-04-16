using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bardez.Projects.DirectX.XAudio2.Enums
{
    /// <summary>Enumerator for Tracemask flags</summary>
    [Flags]
    public enum TraceMask : uint /* UInt32*/
    {
		None                    = 0UL,

		XAUDIO2_LOG_ERRORS      = 1UL,

		/// <remarks>Implies LogErrors</remarks>
        XAUDIO2_LOG_WARNINGS    = 2UL,

        XAUDIO2_LOG_INFO        = 4UL,

		/// <remarks>Implies LogInfo</remarks>
        XAUDIO2_LOG_DETAIL      = 8UL,

        XAUDIO2_LOG_API_CALLS   = 16UL,

		/// <remarks>Implies LogApiCalls</remarks>
        XAUDIO2_LOG_FUNC_CALLS  = 32UL,

        XAUDIO2_LOG_TIMING      = 64UL,

        XAUDIO2_LOG_LOCKS       = 128UL,

        XAUDIO2_LOG_MEMORY      = 256UL,

        XAUDIO2_LOG_STREAMING   = 4096UL,
    }
}