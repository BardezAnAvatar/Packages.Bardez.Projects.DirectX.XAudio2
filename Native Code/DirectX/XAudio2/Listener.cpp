

#include "Listener.h"


using namespace System;
using namespace Bardez::Projects::BasicStructures::ThreeDimensional;
using namespace Bardez::Projects::DirectX::X3DAudio;



#pragma region Construction
/// <summary>Default constructor</summary>
Listener::Listener() : Actor() { }

/// <summary>X3DAudio constructor</summary>
/// <param name="front">Orientation of front direction</param>
/// <param name="top">Orientation of top direction</param>
/// <param name="position">Position in user-defined world units</param>
/// <param name="velocity">Velocity vector in user-defined world units per second</param>
/// <param name="cone">Listener cone</param>
Listener::Listener(Vector<Single>^ front, Vector<Single>^ top, Vector<Single>^ position, Vector<Single>^ velocity, Cone^ cone) : Actor(front, top, position, velocity, cone) { }
						
/// <summary>X3DAudio constructor</summary>
/// <param name="listener">Unmanaged listener to copy from.</param>
Listener^ Listener::FromUnmanaged(X3DAUDIO_LISTENER* listener)
{
	Listener^ managed = nullptr;

	if (listener != NULL)
	{
		Cone^ cone = nullptr;

		if (listener->pCone != NULL)
			cone = Cone::FromUnmanaged(listener->pCone);
	
		Vector<Single>^ front = Actor::CopyUnmanagedVector(listener->OrientFront);
		Vector<Single>^ top = Actor::CopyUnmanagedVector(listener->OrientTop);
		Vector<Single>^ position = Actor::CopyUnmanagedVector(listener->Position);
		Vector<Single>^ velocity = Actor::CopyUnmanagedVector(listener->Velocity);

		managed = gcnew Listener(front, top, position, velocity, cone);
	}

	return managed;
}
#pragma endregion



#pragma region Methods
/// <summary>Generated an unmanaged copy for API calls</summary>
/// <returns>An unmanaged copy for API calls</returns>
X3DAUDIO_LISTENER* Listener::ToUnmanaged()
{
	X3DAUDIO_LISTENER* unmanaged = new X3DAUDIO_LISTENER;
	X3DAUDIO_CONE* cone = NULL;
	if (this->cone != nullptr)
		cone = this->cone->ToUnmanaged();

	//assign values
	unmanaged->pCone = cone;
	unmanaged->OrientFront = Actor::CopyManagedVector(this->orientFront);
	unmanaged->OrientTop = Actor::CopyManagedVector(this->orientTop);
	unmanaged->Position = Actor::CopyManagedVector(this->position);
	unmanaged->Velocity = Actor::CopyManagedVector(this->velocity);

	return unmanaged;
}

/// <summary>Releases up native memory allocated for an unmanaged X3DAUDIO_LISTENER</summary>
/// <param name="listener">Pointer to the listener to release memory for</param>
void Listener::ReleaseMemory(X3DAUDIO_LISTENER** listener)
{
	if (*listener != NULL)
	{
		//release memory
		Cone::ReleaseMemory(&((*listener)->pCone));
		(*listener)->pCone = NULL;

		delete *listener;
		*listener = NULL;
	}
}
#pragma endregion