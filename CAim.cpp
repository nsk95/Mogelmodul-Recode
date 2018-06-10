#include "CLocalplayer.h"

#include "CEntity.h"

#include "Includes.h"

#include "Vector3.h"

#include "CAim.h"


using namespace Angles;

void CAim::Act()
{


	g_pColor->printColor(XorStr(" [>| Aimbot wurde erfolgreich geladen. "), CC_RED, CC_WHITE);

	while (true) {

		if (g_pLocalplayer->fullload())
		{

			if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) && g_pChecker->getAimbot()) {

				
				for (int entity = 1; entity <= 64; entity++)
				{

					if (entity == g_pLocalplayer->getLocal() || g_pEntity->getTeam(entity) == g_pLocalplayer->LocalPlayerTeam() )
					{
						continue;
					}

					if (g_pLocalplayer->getEntityHealth(entity) == 0)
					{
						continue;
					}

					Vector3D enemybone = g_pEntity->getBonePos(entity, 6);

					if (enemybone.x && enemybone.y && enemybone.z == 0 )
					{
						continue;
					}

					Vector3D eyeposition = GetEyePosition();
					
					Vector3D aimangle;
					CalcAngle(eyeposition, enemybone, aimangle);




				}


			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));


		}
	}
}







