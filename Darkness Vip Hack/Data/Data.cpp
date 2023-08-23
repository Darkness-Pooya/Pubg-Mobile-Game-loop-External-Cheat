#include "Data.h"
#include<thread>
#include "Memory.h"

using namespace std;
using namespace Utility;
using namespace Data;
using namespace Algorithm;


Espp* g_pEsp = new Espp();
DWORD Data::ViewMatrixBase;
DWORD Data::UWorld = 0;
BYTE ViewMatrixSearch[] =
{
	0x02, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x01
};

DWORD Data::GetViewMatrixBase(DWORD StartAddress, DWORD EndAddress)
{
	DWORD ViewMatrixBase = 0;
	std::vector<DWORD_PTR> FoundedBase;
	MemSearch(ViewMatrixSearch, sizeof(ViewMatrixSearch), StartAddress, EndAddress, 0, 0, FoundedBase);

	for (int i = 0; i < FoundedBase.size(); i++)
	{
		DWORD Cand = FoundedBase[i] - 0x20;
		DWORD Eng = ReadMemoryEx<DWORD>(Cand) + 0x20;
		DWORD Tmp = ReadMemoryEx<DWORD>(Eng) + 0x200;

		float v1, v2, v3, v4;
		v1 = ReadMemoryEx<float>(Tmp + 0x8);
		v2 = ReadMemoryEx<float>(Tmp + 0x18);
		v3 = ReadMemoryEx<float>(Tmp + 0x28);
		v4 = ReadMemoryEx<float>(Tmp + 0x38);

		if (v1 == 0 && v2 == 0 && v3 == 0 && v4 >= 3)
		{
			ViewMatrixBase = Cand;
			FoundedBase.resize(0);
			break;
		}
	}

	FoundedBase.resize(0);
	return ViewMatrixBase;
}

string GetString(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = Utility::ReadMemoryEx<char>(BaseAddress + i);
	}

	string Result = String;

	delete[] String;
	return Result;
}


DWORD libUE4Base;



struct ObjectName
{
	char Data[64];
};

BOOL IsPlayer(string EntityType)
{
	if (EntityType.find("BP_PlayerPawn") != string::npos || EntityType.find("BP_PlayerCharacter") != string::npos || EntityType.find("PlanET_FakePlayer") != string::npos || EntityType.find("PlayerPawn_Infec") != string::npos)
	{
		return TRUE;
	}

	return FALSE;
}


string PlayerWeapon(string str)
{
	if (str == "BP_Sniper_AWM_C")
		return "AWM";
	else if (str == "BP_Sniper_QBU_C")
		return "QBU";
	else if (str == "BP_Sniper_SLR_C")
		return "SLR";
	else if (str == "BP_Sniper_SKS_C")
		return "SKS";
	else if (str == "BP_Sniper_Mini14_C")
		return "Mini14";
	else if (str == "BP_Sniper_M24_C")
		return "M24";
	else if (str == "BP_Sniper_Kar98k_C")
		return "Kar98k";
	else if (str == "BP_Sniper_VSS_C")
		return "VSS";
	else if (str == "BP_Sniper_Win94_C")
		return "Win94";
	else if (str == "BP_Sniper_Mosin_C")
		return "Mosin";
	else if (str == "BP_Sniper_MK12_C")
		return "MK12";
	else if (str == "BP_Rifle_AUG_C")
		return "AUG";
	else if (str == "BP_Rifle_M762_C")
		return "M762";
	else if (str == "BP_Rifle_SCAR_C")
		return "SCAR";
	else if (str == "BP_Rifle_M416_C")
		return "M416";
	else if (str == "BP_Rifle_M16A4_C")
		return "M16A4";
	else if (str == "BP_Rifle_Mk47_C")
		return "Mk47";
	else if (str == "BP_Rifle_G36_C")
		return "G36";
	else if (str == "BP_Rifle_QBZ_C")
		return "QBZ";
	else if (str == "BP_Rifle_AKM_C")
		return "AKM";
	else if (str == "BP_Rifle_Groza_C")
		return "Groza";
	else if (str == "BP_Other_DP28_C")
		return "DP28";
	else if (str == "BP_Other_MG3_C")
		return "MG3";
	else if (str == "BP_Other_M249_C")
		return "M249";
	else if (str == "BP_MachineGun_P90_C")
		return "P90";
	else if (str == "BP_ShotGun_S12K_C")
		return "S12K";
	else if (str == "BP_ShotGun_DPS_C" || str == "BP_ShotGun_Dps_C")
		return "DPS";
	else if (str == "BP_ShotGun_M1014_C" || str == "BP_ShotGun_m1014_C")
		return "M1014";
	else if (str == "BP_ShotGun_NS2000_C" || str == "BP_ShotGun_Ns2000_C")
		return "NS2000";
	else if (str == "BP_ShotGun_DP12_C")
		return "DP12";
	else if (str == "BP_ShotGun_S686_C")
		return "S686";
	else if (str == "BP_ShotGun_S1897_C")
		return "S1897";
	else if (str == "BP_ShotGun_SawedOff_C")
		return "SawedOff";
	else if (str == "BP_MachineGun_PP19_C")
		return "PP19";
	else if (str == "BP_MachineGun_TommyGun_C")
		return "TommyGu";
	else if (str == "BP_MachineGun_MP5K_C")
		return "MP5K";
	else if (str == "BP_MachineGun_UMP9_C")
		return "UMP9";
	else if (str == "BP_MachineGun_Vector_C")
		return "Vector";
	else if (str == "BP_MachineGun_Thompson_C" || str == "BP_MachineGun_THOMPSON_C")
		return "Thompson";
	else if (str == "BP_MachineGun_Bizon_C" || str == "BP_MachineGun_BIZON_C")
		return "BIZON";
	else if (str == "BP_MachineGun_Uzi_C")
		return "Uzi";
	else if (str == "BP_Pistol_Flaregun_C")
		return "Flaregun";
	else if (str == "BP_Pistol_R1895_C")
		return "R1895";
	else if (str == "BP_Pistol_Vz61_C")
		return "Vz61";
	else if (str == "BP_Pistol_P92_C")
		return "P92";
	else if (str == "BP_Pistol_P18C_C")
		return "P18C";
	else if (str == "BP_Pistol_R45_C")
		return "R45";
	else if (str == "BP_Pistol_P1911_C")
		return "P1911";
	else if (str == "BP_Pistol_DesertEagle_C")
		return "DesertEagle";
	else if (str == "BP_WEP_Mk14_C")
		return "Mk14";
	else if (str == "BP_Other_CrossBow_C")
		return "CrossBow";
	else if (str == "BP_Other_HuntingBowEA_C")
		return "Explosive - BOW";
	else if (str == "BP_Rifle_HoneyBadger_C")
		return "Honey Badger";
	else if (str == "BP_Grenade_Shoulei_C")
		return "Shoulei Grenade";
	else if (str == "BP_Grenade_Smoke_C")
		return "Smoke Grenade";
	else if (str == "BP_Sniper_AMR_C" || str == "BP_Sniper_AMR_C")
		return "AMR";
	else if (str == "BP_Grenade_Burn_C")
		return "Burn Grenade";
	else if (str == "BP_Rifle_FAMAS_C" || str == "BP_Rifle_FAMAS_C")
		return "FAMAS";
	else
		return "";
	return "";
}

