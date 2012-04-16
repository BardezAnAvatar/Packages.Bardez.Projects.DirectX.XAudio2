using System;

namespace Bardez.Projects.DirectX.XAudio2.XAPO
{
    /// <summary>Base class for XAPO audio effect parameter classes</summary>
    public abstract class EffectParameterBase
    {
        #region Fields
        /// <summary>The internal pointer</summary>
        public IntPtr UnmanagedStruct { get; set; }

        /// <summary>Returns the unmanaged size</summary>
        public abstract UInt32 UnmanagedSize { get; set; }
        #endregion
    }
}