#pragma once

#include "Includes.h"

namespace Offset
{

	/// <summary>
	namespace Data {
		const DWORD PersistentLevel = 0x20;
		const DWORD NetDriver = 0x24;
		const DWORD ServerConnection = 0x60;
		const DWORD PlayerController = 0x20;
		const DWORD AcknowledgedPawn = 0x360; // PlayerController.Controller.Actor.Object Pawn* AcknowledgedPawn;//[Offset:
		const DWORD EntityList = 0x70;
		const DWORD EntityCount = 0x74;
		const DWORD GameState = 0x138;
		const DWORD gameInstance = 0x24;
		const DWORD RootComponent = 0x150; // SceneComponent* RootComponent;//[Offset:
	}
	const DWORD playerCarry = 0x20;


	namespace STExtraPlayerCharacter {
		constexpr auto STPlayerController = 0x2ea4;
	}


	////////////GOD VIEW/////////////
	const DWORD SceneComponent = 0x11d0; // SceneComponent* MeshContainer;//[Offset:
	const DWORD CustomSpringArmComponent = 0x1324; // CustomSpringArmComponent* SpringArmComp

	extern struct Vector2 {
		float x = 0;
		float y = 0;
	};
	extern struct Vector3 {
		float x = 0;
		float y = 0;
		float z = 0;
	};
	extern struct Vector4 {
		float x = 0;
		float y = 0;
		float z = 0;
		float w = 0;
	};
	extern struct D3DMatrix {
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;
	};
	struct playerData
	{
		DWORD Address, Pose, World;
		Vector3 Position;
		int Status, TeamID, Health, Distance;
		int AlivePlayers = 0;
		int TimeRemind = 0;
		int AliveTeams = 0;
		int RealPls = 0;
		int ZoneID = 0;
		int MyTeamID = 0;
		int GameID = 0;
		bool IsRobot;
		bool IsDead;
		std::string Name, Type, weapon, Nation;
	};

	struct Item {
		DWORD Address;
		std::string displayName;
		Vector3 Position;
		int color;
		int picid;
	};

	struct Specl {
		DWORD Address;
		std::string displayName;
	};

	struct ItmInfo {
		std::string name;
		int color;
	};

	struct AimInfo {
		Vector3 Head, Chest;
		Vector2 Screen;
	};
	struct Lootbox {
		Vector3 Position;

		std::vector<Item> boxitem;
		int picid;
	};

	struct Vehicle {
		DWORD Address, VehicleComm;
		std::string displayName;
		Vector3 Position;
		int picid;
		int MaxHP, MaxFuel;
		int HP, Fuel;
	};
	struct Vehicle2 {
		DWORD Address, VehicleComm2;
		std::string displayName;
		Vector3 Position;
		int picid;

	};

	struct Vehicle3 {
		DWORD Address, VehicleComm3;
		std::string displayName;
		Vector3 Position;
		int picid;

	};
	//struct Lootbox {
	//    Vector3 Position;
	//    std::string itemname;
	//};
	struct Vehicle4 {
		DWORD Address, VehicleComm4;
		std::string displayName;
		Vector3 Position;
		int picid;

	};

	namespace Hacks {
		const DWORD FastRun = 0x2280;			//CharacterOverrideAttrs CharacterOverrideAttrs;//[Offset:
		// Instant hit
		const DWORD CurrentReloadWeapon = 0x212c;//STExtraWeapon* CurrentReloadWeapon;//[Offset:
		const DWORD CurShootIntervalMode = 0xc84; //enum CurShootIntervalMode;//[Offset: 
		//show dmg
		const DWORD GameReplayType = 0x740; //int GameReplayType;//[Offset:
		//////SPEED OFFSETS/////
		const DWORD CharacterOverrideAttrs = 0x2280; //CharacterOverrideAttrs CharacterOverrideAttrs;
		//repid fire
		const DWORD ShootInterval = 0x434; /// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object float ShootInterval;//[Offset:
		//no spread
		const DWORD GameDeviationFactor = 0x930; ////********* float GameDeviationFactor
		const DWORD ShotGunVerticalSpread = 0x928; //Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object float ShotGunVerticalSpread
		const DWORD ShotGunHorizontalSpread = 0x92c; ///********* float ShotGunHorizontalSpread

		// NoRecoil offsets
		const DWORD AccessoriesVRecoilFactor = 0x8c8; //Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object float AccessoriesVRecoilFactor;//[Offset:
		const DWORD AccessoriesHRecoilFactor = 0x8cc; //float AccessoriesHRecoilFactor;//[Offset:
		const DWORD AccessoriesRecoveryFactor = 0x8d0; //float AccessoriesRecoveryFactor;//[Offset:
		//car speed 
		const DWORD bIsEngineStarted = 0x75d;//bool bIsEngineStarted;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
		//FastSwitch
		const DWORD SwitchWeaponSpeedScale = 0x1e34; ///Class: STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object float SwitchWeaponSpeedScale;//[Offset:
		//Fast Land
		const DWORD CharacterParachuteComponent = 0xff0; //CharacterParachuteComponent* ParachuteComponent
		const DWORD CurrentFallSpeed = 0x14c; //CurrentFallSpeed;//[Offset:

		const DWORD bHasSingleFireMode = 0x480;//bool bHasSingleFireMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
		const DWORD bHasAutoFireMode = 0x481;//bool bHasAutoFireMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
		const DWORD BulletFireSpeed = 0x408; //Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object float BulletFireSpeed
		const DWORD IsFPPGameMode = 0x6b4;//IsFPPGameMode;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:
	}


