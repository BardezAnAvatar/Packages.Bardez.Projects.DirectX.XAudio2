

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
					/// <summary>Local assembly class that houses unmanaged representations of XAudio2 reverberation effect parameters</summary>
					/// <remarks>Host to an I3DL2 standard compliant parameter set as well as a native XAudio2 parameter set</remarks>
					private class ReverbParametersConstants
					{
					#pragma region Static I3DL2 reverb settings
					public:
						/// <summary>Constant for default preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Default;

						/// <summary>Constant for generic preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Generic;

						/// <summary>Constant for padded cell preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_PaddedCell;

						/// <summary>Constant for a generic "room" preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_GenericRoom;

						/// <summary>Constant for bathroom preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_BathRoom;

						/// <summary>Constant for living room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_LivingRoom;

						/// <summary>Constant for stone room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_StoneRoom;

						/// <summary>Constant for auditorium preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Auditorum;

						/// <summary>Constant for concert hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_ConcertHall;

						/// <summary>Constant for cave preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Cave;

						/// <summary>Constant for arena preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Arena;

						/// <summary>Constant for hangar preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Hangar;

						/// <summary>Constant for carpeted hallway preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_CarpetedHallway;

						/// <summary>Constant for hallway preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Hallway;

						/// <summary>Constant for stone corridor preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_StoneCorridor;

						/// <summary>Constant for alley preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Alley;

						/// <summary>Constant for forest preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Forest;

						/// <summary>Constant for city preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_City;

						/// <summary>Constant for mountains preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Mountains;

						/// <summary>Constant for quarry preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Quarry;

						/// <summary>Constant for plain preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Plain;

						/// <summary>Constant for parking lot preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_ParkingLot;

						/// <summary>Constant for sewer pipe preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_SewerPipe;

						/// <summary>Constant for underwater preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Underwater;

						/// <summary>Constant for small room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_SmallRoom;

						/// <summary>Constant for medium room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_MediumRoom;

						/// <summary>Constant for large room preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_LargeRoom;

						/// <summary>Constant for medium hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_MediumHall;

						/// <summary>Constant for large hall preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_LargeHall;

						/// <summary>Constant for plate preset</summary>
						static XAUDIO2FX_REVERB_I3DL2_PARAMETERS I3DL2_Plate;
					#pragma endregion


						
					#pragma region Static Xaudio2 native reverb settings
					public:
						/// <summary>Constant for default preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Default;

						/// <summary>Constant for generic preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Generic;

						/// <summary>Constant for padded cell preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_PaddedCell;

						/// <summary>Constant for a generic "room" preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_GenericRoom;

						/// <summary>Constant for bathroom preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_BathRoom;

						/// <summary>Constant for living room preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_LivingRoom;

						/// <summary>Constant for stone room preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_StoneRoom;

						/// <summary>Constant for auditorium preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Auditorum;

						/// <summary>Constant for concert hall preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_ConcertHall;

						/// <summary>Constant for cave preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Cave;

						/// <summary>Constant for arena preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Arena;

						/// <summary>Constant for hangar preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Hangar;

						/// <summary>Constant for carpeted hallway preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_CarpetedHallway;

						/// <summary>Constant for hallway preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Hallway;

						/// <summary>Constant for stone corridor preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_StoneCorridor;

						/// <summary>Constant for alley preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Alley;

						/// <summary>Constant for forest preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Forest;

						/// <summary>Constant for city preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_City;

						/// <summary>Constant for mountains preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Mountains;

						/// <summary>Constant for quarry preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Quarry;

						/// <summary>Constant for plain preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Plain;

						/// <summary>Constant for parking lot preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_ParkingLot;

						/// <summary>Constant for sewer pipe preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_SewerPipe;

						/// <summary>Constant for underwater preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Underwater;

						/// <summary>Constant for small room preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_SmallRoom;

						/// <summary>Constant for medium room preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_MediumRoom;

						/// <summary>Constant for large room preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_LargeRoom;

						/// <summary>Constant for medium hall preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_MediumHall;

						/// <summary>Constant for large hall preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_LargeHall;

						/// <summary>Constant for plate preset</summary>
						static XAUDIO2FX_REVERB_PARAMETERS Native_Plate;
					#pragma endregion
					};
					
					/* Populate the I3DL2 constants */
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Default			=	XAUDIO2FX_I3DL2_PRESET_DEFAULT;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Generic			=	XAUDIO2FX_I3DL2_PRESET_GENERIC;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_PaddedCell		=	XAUDIO2FX_I3DL2_PRESET_PADDEDCELL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_GenericRoom		=	XAUDIO2FX_I3DL2_PRESET_ROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_BathRoom			=	XAUDIO2FX_I3DL2_PRESET_BATHROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_LivingRoom		=	XAUDIO2FX_I3DL2_PRESET_LIVINGROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_StoneRoom		=	XAUDIO2FX_I3DL2_PRESET_STONEROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Auditorum		=	XAUDIO2FX_I3DL2_PRESET_AUDITORIUM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_ConcertHall		=	XAUDIO2FX_I3DL2_PRESET_CONCERTHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Cave				=	XAUDIO2FX_I3DL2_PRESET_CAVE;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Arena			=	XAUDIO2FX_I3DL2_PRESET_ARENA;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Hangar			=	XAUDIO2FX_I3DL2_PRESET_HANGAR;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_CarpetedHallway	=	XAUDIO2FX_I3DL2_PRESET_CARPETEDHALLWAY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Hallway			=	XAUDIO2FX_I3DL2_PRESET_HALLWAY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_StoneCorridor	=	XAUDIO2FX_I3DL2_PRESET_STONECORRIDOR;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Alley			=	XAUDIO2FX_I3DL2_PRESET_ALLEY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Forest			=	XAUDIO2FX_I3DL2_PRESET_FOREST;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_City				=	XAUDIO2FX_I3DL2_PRESET_CITY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Mountains		=	XAUDIO2FX_I3DL2_PRESET_MOUNTAINS;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Quarry			=	XAUDIO2FX_I3DL2_PRESET_QUARRY;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Plain			=	XAUDIO2FX_I3DL2_PRESET_PLAIN;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_ParkingLot		=	XAUDIO2FX_I3DL2_PRESET_PARKINGLOT;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_SewerPipe		=	XAUDIO2FX_I3DL2_PRESET_SEWERPIPE;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Underwater		=	XAUDIO2FX_I3DL2_PRESET_UNDERWATER;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_SmallRoom		=	XAUDIO2FX_I3DL2_PRESET_SMALLROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_MediumRoom		=	XAUDIO2FX_I3DL2_PRESET_MEDIUMROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_LargeRoom		=	XAUDIO2FX_I3DL2_PRESET_LARGEROOM;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_MediumHall		=	XAUDIO2FX_I3DL2_PRESET_MEDIUMHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_LargeHall		=	XAUDIO2FX_I3DL2_PRESET_LARGEHALL;
					XAUDIO2FX_REVERB_I3DL2_PARAMETERS ReverbParametersConstants::I3DL2_Plate			=	XAUDIO2FX_I3DL2_PRESET_PLATE;

					/* Populate the native constants */
					//ReverbConvertI3DL2ToNative(&ReverbParametersConstants::I3DL2_Default, &ReverbParametersConstants::Native_Default);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Default			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Default);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Generic			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Generic);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_PaddedCell		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_PaddedCell);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_GenericRoom		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_GenericRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_BathRoom			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_BathRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_LivingRoom		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_LivingRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_StoneRoom			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_StoneRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Auditorum			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Auditorum);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_ConcertHall		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_ConcertHall);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Cave				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Cave);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Arena				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Arena);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Hangar			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Hangar);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_CarpetedHallway	=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_CarpetedHallway);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Hallway			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Hallway);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_StoneCorridor		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_StoneCorridor);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Alley				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Alley);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Forest			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Forest);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_City				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_City);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Mountains			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Mountains);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Quarry			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Quarry);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Plain				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Plain);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_ParkingLot		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_ParkingLot);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_SewerPipe			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_SewerPipe);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Underwater		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Underwater);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_SmallRoom			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_SmallRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_MediumRoom		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_MediumRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_LargeRoom			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_LargeRoom);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_MediumHall		=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_MediumHall);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_LargeHall			=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_LargeHall);
					//XAUDIO2FX_REVERB_PARAMETERS ReverbParametersConstants::Native_Plate				=	ReverbConvertI3DL2ToNative(ReverbParametersConstants::I3DL2_Plate);
				}
			}
		}
	}
}


#endif

