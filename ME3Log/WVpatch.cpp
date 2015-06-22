#include "WVpatch.h"

BYTE pattern[] = { 0x8B, 0x11, 0x8B, 0x42, 0x0C,
0x57, 0x56, 0xFF, 0xD0,
0x8B, 0xC3, // <-- move eax,ebx; offset 0x9; will be replaced with 0xB0 0x01 to get mov al,1;
0x8B, 0x4D, 0xF4, 0x64,
0x89, 0x0D, 0x00, 0x00, 0x00,
0x00, 0x59, 0x5F, 0x5E, 0x5B,
0x8B, 0xE5, 0x5D, 0xC2, 0x08,
0x00, 0xCC, 0xCC, 0xCC, 0x8B,
0x41, 0x04, 0x56, 0x85, 0xC0 };
BYTE pattern2[] = {
	0x8B, 0x45, 0x0C,                       // mov     eax, [ebp+arg_4]
	0xC7, 0x00, 0x01, 0x00, 0x00, 0x00,     // mov     dword ptr [eax], 1
	0x5D,                                   // pop     ebp
	0xC2, 0x08, 0x00,                       // retn    8
	0x8B, 0x4D, 0x0C,                       // mov     ecx, [ebp+arg_4]
	0xC7, 0x01, 0x01, 0x00, 0x00, 0x00,     // mov     dword ptr [ecx], 1
	0x5D,                                   // pop     ebp
	0xC2, 0x08, 0x00,                       // retn    8
	0xCC, 0xCC, 0xCC, 0xCC, 0xCC
};


bool DataCompare(const BYTE* OpCodes, const BYTE* Mask, const char* StrMask)
{
	while (*StrMask)
	{
		if (*StrMask == 'x' && *OpCodes != *Mask)
			return false;
		++StrMask;
		++OpCodes;
		++Mask;
	}
	return true;
}

DWORD FindPattern(DWORD StartAddress, DWORD CodeLen, BYTE* Mask, char* StrMask, unsigned short ignore)
{
	unsigned short Ign = 0;
	DWORD i = 0;
	while (Ign <= ignore)
	{
		if (DataCompare((BYTE*)(StartAddress + i++), Mask, StrMask))
			++Ign;
		else if (i >= CodeLen)
			return 0;
	}
	return StartAddress + i - 1;
}

void WVPatchChecks()
{
	FILE* WVLog;
	fopen_s(&WVLog, "binkw32log.txt", "w");
	fprintf(WVLog, "Autopatcher by Warranty Voider\n");

	DWORD patch1, patch2;
	int count = 0;
	while ((patch1 = FindPattern(0x401000, 0xE52000, pattern, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 0)) == 0 && count++ < 10)
	{
		fprintf(WVLog, "Trying again...\n");
		Sleep(300);
	}
	if (patch1 != 0)
	{
		fprintf(WVLog, "Patch position 1: 0x%x\n", patch1);
		DWORD dwProtect;
		VirtualProtect((void*)(patch1 + 9), 0x2, PAGE_READWRITE, &dwProtect);
		BYTE* p = (BYTE *)(patch1 + 9);
		*p++ = 0xB0;
		*p = 0x01;
		VirtualProtect((void*)(patch1 + 9), 0x2, dwProtect, &dwProtect);
		fprintf(WVLog, "Patch position 1: Patched\n");
	}
	count = 0;
	while ((patch2 = FindPattern(0x401000, 0xE52000, pattern2, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 0)) == 0 && count++ < 10)
	{
		fprintf(WVLog, "Trying again...\n");
		Sleep(300);
	}
	if (patch2 != 0)
	{
		fprintf(WVLog, "Patch position 2: 0x%x\n", patch2);
		DWORD dwProtect;
		VirtualProtect((void*)patch2, 0x16, PAGE_READWRITE, &dwProtect);
		BYTE* p = (BYTE *)(patch2 + 5);
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p = 0;
		p = (BYTE *)(patch2 + 0x12);
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p = 0;
		VirtualProtect((void*)patch2, 0x16, dwProtect, &dwProtect);
		fprintf(WVLog, "Patch position 2: Patched\n");
	}

	fflush(WVLog);
	fclose(WVLog);
}