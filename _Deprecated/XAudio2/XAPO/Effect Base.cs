using System;

namespace Bardez.Projects.DirectX.XAudio2.XAPO
{
    /// <summary>Base class for XAPO audio effect classes</summary>
    public abstract class EffectBase
    {
        #region Fields
        /// <summary>The parameters to this effect</summary>
        public EffectParameterBase Parameters { get; set; }
        
		/// <summary>Pointer to the effect COM object/interface</summary>
        public IntPtr Effect { get; set; }
        #endregion
    }
}