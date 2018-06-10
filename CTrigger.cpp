#include "Includes.h"

#include "CTrigger.h"

#include "CLocalplayer.h"

#include "CEntity.h"



void CTrigger::Act()
{
	Sleep(10);

	g_pColor->printColor(XorStr(" [>| Trigger wurde erfolgreich geladen. "), CC_RED, CC_WHITE);

	

	while (true)
	{
		if (g_pChecker->GetTrigger() && g_pLocalplayer->fullload() )
		{
			
			if ((GetAsyncKeyState(VK_XBUTTON2) & 0x8000))
			{
				if (g_pLocalplayer->InCross() > 0 && g_pLocalplayer->InCross() <= 64)
				{
					if (g_pLocalplayer->TriggerEntityBaseTeamID() != NULL)
					{
						if (g_pLocalplayer->TriggerEntityBaseTeamID() != g_pLocalplayer->LocalPlayerTeam())
						{

							if (g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 1) // Pistol 
							{
								Sleep(g_pChecker->triggerdelay(1));
								g_pLocalplayer->Shoot2();
							}

							if (g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 2) // Rifle/SMG 
							{
								Sleep(g_pChecker->triggerdelay(2));
								g_pLocalplayer->Shoot2();
							}

							if (g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 3) // Sniper 
							{
								Sleep(g_pChecker->triggerdelay(3));
								g_pLocalplayer->Shoot();
							}

							if (g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 4) // Shotgun 
							{
								Sleep(g_pChecker->triggerdelay(4));
								g_pLocalplayer->Shoot();
							}
							
							



						}
					}
				}

			}



		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

	} //While-Ende

}




CTrigger* g_pTrigger = new CTrigger();