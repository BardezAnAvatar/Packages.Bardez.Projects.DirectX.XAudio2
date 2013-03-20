

#ifndef XAUDIO2_Reverberation_Parameters_I3DL2
#define XAUDIO2_Reverberation_Parameters_I3DL2


extern "C"
{
	#include <XAudio2fx.h>
}
#include "Effect Parameter Base.h"
#include "Reverb Parameters I3DL2 Helper.h"


using namespace System;
using namespace Bardez::Projects::DirectX::XAudio2::XAPO;


namespace Bardez
{
	namespace Projects
	{
		namespace DirectX
		{
			namespace XAudio2
			{
				namespace FX
				{
					/// <summary>Managed representation of an XAudio2 XAUDIO2FX_REVERB_I3DL2_PARAMETERS structure</summary>
					/// <remarks>Host to an I3DL2 standard compliant parameter set</remarks>
					public ref class ReverbParametersI3DL2
					{
					#pragma region Preset reverb settings
					private:
						//initonly static XAUDIO2FX_REVERB_I3DL2_PARAMETERS _Default = {100,-10000,    0,0.0f, 1.00f,0.50f,-10000,0.020f,-10000,0.040f,100.0f,100.0f,5000.0f};

					public:
						/// <summary>Constant for default preset</summary>
						initonly static ReverbParametersI3DL2^ Default = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Default);

						/// <summary>Constant for generic preset</summary>
						initonly static ReverbParametersI3DL2^ Generic = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Generic);

						/// <summary>Constant for padded cell preset</summary>
						initonly static ReverbParametersI3DL2^ PaddedCell = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::PaddedCell);

						/// <summary>Constant for a generic "room" preset</summary>
						initonly static ReverbParametersI3DL2^ GenericRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::GenericRoom);

						/// <summary>Constant for bathroom preset</summary>
						initonly static ReverbParametersI3DL2^ BathRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::BathRoom);

