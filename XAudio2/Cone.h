

#ifndef Bardez_Projects_DirectX_X3DAudio_Cone
#define Bardez_Projects_DirectX_X3DAudio_Cone


#include <XAudio2.h>
#include <X3DAudio.h>


using namespace System;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Represents a wrapper around an X3DAudio Cone struct.</summary>
				/// <remarks>
				///		Does not contain the actual struct.
				///		For further detailed explanation about cones, see: http://msdn.microsoft.com/en-us/library/windows/desktop/ee418803(v=vs.85).aspx
				///	</remarks>
				public ref class Cone
				{
					#pragma region Fields
					protected:
						/// <summary>Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</summary>
						Single innerAngle;

						/// <summary>Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</summary>
						Single outerAngle;

						/// <summary>Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</summary>
						Single innerVolume;

						/// <summary>Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</summary>
						Single outerVolume;

						/// <summary>LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
						Single innerLPF;

						/// <summary>LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
						Single outerLPF;

						/// <summary>Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</summary>
						Single innerReverb;

						/// <summary>Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</summary>
						Single outerReverb;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</summary>
						property Single InnerAngle
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</summary>
						property Single OuterAngle
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</summary>
						property Single InnerVolume
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</summary>
						property Single OuterVolume
						{
							Single get();
							void set(Single value);
						}

						/// <summary>LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
						property Single InnerLPF
						{
							Single get();
							void set(Single value);
						}

						/// <summary>LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</summary>
						property Single OuterLPF
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</summary>
						property Single InnerReverb
						{
							Single get();
							void set(Single value);
						}

						/// <summary>Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</summary>
						property Single OuterReverb
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						Cone();

						/// <summary>Definition constructor</summary>
						/// <param name="innerAngle">Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</param>
						/// <param name="outerAngle">Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</param>
						/// <param name="innerVolume">Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</param>
						/// <param name="outerVolume">Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</param>
						/// <param name="innerLPF">LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
						/// <param name="outerLPF">LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
						/// <param name="innerReverb">Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</param>
						/// <param name="outerReverb">Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</param>
						Cone(Single innerAngle, Single outerAngle, Single innerVolume, Single outerVolume, Single innerLPF, Single outerLPF, Single innerReverb, Single outerReverb);

						/// <summary>Copy constructor from the MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::AudioCone" /> class</summary>
						/// <param name="managedCone">Source MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::AudioCone" /> to copy from</param>
						Cone(Bardez::Projects::Multimedia::MediaBase::Render::Audio::AudioCone^ managedCone);

					protected:
						/// <summary>Definition method</summary>
						/// <param name="innerAngle">Inner cone angle in radians. This value must be within 0.0f to 2 * Pi.</param>
						/// <param name="outerAngle">Outer cone angle in radians. This value must be within <see cref="innerAngle" /> to 2 * Pi.</param>
						/// <param name="innerVolume">Volume scaler on/within inner cone. This value must be within 0.0f to 2.0f.</param>
						/// <param name="outerVolume">Volume scaler on/beyond outer cone. This value must be within 0.0f to 2.0f.</param>
						/// <param name="innerLPF">LPF direct-path or reverb-path coefficient scaler on/within inner cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
						/// <param name="outerLPF">LPF direct-path or reverb-path coefficient scaler on or beyond outer cone. This value is only used for LPF calculations and must be within 0.0f to 1.0f.</param>
						/// <param name="innerReverb">Reverb send level scaler on or within inner cone. This must be within 0.0f to 2.0f.</param>
						/// <param name="outerReverb">Reverb send level scaler on/beyond outer cone. This must be within 0.0f to 2.0f.</param>
						void DefineCone(Single innerAngle, Single outerAngle, Single innerVolume, Single outerVolume, Single innerLPF, Single outerLPF, Single innerReverb, Single outerReverb);

					internal:
						/// <summary>Constructs a managed audio cone from an unmanaged source</summary>
						/// <param name="cone">Unmanaged source cone to copy from</param>
						static Cone^ FromUnmanaged(X3DAUDIO_CONE* cone);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generated an unmanaged copy for API calls</summary>
						/// <returns>An unmanaged copy for API calls</returns>
						X3DAUDIO_CONE* ToUnmanaged();

						/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_CONE</summary>
						/// <param name="cone">Pointer to the cone to release memory for</param>
						static void ReleaseMemory(X3DAUDIO_CONE** cone);
					#pragma endregion
				};
			}
		}
	}
}

#endif