string GetItemType(string Name) {

	// When the element is not found, std::find returns the end of the range

	if (Settings::Akm) if (Name == "BP_Rifle_AKM_Wrapper_C") return "Akm";
	if (Settings::M16A4) if (Name == "BP_Rifle_M16A4_Wrapper_C") return "M16A4";
	if (Settings::SCARL)if (Name == "BP_Rifle_SCAR_Wrapper_C") return "SCARL";
	if (Settings::M416)if (Name == "BP_Rifle_M416_Wrapper_C") return "M416";
	if (Settings::GROZA)if (Name == "BP_Rifle_Groza_Wrapper_C") return "GROZA";
	if (Settings::AUG)if (Name == "BP_Rifle_AUG_Wrapper_C") return "AUG";
	if (Settings::QBZ)if (Name == "BP_Rifle_QBZ_Wrapper_C") return "QBZ";
	if (Settings::M762)if (Name == "BP_Rifle_M762_Wrapper_C") return "M762";
	if (Settings::MK47)if (Name == "BP_Rifle_Mk47_Wrapper_C") return "MK47";
	if (Settings::G36C)if (Name == "BP_Rifle_G36_Wrapper_C") return "G36C";
	if (Settings::HONEY)if (Name == "BP_Rifle_HoneyBadger_Wrapper_C") return "HONEY";
	if (Settings::FAMAS)if (Name == "BP_Rifle_FAMAS_Wrapper_C") return "FAMAS";
	if (Settings::KAR98)if (Name == "BP_Sniper_Kar98k_Wrapper_C") return "KAR98";
	if (Settings::M24)if (Name == "BP_Sniper_M24_Wrapper_C") return "M24";
	if (Settings::AWM)if (Name == "BP_Sniper_AWM_Wrapper_C") return "AWM";
	if (Settings::WIN94)if (Name == "BP_Sniper_Win94_Wrapper_C") return "WIN94";
	if (Settings::MOSIN)if (Name == "BP_Sniper_MOSIN_Wrapper_C") return "MOSIN";
	if (Settings::AMR)if (Name == "BP_Sniper_AMR_Wrapper_C") return "AMR";
	if (Settings::SKS)if (Name == "BP_Sniper_SKS_Wrapper_C") return "SKS";
	if (Settings::VSS)if (Name == "BP_Sniper_VSS_Wrapper_C") return "VSS";
	if (Settings::MINI14)if (Name == "BP_Sniper_Mini14_Wrapper_C") return "MINI14";
	if (Settings::MK14)if (Name == "BP_Sniper_MK14_Wrapper_C") return "MK14";
	if (Settings::SLR)if (Name == "BP_Sniper_SLR_Wrapper_C") return "SLR";
	if (Settings::QBU)if (Name == "BP_Sniper_QBU_Wrapper_C") return "QBU";
	if (Settings::MK12)if (Name == "BP_Other_MK12_Wrapper_C") return "MK12";
	if (Settings::UZI)if (Name == "BP_MachineGun_Uzi_Wrapper_C") return "UZI";
	if (Settings::UMP45)if (Name == "BP_MachineGun_UMP9_Wrapper_C" || Name == "BP_MachineGun_UMP45_Wrapper_C") return "UMP45";
	if (Settings::VECTOR)if (Name == "BP_MachineGun_Vector_Wrapper_C") return "VECTOR";
	if (Settings::THOMPSON)if (Name == "BP_MachineGun_THOMPSON_Wrapper_C") return "THOMPSON";
	if (Settings::BIZON)if (Name == "BP_MachineGun_Bizon_Wrapper_C") return "BIZON";
	if (Settings::MP5K)if (Name == "BP_MachineGun_MP5K_Wrapper_C") return "MP5K";
	if (Settings::P90)if (Name == "BP_MachineGun_P90_Wrapper_C") return "P90";
	if (Settings::S686)if (Name == "BP_ShotGun_S686_Wrapper_C") return "S686";
	if (Settings::S1897)if (Name == "BP_ShotGun_S1897_Wrapper_C") return "S1897";
	if (Settings::S12K)if (Name == "BP_ShotGun_S12K_Wrapper_C") return "S12K";
	if (Settings::DBS)if (Name == "BP_ShotGun_DBS_Wrapper_C") return "DBS";
	if (Settings::M1014)if (Name == "BP_ShotGun_M1014_Wrapper_C") return "M1014";
	if (Settings::NS2000)if (Name == "BP_ShotGun_NS2000_Wrapper_C") return "NS2000";
	if (Settings::M249)if (Name == "BP_Other_M249_Wrapper_C") return "M249";
	if (Settings::DP28)if (Name == "BP_Other_DP28_Wrapper_C") return "DP28";
	if (Settings::MG3)if (Name == "BP_Other_MG3_Wrapper_C") return "MG3";
	if (Settings::FLARE)if (Name == "BP_Pistol_Flaregun_Wrapper_C") return "FLARE";
	if (Settings::FRAG)if (Name == "BP_Grenade_Shoulei_Weapon_Wrapper_C") return "FRAG";
	if (Settings::SMOKE)if (Name == "BP_Grenade_Smoke_Weapon_Wrapper_C") return "SMOKE";
	if (Settings::MOLOTOF)if (Name == "BP_Grenade_Burn_Weapon_Wrapper_C") return "MOLOTOF";
	if (Settings::MedKit)if (Name == "FirstAidbox_Pickup_C") return "MedKit";
	if (Settings::FirstAidKit)if (Name == "Firstaid_Pickup_C") return "FirstAidKit";
	if (Settings::Painkiller)if (Name == "Pills_Pickup_C") return "Painkiller";
	if (Settings::EnergyDrink)if (Name == "Drink_Pickup_C") return "EnergyDrink";
	if (Settings::Adrenalin)if (Name == "Injection_Pickup_C") return "Adrenalin";
	if (Settings::Bag1)if (Name == "PickUp_BP_Bag_Lv1") return "Bag1";
	if (Settings::Bag2)if (Name == "PickUp_BP_Bag_Lv2") return "Bag2";
	if (Settings::Bag3)if (Name == "PickUp_BP_Bag_Lv3") return "Bag3";
	if (Settings::Helmet1)if (Name == "PickUp_BP_Helmet_Lv1") return "Helmet1";
	if (Settings::Helmet2)if (Name == "PickUp_BP_Helmet_Lv2") return "Helmet2";
	if (Settings::Helmet3)if (Name == "PickUp_BP_Helmet_Lv3") return "Helmet3";
	if (Settings::Armor1)if (Name == "PickUp_BP_Armor_Lv1") return "Armor1";
	if (Settings::Armor2)if (Name == "PickUp_BP_Armor_Lv2") return "Armor2";
	if (Settings::Armor3)if (Name == "PickUp_BP_Armor_Lv3") return "Armor3";
	if (Settings::a762mm)if (Name == "BP_Ammo_762mm_Pickup_C") return "7.62mm";
	if (Settings::a556mm)if (Name == "BP_Ammo_556mm_Pickup_C") return "5.56mm";
	if (Settings::a9mm)if (Name == "BP_Ammo_9mm_Pickup_C") return "9mm";
	if (Settings::a45ACP)if (Name == "BP_Ammo_45ACP_Pickup_C") return "45ACP";
	if (Settings::a12Gauege)if (Name == "BP_Ammo_12Gauege_Pickup_C") return "12Gauege";
	if (Settings::AwmAmmo)if (Name == "BP_Ammo_300Magnum_Pickup_C") return "AwmAmmo";
	if (Settings::AmrAmmo)if (Name == "BP_Ammo_50BMG_Pickup_C") return "AmrAmmo";
	if (Settings::Scope_x2)if (Name == "BP_MZJ_2X_Pickup_C") return "Scope_x2";
	if (Settings::Scope_x3)if (Name == "BP_MZJ_3X_Pickup_C") return "Scope_x3";
	if (Settings::Scope_x4)if (Name == "BP_MZJ_4X_Pickup_C") return "Scope_x4";
	if (Settings::Scope_x6)if (Name == "BP_MZJ_6X_Pickup_C") return "Scope_x6";
	if (Settings::Scope_x8)if (Name == "BP_MZJ_8X_Pickup_C") return "Scope_x8";
	if (Settings::GrandeWarning) 	if (Name.find("BP_Grenade_Burn_C") != std::string::npos)return "Burn";
	if (Settings::GrandeWarning) if (Name.find("BP_Grenade_Shoulei_C") != string::npos) return "Frag";

	if (Name == "AirDropListWrapperActor" || Name == "BP_AirDropBox_New_C")  return "Air Drop";
	if (Settings::ShopToken)if (Name.find("GoldenTokenWrapper_C") != string::npos) return "Shop Token";

	return "Unknown";
}


