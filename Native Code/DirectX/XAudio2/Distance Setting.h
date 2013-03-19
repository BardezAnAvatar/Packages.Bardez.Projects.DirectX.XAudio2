

#ifndef Bardez_Projects_DirectX_X3DAudio_DistanceSetting
#define Bardez_Projects_DirectX_X3DAudio_DistanceSetting


#include <XAudio2.h>
#include <X3DAudio.h>


using namespace System;
using namespace System::Collections::Generic;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Defines a DSP setting at a given normalized distance.</summary>
				public ref class DistanceSetting
				{
					#pragma region Fields
					protected:
						/// <summary>Normalized distance. This must be within 0.0F to 1.0F.</summary>
						Single distance;

						/// <summary>DSP control setting</summary>
						Single setting;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>Normalized distance. This must be within 0.0F to 1.0F.</summary>
						property Single Distance
						{
							Single get();
							void set(Single value);
						}

						/// <summary>DSP control setting</summary>
						property Single Setting
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						DistanceSetting();

						/// <summary>Definition constructor</summary>
						/// <param name="distance">Normalized distance. This must be within 0.0F to 1.0F.</param>
						/// <param name="setting">DSP control setting</param>
						DistanceSetting(Single distance, Single setting);
						
						/// <summary>Copy constructor from the MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint" /> class</summary>
						/// <param name="curvePoint">Source MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint" /> to copy from</param>
						DistanceSetting(Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint^ curvePoint);

					protected:
						/// <summary>Definition method</summary>
						/// <param name="distance">Normalized distance. This must be within 0.0F to 1.0F.</param>
						/// <param name="setting">DSP control setting</param>
						void DefineSetting(Single distance, Single setting);
						
					internal:
						/// <summary>Unmanaged constructor</summary>
						/// <param name="point">Unmanaged curve point to copy from.</param>
						static DistanceSetting^ FromUnmanaged(X3DAUDIO_DISTANCE_CURVE_POINT point);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generated an unmanaged copy for API calls</summary>
						/// <returns>An unmanaged copy for API calls</returns>
						X3DAUDIO_DISTANCE_CURVE_POINT ToUnmanaged();

						/// <summary>Helper method to copy a collection of <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint" /> to a collection of DistanceSetting</summary>
						/// <param name="curvePointCollection">Collection of <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint" /> to copy</param>
						static IList<DistanceSetting^>^ CopyDistanceCurvePoint(IList<Bardez::Projects::Multimedia::MediaBase::Render::Audio::DistanceCurvePoint^>^ curvePointCollection);
					#pragma endregion
				};
			}
		}
	}
}

#endif

