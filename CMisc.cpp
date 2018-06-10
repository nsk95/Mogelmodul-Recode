#include "Includes.h"

#include "CMisc.h"

#include "CLocalplayer.h"

#include "CEntity.h"


/* Radar-Deklarationen */
uint32_t Entity = 0;
int EntityHealth = 0;
int EntityTeam = 0;
/* Ende-Radar-Deklarationen */



void CMisc::forceUpdate()
{

	g_pMemory->Write< int>((g_pMemory->getEngineAddress() + Offsets::signatures::dwClientState) + 0x174, -1);

}



void CMisc::Run()
{
	Sleep(10);

	g_pColor->printColor(XorStr(" [>| BHop wurde erfolgreich geladen. "), CC_RED, CC_WHITE);

	

	while (true)
	{
		if (g_pLocalplayer->fullload())
		{
			/* Bunnyhop-Beginn */
			if (g_pChecker->GetBhop() )
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 && g_pLocalplayer->getFlags() & 1) {



					g_pLocalplayer->doJump();
					g_pLocalplayer->doStrafe();

				}



				Sleep(1);
			}
			/* Bunnyhop-Ende */

			/* NoHands-Beginn*/
			if (g_pChecker->GetNohands() )
			{
				g_pMemory->Write<int>(g_pLocalplayer->getLocal() + 0x254, 0);
				forceUpdate();

			}
			/* NoHands-Ende*/

			/* Autopistol-Beginn*/
			
				if (g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 1)
				{
					if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) /*&& g_pLocalplayer->Shotsfired() > 1*/)
						{
						if (g_pLocalplayer->nextattack() < g_pLocalplayer->getservertime())
							{
								g_pMemory->Write< int >(g_pMemory->getClientAddress() + Offsets::signatures::dwForceAttack, 6);

							}

						}

				}

			/* NoFlash-Beginn*/
			if (g_pChecker->GetNoflash() )

			{
				if (g_pLocalplayer->FlashMaxAlpha() > 0.f)
				{
					g_pLocalplayer->notflashed();
				}

			}
			/* NoFlash-Ende */

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		} //While-Ende
	}
}




CMisc* g_pMisc = new CMisc();