bool IsAirDrop(std::string classname)
{
	if (classname.find("BP_AirDropBox_C") != string::npos || classname.find("AirDropListWrapperActor") != string::npos)

		return true;
	else
		return false;
	return false;
}

bool IsBox(string classname)
{
	if (classname.find("PlayerDeadInventoryBox") != string::npos || classname.find("PickUpListWrapperActor") != string::npos)
		return true;
	else
		return false;
	return false;
}
string GetVehicleType(string Name)
{
	if (Name.find("BRDM") != string::npos) return "BRDM";
	if (Name.find("Scooter") != string::npos) return "Scooter";
	if (Name.find("Motorcycle") != string::npos) return "Motorcycle";
	if (Name.find("Snowmobile") != string::npos) return "Snowmobile";
	if (Name.find("Tuk") != string::npos) return "Tuk";
	if (Name.find("Buggy") != string::npos) return "Buggy";
	if (Name.find("open") != string::npos) return "Sports";
	if (Name.find("close") != string::npos) return "Sportsa";
	if (Name.find("Dacia") != string::npos) return "Dacia";
	if (Name.find("Monster Truck") != string::npos) return "Monster Truck";
	if (Name.find("Rony") != string::npos) return "Rony";
	if (Name.find("UAZ") != string::npos) return "UAZ";
	if (Name.find("MiniBus") != string::npos) return "Minibus";
	if (Name.find("PG117") != string::npos) return "PG117";
	if (Name.find("AquaRail") != string::npos) return "Aquarail";
	if (Name.find("CoupeRB") != string::npos) return "Coupe";
	if (Name.find("ModelY") != string::npos) return "Tesla";
	if (Name.find("G-38Anti-GravityMotorcycle") != string::npos) return "Gravity";
	if (Name.find("Glider") != string::npos) return "Glider";
	if (Name.find("VH_UTV_C") != string::npos) return "UTV";
	if (Name.find("BP_VH_Bigfoot_C") != string::npos) return "MONSTER";
	if (Name.find("ATV1_C") != string::npos) return "Quad";
	if (Name.find("ATV2_C") != string::npos) return "Quad";
	if (Name.find("ATV3_C") != string::npos) return "Quad";
	if (Name.find("ATV4_C") != string::npos) return "Quad";
	if (Name.find("ATV5_C") != string::npos) return "Quad";
	if (Name.find("ATV6_C") != string::npos) return "Quad";
	if (Name.find("VH_Motorglider_SI_C") != string::npos) return "Glider";
	return "Unknown";
}


