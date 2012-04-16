using System;
using System.Runtime.InteropServices;

using Bardez.Projects.DirectX.XAudio2.XAPO;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Defines parameters of a voice/filter.</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct EffectDescriptor
    {
        #region Fields
		/// <summary>Reference to the effect object</summary>
		//TODO: Make this an IntPtr?
        public EffectBase Effect;

		/// <summary>Indicates whether or not to start the effect as enabled</summary>
		public Boolean InitialState;

		/// <summary>Number of channels the effect should output</summary>
		public UInt32 OutputChannels;
        #endregion


        #region Construction
		/// <summary>Default constructor</summary>
		public EffectDescriptor()
        {
            this.Effect = null;
            this.InitialState = false;
            this.OutputChannels = 0;
        }

		/// <summary>Definition constructor</summary>
		/// <param name="effectObject">Reference to an effect object</param>
		/// <param name="enabled">Is the effect enabled?</param>
		/// <param name="channels">Output number of channels</param>
		public EffectDescriptor(EffectBase effectObject, Boolean enabled, UInt32 channels)
        {
            this.Effect = effectObject;
            this.InitialState = enabled;
            this.OutputChannels = channels;
        }
        #endregion
    }
}