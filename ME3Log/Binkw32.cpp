#include "Binkw32.h"

FARPROC BinkIAT[72] = { 0 };

// Initialize library
HINSTANCE InitLibBinkw32()
{
	HINSTANCE hBinkLib = LoadLibrary(L"binkw23.dll");
	BinkIAT[0] = GetProcAddress(hBinkLib, "_BinkBufferBlit@12");
	BinkIAT[1] = GetProcAddress(hBinkLib, "_BinkBufferCheckWinPos@12");
	BinkIAT[2] = GetProcAddress(hBinkLib, "_BinkBufferClear@8");
	BinkIAT[3] = GetProcAddress(hBinkLib, "_BinkBufferClose@4");
	BinkIAT[4] = GetProcAddress(hBinkLib, "_BinkBufferGetDescription@4");
	BinkIAT[5] = GetProcAddress(hBinkLib, "_BinkBufferGetError@0");
	BinkIAT[6] = GetProcAddress(hBinkLib, "_BinkBufferLock@4");
	BinkIAT[7] = GetProcAddress(hBinkLib, "_BinkBufferOpen@16");
	BinkIAT[8] = GetProcAddress(hBinkLib, "_BinkBufferSetDirectDraw@8");
	BinkIAT[9] = GetProcAddress(hBinkLib, "_BinkBufferSetHWND@8");
	BinkIAT[10] = GetProcAddress(hBinkLib, "_BinkBufferSetOffset@12");
	BinkIAT[11] = GetProcAddress(hBinkLib, "_BinkBufferSetResolution@12");
	BinkIAT[12] = GetProcAddress(hBinkLib, "_BinkBufferSetScale@12");
	BinkIAT[13] = GetProcAddress(hBinkLib, "_BinkBufferUnlock@4");
	BinkIAT[14] = GetProcAddress(hBinkLib, "_BinkCheckCursor@20");
	BinkIAT[15] = GetProcAddress(hBinkLib, "_BinkClose@4");
	BinkIAT[16] = GetProcAddress(hBinkLib, "_BinkCloseTrack@4");
	BinkIAT[17] = GetProcAddress(hBinkLib, "_BinkControlBackgroundIO@8");
	BinkIAT[18] = GetProcAddress(hBinkLib, "_BinkControlPlatformFeatures@8");
	BinkIAT[19] = GetProcAddress(hBinkLib, "_BinkCopyToBuffer@28");
	BinkIAT[20] = GetProcAddress(hBinkLib, "_BinkCopyToBufferRect@44");
	BinkIAT[21] = GetProcAddress(hBinkLib, "_BinkDDSurfaceType@4");
	BinkIAT[22] = GetProcAddress(hBinkLib, "_BinkDX8SurfaceType@4");
	BinkIAT[23] = GetProcAddress(hBinkLib, "_BinkDX9SurfaceType@4");
	BinkIAT[24] = GetProcAddress(hBinkLib, "_BinkDoFrame@4");
	BinkIAT[25] = GetProcAddress(hBinkLib, "_BinkDoFrameAsync@12");
	BinkIAT[26] = GetProcAddress(hBinkLib, "_BinkDoFrameAsyncWait@8");
	BinkIAT[27] = GetProcAddress(hBinkLib, "_BinkDoFramePlane@8");
	BinkIAT[28] = GetProcAddress(hBinkLib, "_BinkGetError@0");
	BinkIAT[29] = GetProcAddress(hBinkLib, "_BinkGetFrameBuffersInfo@8");
	BinkIAT[30] = GetProcAddress(hBinkLib, "_BinkGetKeyFrame@12");
	BinkIAT[31] = GetProcAddress(hBinkLib, "_BinkGetPalette@4");
	BinkIAT[32] = GetProcAddress(hBinkLib, "_BinkGetRealtime@12");
	BinkIAT[33] = GetProcAddress(hBinkLib, "_BinkGetRects@8");
	BinkIAT[34] = GetProcAddress(hBinkLib, "_BinkGetSummary@8");
	BinkIAT[35] = GetProcAddress(hBinkLib, "_BinkGetTrackData@8");
	BinkIAT[36] = GetProcAddress(hBinkLib, "_BinkGetTrackID@8");
	BinkIAT[37] = GetProcAddress(hBinkLib, "_BinkGetTrackMaxSize@8");
	BinkIAT[38] = GetProcAddress(hBinkLib, "_BinkGetTrackType@8");
	BinkIAT[39] = GetProcAddress(hBinkLib, "_BinkGoto@12");
	BinkIAT[40] = GetProcAddress(hBinkLib, "_BinkIsSoftwareCursor@8");
	BinkIAT[41] = GetProcAddress(hBinkLib, "_BinkLogoAddress@0");
	BinkIAT[42] = GetProcAddress(hBinkLib, "_BinkNextFrame@4");
	BinkIAT[43] = GetProcAddress(hBinkLib, "_BinkOpen@8");
	BinkIAT[44] = GetProcAddress(hBinkLib, "_BinkOpenDirectSound@4");
	BinkIAT[45] = GetProcAddress(hBinkLib, "_BinkOpenMiles@4");
	BinkIAT[46] = GetProcAddress(hBinkLib, "_BinkOpenTrack@8");
	BinkIAT[47] = GetProcAddress(hBinkLib, "_BinkOpenWaveOut@4");
	BinkIAT[48] = GetProcAddress(hBinkLib, "_BinkPause@8");
	BinkIAT[49] = GetProcAddress(hBinkLib, "_BinkRegisterFrameBuffers@8");
	BinkIAT[50] = GetProcAddress(hBinkLib, "_BinkRequestStopAsyncThread@4");
	BinkIAT[51] = GetProcAddress(hBinkLib, "_BinkRestoreCursor@4");
	BinkIAT[52] = GetProcAddress(hBinkLib, "_BinkService@4");
	BinkIAT[53] = GetProcAddress(hBinkLib, "_BinkSetError@4");
	BinkIAT[54] = GetProcAddress(hBinkLib, "_BinkSetFrameRate@8");
	BinkIAT[55] = GetProcAddress(hBinkLib, "_BinkSetIO@4");
	BinkIAT[56] = GetProcAddress(hBinkLib, "_BinkSetIOSize@4");
	BinkIAT[57] = GetProcAddress(hBinkLib, "_BinkSetMemory@8");
	BinkIAT[58] = GetProcAddress(hBinkLib, "_BinkSetMixBinVolumes@20");
	BinkIAT[59] = GetProcAddress(hBinkLib, "_BinkSetMixBins@16");
	BinkIAT[60] = GetProcAddress(hBinkLib, "_BinkSetPan@12");
	BinkIAT[61] = GetProcAddress(hBinkLib, "_BinkSetSimulate@4");
	BinkIAT[62] = GetProcAddress(hBinkLib, "_BinkSetSoundOnOff@8");
	BinkIAT[63] = GetProcAddress(hBinkLib, "_BinkSetSoundSystem@8");
	BinkIAT[64] = GetProcAddress(hBinkLib, "_BinkSetSoundTrack@8");
	BinkIAT[65] = GetProcAddress(hBinkLib, "_BinkSetVideoOnOff@8");
	BinkIAT[66] = GetProcAddress(hBinkLib, "_BinkSetVolume@12");
	BinkIAT[67] = GetProcAddress(hBinkLib, "_BinkShouldSkip@4");
	BinkIAT[68] = GetProcAddress(hBinkLib, "_BinkStartAsyncThread@8");
	BinkIAT[69] = GetProcAddress(hBinkLib, "_BinkWait@4");
	BinkIAT[70] = GetProcAddress(hBinkLib, "_BinkWaitStopAsyncThread@4");
	BinkIAT[71] = GetProcAddress(hBinkLib, "_RADTimerRead@0");

	return hBinkLib;
}