struct ActorsEncryption {
	uint32_t Enc_1, Enc_2;
	uint32_t Enc_3, Enc_4;
};
uint32_t Data::ActorsPointerAddress;
std::string result;

//std::string GetEntityType(long gNames, long id)
//{
//
//	if (id > 0 && id < 2000000)
//	{
//		DWORD secPartAddv = ReadMemoryEx<DWORD>(gNames + id / 16384 + (id / 16384) * 3);
//		if (secPartAddv > 0)
//		{
//			secPartAddv = ReadMemoryEx<DWORD>(secPartAddv + id % 16384 + (id % 16384) * 3);
//			if (secPartAddv > 0)
//			{
//				result = string(ReadMemoryEx<ObjectName>(secPartAddv + 8).Data);
//			}
//		}
//	}
//	return result;
//}
string GetEntityType(LONG GNames, LONG Id)
{
	DWORD GName = Utility::ReadMemoryEx<DWORD>(GNames);
	DWORD NamePtr = Utility::ReadMemoryEx<DWORD>(GName + int(Id / 16384) * 0x4);
	DWORD Name = Utility::ReadMemoryEx<DWORD>(NamePtr + int(Id % 16384) * 0x4);
	ObjectName pBuffer = Utility::ReadMemoryEx<ObjectName>(Name + 0x8);

	return string(pBuffer.Data);
}
struct Encryption_Chunk {
	uint32_t val_1, val_2;
	uint32_t val_3, val_4;
};


