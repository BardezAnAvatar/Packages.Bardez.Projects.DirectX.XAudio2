

#ifndef Bardez_Projects_DirectX_X3DAudio_Actor
#define Bardez_Projects_DirectX_X3DAudio_Actor


#include <XAudio2.h>
#include <xaudio2fx.h>
#include <X3DAudio.h>
#include "Cone.h"


using namespace System;
using namespace Bardez::Projects::BasicStructures::ThreeDimensional;
using namespace Bardez::Projects::DirectX::X3DAudio;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Represents a common base class for the X3DAudio Listener and Emitter structs.</summary>
				public ref class Actor abstract
				{
					#pragma region Fields
					protected:
						/// <summary>
						///		Orientation of front direction. When cone is NULL OrientFront is used only for matrix and delay calculations.
						///		When cone is not NULL OrientFront is used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						///		This value must be orthonormal with OrientTop when used.
						/// </summary>
						Vector<Single> orientFront;

						/// <summary>
						///		Orientation of top direction, used only for matrix and delay calculations.
						///		This value must be orthonormal with OrientFront when used.
						/// </summary>
						Vector<Single> orientTop;

						/// <summary>Position in user-defined world units. This value does not affect Velocity.</summary>
						Vector<Single> position;

						/// <summary>
						///		Velocity vector in user-defined world units per second, used only for doppler calculations.
						///		This value does not affect Position.
						///	</summary>
						Vector<Single> velocity;

						/// <summary>
						///		Specifies that additional calculations are performed when determining the volume and filter DSP parameters for individual sound sources.
						///		A NULL cone value specifies an omnidirectional inetaction and no cone processing is applied.
						///		Cone is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						/// </summary>
						Cone^ cone;
					#pragma endregion



					#pragma region Properties
					public:
						/// <summary>
						///		Orientation of front direction. When cone is NULL OrientFront is used only for matrix and delay calculations.
						///		When cone is not NULL OrientFront is used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						///		This value must be orthonormal with OrientTop when used.
						/// </summary>
						property Vector<Single> OrientFront
						{
							Vector<Single> get();
							void set(Vector<Single> value);
						}

						/// <summary>
						///		Orientation of top direction, used only for matrix and delay calculations.
						///		This value must be orthonormal with OrientFront when used.
						/// </summary>
						property Vector<Single> OrientTop
						{
							Vector<Single> get();
							void set(Vector<Single> value);
						}

						/// <summary>Position in user-defined world units. This value does not affect Velocity.</summary>
						property Vector<Single> Position
						{
							Vector<Single> get();
							void set(Vector<Single> value);
						}

						/// <summary>
						///		Velocity vector in user-defined world units per second, used only for doppler calculations.
						///		This value does not affect Position.
						///	</summary>
						property Vector<Single> Velocity
						{
							Vector<Single> get();
							void set(Vector<Single> value);
						}

						/// <summary>
						///		Specifies that additional calculations are performed when determining the volume and filter DSP parameters for individual sound sources.
						///		A NULL cone value specifies an omnidirectional inetaction and no cone processing is applied.
						///		Cone is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
						/// </summary>
						property Cone^ SoundCone
						{
							Cone^ get();
							void set(Cone^ value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						Actor();

						/// <summary>Definition constructor</summary>
						/// <param name="front">Orientation of front direction</param>
						/// <param name="top">Orientation of top direction</param>
						/// <param name="position">Position in user-defined world units</param>
						/// <param name="velocity">Velocity vector in user-defined world units per second</param>
						/// <param name="cone">Cone interacting with the environment</param>
						Actor(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Cone^ cone);
						
						/// <summary>MediaBase copy constructor</summary>
						/// <param name="perspective">Source MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::Perspective" /> to copy from</param>
						Actor(Bardez::Projects::Multimedia::MediaBase::Render::Audio::Perspective^ perspective);

						/// <summary>Definition constructor</summary>
						/// <param name="front">Orientation of front direction</param>
						/// <param name="top">Orientation of top direction</param>
						/// <param name="position">Position in user-defined world units</param>
						/// <param name="velocity">Velocity vector in user-defined world units per second</param>
						/// <param name="cone">Cone interacting with the environment</param>
						void DefineActor(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Cone^ cone);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generates a managed copy of an X3DAudio vector</summary>
						/// <param name="vector">X3DAudio Vector to copy</param>
						/// <returns>A managed copy of an X3DAudio vector</returns>
						static Vector<Single> CopyUnmanagedVector(X3DAUDIO_VECTOR vector);

						/// <summary>Generates an unmanaged copy of an basic Single vector</summary>
						/// <param name="vector">Vector to copy</param>
						/// <returns>An unmanaged copy of the basic Single vector</returns>
						static X3DAUDIO_VECTOR CopyManagedVector(Vector<Single> vector);
					#pragma endregion
				};
			}
		}
	}
}

#endif

