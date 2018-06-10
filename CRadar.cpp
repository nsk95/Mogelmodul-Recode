#include "Includes.h"

#include "CRadar.h"

#include "CLocalplayer.h"

#include "CEntity.h"

#include "CRadar.h"



void CRadar::Act()
{
	Sleep(100);
	g_pColor->printColor(XorStr(" [>| Radar wurde erfolgreich geladen. "), CC_RED, CC_WHITE);

	uint32_t Entity = 0;

	int EntityHealth = 0;

	int EntityTeam = 0;

	while (true) {

		if (g_pChecker->GetRadar() && g_pLocalplayer->fullload() )
		{
			for (int i = 1; i < 65; i++)
			{
				Entity = g_pEntity->getEntityByIndex(i);

				if (!Entity)
				{
					Sleep(1);

					continue;
				}

				EntityHealth = g_pEntity->getHealth2(&Entity);

				EntityTeam = g_pEntity->getTeam2(&Entity);

				if (EntityTeam == g_pLocalplayer->LocalPlayerTeam())
				{
					Sleep(1);

					continue;
				}

				if (EntityHealth <= 0 || EntityHealth > 100) {

					Sleep(1);

					continue;
				}

				g_pMemory->Write< int >(Entity + Offsets::netvars::m_bSpotted, 1);
			}

			
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));

	}
}

CRadar* g_pRadar = new CRadar();