#include "Includes.h"
#include "CLocalplayer.h"
#include "CConfig.h"
#include "CMemory.h"


/* Global Vars */
bool Radar = false;
bool Bhop = false;
bool Nohands = false;
bool Noflash = false;
bool Glow = false;
bool Trigger = false;
bool RCS = false;
bool Active = false;
bool Loaded = false;
bool output = false;
bool Aimbot = false;

/* Glow Enemy */
bool glowenemy = true;
float enemyred = 1.0;
float enemygreen = 0;
float enemyblue = 0;
float enemyalpha = 0.7;

/* Glow Friend */
bool glowfriend = false;
float friendred = 0.0;
float friendgreen = 0.5;
float friendblue = 0.5;
float friendalpha = 0.7;

/* Glow Weapons */
bool glowweapon = true;
float weaponred = 0.5;
float weapongreen = 0.5;
float weaponblue = 0.5;
float weaponalpha = 0.7;

/* Glow Nades */
bool glownade = true;
float nadered = 0.0;
float nadegreen = 0.0;
float nadeblue = 1.0;
float nadealpha = 0.7;


/* Trigger Delays */
int delaypistol = 1;
int delayrifle = 20;
int delaysniper = 50;
int delaypumpgun = 10;


/* RCS */
int rcsstartshot = 1;
float rcsstrengh = 3.5;

/* Aimbot */
bool aimnextafterdeath = 0;
float aimbotfovread = 3;
float aimbotfov = aimbotfovread * 10;
bool alwaysaimatclosest = false;
float bone = 6;




void CChecker::ReadConfiguration() {


	g_pColor->printColor(XorStr(" [>] Config wird eingelesen "), CC_WHITE, CC_BLACK);


	ConfigFile cfg("config.cfg");

	Radar = cfg.getValueOfKey<bool>XorStr("radar");
	Bhop = cfg.getValueOfKey<bool>XorStr("bhop");
	Nohands = cfg.getValueOfKey<bool>XorStr("nohands");
	Noflash = cfg.getValueOfKey<bool>XorStr("noflash");
	Glow = cfg.getValueOfKey<bool>XorStr("glow");
	Trigger = cfg.getValueOfKey<bool>XorStr("trigger");
	RCS = cfg.getValueOfKey<bool>XorStr("rcs"); 
	Aimbot = cfg.getValueOfKey<bool>XorStr("aimbot");
	glowenemy = cfg.getValueOfKey <bool>XorStr("glowenemy");
	enemyred = cfg.getValueOfKey<float>XorStr("enemyred");
	enemygreen = cfg.getValueOfKey<float>XorStr("enemygreen");
	enemyblue = cfg.getValueOfKey<float>XorStr("enemyblue");
	enemyalpha = cfg.getValueOfKey<float>XorStr("enemyalpha");
	glowfriend = cfg.getValueOfKey <bool>XorStr("glowfriend");
	friendred = cfg.getValueOfKey<float>XorStr("friendred");
	friendgreen = cfg.getValueOfKey<float>XorStr("friendgreen");
	friendblue = cfg.getValueOfKey<float>XorStr("friendblue");
	friendalpha = cfg.getValueOfKey<float>XorStr("friendalpha");
	glowweapon = cfg.getValueOfKey <bool>XorStr("glowweapon");
	weaponred = cfg.getValueOfKey<float>XorStr("weaponred");
	weapongreen = cfg.getValueOfKey<float>XorStr("weapongreen");
	weaponblue = cfg.getValueOfKey<float>XorStr("weaponblue");
	weaponalpha = cfg.getValueOfKey<float>XorStr("weaponalpha");
	glownade = cfg.getValueOfKey <bool>XorStr("glownade");
	nadered = cfg.getValueOfKey<float>XorStr("nadered");
	nadegreen = cfg.getValueOfKey<float>XorStr("nadegreen");
	nadeblue = cfg.getValueOfKey<float>XorStr("nadeblue");
	nadealpha = cfg.getValueOfKey<float>XorStr("nadealpha");
	delaypistol = cfg.getValueOfKey<int>XorStr("delaypistol");
	delayrifle = cfg.getValueOfKey<int>XorStr("delayrifle");
	delaysniper = cfg.getValueOfKey<int>XorStr("delaysniper");
	delaypumpgun = cfg.getValueOfKey<int>XorStr("delayshotgun");
	rcsstartshot = cfg.getValueOfKey<int>XorStr("rcsstartshot");
	rcsstrengh = cfg.getValueOfKey<float>XorStr("rcsstrengh");
	aimbotfovread = cfg.getValueOfKey<float>XorStr("aimbotfov");
	aimnextafterdeath = cfg.getValueOfKey<bool>XorStr("aimnextafterdeath");
	alwaysaimatclosest = cfg.getValueOfKey<bool>XorStr("alwaysaimatclosest");
	bone = cfg.getValueOfKey<float>XorStr("bone");

	
	
	Sleep(1500);




}




