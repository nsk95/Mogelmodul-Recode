#include "Includes.h"


bool CMemory::Intialize()
{

	HWND hWindow = FindWindowA(0, XorStr("Counter-Strike: Global Offensive"));
	if (!hWindow) { return false; }

	DWORD dwProcessID = 0;

	if (!GetWindowThreadProcessId(hWindow, &dwProcessID)) { return false; }

	HANDLE hlProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwProcessID);


	if (hlProcess == INVALID_HANDLE_VALUE) { return false; }


	this->m_hWindow = hWindow;

	this->m_dwPid = dwProcessID;

	this->m_hlHandle = hlProcess;

	uint32_t client, engine = 0;

	client = this->getBaseAddress(XorStr("client.dll"));

	if (client == 0) { return false; }

	engine = this->getBaseAddress(XorStr("engine.dll"));

	if (engine == 0) { return false; }


	this->uiClientAddress = client;

	this->uiEngineAddress = engine;


	return true;
}

uint32_t CMemory::getBaseAddress(const std::string & name)
{
	uint32_t baseAddress = 0;

	MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };

	std::wstring wstrTemp = L"";

	std::string strTemp = "";

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, this->m_dwPid);

	if (hSnap == INVALID_HANDLE_VALUE) { return 0; }


	if (Module32First(hSnap, &me32)) {

		do {

			wstrTemp = std::wstring(me32.szModule);

			strTemp = std::string(wstrTemp.begin(), wstrTemp.end());

			if (strTemp == name) {

				baseAddress = (uint32_t)me32.modBaseAddr;
			}

		} while (Module32Next(hSnap, &me32));

	}

	CloseHandle(hSnap);

	return baseAddress;
}



CMemory* g_pMemory = new CMemory();