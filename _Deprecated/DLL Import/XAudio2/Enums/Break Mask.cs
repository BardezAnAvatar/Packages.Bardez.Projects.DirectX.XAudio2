using System;

namespace Bardez.Projects.DirectX.XAudio2.Enums
{
    /// <summary>Enumerator for BreakMask flags</summary>
    [Flags]
    public enum BreakMask : uint /* UInt32 */
    {
        None = 0UL,

        XAUDIO2_LOG_ERRORS = 1UL,

        /// <remarks>Implies LogErrors</remarks>
        XAUDIO2_LOG_WARNINGS = 2UL,
    }
}