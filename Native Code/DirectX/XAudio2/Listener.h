

#ifndef Bardez_Projects_DirectX_X3DAudio_Listener
#define Bardez_Projects_DirectX_X3DAudio_Listener


#include <XAudio2.h>
#include <X3DAudio.h>
#include "Actor.h"
#include "Cone.h"


using namespace System;
using namespace Bardez::Projects::BasicStructures::ThreeDimensional;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace X3DAudio
			{
				/// <summary>Represents a wrapper around an X3DAudio Listener struct. Does not contain the actual struct.</summary>
				public ref class Listener : Actor
				{
					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						Listener();

						/// <summary>X3DAudio constructor</summary>
						/// <param name="front">Orientation of front direction</param>
						/// <param name="top">Orientation of top direction</param>
						/// <param name="position">Position in user-defined world units</param>
						/// <param name="velocity">Velocity vector in user-defined world units per second</param>
						/// <param name="cone">Listener cone</param>
						Listener(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Cone^ cone);
						
						/// <summary>Copy constructor from the MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::Listener" /> class</summary>
						/// <param name="emitter">Source MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::Listener" /> to copy from</param>
						Listener(Bardez::Projects::Multimedia::MediaBase::Render::Audio::Listener^ listener);
						
					internal:
						/// <summary>X3DAudio constructor</summary>
						/// <param name="listener">Unmanaged listener to copy from.</param>
						static Listener^ FromUnmanaged(X3DAUDIO_LISTENER* listener);
					#pragma endregion



					#pragma region Methods
					internal:
						/// <summary>Generated an unmanaged copy for API calls</summary>
						/// <returns>An unmanaged copy for API calls</returns>
						X3DAUDIO_LISTENER* ToUnmanaged();

						/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_LISTENER</summary>
						/// <param name="listener">Pointer to the listener to release memory for</param>
						static void ReleaseMemory(X3DAUDIO_LISTENER** listener);
					#pragma endregion
				};
			}
		}
	}
}

#endif
