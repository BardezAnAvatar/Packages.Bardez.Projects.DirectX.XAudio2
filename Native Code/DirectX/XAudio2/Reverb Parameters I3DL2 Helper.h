

#ifndef XAUDIO2_Reverberation_Parameters_I3DL2_Helper
#define XAUDIO2_Reverberation_Parameters_I3DL2_Helper


extern "C"
{
	#include <XAudio2fx.h>
}


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
					private class ReverbParametersI3DL2Helper
					{
					#pragma region Preset reverb settings
					public:
						/// <summary>Constant for default preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Default;

						/// <summary>Constant for generic preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Generic;

						/// <summary>Constant for padded cell preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS PaddedCell;

						/// <summary>Constant for a generic "room" preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS GenericRoom;

						/// <summary>Constant for bathroom preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS BathRoom;

						/// <summary>Constant for living room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS LivingRoom;

						/// <summary>Constant for stone room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS StoneRoom;

						/// <summary>Constant for auditorium preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Auditorum;

						/// <summary>Constant for concert hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS ConcertHall;

						/// <summary>Constant for cave preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Cave;

						/// <summary>Constant for arena preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Arena;

						/// <summary>Constant for hangar preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Hangar;

						/// <summary>Constant for carpeted hallway preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS CarpetedHallway;

						/// <summary>Constant for hallway preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Hallway;

						/// <summary>Constant for stone corridor preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS StoneCorridor;

						/// <summary>Constant for alley preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Alley;

						/// <summary>Constant for forest preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Forest;

						/// <summary>Constant for city preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS City;

						/// <summary>Constant for mountains preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Mountains;

						/// <summary>Constant for quarry preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Quarry;

						/// <summary>Constant for plain preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Plain;

						/// <summary>Constant for parking lot preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS ParkingLot;

						/// <summary>Constant for sewer pipe preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS SewerPipe;

						/// <summary>Constant for underwater preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Underwater;

						/// <summary>Constant for small room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS SmallRoom;

						/// <summary>Constant for medium room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS MediumRoom;

						/// <summary>Constant for large room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS LargeRoom;

						/// <summary>Constant for medium hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS MediumHall;

						/// <summary>Constant for large hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS LargeHall;

						/// <summary>Constant for plate preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS Plate;
					#pragma endregion
					};

					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Default = XAUDIO2FX_I3DL2_PRESET_DEFAULT;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Generic = XAUDIO2FX_I3DL2_PRESET_GENERIC;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::PaddedCell = XAUDIO2FX_I3DL2_PRESET_PADDEDCELL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::GenericRoom = XAUDIO2FX_I3DL2_PRESET_ROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::BathRoom = XAUDIO2FX_I3DL2_PRESET_BATHROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::LivingRoom = XAUDIO2FX_I3DL2_PRESET_LIVINGROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::StoneRoom = XAUDIO2FX_I3DL2_PRESET_STONEROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Auditorum = XAUDIO2FX_I3DL2_PRESET_AUDITORIUM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::ConcertHall = XAUDIO2FX_I3DL2_PRESET_CONCERTHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Cave = XAUDIO2FX_I3DL2_PRESET_CAVE;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Arena = XAUDIO2FX_I3DL2_PRESET_ARENA;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Hangar = XAUDIO2FX_I3DL2_PRESET_HANGAR;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::CarpetedHallway = XAUDIO2FX_I3DL2_PRESET_CARPETEDHALLWAY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Hallway = XAUDIO2FX_I3DL2_PRESET_HALLWAY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::StoneCorridor = XAUDIO2FX_I3DL2_PRESET_STONECORRIDOR;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Alley = XAUDIO2FX_I3DL2_PRESET_ALLEY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Forest = XAUDIO2FX_I3DL2_PRESET_FOREST;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::City = XAUDIO2FX_I3DL2_PRESET_CITY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Mountains = XAUDIO2FX_I3DL2_PRESET_MOUNTAINS;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Quarry = XAUDIO2FX_I3DL2_PRESET_QUARRY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Plain = XAUDIO2FX_I3DL2_PRESET_PLAIN;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::ParkingLot = XAUDIO2FX_I3DL2_PRESET_PARKINGLOT;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::SewerPipe = XAUDIO2FX_I3DL2_PRESET_SEWERPIPE;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Underwater = XAUDIO2FX_I3DL2_PRESET_UNDERWATER;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::SmallRoom = XAUDIO2FX_I3DL2_PRESET_SMALLROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::MediumRoom = XAUDIO2FX_I3DL2_PRESET_MEDIUMROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::LargeRoom = XAUDIO2FX_I3DL2_PRESET_LARGEROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::MediumHall = XAUDIO2FX_I3DL2_PRESET_MEDIUMHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::LargeHall = XAUDIO2FX_I3DL2_PRESET_LARGEHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersI3DL2Helper::Plate = XAUDIO2FX_I3DL2_PRESET_PLATE;
				}
			}
		}
	}
}


#endif