						/// <summary>Constant for living room preset</summary>
						initonly static ReverbParametersI3DL2^ LivingRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::LivingRoom);

						/// <summary>Constant for stone room preset</summary>
						initonly static ReverbParametersI3DL2^ StoneRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::StoneRoom);

						/// <summary>Constant for auditorium preset</summary>
						initonly static ReverbParametersI3DL2^ Auditorum = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Auditorum);

						/// <summary>Constant for concert hall preset</summary>
						initonly static ReverbParametersI3DL2^ ConcertHall = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::ConcertHall);

						/// <summary>Constant for cave preset</summary>
						initonly static ReverbParametersI3DL2^ Cave = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Cave);

						/// <summary>Constant for arena preset</summary>
						initonly static ReverbParametersI3DL2^ Arena = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Arena);

						/// <summary>Constant for hangar preset</summary>
						initonly static ReverbParametersI3DL2^ Hangar = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Hangar);

						/// <summary>Constant for carpeted hallway preset</summary>
						initonly static ReverbParametersI3DL2^ CarpetedHallway = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::CarpetedHallway);

						/// <summary>Constant for hallway preset</summary>
						initonly static ReverbParametersI3DL2^ Hallway = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Hallway);

						/// <summary>Constant for stone corridor preset</summary>
						initonly static ReverbParametersI3DL2^ StoneCorridor = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::StoneCorridor);

						/// <summary>Constant for alley preset</summary>
						initonly static ReverbParametersI3DL2^ Alley = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Alley);

						/// <summary>Constant for forest preset</summary>
						initonly static ReverbParametersI3DL2^ Forest = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Forest);

						/// <summary>Constant for city preset</summary>
						initonly static ReverbParametersI3DL2^ City = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::City);

						/// <summary>Constant for mountains preset</summary>
						initonly static ReverbParametersI3DL2^ Mountains = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Mountains);

						/// <summary>Constant for quarry preset</summary>
						initonly static ReverbParametersI3DL2^ Quarry = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Quarry);

						/// <summary>Constant for plain preset</summary>
						initonly static ReverbParametersI3DL2^ Plain = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Plain);

						/// <summary>Constant for parking lot preset</summary>
						initonly static ReverbParametersI3DL2^ ParkingLot = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::ParkingLot);

						/// <summary>Constant for sewer pipe preset</summary>
						initonly static ReverbParametersI3DL2^ SewerPipe = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::SewerPipe);

						/// <summary>Constant for underwater preset</summary>
						initonly static ReverbParametersI3DL2^ Underwater = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Underwater);

						/// <summary>Constant for small room preset</summary>
						initonly static ReverbParametersI3DL2^ SmallRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::SmallRoom);

						/// <summary>Constant for medium room preset</summary>
						initonly static ReverbParametersI3DL2^ MediumRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::MediumRoom);

						/// <summary>Constant for large room preset</summary>
						initonly static ReverbParametersI3DL2^ LargeRoom = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::LargeRoom);

						/// <summary>Constant for medium hall preset</summary>
						initonly static ReverbParametersI3DL2^ MediumHall = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::MediumHall);

						/// <summary>Constant for large hall preset</summary>
						initonly static ReverbParametersI3DL2^ LargeHall = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::LargeHall);

						/// <summary>Constant for plate preset</summary>
						initonly static ReverbParametersI3DL2^ Plate = gcnew ReverbParametersI3DL2(ReverbParametersI3DL2Helper::Plate);
					#pragma endregion


					#pragma region Fields
					protected:
						/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						Single wetDryMix;

						/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
						Int32 room;

						/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
						Int32 roomHF;

						/// <value>Clamped from 0.0 to 10.0</value>
						Single roomRolloffFactor;

						/// <value>Clamped from 0.1 to 20.0, in seconds</value>
						Single decayTime;

						/// <value>Clamped from 0.1 to 2.0</value>
						Single decayHFRatio;

						/// <value>Clamped from -10000 to 1000, in mB (hundredths of decibels)</value>
						Int32 reflections;

						/// <value>Clamped from 0.0 to 0.3, in seconds</value>
						Single reflectionsDelay;

						/// <value>Clamped from -10000 to 2000, in mB (hundredths of decibels)</value>
						Int32 reverb;

						/// <value>Clamped from 0.0 to 0.1, in seconds</value>
						Single reverbDelay;

						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						Single diffusion;

						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						Single density;

						/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
						Single hfReference;
					#pragma endregion


					#pragma region Properties
					public:
						/// <summary>Ratio of wet (processed) signal to dry (original) signal</summary>
						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						property Single WetDryMix
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
						property Int32 Room
						{
							Int32 get();
							void set(Int32 value);
						}

						/// <value>Clamped from -10000 to 0, in mB (hundredths of decibels)</value>
						property Int32 RoomHF
						{
							Int32 get();
							void set(Int32 value);
						}

						/// <value>Clamped from 0.0 to 10.0</value>
						property Single RoomRolloffFactor
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from 0.1 to 20.0, in seconds</value>
						property Single DecayTime
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from 0.1 to 2.0</value>
						property Single DecayHFRatio
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from -10000 to 1000, in mB (hundredths of decibels)</value>
						property Int32 Reflections
						{
							Int32 get();
							void set(Int32 value);
						}

						/// <value>Clamped from 0.0 to 0.3, in seconds</value>
						property Single ReflectionsDelay
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from -10000 to 2000, in mB (hundredths of decibels)</value>
						property Int32 Reverb
						{
							Int32 get();
							void set(Int32 value);
						}

						/// <value>Clamped from 0.0 to 0.1, in seconds</value>
						property Single ReverbDelay
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						property Single Diffusion
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from 0 to 100, indicating a percentage</value>
						property Single Density
						{
							Single get();
							void set(Single value);
						}

						/// <value>Clamped from 20.0 to 20000.0, in Hz</value>
						property Single HFReference
						{
							Single get();
							void set(Single value);
						}
					#pragma endregion



					#pragma region Construction
					public:
						/// <summary>Default constructor</summary>
						ReverbParametersI3DL2();

						/// <summary>Definition constructor</summary>
						/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
						/// <param name="room">Intensity level and low-pass filter for the room effect</param>
						/// <param name="roomHF">Attenuation at high frequencies relative to the intensity at low frequencies</param>
						/// <param name="roomRolloff">Rolloff of room effect intensity vs. distance</param>
						/// <param name="decayTime">Reverberation decay time at low frequencies</param>
						/// <param name="decayRatio">Ratio of high-frequency decay time relative to low-frequency decay time</param>
						/// <param name="reflections">Adjusts intensity level of early reflections (relative to Room value)</param>
						/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
						/// <param name="reverb">Adjusts intensity of late reverberation (relative to Room value)</param>
						/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
						/// <param name="diffusion">Controls the echo density in the late reverberation decay</param>
						/// <param name="density">Controls the modal density in the late reverberation decay</param>
						/// <param name="hfRef">Reference high frequency</param>
						ReverbParametersI3DL2(Single wetDry, Int32 room, Int32 roomHF, Single roomRolloff, Single decayTime, Single decayRatio, Int32 reflections, Single reflectionsDelay, Int32 reverb, Single reverbDelay, Single diffusion, Single density, Single hfRef);

					internal:
						/// <summary>Definition constructor</summary>
						/// <param name="managed">Managed XAUDIO2FX_REVERB_I3DL2_PARAMETERS struct to copy from</param>
						ReverbParametersI3DL2(XAUDIO2FX_REVERB_I3DL2_PARAMETERS managed);


					protected:
						/// <summary>Definition method</summary>
						/// <param name="wetDry">Ratio of wet (processed) signal to dry (original) signal</param>
						/// <param name="room">Intensity level and low-pass filter for the room effect</param>
						/// <param name="roomHF">Attenuation at high frequencies relative to the intensity at low frequencies</param>
						/// <param name="roomRolloff">Rolloff of room effect intensity vs. distance</param>
						/// <param name="decayTime">Reverberation decay time at low frequencies</param>
						/// <param name="decayRatio">Ratio of high-frequency decay time relative to low-frequency decay time</param>
						/// <param name="reflections">Adjusts intensity level of early reflections (relative to Room value)</param>
						/// <param name="reflectionsDelay">Delay time of the first reflection (relative to the direct path)</param>
						/// <param name="reverb">Adjusts intensity of late reverberation (relative to Room value)</param>
						/// <param name="reverbDelay">Defines the time limit between the early reflections and the late reverberation (relative to the time of the first reflection)</param>
						/// <param name="diffusion">Controls the echo density in the late reverberation decay</param>
						/// <param name="density">Controls the modal density in the late reverberation decay</param>
						/// <param name="hfRef">Reference high frequency</param>
						void DefineReverb(Single wetDry, Int32 room, Int32 roomHF, Single roomRolloff, Single decayTime, Single decayRatio, Int32 reflections, Single reflectionsDelay, Int32 reverb, Single reverbDelay, Single diffusion, Single density, Single hfRef);
					#pragma endregion
					};
				}
			}
		}
	}
}


#endif

