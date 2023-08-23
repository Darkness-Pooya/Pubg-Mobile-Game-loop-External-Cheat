#define STB_IMAGE_IMPLEMENTATION
#pragma warning(disable : 4996)
#include ".\Settings\Settings.h"
#include <D3DX11tex.h>
#define LOADER_BRAND "Loader base"
#include "..\iconcpp.h"

#include "Esp.h"
#include <iostream>
#include <fstream>
#include "..\Data\Data.h"
#include "auth.hpp"
#include "..\SimpleIni.h"
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include ".\\discord\\Discord.h"
#include "..\Memory.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <Psapi.h>
#include <cstring>
#include <array>
#include <thread>
#include <iterator>
#include "..\Images\Images.h"
#include <math.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <random>
#include <stdexcept>
#include <filesystem>
#include <stdio.h>
#include "ImagesInclude.hpp"
#include <sstream> 
Discord* g_Discord;
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = "2.3"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're sز elf-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

void InitImages() {
	D3DX11_IMAGE_LOAD_INFO info;
	ID3DX11ThreadPump* pump{ nullptr };
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LOGO, sizeof(LOGO), &info, pump, &Logo, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RedZone, sizeof(RedZone), &info, pump, &RedZoneImage, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ASWSAw, sizeof(ASWSAw), &info, pump, &BRU, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SM44, sizeof(SM44), &info, pump, &Smk, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GN1, sizeof(GN1), &info, pump, &GN2, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AirDropHex, sizeof(AirDropHex), &info, pump, &AirDropImage, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AkmHex, sizeof(AkmHex), &info, pump, &AkmImage, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ScarHex, sizeof(ScarHex), &info, pump, &ScarImage, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ShopTokenHex, sizeof(ShopTokenHex), &info, pump, &ShopTokenImage, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, M416Hex, sizeof(M416Hex), &info, pump, &M416Image, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, M762Hex, sizeof(M762Hex), &info, pump, &M762Image, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Ammo5Hex, sizeof(Ammo5Hex), &info, pump, &Ammo5Image, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, Ammo7Hex, sizeof(Ammo7Hex), &info, pump, &Ammo7Image, 0);


	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AF, sizeof(AF), &info, pump, &AFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AL, sizeof(AL), &info, pump, &ALFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DZ, sizeof(DZ), &info, pump, &DZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AS, sizeof(AS), &info, pump, &ASFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AD, sizeof(AD), &info, pump, &ADFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AO, sizeof(AO), &info, pump, &AOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AI, sizeof(AI), &info, pump, &AIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AG, sizeof(AG), &info, pump, &AGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AR, sizeof(AR), &info, pump, &ARFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AM, sizeof(AM), &info, pump, &AMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AW, sizeof(AW), &info, pump, &AWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AU, sizeof(AU), &info, pump, &AUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AT, sizeof(AT), &info, pump, &ATFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AZ, sizeof(AZ), &info, pump, &AZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BS, sizeof(BS), &info, pump, &BSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BH, sizeof(BH), &info, pump, &BHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BD, sizeof(BD), &info, pump, &BDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BB, sizeof(BB), &info, pump, &BBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BY, sizeof(BY), &info, pump, &BYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BE, sizeof(BE), &info, pump, &BEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BZ, sizeof(BZ), &info, pump, &BZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BJ, sizeof(BJ), &info, pump, &BJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BM, sizeof(BM), &info, pump, &BMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BT, sizeof(BT), &info, pump, &BTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BO, sizeof(BO), &info, pump, &BOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BA, sizeof(BA), &info, pump, &BAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BW, sizeof(BW), &info, pump, &BWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BV, sizeof(BV), &info, pump, &BVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IO, sizeof(IO), &info, pump, &BRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IO, sizeof(IO), &info, pump, &IOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BN, sizeof(BN), &info, pump, &BNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BG, sizeof(BG), &info, pump, &BGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BF, sizeof(BF), &info, pump, &BFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BI, sizeof(BI), &info, pump, &BIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CV, sizeof(CV), &info, pump, &CVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KH, sizeof(KH), &info, pump, &KHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CM, sizeof(CM), &info, pump, &CMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CA, sizeof(CA), &info, pump, &CAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KY, sizeof(KY), &info, pump, &KYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CF, sizeof(CF), &info, pump, &CFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TD, sizeof(TD), &info, pump, &TDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CL, sizeof(CL), &info, pump, &CLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CN, sizeof(CN), &info, pump, &CNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CX, sizeof(CX), &info, pump, &CXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CC, sizeof(CC), &info, pump, &CCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CO, sizeof(CO), &info, pump, &COFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KM, sizeof(KM), &info, pump, &KMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CD, sizeof(CD), &info, pump, &CDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CG, sizeof(CG), &info, pump, &CGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CK, sizeof(CK), &info, pump, &CKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CR, sizeof(CR), &info, pump, &CRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HR, sizeof(HR), &info, pump, &HRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CU, sizeof(CU), &info, pump, &CUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CW, sizeof(CW), &info, pump, &CWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CY1, sizeof(CY1), &info, pump, &CYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CZ, sizeof(CZ), &info, pump, &CZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CI, sizeof(CI), &info, pump, &CIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DK, sizeof(DK), &info, pump, &DKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DJ, sizeof(DJ), &info, pump, &DJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DM, sizeof(DM), &info, pump, &DMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DO, sizeof(DO), &info, pump, &DOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EC, sizeof(EC), &info, pump, &ECFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EG, sizeof(EG), &info, pump, &EGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SV, sizeof(SV), &info, pump, &SVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GQ, sizeof(GQ), &info, pump, &GQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ER, sizeof(ER), &info, pump, &ERFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, EE, sizeof(EE), &info, pump, &EEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SZ, sizeof(SZ), &info, pump, &SZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ET, sizeof(ET), &info, pump, &ETFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FK, sizeof(FK), &info, pump, &FKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FO, sizeof(FO), &info, pump, &FOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FJ, sizeof(FJ), &info, pump, &FJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FI, sizeof(FI), &info, pump, &FIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FR, sizeof(FR), &info, pump, &FRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GF, sizeof(GF), &info, pump, &GFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PF, sizeof(PF), &info, pump, &PFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TF, sizeof(TF), &info, pump, &TFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GA, sizeof(GA), &info, pump, &GAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GM, sizeof(GM), &info, pump, &GMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GE, sizeof(GE), &info, pump, &GEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, DE, sizeof(DE), &info, pump, &DEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GH, sizeof(GH), &info, pump, &GHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LY, sizeof(LY), &info, pump, &LYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LI, sizeof(LI), &info, pump, &LIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LT, sizeof(LT), &info, pump, &LTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LU, sizeof(LU), &info, pump, &LUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MO, sizeof(MO), &info, pump, &MOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MG, sizeof(MG), &info, pump, &MGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MW, sizeof(MW), &info, pump, &MWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MY, sizeof(MY), &info, pump, &MYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MV, sizeof(MV), &info, pump, &MVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ML, sizeof(ML), &info, pump, &MLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MT, sizeof(MT), &info, pump, &MTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MH, sizeof(MH), &info, pump, &MHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MQ, sizeof(MQ), &info, pump, &MQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MR, sizeof(MR), &info, pump, &MRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MU, sizeof(MU), &info, pump, &MUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, YT, sizeof(YT), &info, pump, &YTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MX, sizeof(MX), &info, pump, &MXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, FM, sizeof(FM), &info, pump, &FMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MD, sizeof(MD), &info, pump, &MDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MC, sizeof(MC), &info, pump, &MCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MN, sizeof(MN), &info, pump, &MNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ME, sizeof(ME), &info, pump, &MEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MS, sizeof(MS), &info, pump, &MSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MA, sizeof(MA), &info, pump, &MAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MZ, sizeof(MZ), &info, pump, &MZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MM, sizeof(MM), &info, pump, &MMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NA, sizeof(NA), &info, pump, &NAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NR, sizeof(NR), &info, pump, &NRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GI, sizeof(GI), &info, pump, &GIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GR, sizeof(GR), &info, pump, &GRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GL, sizeof(GL), &info, pump, &GLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GD, sizeof(GD), &info, pump, &GDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GP, sizeof(GP), &info, pump, &GPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GU, sizeof(GU), &info, pump, &GUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GT, sizeof(GT), &info, pump, &GTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GG, sizeof(GG), &info, pump, &GGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GN, sizeof(GN), &info, pump, &GNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GW, sizeof(GW), &info, pump, &GWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GY, sizeof(GY), &info, pump, &GYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HT, sizeof(HT), &info, pump, &HTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HM, sizeof(HM), &info, pump, &HMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VA, sizeof(VA), &info, pump, &VAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HN, sizeof(HN), &info, pump, &HNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HK, sizeof(HK), &info, pump, &HKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, HU, sizeof(HU), &info, pump, &HUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JM, sizeof(JM), &info, pump, &JMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, G1, sizeof(G1), &info, pump, &G1FLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JP, sizeof(JP), &info, pump, &JPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JE, sizeof(JE), &info, pump, &JEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, JO, sizeof(JO), &info, pump, &JOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KZ, sizeof(KZ), &info, pump, &KZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KE, sizeof(KE), &info, pump, &KEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KI, sizeof(KI), &info, pump, &KIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KP, sizeof(KP), &info, pump, &KPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KR, sizeof(KR), &info, pump, &KRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KW, sizeof(KW), &info, pump, &KWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KG, sizeof(KG), &info, pump, &KGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LA, sizeof(LA), &info, pump, &LAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LV, sizeof(LV), &info, pump, &LVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LB, sizeof(LB), &info, pump, &LBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LS, sizeof(LS), &info, pump, &LSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LR, sizeof(LR), &info, pump, &LRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TR, sizeof(TR), &info, pump, &TRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TM, sizeof(TM), &info, pump, &TMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TC, sizeof(TC), &info, pump, &TCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TV, sizeof(TV), &info, pump, &TVFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UG, sizeof(UG), &info, pump, &UGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UA, sizeof(UA), &info, pump, &UAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AE, sizeof(AE), &info, pump, &AEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, US, sizeof(US), &info, pump, &GBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, US, sizeof(US), &info, pump, &USFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UY, sizeof(UY), &info, pump, &UYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, UZ, sizeof(UZ), &info, pump, &UZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VU, sizeof(VU), &info, pump, &VUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VE, sizeof(VE), &info, pump, &VEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VN, sizeof(VN), &info, pump, &VNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VG, sizeof(VG), &info, pump, &VGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VI, sizeof(VI), &info, pump, &VIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, WF, sizeof(WF), &info, pump, &WFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, YE, sizeof(YE), &info, pump, &YEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZM, sizeof(ZM), &info, pump, &ZMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZW, sizeof(ZW), &info, pump, &ZWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, AX, sizeof(AX), &info, pump, &AXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IS, sizeof(IS), &info, pump, &ISFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IN1, sizeof(IN1), &info, pump, &INFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ID, sizeof(ID), &info, pump, &IDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IR, sizeof(IR), &info, pump, &IRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IQ, sizeof(IQ), &info, pump, &IQFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IE, sizeof(IE), &info, pump, &IEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IM, sizeof(IM), &info, pump, &IMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IL, sizeof(IL), &info, pump, &ILFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, IT, sizeof(IT), &info, pump, &ITFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NP, sizeof(NP), &info, pump, &NPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NL, sizeof(NL), &info, pump, &NLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NC, sizeof(NC), &info, pump, &NCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NZ, sizeof(NZ), &info, pump, &NZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NI, sizeof(NI), &info, pump, &NIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NE, sizeof(NE), &info, pump, &NEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NG, sizeof(NG), &info, pump, &NGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NU, sizeof(NU), &info, pump, &NUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NF, sizeof(NF), &info, pump, &NFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MP, sizeof(MP), &info, pump, &MPFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, NO, sizeof(NO), &info, pump, &NOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PK, sizeof(PK), &info, pump, &PKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PW, sizeof(PW), &info, pump, &PWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PS, sizeof(PS), &info, pump, &PSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PA, sizeof(PA), &info, pump, &PAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PG, sizeof(PG), &info, pump, &PGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PY, sizeof(PY), &info, pump, &PYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PE, sizeof(PE), &info, pump, &PEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PH, sizeof(PH), &info, pump, &PHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PN, sizeof(PN), &info, pump, &PNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PL, sizeof(PL), &info, pump, &PLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PT, sizeof(PT), &info, pump, &PTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PR, sizeof(PR), &info, pump, &PRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, QA, sizeof(QA), &info, pump, &QAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MK, sizeof(MK), &info, pump, &MKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RO, sizeof(RO), &info, pump, &ROFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RU, sizeof(RU), &info, pump, &RUFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RW, sizeof(RW), &info, pump, &RWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RE, sizeof(RE), &info, pump, &REFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, BL, sizeof(BL), &info, pump, &BLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SH, sizeof(SH), &info, pump, &SHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, KN, sizeof(KN), &info, pump, &KNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LC, sizeof(LC), &info, pump, &LCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, MF, sizeof(MF), &info, pump, &MFFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, PM, sizeof(PM), &info, pump, &PMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, VC, sizeof(VC), &info, pump, &VCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, WS, sizeof(WS), &info, pump, &WSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SM, sizeof(SM), &info, pump, &SMFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ST, sizeof(ST), &info, pump, &STFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SA, sizeof(SA), &info, pump, &SAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SN, sizeof(SN), &info, pump, &SNFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, RS, sizeof(RS), &info, pump, &RSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SC, sizeof(SC), &info, pump, &SCFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SL, sizeof(SL), &info, pump, &SLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SG, sizeof(SG), &info, pump, &SGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SX, sizeof(SX), &info, pump, &SXFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SK, sizeof(SK), &info, pump, &SKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SI, sizeof(SI), &info, pump, &SIFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SB, sizeof(SB), &info, pump, &SBFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SO, sizeof(SO), &info, pump, &SOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, ZA, sizeof(ZA), &info, pump, &ZAFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, GS, sizeof(GS), &info, pump, &GSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SS, sizeof(SS), &info, pump, &SSFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, LK, sizeof(LK), &info, pump, &LKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SD, sizeof(SD), &info, pump, &SDFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SR, sizeof(SR), &info, pump, &SRFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SJ, sizeof(SJ), &info, pump, &SJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SE, sizeof(SE), &info, pump, &SEFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, CH, sizeof(CH), &info, pump, &CHFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, SY, sizeof(SY), &info, pump, &SYFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TW, sizeof(TW), &info, pump, &TWFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TJ, sizeof(TJ), &info, pump, &TJFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TZ, sizeof(TZ), &info, pump, &TZFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TH, sizeof(TH), &info, pump, &THFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TL, sizeof(TL), &info, pump, &TLFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TG, sizeof(TG), &info, pump, &TGFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TK, sizeof(TK), &info, pump, &TKFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TO, sizeof(TO), &info, pump, &TOFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TT, sizeof(TT), &info, pump, &TTFLAG, 0);
	D3DX11CreateShaderResourceViewFromMemory(DX11::pDevice, TN, sizeof(TN), &info, pump, &TNFLAG, 0);
}
#pragma endregion
ImVec4 to_vec4(float r, float g, float b, float a)
{
	return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

static auto Flags21 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
static auto Flags2 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse;
void DrawRadarHUD(MinimalViewInfo Camera, AActor Player, int Distance, int xAxis, int yAxis, int width, int height, ImVec4 color)
{

	ImGui::SetNextWindowSize(ImVec2(Settings::RadarSize, Settings::RadarSize));
	ImGuiIO& Io = ImGui::GetIO();

	ImGui::PushStyleColor(ImGuiCol_WindowBg, to_vec4(0, 0, 0, 108));
	ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 200));
	ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x - 100, (Io.DisplaySize.y / 2) + 100), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
	if (ImGui::Begin("     ", 0, Flags21))
	{


		{

			ImVec2 wind = ImGui::GetWindowSize();
			ImVec2 wind2 = ImGui::GetWindowPos();



			bool out = false;
			VECTOR3 siz;
			siz.X = wind.x;
			siz.Y = wind.y;
			VECTOR3 pos;
			pos.X = wind2.x;
			pos.Y = wind2.y;
			float RadarCenterX = pos.X + (siz.X / 2);
			float RadarCenterY = pos.Y + (siz.Y / 2);
			//DX11::ImGui_DX11::DrawOutlineBox(pos.X, pos.Y, siz.X, siz.Y, ImVec4(0, 0, 0, 1.f), 1.0f);
			//DX11::ImGui_DX11::DrawBox(pos.X, pos.Y, siz.X, siz.Y, .1, 0, 0, 0, .1, true);


			DX11::ImGui_DX11::DrawLine(RadarCenterX, RadarCenterY, pos.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::ImGui_DX11::DrawLine(RadarCenterX, RadarCenterY, pos.X + siz.X, pos.Y, ImVec4(255, 0, 0, 255), 1.0f);
			DX11::ImGui_DX11::DrawLine(pos.X, RadarCenterY, pos.X + siz.X, RadarCenterY, ImVec4(color), 1.0f);
			DX11::ImGui_DX11::DrawLine(RadarCenterX, RadarCenterY, RadarCenterX, pos.Y + siz.Y, ImVec4(color), 1.0f);
			DX11::ImGui_DX11::DrawCircle(RadarCenterX, RadarCenterY, 2, ImVec4(color), 1.0f);
			VECTOR3 ddddd;
			ddddd.X = siz.X;
			ddddd.Y = siz.Y;
			ddddd.Z = 0;
			//VECTOR3 single = WorldToRadar(Camera.Rotation.Yaw, Player.Position, Data::CameraCache.POV.Location, pos.X, pos.Y, ddddd, out);

			//if (Distance < 350.0f)
			//{
			//	DX11::ImGui_DX11::DrawCircle(single.X, single.Y, 1.5, ImVec4(color), 4.5f);
			//}



		}
		ImGui::End();
	}
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();



}
bool ProcessInlineHexColor(const char* start, const char* end, ImVec4& color)
{
	const int hexCount = (int)(end - start);
	if (hexCount == 6 || hexCount == 8)
	{
		char hex[9];
		strncpy(hex, start, hexCount);
		hex[hexCount] = 0;

		unsigned int hexColor = 0;
		if (sscanf(hex, "%x", &hexColor) > 0)
		{
			color.x = static_cast<float>((hexColor & 0x00FF0000) >> 16) / 255.0f;
			color.y = static_cast<float>((hexColor & 0x0000FF00) >> 8) / 255.0f;
			color.z = static_cast<float>((hexColor & 0x000000FF)) / 255.0f;
			color.w = 1.0f;

			if (hexCount == 8)
			{
				color.w = static_cast<float>((hexColor & 0xFF000000) >> 24) / 255.0f;
			}

			return true;
		}
	}

	return false;
}