// _BinkBufferBlit@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferBlit(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[0 * 4];
	}
}

// _BinkBufferCheckWinPos@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferCheckWinPos(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[1 * 4];
	}
}

// _BinkBufferClear@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferClear(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[2 * 4];
	}
}

// _BinkBufferClose@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferClose(int a1)
{
	__asm
	{
		jmp BinkIAT[3 * 4];
	}
}

// _BinkBufferGetDescription@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferGetDescription(int a1)
{
	__asm
	{
		jmp BinkIAT[4 * 4];
	}
}

// _BinkBufferGetError@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferGetError()
{
	__asm
	{
		jmp BinkIAT[5 * 4];
	}
}

// _BinkBufferLock@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferLock(int a1)
{
	__asm
	{
		jmp BinkIAT[6 * 4];
	}
}

// _BinkBufferOpen@16
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferOpen(int a1, int a2, int a3, int a4)
{
	__asm
	{
		jmp BinkIAT[7 * 4];
	}
}

// _BinkBufferSetDirectDraw@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetDirectDraw(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[8 * 4];
	}
}

// _BinkBufferSetHWND@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetHWND(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[9 * 4];
	}
}

// _BinkBufferSetOffset@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetOffset(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[10 * 4];
	}
}

// _BinkBufferSetResolution@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetResolution(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[11 * 4];
	}
}

