#include "Includes.h"

#include "CEntity.h"

#include "CGlow.h"

#include "CLocalplayer.h"

CEntity* g_pEntity = new CEntity();

uint32_t CEntity::getEntityByIndex(unsigned __int8 index)
{
	return g_pMemory->Read< uint32_t >(g_pMemory->getClientAddress() + Offsets::signatures::dwEntityList + (index - 1) * 16);
}

int CEntity::getHealth( std::uintptr_t entity )
{
	return g_pMemory->Read< int >(entity + Offsets::netvars::m_iHealth);
}

int CEntity::getTeam( std::uintptr_t entity )
{
	return g_pMemory->Read< uint32_t >( entity + Offsets::netvars::m_iTeamNum);


}



Vector3D CEntity::getBonePos(int entity, int boneid)
{
	Vector3D bone;
	DWORD BoneP = g_pMemory->Read<DWORD>(entity + Offsets::netvars::m_dwBoneMatrix);
	
	bone.x = g_pMemory->Read<float>(BoneP + (0x30 * boneid) + 0x0C);
	bone.y = g_pMemory->Read<float>(BoneP + (0x30 * boneid) + 0x1C);
	bone.z = g_pMemory->Read<float>(BoneP + (0x30 * boneid) + 0x2C);

	return bone;
}

int CEntity::getClassID(std::uintptr_t entity) const {

	return g_pMemory->Read< int >(g_pMemory->Read< int >(g_pMemory->Read< int >(g_pMemory->Read< int >(entity + 0x8) + 0x8) + 0x1) + 0x14);
}



/* Radar-rel */


int CEntity::getHealth2(const uint32_t * entity)
{
	return g_pMemory->Read< int >(*entity + Offsets::netvars::m_iHealth);
}

int CEntity::getTeam2(const uint32_t * entity)
{
	return g_pMemory->Read< uint32_t >(*entity + Offsets::netvars::m_iTeamNum);
}


/* Glow-rel */


void CEntity::setGlow(int index = 0, float red = 0.00f, float blue = 0.00f, float green = 0.00f, float alpha = 0.00f, bool a1 = false, bool a2 = false) {

	std::uintptr_t pGlowArray = g_pLocalplayer->getGlowObjectManager();


	g_pMemory->Write< float >(pGlowArray + (index * sizeof(GlowObject_t) + 0x4), red);

	g_pMemory->Write< float >(pGlowArray + (index * sizeof(GlowObject_t) + 0x8), green);

	g_pMemory->Write< float >(pGlowArray + (index * sizeof(GlowObject_t) + 0xC), blue);

	g_pMemory->Write< float >(pGlowArray + (index * sizeof(GlowObject_t) + 0x10), alpha);


	g_pMemory->Write< bool >(pGlowArray + (index * sizeof(GlowObject_t) + 0x24), a1);

	g_pMemory->Write< bool >(pGlowArray + (index * sizeof(GlowObject_t) + 0x25), a2);

}