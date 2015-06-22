#include <windows.h>
#include <stdio.h>
#include "Binkw32.h"
#include "WVpatch.h"

#pragma pack(1)

HINSTANCE hLib;

FILE* Log;

// Mimicked function declaration to make the compiler generate the correct var_arg asm for us:
void __cdecl LogPrintf(int dummy, wchar_t* pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);
	vfwprintf(Log, pFormat, args);
	fprintf(Log, "\n");
	fflush(Log);
	va_end(args);
}

void DetourPrintFunction()
{
	BYTE *BioDiagnosticPrintf = (BYTE *)0x00467920;

	DWORD OriginalProtection;
	VirtualProtect(BioDiagnosticPrintf, 0x5, PAGE_READWRITE, &OriginalProtection);

	// calculate relative jump offset
	DWORD JmpOffset = (DWORD)((DWORD)LogPrintf - (DWORD)BioDiagnosticPrintf) - 5;

	*BioDiagnosticPrintf = 0xE9;					// write the long relative jmp
	memcpy(BioDiagnosticPrintf + 1, &JmpOffset, 4); // copy the destination adress

	VirtualProtect(BioDiagnosticPrintf, 0x5, OriginalProtection, &OriginalProtection);
}

DWORD WINAPI Start(LPVOID lpParam)
{
	// Start the debug logging.
	fopen_s(&Log, "ME3Log.txt", "w");
	fprintf(Log, "ME3Log - Logging started.\n");
	fflush(Log);

	DetourPrintFunction();

	// Set up the DLL forwarding
	hLib = InitLibBinkw32();

	// WV's patcher still included for now
	WVPatchChecks();

	return 0;
}

void Cleanup()
{
	FreeLibrary(hLib);

	fprintf(Log, "Shutting down, clean exit.\n");
	fclose(Log);
}

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DWORD dwThreadId, dwThrdParam = 1;
		HANDLE hThread;
		hThread = CreateThread(NULL, 0, Start, &dwThrdParam, 0, &dwThreadId);
	}
	if (reason == DLL_PROCESS_DETACH)
	{
		Cleanup();
	}

	return 1;
}