std::string GetBoxItems(int code)
{
	if (code == 101008)
	{
		Settings::colorcode = Settings::M762Color;
		return "M762";

	}
	else if (code == 306001)
	{
		Settings::colorcode = Settings::AwmAmmoColor;
		return "AWM Ammo";
	}

	else if (code == 101003)
	{
		Settings::colorcode = Settings::SCARLColor;
		return "SCAR-L";
	}
	else if (code == 302001)
	{

		Settings::colorcode = Settings::a762mmColor;
		return "7.62";
	}
	else if (code == 303001)
	{

		Settings::colorcode = Settings::a556mmColor;
		return "5.56";
	}
	else if (code == 602004)
	{
		Settings::colorcode = Settings::FRAGColor;

		return "Grenade";
	}
	else if (code == 601006)
	{
		Settings::colorcode = Settings::MedKitColor;

		return "Medkit";
	}
	else if (code == 101004)
	{
		Settings::colorcode = Settings::M416Color;
		return "M416";
	}
	else if (code == 102001)
	{
		Settings::colorcode = Settings::UZIColor;
		return "UZI";
	}
	else if (code == 101010)
	{
		Settings::colorcode = Settings::G36CColor;
		return "G36";
	}

	else if (code == 101006)
	{
		Settings::colorcode = Settings::AUGColor;
		return "AUG";
	}


	else if (code == 101001)
	{
		Settings::colorcode = Settings::AkmColor;
		return "AKM";
	}

	else if (code == 101005)
	{
		Settings::colorcode = Settings::GROZAColor;
		return "Groza";
	}

	else if (code == 103003)
	{
		Settings::colorcode = Settings::AWMColor;
		return "AWM";
	}

	else if (code == 103002)
	{
		Settings::colorcode = Settings::M24Color;
		return "M24";
	}

	else if (code == 103001)
	{
		Settings::colorcode = Settings::KAR98Color;
		return "Kar98k";
	}

	else if (code == 103011)
	{
		Settings::colorcode = Settings::MOSINColor;
		return "Mosin";
	}

	else if (code == 502002)
	{
		Settings::colorcode = Settings::Helmet2Color;
		return "Helmet Lv.2";
	}

	else if (code == 502003)
	{
		Settings::colorcode = Settings::Helmet3Color;
		return "Helmet Lv.3";
	}

	else if (code == 503002)
	{
		Settings::colorcode = Settings::Armor2Color;
		return "Armour Lv.2";
	}

	else if (code == 503003)
	{
		Settings::colorcode = Settings::Armor3Color;
		return "Armour Lv.3";
	}

	else if (code == 501006)
	{
		Settings::colorcode = Settings::Bag3Color;
		return "Bag Lv.3";
	}

	else if (code == 501005)
	{
		Settings::colorcode = Settings::Bag2Color;
		return "Bag Lv.2";
	}

	else if (code == 203014)
	{
		Settings::colorcode = Settings::Scope_x3Color;
		return "3X";

	}
	else if (code == 103007)
	{
		Settings::colorcode = Settings::AWMColor;
		return "MK14";

	}
	else if (code == 203004)
	{
		Settings::colorcode = Settings::Scope_x4Color;
		return "4x";
	}

	else if (code == 203015)
	{
		Settings::colorcode = Settings::Scope_x6Color;
		return "6x";
	}

	else if (code == 203005)
	{
		Settings::colorcode = Settings::Scope_x8Color;
		return "8x";
	}

	else if (code == 106007)
	{
		Settings::colorcode = Settings::FLAREColor;
		return "Flaregun";
	}

	else if (code == 105001)
	{
		Settings::colorcode = Settings::M249Color;
		return "M249";
	}

	else if (code == 105002)
	{
		Settings::colorcode = Settings::DP28Color;
		return "DP28";
	}

	else if (code == 105010)
	{
		Settings::colorcode = Settings::MG3Color;
		return "MG3";
	}

	return "tatti";
}

bool Data::InLobby = true;

string GetGrenadeType(string classname)
{
	if (classname.find("BP_Grenade_Burn_C") != string::npos)
		return  "Burn";
	if (classname.find("BP_Grenade_Shoulei_C") != string::npos)
		return "Frag";
	if (classname.find("AirAttackBomb_Livik_C") != std::string::npos || classname.find("AirAttackBomb_C") != std::string::npos) return "Redzone";

	return "Unknown";
}
CameraCacheEntry Data::CameraCache;
DWORD Data::NetDriver;
DWORD Data::LocalPlayer;
DWORD Data::PlayerCameraManager;
DWORD Data::PlayerController;
vector<AActor> Data::AActorList = {};
vector<Item> Data::ItemList = {};
vector<Vehicle> Data::VehicleList = {};
string Data::Map;
string Data::PlayerPlayerName = "";
string Data::PlayerNation = "";
string Data::PlayerUID = "";

int Data::PlayerTotalKills;
int Data::PlayerTeamID;
int Data::PlayerLevel;
FLOAT Data::PlayerHealth;
FLOAT Data::PlayerTravelDistance;
string GetPlayerName(DWORD BaseAddress)
{
	char* String = new char[34];
	for (int i = 0; i < 34; i++)
	{
		String[i] = ReadMemoryEx<char>(BaseAddress + i * 2);
	}

	return String;
}
namespace Decryption
{
	// pubg 2.4 32bit
	//32bit
	//00 20 90 E5 E0 10 94 E5 0C 20 92 E5

