#pragma once

#include <Windows.h> // Windows Api -> OpenProcess, GetWindowThreadProcessId, FindWindow etc

#include <cstdint> // Datentypen -> uint32_t

#include <iostream> // string

class CMemory
{

public:

	/*			Constructor		*/

	CMemory()
	{
		this->m_hWindow = 0;

		this->m_dwPid = 0;

		this->m_hlHandle = 0;
	}

	CMemory(const HWND & window, const DWORD & pid, const HANDLE & handle)
	{
		this->m_hWindow = (window != 0) ? window : 0;

		this->m_dwPid = (pid != 0) ? pid : 0;

		this->m_hlHandle = (handle != INVALID_HANDLE_VALUE) ? handle : 0;
	}

	/*			Deconstructor		*/

	~CMemory()
	{
		CloseHandle(this->m_hlHandle);
	}


	/*			Getter		*/

	inline HWND getWindow() { return this->m_hWindow; }

	inline DWORD getProcessId() { return this->m_dwPid; }

	inline HANDLE getHandle() { return this->m_hlHandle; }

	inline uint32_t getClientAddress() { return this->uiClientAddress; }

	inline uint32_t getEngineAddress() { return this->uiEngineAddress; }

	/*		Functions		*/

	bool Intialize();

	uint32_t getBaseAddress(const std::string & name);

	void kdp();

	bool idp();

	template< class A >
	A Read(uint32_t Address) {

		A Buffer;

		ReadProcessMemory(this->m_hlHandle, reinterpret_cast< LPCVOID >(Address), &Buffer, sizeof(A), 0);

		return Buffer;
	}

	template< class A >
	void Write(uint32_t Address, A Value) {

		WriteProcessMemory(this->m_hlHandle, reinterpret_cast< LPVOID >(Address), &Value, sizeof(Value), 0);
	}



protected:

	/*			Setter		*/

	void setWindow(const HWND &window) { this->m_hWindow = (window != 0) ? window : this->m_hWindow; }

	void setProcessId(const DWORD &pid) { this->m_dwPid = (pid != 0) ? pid : this->m_dwPid; }

	void setHandle(const HANDLE &handle) { this->m_hlHandle = (handle != INVALID_HANDLE_VALUE) ? handle : this->m_hlHandle; }

private:

	/*			Member		*/

	HWND m_hWindow;

	DWORD m_dwPid;

	HANDLE m_hlHandle;

	uint32_t uiClientAddress;

	uint32_t uiEngineAddress;
};

extern CMemory* g_pMemory;