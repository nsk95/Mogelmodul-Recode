#include "Includes.h"

#include "CRCS.h"

#include "CLocalplayer.h"

#include "CEntity.h"



typedef struct {
	float x, y, z;
}Vector;



Vector vPunch;
float rcsAmount;
Vector ViewAngles;
Vector CurrentViewAngles;
Vector NewViewAngles;
Vector OldAimPunch;



const Vector getViewAngles()  {

	return g_pMemory->Read< Vector >(g_pLocalplayer->getClientstate() + Offsets::signatures::dwClientState_ViewAngles);
}

namespace math {
	/* Normalizierung der Angles (um invalid Angles zu vermeiden) */
	void normalize_angles(Vector& v)
	{

		while (v.x > 180.f)
			v.x -= 360.0f;

		while (v.x < -180.0f)
			v.x += 360.0f;

		while (v.y > 180.0f)
			v.y -= 360.0f;

		while (v.y < -180.0f)
			v.y += 360.0f;

		while (v.z > 180.0f)
			v.z -= 360.0f;

		while (v.z < -180.0f)
			v.z += 360.0f;


	}

	/* Clampen um out of range angles zu vermeiden(UT)*/
	void clamp_angles(Vector& v)
	{
		if (v.x != v.x)
			v.x = 0.0f;

		if (v.y != v.y)
			v.y = 0.0f;

		if (v.z != v.z)
			v.z = 0.0f;

		if (v.x > 89.0f)
			v.x = 89.0f;

		else if (v.x < -89.0f)
			v.x = -89.0f;

		if (v.y > 180.0f)
			v.y = 180.0f;

		else if (v.y < -180.0f)
			v.y = -180.0f;

		v.z = 0;

	}


}








void CRCS::Act()
{
	Sleep(10);

	g_pColor->printColor(XorStr(" [>| RCS wurde erfolgreich geladen. "), CC_RED, CC_WHITE);


	while (true)
	{
		if (g_pChecker->GetRCS() && g_pLocalplayer->fullload() )
		{
			

			
			if ( g_pLocalplayer->get_weapongroup(g_pLocalplayer->WeaponID()) == 2 )
			{

				if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
				{
					if (g_pLocalplayer->Shotsfired() > g_pChecker->rcsvalues(1))
					{

						CurrentViewAngles = getViewAngles();
						vPunch = g_pMemory->Read<Vector>((g_pLocalplayer->getLocal() + Offsets::netvars::m_aimPunchAngle));

						vPunch.x /= g_pChecker->rcsvalues2(1);
						vPunch.y /= g_pChecker->rcsvalues2(1);

						NewViewAngles.x = (CurrentViewAngles.x + OldAimPunch.x) - vPunch.x * 2.f;
						NewViewAngles.y = (CurrentViewAngles.y + OldAimPunch.y) - vPunch.y * 2.f;


						OldAimPunch.x = vPunch.x * 2.f;
						OldAimPunch.y = vPunch.y * 2.f;
						


						
						math::normalize_angles(NewViewAngles);
						math::clamp_angles(NewViewAngles);

						g_pMemory->Write< Vector >(g_pLocalplayer->getClientstate() + Offsets::signatures::dwClientState_ViewAngles, NewViewAngles);

					}
					
					else {
						vPunch = g_pMemory->Read<Vector>((g_pLocalplayer->getLocal() + Offsets::netvars::m_aimPunchAngle));
						vPunch.x /= g_pChecker->rcsvalues2(1);
						vPunch.y /= g_pChecker->rcsvalues2(1);
						OldAimPunch.x = vPunch.x * 2.f;
						OldAimPunch.y = vPunch.y * 2.f;
					}

				}
			}


			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		} //While-Ende

	}
}



CRCS* g_pRCS = new CRCS();