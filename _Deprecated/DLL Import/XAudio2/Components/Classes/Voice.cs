using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

using Bardez.Projects.DirectX.XAudio2.Components.Structs;

namespace Bardez.Projects.DirectX.XAudio2.Components.Classes
{
    /// <summary>Base class of Source, Submix and Mastering Voices for the Voice audio graph</summary>
    public class Voice : IDisposable
    {
        #region Constants
        #endregion


        #region Fields
        /// <summary>Pointer to an XAudio2Voice interface COM object</summary>
        public IntPtr PtrVoice;

        /// <summary>The list of effects</summary>
        public List<EffectDescriptor> Effects;
        #endregion


        #region Construction
        /// <summary>Default constructor</summary>
        public Voice() { }

        /// <summary>Unmanaged constructor</summary>
        /// <param name="pointer">Unmanaged parameters struct</param>
        public Voice(IntPtr pointer)
        {
            this.PtrVoice = pointer;
        }
        #endregion


        #region Destruction
        /// <summary>Destrutor</summary>
        /// <remarks>Dispose()</remarks>
        public void Dispose()
        {
            this.DisposeUnmanaged();
        }

        /// <summary>Destrutor</summary>
        /// <remarks>Finalize()</remarks>
        ~Voice()
        {
            this.DisposeUnmanaged();
        }

        /// <summary>Destrutor logic, disposes the object</summary>
        protected void DisposeUnmanaged()
        {
	        // Dispose this voice
	        if (this.PtrVoice != IntPtr.Zero)
	        {
		        this->XAudio2Voice->DestroyVoice();
		        this->XAudio2Voice = NULL;
	        }
        }
        #endregion
    }
}