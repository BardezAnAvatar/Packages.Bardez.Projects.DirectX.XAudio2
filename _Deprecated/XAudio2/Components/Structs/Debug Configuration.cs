using System;
using System.Runtime.InteropServices;

using Bardez.Projects.DirectX.XAudio2.Enums;

namespace Bardez.Projects.DirectX.XAudio2.Components.Structs
{
    /// <summary>Managed XAUDIO2_DEBUG_CONFIGURATION structure</summary>
    [StructLayout(LayoutKind.Sequential)]
    public struct DebugConfiguration
    {
        #region Fields
        /// <summary>Enabled debug messages</summary>
        public TraceMask MaskTrace;

        /// <summary>Breaking messages</summary>
        public BreakMask MaskBreak;

        /// <summary>Dictates whether or not to log the thread ID with each message</summary>
        public Boolean LogThreadId;

        /// <summary>Dictates whether or not to log the file and line numbers (code?) with each message</summary>
        public Boolean LogFileline;

        /// <summary>Dictates whether or not to log the function names (code?) with each message</summary>
        public Boolean LogFunctionName;

        /// <summary>Dictates whether or not to log the timestamps with each message</summary>
        public Boolean LogTiming;
        #endregion


        #region Construction
        /// <summary>Default constructor</summary>
        public DebugConfiguration()
        {
            this.MaskTrace = TraceMask.None;
            this.MaskBreak = BreakMask.None;
            this.LogThreadId = false;
            this.LogFileline = false;
            this.LogFunctionName = false;
            this.LogTiming = false;
        }

        /// <summary>Definition constructor</summary>
        /// <param name="traceMsk">Tracing flags</param>
        /// <param name="breakMk">Breaking flags</param>
        /// <param name="threadId">Log the thread ID?</param>
        /// <param name="fileLine">Log the file and line numbers?</param>
        /// <param name="function">Log the function names?</param>
        /// <param name="timing">Log the timing?</param>
        public DebugConfiguration(TraceMask traceMsk, BreakMask breakMk, Boolean threadId, Boolean fileLine, Boolean function, Boolean timing)
        {
            this.MaskTrace = traceMsk;
            this.MaskBreak = breakMk;
            this.LogThreadId = threadId;
            this.LogFileline = fileLine;
            this.LogFunctionName = function;
            this.LogTiming = timing;
        }
        #endregion
    }
}