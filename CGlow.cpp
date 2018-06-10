#include "Includes.h"
#include "CGlow.h"
#include "CEntity.h"
#include "CLocalplayer.h"
#include "CVisibleCheck.h"


void CGlow::Act()
{


	/* Start Deklaration für Glow */

	std::uintptr_t entity = 0x0;
	size_t entity_team = 0;
	size_t entity_health = 0;
	size_t local_team = 0;
	std::uintptr_t local = 0x0;
	size_t classID = 0;
	size_t glowObjects = 0;
	GlowObject_t glowObject;
	std::uintptr_t glowObjectManager = 0x0;



	/* Ende Deklaration für Glow */

	Sleep(50);
	g_pColor->printColor(XorStr(" [>| Glow wurde erfolgreich geladen. "), CC_RED, CC_WHITE);


	
		while (true) {


			if (g_pChecker->GetGlow() && g_pLocalplayer->fullload() )

			{

				local = g_pLocalplayer->getLocal();

				local_team = g_pLocalplayer->LocalPlayerTeam();

				glowObjectManager = g_pLocalplayer->getGlowObjectManager();

				if (!glowObjectManager) {

					Sleep(1);

					continue;
				}

				glowObjects = g_pMemory->Read< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwGlowObjectManager + 0xC);


				if (!glowObjects || glowObjects <= 0) {

					Sleep(1);

					continue;


				}


				for (int i = 1; i <= glowObjects; i++) {

					glowObject = g_pMemory->Read< GlowObject_t >(glowObjectManager + i * sizeof(GlowObject_t));

					entity = glowObject.pEntity;

					if (!entity || entity == local) {

						continue;
					}


					classID = g_pEntity->getClassID(entity);
					

					if (classID == CPlantedC4 || classID == CC4) {

						g_pEntity->setGlow(i, 2.f, 0.1f, 2.4f, 1.f, true, false);

						continue;
					}
					
					if (classID == 9 || classID == 41 || classID == 98 || classID == 130 || classID == 134 || classID == 66 && g_pChecker->getNadeglow() == true) { //Nades


						g_pEntity->setGlow(i, g_pChecker->nadeglowvalues(0), g_pChecker->nadeglowvalues(1), g_pChecker->nadeglowvalues(2), g_pChecker->nadeglowvalues(3), true, false);

						continue;

					}

					
					
					if (classID == 1 || classID == 39 || (classID >= 204 && classID <= 244) && g_pChecker->getWeaponglow() == true ) { //Waffen

						g_pEntity->setGlow(i, g_pChecker->weaponglowvalues(0), g_pChecker->weaponglowvalues(1), g_pChecker->weaponglowvalues(2), g_pChecker->weaponglowvalues(3), true, false);

						continue;
					}
					
					

					entity_health = g_pEntity->getHealth(entity);

					if (!entity_health || entity_health <= 0) {

						continue;
					}


					entity_team = g_pEntity->getTeam(entity);

					if (entity_team != local_team  && g_pChecker->getEnemyglow() == true) {

						g_pEntity->setGlow(i, g_pChecker->enemyglowvalues(0), g_pChecker->enemyglowvalues(1), g_pChecker->enemyglowvalues(2), g_pChecker->enemyglowvalues(3), true, false);
					}


					if (entity_team == local_team && g_pChecker->getFriendglow() == true) {

						g_pEntity->setGlow(i, g_pChecker->friendglowvalues(0), g_pChecker->friendglowvalues(1), g_pChecker->friendglowvalues(2), g_pChecker->friendglowvalues(3), true, false);
					}


					





				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		}
}