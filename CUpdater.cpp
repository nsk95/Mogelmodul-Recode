#include "Includes.h"
#include "CUpdater.h"
#include <fstream>
#include <urlmon.h>
#include <tchar.h>
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib,"wininet.lib")
#include <wininet.h>
#include <shlobj.h> 

std::string curver = (XorStr("2.0"));


void CUpdater::Act()
{
	g_pColor->printColor(XorStr(" [>] ...."), CC_RED, CC_WHITE);
	Download();
	Read();


}

void CUpdater::Read()
{
	std::string version;
	std::ifstream file(XorStr("C:\\version.txt")); 

	if (file.is_open())
	{
		std::getline(file, version);

	}

	else {
		g_pColor->printColor(XorStr(" [>] Datei konnte nicht geöffnet werden."), CC_RED, CC_WHITE);

	}

	if (version > curver)
	{
		g_pColor->printColor(XorStr(" [>] Neuere Version gefunden. \n [>] Wird heruntergeladen.\n"), CC_RED, CC_WHITE);

		HRESULT gr = URLDownloadToFile(NULL, _T("LINKZUREXE.EXE"), _T("C:\\Mogelmodulv2.0.exe"), 0, NULL);
		g_pColor->printColor(XorStr(" [>] Die neue Version befindet sich in C:/"), CC_RED, CC_WHITE);

		if (SUCCEEDED(gr)) {


			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));
			if (!CreateProcess
				(
					TEXT("C:\\Mogelmodulv2.0.exe"),
					NULL, NULL, NULL, FALSE,
					CREATE_NEW_CONSOLE,
					NULL, NULL,
					&si,
					&pi
				)
				);

		}

		if (FAILED(gr)) { g_pColor->printColor(XorStr(" [>] Download war nicht erfolgreich."), CC_RED, CC_WHITE);
		}

	}

	else { 
		 g_pColor->printColor(XorStr(" [>] Keine neuere Version gefunden\n"), CC_RED, CC_WHITE);
	}
	Sleep(5000);
	system("cls");

}



void CUpdater::Download()
{

	HRESULT hr = URLDownloadToFile(NULL, _T("LINKZURVERSIONTXT"), _T("C:\\version.txt"), 0, NULL);
	
}



CUpdater* g_pUpdater = new CUpdater();