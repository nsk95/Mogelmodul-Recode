#pragma once

#include <Windows.h>

#include <cstdint>


enum eSignonState {
	SIGNONSTATE_NONE = 0,
	SIGNONSTATE_CHALLENGE = 1,
	SIGNONSTATE_CONNECTED = 2,
	SIGNONSTATE_NEW = 3,
	SIGNONSTATE_PRESPAWN = 4,
	SIGNONSTATE_SPAWN = 5,
	SIGNONSTATE_FULL = 6,
	SIGNONSTATE_CHANGELEVEL = 7
};

class CLocalplayer {

public:

	uint32_t getLocal();

	int getFlags();

	int getHealth();

	int getEntityHealth(int entity);

	void doJump();

	int GetEngineState();

	void doStrafe();

	int CurrentPlayer();

	int CurrentPlayerDormant();

	int CurrentPlayerSpotted();

	void doRadar();

	int LocalPlayerTeam();

	int GetEntityTeam(int entity);

	int InCross();

	int TriggerEntityBase();

	int TriggerEntityBaseTeamID();

	int WeaponIndex();

	int WeaponEntity();

	int WeaponID();

	void Shoot();

	void Shoot2();

	float FlashMaxAlpha();

	void notflashed();

	std::uintptr_t getGlowObjectManager() const;

	int getClientstate();

	int getGamestate();

	int Shotsfired();

	int get_weapongroup(int i);

	bool fullload();

	int gettickbase();

	uintptr_t baseglobalvars();

	float intervalpertrick();

	float getservertime();

	float nextattack();




};

extern CLocalplayer* g_pLocalplayer;