// _BinkBufferSetScale@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferSetScale(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[12 * 4];
	}
}

// _BinkBufferUnlock@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkBufferUnlock(int a1)
{
	__asm
	{
		jmp BinkIAT[13 * 4];
	}
}

// _BinkCheckCursor@20
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCheckCursor(int a1, int a2, int a3, int a4, int a5)
{
	__asm
	{
		jmp BinkIAT[14 * 4];
	}
}

// _BinkClose@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkClose(int a1)
{
	__asm
	{
		jmp BinkIAT[15 * 4];
	}
}

// _BinkCloseTrack@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCloseTrack(int a1)
{
	__asm
	{
		jmp BinkIAT[16 * 4];
	}
}

// _BinkControlBackgroundIO@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkControlBackgroundIO(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[17 * 4];
	}
}

// _BinkControlPlatformFeatures@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkControlPlatformFeatures(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[18 * 4];
	}
}

// _BinkCopyToBuffer@28
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCopyToBuffer(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	__asm
	{
		jmp BinkIAT[19 * 4];
	}
}

// _BinkCopyToBufferRect@44
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkCopyToBufferRect(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
	__asm
	{
		jmp BinkIAT[20 * 4];
	}
}

// _BinkDDSurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDDSurfaceType(int a1)
{
	__asm
	{
		jmp BinkIAT[21 * 4];
	}
}

// _BinkDX8SurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDX8SurfaceType(int a1)
{
	__asm
	{
		jmp BinkIAT[22 * 4];
	}
}

// _BinkDX9SurfaceType@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDX9SurfaceType(int a1)
{
	__asm
	{
		jmp BinkIAT[23 * 4];
	}
}

// _BinkDoFrame@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrame(int a1)
{
	__asm
	{
		jmp BinkIAT[24 * 4];
	}
}

// _BinkDoFrameAsync@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrameAsync(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[25 * 4];
	}
}

// _BinkDoFrameAsyncWait@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFrameAsyncWait(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[26 * 4];
	}
}

// _BinkDoFramePlane@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkDoFramePlane(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[27 * 4];
	}
}

// _BinkGetError@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetError()
{
	__asm
	{
		jmp BinkIAT[28 * 4];
	}
}

// _BinkGetFrameBuffersInfo@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetFrameBuffersInfo(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[29 * 4];
	}
}

// _BinkGetKeyFrame@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetKeyFrame(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[30 * 4];
	}
}

// _BinkGetPalette@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetPalette(int a1)
{
	__asm
	{
		jmp BinkIAT[31 * 4];
	}
}

// _BinkGetRealtime@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetRealtime(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[32 * 4];
	}
}

// _BinkGetRects@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetRects(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[33 * 4];
	}
}

// _BinkGetSummary@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetSummary(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[34 * 4];
	}
}

// _BinkGetTrackData@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackData(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[35 * 4];
	}
}

// _BinkGetTrackID@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackID(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[36 * 4];
	}
}

// _BinkGetTrackMaxSize@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackMaxSize(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[37 * 4];
	}
}

// _BinkGetTrackType@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGetTrackType(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[38 * 4];
	}
}

// _BinkGoto@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkGoto(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[39 * 4];
	}
}

