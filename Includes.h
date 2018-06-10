#pragma once

#include <iostream>

#include <string>

#include <thread>

#include <chrono>

#include <sstream>

#include <Windows.h>

#include <WinUser.h>

#include <process.h>

#include <VersionHelpers.h>

#include <algorithm>

#include <TlHelp32.h>

#include <math.h>

#include <vector>

#include "stdafx.h"

#include "Offsets.h"

#include "ConsoleColors.h"

#include "XOR.h"

#include "CChecker.h"

#include "CMemory.h"

#define NOMINNMAX
#define M_PI 3,1415926535897932384f
#define RAD2DEG( x  )  ( (float)(x) * (float)(180.f / M_PI) )
#define DEG2RAD( x  ) ( (float)(x) * (float)(M_PI / 180.f) )

typedef struct {
	float x, y, z;
}Vector3D;



namespace Angles {

	

	void CalcAngle(Vector3D src, Vector3D dst, Vector3D &angles)
	{
		double delta[3] = { (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
		double hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
		angles.x = (float)(asinf(delta[2] / hyp) * 57.295779513082f);
		angles.y = (float)(atanf(delta[1] / delta[0]) * 57.295779513082f);
		angles.z = 0.0f;
		if (delta[0] >= 0.0) { angles.y += 180.0f; }
	}


	Vector3D GetPosition()
	{
		Vector3D position;
		position =  g_pMemory->Read<Vector3D>(g_pLocalplayer->getLocal() + Offsets::netvars::m_vecOrigin);
		return position;
	}

	
	Vector3D GetEyePosition()
	{
		Vector3D eyePosition;

			eyePosition = GetPosition();
			eyePosition.z +=g_pMemory->Read<Vector3D>(g_pLocalplayer->getLocal() + Offsets::netvars::m_vecViewOffset).z;
		
	}

	void AngleVectors(const Vector3D &angles, Vector3D *forward)
	{
		float    sp, sy, cp, cy;


		
		sy = sin(angles.y * 4.0 * atan(1.0) / 180.0);
		cy = cos(angles.y * 4.0 * atan(1.0) / 180.0);
		sp = sin(angles.x * 4.0 * atan(1.0) / 180.0);
		cp = cos(angles.x * 4.0 * atan(1.0) / 180.0);


		forward->x = cp * cy;
		forward->y = cp * sy;
		forward->z = -sp;
	}


	Vector3D getViewAngles()
	{

		 g_pMemory->Read<Vector3D>(g_pLocalplayer->getClientstate() + Offsets::signatures::dwClientState_ViewAngles);
		

	}

	float GetFov(const Vector3D& viewAngle, const Vector3D& aimAngle)
	{
		Vector3D ang, aim;

		AngleVectors(viewAngle, &aim);
		AngleVectors(aimAngle, &ang);

		return RAD2DEG( acos(Dot(ang) / LengthSqr()) );
	}

	


}