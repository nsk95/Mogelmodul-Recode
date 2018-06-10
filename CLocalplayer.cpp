#include "Includes.h"

#include "CLocalplayer.h"

#include <vector>

#include <unordered_set>


typedef struct {
	float x, y, z;
}Vector;

uint32_t CLocalplayer::getLocal()
{
	return g_pMemory->Read< uint32_t >(g_pMemory->getClientAddress() + Offsets::signatures::dwLocalPlayer);
}

int CLocalplayer::getFlags()
{
	return g_pMemory->Read< int >(this->getLocal() + Offsets::netvars::m_fFlags);
}

int CLocalplayer::getHealth()
{
	return g_pMemory->Read< int >(this->getLocal() + Offsets::netvars::m_iHealth);
}

int CLocalplayer::getEntityHealth( int entity )
{
	return g_pMemory->Read< int >(entity + Offsets::netvars::m_iHealth);
}




void CLocalplayer::doJump()
{

	g_pMemory->Write< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwForceJump, 6);

}

int CLocalplayer::GetEngineState()
{

	return g_pMemory->Read< int >(g_pMemory->getEngineAddress() + Offsets::signatures::dwClientState);
}

void CLocalplayer::doStrafe()
{
	DWORD EngineState = GetEngineState();
	static Vector prevViewAngle;
	Vector currentViewAngles = g_pMemory->Read<Vector>(EngineState + Offsets::signatures::dwClientState_ViewAngles);
	
	if (!(g_pLocalplayer->getFlags() & 1))
	{ 

		if (currentViewAngles.y > prevViewAngle.y)
		{
			g_pMemory->Write< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwForceLeft, 6);
		}
		else if (currentViewAngles.y < prevViewAngle.y)
		{
			g_pMemory->Write< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwForceRight, 6);
		}

		prevViewAngle = currentViewAngles;

	}

}



//Radar-Start
int CLocalplayer::CurrentPlayer()
{
	return 0;
}

int CLocalplayer::CurrentPlayerDormant()
{
	return g_pMemory->Read< int >(this->CurrentPlayer() + 0xE9);
}

int CLocalplayer::CurrentPlayerSpotted()
{
	return g_pMemory->Read< int >(this->CurrentPlayer() + Offsets::netvars::m_bSpotted);
}

void CLocalplayer::doRadar()
{
	return g_pMemory->Write< int >(this->CurrentPlayer() + Offsets::netvars::m_bSpotted, 1);
}

//Radar-Ende

//Trigger-Start

int CLocalplayer::LocalPlayerTeam()
{
	return g_pMemory->Read< int >(this->getLocal() + Offsets::netvars::m_iTeamNum);
}

int CLocalplayer::GetEntityTeam(int entity)
{
	return g_pMemory->Read< int >(entity + Offsets::netvars::m_iTeamNum);
}

int CLocalplayer::InCross()
{
	return g_pMemory->Read< int >(this->getLocal() + Offsets::netvars::m_iCrosshairId);
}

int CLocalplayer::TriggerEntityBase()
{
	return g_pMemory->Read< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwEntityList + (this->InCross() - 1) * 16);
}

int CLocalplayer::TriggerEntityBaseTeamID()
{
	return g_pMemory->Read< int >(this->TriggerEntityBase() + Offsets::netvars::m_iTeamNum);
}

int CLocalplayer::WeaponIndex()
{
	return g_pMemory->Read< int >(this->getLocal() + Offsets::netvars::m_hActiveWeapon) & 0XFFF;
}

int CLocalplayer::WeaponEntity()
{
	return g_pMemory->Read< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwEntityList + (this->WeaponIndex() - 1) * 0x10);
}

int CLocalplayer::WeaponID()
{
	return g_pMemory->Read< int >(this->WeaponEntity() + Offsets::netvars::m_iItemDefinitionIndex);
}

void CLocalplayer::Shoot()
{


	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(2);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

}

void CLocalplayer::Shoot2()
{

	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

}

//Trigger-Ende

//NoFlash-Start

float CLocalplayer::FlashMaxAlpha()
{
	return	g_pMemory->Read< float >(this->getLocal() + Offsets::netvars::m_flFlashMaxAlpha);
}

void CLocalplayer::notflashed()
{
	g_pMemory->Write< float >(g_pLocalplayer->getLocal() + Offsets::netvars::m_flFlashMaxAlpha, 0.f);

}

//NoFlash-Ende

//Glow

std::uintptr_t CLocalplayer::getGlowObjectManager() const {

	return g_pMemory->Read< std::uintptr_t >(g_pMemory->getClientAddress() + Offsets::signatures::dwGlowObjectManager);
}


int CLocalplayer::getClientstate() {

 return g_pMemory->Read< int >(g_pMemory->getEngineAddress() + Offsets::signatures::dwClientState);

}

int CLocalplayer::getGamestate() {

	return g_pMemory->Read< int >(this->getClientstate() + Offsets::signatures::dwClientState_State);

}


int CLocalplayer::Shotsfired() {

	return	g_pMemory->Read<int>(g_pLocalplayer->getLocal() + Offsets::netvars::m_iShotsFired);
}


std::unordered_set<int> pistol = { 1,2,3,4,30,32,36,61,63,64 };
std::unordered_set<int> rifles = { 7, 8, 10, 13, 14, 16, 60, 17, 19, 24, 26, 27, 28, 33, 34, 39 };
std::unordered_set<int> sniper = { 40,9,38,11 };
std::unordered_set<int> shotgun = { 35,25,39,27 };

int CLocalplayer::get_weapongroup(int i ) {


	if (pistol.find(i) != pistol.cend()) { return 1; }
	else if (rifles.find(i) != rifles.cend()) { return 2; }
	else if (sniper.find(i) != sniper.cend()) { return 3; }
	else if (shotgun.find(i) != shotgun.cend()) { return 4; }

}


bool CLocalplayer::fullload() {

	if (g_pLocalplayer->getGamestate() == SIGNONSTATE_FULL && g_pChecker->getActive() ) { return true; }
	else { return false; }

}


int CLocalplayer::gettickbase() {

	int tickbase = g_pMemory->Read<int>(g_pLocalplayer->getLocal() + Offsets::netvars::m_nTickBase);
	return tickbase;

}


uintptr_t CLocalplayer::baseglobalvars() {

	uintptr_t globalvars = g_pMemory->Read<uintptr_t>(g_pMemory->getEngineAddress() + Offsets::signatures::dwGlobalVars);
	return globalvars;

}

float CLocalplayer::intervalpertrick() {

	float intervalpertick = g_pMemory->Read<float>(g_pLocalplayer->baseglobalvars() + 32);
	return intervalpertick;
}

float CLocalplayer::getservertime() {

	float servertime = (g_pLocalplayer->gettickbase() + g_pLocalplayer->intervalpertrick());
	return servertime;
}

float CLocalplayer::nextattack() {

	float nextattack = g_pMemory->Read<float>(g_pLocalplayer->getLocal() + Offsets::netvars::m_flNextPrimaryAttack);
	return nextattack;

}

CLocalplayer* g_pLocalplayer = new CLocalplayer();