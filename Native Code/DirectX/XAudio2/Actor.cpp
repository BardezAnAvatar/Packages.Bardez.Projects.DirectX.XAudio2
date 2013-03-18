

#include "Actor.h"


using namespace System;
using namespace Bardez::Projects::BasicStructures::ThreeDimensional;
using namespace Bardez::Projects::DirectX::X3DAudio;


#pragma region Properties
/// <summary>
///		Orientation of front direction. When cone is NULL OrientFront is used only for matrix and delay calculations.
///		When cone is not NULL OrientFront is used for matrix, LPF (both direct and reverb paths), and reverb calculations.
///		This value must be orthonormal with OrientTop when used.
/// </summary>
Vector<Single> Actor::OrientFront::get()
{
	return this->orientFront;
}

/// <summary>
///		Orientation of front direction. When cone is NULL OrientFront is used only for matrix and delay calculations.
///		When cone is not NULL OrientFront is used for matrix, LPF (both direct and reverb paths), and reverb calculations.
///		This value must be orthonormal with OrientTop when used.
/// </summary>
void Actor::OrientFront::set(Vector<Single> value)
{
	this->orientFront = value;
}

/// <summary>
///		Orientation of top direction, used only for matrix and delay calculations.
///		This value must be orthonormal with OrientFront when used.
/// </summary>
Vector<Single> Actor::OrientTop::get()
{
	return this->orientTop;
}

/// <summary>
///		Orientation of top direction, used only for matrix and delay calculations.
///		This value must be orthonormal with OrientFront when used.
/// </summary>
void Actor::OrientTop::set(Vector<Single> value)
{
	this->orientTop = value;
}

/// <summary>Position in user-defined world units. This value does not affect Velocity.</summary>
Vector<Single> Actor::Position::get()
{
	return this->position;
}

/// <summary>Position in user-defined world units. This value does not affect Velocity.</summary>
void Actor::Position::set(Vector<Single> value)
{
	this->position = value;
}

/// <summary>
///		Velocity vector in user-defined world units per second, used only for doppler calculations.
///		This value does not affect Position.
///	</summary>
Vector<Single> Actor::Velocity::get()
{
	return this->velocity;
}

/// <summary>
///		Velocity vector in user-defined world units per second, used only for doppler calculations.
///		This value does not affect Position.
///	</summary>
void Actor::Velocity::set(Vector<Single> value)
{
	this->velocity = value;
}

/// <summary>
///		Providing a listener cone will specify that additional calculations are performed when determining the volume
///		and filter DSP parameters for individual sound sources. A NULL cone value specifies an omnidirectional sound and no cone processing is applied.
///		cone is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
/// </summary>
Cone^ Actor::SoundCone::get()
{
	return this->cone;
}

/// <summary>
///		Providing a listener cone will specify that additional calculations are performed when determining the volume
///		and filter DSP parameters for individual sound sources. A NULL cone value specifies an omnidirectional sound and no cone processing is applied.
///		cone is only used for matrix, LPF (both direct and reverb paths), and reverb calculations.
/// </summary>
void Actor::SoundCone::set(Cone^ value)
{
	this->cone = value;
}
#pragma endregion



#pragma region Construction
/// <summary>Default constructor</summary>
Actor::Actor()
{
	this->orientFront = Vector<Single>(0.0F, 0.0F, 1.0F);
	this->orientTop = Vector<Single>(0.0F, 1.0F, 0.0F);
	this->position = Vector<Single>(0.0F, 0.0F, 0.0F);
	this->velocity = Vector<Single>(0.0F, 0.0F, 0.0F);
	this->cone = nullptr;
}

/// <summary>X3DAudio constructor</summary>
/// <param name="front">Orientation of front direction</param>
/// <param name="top">Orientation of top direction</param>
/// <param name="position">Position in user-defined world units</param>
/// <param name="velocity">Velocity vector in user-defined world units per second</param>
/// <param name="cone">Cone interacting with the environment</param>
Actor::Actor(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Cone^ cone)
{
	this->DefineActor(front, top, position, velocity, cone);
}

/// <summary>MediaBase copy constructor</summary>
/// <param name="perspective">Source MediaBase <see cref="Bardez::Projects::Multimedia::MediaBase::Render::Audio::Perspective" /> to copy from</param>
Actor::Actor(Bardez::Projects::Multimedia::MediaBase::Render::Audio::Perspective^ perspective)
{
	this->DefineActor(perspective->OrientationFront, perspective->OrientationVertical, perspective->Position, perspective->Velocity, gcnew Cone(perspective->Cone));
}

/// <summary>Definition constructor</summary>
/// <param name="front">Orientation of front direction</param>
/// <param name="top">Orientation of top direction</param>
/// <param name="position">Position in user-defined world units</param>
/// <param name="velocity">Velocity vector in user-defined world units per second</param>
/// <param name="cone">Cone interacting with the environment</param>
void Actor::DefineActor(Vector<Single> front, Vector<Single> top, Vector<Single> position, Vector<Single> velocity, Cone^ cone)
{
	this->orientFront = front;
	this->orientTop = top;
	this->position = position;
	this->velocity = velocity;
	this->cone = cone;
}
#pragma endregion



#pragma region Methods
/// <summary>Generates a managed copy of an X3DAudio vector</summary>
/// <param name="vector">X3DAudio Vector to copy</param>
/// <returns>A managed copy of an X3DAudio vector</returns>
Vector<Single> Actor::CopyUnmanagedVector(X3DAUDIO_VECTOR vector)
{
	Vector<Single> managed = Vector<Single>(vector.x, vector.y, vector.z);
	return managed;
}

/// <summary>Generates an unmanaged copy of a basic Single vector</summary>
/// <param name="vector">Vector to copy</param>
/// <returns>An unmanaged copy of the basic Single vector</returns>
X3DAUDIO_VECTOR Actor::CopyManagedVector(Vector<Single> vector)
{
	X3DAUDIO_VECTOR unmanaged;
	
	unmanaged.x = vector.X;
	unmanaged.y = vector.Y;
	unmanaged.z = vector.Z;

	return unmanaged;
}
#pragma endregion


