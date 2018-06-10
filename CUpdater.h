#pragma once

class CUpdater {

public:


	static void Act();

	static void Read();

	static void Download();
};

extern CUpdater* g_pUpdater;