// _BinkIsSoftwareCursor@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkIsSoftwareCursor(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[40 * 4];
	}
}

// _BinkLogoAddress@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkLogoAddress()
{
	__asm
	{
		jmp BinkIAT[41 * 4];
	}
}

// _BinkNextFrame@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkNextFrame(int a1)
{
	__asm
	{
		jmp BinkIAT[42 * 4];
	}
}

// _BinkOpen@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpen(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[43 * 4];
	}
}

// _BinkOpenDirectSound@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenDirectSound(int a1)
{
	__asm
	{
		jmp BinkIAT[44 * 4];
	}
}

// _BinkOpenMiles@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenMiles(int a1)
{
	__asm
	{
		jmp BinkIAT[45 * 4];
	}
}

// _BinkOpenTrack@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenTrack(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[46 * 4];
	}
}

// _BinkOpenWaveOut@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkOpenWaveOut(int a1)
{
	__asm
	{
		jmp BinkIAT[47 * 4];
	}
}

// _BinkPause@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkPause(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[48 * 4];
	}
}

// _BinkRegisterFrameBuffers@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRegisterFrameBuffers(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[49 * 4];
	}
}

// _BinkRequestStopAsyncThread@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRequestStopAsyncThread(int a1)
{
	__asm
	{
		jmp BinkIAT[50 * 4];
	}
}

// _BinkRestoreCursor@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkRestoreCursor(int a1)
{
	__asm
	{
		jmp BinkIAT[51 * 4];
	}
}

// _BinkService@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkService(int a1)
{
	__asm
	{
		jmp BinkIAT[52 * 4];
	}
}

// _BinkSetError@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetError(int a1)
{
	__asm
	{
		jmp BinkIAT[53 * 4];
	}
}

// _BinkSetFrameRate@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetFrameRate(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[54 * 4];
	}
}

// _BinkSetIO@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetIO(int a1)
{
	__asm
	{
		jmp BinkIAT[55 * 4];
	}
}

// _BinkSetIOSize@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetIOSize(int a1)
{
	__asm
	{
		jmp BinkIAT[56 * 4];
	}
}

// _BinkSetMemory@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMemory(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[57 * 4];
	}
}

// _BinkSetMixBinVolumes@20
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMixBinVolumes(int a1, int a2, int a3, int a4, int a5)
{
	__asm
	{
		jmp BinkIAT[58 * 4];
	}
}

// _BinkSetMixBins@16
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetMixBins(int a1, int a2, int a3, int a4)
{
	__asm
	{
		jmp BinkIAT[59 * 4];
	}
}

// _BinkSetPan@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetPan(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[60 * 4];
	}
}

// _BinkSetSimulate@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSimulate(int a1)
{
	__asm
	{
		jmp BinkIAT[61 * 4];
	}
}

// _BinkSetSoundOnOff@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundOnOff(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[62 * 4];
	}
}

// _BinkSetSoundSystem@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundSystem(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[63 * 4];
	}
}

// _BinkSetSoundTrack@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetSoundTrack(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[64 * 4];
	}
}

// _BinkSetVideoOnOff@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetVideoOnOff(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[65 * 4];
	}
}

// _BinkSetVolume@12
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkSetVolume(int a1, int a2, int a3)
{
	__asm
	{
		jmp BinkIAT[66 * 4];
	}
}

// _BinkShouldSkip@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkShouldSkip(int a1)
{
	__asm
	{
		jmp BinkIAT[67 * 4];
	}
}

// _BinkStartAsyncThread@8
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkStartAsyncThread(int a1, int a2)
{
	__asm
	{
		jmp BinkIAT[68 * 4];
	}
}

// _BinkWait@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkWait(int a1)
{
	__asm
	{
		jmp BinkIAT[69 * 4];
	}
}

// _BinkWaitStopAsyncThread@4
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall BinkWaitStopAsyncThread(int a1)
{
	__asm
	{
		jmp BinkIAT[70 * 4];
	}
}

// _RADTimerRead@0
extern "C" __declspec(dllexport) __declspec(naked) void __stdcall RADTimerRead()
{
	__asm
	{
		jmp BinkIAT[71 * 4];
	}
}