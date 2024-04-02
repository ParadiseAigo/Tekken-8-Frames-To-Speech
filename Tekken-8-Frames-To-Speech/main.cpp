#include "frames-to-speech.h"
#include "pointers.h"
#include "resource.h"
#include "audio.h"

//TODO:
//-> /

HANDLE tekkenHandle;
int tekkenPid;
void* tekkenModulePointer;

int main() {
	init();
	mainLoop();
	closeProgram();
}

void init() {
	initTekkenHandle();
	initModuleAddresses();
	std::cout << "Program ready!" << std::endl;
}

void initTekkenHandle() {
	DWORD pid, secondsDelay;
	pid = getProcessId(TEXT(TEKKEN_EXE_NAME));
	secondsDelay = 2;
	while (pid == 0) {
		std::cout << "Tekken not found. Trying again in " << secondsDelay << " seconds..." << std::endl;
		Sleep(secondsDelay * 1000); // milliseconds
		pid = getProcessId(TEXT(TEKKEN_EXE_NAME));
	}
	tekkenPid = pid; // global variable
	std::cout << "Tekken found! pid = (" << pid << ")" << std::endl;
	std::cout << "Opening Tekken process..." << std::endl;
	tekkenHandle = getProcessHandle(pid);  // global variable
	std::cout << "Opening Tekken process success!" << std::endl;
}

void initModuleAddresses() {
	tekkenModulePointer = (void*)getModuleBaseAddress(tekkenPid, TEKKEN_MODULE_NAME);
	if (tekkenModulePointer == 0) {
		std::cout << "Error finding the Tekken module base address." << std::endl;
	}
	else {
		std::cout << "Tekken module base address found." << std::endl;
	}
}

void mainLoop() {
	float oneFrame = 1000/60;  // "60fps"
	void *p1RecoveryFramesPointer, *p1StateFramesPointer, *p2StateFramesPointer;
	int p1RecoveryFrames;
	int prevRecoveryFrames = 0, lastPunishableFrames = 0;
	int p1State, p2State;
	int p2PrevState = 0, p1PrevState = 0, p1LastPunishableState = 0, p2LastPunishableState = 0;
	while (true) {
		Sleep((int)oneFrame);
		p1RecoveryFramesPointer = (void*)getDynamicPointer(tekkenHandle, (void*) ((QWORD)tekkenModulePointer + P1_RECOVERY_FRAMES_STATIC_POINTER), P1_RECOVERY_FRAMES_POINTER_OFFSETS);
		p1StateFramesPointer = (void*)getDynamicPointer(tekkenHandle, (void*) ((QWORD)tekkenModulePointer + P1_STATE_STATIC_POINTER), P1_STATE_POINTER_OFFSETS);
		p2StateFramesPointer = (void*)getDynamicPointer(tekkenHandle, (void*) ((QWORD)tekkenModulePointer + P2_STATE_STATIC_POINTER), P2_STATE_POINTER_OFFSETS);
		if (! isMemoryReadable(tekkenHandle, p1RecoveryFramesPointer)) {
			continue;
		}
		p1RecoveryFrames = readDwordFromMemory(tekkenHandle, p1RecoveryFramesPointer);
		p1State = readDwordFromMemory(tekkenHandle, p1StateFramesPointer);
		p2State = readDwordFromMemory(tekkenHandle, p2StateFramesPointer);
		if (abs(prevRecoveryFrames) < abs(p1RecoveryFrames)) {
			playFramesAudio(abs(p1RecoveryFrames));
		}
		if ((p2State != p2PrevState) || (p1RecoveryFrames != prevRecoveryFrames || (p1State != p1PrevState))) {
			printf("p1 recovery: %d,  p1 state: %d,  p2 state: %d\n", p1RecoveryFrames, p1State, p2State); //Debugging
			p2PrevState = p2State;
			p1PrevState = p1State;
			prevRecoveryFrames = p1RecoveryFrames;
		}
		/*
		if (24 >= abs(p1RecoveryFrames) && abs(p1RecoveryFrames) >= 10) { // if punishable
			printf("p1State=%d, p1PrevState=%d, p2State=%d, p2PrevState=%d\n", p1State, p1PrevState, p2State, p2PrevState);
			if (p1State != p1PrevState || p2State != p2PrevState) { // ignore (example): -19,-17,-10,..
				if ((p1State == p1LastPunishableState && p2State == p2LastPunishableState) // dont ignore same (broken move; example: causes -15,15,15,..) move if repeated
					|| (lastPunishableFrames != abs(p1RecoveryFrames))) {  // ignore (example): -15,-15,-15,...
					playFramesAudio(abs(p1RecoveryFrames));
					lastPunishableFrames = abs(p1RecoveryFrames);
					p1LastPunishableState = p1State;
					p2LastPunishableState = p2State;
				}
			}
		}
		prevRecoveryFrames = p1RecoveryFrames;
		p1PrevState = p1State;
		p2PrevState = p2State;
		*/
	}
	// program never reaches this comment
}

// this function is never called... (fix it!)
void closeProgram() {
	CloseHandle(tekkenHandle);
	system("PAUSE");
}