void text() {

	system("cls");
	g_pColor->printColor(XorStr(" [>] Spyros External - V 0x2 "), CC_WHITE, CC_BLACK);
	g_pColor->printColor(XorStr("  "), CC_WHITE, CC_BLACK);
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 8] - Bhop: "), CC_RED, CC_WHITE);  std::cout << std::boolalpha << g_pChecker->GetBhop() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 6] - NoFlash: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetNoflash() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 9] - Radar: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetRadar() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 7] - NoHands: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetNohands() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 5] - Glow: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetGlow() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 4] - Trigger: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetTrigger() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 3] - RCS: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->GetRCS() << "\n" << std::endl;
	g_pColor->printColorwb(XorStr(" [>] [NUMPAD 2] - Aimbot: "), CC_RED, CC_WHITE); std::cout << std::boolalpha << g_pChecker->getAimbot() << "\n" << std::endl;
	g_pColor->printColor(XorStr("  "), CC_WHITE, CC_BLACK);
	g_pColor->printColor(XorStr(" [>] [INS]/[EINFG] de-/aktiviert alle Funktionen! (Panic Key)  "), CC_WHITE, CC_RED);
	g_pColor->printColor(XorStr(" [>] [F11] liest die Config neu ein. "), CC_WHITE, CC_BLACK);

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}



void ReadConfigurationWhileStarted() {


	g_pColor->printColor(XorStr(" [>] Config wird erneut eingelesen "), CC_WHITE, CC_BLACK);


	ConfigFile cfg("config.cfg");

	Radar = cfg.getValueOfKey<bool>XorStr("radar");
	Bhop = cfg.getValueOfKey<bool>XorStr("bhop");
	Nohands = cfg.getValueOfKey<bool>XorStr("nohands");
	Noflash = cfg.getValueOfKey<bool>XorStr("noflash");
	Glow = cfg.getValueOfKey<bool>XorStr("glow");
	Trigger = cfg.getValueOfKey<bool>XorStr("trigger");
	RCS = cfg.getValueOfKey<bool>XorStr("rcs");
	Aimbot = cfg.getValueOfKey<bool>XorStr("aimbot");

	glowenemy = cfg.getValueOfKey <bool>XorStr("glowenemy");
	enemyred = cfg.getValueOfKey<float>XorStr("enemyred");
	enemygreen = cfg.getValueOfKey<float>XorStr("enemygreen");
	enemyblue = cfg.getValueOfKey<float>XorStr("enemyblue");
	enemyalpha = cfg.getValueOfKey<float>XorStr("enemyalpha");
	glowfriend = cfg.getValueOfKey <bool>XorStr("glowfriend");
	friendred = cfg.getValueOfKey<float>XorStr("friendred");
	friendgreen = cfg.getValueOfKey<float>XorStr("friendgreen");
	friendblue = cfg.getValueOfKey<float>XorStr("friendblue");
	friendalpha = cfg.getValueOfKey<float>XorStr("friendalpha");
	glowweapon = cfg.getValueOfKey <bool>XorStr("glowweapon");
	weaponred = cfg.getValueOfKey<float>XorStr("weaponred");
	weapongreen = cfg.getValueOfKey<float>XorStr("weapongreen");
	weaponblue = cfg.getValueOfKey<float>XorStr("weaponblue");
	weaponalpha = cfg.getValueOfKey<float>XorStr("weaponalpha");
	glownade = cfg.getValueOfKey <bool>XorStr("glownade");
	nadered = cfg.getValueOfKey<float>XorStr("nadered");
	nadegreen = cfg.getValueOfKey<float>XorStr("nadegreen");
	nadeblue = cfg.getValueOfKey<float>XorStr("nadeblue");
	nadealpha = cfg.getValueOfKey<float>XorStr("nadealpha");

	delaypistol = cfg.getValueOfKey<int>XorStr("delaypistol");
	delayrifle = cfg.getValueOfKey<int>XorStr("delayrifle");
	delaysniper = cfg.getValueOfKey<int>XorStr("delaysniper");
	delaypumpgun = cfg.getValueOfKey<int>XorStr("delayshotgun");

	rcsstartshot = cfg.getValueOfKey<int>XorStr("rcsstartshot");
	rcsstrengh = cfg.getValueOfKey<float>XorStr("rcsstrengh");

	aimbotfovread = cfg.getValueOfKey<float>XorStr("aimbotfov");
	aimnextafterdeath = cfg.getValueOfKey<bool>XorStr("aimnextafterdeath");
	alwaysaimatclosest = cfg.getValueOfKey<bool>XorStr("alwaysaimatclosest");
	bone = cfg.getValueOfKey<float>XorStr("bone");


	text();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}


