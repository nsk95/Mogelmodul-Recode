#pragma once

#include <string>
#include <sstream>
#include <map>
#include <fstream>
#include <iostream>



class CChecker {

public:
	

	void ReadConfiguration();

	static void Act();

	bool GetBhop();

	bool GetRadar();

	bool GetNohands();

	bool GetNoflash();

	bool GetGlow();

	bool GetTrigger();

	bool GetRCS();

	bool getActive();

	bool getLoaded();

	bool getEnemyglow();

	bool getFriendglow();

	bool getWeaponglow();

	bool getNadeglow();

	bool getAimbot();

	bool AimNext();

	bool AimClosest();

	float enemyglowvalues(int i);

	float friendglowvalues(int i);

	float weaponglowvalues(int i);

	float nadeglowvalues(int i);

	int triggerdelay(int i);

	int rcsvalues(int i);

	float rcsvalues2(int i);

	float aimbotvalues(int i);





};

extern CChecker* g_pChecker;