const char ColorMarkerStart = '{';
const char ColorMarkerEnd = '}';
void TextWithColors(const char* fmt, ...)
{
	char tempStr[4096];

	va_list argPtr;
	va_start(argPtr, fmt);
	_vsnprintf(tempStr, sizeof(tempStr), fmt, argPtr);
	va_end(argPtr);
	tempStr[sizeof(tempStr) - 1] = '\0';

	bool pushedColorStyle = false;
	const char* textStart = tempStr;
	const char* textCur = tempStr;
	while (textCur < (tempStr + sizeof(tempStr)) && *textCur != '\0')
	{
		if (*textCur == ColorMarkerStart)
		{
			// Print accumulated text
			if (textCur != textStart)
			{
				ImGui::TextUnformatted(textStart, textCur);
				ImGui::SameLine(0.0f, 0.0f);
			}

			// Process color code
			const char* colorStart = textCur + 1;
			do
			{
				++textCur;
			} while (*textCur != '\0' && *textCur != ColorMarkerEnd);

			// Change color
			if (pushedColorStyle)
			{
				ImGui::PopStyleColor();
				pushedColorStyle = false;
			}

			ImVec4 textColor;
			if (ProcessInlineHexColor(colorStart, textCur, textColor))
			{
				ImGui::PushStyleColor(ImGuiCol_Text, textColor);
				pushedColorStyle = true;
			}

			textStart = textCur + 1;
		}
		else if (*textCur == '\n')
		{
			// Print accumulated text an go to next line
			ImGui::TextUnformatted(textStart, textCur);
			textStart = textCur + 1;
		}

		++textCur;
	}

	if (textCur != textStart)
	{
		ImGui::TextUnformatted(textStart, textCur);
	}
	else
	{
		ImGui::NewLine();
	}

	if (pushedColorStyle)
	{
		ImGui::PopStyleColor();
	}
}
bool Save_Settings(std::string Path)
{
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };

	ini.SetDoubleValue("Floats", "fovcircleredus", Settings::fovcircleredus);
	ini.SetDoubleValue("Floats", "AimSpeed", Settings::AimSpeed);
	ini.SetDoubleValue("Floats", "RepidFireValue", Settings::RepidFireValue);


	ini.SetLongValue("Ints", "IpadValue", Settings::IpadValue);
	ini.SetLongValue("Ints", "InstantValue", Settings::InstantValue);
	ini.SetLongValue("Ints", "UpdateTick", Settings::UpdateTick);
	ini.SetLongValue("Ints", "PlayerNameSize", Settings::PlayerNameSize);
	ini.SetLongValue("Ints", "PlayerStateSize", Settings::PlayerStateSize);
	ini.SetLongValue("Ints", "VehicleSize", Settings::VehicleSize);
	ini.SetLongValue("Ints", "RadarSize", Settings::RadarSize);
	ini.SetLongValue("Ints", "DotsSize", Settings::DotsSize);
	ini.SetLongValue("Ints", "PlayerSkeletonMode", Settings::PlayerSkeletonMode);
	ini.SetLongValue("Ints", "PlayerLineMode", Settings::PlayerLineMode);
	ini.SetLongValue("Ints", "MaxAimDistence", Settings::MaxAimDistence);
	ini.SetLongValue("Ints", "AimKey", Settings::AimKey);


	ini.SetBoolValue("Bools", "SkipBots", Settings::SkipBots ? true : false);
	ini.SetBoolValue("Bools", "knocked", Settings::knocked ? true : false);
	ini.SetBoolValue("Bools", "AimBot", Settings::AimBot ? true : false);
	ini.SetBoolValue("Bools", "Legitrack", Settings::Legitrack ? true : false);
	ini.SetBoolValue("Bools", "MagicBullet", Settings::MagicBullet ? true : false);
	ini.SetBoolValue("Bools", "Fovbased", Settings::Fovbased ? true : false);
	ini.SetBoolValue("Bools", "FovShow", Settings::FovShow ? true : false);
	ini.SetBoolValue("Bools", "AntiStream", Settings::AntiStream ? true : false);
	ini.SetBoolValue("Bools", "IpadView", Settings::IpadView ? true : false);
	ini.SetBoolValue("Bools", "NoRecoil", Settings::NoRecoil ? true : false);
	ini.SetBoolValue("Bools", "ForceTpp", Settings::ForceTpp ? true : false);
	ini.SetBoolValue("Bools", "Xeffect", Settings::Xeffect ? true : false);
	ini.SetBoolValue("Bools", "InstantHit", Settings::InstantHit ? true : false);
	ini.SetBoolValue("Bools", "NoSpread", Settings::NoSpread ? true : false);
	ini.SetBoolValue("Bools", "FastSwitch", Settings::FastSwitch ? true : false);
	ini.SetBoolValue("Bools", "RepidFire", Settings::RepidFire ? true : false);
	ini.SetBoolValue("Bools", "YourInfo", Settings::YourInfo ? true : false);
	ini.SetBoolValue("Bools", "GameInfo", Settings::GameInfo ? true : false);
	ini.SetBoolValue("Bools", "PlayerName", Settings::PlayerName ? true : false);
	ini.SetBoolValue("Bools", "PlayerSkeleton", Settings::PlayerSkeleton ? true : false);
	ini.SetBoolValue("Bools", "PlayerLine", Settings::PlayerLine ? true : false);
	ini.SetBoolValue("Bools", "PlayerDistance", Settings::PlayerDistance ? true : false);
	ini.SetBoolValue("Bools", "PlayerHealth", Settings::PlayerHealth ? true : false);
	ini.SetBoolValue("Bools", "PlayerWeapon", Settings::PlayerWeapon ? true : false);
	ini.SetBoolValue("Bools", "PlayerFlag", Settings::PlayerFlag ? true : false);
	ini.SetBoolValue("Bools", "PlayerBox", Settings::PlayerBox ? true : false);
	ini.SetBoolValue("Bools", "PlayerState", Settings::PlayerState ? true : false);
	ini.SetBoolValue("Bools", "Items", Settings::Items ? true : false);
	ini.SetBoolValue("Bools", "TotalEnemy", Settings::TotalEnemy ? true : false);
	ini.SetBoolValue("Bools", "Vehicle", Settings::Vehicle ? true : false);
	ini.SetBoolValue("Bools", "Lootbox", Settings::Lootbox ? true : false);
	ini.SetBoolValue("Bools", "LootboxItems", Settings::LootboxItems ? true : false);
	ini.SetBoolValue("Bools", "AirDrop", Settings::AirDrop ? true : false);
	ini.SetBoolValue("Bools", "AirDropItems", Settings::AirDropItems ? true : false);
	ini.SetBoolValue("Bools", "GrandeWarning", Settings::GrandeWarning ? true : false);
	ini.SetBoolValue("Bools", "AimWarning", Settings::AimWarning ? true : false);
	ini.SetBoolValue("Bools", "Redzone", Settings::Redzone ? true : false);
	ini.SetBoolValue("Bools", "Dots", Settings::Dots ? true : false);
	ini.SetBoolValue("Bools", "Radar", Settings::Radar ? true : false);
	ini.SetBoolValue("Bools", "Akm", Settings::Akm ? true : false);
	ini.SetBoolValue("Bools", "M16A4", Settings::M16A4 ? true : false);
	ini.SetBoolValue("Bools", "SCARL", Settings::SCARL ? true : false);
	ini.SetBoolValue("Bools", "M416", Settings::M416 ? true : false);
	ini.SetBoolValue("Bools", "GROZA", Settings::GROZA ? true : false);
	ini.SetBoolValue("Bools", "AUG", Settings::AUG ? true : false);
	ini.SetBoolValue("Bools", "QBZ", Settings::QBZ ? true : false);
	ini.SetBoolValue("Bools", "M762", Settings::M762 ? true : false);
	ini.SetBoolValue("Bools", "MK47", Settings::MK47 ? true : false);
	ini.SetBoolValue("Bools", "G36C", Settings::G36C ? true : false);
	ini.SetBoolValue("Bools", "HONEY", Settings::HONEY ? true : false);
	ini.SetBoolValue("Bools", "FAMAS", Settings::FAMAS ? true : false);
	ini.SetBoolValue("Bools", "KAR98", Settings::KAR98 ? true : false);
	ini.SetBoolValue("Bools", "M24", Settings::M24 ? true : false);
	ini.SetBoolValue("Bools", "AWM", Settings::AWM ? true : false);
	ini.SetBoolValue("Bools", "WIN94", Settings::WIN94 ? true : false);
	ini.SetBoolValue("Bools", "MOSIN", Settings::MOSIN ? true : false);
	ini.SetBoolValue("Bools", "AMR", Settings::AMR ? true : false);
	ini.SetBoolValue("Bools", "SKS", Settings::SKS ? true : false);
	ini.SetBoolValue("Bools", "VSS", Settings::VSS ? true : false);
	ini.SetBoolValue("Bools", "MINI14", Settings::MINI14 ? true : false);
	ini.SetBoolValue("Bools", "MK14", Settings::MK14 ? true : false);
	ini.SetBoolValue("Bools", "SLR", Settings::SLR ? true : false);
	ini.SetBoolValue("Bools", "QBU", Settings::QBU ? true : false);
	ini.SetBoolValue("Bools", "MK12", Settings::MK12 ? true : false);
	ini.SetBoolValue("Bools", "UZI", Settings::UZI ? true : false);
	ini.SetBoolValue("Bools", "UMP45", Settings::UMP45 ? true : false);
	ini.SetBoolValue("Bools", "VECTOR", Settings::VECTOR ? true : false);
	ini.SetBoolValue("Bools", "THOMPSON", Settings::THOMPSON ? true : false);
	ini.SetBoolValue("Bools", "BIZON", Settings::BIZON ? true : false);
	ini.SetBoolValue("Bools", "MP5K", Settings::MP5K ? true : false);
	ini.SetBoolValue("Bools", "P90", Settings::P90 ? true : false);
	ini.SetBoolValue("Bools", "S686", Settings::S686 ? true : false);
	ini.SetBoolValue("Bools", "S1897", Settings::S1897 ? true : false);
	ini.SetBoolValue("Bools", "S12K", Settings::S12K ? true : false);
	ini.SetBoolValue("Bools", "DBS", Settings::DBS ? true : false);
	ini.SetBoolValue("Bools", "M1014", Settings::M1014 ? true : false);
	ini.SetBoolValue("Bools", "NS2000", Settings::NS2000 ? true : false);
	ini.SetBoolValue("Bools", "M249", Settings::M249 ? true : false);
	ini.SetBoolValue("Bools", "DP28", Settings::DP28 ? true : false);
	ini.SetBoolValue("Bools", "MG3", Settings::MG3 ? true : false);
	ini.SetBoolValue("Bools", "FLARE", Settings::FLARE ? true : false);
	ini.SetBoolValue("Bools", "FRAG", Settings::FRAG ? true : false);
	ini.SetBoolValue("Bools", "SMOKE", Settings::SMOKE ? true : false);
	ini.SetBoolValue("Bools", "MOLOTOF", Settings::MOLOTOF ? true : false);
	ini.SetBoolValue("Bools", "MedKit", Settings::MedKit ? true : false);
	ini.SetBoolValue("Bools", "FirstAidKit", Settings::FirstAidKit ? true : false);
	ini.SetBoolValue("Bools", "Painkiller", Settings::Painkiller ? true : false);
	ini.SetBoolValue("Bools", "EnergyDrink", Settings::EnergyDrink ? true : false);
	ini.SetBoolValue("Bools", "Adrenalin", Settings::Adrenalin ? true : false);
	ini.SetBoolValue("Bools", "Bag1", Settings::Bag1 ? true : false);
	ini.SetBoolValue("Bools", "Bag2", Settings::Bag2 ? true : false);
	ini.SetBoolValue("Bools", "Bag3", Settings::Bag3 ? true : false);
	ini.SetBoolValue("Bools", "Helmet1", Settings::Helmet1 ? true : false);
	ini.SetBoolValue("Bools", "Helmet2", Settings::Helmet2 ? true : false);
	ini.SetBoolValue("Bools", "Helmet3", Settings::Helmet3 ? true : false);
	ini.SetBoolValue("Bools", "Armor1", Settings::Armor1 ? true : false);
	ini.SetBoolValue("Bools", "Armor2", Settings::Armor2 ? true : false);
	ini.SetBoolValue("Bools", "Armor3", Settings::Armor3 ? true : false);
	ini.SetBoolValue("Bools", "a762mm", Settings::a762mm ? true : false);
	ini.SetBoolValue("Bools", "a556mm", Settings::a556mm ? true : false);
	ini.SetBoolValue("Bools", "a9mm", Settings::a9mm ? true : false);
	ini.SetBoolValue("Bools", "a45ACP", Settings::a45ACP ? true : false);
	ini.SetBoolValue("Bools", "a12Gauege", Settings::a12Gauege ? true : false);
	ini.SetBoolValue("Bools", "AwmAmmo", Settings::AwmAmmo ? true : false);
	ini.SetBoolValue("Bools", "AmrAmmo", Settings::AmrAmmo ? true : false);
	ini.SetBoolValue("Bools", "Scope_x2", Settings::Scope_x2 ? true : false);
	ini.SetBoolValue("Bools", "Scope_x3", Settings::Scope_x3 ? true : false);
	ini.SetBoolValue("Bools", "Scope_x4", Settings::Scope_x4 ? true : false);
	ini.SetBoolValue("Bools", "Scope_x6", Settings::Scope_x6 ? true : false);
	ini.SetBoolValue("Bools", "Scope_x8", Settings::Scope_x8 ? true : false);
	ini.SetBoolValue("Bools", "ShopToken", Settings::ShopToken ? true : false);
	if (ini.SaveFile(Path.c_str()) < 0)
	{
		return false;
	}
	return true;
}
void Load_Settings(std::string Path) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) { std::cout << "File not found"; };
	Settings::fovcircleredus = ini.GetDoubleValue("Floats", "fovcircleredus", Settings::fovcircleredus);
	Settings::AimSpeed = ini.GetDoubleValue("Floats", "AimSpeed", Settings::AimSpeed);
	Settings::RepidFireValue = ini.GetDoubleValue("Floats", "RepidFireValue", Settings::RepidFireValue);



	Settings::IpadValue = ini.GetLongValue("Ints", "IpadValue", Settings::IpadValue);
	Settings::InstantValue = ini.GetLongValue("Ints", "InstantValue", Settings::InstantValue);
	Settings::UpdateTick = ini.GetLongValue("Ints", "UpdateTick", Settings::UpdateTick);
	Settings::PlayerNameSize = ini.GetLongValue("Ints", "PlayerNameSize", Settings::PlayerNameSize);
	Settings::PlayerStateSize = ini.GetLongValue("Ints", "PlayerStateSize", Settings::PlayerStateSize);
	Settings::VehicleSize = ini.GetLongValue("Ints", "VehicleSize", Settings::VehicleSize);
	Settings::RadarSize = ini.GetLongValue("Ints", "RadarSize", Settings::RadarSize);
	Settings::DotsSize = ini.GetLongValue("Ints", "DotsSize", Settings::DotsSize);
	Settings::PlayerSkeletonMode = ini.GetLongValue("Ints", "PlayerSkeletonMode", Settings::PlayerSkeletonMode);
	Settings::PlayerLineMode = ini.GetLongValue("Ints", "PlayerLineMode", Settings::PlayerLineMode);
	Settings::MaxAimDistence = ini.GetLongValue("Ints", "MaxAimDistence", Settings::MaxAimDistence);
	Settings::AimKey = ini.GetLongValue("Ints", "AimKey", Settings::AimKey);



	Settings::SkipBots = ini.GetBoolValue("Bools", "SkipBots", Settings::SkipBots ? true : false);
	Settings::knocked = ini.GetBoolValue("Bools", "knocked", Settings::knocked ? true : false);
	Settings::AimBot = ini.GetBoolValue("Bools", "AimBot", Settings::AimBot ? true : false);
	Settings::Legitrack = ini.GetBoolValue("Bools", "Legitrack", Settings::Legitrack ? true : false);
	Settings::MagicBullet = ini.GetBoolValue("Bools", "MagicBullet", Settings::MagicBullet ? true : false);
	Settings::Fovbased = ini.GetBoolValue("Bools", "Fovbased", Settings::Fovbased ? true : false);
	Settings::FovShow = ini.GetBoolValue("Bools", "FovShow", Settings::FovShow ? true : false);
	Settings::AntiStream = ini.GetBoolValue("Bools", "AntiStream", Settings::AntiStream ? true : false);
	Settings::IpadView = ini.GetBoolValue("Bools", "IpadView", Settings::IpadView ? true : false);
	Settings::NoRecoil = ini.GetBoolValue("Bools", "NoRecoil", Settings::NoRecoil ? true : false);
	Settings::ForceTpp = ini.GetBoolValue("Bools", "ForceTpp", Settings::ForceTpp ? true : false);
	Settings::Xeffect = ini.GetBoolValue("Bools", "Xeffect", Settings::Xeffect ? true : false);
	Settings::InstantHit = ini.GetBoolValue("Bools", "InstantHit", Settings::InstantHit ? true : false);
	Settings::NoSpread = ini.GetBoolValue("Bools", "NoSpread", Settings::NoSpread ? true : false);
	Settings::FastSwitch = ini.GetBoolValue("Bools", "FastSwitch", Settings::FastSwitch ? true : false);
	Settings::RepidFire = ini.GetBoolValue("Bools", "RepidFire", Settings::RepidFire ? true : false);
	Settings::YourInfo = ini.GetBoolValue("Bools", "YourInfo", Settings::YourInfo ? true : false);
	Settings::GameInfo = ini.GetBoolValue("Bools", "GameInfo", Settings::GameInfo ? true : false);
	Settings::PlayerName = ini.GetBoolValue("Bools", "PlayerName", Settings::PlayerName ? true : false);
	Settings::PlayerSkeleton = ini.GetBoolValue("Bools", "PlayerSkeleton", Settings::PlayerSkeleton ? true : false);
	Settings::PlayerLine = ini.GetBoolValue("Bools", "PlayerLine", Settings::PlayerLine ? true : false);
	Settings::PlayerDistance = ini.GetBoolValue("Bools", "PlayerDistance", Settings::PlayerDistance ? true : false);
	Settings::PlayerHealth = ini.GetBoolValue("Bools", "PlayerHealth", Settings::PlayerHealth ? true : false);
	Settings::PlayerWeapon = ini.GetBoolValue("Bools", "PlayerWeapon", Settings::PlayerWeapon ? true : false);
	Settings::PlayerFlag = ini.GetBoolValue("Bools", "PlayerFlag", Settings::PlayerFlag ? true : false);
	Settings::PlayerBox = ini.GetBoolValue("Bools", "PlayerBox", Settings::PlayerBox ? true : false);
	Settings::PlayerState = ini.GetBoolValue("Bools", "PlayerState", Settings::PlayerState ? true : false);
	Settings::Items = ini.GetBoolValue("Bools", "Items", Settings::Items ? true : false);
	Settings::TotalEnemy = ini.GetBoolValue("Bools", "TotalEnemy", Settings::TotalEnemy ? true : false);
	Settings::Vehicle = ini.GetBoolValue("Bools", "Vehicle", Settings::Vehicle ? true : false);
	Settings::Lootbox = ini.GetBoolValue("Bools", "Lootbox", Settings::Lootbox ? true : false);
	Settings::LootboxItems = ini.GetBoolValue("Bools", "LootboxItems", Settings::LootboxItems ? true : false);
	Settings::AirDrop = ini.GetBoolValue("Bools", "AirDrop", Settings::AirDrop ? true : false);
	Settings::AirDropItems = ini.GetBoolValue("Bools", "AirDropItems", Settings::AirDropItems ? true : false);
	Settings::GrandeWarning = ini.GetBoolValue("Bools", "GrandeWarning", Settings::GrandeWarning ? true : false);
	Settings::AimWarning = ini.GetBoolValue("Bools", "AimWarning", Settings::AimWarning ? true : false);
	Settings::Redzone = ini.GetBoolValue("Bools", "Redzone", Settings::Redzone ? true : false);
	Settings::Dots = ini.GetBoolValue("Bools", "Dots", Settings::Dots ? true : false);
	Settings::Radar = ini.GetBoolValue("Bools", "Radar", Settings::Radar ? true : false);
	Settings::Akm = ini.GetBoolValue("Bools", "Akm", Settings::Akm ? true : false);
	Settings::M16A4 = ini.GetBoolValue("Bools", "M16A4", Settings::M16A4 ? true : false);
	Settings::SCARL = ini.GetBoolValue("Bools", "SCARL", Settings::SCARL ? true : false);
	Settings::M416 = ini.GetBoolValue("Bools", "M416", Settings::M416 ? true : false);
	Settings::GROZA = ini.GetBoolValue("Bools", "GROZA", Settings::GROZA ? true : false);
	Settings::AUG = ini.GetBoolValue("Bools", "AUG", Settings::AUG ? true : false);
	Settings::QBZ = ini.GetBoolValue("Bools", "QBZ", Settings::QBZ ? true : false);
	Settings::M762 = ini.GetBoolValue("Bools", "M762", Settings::M762 ? true : false);
	Settings::MK47 = ini.GetBoolValue("Bools", "MK47", Settings::MK47 ? true : false);
	Settings::G36C = ini.GetBoolValue("Bools", "G36C", Settings::G36C ? true : false);
	Settings::HONEY = ini.GetBoolValue("Bools", "HONEY", Settings::HONEY ? true : false);
	Settings::FAMAS = ini.GetBoolValue("Bools", "FAMAS", Settings::FAMAS ? true : false);
	Settings::KAR98 = ini.GetBoolValue("Bools", "KAR98", Settings::KAR98 ? true : false);
	Settings::M24 = ini.GetBoolValue("Bools", "M24", Settings::M24 ? true : false);
	Settings::AWM = ini.GetBoolValue("Bools", "AWM", Settings::AWM ? true : false);
	Settings::WIN94 = ini.GetBoolValue("Bools", "WIN94", Settings::WIN94 ? true : false);
	Settings::MOSIN = ini.GetBoolValue("Bools", "MOSIN", Settings::MOSIN ? true : false);
	Settings::AMR = ini.GetBoolValue("Bools", "AMR", Settings::AMR ? true : false);
	Settings::SKS = ini.GetBoolValue("Bools", "SKS", Settings::SKS ? true : false);
	Settings::VSS = ini.GetBoolValue("Bools", "VSS", Settings::VSS ? true : false);
	Settings::MINI14 = ini.GetBoolValue("Bools", "MINI14", Settings::MINI14 ? true : false);
	Settings::MK14 = ini.GetBoolValue("Bools", "MK14", Settings::MK14 ? true : false);
	Settings::SLR = ini.GetBoolValue("Bools", "SLR", Settings::SLR ? true : false);
	Settings::QBU = ini.GetBoolValue("Bools", "QBU", Settings::QBU ? true : false);
	Settings::MK12 = ini.GetBoolValue("Bools", "MK12", Settings::MK12 ? true : false);
	Settings::UZI = ini.GetBoolValue("Bools", "UZI", Settings::UZI ? true : false);
	Settings::UMP45 = ini.GetBoolValue("Bools", "UMP45", Settings::UMP45 ? true : false);
	Settings::VECTOR = ini.GetBoolValue("Bools", "VECTOR", Settings::VECTOR ? true : false);
	Settings::THOMPSON = ini.GetBoolValue("Bools", "THOMPSON", Settings::THOMPSON ? true : false);
	Settings::BIZON = ini.GetBoolValue("Bools", "BIZON", Settings::BIZON ? true : false);
	Settings::MP5K = ini.GetBoolValue("Bools", "MP5K", Settings::MP5K ? true : false);
	Settings::P90 = ini.GetBoolValue("Bools", "P90", Settings::P90 ? true : false);
	Settings::S686 = ini.GetBoolValue("Bools", "S686", Settings::S686 ? true : false);
	Settings::S1897 = ini.GetBoolValue("Bools", "S1897", Settings::S1897 ? true : false);
	Settings::S12K = ini.GetBoolValue("Bools", "S12K", Settings::S12K ? true : false);
	Settings::DBS = ini.GetBoolValue("Bools", "DBS", Settings::DBS ? true : false);
	Settings::M1014 = ini.GetBoolValue("Bools", "M1014", Settings::M1014 ? true : false);
	Settings::NS2000 = ini.GetBoolValue("Bools", "NS2000", Settings::NS2000 ? true : false);
	Settings::M249 = ini.GetBoolValue("Bools", "M249", Settings::M249 ? true : false);
	Settings::DP28 = ini.GetBoolValue("Bools", "DP28", Settings::DP28 ? true : false);
	Settings::MG3 = ini.GetBoolValue("Bools", "MG3", Settings::MG3 ? true : false);
	Settings::FLARE = ini.GetBoolValue("Bools", "FLARE", Settings::FLARE ? true : false);
	Settings::FRAG = ini.GetBoolValue("Bools", "FRAG", Settings::FRAG ? true : false);
	Settings::SMOKE = ini.GetBoolValue("Bools", "SMOKE", Settings::SMOKE ? true : false);
	Settings::MOLOTOF = ini.GetBoolValue("Bools", "MOLOTOF", Settings::MOLOTOF ? true : false);
	Settings::MedKit = ini.GetBoolValue("Bools", "MedKit", Settings::MedKit ? true : false);
	Settings::FirstAidKit = ini.GetBoolValue("Bools", "FirstAidKit", Settings::FirstAidKit ? true : false);
	Settings::Painkiller = ini.GetBoolValue("Bools", "Painkiller", Settings::Painkiller ? true : false);
	Settings::EnergyDrink = ini.GetBoolValue("Bools", "EnergyDrink", Settings::EnergyDrink ? true : false);
	Settings::Adrenalin = ini.GetBoolValue("Bools", "Adrenalin", Settings::Adrenalin ? true : false);
	Settings::Bag1 = ini.GetBoolValue("Bools", "Bag1", Settings::Bag1 ? true : false);
	Settings::Bag2 = ini.GetBoolValue("Bools", "Bag2", Settings::Bag2 ? true : false);
	Settings::Bag3 = ini.GetBoolValue("Bools", "Bag3", Settings::Bag3 ? true : false);
	Settings::Helmet1 = ini.GetBoolValue("Bools", "Helmet1", Settings::Helmet1 ? true : false);
	Settings::Helmet2 = ini.GetBoolValue("Bools", "Helmet2", Settings::Helmet2 ? true : false);
	Settings::Helmet3 = ini.GetBoolValue("Bools", "Helmet3", Settings::Helmet3 ? true : false);
	Settings::Armor1 = ini.GetBoolValue("Bools", "Armor1", Settings::Armor1 ? true : false);
	Settings::Armor2 = ini.GetBoolValue("Bools", "Armor2", Settings::Armor2 ? true : false);
	Settings::Armor3 = ini.GetBoolValue("Bools", "Armor3", Settings::Armor3 ? true : false);
	Settings::a762mm = ini.GetBoolValue("Bools", "a762mm", Settings::a762mm ? true : false);
	Settings::a556mm = ini.GetBoolValue("Bools", "a556mm", Settings::a556mm ? true : false);
	Settings::a9mm = ini.GetBoolValue("Bools", "a9mm", Settings::a9mm ? true : false);
	Settings::a45ACP = ini.GetBoolValue("Bools", "a45ACP", Settings::a45ACP ? true : false);
	Settings::a12Gauege = ini.GetBoolValue("Bools", "a12Gauege", Settings::a12Gauege ? true : false);
	Settings::AwmAmmo = ini.GetBoolValue("Bools", "AwmAmmo", Settings::AwmAmmo ? true : false);
	Settings::AmrAmmo = ini.GetBoolValue("Bools", "AmrAmmo", Settings::AmrAmmo ? true : false);
	Settings::Scope_x2 = ini.GetBoolValue("Bools", "Scope_x2", Settings::Scope_x2 ? true : false);
	Settings::Scope_x3 = ini.GetBoolValue("Bools", "Scope_x3", Settings::Scope_x3 ? true : false);
	Settings::Scope_x4 = ini.GetBoolValue("Bools", "Scope_x4", Settings::Scope_x4 ? true : false);
	Settings::Scope_x6 = ini.GetBoolValue("Bools", "Scope_x6", Settings::Scope_x6 ? true : false);
	Settings::Scope_x8 = ini.GetBoolValue("Bools", "Scope_x8", Settings::Scope_x8 ? true : false);
	Settings::ShopToken = ini.GetBoolValue("Bools", "ShopToken", Settings::ShopToken ? true : false);


}
VOID DrawManu() {
	ImGui::GetStyle().ItemSpacing = ImVec2(12, 12);

	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 200);
	{
		ImGui::Image((PVOID)Logo, ImVec2(180, 180));

		static ImVec4 active = to_vec4(57, 54, 68, 250);
		static ImVec4 inactive = to_vec4(25, 24, 30, 250);

		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
		if (ImGui::Button(ICON_FA_EYE" ESP", ImVec2(180 - 15, 50)))
			Settings::Tab = 1;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
		if (ImGui::Button(ICON_FA_CROSSHAIRS" AIM", ImVec2(180 - 15, 50)))
			if (Settings::Mode != 0)
				Settings::Tab = 2;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
		if (ImGui::Button(ICON_FA_BAN" Memory", ImVec2(180 - 15, 50)))
			if (Settings::Mode != 0)
				Settings::Tab = 3;


		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
		if (ImGui::Button(ICON_FA_COG" SETTINGS", ImVec2(180 - 15, 50)))
			Settings::Tab = 4;




		ImGui::PopStyleColor(4);

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);

	}

	ImGui::NextColumn();
	{
		if (Settings::Tab == 1) {
			ImGui::Checkbox("Player Name", &Settings::PlayerName);
			ImGui::Checkbox("Player Skeleton", &Settings::PlayerSkeleton);
			ImGui::Checkbox("Player Line", &Settings::PlayerLine);
			ImGui::Checkbox("Player Distance", &Settings::PlayerDistance);
			ImGui::Checkbox("Player Health", &Settings::PlayerHealth);
			ImGui::Checkbox("Player Weapon", &Settings::PlayerWeapon);
			ImGui::Checkbox("Player Flag", &Settings::PlayerFlag);
			ImGui::Checkbox("Player Box", &Settings::PlayerBox);
			ImGui::Checkbox("Player State", &Settings::PlayerState);
			ImGui::Checkbox("Items", &Settings::Items);
			ImGui::Checkbox("Total Enemy", &Settings::TotalEnemy);
			ImGui::Checkbox("Vehicle", &Settings::Vehicle);
			ImGui::Checkbox("Lootbox", &Settings::Lootbox);
			ImGui::Checkbox("AirDrop", &Settings::AirDrop);
			ImGui::Checkbox("Grande Warning", &Settings::GrandeWarning);
			ImGui::Checkbox("Aim Warning", &Settings::AimWarning);
			ImGui::Checkbox("Redzone Warning", &Settings::Redzone);
			ImGui::Checkbox("Dots", &Settings::Dots);
			ImGui::Checkbox("Radar", &Settings::Radar);
			ImGui::Checkbox("Your Info", &Settings::YourInfo);
			ImGui::Checkbox("Game Info", &Settings::GameInfo);
			if (Settings::PlayerName) {
				if (ImGui::TreeNode("Player Name")) {
					ImGui::Text("Name Color :");
					ImGui::SameLine();
					ImGui::ColorEdit4(" Name color", (float*)&Settings::PlayerNameColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Text("Name Size :");
					ImGui::SameLine();
					ImGui::SliderInt("###pname", &Settings::PlayerNameSize, 1, 20);

					ImGui::TreePop();
				}
			}
			if (Settings::PlayerSkeleton) {
				if (ImGui::TreeNode("Player Skeleton")) {
					ImGui::Text(" Color Mode : ");

					ImGui::SameLine();
					ImGui::Combo(" ", &Settings::PlayerSkeletonMode, "Team Id\0Custom Color");
					if (Settings::PlayerSkeletonMode == 1) {
						ImGui::Text("Skeleton Color :");
						ImGui::SameLine();
						ImGui::ColorEdit4(" Skeleton color", (float*)&Settings::PlayerSkeletonColor, ImGuiColorEditFlags_NoLabel);
					}
					ImGui::TreePop();
				}
			}
			if (Settings::PlayerLine) {
				if (ImGui::TreeNode("Player Line")) {
					ImGui::Text(" Color Mode : ");

					ImGui::SameLine();
					ImGui::Combo(" ", &Settings::PlayerLineMode, "Team Id\0Custom Color");
					if (Settings::PlayerLineMode == 1) {
						ImGui::Text("Line Color :");
						ImGui::SameLine();
						ImGui::ColorEdit4(" Line color", (float*)&Settings::PlayerLineColor, ImGuiColorEditFlags_NoLabel);
					}
					ImGui::TreePop();
				}
			}


			if (Settings::PlayerBox) {
				if (ImGui::TreeNode("Player Box")) {
					ImGui::Text("Box Color :");
					ImGui::SameLine();
					ImGui::ColorEdit4(" Box color", (float*)&Settings::PlayerBoxColor, ImGuiColorEditFlags_NoLabel);
					ImGui::TreePop();
				}
			}
			if (Settings::PlayerState) {
				if (ImGui::TreeNode("Player State")) {
					ImGui::Text("State Color :");
					ImGui::SameLine();
					ImGui::ColorEdit4(" state color", (float*)&Settings::PlayerStateColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Text("State Size :");
					ImGui::SameLine();
					ImGui::SliderInt("###State", &Settings::PlayerStateSize, 1, 20);
					ImGui::TreePop();
				}
			}
			if (Settings::Items) {
				if (ImGui::TreeNode("Items")) {
					ImGui::Text("Items: ");
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("Akm", &Settings::Akm);
					ImGui::SameLine();
					ImGui::ColorEdit4("Akm", (float*)&Settings::AkmColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("M16A4", &Settings::M16A4);
					ImGui::SameLine();
					ImGui::ColorEdit4("M16A4", (float*)&Settings::M16A4Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("SCARL", &Settings::SCARL);
					ImGui::SameLine();
					ImGui::ColorEdit4("SCARL", (float*)&Settings::SCARLColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("M416", &Settings::M416);
					ImGui::SameLine();
					ImGui::ColorEdit4("M416", (float*)&Settings::M416Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("GROZA", &Settings::GROZA);
					ImGui::SameLine();
					ImGui::ColorEdit4("GROZA", (float*)&Settings::GROZAColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("AUG", &Settings::AUG);
					ImGui::SameLine();
					ImGui::ColorEdit4("AUG", (float*)&Settings::AUGColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("QBZ", &Settings::QBZ);
					ImGui::SameLine();
					ImGui::ColorEdit4("QBZ", (float*)&Settings::QBZColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("M762", &Settings::M762);
					ImGui::SameLine();
					ImGui::ColorEdit4("M762", (float*)&Settings::M762Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MK47", &Settings::MK47);
					ImGui::SameLine();
					ImGui::ColorEdit4("MK47", (float*)&Settings::MK47Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("G36C", &Settings::G36C);
					ImGui::SameLine();
					ImGui::ColorEdit4("G36C", (float*)&Settings::G36CColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("HONEY", &Settings::HONEY);
					ImGui::SameLine();
					ImGui::ColorEdit4("HONEY", (float*)&Settings::HONEYColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("FAMAS", &Settings::FAMAS);
					ImGui::SameLine();
					ImGui::ColorEdit4("FAMAS", (float*)&Settings::FAMASColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("KAR98", &Settings::KAR98);
					ImGui::SameLine();
					ImGui::ColorEdit4("KAR98", (float*)&Settings::KAR98Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("M24", &Settings::M24);
					ImGui::SameLine();
					ImGui::ColorEdit4("M24", (float*)&Settings::M24Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("AWM", &Settings::AWM);
					ImGui::SameLine();
					ImGui::ColorEdit4("AWM", (float*)&Settings::AWMColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("WIN94", &Settings::WIN94);
					ImGui::SameLine();
					ImGui::ColorEdit4("WIN94", (float*)&Settings::WIN94Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MOSIN", &Settings::MOSIN);
					ImGui::SameLine();
					ImGui::ColorEdit4("MOSIN", (float*)&Settings::MOSINColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("AMR", &Settings::AMR);
					ImGui::SameLine();
					ImGui::ColorEdit4("AMR", (float*)&Settings::AMRColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("SKS", &Settings::SKS);
					ImGui::SameLine();
					ImGui::ColorEdit4("SKS", (float*)&Settings::SKSColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("VSS", &Settings::VSS);
					ImGui::SameLine();
					ImGui::ColorEdit4("VSS", (float*)&Settings::VSSColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MINI14", &Settings::MINI14);
					ImGui::SameLine();
					ImGui::ColorEdit4("MINI14", (float*)&Settings::MINI14Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MK14", &Settings::MK14);
					ImGui::SameLine();
					ImGui::ColorEdit4("MK14", (float*)&Settings::MK14Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("SLR ", &Settings::SLR);
					ImGui::SameLine();
					ImGui::ColorEdit4("SLR ", (float*)&Settings::SLRColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("QBU", &Settings::QBU);
					ImGui::SameLine();
					ImGui::ColorEdit4("QBU", (float*)&Settings::QBUColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MK12", &Settings::MK12);
					ImGui::SameLine();
					ImGui::ColorEdit4("MK12", (float*)&Settings::MK12Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("UZI", &Settings::UZI);
					ImGui::SameLine();
					ImGui::ColorEdit4("UZI", (float*)&Settings::UZIColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("UMP45", &Settings::UMP45);
					ImGui::SameLine();
					ImGui::ColorEdit4("UMP45", (float*)&Settings::UMP45Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("VECTOR", &Settings::VECTOR);
					ImGui::SameLine();
					ImGui::ColorEdit4("VECTOR", (float*)&Settings::VECTORColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("THOMPSON", &Settings::THOMPSON);
					ImGui::SameLine();
					ImGui::ColorEdit4("THOMPSON", (float*)&Settings::THOMPSONColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("BIZON", &Settings::BIZON);
					ImGui::SameLine();
					ImGui::ColorEdit4("BIZON", (float*)&Settings::BIZONColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MP5K", &Settings::MP5K);
					ImGui::SameLine();
					ImGui::ColorEdit4("MP5K", (float*)&Settings::MP5KColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("P90", &Settings::P90);
					ImGui::SameLine();
					ImGui::ColorEdit4("P90", (float*)&Settings::P90Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("S686", &Settings::S686);
					ImGui::SameLine();
					ImGui::ColorEdit4("S686", (float*)&Settings::S686Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("S1897", &Settings::S1897);
					ImGui::SameLine();
					ImGui::ColorEdit4("S1897", (float*)&Settings::S1897Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("S12K", &Settings::S12K);
					ImGui::SameLine();
					ImGui::ColorEdit4("S12K", (float*)&Settings::S12KColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("DBS ", &Settings::DBS);
					ImGui::SameLine();
					ImGui::ColorEdit4("DBS ", (float*)&Settings::DBSColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("M1014", &Settings::M1014);
					ImGui::SameLine();
					ImGui::ColorEdit4("M1014", (float*)&Settings::M1014Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("NS2000", &Settings::NS2000);
					ImGui::SameLine();
					ImGui::ColorEdit4("NS2000", (float*)&Settings::NS2000Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("M249", &Settings::M249);
					ImGui::SameLine();
					ImGui::ColorEdit4("M249", (float*)&Settings::M249Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("DP28", &Settings::DP28);
					ImGui::SameLine();
					ImGui::ColorEdit4("DP28", (float*)&Settings::DP28Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MG3", &Settings::MG3);
					ImGui::SameLine();
					ImGui::ColorEdit4("MG3", (float*)&Settings::MG3Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("FLARE", &Settings::FLARE);
					ImGui::SameLine();
					ImGui::ColorEdit4("FLARE", (float*)&Settings::FLAREColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("FRAG", &Settings::FRAG);
					ImGui::SameLine();
					ImGui::ColorEdit4("FRAG", (float*)&Settings::FRAGColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("SMOKE", &Settings::SMOKE);
					ImGui::SameLine();
					ImGui::ColorEdit4("SMOKE", (float*)&Settings::SMOKEColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("MOLOTOF", &Settings::MOLOTOF);
					ImGui::SameLine();
					ImGui::ColorEdit4("MOLOTOF", (float*)&Settings::MOLOTOFColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("MedKit", &Settings::MedKit);
					ImGui::SameLine();
					ImGui::ColorEdit4("MedKit", (float*)&Settings::MedKitColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("FirstAidKit", &Settings::FirstAidKit);
					ImGui::SameLine();
					ImGui::ColorEdit4("FirstAidKit", (float*)&Settings::FirstAidKitColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Painkiller", &Settings::Painkiller);
					ImGui::SameLine();
					ImGui::ColorEdit4("Painkiller", (float*)&Settings::PainkillerColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("EnergyDrink", &Settings::EnergyDrink);
					ImGui::SameLine();
					ImGui::ColorEdit4("EnergyDrink", (float*)&Settings::EnergyDrinkColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Adrenalin", &Settings::Adrenalin);
					ImGui::SameLine();
					ImGui::ColorEdit4("Adrenalin", (float*)&Settings::AdrenalinColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("Bag1", &Settings::Bag1);
					ImGui::SameLine();
					ImGui::ColorEdit4("Bag1", (float*)&Settings::Bag1Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Bag2", &Settings::Bag2);
					ImGui::SameLine();
					ImGui::ColorEdit4("Bag2", (float*)&Settings::Bag2Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Bag3", &Settings::Bag3);
					ImGui::SameLine();
					ImGui::ColorEdit4("Bag3", (float*)&Settings::Bag3Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Checkbox("Helmet1", &Settings::Helmet1);
					ImGui::SameLine();
					ImGui::ColorEdit4("Helmet1", (float*)&Settings::Helmet1Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Helmet2", &Settings::Helmet2);
					ImGui::SameLine();
					ImGui::ColorEdit4("Helmet2", (float*)&Settings::Helmet2Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Helmet3", &Settings::Helmet3);
					ImGui::SameLine();
					ImGui::ColorEdit4("Helmet3", (float*)&Settings::Helmet3Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Checkbox("Armor1", &Settings::Armor1);
					ImGui::SameLine();
					ImGui::ColorEdit4("Armor1", (float*)&Settings::Armor1Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Armor2", &Settings::Armor2);
					ImGui::SameLine();
					ImGui::ColorEdit4("Armor2", (float*)&Settings::Armor2Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Armor3", &Settings::Armor3);
					ImGui::SameLine();
					ImGui::ColorEdit4("Armor3", (float*)&Settings::Armor3Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("7.62mm", &Settings::a762mm);
					ImGui::SameLine();
					ImGui::ColorEdit4("762mm", (float*)&Settings::a762mmColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("5.56mm", &Settings::a556mm);
					ImGui::SameLine();
					ImGui::ColorEdit4("556mm", (float*)&Settings::a556mmColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("9mm", &Settings::a9mm);
					ImGui::SameLine();
					ImGui::ColorEdit4("9mm", (float*)&Settings::a9mmColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("45ACP", &Settings::a45ACP);
					ImGui::SameLine();
					ImGui::ColorEdit4("45ACP", (float*)&Settings::a45ACPColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("12Gauege", &Settings::a12Gauege);
					ImGui::SameLine();
					ImGui::ColorEdit4("12Gauege", (float*)&Settings::a12GauegeColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("AwmAmmo", &Settings::AwmAmmo);
					ImGui::SameLine();
					ImGui::ColorEdit4("AwmAmmo", (float*)&Settings::AwmAmmoColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("AmrAmmo", &Settings::AmrAmmo);
					ImGui::SameLine();
					ImGui::ColorEdit4("AmrAmmo", (float*)&Settings::AmrAmmoColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("Scope_x2", &Settings::Scope_x2);
					ImGui::SameLine();
					ImGui::ColorEdit4("Scope_x2", (float*)&Settings::Scope_x2Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Scope_x3", &Settings::Scope_x3);
					ImGui::SameLine();
					ImGui::ColorEdit4("Scope_x3", (float*)&Settings::Scope_x3Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Scope_x4", &Settings::Scope_x4);
					ImGui::SameLine();
					ImGui::ColorEdit4("Scope_x4", (float*)&Settings::Scope_x4Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Scope_x6", &Settings::Scope_x6);
					ImGui::SameLine();
					ImGui::ColorEdit4("Scope_x6", (float*)&Settings::Scope_x6Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Checkbox("Scope_x8", &Settings::Scope_x8);
					ImGui::SameLine();
					ImGui::ColorEdit4("Scope_x8", (float*)&Settings::Scope_x8Color, ImGuiColorEditFlags_NoLabel);
					ImGui::Spacing();
					ImGui::Spacing();
					ImGui::Checkbox("ShopToken", &Settings::ShopToken);
					ImGui::SameLine();
					ImGui::ColorEdit4("ShopToken", (float*)&Settings::ShopTokenColor, ImGuiColorEditFlags_NoLabel);
					ImGui::TreePop();
				}
			}
			if (Settings::Vehicle) {
				if (ImGui::TreeNode("Vehicle")) {
					ImGui::Text("Vehicle Color :");
					ImGui::SameLine();
					ImGui::ColorEdit4(" Vehicle color", (float*)&Settings::VehicleColor, ImGuiColorEditFlags_NoLabel);
					ImGui::Text("Vehicle Size :");
					ImGui::SameLine();
					ImGui::SliderInt("###Vehicle", &Settings::VehicleSize, 1, 20);
					ImGui::TreePop();
				}
			}
			if (Settings::Lootbox) {
				if (ImGui::TreeNode("Lootbox")) {
					ImGui::Checkbox("Lootbox Items", &Settings::LootboxItems);
					ImGui::TreePop();
				}
			}
			if (Settings::AirDrop) {
				if (ImGui::TreeNode("AirDrop")) {
					ImGui::Checkbox("AirDrop Items", &Settings::AirDropItems);
					ImGui::TreePop();
				}
			}
			if (Settings::Dots) {
				if (ImGui::TreeNode("Dots")) {
					ImGui::Text("Rander Size: ");
					ImGui::SameLine();
					ImGui::SliderInt("###21452", &Settings::DotsSize, 5, 100);
					ImGui::TreePop();
				}
			}
			if (Settings::Radar) {
				if (ImGui::TreeNode("Radar")) {
					ImGui::Text("Radar Size: ");
					ImGui::SameLine();
					ImGui::SliderInt("###21452dsfs", &Settings::RadarSize, 5, 300);
					ImGui::TreePop();
				}
			}
		}
		if (Settings::Tab == 2) {
			ImGui::Checkbox(" Aim Bot", &Settings::AimBot);
			ImGui::Text("Aim Positon :");
			ImGui::SameLine();
			ImGui::Combo(" ", &Settings::curraim, "Head\0Cheast\0Pelvis");

			ImGui::Text("Aimbot Key :");
			ImGui::SameLine();
			ImGui::Hotkey("##AimbotKey ", &Settings::AimKey, ImVec2(180.0f, 24));
			ImGui::Text("Aim Speed :");
			ImGui::SameLine();
			ImGui::SliderFloat("###aimspped", &Settings::AimSpeed, 0.0f, 30.0f);
			ImGui::Checkbox(" Bullet Track", &Settings::MagicBullet);
			ImGui::Checkbox(" Legit Track", &Settings::Legitrack);
			ImGui::Checkbox(" AIM Knocked", &Settings::knocked);
			ImGui::Checkbox(" SKIP Bots ", &Settings::SkipBots);
			ImGui::Checkbox(" Fov Based Tracking ", &Settings::Fovbased);
			if (Settings::Fovbased)
			{
				ImGui::Checkbox(" Show Fov ", &Settings::FovShow);

				if (Settings::FovShow)
				{
					ImGui::Text("Fov Size :");
					ImGui::SameLine();
					ImGui::SliderFloat("###fovFOVsize", &Settings::fovcircleredus, 1.0f, 2000.0f);
					ImGui::Text("Fov Color :");
					ImGui::SameLine();
					ImGui::ColorEdit4(" Fov color", (float*)&Settings::FovColor, ImGuiColorEditFlags_NoLabel);

				}
			}
			else {
				Settings::FovShow = false;
			}
			ImGui::Text("Max Aim Distence");
			ImGui::SameLine();
			ImGui::SliderInt("###MaxAimDistence", &Settings::MaxAimDistence, 1.0f, 400.0f);

		}
		if (Settings::Tab == 3) {
			ImGui::Checkbox("Anti Stream", &Settings::AntiStream);
			ImGui::Checkbox("Ipad View", &Settings::IpadView);
			if (ImGui::TreeNode("Ipad")) {
				ImGui::Text("Ipad Value :");
				ImGui::SameLine();
				ImGui::SliderInt("###ipadddd", &Settings::IpadValue, 100, 4000);
				ImGui::TreePop();
			}
			if (Settings::Mode == 2) {
				ImGui::Checkbox("Magic 360", &Settings::Magic360);
				ImGui::Checkbox("No Recoil", &Settings::NoRecoil);
				ImGui::Checkbox("Force Tpp", &Settings::ForceTpp);
				ImGui::Checkbox("Xeffect", &Settings::Xeffect);
				ImGui::Checkbox("Instant Hit", &Settings::InstantHit);
				if (ImGui::TreeNode("Instant Hit")) {
					ImGui::Text("Instant Hit :");
					ImGui::SameLine();
					ImGui::SliderInt("###Instant Hit", &Settings::InstantValue, 0, 10000);
					ImGui::TreePop();
				}
				ImGui::Checkbox("No Spread", &Settings::NoSpread);
				ImGui::Checkbox("Fast Switch", &Settings::FastSwitch);
				ImGui::Checkbox("Repid Fire", &Settings::RepidFire);
				if (ImGui::TreeNode("Repid Fire")) {
					ImGui::Text("Repid Fire Value :");
					ImGui::SameLine();
					ImGui::SliderFloat("###Firevalue", &Settings::RepidFireValue, 0.0f, 30.0f);
					ImGui::TreePop();
				}
				//ImGui::Checkbox("Mod Skin", &Settings::ModSKin);
				//if (ImGui::TreeNode("Mod Skin")) {

				//	ImGui::Text(" Suit : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModSuit", &ModSkin::Suit, "Stygian Liege Xsuit\0Arcane Jester Xsuit\0Iridescence Xsuit\0Silvanus Xsuit\0Avalanche Xsuit\0Poseidon Xsuit\0Blood Raven Xsuit\0Golden Pharaoh Xsuit\0Yellow Mummy\0White Mummy\0Custom...");

				//	//--------------------------
				//	ImGui::Text(" Helmet : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModHelmet", &ModSkin::Helmet, "\0Custom...");

				//	//--------------------------
				//	ImGui::Text(" BackBack : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModBackBack", &ModSkin::BackBack, "\0Custom...");


				//	//--------------------------
				//	ImGui::Text(" Weapons  : ");
				//	ImGui::Text(" Akm : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModAkm", &ModSkin::Akm, "The Seven Seas \0Glacier \0Desert Fossil \0Jack-o' lantern\0Ghillie Dragon \0Sculpture\0Custom... ");


				//	//--------------------------
				//	ImGui::Text(" M16a4  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModM16a4 ", &ModSkin::M16a4, "Blood & Bones\0Aurora Pulse \0Custom... ");


				//	//--------------------------	
				//	ImGui::Text(" Scar  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModScar ", &ModSkin::Scar, "Water Blaster \0Enchanted Pumpkin \0Operation Tomorrow \0Drop the Bass  \0Custom... ");


				//	//--------------------------	
				//	ImGui::Text(" M416   : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModM416  ", &ModSkin::M416, "Glacier \0The Fool\0Wanderer\0Lizard Roar\0Call of the Wild\0Custom... ");


				//	//--------------------------	
				//	ImGui::Text(" M762   : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModM762  ", &ModSkin::M762, "Royal Butterfly \0Messi Football \0Starcore\0Stray Rebellion\0Deadly Precision\0Custom... ");


				//	//--------------------------	
				//	ImGui::Text(" Ump  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModUmp  ", &ModSkin::Ump, "Dragonfire\0Outlawed Fantasy\0Custom... ");


				//	//--------------------------
				//	ImGui::Text(" Kar98  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModKar98  ", &ModSkin::Kar98, "Terror Fang \0Kukulkan Fury\0Moonlit Grace\0Custom... ");


				//	//--------------------------	
				//	ImGui::Text(" M24  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModM24  ", &ModSkin::M24, "Pharaoh's Might\0Custom... ");


				//	//--------------------------
				//	ImGui::Text(" AWM  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModAWM  ", &ModSkin::AWM, "Mauve Avenger \0Field Commander\0Godzilla\0Custom... ");


				//	//--------------------------
				//	ImGui::Text(" SKS  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModSKS  ", &ModSkin::SKS, "Lady Carmine\0Custom... ");

				//	//--------------------------
				//	ImGui::Text(" Mini14  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModMini14  ", &ModSkin::Mini14, "Icicle \0Custom... ");

				//	//--------------------------	
				//	ImGui::Text(" S12k  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModS12k  ", &ModSkin::S12k, "GACKT Lv. 7 \0Custom... ");

				//	//--------------------------
				//	ImGui::Text(" M249  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModM249  ", &ModSkin::M249, "Winter Queen \0Custom... ");

				//	//--------------------------	
				//	ImGui::Text(" Pan  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModPan  ", &ModSkin::Pan, "Sobbing Sensation\0Shockingly Delicious\0Tasty Cheese\0Custom... ");

				//	//--------------------------
				//	ImGui::Text(" UZI  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModUZI  ", &ModSkin::UZI, "Romantic Moments\0Custom... ");

				//	//--------------------------
				//	ImGui::Text(" Vector  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModVector  ", &ModSkin::Vector, "Midnight Rose\0Custom... ");

				//	//--------------------------
				//	ImGui::Text(" DP28  : ");
				//	ImGui::SameLine();
				//	ImGui::SetNextItemWidth(250);
				//	ImGui::Combo("ModDP28  ", &ModSkin::DP28, "Enigmatic Killer\0Custom... ");

				//	//--------------------------
				//	if (ImGui::Button("Apply"))
				//		Memory::DoModSkin();
				//	ImGui::TreePop();
				//}

			}
		}
		if (Settings::Tab == 4) {
			ImGui::Text("Second Menu Mode :");
			ImGui::SameLine();
			ImGui::Combo("    ", &Settings::SecondMenuMode, "On Right\0On Top");
			ImGui::Text("Update Tick :");
			ImGui::SameLine();
			ImGui::SliderInt("###Update", &Settings::UpdateTick, 0, 100);
			ImGui::Text("Low Update Tick = High Cpu = Better Hack");

			if (ImGui::Button("Save Setting", { 185.f,25.f }))
			{
				Save_Settings("C:\\DARKNESS_HACK_Config.ini");
			}
			ImGui::SameLine();
			if (ImGui::Button("Load Setting", { 185.f,25.f }))
			{
				Load_Settings("C:\\DARKNESS_HACK_Config.ini");
			}


			//ImGui::Text("\n Key Expires Date  :  %s", tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.expiry))));
		}
	}

}
VOID DrawMenu2()
{

	if (Settings::SecondMenuMode == 0) {
		ImGui::SetNextWindowPos({ 10, (DX11Window::Height / 2.0f) - 80 });

		ImGuiIO& Io = ImGui::GetIO();
		ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));


		ImGui::SetNextWindowSize(ImVec2(141.0f, 275.0f));

		ImGui::GetStyle().ItemSpacing = ImVec2(8, 4);
		static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;

		ImGui::Begin("DARKNESS", 0, FlagsMenu);
		{
			const float colPos = 220.0f;
			bool P = false;
			ImGui::Text;
			//0FFFFF/ ازرق
			//0FFF0F/ ازرق

			ImGui::Image((PVOID)Logo, ImVec2(125, 130));
			ImGui::Spacing();
			Settings::FightMode ? TextWithColors("{74ff03}F4   {74ff03}FIGHT MODE{74ff03}") : TextWithColors("{FF0000}F4   {FF0000}FIGHT MODE{FF0000}");  //FFFFFF
			ImGui::Spacing();
			Settings::MagicBullet ? TextWithColors("{74ff03}F5   {74ff03}BULLET TRACK{74ff03}") : TextWithColors("{FF0000}F5   {FF0000}BULLET TRACK{FF0000}");  //FFFFFF
			ImGui::Spacing();
			Settings::Legitrack ? TextWithColors("{74ff03}F6   {74ff03}LEGIT TRACK{74ff03}") : TextWithColors("{FF0000}F6   {FF0000}LEGIT TRACK{FF0000}");  //FFFFFF
			ImGui::Spacing();
			Settings::Items ? TextWithColors("{74ff03}F7   {74ff03}ITEMS ESP{74ff03}") : TextWithColors("{FF0000}F7   {FF0000}ITEMS ESP{FF0000}");  //FFFFFF
			ImGui::Spacing();
			Settings::Vehicle ? TextWithColors("{74ff03}F8   {74ff03}VEHICLE ESP{74ff03}") : TextWithColors("{FF0000}F8   {FF0000}VEHICLE ESP{FF0000}");  //FFFFFF
			if (Settings::Legitrack) {
				TextWithColors(("{FF0000}Aim : Legit "));
			}
			else {
				if (Settings::curraim == 0)
				{
					TextWithColors(("{FF0000}Aim : Head "));
				}
				else if (Settings::curraim == 1)
				{
					TextWithColors(("{74ff03}Aim : Chest "));
				}
				else if (Settings::curraim == 2)
				{
					TextWithColors(("{74ff03}Aim : Pelvis "));
				}
			}


			ImGui::SetCursorPos({ 20.f,200.0f });

			ImGui::End();
		}
	}
	else {

		ImGuiIO& Io = ImGui::GetIO();
		ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 255, 0, 255));
		ImGui::SetNextWindowSize(ImVec2(600, 75));

		ImGui::GetStyle().ItemSpacing = ImVec2(8, 4);
		static auto FlagsMenu = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
		ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.01f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));

		ImGui::Begin("Vampy", 0, FlagsMenu);
		{
			const float colPos = 220.0f;
			bool P = false;
			//ImGui::Text;
			//0FFFFF/ ازرق
			//0FFF0F/ ازرق

			//ImGui::Image((PVOID)Logo, ImVec2(125, 130));
			//ImGui::Spacing();
			//
			TextWithColors("{07e3ea}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  DARKNESS{07e3ea}");
			ImGui::Spacing();

			Settings::FightMode ? TextWithColors("{74ff03}\t     F4{74ff03}     ") : TextWithColors("{FF0000}\t     F4     ");  //FFFFFF
			ImGui::SameLine();
			Settings::MagicBullet ? TextWithColors("{74ff03}\t                F5      ") : TextWithColors("{FF0000}\t                F5      ");  //FFFFFF
			ImGui::SameLine();
			Settings::Legitrack ? TextWithColors("{74ff03}\t               F6     ") : TextWithColors("{FF0000}\t                F6     ");  //FFFFFF
			ImGui::SameLine();
			Settings::Items ? TextWithColors("{74ff03}\t               F7    ") : TextWithColors("{FF0000}\t               F7    ");  //FFFFFF
			ImGui::SameLine();
			Settings::Vehicle ? TextWithColors("{74ff03}\t                F8") : TextWithColors("{FF0000}\t                F8");  //FFFFFF	
			ImGui::SameLine();
			Settings::Vehicle ? TextWithColors("{74ff03}\t                T") : TextWithColors("{FF0000}\t                T");  //FFFFFF
			ImGui::Spacing();

			Settings::FightMode ? TextWithColors("{74ff03}FIGHT MODE{74ff03}\t") : TextWithColors("{FF0000}FIGHT MODE{FF0000}\t");  //FFFFFF
			ImGui::SameLine();
			Settings::MagicBullet ? TextWithColors("{74ff03}BULLET TRACK{74ff03}\t") : TextWithColors("{FF0000}BULLET TRACK{FF0000}\t");  //FFFFFF
			ImGui::SameLine();
			Settings::Legitrack ? TextWithColors("{74ff03}LEGIT TRACK{74ff03}\t") : TextWithColors("{FF0000}LEGIT TRACK{FF0000}\t");  //FFFFFF
			ImGui::SameLine();
			Settings::Items ? TextWithColors("{74ff03}ITEMS ESP{74ff03}\t") : TextWithColors("{FF0000}ITEMS ESP{FF0000}\t");  //FFFFFF
			ImGui::SameLine();
			Settings::Vehicle ? TextWithColors("{74ff03}VEHICLE ESP{74ff03}\t") : TextWithColors("{FF0000}VEHICLE ESP{FF0000}\t");  //FFFFFF
			ImGui::SameLine();

			if (Settings::Legitrack) {
				TextWithColors(("{FF0000}Aim : Legit "));
			}
			else {
				if (Settings::curraim == 0)
				{
					TextWithColors(("{FF0000}Aim : Head "));
				}
				else if (Settings::curraim == 1)
				{
					TextWithColors(("{74ff03}Aim : Chest "));
				}
				else if (Settings::curraim == 2)
				{
					TextWithColors(("{74ff03}Aim : Pelvis "));
				}
			}


			ImGui::SetCursorPos({ 20.f,200.0f });

			ImGui::End();
		}
	}
	if (GetAsyncKeyState(VK_F6) & 1)
	{
		Settings::Legitrack = !Settings::Legitrack;
	}
	if (GetAsyncKeyState(VK_F8) & 1)
	{
		Settings::Vehicle = !Settings::Vehicle;
	}
	if (GetAsyncKeyState(VK_F7) & 1)
	{
		Settings::Items = !Settings::Items;
	}
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		Settings::FightMode = !Settings::FightMode;
	}
	if (GetAsyncKeyState(VK_F5) & 1)
	{
		Settings::MagicBullet = !Settings::MagicBullet;
	}
	if (GetAsyncKeyState('T') & 1) {
		if (Settings::curraim == 2)
			Settings::curraim = 0;
		else
			Settings::curraim++;
	}

	ImGui::PopStyleColor();

}
char CharKey[60] = "";

void DrawImage(ID3D11ShaderResourceView* img, int x, int y, int sizex, int sizey)
{
	ImGui::GetOverlayDrawList()->AddImage(img, ImVec2(x, y), ImVec2(x + sizex, y + sizey));
}
bool checking;
inline bool FileExist(const std::string& name) {
	if (FILE* file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
void Esp::LoadConfig(std::string Path) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	//	if (rc < 0) { std::cout << "File not found"; };
	if (FileExist(Path))
	{
		bool State = ini.GetBoolValue("Key", "UserKeyState");
		if (State == true)
		{
			std::string Key = ini.GetValue("Key", "UserKey");
			if (Key != "")
			{
				strcpy(CharKey, Key.c_str());
			}

		}

	}

}
void WriteConfig(std::string Path, std::string Key, bool State) {
	CSimpleIniA ini;
	ini.SetUnicode();
	SI_Error rc = ini.LoadFile(Path.c_str());
	if (rc < 0) {
		//	std::cout << "File not found";
	};
	if (State == true)
	{
		ini.SetBoolValue("Key", "UserKeyState", true);
	}
	else
	{
		ini.SetBoolValue("Key", "UserKeyState", false);
	}
	ini.SetValue("Key", "UserKey", Key.c_str());

	ini.SaveFile(Path.c_str());
}

void Loginn() {
	//LOGIN CODES . SET UR KEYAUTH AND THEN UN COMMAND THIS CODES
	/*KeyAuthApp.init();
	KeyAuthApp.license(CharKey);

	if (!KeyAuthApp.data.success) {
		MessageBoxA(0, KeyAuthApp.data.message.c_str(), "Error", MB_ICONERROR);
		Sleep(1500);
		std::exit(0);
	}*/

	Settings::Login = true;
	checking = false;
	WriteConfig("C:\\Darkness-Hack.lic", CharKey, true);
}
std::string random_string1(int len)
{
	std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, len);
}
void getlink(string link) {
	IStream* stream;
	HRESULT result = URLOpenBlockingStream(0, (link.c_str()), &stream, 0, 0);
	if (result != 0)
	{
		return;
	}
	char buffer[100];
	unsigned long bytesRead;
	std::stringstream ss;
	stream->Read(buffer, 100, &bytesRead);
	while (bytesRead > 0U)
	{
		ss.write(buffer, (long long)bytesRead);
		stream->Read(buffer, 100, &bytesRead);
	}
	stream->Release();
}
int teamids;
ImVec4 linescolors;// = { 1.0f,1.0f,1.0f,1.0f };
ImVec4 salahcolor;
int botcount;
int playercount;
D3DMATRIX Esp::ViewMatrix;

VOID Esp::EspThread()
{
	InitImages();

	VECTOR3 Screen;
	INT Distance;
	INT EnemyCount;

	VECTOR3 HeadPos;
	VECTOR2 Head;
	VECTOR2 Chest;
	VECTOR2 Pelvis;
	VECTOR2 lSholder;
	VECTOR2 rSholder;
	VECTOR2 lElbow;
	VECTOR2 rElbow;
	VECTOR2 lWrist;
	VECTOR2 rWrist;
	VECTOR2 lThigh;
	VECTOR2 rThigh;
	VECTOR2 lKnee;
	VECTOR2 rKnee;
	VECTOR2 lAnkle;
	VECTOR2 rAnkle;
	std::string temp = "";
	std::string dist = "";
	string Text = "";
	string weapon = "";
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	LoadConfig("C:\\Darkness-Hack.lic");

	while (true)
	{

		DX11::BeginDraw();
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();


		if (Settings::ShowMenu)
		{

			if (!Settings::Login)
			{
				ImGuiIO& Io = ImGui::GetIO();
				ImGui::SetNextWindowSize(ImVec2(400.0f, 390.0f));
				ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
				if (ImGui::Begin("DARKNESS HACK", 0, Flags2))
				{
					ImGui::SetCursorPosX({ 105.f });

					ImGui::Image((PVOID)Logo, ImVec2(180, 180));

					ImGui::Text(" Inject Mode : ");

					ImGui::SameLine();
					ImGui::Combo(" ", &Settings::Mode, "Only Esp\0Safe Mode\0Brutal Mode");

					ImGui::Text(" Key :\t\t\t\t");

					ImGui::SameLine();
					ImGui::InputText("###Key", CharKey, IM_ARRAYSIZE(CharKey), ImGuiInputTextFlags_Password);
					ImGui::SetCursorPosX({ 6.f });

					if (ImGui::Button(" Check", { 190.0f,23.0f }))
					{
						if (!checking) {
							thread(Loginn).detach();
							checking = true;
						}
					}
					ImGui::SameLine();
					ImGui::SetCursorPosX({ 205.f });
					if (ImGui::Button(" Get Free Key", { 190.0f,23.0f }))
					{

					}
					if (ImGui::Button(" Discord Server", { 390.0f,23.0f }))
					{
					}
					if (checking) {
						ImGui::Text("Checking Key ...");
					}
					ImGui::End();
				}

			}
			else {

				ImGui::SetNextWindowSize(ImVec2(640.0f, 540.0f));

				ImGui::Begin("DARKNESS OP", 0, Flags2);
				{
					DrawManu();
				}
				//ImGui::End();
			}
		}
		if (Settings::Login) {
			g_Discord->Update();
			if (Settings::ShowMenu2) {
				DrawMenu2();
			}
			if (Data::InLobby)
				Settings::GameState = "In Lobby";
			else
				Settings::GameState = "Player Alive : " + std::to_string(Settings::AlivePlayers) + "   Team Alive : " + std::to_string(Settings::AliveTeams);

			if (Settings::TotalEnemy)
			{
				if (Data::InLobby)
				{
					ImGuiIO& Io = ImGui::GetIO();
					ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 0, 0, 255));

					ImGui::SetNextWindowSize(ImVec2(80.0f, 30.0f));
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
					if (ImGui::Begin("lobby", 0, Flags21))
					{
						ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));

						Text = ICON_FA_HOME" In Lobby";
						ImGui::Text(Text.c_str());
						ImGui::PopStyleColor();

						ImGui::End();
					}

					ImGui::PopStyleColor();

				}
				else
				{
					if (Data::AActorList.size() != 0)
					{

						botcount = 0;
						playercount = 0;
						for (int i = 0; i < Data::AActorList.size(); i++)
						{
							if (Data::AActorList[i].IsDead == false) {
								if (Data::AActorList[i].Name == "[ Bot ]")
								{
									botcount = botcount + 1;
								}
								else
								{
									playercount = playercount + 1;
								}
							}
						}

						ImGui::SetNextWindowSize(ImVec2(185.0f, 30.0f));

						ImGuiIO& Io = ImGui::GetIO();
						ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 270, 0, 255));

						//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
						ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
						if (ImGui::Begin("enemy", 0, Flags21))
						{

							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
							Text = "  ";
							Text.append(ICON_FA_MALE" Player : " + (std::to_string(playercount)) + "  ");
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();
							ImGui::SameLine();
							ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
							Text = (ICON_FA_USER" Bot : " + (std::to_string(botcount)));
							ImGui::Text(Text.c_str());
							ImGui::PopStyleColor();


							ImGui::End();

						}
						ImGui::PopStyleColor();

					}
					else
					{


						ImGui::SetNextWindowSize(ImVec2(65.0f, 30.0f));

						ImGuiIO& Io = ImGui::GetIO();
						ImGui::PushStyleColor(ImGuiCol_Border, to_vec4(255, 270, 0, 255));

						//ImGui::SetNextWindowSize(ImVec2(400.0f, 115.0f));
						ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.1f));
						if (ImGui::Begin("clear", 0, Flags21))
						{
							Text = ICON_FA_HOME" Clear";
							ImGui::Text(Text.c_str());
							ImGui::End();
						}
						ImGui::PopStyleColor();

					}
				}
			}
			if (!Data::InLobby) {
				if (Settings::GameInfo)
				{
					ImGui::SetNextWindowSize(ImVec2(270.0f, 110.0f));
					ImGuiStyle& sstyle = ImGui::GetStyle();
					ImVec4* colors = sstyle.Colors;
					sstyle.Colors[ImGuiCol_Border] = DX11::ImGui_DX11::Color::Yellow;
					ImGuiIO& Io = ImGui::GetIO();
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.65, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
					if (ImGui::Begin("gameInfo", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
					{
						TextWithColors(("{ffffff} Alive Players : {05d5ff} " + std::to_string(Settings::AlivePlayers)).c_str());
						ImGui::SameLine();
						TextWithColors(("{ffffff} With Alive Teams : {05d5ff} " + std::to_string(Settings::AliveTeams)).c_str());

						TextWithColors(("{ffffff} Match Real Players : {05d5ff} " + std::to_string(Settings::RealPls)).c_str());
						TextWithColors(("{ffffff} Zone ID : {05d5ff} " + std::to_string(Settings::ZoneID)).c_str());
						ImGui::SameLine();
						TextWithColors(("{ffffff} Game ID : {05d5ff} " + std::to_string(Settings::GameID)).c_str());
						TextWithColors(("{ffffff} Distance Traveled : {05d5ff} " + std::to_string(Data::PlayerTravelDistance)).c_str());
						TextWithColors(("{ffffff} Elapsed Time : {05d5ff} " + std::to_string(Settings::TimeRemind)).c_str());

						ImGui::End();
					}
				}

				/*if (Settings::YourInfo)
				{
					ImGui::SetNextWindowSize(ImVec2(215.0f, 200.0f));
					ImGuiStyle& sstyle = ImGui::GetStyle();
					ImVec4* colors = sstyle.Colors;
					ImGuiIO& Io = ImGui::GetIO();
					sstyle.Colors[ImGuiCol_Border] = DX11::ImGui_DX11::Color::Green;
					ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.80f, Io.DisplaySize.y * 0.1f), ImGuiCond_FirstUseEver, ImVec2(0.15f, 0.1f));
					if (ImGui::Begin("Your Information", 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar))
					{

						std::string totalKills;
						totalKills.append("Your Kills : " + std::to_string(Data::PlayerTotalKills));

						std::string yourTeamId;
						yourTeamId.append("Your TeamId : " + std::to_string(Data::PlayerTeamID));

						std::string yourUId;
						yourUId.append("Your UID : " + Data::PlayerUID);

						std::string yourLevel;
						yourLevel.append("Your Level : " + Data::PlayerLevel);

						std::string yourNation;
						yourNation.append("Your Country : " + Data::PlayerNation);

						std::string yourHealth;
						yourHealth.append("Your Health : " + std::to_string(Data::PlayerHealth));

						std::string yourName;
						yourName.append("Your Name : " + Data::PlayerPlayerName);

						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourNation.c_str());
						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), totalKills.c_str());
						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourUId.c_str());
						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourLevel.c_str());
						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourHealth.c_str());
						ImGui::Spacing();
						ImGui::TextColored(ImVec4(1.00, 1.00, 1.00, 1.00), yourName.c_str());
						ImGui::Spacing();

						ImGui::End();
					}
				}*/
				ViewMatrix = Utility::ReadMemoryEx<D3DMATRIX>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::ViewMatrixBase) + 0x20) + 0x200);
				for (AActor& AActor : Data::AActorList)
				{
					if (!Algorithm::WorldToScreenPlayer(AActor.Position, Screen, &Distance, ViewMatrix)) continue;
					if (Distance < 400 && Distance > -1 && AActor.TeamId > 0)
					{
						if (Distance > 500 || Screen.Z < 0.001f || AActor.IsDead) continue;
						temp = to_string(AActor.TeamId) + " | " + AActor.Name.c_str();
						teamids = AActor.TeamId;
						//col = ImColor(teamids, teamids, teamids, 255);

						switch (teamids)
						{

						case 1:
							linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };
							break;
						case 2:
							linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
							break;
						case 3:
							linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
							break;
						case 4:
							linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
							break;
						case 5:
							linescolors = { 0.737f, 1.000f, 0.000f, 1.000f };
							break; 
						case 6:
							linescolors = { 0.000f, 1.000f, 0.964f, 1.000f };
							break;
						case 7:
							linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
							break;
						case 8:
							linescolors = { 1.000f, 0.100f, 0.401f, 1.000f };
							break;
						case 9:
							linescolors = { 0.610f, 0.190f, 1.000f, 1.000f };
							break;
						case  10:
							linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 11:
							linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 12:
							linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 13:
							linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 14:
							linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 15:
							linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
							break;
						case 16:
							linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
							break;
						case 17:
							linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
							break;
						case 18:
							linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
							break;
						case 19:
							linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  20:
							linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
							break;
						case 21:
							linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 22:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 23:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 24:
							linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 25:
							linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
							break;
						case 26:
							linescolors = { 1.000f, 0.70f, 0.000f, 1.000f };
							break;
						case 27:
							linescolors = { 1.000f, 1.000f, 0.000f, 1.000f };
							break;
						case 28:
							linescolors = { 0.866f, 0.128f, 0.081f, 1.000f };
							break;
						case 29:
							linescolors = { 0.844f, 0.066f, 1.000f, 1.000f };
							break;
						case 30:
							linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 31:
							linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 32:
							linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 33:
							linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 34:
							linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 35:
							linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };
							break;
						case 36:
							linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };
							break;
						case 37:
							linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };
							break;
						case 38:
							linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };
							break;
						case 39:
							linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  40:
							linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };
							break;
						case 41:
							linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 42:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 43:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 44:
							linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 45:
							linescolors = { 0.053f, 0.355f, 1.000f, 1.000f };
							break;
						case 46:
							linescolors = { 0.126f, 0.430f, 1.000f, 1.000f };
							break;
						case 47:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 48:
							linescolors = { 0.639f, 0.879f, 0.008f, 1.000f };
							break;
						case 49:
							linescolors = { 1.000f, 0.859f, 0.251f, 1.000f };
							break;
						case 50:
							linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };
							break;
						case 51:
							linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };
							break;
						case 52:
							linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };
							break;
						case 53:
							linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };
							break;
						case 54:
							linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };
							break;
						case 55:
							linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;
						case 56:
							linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 57:
							linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 58:
							linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 59:
							linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };
							break;
						case  60:
							linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
						case 61:
							linescolors = { 0.399f, 0.720f, 0.122f, 1.000f };

							break;
						case 62:
							linescolors = { 1.000f, 0.960f, 0.560f, 1.000f };

							break;
						case 63:
							linescolors = { 0.874f, 0.301f, 0.068f, 1.000f };

							break;
						case 64:
							linescolors = { 0.110f, 0.845f, 0.174f, 1.000f };

							break;
						case 65:
							linescolors = { 0.802f, 0.267f, 0.077f, 1.000f };

							break;

						case 66:
							linescolors = { 0.129f, 0.774f, 0.986f, 1.000f };

							break;
						case 67:
							linescolors = { 0.168f, 0.792f, 0.792f, 1.000f };

							break;
						case 68:
							linescolors = { 1.000f, 0.237f, 0.945f, 1.000f };

							break;
						case 69:
							linescolors = { 1.000f, 0.126f, 0.430f, 1.000f };

							break;
						case  70:
							linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

							break;
						case 71:
							linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

							break;
						case 72:
							linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

							break;
						case 73:
							linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

							break;
						case 74:
							linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

							break;
						case 75:
							linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;
						case 76:
							linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 77:
							linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 78:
							linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 79:
							linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

							break;
						case 80:
							linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
						case 81:
							linescolors = { 1.000f, 0.033f, 0.129f, 1.000f };

							break;
						case 82:
							linescolors = { 1.000f, 0.033f, 0.290f, 1.000f };

							break;
						case 83:
							linescolors = { 1.000f, 0.033f, 0.450f, 1.000f };

							break;
						case 84:
							linescolors = { 1.000f, 0.033f, 0.578f, 1.000f };

							break;
						case 85:
							linescolors = { 1.000f, 0.033f, 0.802f, 1.000f };

							break;

						case 86:
							linescolors = { 0.973f, 0.033f, 1.000f, 1.000f };

							break;
						case 87:
							linescolors = { 0.781f, 0.033f, 1.000f, 1.000f };

							break;
						case 88:
							linescolors = { 0.557f, 0.033f, 1.000f, 1.000f };

							break;
						case 89:
							linescolors = { 0.033f, 0.375f, 1.000f, 1.000f };

							break;
						case  90:
							linescolors = { 0.033f, 0.696f, 1.000f, 1.000f };

							break;
						case 91:
							linescolors = { 0.033f, 1.000f, 0.952f, 1.000f };

							break;
						case 92:
							linescolors = { 0.033f, 1.000f, 0.535f, 1.000f };

							break;
						case 93:
							linescolors = { 0.044f, 1.000f, 0.033f, 1.000f };

							break;
						case 94:
							linescolors = { 0.428f, 1.000f, 0.033f, 1.000f };

							break;
						case 95:
							linescolors = { 0.749f, 1.000f, 0.033f, 1.000f };

							break;

						case 96:
							linescolors = { 0.941f, 1.000f, 0.033f, 1.000f };

							break;
						case 97:
							linescolors = { 1.000f, 0.866f, 0.033f, 1.000f };

							break;
						case 98:
							linescolors = { 1.000f, 0.642f, 0.033f, 1.000f };

							break;
						case 99:
							linescolors = { 1.000f, 0.386f, 0.033f, 1.000f };

							break;
						case  100:
							linescolors = { 1.000f, 0.033f, 0.033f, 1.000f };

							break;
						default:
							linescolors = Settings::PlayerSkeletonColor;
							break;
						}


						if (Settings::PlayerFlag)
						{
#pragma region DrowFlags
							//for (int i = 0; i < Data::AActorList.size(); i++)
							{
								if (!AActor.IsBot && AActor.Nation == "JM")
								{
									DrawImage(JMFLAG, Screen.X + 10, Screen.Y - 30, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "G1")
								{
									DrawImage(G1FLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AF")
								{
									DrawImage(AFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AL")
								{
									DrawImage(ALFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DZ")
								{
									DrawImage(DZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AS")
								{
									DrawImage(ASFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AD")
								{
									DrawImage(ADFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AO")
								{
									DrawImage(AOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AI")
								{
									DrawImage(AIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AQ")
								{
									DrawImage(AQFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AG")
								{
									DrawImage(AGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AR")
								{
									DrawImage(ARFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AM")
								{
									DrawImage(AMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AW")
								{
									DrawImage(AWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AU")
								{
									DrawImage(AUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AT")
								{
									DrawImage(ATFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AZ")
								{
									DrawImage(AZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BS")
								{
									DrawImage(BSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BH")
								{
									DrawImage(BHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BD")
								{
									DrawImage(BDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BB")
								{
									DrawImage(BBFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BY")
								{
									DrawImage(BYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BE")
								{
									DrawImage(BEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BZ")
								{
									DrawImage(BZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BJ")
								{
									DrawImage(BJFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BM")
								{
									DrawImage(BMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BT")
								{
									DrawImage(BTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BO")
								{
									DrawImage(BOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BQ")
								{
									DrawImage(BQFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BA")
								{
									DrawImage(BAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BW")
								{
									DrawImage(BWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BV")
								{
									DrawImage(BVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BR")
								{
									DrawImage(BRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IO")
								{
									DrawImage(IOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BN")
								{
									DrawImage(BNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BG")
								{
									DrawImage(BGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BF")
								{
									DrawImage(BFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BI")
								{
									DrawImage(BIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CV")
								{
									DrawImage(CVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KH")
								{
									DrawImage(KHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CM")
								{
									DrawImage(CMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CA")
								{
									DrawImage(CAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KY")
								{
									DrawImage(KYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CF")
								{
									DrawImage(CFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TD")
								{
									DrawImage(TDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CL")
								{
									DrawImage(CLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CN")
								{
									DrawImage(CNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CX")
								{
									DrawImage(CXFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CC")
								{
									DrawImage(CCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CO")
								{
									DrawImage(COFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KM")
								{
									DrawImage(KMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CD")
								{
									DrawImage(CDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CG")
								{
									DrawImage(CGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CK")
								{
									DrawImage(CKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CR")
								{
									DrawImage(CRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HR")
								{
									DrawImage(HRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CU")
								{
									DrawImage(CUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CW")
								{
									DrawImage(CWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CY")
								{
									DrawImage(CYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CZ")
								{
									DrawImage(CZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CI")
								{
									DrawImage(CIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DK")
								{
									DrawImage(DKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DJ")
								{
									DrawImage(DJFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DM")
								{
									DrawImage(DMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DO")
								{
									DrawImage(DOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "EC")
								{
									DrawImage(ECFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "EG")
								{
									DrawImage(EGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SV")
								{
									DrawImage(SVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GQ")
								{
									DrawImage(GQFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ER")
								{
									DrawImage(ERFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "EE")
								{
									DrawImage(EEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SZ")
								{
									DrawImage(SZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ET")
								{
									DrawImage(ETFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FK")
								{
									DrawImage(FKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FO")
								{
									DrawImage(FOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FJ")
								{
									DrawImage(FJFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FI")
								{
									DrawImage(FIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FR")
								{
									DrawImage(FRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GF")
								{
									DrawImage(GFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PF")
								{
									DrawImage(PFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TF")
								{
									DrawImage(TFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GA")
								{
									DrawImage(GAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GM")
								{
									DrawImage(GMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GE")
								{
									DrawImage(GEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "DE")
								{
									DrawImage(DEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GH")
								{
									DrawImage(GHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GI")
								{
									DrawImage(GIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GR")
								{
									DrawImage(GRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GL")
								{
									DrawImage(GLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GD")
								{
									DrawImage(GDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GP")
								{
									DrawImage(GPFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GU")
								{
									DrawImage(GUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GT")
								{
									DrawImage(GTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GG")
								{
									DrawImage(GGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GN")
								{
									DrawImage(GNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GW")
								{
									DrawImage(GWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GY")
								{
									DrawImage(GYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HT")
								{
									DrawImage(HTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HM")
								{
									DrawImage(HMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VA")
								{
									DrawImage(VAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HN")
								{
									DrawImage(HNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HK")
								{
									DrawImage(HKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "HU")
								{
									DrawImage(HUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "JP")
								{
									DrawImage(JPFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "JE")
								{
									DrawImage(JEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "JO")
								{
									DrawImage(JOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KZ")
								{
									DrawImage(KZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KE")
								{
									DrawImage(KEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KI")
								{
									DrawImage(KIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KP")
								{
									DrawImage(KPFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KR")
								{
									DrawImage(KRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KW")
								{
									DrawImage(KWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KG")
								{
									DrawImage(KGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LA")
								{
									DrawImage(LAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LV")
								{
									DrawImage(LVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LB")
								{
									DrawImage(LBFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LS")
								{
									DrawImage(LSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LR")
								{
									DrawImage(LRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LY")
								{
									DrawImage(LYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LI")
								{
									DrawImage(LIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LT")
								{
									DrawImage(LTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LU")
								{
									DrawImage(LUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MO")
								{
									DrawImage(MOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MG")
								{
									DrawImage(MGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MW")
								{
									DrawImage(MWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MY")
								{
									DrawImage(MYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MV")
								{
									DrawImage(MVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ML")
								{
									DrawImage(MLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MT")
								{
									DrawImage(MTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MH")
								{
									DrawImage(MHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MQ")
								{
									DrawImage(MQFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MR")
								{
									DrawImage(MRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MU")
								{
									DrawImage(MUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "YT")
								{
									DrawImage(YTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MX")
								{
									DrawImage(MXFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "FM")
								{
									DrawImage(FMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MD")
								{
									DrawImage(MDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MC")
								{
									DrawImage(MCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MN")
								{
									DrawImage(MNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ME")
								{
									DrawImage(MEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MS")
								{
									DrawImage(MSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MA")
								{
									DrawImage(MAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MZ")
								{
									DrawImage(MZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MM")
								{
									DrawImage(MMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NA")
								{
									DrawImage(NAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NR")
								{
									DrawImage(NRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NP")
								{
									DrawImage(NPFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NL")
								{
									DrawImage(NLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NC")
								{
									DrawImage(NCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NZ")
								{
									DrawImage(NZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NI")
								{
									DrawImage(NIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NE")
								{
									DrawImage(NEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NG")
								{
									DrawImage(NGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NU")
								{
									DrawImage(MUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NF")
								{
									DrawImage(NFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MP")
								{
									DrawImage(NPFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "NO")
								{
									DrawImage(NOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "OM")
								{
									DrawImage(OMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PK")
								{
									DrawImage(PKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PW")
								{
									DrawImage(PWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PS")
								{
									DrawImage(PSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PA")
								{
									DrawImage(PAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PG")
								{
									DrawImage(PGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PY")
								{
									DrawImage(PYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PE")
								{
									DrawImage(PEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PH")
								{
									DrawImage(PHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PN")
								{
									DrawImage(PNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PL")
								{
									DrawImage(PLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PT")
								{
									DrawImage(PTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PR")
								{
									DrawImage(PRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "QA")
								{
									DrawImage(QAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MK")
								{
									DrawImage(MKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "RO")
								{
									DrawImage(ROFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "RU")
								{
									DrawImage(RUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "RW")
								{
									DrawImage(RWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "RE")
								{
									DrawImage(REFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "BL")
								{
									DrawImage(BLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SH")
								{
									DrawImage(SHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "KN")
								{
									DrawImage(KNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LC")
								{
									DrawImage(LCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "MF")
								{
									DrawImage(MFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "PM")
								{
									DrawImage(PMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VC")
								{
									DrawImage(VCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "WS")
								{
									DrawImage(WSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SM")
								{
									DrawImage(SMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ST")
								{
									DrawImage(STFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SA")
								{
									DrawImage(SAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SN")
								{
									DrawImage(SNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "RS")
								{
									DrawImage(RSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SC")
								{
									DrawImage(SCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SL")
								{
									DrawImage(SLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SG")
								{
									DrawImage(SGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SX")
								{
									DrawImage(SXFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SK")
								{
									DrawImage(SKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SI")
								{
									DrawImage(SIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SB")
								{
									DrawImage(SBFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SO")
								{
									DrawImage(SOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ZA")
								{
									DrawImage(ZAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GS")
								{
									DrawImage(GSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SS")
								{
									DrawImage(SSFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ES")
								{
									DrawImage(ESFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "LK")
								{
									DrawImage(LKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SD")
								{
									DrawImage(SDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SR")
								{
									DrawImage(SRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SJ")
								{
									DrawImage(SJFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SE")
								{
									DrawImage(SEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "CH")
								{
									DrawImage(CHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "SY")
								{
									DrawImage(SYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TW")
								{
									DrawImage(TWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TJ")
								{
									DrawImage(TJFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TZ")
								{
									DrawImage(TZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TH")
								{
									DrawImage(THFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TL")
								{
									DrawImage(TLFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TG")
								{
									DrawImage(TGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TK")
								{
									DrawImage(TKFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TO")
								{
									DrawImage(TOFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TT")
								{
									DrawImage(TTFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TN")
								{
									DrawImage(TNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TR")
								{
									DrawImage(TRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TM")
								{
									DrawImage(TMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TC")
								{
									DrawImage(TCFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "TV")
								{
									DrawImage(TVFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "UG")
								{
									DrawImage(UGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "UA")
								{
									DrawImage(UAFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AE")
								{
									DrawImage(AEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "GB")
								{
									DrawImage(GBFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "US")
								{
									DrawImage(USFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "UY")
								{
									DrawImage(UYFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "UZ")
								{
									DrawImage(UZFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VU")
								{
									DrawImage(VUFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VE")
								{
									DrawImage(VEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VN")
								{
									DrawImage(VNFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VG")
								{
									DrawImage(VGFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "VI")
								{
									DrawImage(VIFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "WF")
								{
									DrawImage(WFFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "EH")
								{
									DrawImage(EHFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "YE")
								{
									DrawImage(YEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ZM")
								{
									DrawImage(ZMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ZW")
								{
									DrawImage(ZWFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "AX")
								{
									DrawImage(AXFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IS")
								{
									DrawImage(ISFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IN")
								{
									DrawImage(INFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "ID")
								{
									DrawImage(IDFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IR")
								{
									DrawImage(IRFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IQ")
								{
									DrawImage(IQFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IE")
								{
									DrawImage(IEFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IM")
								{
									DrawImage(IMFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IL")
								{
									DrawImage(ILFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
								if (!AActor.IsBot && AActor.Nation == "IT")
								{
									DrawImage(ITFLAG, Screen.X + 15, Screen.Y - 15, 20, 14);
								}
#pragma endregion
							}
						}
						//col = ImColor(teamids, teamids, teamids, 255);
						if (Settings::PlayerName)
						{
							if (AActor.Health <= 0)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Settings::PlayerNameSize, temp, Screen.X - 50, Screen.Y - 30, DX11::ImGui_DX11::Color::Red, false);
							}


							else
							{

								if (AActor.IsBot)
								{
									AActor.Name = " [ BOT ] ";

									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Settings::PlayerNameSize, temp, Screen.X - 50, Screen.Y - 30, ImVec4(0.0194, 0.970, 0.922, 1.0), false);

								}
								else
								{

									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Settings::PlayerNameSize, temp, Screen.X - 20, Screen.Y - 30, Settings::PlayerNameColor, true);

								}
							}
						}

						if (Settings::PlayerDistance)
						{
							if (Settings::PlayerWeapon)
								Text = AActor.weapon + " | " + to_string(Distance) + "M";
							else

								Text = to_string(Distance) + "M";


							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, Text, Screen.X - 30, (Screen.Y + 15 + Screen.Z), DX11::ImGui_DX11::Color::Green, false);

						}
						if (Settings::PlayerHealth)
						{

							DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5), DX11::ImGui_DX11::Color::Black);

							if (AActor.Health > 70.0)
							{
								DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Green);
							}
							if (AActor.Health > 30.0 && AActor.Health <= 70.0)
							{
								DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Yellow);
							}
							if (AActor.Health > 0.0 && AActor.Health <= 30.0)
							{
								DX11::ImGui_DX11::DrawFilledRectangle(Screen.X - (Screen.Z / 4) - 4, (Screen.Y - 5) + (Screen.Z + 5), 3, (Screen.Z + 5) * AActor.Health / AActor.HealthMax, DX11::ImGui_DX11::Color::Red);

							}


						}
						if (Settings::PlayerBox)
						{
							DX11::ImGui_DX11::CornerBox(Screen.X - Screen.Z / 4 - 3, Screen.Y - 5, (Screen.Z / 2) + 3, Screen.Z + 5, 0.7f, 0.5f / 2, Settings::PlayerBoxColor);
						}
						float Botlinescolors[] = { 255, 255, 255, 255 };
						if (Settings::PlayerLine)
						{
							if (AActor.IsBot)
							{
								DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, ImColor(Botlinescolors[0], Botlinescolors[1], Botlinescolors[2], Botlinescolors[3]), 0.7f);
							}
							else if (Settings::PlayerLineMode == 0)
							{
								DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, linescolors, 0.7f);
							}
							else {
								DX11::ImGui_DX11::DrawLine(DX11Window::Width / 2, 0, Screen.X, Screen.Y - 5, Settings::PlayerLineColor, 0.7f);

							}

						}
						if (Settings::PlayerSkeleton)
						{
							ImColor bonescolors1;
							HeadPos = AActor.HeadPos;
							HeadPos.Z += 7;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, HeadPos, Head, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.ChestPos, Chest, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.PelvisPos, Pelvis, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lSholderPos, lSholder, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rSholderPos, rSholder, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lElbowPos, lElbow, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rElbowPos, rElbow, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lWristPos, lWrist, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rWristPos, rWrist, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lThighPos, lThigh, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rThighPos, rThigh, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lKneePos, lKnee, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rKneePos, rKnee, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.lAnklePos, lAnkle, &Distance)) continue;
							if (!Algorithm::WorldToScreenBone(ViewMatrix, AActor.rAnklePos, rAnkle, &Distance)) continue;

							{
								if (AActor.Address == 0) {
									bonescolors1 = DX11::ImGui_DX11::Color::Red;
								}
								else {
									if (Settings::PlayerSkeletonMode = 0)
										bonescolors1 = linescolors;
									else
										bonescolors1 = Settings::PlayerSkeletonColor;
								}

								{
									DX11::ImGui_DX11::DrawCircle(Head.X, Head.Y, Screen.Z / 12, DX11::ImGui_DX11::Color::Yellow, 0.7f);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, Pelvis.X, Pelvis.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, lSholder.X, lSholder.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(Chest.X, Chest.Y, rSholder.X, rSholder.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(lSholder.X, lSholder.Y, lElbow.X, lElbow.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(rSholder.X, rSholder.Y, rElbow.X, rElbow.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(lElbow.X, lElbow.Y, lWrist.X, lWrist.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(rElbow.X, rElbow.Y, rWrist.X, rWrist.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, lThigh.X, lThigh.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(Pelvis.X, Pelvis.Y, rThigh.X, rThigh.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(lThigh.X, lThigh.Y, lKnee.X, lKnee.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(rThigh.X, rThigh.Y, rKnee.X, rKnee.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(lKnee.X, lKnee.Y, lAnkle.X, lAnkle.Y, bonescolors1, 0.7f);
									DX11::ImGui_DX11::DrawLine(rKnee.X, rKnee.Y, rAnkle.X, rAnkle.Y, bonescolors1, 0.7f);
								}

							}
						}

					}
					//if (Settings::Dots)
					//{

					//	salahcolor = linescolors;
					//	float S_height = DX11Window::Height;
					//	float S_width = DX11Window::Width;
					//	bool shit = false;
					//	VECTOR3 EntityPos = WorldToRadar(Data::CameraCache.POV.Rotation.Yaw, AActor.Position, Data::CameraCache.POV.Location, NULL, NULL, ToVECTOR3(S_width, S_height, 0), shit);

					//	int x, y;
					//	x = EntityPos.X;
					//	y = EntityPos.Y;

					//	auto angle = VECTOR3();
					//	VECTOR3 temmp = ToVECTOR3((float)(S_width / 2) - x, (float)(S_height / 2) - y, 0.f);

					//	VectorAnglesRadar(temmp, angle);

					//	const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
					//	const auto new_point_x = (S_width / 2) + (Settings::DotsSize) / 2 * 8 * cosf(angle_yaw_rad);
					//	const auto new_point_y = (S_height / 2) + (Settings::DotsSize) / 2 * 8 * sinf(angle_yaw_rad);

					//	std::array<VECTOR3, 3> points
					//	{
					//		ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((Settings::DotsSize) / 4 + 3.5f) / 2, 0.f),
					//		ToVECTOR3(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
					//		ToVECTOR3(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((Settings::DotsSize) / 4 + 3.5f) / 2, 0.f)
					//	};
					//	if (AActor.IsBot) {
					//		DX11::ImGui_DX11::DrawRectangle(points.at(1).X, points.at(1).Y, 10, 10, ImColor(3, 255, 0), 2);
					//	}
					//	else {
					//		DX11::ImGui_DX11::DrawRectangle(points.at(1).X, points.at(1).Y, 10, 10, ImColor(255, 0, 0), 5);
					//	}
					//}
					//if (Settings::Radar)
					//{

					//	//float S_height = DX11Window::Height;
					//	//float S_width = DX11Window::Width;
					//	if (AActor.IsBot) {
					//		DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 20, 50, 100, 200, ImColor(3, 255, 0));

					//	}
					//	else {
					//		DrawRadarHUD(Data::CameraCache.POV, AActor, Distance, 20, 50, 100, 200, ImColor(255, 0, 0));

					//	}

					//}
					if (AActor.IsBot) continue;
					int enemystate = AActor.status;
					string stateB = std::to_string(enemystate);
					if (stateB == "0") { stateB == "AFK"; }
					else if (stateB == "1") { stateB = "InWater"; }
					else if (stateB == "268435464") { stateB = "Play Emotion"; }
					else if (stateB == "8") { stateB = "Stand"; }
					else if (stateB == "520" || stateB == "544" || stateB == "656" || stateB == "521" || stateB == "528") { stateB = "Aiming"; }
					else if (stateB == "1680" || stateB == "1672" || stateB == "1673" || stateB == "1032" || stateB == "1544" || stateB == "1545" || stateB == "1033") { stateB = "Peek"; }
					else if (stateB == "9") { stateB = "Walking"; }
					else if (stateB == "11") { stateB = "Running"; }
					else if (stateB == "4194304") { stateB = "Swimming"; }
					else if (stateB == "32784") { stateB = "Reviving"; }
					else if (stateB == "16777224") { stateB = "Climbing"; }
					else if (stateB == "8200" || stateB == "8208") { stateB = "Punching"; }
					else if (stateB == "16" || stateB == "17" || stateB == "19") { stateB = "Crouch"; }
					else if (stateB == "32" || stateB == "33" || stateB == "35") { stateB = "Snake"; }
					else if (stateB == "5445" || stateB == "762" || stateB == "35") { stateB = "Snake"; }
					else if (stateB == "72" || stateB == "73" || stateB == "75") { stateB = "Jumping"; }
					else if (stateB == "264" || stateB == "272" || stateB == "273" || stateB == "288" || stateB == "265" || stateB == "329") { stateB = "Reloading"; }
					else if (stateB == "137" || stateB == "144" || stateB == "201" || stateB == "145" || stateB == "160" || stateB == "649" || stateB == "648" || stateB == "1160" || stateB == "1161" || stateB == "1169") { stateB = "Firing"; }
					else if (stateB == "131070" || stateB == "131071" || stateB == "131072" || stateB == "131073" || stateB == "131074" || stateB == "131075") { stateB = "Knocked"; }
					else if (stateB == "33554440" || stateB == "524296" || stateB == "1048584" || stateB == "524288") { stateB = "Driving"; }
					else if (stateB == "16392" || stateB == "16393" || stateB == "16401" || stateB == "16416" || stateB == "16417" || stateB == "16457") { stateB = "Throwing Bomb"; }
					else if (stateB == "16400" || stateB == "17401" || stateB == "17417" || stateB == "17424" || stateB == "17425") { stateB = "Throwing Bomb"; }
					else
					{
						stateB = " ";
					}
					if (Settings::PlayerState) {
						{

							if (stateB == "Aiming") {
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Settings::PlayerStateSize, stateB, Screen.X - 20, (Screen.Y + 30 + Screen.Z), DX11::ImGui_DX11::Color::Red, true);
							}
							else {
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, Settings::PlayerStateSize, stateB, Screen.X - 20, (Screen.Y + 30 + Screen.Z), Settings::PlayerStateColor, true);
							}
						}
					}
					if (Settings::AimWarning) {

						if (stateB == "Aiming") {
							ImColor colorofwaring;
							int randomNum = (rand() % 40) + 1;
							if (randomNum >= 1 && randomNum <= 20)
							{
								colorofwaring = ImColor(255, 0, 0);
							}
							if (randomNum > 20 && randomNum <= 40)
							{
								colorofwaring = ImColor(255, 255, 0);

							}
							if (randomNum == 40)
							{
								randomNum == 1;
							}
							Text = "Enemy Aiming At You";
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 30, Text, DX11Window::Width / 2, DX11Window::Height / 100 * 14.5f, colorofwaring, true);
						}
					}

					if (Settings::Redzone)
					{

						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;

							string air = Item.Name + " " + to_string(Distance) + " M";

							if (Item.Name == "Redzone")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 20, air, Screen.X - 1, Screen.Y - 1, DX11::ImGui_DX11::Color::Red, true);

								DrawImage(RedZoneImage, Screen.X - 75, Screen.Y - 150, 200, 200);
							}
						}
					}


				}
				if (Settings::FovShow)
				{
					if (Data::AActorList.size() != 0)
					{
						DX11::ImGui_DX11::DrawCircle(DX11Window::Width / 2, DX11Window::Height / 2, Settings::fovcircleredus, Settings::FovColor);
					}
				}
				if (Settings::Legitrack)
				{
					int random = rand() % 3;
					Settings::curraim = random;

				}
				{
					for (Item& Item : Data::ItemList)
					{
						if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;
						if (Item.Name == "FRAG")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, Item.Name, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Yellow, true);
						}
						if (Item.Name == "Frag")
						{

							DrawImage(GN2, Screen.X - 10, Screen.Y - 20, 60, 60);
						}
						if (Item.Name == "Smoke")
						{
							DrawImage(Smk, Screen.X - 10, Screen.Y - 20, 40, 35);
						}
						if (Item.Name == "Molotof")
						{
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, Item.Name, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Yellow, true);

						}
						if (Item.Name == "Burn")
						{
							DrawImage(BRU, Screen.X - 10, Screen.Y - 20, 40, 35);
						}

					}
				}
				if (!Settings::FightMode) {
					if (Settings::AirDrop) {
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;
							if (Item.Name == "Air Drop")
							{
								DrawImage(AirDropImage, Screen.X - 20, Screen.Y - 25, 35, 30);
								auto dist = to_string(Distance) + "M";
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 15, dist, Screen.X, Screen.Y + 15, ImVec4(0.737f, 1.000f, 0.000f, 1.000f), true);
							}
						}
					}
					if (Settings::Lootbox)
					{
						ImColor color;
						for (int i = 0; i < g_pEsp->lootboxr.size(); i++)
						{
							if (!Algorithm::WorldToScreen(g_pEsp->lootboxr[i].Position, Screen, &Distance, ViewMatrix)) continue;
							if (Distance > 70)continue;
							std::string dead = "[ Dead Box   " + to_string(Distance) + "M ]";

							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, dead, Screen.X, Screen.Y + 18, ImVec4(0.737f, 1.000f, 0.000f, 1.000f), false);
							if (Settings::LootboxItems)
							{


								for (int k = 0; k < g_pEsp->lootboxr[i].boxitem.size(); k++)
								{

									color = g_pEsp->lootboxr[i].boxitem[k].colorcod;
									std::string text = g_pEsp->lootboxr[i].boxitem[k].Displayname;

									DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, text, Screen.X, Screen.Y - 15 * (k), g_pEsp->lootboxr[i].boxitem[k].colorcod, false);
									//continue;

									//if (Setting::bg)
									{
										DX11::ImGui_DX11::DrawFilledRect(Screen.X - 10, Screen.Y - 15 * (k), 100, 15, ImColor(0.000f, 0.00f, 0.00f, 0.200f));
									}

									DX11::ImGui_DX11::CornerBox(Screen.X - 10, Screen.Y - 15 * (k), 110, 15, 0.6f, 0.450f, ImVec4(0.000f, 1.000f, 0.964f, 1.000f));
								}

							}



						}


					}
					if (Settings::Items) {
						for (Item& Item : Data::ItemList)
						{
							if (!Algorithm::WorldToScreen(Item.Position, Screen, &Distance, ViewMatrix)) continue;
							Text = Item.Name;// +" " + "(" + to_string(Distance) + "m)";
							string air = Item.Name + " " + to_string(Distance) + "M";
							if (Item.Name == "Akm")
							{
								DrawImage(AkmImage, Screen.X - 10, Screen.Y - 20, 40, 35);
							}
							if (Item.Name == "M16A4")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::M16A4Color, true);
							}
							if (Item.Name == "SCARL")
							{
								DrawImage(ScarImage, Screen.X - 10, Screen.Y - 20, 40, 35);
							}
							if (Item.Name == "M416")
							{
								DrawImage(M416Image, Screen.X - 10, Screen.Y - 20, 40, 35);
							}
							if (Item.Name == "GROZA")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::GROZAColor, true);
							}
							if (Item.Name == "AUG")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AUGColor, true);
							}
							if (Item.Name == "QBZ")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::QBZColor, true);
							}
							if (Item.Name == "M762")
							{
								DrawImage(M762Image, Screen.X - 10, Screen.Y - 20, 40, 35);
							}
							if (Item.Name == "MK47")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MK47Color, true);
							}
							if (Item.Name == "G36C")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::G36CColor, true);
							}
							if (Item.Name == "HONEY")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::HONEYColor, true);
							}
							if (Item.Name == "FAMAS")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::FAMASColor, true);
							}
							if (Item.Name == "KAR98")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::KAR98Color, true);
							}
							if (Item.Name == "M24")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::M24Color, true);
							}
							if (Item.Name == "AWM")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AWMColor, true);
							}
							if (Item.Name == "WIN94")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::WIN94Color, true);
							}
							if (Item.Name == "MOSIN")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MOSINColor, true);
							}
							if (Item.Name == "AMR")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AMRColor, true);
							}
							if (Item.Name == "SKS")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::SKSColor, true);
							}
							if (Item.Name == "VSS")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::VSSColor, true);
							}
							if (Item.Name == "MINI14")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MINI14Color, true);
							}
							if (Item.Name == "MK14")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MK14Color, true);
							}
							if (Item.Name == "SLR")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::SLRColor, true);
							}
							if (Item.Name == "QBU")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::QBUColor, true);
							}
							if (Item.Name == "MK12")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MK12Color, true);
							}
							if (Item.Name == "UZI")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::UZIColor, true);
							}
							if (Item.Name == "UMP45")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::UMP45Color, true);
							}
							if (Item.Name == "VECTOR")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::VECTORColor, true);
							}
							if (Item.Name == "THOMPSON")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::THOMPSONColor, true);
							}
							if (Item.Name == "BIZON")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::BIZONColor, true);
							}
							if (Item.Name == "MP5K")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MP5KColor, true);
							}
							if (Item.Name == "P90")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::P90Color, true);
							}
							if (Item.Name == "S686")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::S686Color, true);
							}
							if (Item.Name == "S1897")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::S1897Color, true);
							}
							if (Item.Name == "S12K")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::S12KColor, true);
							}
							if (Item.Name == "DBS")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::DBSColor, true);
							}
							if (Item.Name == "M1014")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::M1014Color, true);
							}
							if (Item.Name == "NS2000")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::NS2000Color, true);
							}
							if (Item.Name == "M249")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::M249Color, true);
							}
							if (Item.Name == "DP28")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::DP28Color, true);
							}
							if (Item.Name == "MG3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MG3Color, true);
							}
							if (Item.Name == "FLARE")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::FLAREColor, true);
							}
							if (Item.Name == "FRAG")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::FRAGColor, true);
							}
							if (Item.Name == "SMOKE")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::SMOKEColor, true);
							}
							if (Item.Name == "MOLOTOF")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MOLOTOFColor, true);
							}
							if (Item.Name == "MedKit")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::MedKitColor, true);
							}
							if (Item.Name == "FirstAidKit")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::FirstAidKitColor, true);
							}
							if (Item.Name == "Painkiller")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::PainkillerColor, true);
							}
							if (Item.Name == "EnergyDrink")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::EnergyDrinkColor, true);
							}
							if (Item.Name == "Adrenalin")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AdrenalinColor, true);
							}
							if (Item.Name == "Bag1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Bag1Color, true);
							}
							if (Item.Name == "Bag2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Bag2Color, true);
							}
							if (Item.Name == "Bag3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Bag3Color, true);
							}
							if (Item.Name == "Helmet1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Helmet1Color, true);
							}
							if (Item.Name == "Helmet2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Helmet2Color, true);
							}
							if (Item.Name == "Helmet3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Helmet3Color, true);
							}
							if (Item.Name == "Armor1")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Armor1Color, true);
							}
							if (Item.Name == "Armor2")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Armor2Color, true);
							}
							if (Item.Name == "Armor3")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Armor3Color, true);
							}
							if (Item.Name == "7.62mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::a762mmColor, true);
							}
							if (Item.Name == "5.56mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::a556mmColor, true);
							}
							if (Item.Name == "9mm")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::a9mmColor, true);
							}
							if (Item.Name == "45ACP")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::a45ACPColor, true);
							}
							if (Item.Name == "12Gauege")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::a12GauegeColor, true);
							}
							if (Item.Name == "AwmAmmo")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AwmAmmoColor, true);
							}
							if (Item.Name == "AmrAmmo")
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::AmrAmmoColor, true);
							}
							if (Item.Name == "Scope_x2")
							{
								Text = "2x";

								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Scope_x2Color, true);
							}
							if (Item.Name == "Scope_x3")
							{
								Text = "3x";

								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Scope_x3Color, true);
							}
							if (Item.Name == "Scope_x4")
							{
								Text = "4x";

								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Scope_x4Color, true);
							}
							if (Item.Name == "Scope_x6")
							{
								Text = "6x";

								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Scope_x6Color, true);
							}
							if (Item.Name == "Scope_x8")
							{
								Text = "8x";
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::special, 17, Text, Screen.X, Screen.Y, Settings::Scope_x8Color, true);
							}
							if (Item.Name == "Shop Token")
							{
								DrawImage(ShopTokenImage, Screen.X - 5, Screen.Y - 8, 18, 20);
							}
						}
					}


					if (Settings::Vehicle)
					{
						for (Vehicle& Vehicle : Data::VehicleList)
						{
							if (!Algorithm::WorldToScreen(Vehicle.Position, Screen, &Distance, Esp::ViewMatrix)) continue;

							if (Distance < 10 || Distance > 750 || Vehicle.hp < 0 || Vehicle.oil < 0) {
								continue;

							}

							Text = ICON_FA_CAR" " + Vehicle.Name + " [" + to_string(Distance) + "m]";

							std::string fuel;

							fuel.append(ICON_FA_HEARTBEAT " ").append(std::to_string((int)(Vehicle.hp)).append(" | " ICON_FA_BATTERY_FULL).append(" " + std::to_string((int)(Vehicle.oil)).append("")));
							DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Settings::VehicleSize, fuel, Screen.X, Screen.Y + 20, Settings::VehicleColor, true);
							if (Vehicle.driving)
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Settings::VehicleSize, Text, Screen.X, Screen.Y, DX11::ImGui_DX11::Color::Red, true);

							}
							else
							{
								DX11::ImGui_DX11::DrawBorderString(DX11::ImGui_DX11::pIconFont, Settings::VehicleSize, Text, Screen.X, Screen.Y, Settings::VehicleColor, true);

							}
						}
					}
				}
			}

		}
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		DX11::EndDraw();
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
}