	// AActor
	namespace Player {
		const DWORD CurrentStates = 0xb20;// uint64 CurrentStates;//[Offset:
		const DWORD IsDead = 0x9f4;//bool bDead;//(ByteOffset: 0, ByteMask: 1, FieldMask: 1)[Offset:
		const DWORD TeamId = 0x6b4; //Class: UAECharacter.Character.Pawn.Actor.Object int TeamID;//[Offset:
		const DWORD PoseState = 0x100c; //Class: UAECharacter.Character.Pawn.Actor.Object byte PoseState;//[Offset:
		const DWORD IsBot = 0x734; // bool bIsAI;//(ByteOffset:
		const DWORD Name = 0x680; //Class: UAECharacter.Character.Pawn.Actor.Object FString PlayerName;//[Offset:
		//const DWORD Status = 0xaf8; // Class: UAECharacter.Character.Pawn.Actor.Object FString PlayerName;//[Offset:
		const DWORD Nation = 0x794; //FString Nation;//[Offset: 
		const DWORD Health = 0x9dc; // float Health;//[Offset:
		const DWORD HealthMax = 0x9e0; // float HealthMax;//[Offset:
		const DWORD weaponOffset = 0x1d18; //STExtraWeapon* CurrentWeapon;
	}

	// Lot BOX
	namespace LootBox {
		const DWORD PickUpItemData = 0x6a0; // PickUpItemData[] PickUpDataList;//[Offset: 
		const DWORD boxItemsCount = 0x6a4; // PickUpItemData[] PickUpDataList;//[Offset:   + 0x4
		const DWORD itemBase = 0x6a0; // PickUpItemData[] PickUpDataList;//[Offset:   
	}

	/// </summary>
	const DWORD CharacterMovement = 0x350; // CharacterMovementComponent* CharacterMovement;//[Offset:
	const DWORD LastUpdateVelocity = 0x250; // Vector LastUpdateVelocity;//[Offset:
	const DWORD Velocity = 0xc8; // Vector Velocity;//[Offset:

	const DWORD RelativeLocation = 0x118; // Vector RelativeLocation;//[Offset: 0x120,
	const DWORD RelativeRotation = 0x124; // Rotator RelativeRotation;//[Offset: 0x12c,
	const DWORD Position = 0x150;
	const DWORD IsVisible = 0x1bc;///SceneComponent.ActorComponent.Object , bool bVisible;//(ByteOffset: 0, ByteMask: 1, FieldMask: 1)[Offset:
	// Bone
	namespace Bone {
		const DWORD Mesh = 0x34c; // SkeletalMeshComponent* Mesh;//[Offset: 0x320, / tmpOffset
		const DWORD BodyAddv = 0x140; // enum meshType;//[Offset
		const DWORD MinLOD = 0x63c; // int MinLOD;//[Offset: 0x5b0, / boneOffset
	}
	// Camera
	namespace Camera {
		const DWORD LocalController = 0x2ea4; //STExtraPlayerController* STPlayerController;//[Offset
		const DWORD PlayerCameraManager = 0x370;// Class: PlayerController.Controller.Actor.Object -> PlayerCameraManager* PlayerCameraManager;//[Offset: 0x340,
		const DWORD CameraCache = 0x370; // Class: PlayerCameraManager.Actor.Object -> CameraCacheEntry CameraCache;//[Offset: 0x350,
		const DWORD POV = 0x10; // Class: CameraCacheEntry -> MinimalViewInfo POV;//[Offset: 0x10,
		const DWORD Location = 0x0; // Class: MinimalViewInfo -> Vector Location;//[Offset: 0x0,
		const DWORD Rotation = 0x18; // Class: MinimalViewInfo -> Rotator Rotation;//[Offset: 0x18,
		const DWORD FOV = 0x24; // Class: MinimalViewInfo -> float FOV;//[Offset: 0x24,
	}


	///////
	const DWORD bEnablePlayerPickUpAnim = 0x17f4;//float voiceCheckShowCD;//[Offset:
	//Game Status
	const DWORD GameStateBase = 0x138; //Class: World.Object   GameStateBase* GameState;//[Offset:
	const DWORD AlivePlayerNum = 0x7f4; //Class: STExtraGameStateBase.UAEGameState.LuaGameState.GameState.GameStateBase.Info.Actor.Object  int AlivePlayerNum;//[Offset:
	const DWORD ElapsedTime = 0x348; //Class: GameState.GameStateBase.Info.Actor.Object -> int ElapsedTime;//[Offset:
	const DWORD AliveTeamNum = 0x7f8; //int AliveTeamNum;//[Offset:
	const DWORD PlayerNum = 0x554; // int PlayerNum;//[Offset:
	const DWORD CurCircleWave = 0x778; //int CurCircleWave;//[Offset:
	const DWORD GameModeID = 0xbf8; //Class: STExtraGameStateBase.UAEGameState.LuaGameState.GameState.GameStateBase.Info.Actor.Object  ->  FString GameModeID;//[Offset:


	const DWORD ShootWeaponEntity = 0xc70; // ShootWeaponEntity* ShootWeaponEntityComp;//[Offset: 

	//
	//
	////vehicle
	namespace vehicle {
		const DWORD VehicleCommon = 0x77c; // VehicleCommonComponent* VehicleCommon;//[Offset:
		const  DWORD lastForwardSpeed = 0x800;  // 2.4
		const DWORD HP = 0x1e4; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float HP;//[Offset: 0x11c, Size: 4]
		const DWORD HPMax = 0x1e0; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float HPMax;//[Offset: 0x118,
		const DWORD FuelMax = 0x200; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float FuelMax;//[Offset: 0x130,
		const DWORD Fuel = 0x204; // Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float Fuel;//[Offset: 0x134,
	}

}