void shutdown() {

	
	if (Radar || Bhop || Noflash || Glow || Trigger || RCS)
	{
		Radar = false;
		Bhop = false;
		Noflash = false;
		Glow = false;
		Trigger = false;
		RCS = false;

	}
	else if (!Radar && !Bhop && !Nohands && !Noflash && !Glow && !Trigger && !RCS)
	{
		Radar = true;
		Bhop = true;
		Noflash = true;
		Glow = true;
		Trigger = true;
		RCS = true;

	} 

	


		
}





void CChecker::Act()
{
	g_pColor->printColor(XorStr(" [>| Backgroundchecker wurde erfolgreich geladen. "), CC_RED, CC_WHITE);

	while (true)
	{
		HWND hWindow = FindWindowA(0, XorStr("Counter-Strike: Global Offensive"));
		HWND actualwindow = GetForegroundWindow();


		if (GetAsyncKeyState(VK_NUMPAD9)) {
			Radar = !Radar;
			text();
		}


		if (GetAsyncKeyState(VK_NUMPAD8)) {
			Bhop = !Bhop;
			text();
		}
		
		if (GetAsyncKeyState(VK_NUMPAD7)) {
			Nohands = !Nohands;
			text();
		}

		if (GetAsyncKeyState(VK_NUMPAD6)) {
			Noflash = !Noflash;
			text();
		}


		if (GetAsyncKeyState(VK_NUMPAD5)) {
			Glow = !Glow;
			text();
		}


		if (GetAsyncKeyState(VK_NUMPAD4)) {
			Trigger = !Trigger;
			text();
		}


		if (GetAsyncKeyState(VK_NUMPAD3)) {
			RCS = !RCS;
			text();
		}
		

		if (GetAsyncKeyState(VK_NUMPAD2)) {
			Aimbot = !Aimbot;
			text();

		}


		if (hWindow == actualwindow) { 
			Active = true;

			if (!output) {

				text();

				output = true;
			}
		}
		else { Active = false; }

		if (g_pLocalplayer->getGamestate() == SIGNONSTATE_FULL) {
			Loaded = true;
		}
		else { Loaded = false; }

		if (GetAsyncKeyState(VK_INSERT)) {

			shutdown();
		}

		if (GetAsyncKeyState(VK_F11)) {

			ReadConfigurationWhileStarted();
		}


	}
 

}


/* Gibt an, ob eine Funktion de-/aktiviert ist. Ziemlich Dirty und könnte man über extern weitaus besser umsetzen! */

bool CChecker::GetBhop() { return Bhop;	}

bool CChecker::GetRadar() { return Radar; }

bool CChecker::GetNohands() { return Nohands; }

bool CChecker::GetNoflash() { return Noflash; }

bool CChecker::GetGlow() { return Glow; }

bool CChecker::GetTrigger() { return Trigger; }

bool CChecker::GetRCS() { return RCS; }

bool CChecker::getActive() { return Active; }

bool CChecker::getLoaded() { return Loaded; }

bool CChecker::getEnemyglow() { return glowenemy; }

bool CChecker::getFriendglow() { return glowfriend; }

bool CChecker::getWeaponglow() { return glowweapon; }

bool CChecker::getNadeglow() { return glownade; }

bool CChecker::getAimbot() { return Aimbot; }

bool CChecker::AimNext() { return aimnextafterdeath; }

bool CChecker::AimClosest() { return alwaysaimatclosest; }




float CChecker::enemyglowvalues(int i) {


	if (i == 0) { return enemyred; }
	if (i == 1) { return enemygreen; }
	if (i == 2) { return enemyblue; }
	if (i == 3) { return enemyalpha; }
	else { return 0; }
}

float CChecker::friendglowvalues(int i) {

	if (i == 0) { return friendred; }
	if (i == 1) { return friendgreen; }
	if (i == 2) { return friendblue; }
	if (i == 3) { return friendalpha; }
	else { return 0; }
}

float CChecker::weaponglowvalues(int i) {

	if (i == 0) { return weaponred; }
	if (i == 1) { return weapongreen; }
	if (i == 2) { return weaponblue; }
	if (i == 3) { return weaponalpha; }
	else { return 0; }
}

float CChecker::nadeglowvalues(int i) {


	if (i == 0) { return nadered; }
	if (i == 1) { return nadegreen; }
	if (i == 2) { return nadeblue; }
	if (i == 3) { return nadealpha; }
	else { return 0; }
}

int CChecker::triggerdelay(int i) {

	if (i == 1) { return delaypistol; }
	if (i == 2) { return delayrifle; }
	if (i == 3) { return delaysniper; }
	if (i == 4) { return delaypumpgun; }
	else { return 0; }
}


int CChecker::rcsvalues(int i) {

	if (i == 1) { return rcsstartshot; }
	else { return 1; }
}

float CChecker::rcsvalues2(int i) {
	
	if (i == 1) { return rcsstrengh; }
	else { return 2; }
}

float CChecker::aimbotvalues(int i) {

	if (i == 1) { return aimbotfov; }
	if (i == 2) { return bone; }

}



CChecker* g_pChecker = new CChecker();