	struct ActorsEncryption {
		uint32_t Enc_1; //0x0340 
		uint32_t Enc_2; //0x0344 
		uint32_t Enc_3; //0x0348 
		uint32_t Enc_4; //0x034C 
	};
	struct Encryption_Chunk {
		uint32_t val_1, val_2, val_3, val_4;
	};
	uint32_t DecryptActorsArray(uint32_t uLevel, int Actors_Offset, int EncryptedActors_Offset)
	{
		if (uLevel < 0x10000000)
			return 0;

		if (ReadMemoryEx<uint32_t>(uLevel + Actors_Offset) > 0)
			return uLevel + Actors_Offset;
		else
		{
			std::cout << "Try Find Next Decryption Address 1" << std::endl;

		}

		if (ReadMemoryEx<uint32_t>(uLevel + EncryptedActors_Offset) > 0)
			return uLevel + EncryptedActors_Offset;
		else
		{
			std::cout << "Try Find Next Decryption Address 2" << std::endl;

		}
		auto Encryption = ReadMemoryEx<ActorsEncryption>(uLevel + EncryptedActors_Offset + 0x0C);

		if (Encryption.Enc_1 > 0)
		{
			auto Enc = ReadMemoryEx<Encryption_Chunk>(Encryption.Enc_1 + 0x80);

			return ((ReadMemoryEx<unsigned __int8>(Encryption.Enc_1 + Enc.val_1))
				| ((ReadMemoryEx<unsigned __int8>(Encryption.Enc_1 + Enc.val_2)) << 8)
				| ((ReadMemoryEx<unsigned __int8>(Encryption.Enc_1 + Enc.val_3)) << 16)
				| ((ReadMemoryEx<unsigned __int8>(Encryption.Enc_1 + Enc.val_4)) << 24));
		} //ok
		else if (Encryption.Enc_2 > 0)
		{
			auto Encrypted_Actors = ReadMemoryEx<uint32_t>(Encryption.Enc_2);
			if (Encrypted_Actors > 0)
			{
				return (Encrypted_Actors - 0x4000000) & 0xFF000000
					| (Encrypted_Actors + 0xFC0000) & 0xFF0000
					| ((unsigned __int16)Encrypted_Actors - 0x400) & 0xFF00
					| (unsigned __int8)(Encrypted_Actors - 4);
			}
		} //ok
		else if (Encryption.Enc_3 > 0)
		{
			auto Encrypted_Actors = ReadMemoryEx<uint32_t>(Encryption.Enc_3);
			if (Encrypted_Actors > 0)
				return (Encrypted_Actors >> 0x18) | (Encrypted_Actors << (32 - 0x18));
		}
		else if (Encryption.Enc_4 > 0)
		{
			auto Encrypted_Actors = ReadMemoryEx<uint32_t>(Encryption.Enc_4);
			if (Encrypted_Actors > 0)
				return Encrypted_Actors ^ 0xCDCD00;
		}
		else
		{
			std::cout << "Cant Find Decryption Address" << std::endl;
		}
		return 0;
	}
}
VOID Data::QueryThread()
{
	DWORD GWorld;
	DWORD GName;
	DWORD libUE4Base = ReadMemoryEx<DWORD>(0x0E0C3860);
	if (Data::ViewMatrixBase != 0) {
		GWorld = ReadMemoryEx<DWORD>(Data::ViewMatrixBase + 115004) + 60;
		GName = ReadMemoryEx<DWORD>(Data::ViewMatrixBase - 3211240) + 136;
	}
	else {
		GName = ReadMemoryEx<DWORD>(libUE4Base + 0x8435468) + 0x88;
		GWorld = ReadMemoryEx<DWORD>(libUE4Base + 0x876185C) + 0x3C;
		Data::ViewMatrixBase = ReadMemoryEx<DWORD>(ReadMemoryEx<DWORD>(libUE4Base + 0x8745720) + 0x7c);
	}
	DWORD PersistentLevel = 0;
	DWORD ServerConnection = 0;
	DWORD EntityList = 0;
	INT EntityCount = 0;
	DWORD LocalController;
	DWORD EntityStruct = 0;
	string EntityType = "";
	DWORD EntityAddress;
	DWORD RootComponent = 0;
	INT MyTeamId = 0;
	DWORD MeshAddv;
	DWORD BodyAddv;
	DWORD BoneAddv;
	string wep = "";

	string ItemType = "";
	string VehicleType = "";
	string airdroptype = "";
	string deadboxtype = "";
	DWORD gnameget;
	vector<AActor> AActorListtt = {};
	vector<Vehicle> VehicleList = {};
	vector<Item> ItemList = {};
	DWORD PlayerStateBASE;
	DWORD GameStateBASE;
	uint32_t ActorsPointerAddress;
	DWORD  count;

	DWORD veh;
	float HP;
	float HPMax;
	float Fuel;
	float FuelMax;
	long itemBase;
	long itemAddv;
	while (true)
	{
		UWorld = ReadMemoryEx<DWORD>(GWorld);
		PersistentLevel = ReadMemoryEx<DWORD>(UWorld + Offset::Data::PersistentLevel);
		NetDriver = ReadMemoryEx<DWORD>(UWorld + Offset::Data::NetDriver);

		if (Data::NetDriver > 0)
		{
			Data::InLobby = false;
		}
		else
		{
			Data::InLobby = true;
		}
		if (!InLobby) {
			gnameget = ReadMemoryEx<DWORD>(GName);

			ServerConnection = ReadMemoryEx<DWORD>(NetDriver + Offset::Data::ServerConnection);
			PlayerController = ReadMemoryEx<DWORD>(ServerConnection + Offset::Data::PlayerController);
			LocalPlayer = ReadMemoryEx<DWORD>(PlayerController + Offset::Data::AcknowledgedPawn);

			LocalController = ReadMemoryEx<DWORD>(LocalPlayer + Offset::Camera::LocalController);
			PlayerCameraManager = ReadMemoryEx<DWORD>(LocalController + Offset::Camera::PlayerCameraManager);
			CameraCache = ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::Camera::CameraCache);

			ActorsPointerAddress = Decryption::DecryptActorsArray(PersistentLevel, 0x70, 0x334);//--Actors
			EntityList = ReadMemoryEx<uint32_t>(ActorsPointerAddress);
			EntityCount = ReadMemoryEx<int>(ActorsPointerAddress + 0x4);

			PlayerStateBASE = ReadMemoryEx<DWORD>(LocalPlayer + 0x300);//Class: UAEPlayerState.LuaPlayerState.PlayerState.Info.Actor.Object

			if (Settings::YourInfo)
			{
				Data::PlayerTotalKills = ReadMemoryEx<INT>(PlayerStateBASE + 0x4bc);
				Data::PlayerPlayerName = GetPlayerName(ReadMemoryEx<DWORD>(PlayerStateBASE + 0x2f4));
				Data::PlayerNation = GetPlayerName(ReadMemoryEx<DWORD>(PlayerStateBASE + 0x49c));
				Data::PlayerTeamID = ReadMemoryEx<INT>(PlayerStateBASE + 0x4a8);
				Data::PlayerLevel = ReadMemoryEx<INT>(PlayerStateBASE + 0x460);
				Data::PlayerHealth = ReadMemoryEx<FLOAT>(PlayerStateBASE + 0xec0);
				Data::PlayerUID = GetPlayerName(ReadMemoryEx<DWORD>(PlayerStateBASE + 0x434));

			}
			GameStateBASE = ReadMemoryEx<DWORD>(UWorld + Offset::GameStateBase);

			if (Settings::GameInfo)
			{
				Settings::AlivePlayers = ReadMemoryEx<INT>(GameStateBASE + Offset::AlivePlayerNum);
				Settings::TimeRemind = ReadMemoryEx<INT>(GameStateBASE + Offset::ElapsedTime);
				Settings::AliveTeams = ReadMemoryEx<INT>(GameStateBASE + Offset::AliveTeamNum);
				Settings::RealPls = ReadMemoryEx<INT>(GameStateBASE + Offset::PlayerNum);
				Settings::ZoneID = ReadMemoryEx<INT>(GameStateBASE + Offset::CurCircleWave) + 2;
				Settings::MyTeamID = ReadMemoryEx<INT>(LocalPlayer + Offset::Player::TeamId);
				Settings::GameID = ReadMemoryEx<INT>(GameStateBASE + Offset::GameModeID) * -1;
				Data::PlayerTravelDistance = ReadMemoryEx<FLOAT>(GameStateBASE + 0x418);

			}
			for (int i = 0; i < EntityCount; ++i)
			{
				EntityAddress = ReadMemoryEx<DWORD>(EntityList + i * 4);

				EntityStruct = ReadMemoryEx<DWORD>(EntityAddress + 0x10);

				//if (EntityStruct < 0x20000000 && EntityStruct > 0x0) 
				{

					EntityType = GetEntityType(GName, EntityStruct);

					{
						RootComponent = ReadMemoryEx<DWORD>(EntityAddress + Offset::Data::RootComponent);
						if (IsPlayer(EntityType))
						{
							AActor AActor;
							AActor.IsDead = ReadMemoryEx<bool>(EntityAddress + Offset::Player::IsDead);
							if (AActor.IsDead)  continue;
							AActor.TeamId = ReadMemoryEx<int>(EntityAddress + Offset::Player::TeamId);
							if (MyTeamId == AActor.TeamId)  continue;

							AActor.Address = EntityAddress;

							if (AActor.Address == LocalPlayer)
							{
								MyTeamId = AActor.TeamId;
								continue;
							}
							if (Settings::PlayerWeapon)
							{
								{
									wep = PlayerWeapon(GetEntityType(gnameget, ReadMemoryEx<DWORD>(ReadMemoryEx<DWORD>(EntityAddress + Offset::Player::weaponOffset) + 16)));
									if (wep == "")
										wep = "Fist";
									AActor.weapon = wep;
								}
							}


							AActor.Position = ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
							AActor.IsBot = ReadMemoryEx<bool>(EntityAddress + Offset::Player::IsBot);

							if (!AActor.IsBot)
							{
								AActor.Nation = GetPlayerName(ReadMemoryEx<DWORD>(EntityAddress + Offset::Player::Nation));
								AActor.Name = GetPlayerName(ReadMemoryEx<DWORD>(EntityAddress + Offset::Player::Name));
								AActor.status = ReadMemoryEx<int>(EntityAddress + Offset::Player::CurrentStates);

							}
							else
							{
								AActor.Name = "[ Bot ]";
								AActor.Nation = "";
							}

							AActor.Health = ReadMemoryEx<float>(EntityAddress + Offset::Player::Health);
							AActor.HealthMax = ReadMemoryEx<float>(EntityAddress + Offset::Player::HealthMax);
							AActor.Velocity = ReadMemoryEx<VECTOR3>(ReadMemoryEx<DWORD>(AActor.Address + Offset::CharacterMovement) + Offset::LastUpdateVelocity);
							AActor.TeamId = ReadMemoryEx<int>(EntityAddress + Offset::Player::TeamId);

							//if (Settings::PlayerSkeleton || Settings::MagicBullet)
							{
								MeshAddv = ReadMemoryEx<DWORD>(AActor.Address + Offset::Bone::Mesh);
								BodyAddv = MeshAddv + Offset::Bone::BodyAddv;
								BoneAddv = ReadMemoryEx<DWORD>(MeshAddv + Offset::Bone::MinLOD) + 48;
								AActor.HeadPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);
								AActor.ChestPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 4 * 48);
								AActor.PelvisPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 1 * 48);
							}

							if (Settings::PlayerSkeleton || Settings::MagicBullet)
							{

								AActor.lSholderPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 11 * 48);
								AActor.rSholderPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 32 * 48);
								AActor.lElbowPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 12 * 48);
								AActor.rElbowPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 33 * 48);
								AActor.lWristPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 63 * 48);
								AActor.rWristPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 62 * 48);
								AActor.lThighPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 52 * 48);
								AActor.rThighPos = GetBoneWorldPosition(BodyAddv, BoneAddv + 56 * 48);
								AActor.lKneePos = GetBoneWorldPosition(BodyAddv, BoneAddv + 53 * 48);
								AActor.rKneePos = GetBoneWorldPosition(BodyAddv, BoneAddv + 57 * 48);
								AActor.lAnklePos = GetBoneWorldPosition(BodyAddv, BoneAddv + 54 * 48);
								AActor.rAnklePos = GetBoneWorldPosition(BodyAddv, BoneAddv + 58 * 48);
							}

							AActorListtt.push_back(AActor);
						}
						else {
							ItemType = GetGrenadeType(EntityType);
							if (ItemType != "Unknown")
							{

								Item Item;
								Item.Name = ItemType;
								Item.Position = ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

								ItemList.push_back(Item);
							}
							if (!Settings::FightMode) {
								if (Settings::Lootbox && IsBox(EntityType))
								{

									g_pEsp->lootbox.push_back(g_pEsp->lbox);
									count = ReadMemoryEx<DWORD>(EntityAddress + Offset::LootBox::boxItemsCount);
									if (count > 30)
										count = 30;
									g_pEsp->lbox.boxitem.resize(0);
									if (count > 0)

									{
										itemBase = ReadMemoryEx<DWORD>(EntityAddress + Offset::LootBox::itemBase);
										itemAddv;

										for (int t = 0; t < count; t++)
										{
											itemAddv = itemBase + t * 48;
											string bitm = GetBoxItems(ReadMemoryEx<DWORD>(itemAddv + 0x4));
											if (bitm.find("tatti") == string::npos)
											{
												Itemb temo;
												bitm.append("  :  ").append(to_string(ReadMemoryEx<DWORD>(itemAddv + 0x18)));
												g_pEsp->lbox.Position = ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);
												temo.colorcod = Settings::colorcode;
												temo.Displayname = bitm;
												g_pEsp->lbox.boxitem.push_back(temo);
											}
										}
									}


								}

								else {

									if (Settings::Items)
									{
										ItemType = GetItemType(EntityType);
										if (ItemType.find("Unknown") == string::npos)
										{

											Item Item;
											Item.Name = ItemType;
											Item.Position = ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

											ItemList.push_back(Item);
										}
									}

									if (Settings::Vehicle)
									{
										VehicleType = GetVehicleType(EntityType);
										if (VehicleType.find("Unknown") == string::npos)
										{

											Vehicle Vehicle;
											Vehicle.Name = VehicleType;
											Vehicle.Position = ReadMemoryEx<VECTOR3>(RootComponent + Offset::Position);

											veh = ReadMemoryEx<DWORD>(EntityAddress + Offset::vehicle::VehicleCommon);
											HP = ReadMemoryEx<float>(veh + Offset::vehicle::HP);
											HPMax = ReadMemoryEx<float>(veh + Offset::vehicle::HPMax);
											//	int _HP = (int)(HP * 100 / HPMax);
											Vehicle.hp = (int)(HP * 100 / HPMax);
											Vehicle.driving = ReadMemoryEx<DWORD>(EntityAddress + 0x719);//bool bIsEngineStarted;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset: 
											Fuel = ReadMemoryEx<float>(veh + Offset::vehicle::Fuel);
											FuelMax = ReadMemoryEx<float>(veh + Offset::vehicle::FuelMax);

											Vehicle.oil = (int)(Fuel * 100 / FuelMax);

											VehicleList.push_back(Vehicle);
										}
									}
								}
							}

						}
					}

				}

			}
		}
		Data::AActorList.resize(0);
		Data::ItemList.resize(0);
		Data::VehicleList.resize(0);
		g_pEsp->lootboxr.resize(0);
		Data::AActorList = AActorListtt;
		Data::ItemList = ItemList;
		Data::VehicleList = VehicleList;
		g_pEsp->lootboxr = g_pEsp->lootbox;
		AActorListtt.resize(0);
		ItemList.resize(0);
		VehicleList.resize(0);
		g_pEsp->lootbox.resize(0);
		g_pEsp->lootbox.resize(0);
		std::this_thread::sleep_for(std::chrono::milliseconds(Settings::UpdateTick));

	}
}
